
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
#line 71 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"


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
#line 79 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 861 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 961 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 109 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"

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
#line 178 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
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
#line 859 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 285 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 123: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 858 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 294 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 148: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 857 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 303 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 312 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 321 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 330 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 339 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 348 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 357 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 366 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 375 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 384 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 393 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 402 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 411 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 420 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 429 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 438 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 447 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 456 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 465 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 474 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 483 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 492 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 501 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 510 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 519 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 882 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 528 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 882 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 537 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 546 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 555 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 564 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 573 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 582 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 591 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 600 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 882 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 609 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 618 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 627 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 636 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 645 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 654 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 663 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 672 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 882 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 681 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 690 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 699 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 708 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 717 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 726 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 735 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 744 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 753 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 762 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 771 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 780 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 789 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 798 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 807 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 816 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 825 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 834 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 843 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 852 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 861 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 888 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 897 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 906 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 924 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 951 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 960 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 969 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 978 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 987 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 996 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1005 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1014 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1023 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1032 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1041 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1050 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1059 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1068 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1077 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1086 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1095 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1104 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1113 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1122 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1131 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1140 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1149 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1158 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1167 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1176 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1185 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1194 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1203 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1212 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1221 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1230 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1239 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1248 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1257 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1266 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1275 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1284 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1293 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1302 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1311 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1320 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1329 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1338 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1347 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1356 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1365 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1374 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1383 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1392 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1401 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1410 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1419 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1428 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1437 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1446 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1455 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1464 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1473 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1482 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1491 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1500 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1509 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1518 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1527 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1536 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1545 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1554 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1563 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1572 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1581 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1590 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1599 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1608 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1617 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1626 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1635 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1644 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1653 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1662 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1671 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1680 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1689 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1698 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1707 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1716 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1725 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1734 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1743 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1752 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1761 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1770 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1779 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1788 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1797 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1806 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1815 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1824 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1833 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1842 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1851 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1860 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1869 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1878 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1887 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1896 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1905 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1914 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1923 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1932 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1941 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1950 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1959 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1968 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1977 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1986 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1995 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2004 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2013 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2022 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2031 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2040 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2049 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2058 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2067 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2076 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2085 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2094 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2103 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2112 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2121 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2130 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2139 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2148 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2157 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2166 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2175 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2184 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2193 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2202 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2211 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2220 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2229 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2238 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2247 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2256 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2265 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2274 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2283 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2292 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2301 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2310 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 882 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2319 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2328 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2337 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2346 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2355 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2364 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2373 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2382 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2391 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2400 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2409 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2418 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2427 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2436 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2445 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2454 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2463 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2472 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2481 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2490 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2499 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2508 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2517 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2526 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2535 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2544 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2553 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2562 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2571 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2580 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 615: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2589 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2598 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2607 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 618: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2616 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 619: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2625 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2634 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2643 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 622: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2652 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 623: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2661 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 626: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2670 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 627: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2679 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2688 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
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
#line 124 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 553 of lalr1.cc  */
#line 2773 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"

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
#line 979 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 988 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 997 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 1003 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1011 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1017 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1028 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1033 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1041 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1048 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1055 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1064 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1071 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1079 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1087 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1095 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1106 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1111 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1118 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1125 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1137 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1147 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1154 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1161 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 1196 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1201 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1209 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1217 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1225 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1230 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1238 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1243 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1251 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1256 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1264 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1271 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1278 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1285 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1300 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1310 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1315 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1323 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1331 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1342 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1349 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1360 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1365 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1373 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1380 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1387 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1396 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 1409 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1417 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1424 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1434 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1441 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1448 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1471 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1477 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1486 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1493 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1503 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1512 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1513 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1514 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1515 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1516 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1517 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1518 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1519 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1520 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1521 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1527 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1535 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1543 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1551 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1558 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1566 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1573 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1578 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1586 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1594 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 1609 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 1624 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 1642 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1647 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1655 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1663 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1674 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1679 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1688 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1693 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1700 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1705 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1715 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1720 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1729 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1735 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1748 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1753 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1761 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 1772 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 1787 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 1799 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 1814 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1819 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1824 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1829 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1837 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1844 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1855 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1860 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1870 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1877 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1884 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1891 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1901 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1905 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1915 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 1923 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 1934 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1940 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1949 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1954 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1961 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1968 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1980 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 1990 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 2000 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 2011 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 2027 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 2047 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 2052 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 2056 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 2064 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 2069 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2073 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2081 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2086 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2098 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2105 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2134 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2139 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2147 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 2164 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2172 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2180 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2187 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2194 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 2201 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 2208 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)));
      vdecl->add((yysemantic_stack_[(4) - (4)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 2218 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 2230 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 2243 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 2255 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 2271 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 2279 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 2287 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 2295 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 2310 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 2315 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 2323 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 2337 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 2354 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 2379 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2387 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2394 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2405 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 2415 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 2420 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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

  case 221:

/* Line 678 of lalr1.cc  */
#line 2458 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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

  case 222:

/* Line 678 of lalr1.cc  */
#line 2472 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2480 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2485 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2493 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2498 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2503 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2511 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 2520 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2532 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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

  case 231:

/* Line 678 of lalr1.cc  */
#line 2542 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2555 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2579 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2586 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2596 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2604 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2611 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2621 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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

  case 247:

/* Line 678 of lalr1.cc  */
#line 2631 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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

  case 248:

/* Line 678 of lalr1.cc  */
#line 2641 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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

  case 249:

/* Line 678 of lalr1.cc  */
#line 2651 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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

  case 250:

/* Line 678 of lalr1.cc  */
#line 2661 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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

  case 251:

/* Line 678 of lalr1.cc  */
#line 2671 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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

  case 252:

/* Line 678 of lalr1.cc  */
#line 2681 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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

  case 253:

/* Line 678 of lalr1.cc  */
#line 2691 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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

  case 254:

/* Line 678 of lalr1.cc  */
#line 2702 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2711 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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

  case 256:

/* Line 678 of lalr1.cc  */
#line 2721 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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

  case 257:

/* Line 678 of lalr1.cc  */
#line 2731 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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

  case 258:

/* Line 678 of lalr1.cc  */
#line 2747 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2756 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2765 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2773 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2779 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2791 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2799 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2809 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2817 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2829 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2835 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2848 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2852 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2860 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2864 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2877 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2881 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2891 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2899 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2906 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2912 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2923 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2927 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2936 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2944 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2950 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2960 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2966 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2976 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2980 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2990 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2996 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 3002 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 3008 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 3017 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3026 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3035 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3048 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3052 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3060 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3066 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3076 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3084 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3093 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3106 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3113 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3125 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3129 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3141 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3148 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3154 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3163 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3170 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3176 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3187 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3194 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3200 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3209 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3218 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3225 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 3236 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3243 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3255 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3261 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3273 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3279 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3290 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3296 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3307 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3313 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3324 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3333 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3337 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3346 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3350 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3358 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3362 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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

  case 338:

/* Line 678 of lalr1.cc  */
#line 3372 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3379 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3388 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3397 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3402 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3411 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3420 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3429 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3442 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3446 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3458 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3462 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3469 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3473 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3482 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3486 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3490 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3499 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3503 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3509 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3515 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3521 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3532 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3536 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3540 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3548 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3552 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3558 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3568 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3572 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3582 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3586 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3596 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3600 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3610 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3614 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3624 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3628 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3636 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3640 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3644 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3648 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3658 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3662 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3666 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3674 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3678 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3682 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3686 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3690 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3694 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3702 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3706 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3710 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3718 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3722 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3726 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3730 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3741 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3747 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3757 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3763 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3773 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3777 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3781 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3819 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3823 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 3833 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 3843 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3856 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3865 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 3875 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3888 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3892 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3901 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3907 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 3915 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3921 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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
#line 3933 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3939 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3949 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3953 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3957 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3961 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3965 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3971 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3977 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3985 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 3989 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 3997 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 4001 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 4012 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4016 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4020 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4026 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4030 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4044 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4048 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4056 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4060 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4070 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4074 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4078 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4082 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4091 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4095 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4099 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4103 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4111 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4117 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4127 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4135 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4139 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4143 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4147 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4151 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4155 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4159 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4163 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4167 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4177 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4185 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4189 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4197 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4204 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4211 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4222 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4230 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4234 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4242 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4250 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4258 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4312 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4316 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4329 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4335 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4345 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4349 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4357 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4361 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4365 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4373 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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

  case 481:

/* Line 678 of lalr1.cc  */
#line 4383 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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

  case 482:

/* Line 678 of lalr1.cc  */
#line 4393 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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

  case 483:

/* Line 678 of lalr1.cc  */
#line 4403 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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

  case 484:

/* Line 678 of lalr1.cc  */
#line 4413 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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

  case 485:

/* Line 678 of lalr1.cc  */
#line 4423 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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

  case 486:

/* Line 678 of lalr1.cc  */
#line 4438 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4444 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4455 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4461 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4472 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4489 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4494 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4503 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4507 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4514 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4520 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4526 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4534 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4546 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4550 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4557 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4563 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4569 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4576 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4587 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4591 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4601 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4605 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4615 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4619 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4623 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4628 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4637 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4643 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4649 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4655 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4663 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4668 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4676 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4681 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4689 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4697 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4702 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4707 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4712 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4717 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4722 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4731 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4739 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4743 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4760 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4764 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4772 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4780 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4788 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4792 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4800 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4806 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4816 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4824 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4828 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4832 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4867 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4873 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4889 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4893 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4897 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4901 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4905 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4912 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4918 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4928 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4936 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4940 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4944 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4948 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4952 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 4956 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 4960 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 4964 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 4968 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 4976 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 4984 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 4988 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 4992 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5002 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5010 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5018 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5022 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5026 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5034 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5038 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5044 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5050 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5054 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5064 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5072 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5076 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5082 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5091 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5100 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5106 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5112 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5122 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5139 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5146 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5161 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5197 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5201 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5209 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5217 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5229 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5233 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5241 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5249 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5253 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5264 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5281 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5287 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5293 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5303 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5307 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5313 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5319 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5323 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5329 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5333 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5339 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5345 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5352 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5362 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5367 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5375 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5381 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5391 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5413 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5422 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5428 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5441 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5455 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5462 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5468 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5478 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5487 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5495 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5501 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5519 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5527 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5531 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5538 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5543 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5551 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5555 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5562 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5566 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5573 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5577 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5584 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5588 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5597 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5609 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5613 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5620 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5624 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5632 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5640 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5648 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5652 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5659 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5663 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5671 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5682 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5686 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5694 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5706 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5712 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5721 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5725 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5733 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5737 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5741 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5748 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5752 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5759 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5763 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5771 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5775 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5779 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5783 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5787 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5795 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5803 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5815 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5827 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5831 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5835 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5843 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5849 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5859 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5863 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5867 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5871 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5875 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5879 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5883 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5887 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5895 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5899 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5903 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5907 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5915 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5921 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5931 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5941 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5945 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5953 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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

  case 700:

/* Line 678 of lalr1.cc  */
#line 5963 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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

  case 701:

/* Line 678 of lalr1.cc  */
#line 5974 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5981 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5985 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5992 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5996 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 6003 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 6008 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 6017 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 6026 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 6030 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 6037 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 6041 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 6049 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 6058 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 6065 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 6075 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 6079 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 6086 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 6092 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 6101 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 6105 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 6112 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 6117 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 6129 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 6137 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 6149 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 6157 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 6161 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 6169 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 6173 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 6177 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 6185 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 6193 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 6197 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 6201 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 6205 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 6213 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 6221 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 6233 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 6237 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 6245 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 6263 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
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

  case 746:

/* Line 678 of lalr1.cc  */
#line 6276 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 6277 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 6278 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 6279 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 6280 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 6281 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 6282 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 6283 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 6284 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 6285 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 6286 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 6287 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 6288 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 6289 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 6290 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 6295 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 6296 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 6297 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 6298 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 6299 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 6300 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 6301 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 6302 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 6303 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 6304 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 6305 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 6306 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 6307 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 6308 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 6309 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 6310 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 6311 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 6312 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 6313 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 6314 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 6315 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 6316 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 6317 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 6318 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 6319 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 6320 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 6321 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 6322 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 6323 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 6324 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 6325 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 6326 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 6327 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 6328 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 6329 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 6330 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 6331 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 6332 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 6333 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 6334 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 6335 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 6336 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 6337 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 6338 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 6339 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 6340 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 6341 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 6342 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 6343 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 6344 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 6345 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 6346 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 6347 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 6348 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 6349 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 6350 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 6351 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 6352 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 6353 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 6354 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 6355 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 6356 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 6357 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 6358 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 6359 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 6360 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 6361 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 6362 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 6363 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 6364 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 6365 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 6366 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 6367 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 6368 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 6369 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 6370 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 6371 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 6372 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 6373 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 6374 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 6375 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 6376 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 6377 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 6378 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 6379 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 6380 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 6381 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 6382 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 6383 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 6384 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 6385 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 6386 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 6387 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 6388 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 6389 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 6390 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 6391 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 6392 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 6393 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6394 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6395 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6396 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6397 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6398 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6399 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6400 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6401 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6402 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6403 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6404 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6405 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6406 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6407 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6408 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6409 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6410 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6411 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6412 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6413 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6414 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6415 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6416 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6417 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6418 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6419 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6420 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6421 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6422 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6423 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6424 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6425 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6426 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6427 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6428 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6429 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6430 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6431 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6432 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6433 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6434 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6435 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6436 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6437 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6438 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6439 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6440 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6441 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("local"))); }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6442 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6443 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6444 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6445 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6446 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6447 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6448 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6449 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6450 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6451 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 919:

/* Line 678 of lalr1.cc  */
#line 6452 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 920:

/* Line 678 of lalr1.cc  */
#line 6453 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 921:

/* Line 678 of lalr1.cc  */
#line 6454 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 922:

/* Line 678 of lalr1.cc  */
#line 6455 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 923:

/* Line 678 of lalr1.cc  */
#line 6456 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 924:

/* Line 678 of lalr1.cc  */
#line 6457 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 925:

/* Line 678 of lalr1.cc  */
#line 6458 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 926:

/* Line 678 of lalr1.cc  */
#line 6459 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 927:

/* Line 678 of lalr1.cc  */
#line 6460 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 928:

/* Line 678 of lalr1.cc  */
#line 6461 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 929:

/* Line 678 of lalr1.cc  */
#line 6462 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 930:

/* Line 678 of lalr1.cc  */
#line 6463 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 931:

/* Line 678 of lalr1.cc  */
#line 6464 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 932:

/* Line 678 of lalr1.cc  */
#line 6465 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 933:

/* Line 678 of lalr1.cc  */
#line 6466 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 934:

/* Line 678 of lalr1.cc  */
#line 6467 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 935:

/* Line 678 of lalr1.cc  */
#line 6468 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 936:

/* Line 678 of lalr1.cc  */
#line 6469 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 937:

/* Line 678 of lalr1.cc  */
#line 6470 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 938:

/* Line 678 of lalr1.cc  */
#line 6471 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 939:

/* Line 678 of lalr1.cc  */
#line 6472 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 940:

/* Line 678 of lalr1.cc  */
#line 6473 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 941:

/* Line 678 of lalr1.cc  */
#line 6474 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 942:

/* Line 678 of lalr1.cc  */
#line 6475 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 943:

/* Line 678 of lalr1.cc  */
#line 6476 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 944:

/* Line 678 of lalr1.cc  */
#line 6477 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 945:

/* Line 678 of lalr1.cc  */
#line 6478 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 946:

/* Line 678 of lalr1.cc  */
#line 6479 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 947:

/* Line 678 of lalr1.cc  */
#line 6480 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 948:

/* Line 678 of lalr1.cc  */
#line 6481 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 949:

/* Line 678 of lalr1.cc  */
#line 6482 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 950:

/* Line 678 of lalr1.cc  */
#line 6483 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 951:

/* Line 678 of lalr1.cc  */
#line 6484 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 952:

/* Line 678 of lalr1.cc  */
#line 6485 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 953:

/* Line 678 of lalr1.cc  */
#line 6486 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 954:

/* Line 678 of lalr1.cc  */
#line 6487 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 955:

/* Line 678 of lalr1.cc  */
#line 6488 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 956:

/* Line 678 of lalr1.cc  */
#line 6489 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 957:

/* Line 678 of lalr1.cc  */
#line 6490 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 958:

/* Line 678 of lalr1.cc  */
#line 6491 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 959:

/* Line 678 of lalr1.cc  */
#line 6492 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 960:

/* Line 678 of lalr1.cc  */
#line 6493 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 961:

/* Line 678 of lalr1.cc  */
#line 6499 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    {
          // EQName's namespace URI value is whitespace normalized according to the rules for the xs:anyURI type
          std::string uri = "\"" + SYMTAB((yysemantic_stack_[(3) - (1)].sval)) + "\"";
          std::string eqname = SYMTAB(driver.symtab.put_uri(uri.c_str(), uri.size())) + ":" + SYMTAB((yysemantic_stack_[(3) - (3)].sval));
          (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT(eqname.c_str())), true);
        }
    break;

  case 962:

/* Line 678 of lalr1.cc  */
#line 6505 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 678 of lalr1.cc  */
#line 11541 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1423;
  const short int
  xquery_parser::yypact_[] =
  {
      2698, -1423, -1423, -1423,  4189,  4189,  4189, -1423, -1423,   308,
     450,    23,    66,   -13, -1423, -1423, -1423,   498, -1423, -1423,
   -1423,    19,   518,   723,   551,   526,   559,   140, -1423,    -3,
   -1423, -1423, -1423, -1423, -1423, -1423,   742, -1423,   632,   703,
   -1423, -1423, -1423, -1423,   422, -1423,   743, -1423,   756,   769,
   -1423,    92, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423,
   -1423, -1423, -1423, -1423, -1423, -1423,   662,   782, -1423, -1423,
   -1423, -1423,   604,  8659, -1423, -1423, -1423,   821, -1423, -1423,
   -1423,   829, -1423,   827,   837, -1423, -1423, 12399, -1423, -1423,
   -1423, -1423, -1423, -1423, -1423, -1423,   848, -1423, -1423,   846,
     851, -1423, -1423, -1423, -1423, -1423, -1423, -1423,  2997,  5977,
   12399, -1423, -1423, -1423, -1423, -1423, -1423, -1423,   798, -1423,
   -1423,   855,  9543, -1423,  9834,   857,   858, -1423, -1423, -1423,
     859, -1423,  8361, -1423, -1423, -1423, -1423, -1423, -1423,   830,
   -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423,    59,   767,
   -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423,   -58,   831,
     702, -1423,   761,   599, -1423, -1423, -1423, -1423, -1423, -1423,
     868, -1423,   315,   747,   749,   750, -1423, -1423,   839,   836,
   -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423,
   -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423,
   -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423,
   -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423,
   -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423,
   -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423,
   -1423, -1423, -1423,  4487,   992, -1423,  4785, -1423, -1423,   511,
      61, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423,
   -1423, -1423, -1423, -1423, -1423,    68, -1423, -1423, -1423, -1423,
   -1423, -1423,   317, -1423, -1423, -1423, -1423, -1423, -1423, -1423,
   -1423,  4189, -1423, -1423, -1423, -1423,     3, -1423, -1423, -1423,
   -1423, -1423, -1423, -1423, -1423,   889, -1423,   808, -1423, -1423,
   -1423,   339, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423,
     832,   904, -1423,   805,   751,   642,   405,   634,   637, -1423,
     952,   806,   903,   911,  7169, -1423, -1423, -1423,   -21, -1423,
   -1423,  8361, -1423,   717, -1423,   852,  8659, -1423,   852,  8659,
   -1423, -1423, -1423,   775, -1423, -1423, -1423, -1423, -1423, -1423,
   -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423,
   -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423,
   -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423,
   -1423, -1423, -1423, -1423, -1423, -1423,   895,   872,   862, -1423,
   -1423, -1423, -1423, -1423,   838, -1423,  4189,   841,   843,    81,
      81,   990,   635,   655,   455, 12684, 12399,   223,   973, 12399,
     871,   910,   601,  9543,   574,   783, 12399, 12399,   726,   712,
      41, -1423, -1423, -1423,  9543,  4189,   844,  4189,    55,  7467,
   10404,   753,   754, 12399,   914,     1,   880,  7467,  1034,    67,
      54, 12399,   922,   899,   935, -1423,  7467,  9250, 12399, 12399,
   12399,  4189,   860,  7467,  7467, 12399,  4189,   891,   892, -1423,
   -1423, -1423,  7467, 10689, -1423,   890, -1423,   896, -1423, -1423,
   -1423, -1423,   897, -1423,   898, -1423, -1423, -1423, -1423, -1423,
     900, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423,
   -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423,
   -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, 12399,
   -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423,
   -1423, -1423,   906, 12399, -1423, -1423, -1423,   876,  3295,   905,
     907,   908, 12399,  4189, -1423,   902,    33, -1423,   341,  1026,
    7467, -1423, -1423,    71, -1423, -1423, -1423,  1047, -1423, -1423,
   -1423, -1423,  7467,   853, -1423,  1037,  7467,  7467,   882,  7467,
    7467,  7467,  7467,   840, 12399,   829,   332,   881,   883,  7467,
    7467,  2997,   835, -1423, -1423, -1423, -1423,    66,   140,    72,
      76,  1068,  5083,  5083,  5381,  5381,   829, -1423, -1423,   889,
     829, -1423,  7467, -1423,   956,   551,    -3,   909,   912,   915,
    4189,  7467, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423,
    7765,  7765,  7765, -1423,  7765,  7765, -1423,  7765, -1423,  7765,
   -1423, -1423, -1423, -1423, -1423, -1423, -1423,  7765,  7765,  1007,
    7765,  7765,  7765,  7765,  7765,  7765,  7765,  7765,  7765,  7765,
    7765,   854,   981,   986,   993, -1423, -1423, -1423,  6275, -1423,
   -1423,  8361,  8361,  7467,   852, -1423, -1423,   852, -1423,  6573,
     852,  9543,   938,  6871, -1423, -1423, -1423, -1423,    45, -1423,
     106, -1423, -1423, -1423, -1423, -1423,   982,   983,   526,  1061,
   -1423, -1423, 12684,   833,   602, 12399,   932,   934,   833,   990,
     968,   964, -1423, -1423, -1423,    73,   856,  1002,   799, 12399,
     957,  7467,   985, 12399, 12399, -1423,   969,   916,  4189, -1423,
     921,   896,   703, -1423,   919,   920,    18, -1423,   112,   202,
   -1423, -1423,  1001, -1423,    38, 12399,    21, 12399,  1014,   203,
   -1423,  4189, -1423,   212, -1423,  9543,  1013,  1065,  9543,   990,
    1015,   343, 12399,  7467,    -3,    96,   926, -1423,   927,   928,
     930,    30, -1423,   323,   936, -1423,   216,   227,   965, -1423,
     937,  4189,  4189,   257, -1423,   228,   266,   437,  7467,    35,
   -1423, -1423,  7467,  7467,  7467, -1423,  7467, -1423,  7467, 12399,
    1026, -1423,   199,   340, -1423, -1423, -1423,   379, -1423,    14,
   -1423, -1423, -1423,    11,    99,  1024,   886,   901,   -12, -1423,
     984, -1423,   829, -1423, -1423,   933,   271,  3593,   384,  8957,
     835, -1423,   511,   611,  1090,  1090, -1423, -1423,    84, -1423,
   -1423,    89, -1423,   666, -1423, -1423, -1423, -1423, -1423, -1423,
   -1423, 12399,   959,  7467,  1009, -1423, -1423, -1423,   904, -1423,
   -1423, -1423, -1423, -1423,  7765, -1423, -1423, -1423,    82,   405,
     405,   246,   634,   634,   634,   634,   637,   637, -1423, -1423,
   11829, 11829, 12399, 12399, -1423,   496, -1423, -1423,    -4, -1423,
   -1423, -1423,   394, -1423, -1423, -1423,   395,    81, -1423, -1423,
     235,   272,   565, -1423,   526, -1423, -1423, -1423, -1423, -1423,
   -1423, -1423, -1423, -1423, -1423,   833, -1423,   999, 12114,   991,
    7467, -1423, -1423, -1423,  1039,   990,   990,   833, -1423,   807,
     990,   628, 12399,   390,   461,  1102, -1423, -1423,   849,   549,
   -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423,
   -1423,    73,   650,   913,   466,  7467, -1423, 12399,  1041,   842,
     990, -1423, -1423, -1423, -1423,   987, 12399, -1423, 12399, -1423,
    1019,  1011, 11829,  1025,  7467,   -49,   995,    42,   453,   894,
   -1423, -1423,   688,    21,  1039, 11829,  1027,  1049,   962,   953,
    1021,   990,   994,  1023,  1054,   990,  7467,   -40, -1423, -1423,
   -1423,  1003, -1423, -1423, -1423, -1423,  1040,  7467,  7467,  1012,
   -1423,  1062,  1063,  4189, -1423,   977,   980,  1016, 12399, -1423,
   12399, -1423,  7467,  1028,   975,  7467,   412,   423,   424,  1130,
   -1423,   244, -1423,   173, -1423, -1423,  1137, -1423,   699,  7467,
    7467,  7467,   719,  7467,  7467,  7467,  7467,  7467,  7467,  1050,
    7467,  7467, -1423, -1423,  5679,  1017,  1018,  1020,  1022,   808,
     355,   939, -1423,   358, -1423,    94,   158,   666,  5381,  5381,
    5381,  1091, -1423,  7467,   776,  1070, -1423, 12399,  1071, -1423,
   -1423,  7467,    82,   478,   148, -1423,   917,   386,   923,   925,
   -1423, -1423,   783, -1423,   924,   480,  1032,  1033, 12114,  1038,
   -1423,   527, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423,
   -1423,  1035, -1423, -1423, -1423,  7467, -1423, -1423, -1423, -1423,
   -1423, -1423, -1423, -1423, -1423,   622, -1423,  1150,   718, -1423,
   -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423,   918, -1423,
   -1423,  1152, -1423, -1423, -1423, -1423, -1423,   575,  1160, -1423,
     716, -1423, -1423, -1423,   890,   518,   897,   632,   898,   900,
     831, -1423,   527,  8063,   929,   887, -1423,  1039,   650,   970,
    1010,  4189,  1036,  1042,  1053,  1043,  1044, 12399,   249, -1423,
   12399, -1423,  7467,  1052,  7467,  1078,  7467,    16,  1060,  7467,
    1064, -1423,  1094,  1095,  7467, 12399,   772,  1131, -1423, -1423,
   -1423, -1423, -1423, -1423, 11829, -1423,  4189,   990,  1101, -1423,
   -1423, -1423,   990,  1101, -1423,  7467,  1072,  4189, 12399, -1423,
   -1423,  7467,  7467,   748, -1423,    22,   752, -1423, 10974,   764,
   -1423,   778, -1423,  1031, -1423, -1423,  4189,  1045,  1046, -1423,
    7467, -1423, -1423,  1029,  1062,  1119, -1423,  1088, -1423,   510,
   -1423, -1423,  1213, -1423, -1423,  4189, 12399, -1423,   633, -1423,
   -1423, -1423,  1051,   996,  1008, -1423, -1423, -1423,  1048,  1057,
   -1423, -1423, -1423, -1423, -1423,  1006, 12399,  1059, -1423, -1423,
    7467,  7467,  7467,  3891,  5679,  8957,   939, -1423,  8957, -1423,
    1090,   643, -1423, -1423, -1423,  1070, -1423,   990, -1423,   811,
   -1423,   274,  1121, -1423,  7467,  1129,  1009,   508,  1056, -1423,
      82,   989, -1423, -1423,   -78, -1423,   411,    64,   997,    82,
     411,  7765, -1423,   586, -1423, -1423, -1423, -1423, -1423, -1423,
      82,  1099,   966,   856,    64, -1423, -1423,   963,  1171, -1423,
   -1423, -1423, 10119,  1066,  1067,  1073, -1423, -1423, -1423, -1423,
   -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423,  1221,     7,
    1222,     7,   988,  1148, -1423,  1093, 12399,  1004, -1423, -1423,
    8063, -1423,  1074, -1423, -1423, -1423, -1423, -1423, -1423,  7467,
    1122, -1423, -1423,  7467, -1423,   431, -1423,  7467,  1123,  7467,
   -1423,  7467, 12399, 12399, -1423,   684, -1423,  7467, -1423,  1140,
    1142,  1174,   990,  1101, -1423,  7467,  1100, -1423, -1423, -1423,
    1089, -1423,    26,  7467,  4189,  1097,    31, -1423, 12399,  1104,
   11259,     9, -1423, 11544,  1106, -1423, -1423,  1109, -1423, -1423,
   -1423,  7467,   781,  1130, 12399,   689, -1423,  1111,  1130, 12399,
   -1423, -1423,  7467,  7467,  7467,  7467,  7467, -1423,  7467,   429,
     439,   449,   380, -1423, -1423, -1423, -1423, -1423,  1121, -1423,
   -1423, -1423,   990, -1423, -1423, -1423, -1423, -1423,  1112,  7765,
   -1423, -1423, -1423, -1423, -1423,   242,  7765,  7765,   338, -1423,
     923, -1423,   399, -1423,   925,    82,  1124, -1423, -1423,  1030,
   -1423, -1423, -1423, -1423,  1179,  1110, -1423,   463, -1423, -1423,
   -1423, -1423,    85,    85, -1423,     7, -1423, -1423,   469, -1423,
    1268,    64,  1202,  1113,  8063,   -26,  1069,  1132, -1423, -1423,
    7467, -1423,  7467,  1154, -1423,  7467, -1423, -1423, -1423,  1249,
   -1423, -1423,  5679,  7467,   990, -1423, -1423, -1423,  7467,  7467,
   -1423, -1423, -1423,  5679,  5679,  1210,  4189, 12399,  1120, 12399,
    7467, 12399,  1125,  5679, -1423,   231,    27,  1130, 12399, -1423,
    1116,  1130, -1423, -1423, -1423, -1423, -1423, -1423,  1117,  1062,
    1063,  7467, -1423, -1423, -1423, -1423,   634,  7765,  7765,   246,
     646, -1423, -1423, -1423, -1423, -1423, -1423,  7467, -1423, 11829,
   -1423, 11829,  1212, -1423, -1423, -1423,  1278, -1423, -1423, -1423,
    1055,  1206, -1423, -1423,  1208, -1423,   639, 12399,  1191,  1092,
   12399,  8063, -1423, -1423,  7467, -1423,  1199, -1423, -1423,  1101,
   -1423, -1423, 11829, -1423, -1423,  1223,  7467,  1133, -1423,  1226,
    5679, -1423, 12399,   215,   180, -1423,  1126,  1130, -1423,  1127,
    5679,   784,   522,   246,   246,  7765,   535, -1423, -1423, 11829,
   -1423, -1423,  1202,  8063, -1423,  1121,  1075, 12399,  1207,  1103,
    1208, -1423, 12399,  1138, 11829,  4189, 11829,  1143, -1423, -1423,
    1232,   507, -1423, -1423, -1423, -1423,  1145,   365, -1423, -1423,
   -1423,  1134, -1423,  1214, -1423,   246, -1423, -1423, -1423, -1423,
   -1423,  7467,  1076, 12399,  1215, -1423,  4189,  1149, -1423, -1423,
    1151,  7467, -1423, -1423, -1423, -1423, -1423, -1423, -1423, 12399,
   -1423,  1058,  1077, 12399, -1423, -1423,  7467,  5679,  1153,  1079,
    7467,  1080,  5679,  8063, -1423,  8063, -1423,  1136,  1081, 12399,
    1107,  1218, 12399,  1082,  8063, -1423
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       159,   440,   441,   442,   162,   162,   162,   762,   962,   116,
     118,   590,   854,   863,   803,   767,   765,   747,   855,   858,
     810,   771,   748,   749,   802,   864,   751,   861,   832,   812,
     787,   807,   808,   859,   856,   806,   753,   862,   754,   755,
     903,   916,   902,   804,   823,   817,   756,   805,   758,   757,
     904,   841,   842,   809,   784,   926,   927,   928,   929,   930,
     931,   932,   933,   934,   935,   936,   950,   957,   831,   827,
     818,   798,   746,     0,   826,   834,   843,   951,   822,   462,
     799,   800,   857,   952,   958,   819,   836,     0,   468,   429,
     464,   829,   764,   820,   821,   850,   824,   840,   849,   956,
     959,   770,   811,   852,   463,   839,   845,   750,     0,     0,
       0,   377,   837,   848,   853,   851,   830,   816,   905,   814,
     815,   953,     0,   376,     0,   954,   960,   846,   801,   825,
     955,   407,     0,   439,   847,   828,   835,   844,   838,   906,
     792,   797,   796,   795,   794,   793,   759,   813,     0,   763,
     860,   785,   894,   893,   895,   769,   768,   788,   900,   752,
     892,   897,   898,   889,   791,   833,   891,   901,   899,   890,
     789,   896,   908,   911,   912,   909,   910,   907,   760,   913,
     914,   915,   880,   879,   866,   783,   776,   873,   869,   786,
     782,   881,   882,   772,   773,   766,   775,   878,   877,   874,
     870,   887,   888,   886,   876,   872,   865,   774,   885,   884,
     778,   780,   779,   871,   875,   867,   781,   868,   777,   883,
     937,   938,   939,   940,   941,   942,   918,   919,   917,   923,
     924,   925,   920,   921,   922,   790,   943,   944,   945,   946,
     947,   948,   949,   159,     0,     2,   159,     5,     7,    19,
       0,    24,    27,    32,    33,    34,    35,    36,    37,    38,
      28,    54,    55,    29,    30,     0,    72,    75,    76,    31,
      77,    78,     0,   114,    79,    80,    81,    82,    14,   156,
     157,   158,   165,   167,   459,   168,     0,   169,   170,   171,
     172,   173,   174,   175,   178,   163,   206,   213,   208,   235,
     241,     0,   233,   234,   215,   209,   177,   210,   176,   211,
     214,   332,   334,   336,   346,   350,   352,   355,   360,   363,
     366,   368,   370,   372,     0,   374,   380,   382,     0,   398,
     381,   403,   406,   408,   411,   413,     0,   418,   415,     0,
     426,   436,   438,   412,   443,   450,   460,   451,   452,   453,
     456,   457,   454,   455,   475,   477,   478,   479,   476,   524,
     525,   526,   527,   528,   529,   435,   564,   556,   563,   562,
     561,   558,   560,   557,   559,   461,   458,   591,   592,    39,
     216,   217,   219,   218,   220,   212,     0,   437,   745,   761,
     854,   863,   861,   763,     0,   160,   161,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   122,   124,   125,     0,     0,     0,   162,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   260,   261,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   431,
     434,   421,     0,     0,   742,   747,   771,   749,   802,   864,
     751,   812,   753,   823,   756,   758,   757,   841,   950,   957,
     746,   951,   800,   952,   958,   824,   956,   959,   905,   953,
     954,   960,   955,   906,   900,   892,   898,   889,   789,   908,
     911,   912,   909,   760,   913,   427,   437,   745,   419,     0,
     185,   420,   423,   747,   748,   749,   753,   754,   755,   756,
     746,   752,   465,     0,   425,   424,   180,     0,     0,   751,
     758,   757,     0,   162,   466,   913,     0,   213,     0,   491,
       0,   430,   743,     0,   744,   401,   402,     0,   433,   432,
     422,   405,     0,     0,   520,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     3,     1,     6,     8,     0,     0,     0,
       0,     0,   159,   159,   159,   159,     0,   115,   166,   164,
       0,   183,     0,   194,     0,     0,     0,     0,     0,     0,
       0,     0,   199,   221,   240,   236,   242,   237,   239,   238,
       0,     0,     0,   391,     0,     0,   389,     0,   341,     0,
     390,   383,   388,   387,   386,   385,   384,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   379,   378,   375,     0,   399,
     404,     0,     0,     0,   414,   447,   417,   416,   428,     0,
     444,     0,     0,     0,   531,   533,   537,   590,     0,   120,
       0,    43,    40,    41,    44,    45,     0,     0,     0,     0,
      46,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   601,   602,   603,     0,    99,   138,     0,     0,
     108,     0,     0,     0,     0,   123,     0,     0,     0,   570,
       0,     0,     0,   566,     0,     0,     0,   580,     0,     0,
     223,   224,   243,   244,     0,     0,     0,     0,   130,     0,
     134,   162,   594,     0,    56,     0,    65,     0,     0,     0,
      57,     0,     0,     0,     0,     0,   742,   571,     0,     0,
       0,     0,   305,     0,     0,   569,     0,     0,     0,   588,
       0,     0,     0,     0,   574,     0,     0,   189,     0,     0,
     181,   179,     0,     0,     0,   465,     0,   467,     0,   492,
     491,   488,     0,     0,   522,   521,   400,     0,   519,     0,
     614,   615,   565,     0,     0,     0,     0,     0,     0,   620,
       0,   186,     0,   197,   198,     0,     0,     0,     0,     0,
     202,   203,    20,     0,    21,     0,     4,    25,     0,    11,
      26,     0,    15,   854,    73,    12,    74,    16,   187,   184,
     207,     0,     0,     0,     0,   200,   222,   278,   333,   335,
     339,   345,   344,   343,     0,   340,   337,   338,     0,   354,
     353,   351,   357,   358,   359,   356,   361,   362,   365,   364,
       0,     0,     0,     0,   396,     0,   409,   410,     0,   448,
     445,   473,     0,   961,   593,   471,     0,     0,   117,   119,
       0,     0,     0,    98,     0,    88,    90,    91,    92,    93,
      95,    96,    97,    89,    94,    84,    85,     0,     0,   104,
       0,   100,   102,   103,   110,     0,     0,    83,    42,     0,
       0,     0,     0,     0,     0,     0,   692,   697,     0,     0,
     693,   727,   680,   682,   683,   684,   686,   688,   687,   685,
     689,     0,     0,     0,     0,     0,   107,     0,   140,     0,
       0,   536,   530,   567,   568,     0,     0,   584,     0,   581,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     225,   226,     0,   231,   136,     0,     0,   131,     0,     0,
       0,     0,     0,     0,    58,     0,     0,     0,   259,   265,
     262,     0,   573,   572,   579,   587,     0,     0,     0,     0,
     535,     0,     0,     0,   392,     0,     0,     0,     0,   577,
       0,   575,     0,   190,     0,     0,     0,     0,     0,   491,
     489,     0,   480,     0,   469,   470,     0,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   188,   195,     0,   751,   758,   757,   913,     0,
       0,     0,   628,     0,   204,     0,     0,     0,   159,   159,
     159,     0,   232,     0,   289,   285,   287,     0,   279,   280,
     342,     0,     0,     0,     0,   658,   348,   631,   635,   637,
     639,   641,   644,   651,   652,   660,   864,   750,     0,   759,
     367,   542,   548,   549,   551,   595,   596,   552,   555,   369,
     371,   539,   373,   397,   449,     0,   446,   472,   121,    52,
      53,    50,    51,   127,   126,     0,    86,     0,     0,   105,
     106,   111,    70,    71,    48,    49,    69,   698,     0,   701,
     728,     0,   691,   690,   695,   694,   726,     0,     0,   703,
       0,   699,   702,   681,     0,     0,     0,     0,     0,     0,
       0,   139,   142,     0,     0,     0,   109,   112,     0,     0,
       0,   162,     0,     0,   588,     0,     0,     0,     0,   541,
       0,   246,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   227,     0,     0,     0,     0,   272,     0,   269,   274,
     230,   137,   132,   135,     0,   182,     0,     0,    67,    61,
      64,    63,     0,    59,   263,     0,     0,   162,     0,   303,
     307,     0,     0,     0,   310,     0,     0,   316,     0,     0,
     323,     0,   327,     0,   394,   393,   162,     0,     0,   191,
       0,   193,   304,     0,     0,     0,   492,     0,   481,     0,
     515,   512,     0,   516,   517,     0,     0,   511,     0,   486,
     514,   513,     0,     0,     0,   607,   608,   604,     0,     0,
     612,   613,   609,   618,   616,     0,     0,     0,   622,   196,
       0,     0,     0,     0,     0,     0,   623,   624,     0,   205,
      22,     0,    13,    17,    18,   286,   298,     0,   299,     0,
     290,   291,   292,   293,     0,   282,     0,     0,     0,   642,
     655,     0,   347,   349,     0,   674,     0,     0,     0,     0,
       0,     0,   630,   632,   633,   669,   670,   671,   673,   672,
       0,     0,   646,   645,     0,   649,   653,   667,   665,   664,
     657,   661,     0,     0,     0,     0,   545,   547,   546,   543,
     540,   474,   129,   128,    87,   101,   715,   696,     0,   720,
       0,   720,   709,   704,   143,     0,     0,     0,   113,   141,
       0,    23,     0,   585,   586,   589,   582,   583,   245,     0,
       0,   258,   250,     0,   254,     0,   248,     0,     0,     0,
     267,     0,     0,     0,   229,   270,   273,     0,   133,     0,
       0,    66,     0,    60,   264,     0,     0,   306,   308,   313,
       0,   311,     0,     0,     0,     0,     0,   317,     0,     0,
       0,     0,   324,     0,     0,   328,   395,     0,   578,   576,
     192,     0,     0,   491,     0,     0,   523,     0,   491,     0,
     487,    10,     0,     0,     0,     0,     0,   621,     0,     0,
       0,     0,     0,   625,   629,   302,   300,   301,   294,   295,
     296,   288,     0,   283,   281,   659,   650,   656,     0,     0,
     729,   730,   740,   739,   738,     0,     0,     0,     0,   731,
     636,   737,     0,   634,   638,     0,     0,   643,   647,     0,
     668,   663,   666,   662,     0,     0,   553,     0,   550,   600,
     544,   716,     0,     0,   714,   721,   722,   718,     0,   713,
       0,   711,     0,     0,     0,     0,     0,     0,   532,   247,
       0,   256,     0,     0,   252,     0,   255,   268,   276,   277,
     271,   228,     0,     0,     0,    62,   266,   538,     0,     0,
     314,   318,   312,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   534,     0,     0,   491,     0,   518,
       0,   491,   605,   606,   610,   611,   617,   619,     0,     0,
       0,     0,   626,   297,   284,   654,   741,     0,     0,   733,
       0,   679,   678,   677,   676,   675,   640,     0,   732,     0,
     597,     0,     0,   725,   724,   723,     0,   717,   710,   708,
       0,   705,   706,   700,   144,   146,   148,     0,     0,     0,
       0,     0,   251,   249,     0,   257,     0,   201,   331,    68,
     309,   315,     0,   329,   325,     0,     0,     0,   319,     0,
       0,   321,     0,   501,   495,   490,     0,   491,   482,     0,
       0,     0,     0,   735,   734,     0,     0,   598,   554,     0,
     719,   712,     0,     0,   150,   149,     0,     0,     0,     0,
     145,   253,     0,     0,     0,     0,     0,     0,   509,   503,
       0,   502,   504,   510,   507,   497,     0,   496,   498,   508,
     484,     0,   483,     0,   627,   736,   648,   599,   707,   147,
     151,     0,     0,     0,     0,   275,     0,     0,   322,   320,
       0,     0,   494,   505,   506,   493,   499,   500,   485,     0,
     152,     0,     0,     0,   330,   326,     0,     0,     0,     0,
       0,     0,     0,     0,   154,     0,   153,     0,     0,     0,
       0,     0,     0,     0,     0,   155
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1423, -1423,  -214,  1096, -1423,  1105,  1108, -1423,  1114,  -522,
   -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423,
    -944, -1423, -1423, -1423, -1423,  -226,  -555, -1423,   649,  -447,
   -1423, -1423, -1423, -1423, -1423,   232,   443, -1423, -1423,    -9,
    -235,   943, -1423,   945, -1423, -1423,  -612, -1423,   382, -1423,
     197, -1423,  -242,  -287, -1423,  -535, -1423,     5,    20,    40,
    -246,  -164, -1423,  -819, -1423, -1423,  -506, -1423, -1423, -1423,
   -1423, -1423, -1423, -1423, -1423, -1423, -1423,   542,    24,   800,
       0, -1423, -1423, -1423, -1423,   403, -1423, -1423,  -274, -1423,
       8, -1423, -1423,   196,  -690,  -670, -1423, -1423,   614, -1423,
   -1423,    -7,   194, -1423, -1423, -1423,    86, -1423, -1423,   320,
      91, -1423, -1423,    95, -1224, -1423,   863,   179, -1423, -1423,
     175,  -953, -1423, -1423,   176, -1423, -1423, -1170, -1177, -1423,
     172, -1423, -1423,   779,   777, -1423,  -458, -1423, -1423,  -625,
     326,  -614,   316,   324, -1423, -1423, -1423, -1423, -1423,  1083,
   -1423, -1423, -1423, -1423,  -807,  -311, -1087, -1423,   -93, -1423,
   -1423, -1423, -1423, -1423, -1423, -1423,   -33,  -766, -1423, -1423,
     546,  -245, -1423,  -398, -1423, -1423, -1423, -1423, -1423, -1423,
   -1423,   727, -1423,  -961, -1423,   162, -1423,   613,  -762, -1423,
   -1423, -1423, -1423, -1423,  -262,  -255, -1163,  -805, -1423, -1423,
   -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423,   540,  -725,
    -703,   262,  -812, -1423,   107,  -779, -1423, -1423, -1423, -1423,
   -1423, -1423, -1423,   978,   998,  -128,   457,   301, -1423, -1423,
   -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423,
   -1423, -1423,   153, -1423, -1423,   144, -1423,   147,  -997, -1423,
   -1423, -1423,   114,   105,   -48,   353, -1423, -1423, -1423, -1423,
   -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423, -1423,   116,
   -1423, -1423, -1423,   -42,   352,   500, -1423, -1423, -1423, -1423,
   -1423,   297, -1423, -1423, -1422, -1423, -1423, -1423,  -508, -1423,
      93, -1423,   -53, -1423, -1423, -1423, -1423, -1215, -1423,   133,
   -1423,  -368,  -360,  1005,    25, -1423
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   244,   815,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
    1188,   739,   262,   263,   264,   265,   266,   267,   895,   896,
     897,   268,   269,   270,   901,   902,   903,   271,   419,   272,
     273,   668,   274,   421,   422,   423,   436,   729,   730,   275,
    1141,   276,  1584,  1585,   277,   278,   279,   527,   280,   281,
     282,   283,   284,   732,   285,   286,   510,   287,   288,   289,
     290,   291,   292,   602,   293,   294,   810,   811,   295,   296,
     537,   298,   603,   434,   962,   963,   299,   604,   300,   606,
     538,   302,   722,   723,  1176,   443,   303,   444,   445,   726,
    1177,  1178,  1179,   607,   608,  1058,  1059,  1443,   609,  1055,
    1056,  1280,  1281,  1282,  1283,   304,   751,   752,   305,  1203,
    1204,  1392,   306,  1206,  1207,   307,   308,  1209,  1210,  1211,
    1212,   309,   310,   311,   312,   844,   313,  1292,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     627,   628,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     654,   655,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   872,   353,   354,   355,  1238,   780,   781,   782,  1615,
    1656,  1657,  1650,  1651,  1658,  1652,  1239,  1240,   356,   357,
    1241,   358,   359,   360,   361,   362,   363,   364,  1090,   957,
    1080,  1329,  1081,  1477,  1082,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   758,  1153,   375,   376,   377,
     378,  1084,  1085,  1086,  1087,   379,   380,   381,   382,   383,
     384,   798,   799,   385,  1266,  1267,  1552,  1043,  1066,  1302,
    1303,  1067,  1068,  1069,  1070,  1071,  1312,  1467,  1468,  1072,
    1315,  1073,  1448,  1074,  1075,  1320,  1321,  1473,  1471,  1304,
    1305,  1306,  1307,  1564,   696,   922,   923,   924,   925,   926,
     927,  1131,  1493,  1581,  1132,  1491,  1579,   928,  1341,  1488,
    1484,  1485,  1486,   929,   930,  1308,  1316,  1458,  1309,  1454,
    1293,   386,   543,   387,   388,   389
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int xquery_parser::yytable_ninf_ = -743;
  const short int
  xquery_parser::yytable_[] =
  {
       297,   669,   669,   420,   297,   297,   297,   851,   301,   394,
     397,   398,   301,   301,   301,   572,   977,   649,  1011,   852,
     853,   854,   855,   580,   395,   395,   395,   605,   989,   824,
     826,  1193,  1402,   671,   955,   588,   583,   587,  1205,   551,
     505,  1064,  1003,  1042,   396,   396,   396,   819,   822,   825,
     827,   585,  1237,   691,   956,  1412,  1345,  1439,  1440,   801,
     817,   820,   581,  1104,   706,  1288,   882,     9,    10,   581,
    1582,   736,   740,   581,   951,  1420,   959,   581,  1165,   784,
     828,  1083,  1083,   464,   829,   581,  1108,   748,   405,   553,
     581,  1587,     9,    10,  1029,   581,   464,  1162,   507,  1469,
     711,  1195,   592,   401,   402,  1018,   403,   404,   297,   590,
     667,   667,   507,   405,   441,   408,   301,   712,   727,  1083,
    1613,  1393,   406,   407,   592,  1393,  1529,   911,   395,   912,
    1393,   648,   952,   536,   953,   507,   986,  1450,   953,   592,
     408,   986,  1482,  -742,  1016,   409,   424,   507,   528,   507,
     588,   877,   702,  1142,   840,   124,   841,   842,  1089,   843,
    1455,   845,  1367,   566,   438,   556,   737,   557,   455,   846,
     847,   427,   913,  1083,   439,  1451,   410,   411,   412,  1111,
    1094,  1338,  1230,  1231,   954,   587,  1083,   728,  1166,  1230,
      79,    79,   591,  1022,  1530,   401,   402,  1588,   403,   404,
     440,   945,   592,  1017,    90,    90,  1483,  1394,  1654,  1614,
    1668,  1519,   877,   738,  1553,   407,  1524,   987,   946,   777,
    1648,  1030,  1005,   442,  1230,   413,   735,  1019,  1020,   104,
     104,   878,   442,  1170,  1061,  1402,   960,  1062,   650,  1181,
    1340,   713,  1021,   297,   456,   785,   297,  1227,  1383,  1159,
     582,   301,  1420,  1396,   301,  1064,  1064,   584,   124,   824,
     826,   812,  1182,  1497,   605,   814,  1324,  1167,  1237,   442,
    1271,   554,  1105,  1048,   961,  1232,  1580,  1237,  1050,   981,
    1589,   297,   588,  1270,   414,  1163,  1333,  1168,   442,   301,
     817,   820,   879,  1447,  1557,  1233,  1032,  1234,   947,  1083,
    1290,   873,  1233,   656,  1234,   589,   658,  1196,   948,   966,
     442,   457,   458,  1655,   442,  1023,  1024,   413,   592,  1456,
    1457,   908,   592,   914,   124,  1235,   415,   703,  1012,   110,
    1025,   587,  1235,   592,   998,   704,   915,  1233,   916,  1234,
    1063,     9,    10,     9,    10,   953,   122,  1649,  1612,   917,
     918,   919,   416,   920,   835,   921,   818,   821,     9,    10,
     417,   507,  1634,   592,   507,   813,  1236,  1235,   418,  1142,
    1558,   974,  1000,  1228,  1230,   970,   414,   592,   973,  1277,
    1621,   594,  1099,   594,   148,   595,  1060,   595,   949,   967,
     596,   680,   596,  1654,  1013,  1359,   297,   594,   969,  1100,
    1279,   595,   991,   630,   301,  1083,   596,  1586,   597,   869,
     597,  1670,   869,   992,   999,   869,  1530,   952,   415,  1101,
     589,   631,  1348,   681,   597,   297,   565,   297,   586,  1083,
     678,   507,   710,   301,   507,   301,  1102,   952,   507,  1229,
     997,   507,   507,   802,  1402,   707,   592,   395,  1106,   507,
    1065,   297,  1001,   716,  1237,   507,   297,  1034,   507,   301,
    1106,   733,   588,   399,   301,   708,   507,   396,  1360,   988,
     745,   754,   507,   507,   507,   507,   760,   756,   757,  1098,
     507,  1378,  1294,  1064,   976,   592,   763,  1233,   507,  1234,
     592,   708,  1064,   824,   826,   824,   708,  1368,  1686,  1042,
    1095,  1095,  1434,  1064,  1586,  1399,   598,   667,   598,   599,
    1263,   599,  1648,  1272,  1273,  1274,  1230,  1235,   592,  1230,
    1231,   633,   598,  1014,   600,   599,   778,   953,   297,   592,
     592,   952,  1551,   297,   507,   592,   301,  1112,  1113,   450,
    1264,   301,  1116,  1083,   577,   592,  1586,   952,   507,   601,
     634,   601,   589,   395,  1295,   592,   630,   507,   866,   867,
     578,   588,  1015,   635,   783,   601,  1268,  1041,   420,  1571,
    1599,   297,  1150,   396,   631,  1576,   787,  1502,  1002,   301,
    1096,  1097,   297,   297,   297,   297,  1045,    79,  1268,   507,
     301,   301,   301,   301,   806,   808,  1396,   636,  1223,  1169,
     297,    90,   592,  1189,  1049,   400,  1561,  1189,   301,  1224,
    1225,   807,  1232,  1562,   592,  1548,  1706,   431,  1707,  1476,
     676,  1083,   432,  1563,  1083,  1549,   104,  1715,   592,  1233,
    1061,  1234,  1233,  1062,  1234,  1550,   677,  1296,  1297,  1683,
    1298,   592,  1230,  1231,  1046,  1128,   686,  1299,   687,  1572,
     425,  1536,  1122,   426,   124,  1577,  1540,  1300,  1064,  1235,
     578,  1129,  1235,  1123,  1065,  1065,   110,  1561,   433,  1301,
    1326,  1338,   865,   428,  1562,  1503,  1462,   868,  1452,  1093,
     688,   435,  1294,   122,  1563,  1453,   507,  1339,   686,  1134,
     687,  1445,     9,    10,  1135,   711,   898,  1528,  1230,  1231,
    1532,  1103,  1327,  1414,  1130,  1664,   689,   884,   297,  1136,
     507,  1137,   712,   405,   437,   824,   301,   731,  1666,  1328,
    1138,   148,   406,  1124,   507,   461,  1317,  1318,   507,   507,
    1340,   297,   589,   952,  1125,  1232,   968,  1172,   899,   301,
     408,  1172,  1173,   900,  1277,   409,  1173,  1139,   689,  1319,
     507,   395,   507,   649,  1295,  1233,   462,  1234,  1332,   463,
     507,   297,   297,   507,  1144,  1174,   605,   507,   690,   301,
     301,   396,   639,  1145,   731,  1616,   410,   411,  1051,  1619,
     953,   995,   996,   459,   953,  1235,   640,   448,  1259,   110,
    1083,  1232,  1083,   692,   693,   694,  1006,  1007,  1008,   630,
     808,   708,   708,   630,   507,  1175,   122,  1039,  1653,  1659,
     690,  1233,  1128,  1234,   420,  1040,   672,   631,  1152,  1381,
    1155,   631,   562,  1083,  1189,  1172,  1419,   563,  1129,   673,
    1173,  1559,  1560,   637,   507,  1556,   674,  1296,  1297,   632,
    1298,  1235,   638,  1625,   148,   110,  1653,  1202,   700,   675,
    1083,  1202,  1659,   701,   899,  1661,   507,  1300,   449,   900,
    1390,  1635,   122,  1400,  1395,  1083,  1627,  1083,  1628,  1301,
    1217,  1276,  1218,  1140,   572,   429,  1401,  1403,   430,  1269,
    1400,  1277,  1538,  1400,   657,   507,   507,   507,   507,   660,
    1404,  1278,  1065,  1535,   446,   451,  1663,   447,   452,  1643,
     148,  1065,  1279,   460,  1117,  1118,  1119,   651,   652,  1435,
    1120,   453,  1065,   885,   886,   887,   888,   889,   890,   891,
     892,   893,   894,   507,   454,   559,  1667,   560,   653,  1243,
     659,  1244,  1623,  1624,  1114,  1115,   612,   507,  1436,  1437,
    1379,  1677,   508,  1680,   613,   614,   509,   615,   511,  1248,
     540,  1249,   416,   856,   857,   616,   849,   850,   512,   617,
     417,   618,   507,   858,   859,   523,   619,   524,   418,  1091,
    1091,   507,   525,   507,  1573,  1574,   541,   507,   548,   549,
     550,   555,   552,   620,   561,   564,   558,   567,   571,   568,
     507,   569,   574,   297,   570,   592,   611,   593,   610,   629,
    1665,   301,   641,   643,   642,   653,   621,   622,   623,   624,
     625,   626,   644,  1213,  1515,   661,   662,   663,   835,   464,
     682,   664,   684,   507,   665,   507,   666,   685,   695,   699,
     709,   725,   731,   708,  1039,   734,   720,   721,   420,   742,
     743,   744,  1040,   761,   762,   426,   755,   768,   297,   297,
     297,   430,   447,   452,   776,   463,   301,   301,   301,   770,
     772,   779,   773,   774,   786,   788,   789,  1065,   792,   797,
     803,   816,   804,   831,  1554,   861,   832,   848,   506,   809,
     862,   833,   507,   860,   834,  1287,   874,   863,   880,   881,
     883,   905,   522,   906,   909,   910,   932,   933,   935,   941,
     940,   931,   937,   507,   942,   943,   944,   950,   965,   971,
     972,   975,   982,   983,   984,   539,   985,   993,  1026,   990,
     994,  1027,  1033,  1047,  1028,  1031,  1057,   544,  1053,   547,
    1107,  1126,   900,   952,  1127,  1148,  1157,  1158,  1143,  1151,
    1149,  1164,  1160,  1184,   727,  1185,  1189,  1171,  1521,  1186,
    1192,   297,  1187,  1190,  1191,  1197,  1352,  1198,  1201,   301,
    1214,  1202,  1208,  1215,  1221,  1226,  1242,  1256,  1216,  1220,
     688,   395,  1260,  1261,  1263,  1262,  1284,  1286,  1330,   667,
    1310,  1337,   507,  1265,  1311,   507,   297,  1322,  1323,  1342,
    1314,   396,  1347,  1325,   301,  1350,  1355,   297,  1363,  1351,
     507,  1291,  1386,  1336,  1365,   301,  1369,  1382,  1377,   507,
    1371,  1372,  1373,  1385,  1406,  1346,   297,   395,  1400,  1413,
    1416,  1407,  1353,   507,   301,  1411,  1277,  1422,  1354,  1356,
    1357,  1408,  1409,   507,  1442,   297,   395,   396,  1449,  1423,
    1421,  1426,  1446,   301,  1428,  1465,  1459,  1466,  1470,  1472,
    1481,  1487,  1478,  1479,  1492,  1417,   396,  1498,  1490,  1480,
    1496,   507,  1494,  1039,  1039,  1512,  1597,  1513,  1500,  1505,
    1514,  1040,  1040,  1569,  1518,   708,  1567,  1601,  1521,  1424,
    1603,   507,  1523,  1517,  1429,  1430,  1431,  1611,  1425,  1526,
     507,  1533,  1534,   507,  1539,  1555,  1570,  1578,  1128,  1583,
    1594,  1591,  1596,   807,  1602,  1606,  1629,  1630,  1637,  1568,
    1610,  1618,  1632,  1620,  1633,  1638,  1642,  1644,  1645,  1631,
    1646,  1660,  1662,  1676,  1673,  1682,  1674,  1685,  1681,  1688,
    1711,  1689,  1693,  1708,  1696,  1712,  1697,   907,  1702,   573,
    1335,   506,  1109,   670,   506,  1349,  1669,   507,  1183,  1640,
    1699,   575,  1044,  1358,   576,  1590,   790,   791,   980,   793,
     794,   795,   796,   579,  1603,   705,  1180,  1709,  1510,   805,
    1376,   507,  1444,  1275,  1379,  1441,  1438,  1387,  1391,  1671,
    1691,  1700,  1397,  1405,  1703,  1705,   769,  1714,   839,   838,
     876,  1415,   830,  1010,   297,  1687,  1684,   507,   507,  1678,
     836,   837,   301,  1092,  1344,  1156,   714,   647,  1334,  1427,
    1433,   679,  1432,  1460,   683,  1464,  1289,  1566,   544,  1463,
    1565,   697,   698,   507,  1313,   507,   715,  1343,   507,   544,
    1694,  1133,  1575,  1461,  1489,   719,     0,     0,   724,   507,
       0,     0,     0,     0,   507,     0,   741,     0,     0,     0,
       0,  1694,   544,   749,   750,   753,  1678,     0,     0,   871,
     759,     0,     0,   871,     0,     0,     0,     0,   766,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   936,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1039,     0,   767,     0,     0,     0,     0,     0,
    1040,     0,     0,  1039,  1039,     0,   297,     0,   753,     0,
       0,  1040,  1040,  1039,   301,     0,     0,   775,     0,     0,
       0,  1040,     0,   979,     0,     0,     0,     0,     0,     0,
       0,     0,   507,     0,   507,     0,   507,     0,     0,     0,
       0,     0,     0,   507,     0,     0,     0,     0,  1004,   800,
       0,     0,     0,     0,     0,  1622,     0,     0,   836,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1626,     0,     0,   507,     0,   507,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1039,     0,   507,     0,     0,   507,     0,     0,  1040,     0,
    1039,     0,     0,     0,     0,     0,     0,   507,  1040,     0,
       0,     0,     0,  1054,     0,     0,     0,   507,     0,     0,
       0,     0,     0,     0,     0,   297,     0,     0,     0,     0,
       0,     0,     0,   301,   507,     0,     0,     0,     0,     0,
       0,     0,   507,     0,     0,     0,   544,   507,     0,   507,
       0,   507,     0,     0,     0,     0,   297,     0,     0,     0,
       0,     0,     0,     0,   301,     0,     0,     0,     0,     0,
     904,     0,     0,     0,     0,     0,     0,  1039,   507,     0,
    1110,     0,  1039,     0,   934,  1040,     0,     0,   938,   939,
    1040,     0,     0,     0,   507,     0,     0,     0,   507,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     958,     0,   964,     0,   507,  1146,     0,   507,     0,     0,
     544,     0,     0,   544,     0,     0,     0,   978,     0,     0,
       0,     0,     0,     0,  1161,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1194,     0,     0,     0,
       0,     0,     0,     0,  1009,     0,     0,  1199,  1200,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1219,     0,     0,  1222,     0,     0,     0,     0,
       0,     0,     0,     0,   506,     0,     0,     0,     0,  1245,
    1246,  1247,     0,  1250,  1251,  1252,  1253,  1254,  1255,     0,
    1257,  1258,     0,     0,     0,     0,  1052,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1054,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1088,  1088,  1088,  1088,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1331,     0,     0,     0,     0,
       0,     0,     0,  1088,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1147,     0,     0,     0,     0,     0,     0,     0,
       0,  1154,     0,  1154,     0,     0,     0,  1088,     0,     0,
       0,     0,  1362,     0,  1364,     0,  1366,     0,     0,  1370,
    1088,     0,     0,     0,  1374,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1380,     0,     0,     0,
       0,     0,     0,     0,     0,  1384,     0,     0,     0,     0,
       0,  1388,  1389,   759,     0,   759,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1410,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1285,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1088,  1054,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1499,
       0,     0,   724,  1501,     0,  1361,     0,  1504,     0,  1506,
       0,  1507,     0,     0,     0,     0,     0,  1511,     0,     0,
    1375,     0,     0,     0,     0,  1516,     0,     0,     0,  1088,
       0,     0,     0,  1520,  1522,     0,     0,     0,     0,     0,
       0,     0,     0,   753,     0,     0,     0,     0,     0,     0,
       0,  1380,     0,  1088,     0,     0,     0,     0,     0,     0,
       0,     0,  1542,  1543,  1544,  1545,  1546,     0,  1547,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1418,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   800,     0,     0,     0,     0,     0,     0,     0,     0,
     506,     0,     0,   506,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1592,     0,  1593,     0,     0,  1595,     0,     0,     0,     0,
       0,     0,     0,  1598,     0,     0,     0,     0,  1600,  1522,
       0,     0,     0,     0,     0,     0,  1604,  1088,     0,     0,
    1608,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1495,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1508,  1509,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1641,     0,     0,     0,     0,     0,
       0,     0,     0,  1525,     0,  1088,  1604,     0,  1088,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1537,
       0,     0,     0,     0,  1541,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1679,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1690,     0,     0,     0,     0,  1695,     0,     0,     0,
       0,  1679,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1695,     0,     0,     0,
    1704,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1605,     0,  1607,     0,  1609,     0,     0,     0,
       0,     0,     0,  1617,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1088,     0,  1088,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1636,     0,     0,  1639,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1088,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1647,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1088,     0,     0,     0,     0,     0,
       0,     0,  1672,     0,     0,     0,     0,  1675,     0,  1088,
       0,  1088,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1692,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1698,     0,     0,     0,  1701,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     0,     0,     0,  1710,     0,     0,  1713,     3,     4,
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
     108,     0,     0,   109,   110,   111,   112,   113,     0,     0,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
       0,   122,     0,   123,   124,     0,     0,   125,   126,   127,
       0,     0,     0,   128,     0,   129,   130,     0,   131,   132,
     133,     0,   134,     0,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,     0,     0,   146,   147,   148,
       0,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,     0,    11,     0,     0,     0,
     390,   391,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,   392,    28,    29,    30,
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
       0,     0,   109,   110,   111,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,     0,
     122,     0,   123,   124,     0,     0,   125,   126,   127,     0,
     526,     0,   128,     0,   129,   130,     0,   131,   132,   133,
       0,   134,     0,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,     0,     0,   146,   147,   148,     0,
     393,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,     0,    11,     0,     0,     0,   390,   391,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,   392,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   108,     0,     0,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,     0,   122,     0,
     123,   124,     0,     0,   125,   126,   127,     0,   771,     0,
     128,     0,   129,   130,     0,   131,   132,   133,     0,   134,
       0,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,     0,     0,   146,   147,   148,     0,   393,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,     0,    11,     0,     0,     0,   390,   391,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,  1035,   392,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,  1036,  1037,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   108,     0,     0,   109,   110,
     111,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,     0,   122,     0,   123,   124,
       0,     0,   125,   126,   127,     0,   771,     0,   128,     0,
     129,   130,     0,   131,   132,   133,     0,   134,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
       0,     0,   146,   147,   148,     0,   393,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,  1038,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,     0,
      11,     0,     0,     0,   390,   391,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,  1035,
     392,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,  1036,  1037,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,    96,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   108,     0,     0,   109,   110,   111,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,     0,   122,     0,   123,   124,     0,     0,
     125,   126,   127,     0,   526,     0,   128,     0,   129,   130,
       0,   131,   132,   133,     0,   134,     0,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,     0,     0,
     146,   147,   148,     0,   393,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,  1038,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,     0,    11,     0,
       0,     0,   390,   391,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,   392,    28,
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
     107,   108,     0,     0,   109,   110,   111,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,     0,   122,     0,   123,   124,     0,     0,   125,   126,
     127,     0,     0,     0,   128,     0,   129,   130,     0,   131,
     132,   133,     0,   134,     0,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,     0,     0,   146,   147,
     148,     0,   393,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,     0,    11,     0,     0,     0,
      12,    13,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
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
       0,     0,   109,   110,   111,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,     0,
     122,     0,   123,   124,     0,     0,   125,   126,   127,     0,
       0,     0,   128,     0,   129,   130,     0,   131,   132,   133,
       0,   134,     0,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,     0,     0,   146,   147,   148,     0,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,     0,    11,     0,     0,     0,    12,    13,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   108,     0,     0,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,     0,   122,     0,
     123,   124,     0,     0,   125,   126,   127,     0,     0,     0,
     128,     0,   129,   130,     0,   131,   132,   133,     0,   134,
       0,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,     0,     0,   146,   147,   148,     0,   393,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,     0,    11,     0,     0,     0,    12,   391,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   108,     0,     0,   109,   110,
     111,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,     0,   122,     0,   123,   124,
       0,     0,   125,   126,   127,     0,     0,     0,   128,     0,
     129,   130,     0,   131,   132,   133,     0,   134,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
       0,     0,   146,   147,   148,     0,   393,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,     0,
      11,     0,     0,     0,   823,   391,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
     392,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,    96,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   108,     0,     0,   109,   110,   111,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,     0,   122,     0,   123,   124,     0,     0,
     125,   126,   127,     0,     0,     0,   128,     0,   129,   130,
       0,   131,   132,   133,     0,   134,     0,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,     0,     0,
     146,   147,   148,     0,   393,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,     0,    11,     0,
       0,     0,   390,   391,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,  1035,   392,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,  1036,  1037,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   108,     0,     0,   109,   110,   111,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,     0,   122,     0,   123,   124,     0,     0,   125,   126,
     127,     0,     0,     0,   128,     0,   129,   130,     0,   131,
     132,   133,     0,   134,     0,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,     0,     0,   146,   147,
     148,     0,   393,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,  1038,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     0,     0,     0,    11,     0,     0,     0,
     390,   391,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   529,   392,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,   530,
     531,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,   482,    82,
      83,    84,    85,    86,   532,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   533,
       0,     0,   109,   110,   111,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,     0,
     122,     0,   123,   124,     0,     0,   125,   126,   127,     0,
       0,     0,   128,   534,   129,   130,     0,   131,   132,   133,
       0,   134,     0,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,     0,     0,   146,   147,   148,     0,
     393,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   499,   500,   501,   502,   176,   177,   503,
     535,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     0,     0,    11,     0,     0,     0,   390,   391,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   529,   392,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,   530,   531,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   482,    82,    83,    84,
      85,    86,   532,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   533,     0,     0,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,     0,   122,     0,
     123,   124,     0,     0,   125,   126,   127,     0,   864,     0,
     128,     0,   129,   130,     0,   131,   132,   133,     0,   134,
       0,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,     0,     0,   146,   147,   148,     0,   393,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   499,   500,   501,   502,   176,   177,   503,   535,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     0,
       0,     0,    11,     0,     0,     0,   390,   391,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   529,   392,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,   530,   531,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   482,    82,    83,    84,    85,    86,
     532,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   533,     0,     0,   109,   110,
     111,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,     0,   122,     0,   123,   124,
       0,     0,   125,   126,   127,     0,     0,     0,   128,   870,
     129,   130,     0,   131,   132,   133,     0,   134,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
       0,     0,   146,   147,   148,     0,   393,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   499,
     500,   501,   502,   176,   177,   503,   535,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     0,     0,     0,
      11,     0,     0,     0,   390,   391,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   529,
     392,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,   530,   531,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,   482,    82,    83,    84,    85,    86,   532,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,    96,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   533,     0,     0,   109,   110,   111,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,     0,   122,     0,   123,   124,     0,     0,
     125,   126,   127,     0,     0,     0,   128,   875,   129,   130,
       0,   131,   132,   133,     0,   134,     0,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,     0,     0,
     146,   147,   148,     0,   393,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   499,   500,   501,
     502,   176,   177,   503,   535,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     0,     0,     0,    11,     0,
       0,     0,   390,   391,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,   468,    25,   470,   392,    28,
     471,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,   473,     0,    45,    46,
      47,   475,   476,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     482,    82,    83,    84,    85,    86,   532,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   485,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   533,     0,     0,   109,   110,   645,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,     0,   122,     0,   646,   124,     0,     0,   125,   126,
     127,     0,     0,     0,   128,     0,   129,   130,     0,   131,
     132,   133,     0,   134,     0,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,     0,     0,   146,   147,
     148,     0,   393,   150,   151,   152,   153,   154,   155,   156,
     157,   494,   159,   495,   161,   496,   497,   164,   165,   166,
     167,   168,   169,   498,   171,   499,   500,   501,   502,   176,
     177,   503,   504,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     0,     0,     0,    11,     0,     0,     0,
     390,   391,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   529,   392,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,   530,
     531,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,   482,    82,
      83,    84,    85,    86,   532,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   533,
       0,     0,   109,   110,   111,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,     0,
     122,     0,   123,   124,     0,     0,   125,   126,   127,     0,
       0,     0,   128,     0,   129,   130,     0,   131,   132,   133,
       0,   134,     0,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,     0,     0,   146,   147,   148,     0,
     393,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   499,   500,   501,   502,   176,   177,   503,
     535,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     0,     0,    11,     0,     0,     0,   390,   391,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   468,    25,   470,   392,    28,   471,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,   473,     0,    45,    46,    47,   475,   476,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   482,    82,    83,    84,
      85,    86,   532,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   485,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   533,     0,     0,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,     0,   122,     0,
     123,   124,     0,     0,   125,   126,   127,     0,     0,     0,
     128,     0,   129,   130,     0,   131,   132,   133,     0,   134,
       0,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,     0,     0,   146,   147,   148,     0,   393,   150,
     151,   152,   153,   154,   155,   156,   157,   494,   159,   495,
     161,   496,   497,   164,   165,   166,   167,   168,   169,   498,
     171,   499,   500,   501,   502,   176,   177,   503,   504,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     0,
       0,     0,    11,     0,     0,     0,   390,   391,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   468,
      25,   470,   392,    28,   471,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
     473,     0,    45,    46,    47,   475,   476,    50,   477,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   482,    82,    83,    84,    85,    86,
     532,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   485,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   533,     0,     0,   109,   110,
       0,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,     0,   122,     0,     0,     0,
       0,     0,   125,   126,   127,     0,     0,     0,   128,     0,
     129,   130,     0,   131,   132,   133,     0,   134,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
       0,     0,   146,   147,   148,     0,   393,   150,   151,   152,
     153,   154,   155,   156,   157,   494,   159,   495,   161,   496,
     497,   164,   165,   166,   167,   168,   169,   498,   171,   499,
     500,   501,   502,   176,   177,   503,   504,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     0,     0,     0,
      11,     0,     0,     0,   390,   391,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   468,    25,   470,
     392,    28,   471,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,   473,     0,
      45,    46,    47,   475,   476,    50,   477,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,   482,    82,    83,    84,    85,    86,   532,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   485,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   533,     0,     0,   109,   110,     0,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,     0,   122,     0,     0,     0,     0,     0,
     125,   126,   127,     0,     0,     0,   128,     0,   129,   130,
       0,     0,     0,   133,     0,   134,     0,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,     0,     0,
     146,   147,   148,     0,   393,   150,   151,   152,   153,   154,
     155,   156,   157,   494,   159,   495,   161,   496,   497,   164,
     165,   166,   167,   168,   169,   498,   171,   499,   500,   501,
     502,   176,   177,   503,   504,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       0,     0,     0,     7,     8,     0,     0,     0,   464,     0,
       0,     0,   390,   391,     0,    14,    15,    16,   465,    18,
      19,    20,   466,    22,   467,   468,   469,   470,   392,    28,
     471,    30,    31,     0,    32,    33,    34,    35,   472,    37,
      38,    39,    40,    41,    42,    43,   473,     0,    45,   474,
      47,   475,   476,    50,   477,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   478,
     479,    68,     0,    69,    70,    71,   480,     0,    74,    75,
      76,     0,     0,   481,    78,     0,     0,     0,     0,    80,
     482,    82,   483,   484,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   485,    97,    98,   486,   487,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
     107,     0,     0,     0,     0,     0,     0,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   488,   119,   120,
     489,     0,     0,     0,     0,     0,     0,     0,   490,   491,
     127,     0,     0,     0,   128,     0,   129,   492,     0,     0,
       0,   133,     0,   134,     0,   135,   136,   137,   138,   493,
     140,   141,   142,   143,   144,   145,     0,     0,   146,   147,
       0,     0,   393,   150,   151,   152,   153,   154,   155,   156,
     157,   494,   159,   495,   161,   496,   497,   164,   165,   166,
     167,   168,   169,   498,   171,   499,   500,   501,   502,   176,
     177,   503,   504,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     0,     0,
       0,     7,     8,     0,     0,     0,   464,     0,     0,     0,
     390,   391,     0,    14,    15,    16,   513,    18,    19,    20,
     466,   514,   515,   468,   469,   470,   392,    28,   471,    30,
      31,     0,    32,    33,    34,    35,   516,    37,   517,   518,
      40,    41,    42,    43,   473,     0,    45,   519,    47,   475,
     476,    50,   477,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   478,   479,    68,
       0,    69,    70,    71,   520,     0,    74,    75,    76,     0,
       0,   481,    78,     0,     0,     0,     0,    80,   482,    82,
     483,   484,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   485,    97,    98,   486,   487,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   488,   119,   120,   489,     0,
       0,     0,     0,     0,     0,     0,   490,   491,   127,     0,
       0,     0,   128,     0,   129,   492,     0,     0,     0,   133,
       0,   134,     0,   135,   136,   137,   138,   493,   140,   141,
     142,   143,   144,   145,     0,     0,   146,   147,     0,     0,
     393,   150,   151,   152,   153,   154,   155,   156,   157,   494,
     521,   495,   161,   496,   497,   164,   165,   166,   167,   168,
     169,   498,   171,   499,   500,   501,   502,   176,   177,   503,
     504,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   542,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     0,     0,   746,
       0,     0,     0,   390,   391,     0,    14,    15,    16,   513,
      18,    19,    20,   466,   514,   515,   468,   469,   470,   392,
      28,   471,    30,    31,     0,    32,    33,    34,    35,   516,
      37,   517,   518,    40,    41,    42,    43,   473,     0,    45,
     519,    47,   475,   476,    50,   477,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     478,   479,    68,     0,    69,    70,    71,   520,     0,    74,
      75,    76,     0,     0,   481,    78,     0,     0,     0,     0,
      80,   482,    82,   483,   484,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   485,    97,    98,   486,   487,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,   107,     0,     0,     0,     0,     0,     0,   112,   113,
       0,     0,     0,     0,   114,   115,   116,   117,   488,   119,
     120,   489,     0,     0,     0,     0,     0,     0,     0,   490,
     491,   127,     0,     0,     0,   128,   747,   129,   492,     0,
       0,     0,     0,     0,   134,     0,   135,   136,   137,   138,
     493,   140,   141,   142,   143,   144,   145,     0,     0,   146,
     147,     0,     0,   393,   150,   151,   152,   153,   154,   155,
     156,   157,   494,   521,   495,   161,   496,   497,   164,   165,
     166,   167,   168,   169,   498,   171,   499,   500,   501,   502,
     176,   177,   503,   504,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   542,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     0,
       0,     0,   464,     0,     0,     0,   390,   391,     0,    14,
      15,    16,   513,    18,    19,    20,   466,   514,   515,   468,
     469,   470,   392,    28,   471,    30,    31,     0,    32,    33,
      34,    35,   516,    37,   517,   518,    40,    41,    42,    43,
     473,     0,    45,   519,    47,   475,   476,    50,   477,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   478,   479,    68,     0,    69,    70,    71,
     520,     0,    74,    75,    76,     0,     0,   481,    78,     0,
       0,     0,     0,    80,   482,    82,   483,   484,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   485,    97,    98,
     486,   487,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,   107,     0,     0,     0,     0,     0,
       0,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     117,   488,   119,   120,   489,     0,     0,     0,     0,     0,
       0,     0,   490,   491,   127,     0,     0,     0,   128,     0,
     129,   492,     0,     0,     0,     0,     0,   134,     0,   135,
     136,   137,   138,   493,   140,   141,   142,   143,   144,   145,
       0,     0,   146,   147,     0,     0,   393,   150,   151,   152,
     153,   154,   155,   156,   157,   494,   521,   495,   161,   496,
     497,   164,   165,   166,   167,   168,   169,   498,   171,   499,
     500,   501,   502,   176,   177,   503,   504,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   545,   546,     0,     0,     0,     0,     7,     8,
       0,     0,     0,   464,     0,     0,     0,   390,   391,     0,
      14,    15,    16,   513,    18,    19,    20,   466,   514,   515,
     468,   469,   470,   392,    28,   471,    30,    31,     0,    32,
      33,    34,    35,   516,    37,   517,   518,    40,    41,    42,
      43,   473,     0,    45,   519,    47,   475,   476,    50,   477,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   478,   479,    68,     0,    69,    70,
      71,   520,     0,    74,    75,    76,     0,     0,   481,    78,
       0,     0,     0,     0,    80,   482,    82,   483,   484,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   485,    97,
      98,   486,   487,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,   107,     0,     0,     0,     0,
       0,     0,   112,   113,     0,     0,     0,     0,   114,   115,
     116,   117,   488,   119,   120,   489,     0,     0,     0,     0,
       0,     0,     0,   490,   491,   127,     0,     0,     0,   128,
       0,   129,   492,     0,     0,     0,     0,     0,   134,     0,
     135,   136,   137,   138,   493,   140,   141,   142,   143,   144,
     145,     0,     0,   146,   147,     0,     0,   393,   150,   151,
     152,   153,   154,   155,   156,   157,   494,   521,   495,   161,
     496,   497,   164,   165,   166,   167,   168,   169,   498,   171,
     499,   500,   501,   502,   176,   177,   503,   504,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     7,     8,     0,     0,     0,   464,     0,
       0,     0,   390,   391,     0,    14,    15,    16,   465,    18,
      19,    20,   466,    22,   467,   468,  1076,   470,   392,    28,
     471,    30,    31,     0,    32,    33,    34,    35,   472,    37,
      38,    39,    40,    41,    42,    43,   473,     0,    45,   474,
      47,   475,   476,    50,   477,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   478,
     479,    68,     0,    69,    70,    71,   480,     0,    74,    75,
      76,     0,     0,   481,    78,     0,     0,     0,     0,    80,
     482,    82,   483,   484,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   485,    97,    98,   486,   487,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
    1077,     0,     0,     0,  1078,     0,     0,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   488,   119,   120,
     489,     0,     0,     0,     0,     0,     0,     0,   490,   491,
     127,     0,     0,     0,   128,  1474,   129,   492,     0,     0,
       0,  1475,     0,   134,     0,   135,   136,   137,   138,   493,
     140,   141,   142,   143,   144,   145,     0,     0,  1079,   147,
       0,     0,   393,   150,   151,   152,   153,   154,   155,   156,
     157,   494,   159,   495,   161,   496,   497,   164,   165,   166,
     167,   168,   169,   498,   171,   499,   500,   501,   502,   176,
     177,   503,   504,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     7,     8,
       0,     0,     0,   464,     0,     0,     0,   390,   391,     0,
      14,    15,    16,   513,    18,    19,    20,   466,   514,   515,
     468,   469,   470,   392,    28,   471,    30,    31,     0,    32,
      33,    34,    35,   516,    37,   517,   518,    40,    41,    42,
      43,   473,     0,    45,   519,    47,   475,   476,    50,   477,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   478,   479,    68,     0,    69,    70,
      71,   520,     0,    74,    75,    76,     0,     0,   481,    78,
       0,     0,     0,     0,    80,   482,    82,   483,   484,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   485,    97,
      98,   486,   487,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,   107,     0,     0,     0,     0,
       0,     0,   112,   113,     0,     0,     0,     0,   114,   115,
     116,   117,   488,   119,   120,   489,     0,     0,     0,     0,
       0,     0,     0,   490,   491,   127,     0,     0,     0,   128,
     717,   129,   492,     0,     0,     0,   718,     0,   134,     0,
     135,   136,   137,   138,   493,   140,   141,   142,   143,   144,
     145,     0,     0,   146,   147,     0,     0,   393,   150,   151,
     152,   153,   154,   155,   156,   157,   494,   521,   495,   161,
     496,   497,   164,   165,   166,   167,   168,   169,   498,   171,
     499,   500,   501,   502,   176,   177,   503,   504,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     7,     8,     0,     0,     0,   464,     0,
       0,     0,   390,   391,     0,    14,    15,    16,   513,    18,
      19,    20,   466,   514,   515,   468,   469,   470,   392,    28,
     471,    30,    31,     0,    32,    33,    34,    35,   516,    37,
     517,   518,    40,    41,    42,    43,   473,     0,    45,   519,
      47,   475,   476,    50,   477,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   478,
     479,    68,     0,    69,    70,    71,   520,     0,    74,    75,
      76,     0,     0,   481,    78,     0,     0,     0,     0,    80,
     482,    82,   483,   484,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   485,    97,    98,   486,   487,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
     107,     0,     0,     0,     0,     0,     0,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   488,   119,   120,
     489,     0,     0,     0,     0,     0,     0,     0,   490,   491,
     127,     0,     0,     0,   128,   764,   129,   492,     0,     0,
       0,   765,     0,   134,     0,   135,   136,   137,   138,   493,
     140,   141,   142,   143,   144,   145,     0,     0,   146,   147,
       0,     0,   393,   150,   151,   152,   153,   154,   155,   156,
     157,   494,   521,   495,   161,   496,   497,   164,   165,   166,
     167,   168,   169,   498,   171,   499,   500,   501,   502,   176,
     177,   503,   504,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     7,     8,
       0,     0,     0,   464,     0,     0,     0,   390,   391,     0,
      14,    15,    16,   465,    18,    19,    20,   466,    22,   467,
     468,  1076,   470,   392,    28,   471,    30,    31,     0,    32,
      33,    34,    35,   472,    37,    38,    39,    40,    41,    42,
      43,   473,     0,    45,   474,    47,   475,   476,    50,   477,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   478,   479,    68,     0,    69,    70,
      71,   480,     0,    74,    75,    76,     0,     0,   481,    78,
       0,     0,     0,     0,    80,   482,    82,   483,   484,    85,
      86,  1398,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   485,    97,
      98,   486,   487,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,  1077,     0,     0,     0,  1078,
       0,     0,   112,   113,     0,     0,     0,     0,   114,   115,
     116,   117,   488,   119,   120,   489,     0,     0,     0,     0,
       0,     0,     0,   490,   491,   127,     0,     0,     0,   128,
       0,   129,   492,     0,     0,     0,     0,     0,   134,     0,
     135,   136,   137,   138,   493,   140,   141,   142,   143,   144,
     145,     0,     0,  1079,   147,     0,     0,   393,   150,   151,
     152,   153,   154,   155,   156,   157,   494,   159,   495,   161,
     496,   497,   164,   165,   166,   167,   168,   169,   498,   171,
     499,   500,   501,   502,   176,   177,   503,   504,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     7,     8,     0,     0,     0,   464,     0,
       0,     0,   390,   391,     0,    14,    15,    16,   465,    18,
      19,    20,   466,    22,   467,   468,  1076,   470,   392,    28,
     471,    30,    31,     0,    32,    33,    34,    35,   472,    37,
      38,    39,    40,    41,    42,    43,   473,     0,    45,   474,
      47,   475,   476,    50,   477,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   478,
     479,    68,     0,    69,    70,    71,   480,     0,    74,    75,
      76,     0,     0,   481,    78,     0,     0,     0,     0,    80,
     482,    82,   483,   484,    85,    86,  1527,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   485,    97,    98,   486,   487,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
    1077,     0,     0,     0,  1078,     0,     0,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   488,   119,   120,
     489,     0,     0,     0,     0,     0,     0,     0,   490,   491,
     127,     0,     0,     0,   128,     0,   129,   492,     0,     0,
       0,     0,     0,   134,     0,   135,   136,   137,   138,   493,
     140,   141,   142,   143,   144,   145,     0,     0,  1079,   147,
       0,     0,   393,   150,   151,   152,   153,   154,   155,   156,
     157,   494,   159,   495,   161,   496,   497,   164,   165,   166,
     167,   168,   169,   498,   171,   499,   500,   501,   502,   176,
     177,   503,   504,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     7,     8,
       0,     0,     0,   464,     0,     0,     0,   390,   391,     0,
      14,    15,    16,   465,    18,    19,    20,   466,    22,   467,
     468,  1076,   470,   392,    28,   471,    30,    31,     0,    32,
      33,    34,    35,   472,    37,    38,    39,    40,    41,    42,
      43,   473,     0,    45,   474,    47,   475,   476,    50,   477,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   478,   479,    68,     0,    69,    70,
      71,   480,     0,    74,    75,    76,     0,     0,   481,    78,
       0,     0,     0,     0,    80,   482,    82,   483,   484,    85,
      86,  1531,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   485,    97,
      98,   486,   487,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,  1077,     0,     0,     0,  1078,
       0,     0,   112,   113,     0,     0,     0,     0,   114,   115,
     116,   117,   488,   119,   120,   489,     0,     0,     0,     0,
       0,     0,     0,   490,   491,   127,     0,     0,     0,   128,
       0,   129,   492,     0,     0,     0,     0,     0,   134,     0,
     135,   136,   137,   138,   493,   140,   141,   142,   143,   144,
     145,     0,     0,  1079,   147,     0,     0,   393,   150,   151,
     152,   153,   154,   155,   156,   157,   494,   159,   495,   161,
     496,   497,   164,   165,   166,   167,   168,   169,   498,   171,
     499,   500,   501,   502,   176,   177,   503,   504,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     7,     8,     0,     0,     0,   464,     0,
       0,     0,   390,   391,     0,    14,    15,    16,   465,    18,
      19,    20,   466,    22,   467,   468,  1076,   470,   392,    28,
     471,    30,    31,     0,    32,    33,    34,    35,   472,    37,
      38,    39,    40,    41,    42,    43,   473,     0,    45,   474,
      47,   475,   476,    50,   477,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   478,
     479,    68,     0,    69,    70,    71,   480,     0,    74,    75,
      76,     0,     0,   481,    78,     0,     0,     0,     0,    80,
     482,    82,   483,   484,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   485,    97,    98,   486,   487,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
    1077,     0,     0,     0,  1078,     0,     0,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   488,   119,   120,
     489,     0,     0,     0,     0,     0,     0,     0,   490,   491,
     127,     0,     0,     0,   128,     0,   129,   492,     0,     0,
       0,     0,     0,   134,     0,   135,   136,   137,   138,   493,
     140,   141,   142,   143,   144,   145,     0,     0,  1079,   147,
       0,     0,   393,   150,   151,   152,   153,   154,   155,   156,
     157,   494,   159,   495,   161,   496,   497,   164,   165,   166,
     167,   168,   169,   498,   171,   499,   500,   501,   502,   176,
     177,   503,   504,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     7,     8,
       0,     0,     0,   464,     0,     0,     0,   390,   391,     0,
      14,    15,    16,   465,    18,    19,    20,   466,    22,   467,
     468,  1076,   470,   392,    28,   471,    30,    31,     0,    32,
      33,    34,    35,   472,    37,    38,    39,    40,    41,    42,
      43,   473,     0,    45,   474,    47,   475,   476,    50,   477,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   478,   479,    68,     0,    69,    70,
      71,   480,     0,    74,    75,    76,     0,     0,   481,    78,
       0,     0,     0,     0,    80,   482,    82,   483,   484,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   485,    97,
      98,   486,   487,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,  1077,     0,     0,     0,  1078,
       0,     0,   112,   113,     0,     0,     0,     0,   114,   115,
     116,   117,   488,   119,   120,   489,     0,     0,     0,     0,
       0,     0,     0,   490,   491,   127,     0,     0,     0,   128,
       0,   129,   492,     0,     0,     0,     0,     0,   134,     0,
     135,   136,   137,   138,   493,   140,   141,   142,   143,   144,
     145,     0,     0,   146,   147,     0,     0,   393,   150,   151,
     152,   153,   154,   155,   156,   157,   494,   159,   495,   161,
     496,   497,   164,   165,   166,   167,   168,   169,   498,   171,
     499,   500,   501,   502,   176,   177,   503,   504,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     7,     8,     0,     0,     0,   464,     0,
       0,     0,   390,   391,     0,    14,    15,    16,   513,    18,
      19,    20,   466,   514,   515,   468,   469,   470,   392,    28,
     471,    30,    31,     0,    32,    33,    34,    35,   516,    37,
     517,   518,    40,    41,    42,    43,   473,     0,    45,   519,
      47,   475,   476,    50,   477,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   478,
     479,    68,     0,    69,    70,    71,   520,     0,    74,    75,
      76,     0,     0,   481,    78,     0,     0,     0,     0,    80,
     482,    82,   483,   484,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   485,    97,    98,   486,   487,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
     107,     0,     0,     0,     0,     0,     0,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   488,   119,   120,
     489,     0,     0,     0,     0,     0,     0,     0,   490,   491,
     127,     0,     0,     0,   128,     0,   129,   492,     0,     0,
       0,     0,     0,   134,     0,   135,   136,   137,   138,   493,
     140,   141,   142,   143,   144,   145,     0,     0,   146,   147,
       0,     0,   393,   150,   151,   152,   153,   154,   155,   156,
     157,   494,   521,   495,   161,   496,   497,   164,   165,   166,
     167,   168,   169,   498,   171,   499,   500,   501,   502,   176,
     177,   503,   504,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     7,     8,
       0,     0,     0,   464,     0,     0,     0,   390,   391,     0,
      14,    15,    16,     0,    18,    19,    20,   466,     0,     0,
     468,   469,     0,   392,    28,   471,    30,    31,     0,    32,
      33,    34,    35,     0,    37,     0,     0,    40,    41,    42,
      43,   473,     0,    45,     0,    47,     0,     0,    50,   477,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   478,   479,    68,     0,    69,    70,
      71,     0,     0,    74,    75,    76,     0,     0,   481,    78,
       0,     0,     0,     0,    80,   482,    82,   483,   484,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   485,    97,
      98,   486,   487,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,     0,     0,     0,     0,     0,
       0,     0,   112,   113,     0,     0,     0,     0,   114,   115,
     116,   117,   488,   119,   120,   489,     0,     0,     0,     0,
       0,     0,     0,   490,   491,   127,     0,     0,     0,   128,
       0,   129,   492,     0,     0,     0,     0,     0,   134,     0,
     135,   136,   137,   138,   493,   140,   141,   142,   143,   144,
     145,     0,     0,     0,   147,     0,     0,   393,   150,   151,
     152,   153,   154,   155,   156,   157,   494,     0,   495,   161,
     496,   497,   164,   165,   166,   167,   168,   169,   498,   171,
     499,   500,   501,   502,   176,   177,     0,   504,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   399,   400,    12,     4,     5,     6,   632,     0,     4,
       5,     6,     4,     5,     6,   179,   741,   328,   780,   633,
     634,   635,   636,   249,     4,     5,     6,   301,   753,   584,
     585,   975,  1209,   401,   724,   281,   250,   272,   991,   132,
      73,   848,   767,   809,     4,     5,     6,   582,   583,   584,
     585,   265,  1013,   413,   724,  1225,  1143,  1281,  1282,   565,
     582,   583,     1,   882,   424,  1062,   678,    26,    27,     1,
    1492,   439,   440,     1,    36,  1238,    55,     1,    36,     8,
     586,   860,   861,    29,   590,     1,   898,   447,    47,    30,
       1,   117,    26,    27,   106,     1,    29,   146,    73,  1314,
      45,   141,   106,    37,    38,    94,    40,    41,   108,   106,
      29,    29,    87,    47,   117,    74,   108,    62,   117,   898,
      93,    99,    56,    57,   106,    99,   117,    54,   108,    56,
      99,   152,    94,   109,    96,   110,   106,   215,    96,   106,
      74,   106,   135,   120,   130,    79,   159,   122,   108,   124,
     396,   106,   111,   932,   612,   176,   614,   615,   861,   617,
      96,   619,   146,   172,    24,   223,   112,   225,    76,   627,
     628,   152,    99,   952,    34,   253,   110,   111,   112,   904,
     184,    96,     9,    10,   146,   420,   965,   186,   146,     9,
     109,   109,   189,    94,   185,    37,    38,   223,    40,    41,
      60,   183,   106,   189,   123,   123,   199,   185,    28,   182,
    1632,   185,   106,   159,  1438,    57,   185,   187,   106,   186,
       5,   233,   187,   272,     9,   159,   159,   216,   217,   148,
     148,   186,   272,   958,   152,  1412,   215,   155,   331,   964,
     155,   186,   231,   243,   152,   174,   246,  1009,  1192,   952,
     189,   243,  1415,  1206,   246,  1062,  1063,   189,   176,   814,
     815,   189,   965,  1350,   538,   189,  1078,   957,  1229,   272,
     112,   212,   884,   189,   253,   102,  1491,  1238,   189,   183,
     306,   281,   528,   189,   218,   955,  1105,   957,   272,   281,
     812,   813,   186,  1290,    52,   122,   802,   124,   186,  1078,
     152,   661,   122,   336,   124,   281,   339,   977,   106,   106,
     272,   219,   220,   133,   272,   216,   217,   159,   106,   255,
     256,   689,   106,   250,   176,   152,   260,   286,   129,   156,
     231,   566,   152,   106,   106,   294,   263,   122,   265,   124,
     258,    26,    27,    26,    27,    96,   173,   132,   117,   276,
     277,   278,   286,   280,   600,   282,   582,   583,    26,    27,
     294,   336,  1586,   106,   339,   579,   193,   152,   302,  1148,
     128,   739,   106,   129,     9,   735,   218,   106,   738,   105,
    1550,    42,   147,    42,   211,    46,   844,    46,   186,   186,
      51,   168,    51,    28,   195,   146,   396,    42,   186,   164,
     126,    46,   186,   157,   396,  1184,    51,  1494,    69,   654,
      69,  1635,   657,   186,   186,   660,   185,    94,   260,   147,
     396,   175,  1147,   200,    69,   425,   111,   427,   111,  1208,
     405,   406,   427,   425,   409,   427,   164,    94,   413,   195,
     183,   416,   417,   111,  1621,   425,   106,   427,   895,   424,
     848,   451,   186,   429,  1415,   430,   456,   186,   433,   451,
     907,   437,   708,   155,   456,   425,   441,   427,  1158,   146,
     446,   451,   447,   448,   449,   450,   456,   453,   454,   877,
     455,  1184,    96,  1290,   141,   106,   462,   122,   463,   124,
     106,   451,  1299,  1048,  1049,  1050,   456,  1167,   133,  1265,
     106,   106,  1268,  1310,  1591,  1208,   167,    29,   167,   170,
     152,   170,     5,  1048,  1049,  1050,     9,   152,   106,     9,
      10,   116,   167,   183,   185,   170,   185,    96,   528,   106,
     106,    94,   152,   533,   509,   106,   528,   905,   906,   117,
     185,   533,   910,  1322,    33,   106,  1633,    94,   523,   210,
     145,   210,   528,   533,   168,   106,   157,   532,   651,   652,
      49,   807,   183,   158,   540,   210,   208,   183,   577,   106,
    1514,   571,   940,   533,   175,   106,   552,   146,   141,   571,
     186,   186,   582,   583,   584,   585,   812,   109,   208,   564,
     582,   583,   584,   585,   570,   571,  1549,   192,   186,   146,
     600,   123,   106,   971,   818,   155,   268,   975,   600,   186,
     186,   571,   102,   275,   106,   186,  1703,    66,  1705,  1322,
     165,  1400,    71,   285,  1403,   186,   148,  1714,   106,   122,
     152,   124,   122,   155,   124,   186,   181,   251,   252,   132,
     254,   106,     9,    10,    33,    96,    45,   261,    47,   186,
     152,  1413,   262,   155,   176,   186,  1418,   271,  1465,   152,
      49,   112,   152,   273,  1062,  1063,   156,   268,   117,   283,
     143,    96,   648,   155,   275,  1365,  1301,   653,   267,   183,
      79,   155,    96,   173,   285,   274,   661,   112,    45,    39,
      47,   183,    26,    27,    44,    45,    94,  1400,     9,    10,
    1403,   136,   175,   193,   155,   183,   105,   682,   708,    59,
     685,    61,    62,    47,   155,  1270,   708,   152,   183,   192,
      70,   211,    56,   262,   699,   121,   246,   247,   703,   704,
     155,   731,   708,    94,   273,   102,   731,    53,   136,   731,
      74,    53,    58,   141,   105,    79,    58,    97,   105,   269,
     725,   731,   727,  1064,   168,   122,   152,   124,   136,   155,
     735,   761,   762,   738,   298,    77,  1040,   742,   167,   761,
     762,   731,   135,   307,   152,  1537,   110,   111,   112,  1541,
      96,   761,   762,   121,    96,   152,   149,   155,  1034,   156,
    1569,   102,  1571,   219,   220,   221,   772,   773,   774,   157,
     776,   761,   762,   157,   779,   117,   173,   807,  1613,  1614,
     167,   122,    96,   124,   823,   807,   181,   175,   946,  1187,
     948,   175,   223,  1602,  1192,    53,   193,   228,   112,   194,
      58,  1456,  1457,   199,   809,  1449,   181,   251,   252,   197,
     254,   152,   208,   197,   211,   156,  1651,    99,   136,   194,
    1629,    99,  1657,   141,   136,  1617,   831,   271,   155,   141,
     112,  1586,   173,    99,   112,  1644,  1569,  1646,  1571,   283,
     998,    95,  1000,   223,  1038,   152,   112,    99,   155,  1043,
      99,   105,   193,    99,   338,   860,   861,   862,   863,   343,
     112,   115,  1290,   112,   152,   152,   112,   155,   155,  1602,
     211,  1299,   126,   121,   276,   277,   278,   190,   191,  1277,
     282,   155,  1310,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,   898,   155,   223,  1629,   225,   153,   230,
     155,   232,  1557,  1558,   127,   128,   131,   912,   127,   128,
    1186,  1644,   121,  1646,   139,   140,   117,   142,   121,   230,
     152,   232,   286,   637,   638,   150,   630,   631,   121,   154,
     294,   156,   937,   639,   640,   117,   161,   121,   302,   862,
     863,   946,   121,   948,  1482,  1483,   121,   952,   121,   121,
     121,   214,   152,   178,   223,   117,   155,   240,   152,   240,
     965,   241,     0,   993,   155,   106,    92,   189,   166,   248,
    1625,   993,    50,   100,   198,   153,   201,   202,   203,   204,
     205,   206,   101,   993,  1382,   120,   144,   155,  1264,    29,
      47,   183,   151,   998,   183,  1000,   183,   117,   245,   303,
     186,   117,   152,   993,  1034,     1,   283,   283,  1047,   117,
     141,   106,  1034,   152,   152,   155,   186,   141,  1048,  1049,
    1050,   155,   155,   155,   152,   155,  1048,  1049,  1050,   183,
     155,    35,   155,   155,    17,   212,    29,  1465,   186,   229,
     189,     3,   189,   117,  1442,    94,   167,    70,    73,   244,
      94,   169,  1057,   229,   169,  1061,   148,    94,   106,   106,
      29,   159,    87,   159,   126,   131,    94,   298,   141,   183,
     131,   245,   117,  1078,   183,   186,   186,   106,    94,    96,
      45,    96,   186,   186,   186,   110,   186,   152,    94,   183,
     183,   235,   189,    33,   223,   141,   117,   122,   169,   124,
     131,    29,   141,    94,   285,    94,   117,   126,   225,   152,
     298,   146,   117,    94,   117,   183,  1514,   253,  1394,   196,
      96,  1151,   131,   159,   131,   152,  1151,   117,   146,  1151,
     183,    99,    99,   183,   189,    35,    29,   117,   152,   141,
      79,  1151,   155,   155,   152,   155,   106,   106,   143,    29,
     257,    29,  1157,   244,   259,  1160,  1186,   155,   155,    29,
     266,  1151,   305,   155,  1186,   225,   143,  1197,   146,   189,
    1175,   284,  1197,   285,   126,  1197,   146,   106,    77,  1184,
     146,   117,   117,   141,   183,   286,  1216,  1197,    99,   131,
       7,  1216,   186,  1198,  1216,   196,   105,   231,   186,   186,
     186,   186,   186,  1208,   105,  1235,  1216,  1197,   249,   231,
     189,   235,   186,  1235,   185,   146,   249,   281,   285,    78,
      29,    29,   186,   186,   106,  1235,  1216,   183,   270,   186,
     256,  1236,   169,  1263,  1264,   125,  1512,   125,   146,   146,
      96,  1263,  1264,    94,   185,  1235,   152,  1523,  1524,   231,
    1526,  1256,   185,   183,  1260,  1261,  1262,  1533,   231,   185,
    1265,   185,   183,  1268,   183,   183,   186,    29,    96,   186,
     146,   169,    53,  1263,    94,   185,    94,    29,   117,   279,
     185,   195,   106,   196,   106,   223,   117,    94,   185,   264,
      94,   195,   195,   185,   117,    93,   223,   182,   185,   195,
     223,   117,   117,   197,   185,   117,   185,   688,   185,   243,
    1108,   336,   899,   400,   339,  1148,  1633,  1322,   966,  1591,
     292,   246,   810,  1157,   246,   286,   556,   557,   744,   559,
     560,   561,   562,   249,  1610,   420,   963,   286,  1375,   569,
    1176,  1346,  1286,  1053,  1620,  1284,  1281,  1198,  1203,   304,
     304,   304,  1206,  1211,   305,   305,   523,   305,   611,   610,
     663,  1229,   592,   780,  1394,  1657,  1651,  1372,  1373,  1645,
     600,   601,  1394,   863,  1142,   948,   428,   324,  1107,  1256,
    1266,   406,  1265,  1299,   409,  1310,  1063,  1465,   413,  1303,
    1462,   416,   417,  1398,  1072,  1400,   428,  1130,  1403,   424,
    1676,   931,  1485,  1300,  1341,   430,    -1,    -1,   433,  1414,
      -1,    -1,    -1,    -1,  1419,    -1,   441,    -1,    -1,    -1,
      -1,  1697,   447,   448,   449,   450,  1702,    -1,    -1,   659,
     455,    -1,    -1,   663,    -1,    -1,    -1,    -1,   463,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   701,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1512,    -1,   509,    -1,    -1,    -1,    -1,    -1,
    1512,    -1,    -1,  1523,  1524,    -1,  1526,    -1,   523,    -1,
      -1,  1523,  1524,  1533,  1526,    -1,    -1,   532,    -1,    -1,
      -1,  1533,    -1,   743,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1527,    -1,  1529,    -1,  1531,    -1,    -1,    -1,
      -1,    -1,    -1,  1538,    -1,    -1,    -1,    -1,   768,   564,
      -1,    -1,    -1,    -1,    -1,  1551,    -1,    -1,   778,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1567,    -1,    -1,  1569,    -1,  1571,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1610,    -1,  1587,    -1,    -1,  1590,    -1,    -1,  1610,    -1,
    1620,    -1,    -1,    -1,    -1,    -1,    -1,  1602,  1620,    -1,
      -1,    -1,    -1,   833,    -1,    -1,    -1,  1612,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1645,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1645,  1629,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1637,    -1,    -1,    -1,   661,  1642,    -1,  1644,
      -1,  1646,    -1,    -1,    -1,    -1,  1676,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1676,    -1,    -1,    -1,    -1,    -1,
     685,    -1,    -1,    -1,    -1,    -1,    -1,  1697,  1673,    -1,
     900,    -1,  1702,    -1,   699,  1697,    -1,    -1,   703,   704,
    1702,    -1,    -1,    -1,  1689,    -1,    -1,    -1,  1693,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     725,    -1,   727,    -1,  1709,   935,    -1,  1712,    -1,    -1,
     735,    -1,    -1,   738,    -1,    -1,    -1,   742,    -1,    -1,
      -1,    -1,    -1,    -1,   954,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   976,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   779,    -1,    -1,   987,   988,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1002,    -1,    -1,  1005,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   809,    -1,    -1,    -1,    -1,  1019,
    1020,  1021,    -1,  1023,  1024,  1025,  1026,  1027,  1028,    -1,
    1030,  1031,    -1,    -1,    -1,    -1,   831,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1053,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   860,   861,   862,   863,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1095,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   898,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   912,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   937,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   946,    -1,   948,    -1,    -1,    -1,   952,    -1,    -1,
      -1,    -1,  1162,    -1,  1164,    -1,  1166,    -1,    -1,  1169,
     965,    -1,    -1,    -1,  1174,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1186,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1195,    -1,    -1,    -1,    -1,
      -1,  1201,  1202,   998,    -1,  1000,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1057,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1078,  1284,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1359,
      -1,    -1,  1157,  1363,    -1,  1160,    -1,  1367,    -1,  1369,
      -1,  1371,    -1,    -1,    -1,    -1,    -1,  1377,    -1,    -1,
    1175,    -1,    -1,    -1,    -1,  1385,    -1,    -1,    -1,  1184,
      -1,    -1,    -1,  1393,  1394,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1198,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1411,    -1,  1208,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1422,  1423,  1424,  1425,  1426,    -1,  1428,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1265,    -1,    -1,  1268,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1500,    -1,  1502,    -1,    -1,  1505,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1513,    -1,    -1,    -1,    -1,  1518,  1519,
      -1,    -1,    -1,    -1,    -1,    -1,  1526,  1322,    -1,    -1,
    1530,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1372,  1373,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1594,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1398,    -1,  1400,  1606,    -1,  1403,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1414,
      -1,    -1,    -1,    -1,  1419,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1645,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1671,    -1,    -1,    -1,    -1,  1676,    -1,    -1,    -1,
      -1,  1681,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1696,    -1,    -1,    -1,
    1700,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1527,    -1,  1529,    -1,  1531,    -1,    -1,    -1,
      -1,    -1,    -1,  1538,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1569,    -1,  1571,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1587,    -1,    -1,  1590,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1602,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1612,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1629,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1637,    -1,    -1,    -1,    -1,  1642,    -1,  1644,
      -1,  1646,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1673,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1689,    -1,    -1,    -1,  1693,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      12,    -1,    -1,    -1,  1709,    -1,    -1,  1712,    20,    21,
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
     152,    -1,    -1,   155,   156,   157,   158,   159,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,    -1,   175,   176,    -1,    -1,   179,   180,   181,
      -1,    -1,    -1,   185,    -1,   187,   188,    -1,   190,   191,
     192,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,   209,   210,   211,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,    11,    12,
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
      -1,    -1,   155,   156,   157,   158,   159,    -1,    -1,    -1,
      -1,   164,   165,   166,   167,   168,   169,   170,   171,    -1,
     173,    -1,   175,   176,    -1,    -1,   179,   180,   181,    -1,
     183,    -1,   185,    -1,   187,   188,    -1,   190,   191,   192,
      -1,   194,    -1,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,    -1,    -1,   209,   210,   211,    -1,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,    11,    12,    -1,    -1,
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
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
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
     255,   256,    -1,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,    11,    12,    -1,    -1,    -1,    -1,
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
     147,   148,   149,   150,   151,   152,    -1,    -1,   155,   156,
     157,   158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,
     167,   168,   169,   170,   171,    -1,   173,    -1,   175,   176,
      -1,    -1,   179,   180,   181,    -1,   183,    -1,   185,    -1,
     187,   188,    -1,   190,   191,   192,    -1,   194,    -1,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
      -1,    -1,   209,   210,   211,    -1,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
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
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,    -1,    -1,    -1,   123,    -1,   125,   126,   127,   128,
      -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,   138,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,   155,   156,   157,   158,
     159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,    -1,   173,    -1,   175,   176,    -1,    -1,
     179,   180,   181,    -1,   183,    -1,   185,    -1,   187,   188,
      -1,   190,   191,   192,    -1,   194,    -1,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,    -1,    -1,
     209,   210,   211,    -1,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
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
     151,   152,    -1,    -1,   155,   156,   157,   158,   159,    -1,
      -1,    -1,    -1,   164,   165,   166,   167,   168,   169,   170,
     171,    -1,   173,    -1,   175,   176,    -1,    -1,   179,   180,
     181,    -1,    -1,    -1,   185,    -1,   187,   188,    -1,   190,
     191,   192,    -1,   194,    -1,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,    -1,    -1,   209,   210,
     211,    -1,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,    11,    12,
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
      -1,    -1,   155,   156,   157,   158,   159,    -1,    -1,    -1,
      -1,   164,   165,   166,   167,   168,   169,   170,   171,    -1,
     173,    -1,   175,   176,    -1,    -1,   179,   180,   181,    -1,
      -1,    -1,   185,    -1,   187,   188,    -1,   190,   191,   192,
      -1,   194,    -1,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,    -1,    -1,   209,   210,   211,    -1,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,    11,    12,    -1,    -1,
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
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
     155,   156,   157,   158,   159,    -1,    -1,    -1,    -1,   164,
     165,   166,   167,   168,   169,   170,   171,    -1,   173,    -1,
     175,   176,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,
     185,    -1,   187,   188,    -1,   190,   191,   192,    -1,   194,
      -1,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,    -1,    -1,   209,   210,   211,    -1,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,    11,    12,    -1,    -1,    -1,    -1,
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
     147,   148,   149,   150,   151,   152,    -1,    -1,   155,   156,
     157,   158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,
     167,   168,   169,   170,   171,    -1,   173,    -1,   175,   176,
      -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,    -1,
     187,   188,    -1,   190,   191,   192,    -1,   194,    -1,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
      -1,    -1,   209,   210,   211,    -1,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
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
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,    -1,    -1,    -1,   123,    -1,   125,   126,   127,   128,
      -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,   138,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,   155,   156,   157,   158,
     159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,    -1,   173,    -1,   175,   176,    -1,    -1,
     179,   180,   181,    -1,    -1,    -1,   185,    -1,   187,   188,
      -1,   190,   191,   192,    -1,   194,    -1,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,    -1,    -1,
     209,   210,   211,    -1,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
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
     151,   152,    -1,    -1,   155,   156,   157,   158,   159,    -1,
      -1,    -1,    -1,   164,   165,   166,   167,   168,   169,   170,
     171,    -1,   173,    -1,   175,   176,    -1,    -1,   179,   180,
     181,    -1,    -1,    -1,   185,    -1,   187,   188,    -1,   190,
     191,   192,    -1,   194,    -1,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,    -1,    -1,   209,   210,
     211,    -1,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,    11,    12,
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
      -1,    -1,   155,   156,   157,   158,   159,    -1,    -1,    -1,
      -1,   164,   165,   166,   167,   168,   169,   170,   171,    -1,
     173,    -1,   175,   176,    -1,    -1,   179,   180,   181,    -1,
      -1,    -1,   185,   186,   187,   188,    -1,   190,   191,   192,
      -1,   194,    -1,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,    -1,    -1,   209,   210,   211,    -1,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,    11,    12,    -1,    -1,
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
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
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
     255,   256,    -1,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,    11,    12,    -1,    -1,    -1,    -1,
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
     147,   148,   149,   150,   151,   152,    -1,    -1,   155,   156,
     157,   158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,
     167,   168,   169,   170,   171,    -1,   173,    -1,   175,   176,
      -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,   186,
     187,   188,    -1,   190,   191,   192,    -1,   194,    -1,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
      -1,    -1,   209,   210,   211,    -1,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
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
     149,   150,   151,   152,    -1,    -1,   155,   156,   157,   158,
     159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,    -1,   173,    -1,   175,   176,    -1,    -1,
     179,   180,   181,    -1,    -1,    -1,   185,   186,   187,   188,
      -1,   190,   191,   192,    -1,   194,    -1,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,    -1,    -1,
     209,   210,   211,    -1,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
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
     151,   152,    -1,    -1,   155,   156,   157,   158,   159,    -1,
      -1,    -1,    -1,   164,   165,   166,   167,   168,   169,   170,
     171,    -1,   173,    -1,   175,   176,    -1,    -1,   179,   180,
     181,    -1,    -1,    -1,   185,    -1,   187,   188,    -1,   190,
     191,   192,    -1,   194,    -1,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,    -1,    -1,   209,   210,
     211,    -1,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,    11,    12,
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
      -1,    -1,   155,   156,   157,   158,   159,    -1,    -1,    -1,
      -1,   164,   165,   166,   167,   168,   169,   170,   171,    -1,
     173,    -1,   175,   176,    -1,    -1,   179,   180,   181,    -1,
      -1,    -1,   185,    -1,   187,   188,    -1,   190,   191,   192,
      -1,   194,    -1,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,    -1,    -1,   209,   210,   211,    -1,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,    11,    12,    -1,    -1,
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
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
     155,   156,   157,   158,   159,    -1,    -1,    -1,    -1,   164,
     165,   166,   167,   168,   169,   170,   171,    -1,   173,    -1,
     175,   176,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,
     185,    -1,   187,   188,    -1,   190,   191,   192,    -1,   194,
      -1,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,    -1,    -1,   209,   210,   211,    -1,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,    11,    12,    -1,    -1,    -1,    -1,
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
     147,   148,   149,   150,   151,   152,    -1,    -1,   155,   156,
      -1,   158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,
     167,   168,   169,   170,   171,    -1,   173,    -1,    -1,    -1,
      -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,    -1,
     187,   188,    -1,   190,   191,   192,    -1,   194,    -1,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
      -1,    -1,   209,   210,   211,    -1,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
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
     149,   150,   151,   152,    -1,    -1,   155,   156,    -1,   158,
     159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,    -1,   173,    -1,    -1,    -1,    -1,    -1,
     179,   180,   181,    -1,    -1,    -1,   185,    -1,   187,   188,
      -1,    -1,    -1,   192,    -1,   194,    -1,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,    -1,    -1,
     209,   210,   211,    -1,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
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
     181,    -1,    -1,    -1,   185,    -1,   187,   188,    -1,    -1,
      -1,   192,    -1,   194,    -1,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,    -1,    -1,   209,   210,
      -1,    -1,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,   158,   159,    -1,    -1,    -1,
      -1,   164,   165,   166,   167,   168,   169,   170,   171,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,    -1,
      -1,    -1,   185,    -1,   187,   188,    -1,    -1,    -1,   192,
      -1,   194,    -1,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,    -1,    -1,   209,   210,    -1,    -1,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    -1,    99,
     100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,
     130,    -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   146,   147,    -1,   149,
     150,   151,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,
     180,   181,    -1,    -1,    -1,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,   209,
     210,    -1,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
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
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
      -1,    -1,   209,   210,    -1,    -1,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,    18,    19,    -1,    -1,    -1,    -1,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    -1,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,    -1,   149,   150,   151,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,
      -1,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,   209,   210,    -1,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,    24,    25,    -1,    -1,    -1,    29,    -1,
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
     151,    -1,    -1,    -1,   155,    -1,    -1,   158,   159,    -1,
      -1,    -1,    -1,   164,   165,   166,   167,   168,   169,   170,
     171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,
     181,    -1,    -1,    -1,   185,   186,   187,   188,    -1,    -1,
      -1,   192,    -1,   194,    -1,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,    -1,    -1,   209,   210,
      -1,    -1,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    -1,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,    -1,   149,   150,   151,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,
     186,   187,   188,    -1,    -1,    -1,   192,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,   209,   210,    -1,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,    24,    25,    -1,    -1,    -1,    29,    -1,
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
      -1,   192,    -1,   194,    -1,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,    -1,    -1,   209,   210,
      -1,    -1,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    -1,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,    -1,   149,   150,   151,    -1,    -1,    -1,   155,
      -1,    -1,   158,   159,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,
      -1,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,   209,   210,    -1,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,    24,    25,    -1,    -1,    -1,    29,    -1,
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
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    -1,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,    -1,   149,   150,   151,    -1,    -1,    -1,   155,
      -1,    -1,   158,   159,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,
      -1,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,   209,   210,    -1,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,    24,    25,    -1,    -1,    -1,    29,    -1,
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
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    -1,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,    -1,   149,   150,   151,    -1,    -1,    -1,   155,
      -1,    -1,   158,   159,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,
      -1,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,   209,   210,    -1,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,    24,    25,    -1,    -1,    -1,    29,    -1,
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
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    -1,    40,    41,    42,    43,    -1,    -1,
      46,    47,    -1,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    -1,    60,    -1,    -1,    63,    64,    65,
      66,    67,    -1,    69,    -1,    71,    -1,    -1,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    -1,    -1,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,    -1,   149,   150,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,
      -1,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,    -1,   210,    -1,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,    -1,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308
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
     138,   145,   146,   147,   148,   149,   150,   151,   152,   155,
     156,   157,   158,   159,   164,   165,   166,   167,   168,   169,
     170,   171,   173,   175,   176,   179,   180,   181,   185,   187,
     188,   190,   191,   192,   194,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   209,   210,   211,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   258,   259,   260,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   324,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   345,   346,   347,   348,   349,   350,   354,   355,
     356,   360,   362,   363,   365,   372,   374,   377,   378,   379,
     381,   382,   383,   384,   385,   387,   388,   390,   391,   392,
     393,   394,   395,   397,   398,   401,   402,   403,   404,   409,
     411,   413,   414,   419,   438,   441,   445,   448,   449,   454,
     455,   456,   457,   459,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   505,   506,   507,   521,   522,   524,   525,
     526,   527,   528,   529,   530,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   550,   551,   552,   553,   558,
     559,   560,   561,   562,   563,   566,   624,   626,   627,   628,
      33,    34,    49,   213,   380,   381,   382,   380,   380,   155,
     155,    37,    38,    40,    41,    47,    56,    57,    74,    79,
     110,   111,   112,   159,   218,   260,   286,   294,   302,   361,
     362,   366,   367,   368,   159,   152,   155,   152,   155,   152,
     155,    66,    71,   117,   406,   155,   369,   155,    24,    34,
      60,   117,   272,   418,   420,   421,   152,   155,   155,   155,
     117,   152,   155,   155,   155,    76,   152,   219,   220,   121,
     121,   121,   152,   155,    29,    39,    43,    45,    46,    47,
      48,    51,    59,    67,    70,    72,    73,    75,    90,    91,
      97,   104,   111,   113,   114,   134,   137,   138,   168,   171,
     179,   180,   188,   200,   222,   224,   226,   227,   234,   236,
     237,   238,   239,   242,   243,   489,   626,   627,   121,   117,
     389,   121,   121,    39,    44,    45,    59,    61,    62,    70,
      97,   223,   626,   117,   121,   121,   183,   380,   382,    48,
      72,    73,   117,   152,   186,   243,   401,   403,   413,   626,
     152,   121,    16,   625,   626,    18,    19,   626,   121,   121,
     121,   481,   152,    30,   212,   214,   223,   225,   155,   223,
     225,   223,   223,   228,   117,   111,   362,   240,   240,   241,
     155,   152,   384,   326,     0,   328,   329,    33,    49,   331,
     348,     1,   189,   325,   189,   325,   111,   363,   383,   401,
     106,   189,   106,   189,    42,    46,    51,    69,   167,   170,
     185,   210,   396,   405,   410,   411,   412,   426,   427,   431,
     166,    92,   131,   139,   140,   142,   150,   154,   156,   161,
     178,   201,   202,   203,   204,   205,   206,   473,   474,   248,
     157,   175,   197,   116,   145,   158,   192,   199,   208,   135,
     149,    50,   198,   100,   101,   157,   175,   472,   152,   478,
     481,   190,   191,   153,   493,   494,   489,   493,   489,   155,
     493,   120,   144,   155,   183,   183,   183,    29,   364,   496,
     364,   624,   181,   194,   181,   194,   165,   181,   627,   626,
     168,   200,    47,   626,   151,   117,    45,    47,    79,   105,
     167,   625,   219,   220,   221,   245,   597,   626,   626,   303,
     136,   141,   111,   286,   294,   366,   625,   381,   382,   186,
     380,    45,    62,   186,   546,   547,   401,   186,   192,   626,
     283,   283,   415,   416,   626,   117,   422,   117,   186,   370,
     371,   152,   386,   401,     1,   159,   624,   112,   159,   344,
     624,   626,   117,   141,   106,   401,    29,   186,   625,   626,
     626,   439,   440,   626,   381,   186,   401,   401,   548,   626,
     381,   152,   152,   401,   186,   192,   626,   626,   141,   439,
     183,   183,   155,   155,   155,   626,   152,   186,   185,    35,
     509,   510,   511,   401,     8,   174,    17,   401,   212,    29,
     402,   402,   186,   402,   402,   402,   402,   229,   564,   565,
     626,   389,   111,   189,   189,   402,   401,   382,   401,   244,
     399,   400,   189,   325,   189,   325,     3,   332,   348,   378,
     332,   348,   378,    33,   349,   378,   349,   378,   389,   389,
     402,   117,   167,   169,   169,   383,   402,   402,   456,   457,
     459,   459,   459,   459,   458,   459,   459,   459,    70,   463,
     463,   462,   464,   464,   464,   464,   465,   465,   466,   466,
     229,    94,    94,    94,   183,   401,   481,   481,   401,   494,
     186,   402,   504,   625,   148,   186,   504,   106,   186,   186,
     106,   106,   369,    29,   627,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,   351,   352,   353,    94,   136,
     141,   357,   358,   359,   626,   159,   159,   351,   624,   126,
     131,    54,    56,    99,   250,   263,   265,   276,   277,   278,
     280,   282,   598,   599,   600,   601,   602,   603,   610,   616,
     617,   245,    94,   298,   626,   141,   402,   117,   626,   626,
     131,   183,   183,   186,   186,   183,   106,   186,   106,   186,
     106,    36,    94,    96,   146,   417,   418,   532,   626,    55,
     215,   253,   407,   408,   626,    94,   106,   186,   380,   186,
     625,    96,    45,   625,   624,    96,   141,   532,   626,   402,
     421,   183,   186,   186,   186,   186,   106,   187,   146,   532,
     183,   186,   186,   152,   183,   381,   381,   183,   106,   186,
     106,   186,   141,   532,   402,   187,   401,   401,   401,   626,
     510,   511,   129,   195,   183,   183,   130,   189,    94,   216,
     217,   231,    94,   216,   217,   231,    94,   235,   223,   106,
     233,   141,   389,   189,   186,    48,    72,    73,   243,   403,
     413,   183,   490,   570,   400,   348,    33,    33,   189,   325,
     189,   112,   626,   169,   402,   432,   433,   117,   428,   429,
     459,   152,   155,   258,   477,   496,   571,   574,   575,   576,
     577,   578,   582,   584,   586,   587,    47,   151,   155,   209,
     533,   535,   537,   538,   554,   555,   556,   557,   626,   533,
     531,   537,   531,   183,   184,   106,   186,   186,   496,   147,
     164,   147,   164,   136,   386,   369,   352,   131,   535,   359,
     402,   532,   624,   624,   127,   128,   624,   276,   277,   278,
     282,   626,   262,   273,   262,   273,    29,   285,    96,   112,
     155,   604,   607,   598,    39,    44,    59,    61,    70,    97,
     223,   373,   538,   225,   298,   307,   402,   626,    94,   298,
     624,   152,   548,   549,   626,   548,   549,   117,   126,   533,
     117,   402,   146,   418,   146,    36,   146,   417,   418,   146,
     532,   253,    53,    58,    77,   117,   417,   423,   424,   425,
     408,   532,   533,   371,    94,   183,   196,   131,   343,   624,
     159,   131,    96,   343,   402,   141,   418,   152,   117,   402,
     402,   146,    99,   442,   443,   444,   446,   447,    99,   450,
     451,   452,   453,   381,   183,   183,   152,   548,   548,   402,
     141,   189,   402,   186,   186,   186,    35,   511,   129,   195,
       9,    10,   102,   122,   124,   152,   193,   506,   508,   519,
     520,   523,    29,   230,   232,   402,   402,   402,   230,   232,
     402,   402,   402,   402,   402,   402,   117,   402,   402,   383,
     155,   155,   155,   152,   185,   244,   567,   568,   208,   384,
     189,   112,   378,   378,   378,   432,    95,   105,   115,   126,
     434,   435,   436,   437,   106,   626,   106,   401,   571,   578,
     152,   284,   460,   623,    96,   168,   251,   252,   254,   261,
     271,   283,   572,   573,   592,   593,   594,   595,   618,   621,
     257,   259,   579,   597,   266,   583,   619,   246,   247,   269,
     588,   589,   155,   155,   535,   155,   143,   175,   192,   534,
     143,   402,   136,   386,   550,   358,   285,    29,    96,   112,
     155,   611,    29,   604,   534,   479,   286,   305,   532,   373,
     225,   189,   380,   186,   186,   143,   186,   186,   416,   146,
     417,   626,   402,   146,   402,   126,   402,   146,   418,   146,
     402,   146,   117,   117,   402,   626,   425,    77,   533,   383,
     402,   624,   106,   343,   402,   141,   380,   440,   402,   402,
     112,   443,   444,    99,   185,   112,   444,   447,   117,   533,
      99,   112,   451,    99,   112,   453,   183,   380,   186,   186,
     402,   196,   450,   131,   193,   508,     7,   381,   626,   193,
     519,   189,   231,   231,   231,   231,   235,   565,   185,   401,
     401,   401,   570,   568,   490,   624,   127,   128,   436,   437,
     437,   433,   105,   430,   429,   183,   186,   571,   585,   249,
     215,   253,   267,   274,   622,    96,   255,   256,   620,   249,
     575,   622,   462,   592,   576,   146,   281,   580,   581,   620,
     285,   591,    78,   590,   186,   192,   533,   536,   186,   186,
     186,    29,   135,   199,   613,   614,   615,    29,   612,   613,
     270,   608,   106,   605,   169,   626,   256,   479,   183,   402,
     146,   402,   146,   417,   402,   146,   402,   402,   626,   626,
     424,   402,   125,   125,    96,   624,   402,   183,   185,   185,
     402,   383,   402,   185,   185,   626,   185,   117,   533,   117,
     185,   117,   533,   185,   183,   112,   511,   626,   193,   183,
     511,   626,   402,   402,   402,   402,   402,   402,   186,   186,
     186,   152,   569,   437,   624,   183,   464,    52,   128,   462,
     462,   268,   275,   285,   596,   596,   577,   152,   279,    94,
     186,   106,   186,   611,   611,   615,   106,   186,    29,   609,
     620,   606,   607,   186,   375,   376,   479,   117,   223,   306,
     286,   169,   402,   402,   146,   402,    53,   383,   402,   343,
     402,   383,    94,   383,   402,   626,   185,   626,   402,   626,
     185,   383,   117,    93,   182,   512,   511,   626,   195,   511,
     196,   450,   401,   462,   462,   197,   401,   533,   533,    94,
      29,   264,   106,   106,   437,   532,   626,   117,   223,   626,
     375,   402,   117,   533,    94,   185,    94,   626,     5,   132,
     515,   516,   518,   520,    28,   133,   513,   514,   517,   520,
     195,   511,   195,   112,   183,   462,   183,   533,   607,   376,
     437,   304,   626,   117,   223,   626,   185,   533,   383,   402,
     533,   185,    93,   132,   518,   182,   133,   517,   195,   117,
     402,   304,   626,   117,   383,   402,   185,   185,   626,   292,
     304,   626,   185,   305,   402,   305,   479,   479,   197,   286,
     626,   223,   117,   626,   305,   479
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
     575,   576,   577
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   323,   324,   324,   325,   326,   326,   326,   326,   327,
     327,   328,   328,   328,   328,   328,   328,   328,   328,   329,
     329,   329,   329,   330,   331,   331,   331,   332,   332,   332,
     332,   332,   333,   333,   333,   333,   333,   333,   333,   333,
     334,   334,   335,   336,   337,   337,   338,   338,   339,   339,
     340,   340,   340,   340,   341,   341,   341,   342,   342,   342,
     342,   343,   343,   344,   344,   345,   345,   345,   345,   346,
     347,   347,   348,   348,   348,   349,   349,   349,   349,   349,
     349,   349,   349,   350,   350,   351,   351,   352,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   354,   355,
     356,   357,   357,   358,   358,   358,   359,   360,   360,   360,
     361,   361,   361,   361,   362,   362,   363,   363,   363,   363,
     364,   364,   365,   365,   366,   366,   367,   367,   368,   368,
     369,   369,   369,   369,   370,   370,   371,   371,   372,   372,
     372,   372,   373,   373,   374,   374,   375,   375,   376,   376,
     376,   376,   377,   377,   377,   377,   378,   379,   379,   379,
     380,   380,   380,   381,   381,   382,   382,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   384,
     384,   385,   386,   387,   388,   388,   388,   388,   388,   389,
     389,   389,   389,   390,   391,   392,   393,   394,   394,   395,
     396,   397,   398,   399,   399,   400,   401,   401,   402,   402,
     402,   402,   402,   402,   403,   403,   403,   403,   403,   403,
     403,   404,   405,   406,   406,   407,   407,   407,   408,   408,
     409,   409,   410,   411,   411,   411,   412,   412,   412,   412,
     412,   413,   413,   414,   415,   415,   416,   416,   416,   416,
     416,   416,   416,   416,   416,   416,   416,   416,   417,   418,
     419,   420,   420,   421,   421,   421,   421,   422,   422,   423,
     423,   423,   424,   424,   424,   425,   425,   425,   426,   427,
     428,   428,   429,   429,   430,   431,   431,   432,   432,   433,
     433,   434,   434,   434,   434,   434,   434,   434,   435,   435,
     436,   436,   437,   438,   438,   439,   439,   440,   440,   441,
     442,   442,   443,   444,   444,   445,   446,   446,   447,   448,
     448,   449,   449,   450,   450,   451,   451,   452,   452,   453,
     453,   454,   455,   455,   456,   456,   457,   457,   457,   457,
     457,   458,   457,   457,   457,   457,   459,   459,   460,   460,
     461,   461,   462,   462,   462,   463,   463,   463,   463,   463,
     464,   464,   464,   465,   465,   465,   466,   466,   467,   467,
     468,   468,   469,   469,   470,   470,   471,   471,   471,   471,
     472,   472,   472,   473,   473,   473,   473,   473,   473,   474,
     474,   474,   475,   475,   475,   475,   476,   476,   477,   477,
     478,   478,   478,   479,   479,   479,   479,   480,   481,   481,
     481,   482,   482,   483,   483,   483,   483,   484,   484,   485,
     485,   485,   485,   485,   485,   485,   486,   486,   487,   487,
     488,   488,   488,   488,   488,   489,   489,   490,   490,   491,
     491,   491,   491,   492,   492,   492,   492,   493,   493,   494,
     495,   495,   495,   495,   495,   495,   495,   495,   495,   495,
     496,   496,   497,   497,   497,   498,   499,   499,   500,   501,
     502,   503,   503,   504,   504,   505,   505,   506,   506,   506,
     507,   507,   507,   507,   507,   507,   508,   508,   509,   509,
     510,   511,   511,   512,   512,   513,   513,   514,   514,   514,
     514,   515,   515,   516,   516,   516,   516,   517,   517,   518,
     518,   519,   519,   519,   519,   520,   520,   520,   520,   521,
     521,   522,   522,   523,   524,   524,   524,   524,   524,   524,
     525,   526,   526,   527,   527,   528,   529,   530,   530,   531,
     531,   532,   533,   533,   533,   534,   534,   534,   535,   535,
     535,   535,   535,   536,   536,   537,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   539,   540,   540,   540,   541,
     542,   543,   543,   543,   544,   544,   544,   544,   544,   545,
     546,   546,   546,   546,   546,   546,   546,   547,   548,   549,
     550,   551,   551,   552,   553,   554,   554,   555,   556,   556,
     557,   558,   558,   558,   559,   559,   559,   559,   559,   559,
     559,   559,   559,   559,   560,   560,   561,   561,   562,   563,
     564,   564,   565,   566,   567,   567,   568,   569,   570,   570,
     571,   572,   572,   573,   573,   574,   574,   575,   575,   576,
     576,   577,   577,   578,   579,   579,   580,   580,   581,   582,
     582,   582,   583,   583,   584,   585,   585,   586,   587,   587,
     588,   588,   589,   589,   589,   590,   590,   591,   591,   592,
     592,   592,   592,   592,   593,   594,   595,   596,   596,   596,
     597,   597,   598,   598,   598,   598,   598,   598,   598,   598,
     599,   599,   599,   599,   600,   600,   601,   602,   602,   603,
     603,   603,   604,   604,   605,   605,   606,   606,   607,   608,
     608,   609,   609,   610,   610,   610,   611,   611,   612,   612,
     613,   613,   614,   614,   615,   615,   616,   617,   617,   618,
     618,   618,   619,   620,   620,   620,   620,   621,   621,   622,
     622,   623,   624,   625,   625,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   628,   628
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
       2,     8,     3,     1,     2,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     1,     2,     4,     3,
       5,     4,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     1,     4,     3,     5,     4,     6,
       4,     6,     5,     7,     4,     5,     5,     6,     3,     3,
       2,     1,     3,     4,     5,     3,     6,     4,     5,     1,
       2,     3,     1,     2,     1,     6,     3,     3,     2,     3,
       1,     3,     2,     3,     2,     3,     4,     1,     3,     1,
       2,     1,     1,     1,     2,     2,     2,     3,     1,     1,
       2,     2,     2,     5,     5,     1,     4,     3,     4,     8,
       1,     2,     3,     2,     3,     8,     1,     2,     3,     8,
      10,     8,    10,     1,     2,     4,     7,     1,     2,     4,
       7,     8,     1,     3,     1,     3,     1,     3,     3,     3,
       3,     0,     4,     3,     3,     3,     1,     5,     0,     1,
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
       1,     1,     1,     1,     1,     2,     2,     3,     1,     4,
       4,     3,     4,     1,     3,     1,     1,     1,     1,     1,
       4,     5,     8,     9,     9,    10,     1,     2,     1,     2,
       6,     0,     1,     3,     3,     0,     1,     1,     1,     2,
       2,     0,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       2,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       4,     3,     7,     3,     7,     4,     4,     3,     7,     1,
       2,     2,     1,     2,     3,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     4,     4,     3,
       3,     3,     4,     4,     3,     4,     6,     4,     6,     4,
       3,     4,     6,     6,     4,     6,     6,     4,     1,     2,
       1,     1,     1,     3,     3,     1,     1,     4,     5,     6,
       3,     3,     3,     3,     5,     7,     7,     5,     5,     5,
       7,     7,     5,     5,     3,     3,     5,     7,     5,     7,
       1,     4,     3,     5,     1,     2,     3,     3,     1,     3,
       2,     0,     1,     1,     2,     1,     3,     1,     3,     1,
       4,     1,     2,     3,     0,     1,     0,     1,     4,     2,
       3,     1,     0,     1,     4,     0,     1,     2,     1,     3,
       0,     1,     2,     2,     1,     0,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     1,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     2,     2,     3,     1,     2,     2,
       5,     2,     1,     1,     0,     2,     1,     3,     4,     0,
       2,     0,     2,     4,     4,     3,     2,     3,     1,     3,
       0,     1,     1,     2,     2,     2,     2,     1,     2,     2,
       2,     2,     3,     2,     3,     3,     4,     2,     2,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
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
       1,     3,     1
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
       324,     0,    -1,   326,    -1,   309,   326,    -1,     1,     3,
      -1,   328,    -1,   327,   328,    -1,   329,    -1,   327,   329,
      -1,   213,   214,    29,   189,    -1,   213,   214,    29,   130,
      29,   189,    -1,   331,   189,   378,    -1,   348,   189,   378,
      -1,   331,   189,   348,   189,   378,    -1,   378,    -1,   331,
     325,   378,    -1,   348,   325,   378,    -1,   331,   189,   348,
     325,   378,    -1,   331,   325,   348,   189,   378,    -1,   330,
      -1,   330,   331,   189,    -1,   330,   348,   189,    -1,   330,
     331,   189,   348,   189,    -1,    34,   159,   625,   131,   624,
     189,    -1,   332,    -1,   331,   189,   332,    -1,   331,   325,
     332,    -1,   333,    -1,   341,    -1,   346,    -1,   347,    -1,
     355,    -1,   334,    -1,   335,    -1,   336,    -1,   337,    -1,
     338,    -1,   339,    -1,   340,    -1,   558,    -1,    33,    38,
     181,    -1,    33,    38,   194,    -1,    33,   112,   105,   624,
      -1,    33,    37,   624,    -1,    33,    40,   181,    -1,    33,
      40,   194,    -1,    33,    57,   168,    -1,    33,    57,   200,
      -1,    33,   112,   167,   126,   127,    -1,    33,   112,   167,
     126,   128,    -1,    33,    41,   181,   106,   147,    -1,    33,
      41,   181,   106,   164,    -1,    33,    41,   165,   106,   147,
      -1,    33,    41,   165,   106,   164,    -1,   342,    -1,   345,
      -1,    49,    24,     1,    -1,    49,    60,   624,    -1,    49,
      60,   344,   624,    -1,    49,    60,   624,    96,   343,    -1,
      49,    60,   344,   624,    96,   343,    -1,   624,    -1,   343,
     106,   624,    -1,   159,   625,   131,    -1,   112,    45,   159,
      -1,    49,    34,   624,    -1,    49,    34,   159,   625,   131,
     624,    -1,    49,    34,   624,    96,   343,    -1,    49,    34,
     159,   625,   131,   624,    96,   343,    -1,    33,   159,   625,
     131,   624,    -1,    33,   112,    45,   159,   624,    -1,    33,
     112,    47,   159,   624,    -1,   349,    -1,   348,   189,   349,
      -1,   348,   325,   349,    -1,   350,    -1,   354,    -1,   356,
      -1,   360,    -1,   365,    -1,   372,    -1,   374,    -1,   377,
      -1,    33,   112,    79,   351,    -1,    33,    79,   626,   351,
      -1,   352,    -1,   351,   352,    -1,   353,   131,   550,    -1,
      80,    -1,    88,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    89,    -1,    85,    -1,    86,    -1,    87,    -1,
      33,    56,   626,    29,    -1,    33,   260,   597,    -1,    33,
     110,   151,   357,    -1,    94,   535,   358,    -1,   358,    -1,
     359,    -1,   136,    -1,   136,   359,    -1,   141,   402,    -1,
      33,   361,   141,   402,    -1,    33,   361,   136,    -1,    33,
     361,   136,   141,   402,    -1,   111,   117,   626,    -1,   111,
     117,   626,   532,    -1,   362,   111,   117,   626,    -1,   362,
     111,   117,   626,   532,    -1,   363,    -1,   362,   363,    -1,
      26,    -1,    26,   155,   364,   186,    -1,    27,    -1,    27,
     155,   364,   186,    -1,   496,    -1,   364,   106,   496,    -1,
      33,   366,    -1,    33,   362,   366,    -1,   367,    -1,   368,
      -1,    47,   627,   369,   386,    -1,    47,   627,   369,   136,
      -1,    74,    47,   627,   369,   386,    -1,    74,    47,   627,
     369,   136,    -1,   155,   186,    -1,   155,   370,   186,    -1,
     155,   186,    94,   533,    -1,   155,   370,   186,    94,   533,
      -1,   371,    -1,   370,   106,   371,    -1,   117,   626,    -1,
     117,   626,   532,    -1,    33,   286,   626,    -1,    33,   286,
     626,    94,   373,    -1,    33,   362,   286,   626,    -1,    33,
     362,   286,   626,    94,   373,    -1,   538,    -1,   538,   534,
      -1,    33,   294,   626,   298,   225,   479,   169,   375,    -1,
      33,   362,   294,   626,   298,   225,   479,   169,   375,    -1,
     376,    -1,   375,   106,   376,    -1,   479,    -1,   479,   532,
      -1,   479,   437,    -1,   479,   532,   437,    -1,    33,   302,
     303,   626,   298,   286,   626,   117,   626,   304,   402,    -1,
      33,   302,   303,   626,   298,   286,   626,   223,   117,   626,
     304,   292,   305,   479,    -1,    33,   302,   303,   626,   298,
     286,   626,   306,   223,   117,   626,   304,   402,    -1,    33,
     302,   303,   626,   307,   305,   256,   286,   626,   223,   117,
     626,   305,   479,   197,   286,   626,   223,   117,   626,   305,
     479,    -1,   379,    -1,   381,    -1,   382,    -1,    -1,   381,
      -1,   382,    -1,    -1,   401,    -1,   382,   401,    -1,   383,
      -1,   382,   383,    -1,   384,    -1,   387,    -1,   390,    -1,
     391,    -1,   392,    -1,   393,    -1,   394,    -1,   395,    -1,
     397,    -1,   449,    -1,   445,    -1,   398,    -1,   152,   382,
     183,    -1,   152,   183,    -1,   152,   380,   183,    -1,   152,
     380,   183,    -1,   388,   189,    -1,   388,   106,   389,    -1,
     111,   389,    -1,   236,   111,   389,    -1,   362,   111,   389,
      -1,   236,   362,   111,   389,    -1,   117,   626,    -1,   117,
     626,   532,    -1,   117,   626,   141,   402,    -1,   117,   626,
     532,   141,   402,    -1,   117,   626,   141,   402,   189,    -1,
     403,   189,    -1,   239,   241,   402,   189,    -1,   242,   155,
     401,   186,   383,    -1,   237,   240,   189,    -1,   238,   240,
     189,    -1,   413,   396,    -1,   185,   383,    -1,    48,   155,
     401,   186,   196,   383,   125,   383,    -1,   243,   384,   399,
      -1,   400,    -1,   399,   400,    -1,   244,   570,   384,    -1,
     402,    -1,   401,   106,   402,    -1,   404,    -1,   441,    -1,
     448,    -1,   454,    -1,   566,    -1,   403,    -1,   455,    -1,
     438,    -1,   559,    -1,   560,    -1,   562,    -1,   561,    -1,
     563,    -1,   413,   405,    -1,   185,   402,    -1,    66,   283,
      -1,    71,   283,    -1,   215,    -1,   253,    -1,    55,   253,
      -1,   407,   423,    77,   402,    -1,   407,    77,   402,    -1,
      46,   406,   422,   408,   408,    -1,    46,   406,   422,   408,
      -1,    42,   117,   626,    -1,   414,    -1,   419,    -1,   409,
      -1,   411,    -1,   426,    -1,   431,    -1,   427,    -1,   410,
      -1,   411,    -1,   413,   412,    -1,    46,   117,   415,    -1,
     416,    -1,   415,   106,   117,   416,    -1,   626,   146,   402,
      -1,   626,    36,   126,   146,   402,    -1,   626,   532,   146,
     402,    -1,   626,   532,    36,   126,   146,   402,    -1,   626,
     417,   146,   402,    -1,   626,    36,   126,   417,   146,   402,
      -1,   626,   532,   417,   146,   402,    -1,   626,   532,    36,
     126,   417,   146,   402,    -1,   626,   418,   146,   402,    -1,
     626,   532,   418,   146,   402,    -1,   626,   417,   418,   146,
     402,    -1,   626,   532,   417,   418,   146,   402,    -1,    96,
     117,   626,    -1,   272,   117,   626,    -1,    51,   420,    -1,
     421,    -1,   420,   106,   421,    -1,   117,   626,   141,   402,
      -1,   117,   626,   532,   141,   402,    -1,   418,   141,   402,
      -1,   117,   626,   532,   418,   141,   402,    -1,   117,   626,
     146,   402,    -1,   117,   626,   532,   146,   402,    -1,   424,
      -1,   117,   626,    -1,   117,   626,   424,    -1,   417,    -1,
     417,   425,    -1,   425,    -1,    58,   117,   626,    53,   117,
     626,    -1,    53,   117,   626,    -1,    58,   117,   626,    -1,
     210,   402,    -1,   170,   169,   428,    -1,   429,    -1,   428,
     106,   429,    -1,   117,   626,    -1,   117,   626,   430,    -1,
     105,   624,    -1,   167,   169,   432,    -1,    69,   167,   169,
     432,    -1,   433,    -1,   432,   106,   433,    -1,   402,    -1,
     402,   434,    -1,   435,    -1,   436,    -1,   437,    -1,   435,
     436,    -1,   435,   437,    -1,   436,   437,    -1,   435,   436,
     437,    -1,    95,    -1,   115,    -1,   126,   127,    -1,   126,
     128,    -1,   105,   624,    -1,    67,   117,   439,   187,   402,
      -1,   134,   117,   439,   187,   402,    -1,   440,    -1,   439,
     106,   117,   440,    -1,   626,   146,   402,    -1,   626,   532,
     146,   402,    -1,    72,   155,   401,   186,   442,   112,   185,
     402,    -1,   443,    -1,   442,   443,    -1,   444,   185,   402,
      -1,    99,   402,    -1,   444,    99,   402,    -1,    72,   155,
     401,   186,   446,   112,   185,   383,    -1,   447,    -1,   446,
     447,    -1,   444,   185,   383,    -1,    73,   155,   401,   186,
     450,   112,   185,   402,    -1,    73,   155,   401,   186,   450,
     112,   117,   626,   185,   402,    -1,    73,   155,   401,   186,
     452,   112,   185,   383,    -1,    73,   155,   401,   186,   450,
     112,   117,   626,   185,   383,    -1,   451,    -1,   450,   451,
      -1,    99,   533,   185,   402,    -1,    99,   117,   626,    94,
     533,   185,   402,    -1,   453,    -1,   452,   453,    -1,    99,
     533,   185,   383,    -1,    99,   117,   626,    94,   533,   185,
     383,    -1,    48,   155,   401,   186,   196,   402,   125,   402,
      -1,   456,    -1,   455,   166,   456,    -1,   457,    -1,   456,
      92,   457,    -1,   459,    -1,   459,   473,   459,    -1,   459,
     474,   459,    -1,   459,   131,   459,    -1,   459,   161,   459,
      -1,    -1,   459,   156,   458,   459,    -1,   459,   154,   459,
      -1,   459,   142,   459,    -1,   459,   140,   459,    -1,   461,
      -1,   461,   248,    70,   571,   460,    -1,    -1,   623,    -1,
     462,    -1,   462,   197,   462,    -1,   463,    -1,   462,   175,
     463,    -1,   462,   157,   463,    -1,   464,    -1,   463,   192,
     464,    -1,   463,   116,   464,    -1,   463,   145,   464,    -1,
     463,   158,   464,    -1,   465,    -1,   464,   199,   465,    -1,
     464,   208,   465,    -1,   466,    -1,   465,   149,   466,    -1,
     465,   135,   466,    -1,   467,    -1,   467,    50,   229,   533,
      -1,   468,    -1,   468,   198,    94,   533,    -1,   469,    -1,
     469,   100,    94,   531,    -1,   470,    -1,   470,   101,    94,
     531,    -1,   472,    -1,   471,   472,    -1,   175,    -1,   157,
      -1,   471,   175,    -1,   471,   157,    -1,   475,    -1,   479,
      -1,   476,    -1,   201,    -1,   206,    -1,   205,    -1,   204,
      -1,   203,    -1,   202,    -1,   150,    -1,   178,    -1,   139,
      -1,    75,   152,   381,   183,    -1,    75,   220,   152,   381,
     183,    -1,    75,   219,   152,   381,   183,    -1,    75,    76,
     548,   152,   381,   183,    -1,   477,   152,   183,    -1,   477,
     152,   401,   183,    -1,   478,    -1,   477,   478,    -1,   176,
     626,    17,    -1,   176,    18,    -1,   176,    19,    -1,   480,
      -1,   480,   481,    -1,   191,   481,    -1,   481,    -1,   190,
      -1,   482,    -1,   482,   190,   481,    -1,   482,   191,   481,
      -1,   483,    -1,   492,    -1,   484,    -1,   484,   493,    -1,
     487,    -1,   487,   493,    -1,   485,   489,    -1,   486,    -1,
     104,   121,    -1,   113,   121,    -1,    97,   121,    -1,   188,
     121,    -1,   114,   121,    -1,   138,   121,    -1,   137,   121,
      -1,   489,    -1,    98,   489,    -1,   488,   489,    -1,   119,
      -1,   171,   121,    -1,    90,   121,    -1,   180,   121,    -1,
     179,   121,    -1,    91,   121,    -1,   538,    -1,   490,    -1,
     626,    -1,   491,    -1,   192,    -1,    11,    -1,    12,    -1,
      20,    -1,   495,    -1,   492,   493,    -1,   492,   155,   186,
      -1,   492,   155,   504,   186,    -1,   494,    -1,   493,   494,
      -1,   153,   401,   184,    -1,   496,    -1,   498,    -1,   499,
      -1,   500,    -1,   503,    -1,   505,    -1,   501,    -1,   502,
      -1,   551,    -1,   385,    -1,   497,    -1,   550,    -1,   109,
      -1,   148,    -1,   123,    -1,   117,   626,    -1,   155,   186,
      -1,   155,   401,   186,    -1,   118,    -1,   168,   152,   401,
     183,    -1,   200,   152,   401,   183,    -1,   627,   155,   186,
      -1,   627,   155,   504,   186,    -1,   402,    -1,   504,   106,
     402,    -1,   506,    -1,   524,    -1,   507,    -1,   521,    -1,
     522,    -1,   156,   626,   511,   129,    -1,   156,   626,   509,
     511,   129,    -1,   156,   626,   511,   195,   193,   626,   511,
     195,    -1,   156,   626,   511,   195,   508,   193,   626,   511,
     195,    -1,   156,   626,   509,   511,   195,   193,   626,   511,
     195,    -1,   156,   626,   509,   511,   195,   508,   193,   626,
     511,   195,    -1,   519,    -1,   508,   519,    -1,   510,    -1,
     509,   510,    -1,    35,   626,   511,   131,   511,   512,    -1,
      -1,    35,    -1,   182,   513,   182,    -1,    93,   515,    93,
      -1,    -1,   514,    -1,   133,    -1,   517,    -1,   514,   133,
      -1,   514,   517,    -1,    -1,   516,    -1,   132,    -1,   518,
      -1,   516,   132,    -1,   516,   518,    -1,    28,    -1,   520,
      -1,     5,    -1,   520,    -1,   506,    -1,    10,    -1,   523,
      -1,   520,    -1,     9,    -1,   122,    -1,   124,    -1,   152,
     381,   183,    -1,   211,    30,   212,    -1,   211,   212,    -1,
     173,   625,   174,    -1,   173,   625,     8,    -1,   102,     7,
      -1,   525,    -1,   526,    -1,   527,    -1,   528,    -1,   529,
      -1,   530,    -1,    43,   152,   380,   183,    -1,    21,   380,
     183,    -1,    45,   152,   401,   183,   152,   380,   183,    -1,
      22,   380,   183,    -1,    97,   152,   401,   183,   152,   380,
     183,    -1,    70,   152,   381,   183,    -1,    39,   152,   381,
     183,    -1,    23,   380,   183,    -1,    59,   152,   401,   183,
     152,   380,   183,    -1,   537,    -1,   537,   143,    -1,    94,
     533,    -1,   535,    -1,   535,   534,    -1,   209,   155,   186,
      -1,   143,    -1,   192,    -1,   175,    -1,   537,    -1,   538,
      -1,   151,   155,   186,    -1,   554,    -1,   557,    -1,   533,
      -1,   536,   106,   533,    -1,   626,    -1,   540,    -1,   546,
      -1,   544,    -1,   547,    -1,   545,    -1,   543,    -1,   542,
      -1,   541,    -1,   539,    -1,   223,   155,   186,    -1,    44,
     155,   186,    -1,    44,   155,   546,   186,    -1,    44,   155,
     547,   186,    -1,    70,   155,   186,    -1,    39,   155,   186,
      -1,    59,   155,   186,    -1,    59,   155,   625,   186,    -1,
      59,   155,    29,   186,    -1,    97,   155,   186,    -1,    97,
     155,   626,   186,    -1,    97,   155,   626,   106,   548,   186,
      -1,    97,   155,   192,   186,    -1,    97,   155,   192,   106,
     548,   186,    -1,    61,   155,   626,   186,    -1,    45,   155,
     186,    -1,    45,   155,   626,   186,    -1,    45,   155,   626,
     106,   548,   186,    -1,    45,   155,   626,   106,   549,   186,
      -1,    45,   155,   192,   186,    -1,    45,   155,   192,   106,
     548,   186,    -1,    45,   155,   192,   106,   549,   186,    -1,
      62,   155,   626,   186,    -1,   626,    -1,   626,   143,    -1,
      29,    -1,   552,    -1,   553,    -1,   626,   144,   148,    -1,
      47,   369,   386,    -1,   555,    -1,   556,    -1,    47,   155,
     192,   186,    -1,    47,   155,   186,    94,   533,    -1,    47,
     155,   536,   186,    94,   533,    -1,   155,   535,   186,    -1,
      33,   218,   219,    -1,    33,   218,   220,    -1,    33,   218,
     221,    -1,   224,   223,   402,   231,   402,    -1,   224,   223,
     402,    94,   230,   231,   402,    -1,   224,   223,   402,    94,
     232,   231,   402,    -1,   224,   223,   402,   216,   402,    -1,
     224,   223,   402,   217,   402,    -1,   224,   225,   402,   231,
     402,    -1,   224,   225,   402,    94,   230,   231,   402,    -1,
     224,   225,   402,    94,   232,   231,   402,    -1,   224,   225,
     402,   216,   402,    -1,   224,   225,   402,   217,   402,    -1,
     222,   223,   402,    -1,   222,   225,   402,    -1,   227,   223,
     402,   235,   402,    -1,   227,   228,   229,   223,   402,   235,
     402,    -1,   226,   223,   402,    94,   402,    -1,   234,   117,
     564,   233,   402,   185,   402,    -1,   565,    -1,   564,   106,
     117,   565,    -1,   626,   141,   402,    -1,   243,   152,   401,
     183,   567,    -1,   568,    -1,   567,   568,    -1,   244,   570,
     569,    -1,   152,   401,   183,    -1,   490,    -1,   570,   208,
     490,    -1,   574,   572,    -1,    -1,   573,    -1,   592,    -1,
     573,   592,    -1,   575,    -1,   574,   261,   575,    -1,   576,
      -1,   575,   257,   576,    -1,   577,    -1,   576,   259,   146,
     577,    -1,   578,    -1,   258,   578,    -1,   582,   579,   580,
      -1,    -1,   597,    -1,    -1,   581,    -1,   281,   152,   401,
     183,    -1,   586,   583,    -1,   155,   571,   186,    -1,   584,
      -1,    -1,   619,    -1,   477,   152,   585,   183,    -1,    -1,
     571,    -1,   587,   588,    -1,   496,    -1,   152,   401,   183,
      -1,    -1,   589,    -1,   247,   590,    -1,   246,   591,    -1,
     269,    -1,    -1,    78,    -1,    -1,   285,    -1,   593,    -1,
     594,    -1,   595,    -1,   621,    -1,   618,    -1,   168,    -1,
     283,   462,   596,    -1,   252,   620,   596,    -1,   285,    -1,
     275,    -1,   268,    -1,   245,   598,    -1,   597,   245,   598,
      -1,   599,    -1,   600,    -1,   601,    -1,   616,    -1,   602,
      -1,   610,    -1,   603,    -1,   617,    -1,    99,   273,    -1,
      99,   262,    -1,   265,    -1,   280,    -1,   250,   273,    -1,
     250,   262,    -1,    56,   626,    29,    -1,   276,    -1,    54,
     276,    -1,   278,   604,    -1,   278,   155,   604,   605,   186,
      -1,    54,   278,    -1,   607,    -1,   112,    -1,    -1,   106,
     606,    -1,   607,    -1,   606,   106,   607,    -1,    96,    29,
     608,   609,    -1,    -1,   270,    29,    -1,    -1,   620,   264,
      -1,   277,   285,   611,   613,    -1,   277,   285,   112,   613,
      -1,    54,   277,   285,    -1,    96,    29,    -1,   155,   612,
     186,    -1,    29,    -1,   612,   106,    29,    -1,    -1,   614,
      -1,   615,    -1,   614,   615,    -1,   199,   611,    -1,   135,
     611,    -1,   263,    29,    -1,   282,    -1,    54,   282,    -1,
      96,   215,    -1,    96,   253,    -1,   254,   249,    -1,   266,
     620,   279,    -1,   255,   462,    -1,    96,   128,   462,    -1,
      96,    52,   462,    -1,   256,   462,   197,   462,    -1,   271,
     622,    -1,   251,   622,    -1,   274,    -1,   267,    -1,   284,
     249,   464,    -1,    29,    -1,    16,    -1,   626,    -1,   627,
      -1,    97,    -1,    39,    -1,    44,    -1,    45,    -1,   151,
      -1,    48,    -1,   223,    -1,    59,    -1,    61,    -1,    62,
      -1,    70,    -1,    73,    -1,    72,    -1,   209,    -1,   242,
      -1,   628,    -1,    24,    -1,   213,    -1,   126,    -1,    38,
      -1,   260,    -1,    37,    -1,   220,    -1,   219,    -1,   145,
      -1,    43,    -1,   258,    -1,   259,    -1,   273,    -1,   262,
      -1,   250,    -1,   284,    -1,   276,    -1,   278,    -1,   277,
      -1,   282,    -1,   254,    -1,   249,    -1,    78,    -1,   215,
      -1,   253,    -1,    52,    -1,   221,    -1,   234,    -1,   301,
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
      -1,    49,    -1,    60,    -1,    34,    -1,    47,    -1,   272,
      -1,   248,    -1,   281,    -1,   283,    -1,   252,    -1,   266,
      -1,   279,    -1,   271,    -1,   251,    -1,   265,    -1,   280,
      -1,   270,    -1,   264,    -1,   263,    -1,   247,    -1,   246,
      -1,   255,    -1,   256,    -1,   285,    -1,   275,    -1,   274,
      -1,   269,    -1,   267,    -1,   268,    -1,   227,    -1,   233,
      -1,   230,    -1,   224,    -1,   217,    -1,   216,    -1,   218,
      -1,   235,    -1,   225,    -1,   226,    -1,   232,    -1,   222,
      -1,   231,    -1,    65,    -1,    63,    -1,    74,    -1,   168,
      -1,   200,    -1,   241,    -1,   236,    -1,   239,    -1,   240,
      -1,   237,    -1,   238,    -1,   243,    -1,   244,    -1,   245,
      -1,    64,    -1,   294,    -1,   292,    -1,   293,    -1,   298,
      -1,   299,    -1,   300,    -1,   295,    -1,   296,    -1,   297,
      -1,    79,    -1,    80,    -1,    81,    -1,    82,    -1,    83,
      -1,    84,    -1,    85,    -1,    86,    -1,    87,    -1,    88,
      -1,    89,    -1,   286,    -1,   287,    -1,   288,    -1,   289,
      -1,   290,    -1,   291,    -1,   302,    -1,   303,    -1,   304,
      -1,   305,    -1,   306,    -1,   307,    -1,   308,    -1,    90,
      -1,   104,    -1,   113,    -1,   171,    -1,   179,    -1,   188,
      -1,   137,    -1,    91,    -1,   114,    -1,   138,    -1,   180,
      -1,   624,   120,   625,    -1,    25,    -1
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
     765,   768,   777,   781,   783,   786,   790,   792,   796,   798,
     800,   802,   804,   806,   808,   810,   812,   814,   816,   818,
     820,   822,   825,   828,   831,   834,   836,   838,   841,   846,
     850,   856,   861,   865,   867,   869,   871,   873,   875,   877,
     879,   881,   883,   886,   890,   892,   897,   901,   907,   912,
     919,   924,   931,   937,   945,   950,   956,   962,   969,   973,
     977,   980,   982,   986,   991,   997,  1001,  1008,  1013,  1019,
    1021,  1024,  1028,  1030,  1033,  1035,  1042,  1046,  1050,  1053,
    1057,  1059,  1063,  1066,  1070,  1073,  1077,  1082,  1084,  1088,
    1090,  1093,  1095,  1097,  1099,  1102,  1105,  1108,  1112,  1114,
    1116,  1119,  1122,  1125,  1131,  1137,  1139,  1144,  1148,  1153,
    1162,  1164,  1167,  1171,  1174,  1178,  1187,  1189,  1192,  1196,
    1205,  1216,  1225,  1236,  1238,  1241,  1246,  1254,  1256,  1259,
    1264,  1272,  1281,  1283,  1287,  1289,  1293,  1295,  1299,  1303,
    1307,  1311,  1312,  1317,  1321,  1325,  1329,  1331,  1337,  1338,
    1340,  1342,  1346,  1348,  1352,  1356,  1358,  1362,  1366,  1370,
    1374,  1376,  1380,  1384,  1386,  1390,  1394,  1396,  1401,  1403,
    1408,  1410,  1415,  1417,  1422,  1424,  1427,  1429,  1431,  1434,
    1437,  1439,  1441,  1443,  1445,  1447,  1449,  1451,  1453,  1455,
    1457,  1459,  1461,  1466,  1472,  1478,  1485,  1489,  1494,  1496,
    1499,  1503,  1506,  1509,  1511,  1514,  1517,  1519,  1521,  1523,
    1527,  1531,  1533,  1535,  1537,  1540,  1542,  1545,  1548,  1550,
    1553,  1556,  1559,  1562,  1565,  1568,  1571,  1573,  1576,  1579,
    1581,  1584,  1587,  1590,  1593,  1596,  1598,  1600,  1602,  1604,
    1606,  1608,  1610,  1612,  1614,  1617,  1621,  1626,  1628,  1631,
    1635,  1637,  1639,  1641,  1643,  1645,  1647,  1649,  1651,  1653,
    1655,  1657,  1659,  1661,  1663,  1665,  1668,  1671,  1675,  1677,
    1682,  1687,  1691,  1696,  1698,  1702,  1704,  1706,  1708,  1710,
    1712,  1717,  1723,  1732,  1742,  1752,  1763,  1765,  1768,  1770,
    1773,  1780,  1781,  1783,  1787,  1791,  1792,  1794,  1796,  1798,
    1801,  1804,  1805,  1807,  1809,  1811,  1814,  1817,  1819,  1821,
    1823,  1825,  1827,  1829,  1831,  1833,  1835,  1837,  1839,  1843,
    1847,  1850,  1854,  1858,  1861,  1863,  1865,  1867,  1869,  1871,
    1873,  1878,  1882,  1890,  1894,  1902,  1907,  1912,  1916,  1924,
    1926,  1929,  1932,  1934,  1937,  1941,  1943,  1945,  1947,  1949,
    1951,  1955,  1957,  1959,  1961,  1965,  1967,  1969,  1971,  1973,
    1975,  1977,  1979,  1981,  1983,  1985,  1989,  1993,  1998,  2003,
    2007,  2011,  2015,  2020,  2025,  2029,  2034,  2041,  2046,  2053,
    2058,  2062,  2067,  2074,  2081,  2086,  2093,  2100,  2105,  2107,
    2110,  2112,  2114,  2116,  2120,  2124,  2126,  2128,  2133,  2139,
    2146,  2150,  2154,  2158,  2162,  2168,  2176,  2184,  2190,  2196,
    2202,  2210,  2218,  2224,  2230,  2234,  2238,  2244,  2252,  2258,
    2266,  2268,  2273,  2277,  2283,  2285,  2288,  2292,  2296,  2298,
    2302,  2305,  2306,  2308,  2310,  2313,  2315,  2319,  2321,  2325,
    2327,  2332,  2334,  2337,  2341,  2342,  2344,  2345,  2347,  2352,
    2355,  2359,  2361,  2362,  2364,  2369,  2370,  2372,  2375,  2377,
    2381,  2382,  2384,  2387,  2390,  2392,  2393,  2395,  2396,  2398,
    2400,  2402,  2404,  2406,  2408,  2410,  2414,  2418,  2420,  2422,
    2424,  2427,  2431,  2433,  2435,  2437,  2439,  2441,  2443,  2445,
    2447,  2450,  2453,  2455,  2457,  2460,  2463,  2467,  2469,  2472,
    2475,  2481,  2484,  2486,  2488,  2489,  2492,  2494,  2498,  2503,
    2504,  2507,  2508,  2511,  2516,  2521,  2525,  2528,  2532,  2534,
    2538,  2539,  2541,  2543,  2546,  2549,  2552,  2555,  2557,  2560,
    2563,  2566,  2569,  2573,  2576,  2580,  2584,  2589,  2592,  2595,
    2597,  2599,  2603,  2605,  2607,  2609,  2611,  2613,  2615,  2617,
    2619,  2621,  2623,  2625,  2627,  2629,  2631,  2633,  2635,  2637,
    2639,  2641,  2643,  2645,  2647,  2649,  2651,  2653,  2655,  2657,
    2659,  2661,  2663,  2665,  2667,  2669,  2671,  2673,  2675,  2677,
    2679,  2681,  2683,  2685,  2687,  2689,  2691,  2693,  2695,  2697,
    2699,  2701,  2703,  2705,  2707,  2709,  2711,  2713,  2715,  2717,
    2719,  2721,  2723,  2725,  2727,  2729,  2731,  2733,  2735,  2737,
    2739,  2741,  2743,  2745,  2747,  2749,  2751,  2753,  2755,  2757,
    2759,  2761,  2763,  2765,  2767,  2769,  2771,  2773,  2775,  2777,
    2779,  2781,  2783,  2785,  2787,  2789,  2791,  2793,  2795,  2797,
    2799,  2801,  2803,  2805,  2807,  2809,  2811,  2813,  2815,  2817,
    2819,  2821,  2823,  2825,  2827,  2829,  2831,  2833,  2835,  2837,
    2839,  2841,  2843,  2845,  2847,  2849,  2851,  2853,  2855,  2857,
    2859,  2861,  2863,  2865,  2867,  2869,  2871,  2873,  2875,  2877,
    2879,  2881,  2883,  2885,  2887,  2889,  2891,  2893,  2895,  2897,
    2899,  2901,  2903,  2905,  2907,  2909,  2911,  2913,  2915,  2917,
    2919,  2921,  2923,  2925,  2927,  2929,  2931,  2933,  2935,  2937,
    2939,  2941,  2943,  2945,  2947,  2949,  2951,  2953,  2955,  2957,
    2959,  2961,  2963,  2965,  2967,  2969,  2971,  2973,  2975,  2977,
    2979,  2981,  2983,  2985,  2987,  2989,  2991,  2993,  2995,  2997,
    2999,  3001,  3003,  3005,  3007,  3009,  3011,  3013,  3015,  3017,
    3019,  3021,  3023,  3025,  3027,  3029,  3031,  3033,  3035,  3037,
    3039,  3041,  3045
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   977,   977,   978,   987,   996,  1002,  1010,  1016,  1027,
    1032,  1040,  1047,  1054,  1063,  1070,  1078,  1086,  1094,  1105,
    1110,  1117,  1124,  1136,  1146,  1153,  1160,  1172,  1173,  1174,
    1175,  1176,  1181,  1182,  1183,  1184,  1185,  1186,  1187,  1190,
    1195,  1200,  1208,  1216,  1224,  1229,  1237,  1242,  1250,  1255,
    1263,  1270,  1277,  1284,  1294,  1296,  1299,  1309,  1314,  1322,
    1330,  1341,  1348,  1359,  1364,  1372,  1379,  1386,  1395,  1408,
    1416,  1423,  1433,  1440,  1447,  1458,  1459,  1460,  1461,  1462,
    1463,  1464,  1465,  1470,  1476,  1485,  1492,  1502,  1512,  1513,
    1514,  1515,  1516,  1517,  1518,  1519,  1520,  1521,  1526,  1534,
    1542,  1550,  1557,  1565,  1572,  1577,  1585,  1593,  1608,  1623,
    1641,  1646,  1654,  1662,  1673,  1678,  1687,  1692,  1699,  1704,
    1714,  1719,  1728,  1734,  1747,  1752,  1760,  1771,  1786,  1798,
    1813,  1818,  1823,  1828,  1836,  1843,  1854,  1859,  1869,  1876,
    1883,  1890,  1900,  1904,  1914,  1922,  1933,  1939,  1948,  1953,
    1960,  1967,  1978,  1988,  1998,  2008,  2026,  2046,  2051,  2056,
    2063,  2068,  2073,  2080,  2085,  2097,  2104,  2116,  2117,  2118,
    2119,  2120,  2121,  2122,  2124,  2125,  2126,  2127,  2128,  2133,
    2138,  2146,  2163,  2171,  2179,  2186,  2193,  2200,  2207,  2217,
    2229,  2242,  2254,  2270,  2278,  2286,  2294,  2309,  2314,  2322,
    2336,  2353,  2378,  2386,  2393,  2404,  2414,  2419,  2434,  2435,
    2436,  2437,  2438,  2439,  2444,  2445,  2448,  2449,  2450,  2451,
    2452,  2457,  2471,  2479,  2484,  2492,  2497,  2502,  2510,  2519,
    2531,  2541,  2554,  2562,  2563,  2564,  2569,  2570,  2571,  2572,
    2573,  2578,  2585,  2595,  2603,  2610,  2620,  2630,  2640,  2650,
    2660,  2670,  2680,  2690,  2701,  2710,  2720,  2730,  2746,  2755,
    2764,  2772,  2778,  2790,  2798,  2808,  2816,  2828,  2834,  2845,
    2847,  2851,  2859,  2863,  2868,  2872,  2876,  2880,  2890,  2898,
    2905,  2911,  2922,  2926,  2935,  2943,  2949,  2959,  2965,  2975,
    2979,  2989,  2995,  3001,  3007,  3016,  3025,  3034,  3047,  3051,
    3059,  3065,  3075,  3083,  3092,  3105,  3112,  3124,  3128,  3140,
    3147,  3153,  3162,  3169,  3175,  3186,  3193,  3199,  3208,  3217,
    3224,  3235,  3242,  3254,  3260,  3272,  3278,  3289,  3295,  3306,
    3312,  3323,  3332,  3336,  3345,  3349,  3357,  3361,  3371,  3378,
    3387,  3397,  3396,  3410,  3419,  3428,  3441,  3445,  3458,  3461,
    3468,  3472,  3481,  3485,  3489,  3498,  3502,  3508,  3514,  3520,
    3531,  3535,  3539,  3547,  3551,  3557,  3567,  3571,  3581,  3585,
    3595,  3599,  3609,  3613,  3623,  3627,  3635,  3639,  3643,  3647,
    3657,  3661,  3665,  3673,  3677,  3681,  3685,  3689,  3693,  3701,
    3705,  3709,  3717,  3721,  3725,  3729,  3740,  3746,  3756,  3762,
    3772,  3776,  3780,  3818,  3822,  3832,  3842,  3855,  3864,  3874,
    3878,  3887,  3891,  3900,  3906,  3914,  3920,  3932,  3938,  3948,
    3952,  3956,  3960,  3964,  3970,  3976,  3984,  3988,  3996,  4000,
    4011,  4015,  4019,  4025,  4029,  4043,  4047,  4055,  4059,  4069,
    4073,  4077,  4081,  4090,  4094,  4098,  4102,  4110,  4116,  4126,
    4134,  4138,  4142,  4146,  4150,  4154,  4158,  4162,  4166,  4176,
    4184,  4188,  4196,  4203,  4210,  4221,  4229,  4233,  4241,  4249,
    4257,  4311,  4315,  4328,  4334,  4344,  4348,  4356,  4360,  4364,
    4372,  4382,  4392,  4402,  4412,  4422,  4437,  4443,  4454,  4460,
    4471,  4482,  4484,  4488,  4493,  4503,  4506,  4513,  4519,  4525,
    4533,  4546,  4549,  4556,  4562,  4568,  4575,  4586,  4590,  4600,
    4604,  4614,  4618,  4622,  4627,  4636,  4642,  4648,  4654,  4662,
    4667,  4675,  4680,  4688,  4696,  4701,  4706,  4711,  4716,  4721,
    4730,  4738,  4742,  4759,  4763,  4771,  4779,  4787,  4791,  4799,
    4805,  4815,  4823,  4827,  4831,  4866,  4872,  4878,  4888,  4892,
    4896,  4900,  4904,  4911,  4917,  4927,  4935,  4939,  4943,  4947,
    4951,  4955,  4959,  4963,  4967,  4975,  4983,  4987,  4991,  5001,
    5009,  5017,  5021,  5025,  5033,  5037,  5043,  5049,  5053,  5063,
    5071,  5075,  5081,  5090,  5099,  5105,  5111,  5121,  5138,  5145,
    5160,  5196,  5200,  5208,  5216,  5228,  5232,  5240,  5248,  5252,
    5263,  5280,  5286,  5292,  5302,  5306,  5312,  5318,  5322,  5328,
    5332,  5338,  5344,  5351,  5361,  5366,  5374,  5380,  5390,  5412,
    5421,  5427,  5440,  5454,  5461,  5467,  5477,  5486,  5494,  5500,
    5518,  5527,  5530,  5537,  5542,  5550,  5554,  5561,  5565,  5572,
    5576,  5583,  5587,  5596,  5609,  5612,  5620,  5623,  5631,  5639,
    5647,  5651,  5659,  5662,  5670,  5682,  5685,  5693,  5705,  5711,
    5721,  5724,  5732,  5736,  5740,  5748,  5751,  5759,  5762,  5770,
    5774,  5778,  5782,  5786,  5794,  5802,  5814,  5826,  5830,  5834,
    5842,  5848,  5858,  5862,  5866,  5870,  5874,  5878,  5882,  5886,
    5894,  5898,  5902,  5906,  5914,  5920,  5930,  5940,  5944,  5952,
    5962,  5973,  5980,  5984,  5992,  5995,  6002,  6007,  6016,  6026,
    6029,  6037,  6040,  6048,  6057,  6064,  6074,  6078,  6085,  6091,
    6101,  6104,  6111,  6116,  6128,  6136,  6148,  6156,  6160,  6168,
    6172,  6176,  6184,  6192,  6196,  6200,  6204,  6212,  6220,  6232,
    6236,  6244,  6257,  6261,  6262,  6275,  6276,  6277,  6278,  6279,
    6280,  6281,  6282,  6283,  6284,  6285,  6286,  6287,  6288,  6289,
    6290,  6294,  6295,  6296,  6297,  6298,  6299,  6300,  6301,  6302,
    6303,  6304,  6305,  6306,  6307,  6308,  6309,  6310,  6311,  6312,
    6313,  6314,  6315,  6316,  6317,  6318,  6319,  6320,  6321,  6322,
    6323,  6324,  6325,  6326,  6327,  6328,  6329,  6330,  6331,  6332,
    6333,  6334,  6335,  6336,  6337,  6338,  6339,  6340,  6341,  6342,
    6343,  6344,  6345,  6346,  6347,  6348,  6349,  6350,  6351,  6352,
    6353,  6354,  6355,  6356,  6357,  6358,  6359,  6360,  6361,  6362,
    6363,  6364,  6365,  6366,  6367,  6368,  6369,  6370,  6371,  6372,
    6373,  6374,  6375,  6376,  6377,  6378,  6379,  6380,  6381,  6382,
    6383,  6384,  6385,  6386,  6387,  6388,  6389,  6390,  6391,  6392,
    6393,  6394,  6395,  6396,  6397,  6398,  6399,  6400,  6401,  6402,
    6403,  6404,  6405,  6406,  6407,  6408,  6409,  6410,  6411,  6412,
    6413,  6414,  6415,  6416,  6417,  6418,  6419,  6420,  6421,  6422,
    6423,  6424,  6425,  6426,  6427,  6428,  6429,  6430,  6431,  6432,
    6433,  6434,  6435,  6436,  6437,  6438,  6439,  6440,  6441,  6442,
    6443,  6444,  6445,  6446,  6447,  6448,  6449,  6450,  6451,  6452,
    6453,  6454,  6455,  6456,  6457,  6458,  6459,  6460,  6461,  6462,
    6463,  6464,  6465,  6466,  6467,  6468,  6469,  6470,  6471,  6472,
    6473,  6474,  6475,  6476,  6477,  6478,  6479,  6480,  6481,  6482,
    6483,  6484,  6485,  6486,  6487,  6488,  6489,  6490,  6491,  6492,
    6493,  6498,  6505
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
     315,   316,   317,   318,   319,   320,   321,   322
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 12992;
  const int xquery_parser::yynnts_ = 306;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 574;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 323;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 577;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 16032 "/home/mbrantner/zorba/trycatch/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6509 "/home/mbrantner/zorba/trycatch/core/src/compiler/parser/xquery_parser.y"


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

