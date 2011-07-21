
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
#line 71 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"


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
#line 79 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 861 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 961 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 109 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"

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
#line 178 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
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
#line 859 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 285 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 122: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 858 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 294 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 147: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 857 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 303 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 312 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 321 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 330 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 339 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 348 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 357 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 366 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 375 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 384 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 393 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 402 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 411 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 420 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 429 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 438 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 447 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 456 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 465 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 474 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 483 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 492 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 501 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 510 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 519 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 882 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 528 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 882 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 537 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 546 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 555 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 564 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 573 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 582 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 591 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 600 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 882 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 609 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 618 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 627 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 636 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 645 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 654 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 663 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 672 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 882 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 681 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 690 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 699 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 708 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 717 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 726 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 735 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 744 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 753 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 762 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 771 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 780 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 789 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 798 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 807 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 816 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 825 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 834 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 843 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 852 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 861 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 888 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 897 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 906 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 924 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 951 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 960 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 969 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 978 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 987 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 996 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1005 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1014 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1023 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1032 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1041 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1050 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1059 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1068 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1077 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1086 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1095 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1104 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1113 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1122 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1131 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1140 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1149 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1158 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1167 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1176 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1185 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1194 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1203 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1212 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1221 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1230 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1239 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1248 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1257 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1266 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1275 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1284 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1293 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1302 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1311 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1320 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1329 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1338 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1347 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1356 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1365 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1374 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1383 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1392 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1401 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1410 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1419 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1428 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1437 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1446 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1455 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1464 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1473 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1482 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1491 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1500 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1509 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1518 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1527 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1536 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1545 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1554 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1563 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1572 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1581 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1590 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1599 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1608 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1617 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1626 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1635 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1644 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1653 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1662 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1671 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1680 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1689 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1698 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1707 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1716 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1725 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1734 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1743 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1752 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1761 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1770 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1779 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1788 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1797 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1806 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1815 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1824 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1833 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1842 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1851 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1860 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1869 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1878 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1887 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1896 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1905 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1914 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1923 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1932 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1941 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1950 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1959 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1968 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1977 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1986 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1995 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2004 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2013 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2022 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2031 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2040 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2049 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2058 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2067 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2076 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2085 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2094 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2103 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2112 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2121 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2130 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2139 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2148 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2157 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2166 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2175 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2184 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2193 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2202 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2211 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2220 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2229 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2238 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2247 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2256 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2265 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2274 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2283 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2292 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2301 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2310 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2319 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 882 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2328 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2337 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2346 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2355 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2364 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2373 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2382 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2391 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2400 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2409 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2418 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2427 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2436 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2445 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2454 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2463 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2472 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2481 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2490 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2499 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2508 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2517 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2526 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2535 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2544 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2553 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2562 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2571 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2580 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2589 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 615: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2598 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2607 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2616 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 618: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2625 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 619: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2634 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2643 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2652 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 622: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2661 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 623: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2670 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 626: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2679 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 627: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2688 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2697 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
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
#line 124 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 553 of lalr1.cc  */
#line 2782 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"

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
#line 979 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 988 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 997 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 1003 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1011 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1017 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1028 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1033 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1041 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1048 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1055 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1064 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1071 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1079 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1087 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1095 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1106 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1111 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1118 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1125 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1137 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1147 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1154 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1161 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 1196 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1201 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1209 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1217 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1225 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1230 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1238 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1243 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1251 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1256 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1264 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1271 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1278 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1285 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1300 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1310 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1315 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1323 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1331 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1342 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1349 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1360 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1365 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1373 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1380 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1387 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1396 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 1409 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1417 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1424 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1434 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1441 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1448 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1471 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1477 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1486 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1493 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1503 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1512 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1513 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1514 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1515 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1516 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1517 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1518 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1519 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1520 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1521 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1527 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1535 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1543 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1551 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1558 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1566 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1573 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1578 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1586 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1594 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 1609 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 1624 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 1642 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1647 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1655 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1663 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1674 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1679 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1688 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1693 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1700 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1705 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1715 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1720 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1729 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1735 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1748 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1753 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1761 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 1772 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 1787 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 1799 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 1814 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1819 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1824 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1829 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1837 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1844 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1855 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1860 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1870 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL,
                              NULL);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1886 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              NULL,
                              NULL,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1894 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(6) - (6)].node)),
                              static_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)));
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1902 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0, 0);
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1909 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (2)].node)),
                               static_cast<NodeModifier*>((yysemantic_stack_[(5) - (5)].node)),
                               NULL);
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1917 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               NULL,
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1925 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(7) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(7) - (2)].node)),
                               static_cast<NodeModifier*>((yysemantic_stack_[(7) - (7)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(7) - (6)].node)));
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1936 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1940 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1949 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1953 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1960 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1968 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(9) - (4)].expr)),
                             (yysemantic_stack_[(9) - (7)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (9)].node)),
                             static_cast<AnnotationListParsenode*>((yysemantic_stack_[(9) - (2)].node)));
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1979 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1985 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1994 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1999 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 2006 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 2013 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 2025 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2035 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2045 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2056 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2072 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 163:

/* Line 678 of lalr1.cc  */
#line 2092 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2097 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2101 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2109 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 2114 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 2118 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 2126 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2131 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 2143 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2150 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2179 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2184 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 2192 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 188:

/* Line 678 of lalr1.cc  */
#line 2209 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 2217 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 2225 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 2232 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 2239 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 2246 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 2253 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)));
      vdecl->add((yysemantic_stack_[(4) - (4)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 2263 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 196:

/* Line 678 of lalr1.cc  */
#line 2275 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 197:

/* Line 678 of lalr1.cc  */
#line 2288 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 198:

/* Line 678 of lalr1.cc  */
#line 2300 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 199:

/* Line 678 of lalr1.cc  */
#line 2316 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 2324 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2332 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2340 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 203:

/* Line 678 of lalr1.cc  */
#line 2355 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2360 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2368 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 206:

/* Line 678 of lalr1.cc  */
#line 2382 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 207:

/* Line 678 of lalr1.cc  */
#line 2399 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 208:

/* Line 678 of lalr1.cc  */
#line 2424 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 2432 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 2439 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 2450 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 2456 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 2462 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 214:

/* Line 678 of lalr1.cc  */
#line 2473 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 215:

/* Line 678 of lalr1.cc  */
#line 2488 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 2493 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 230:

/* Line 678 of lalr1.cc  */
#line 2531 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 231:

/* Line 678 of lalr1.cc  */
#line 2545 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2553 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 2558 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 2566 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2571 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 2576 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 2584 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 2593 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 2605 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 240:

/* Line 678 of lalr1.cc  */
#line 2615 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2628 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2652 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2659 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2669 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2677 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2684 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2694 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 256:

/* Line 678 of lalr1.cc  */
#line 2704 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 257:

/* Line 678 of lalr1.cc  */
#line 2714 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 258:

/* Line 678 of lalr1.cc  */
#line 2724 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 259:

/* Line 678 of lalr1.cc  */
#line 2734 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 260:

/* Line 678 of lalr1.cc  */
#line 2744 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 261:

/* Line 678 of lalr1.cc  */
#line 2754 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 262:

/* Line 678 of lalr1.cc  */
#line 2764 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 263:

/* Line 678 of lalr1.cc  */
#line 2775 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2784 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 265:

/* Line 678 of lalr1.cc  */
#line 2794 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 266:

/* Line 678 of lalr1.cc  */
#line 2804 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 267:

/* Line 678 of lalr1.cc  */
#line 2820 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2829 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2838 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2846 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2852 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2864 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2872 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2882 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2890 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2902 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2908 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2921 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2925 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2933 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2937 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2946 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2950 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2954 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2964 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2972 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2979 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2985 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2996 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 3000 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 3009 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 3017 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 3023 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3033 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3039 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3049 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3053 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3063 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3069 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3075 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3081 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3090 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3099 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3108 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3121 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3125 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3133 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3139 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3149 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3157 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3166 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3179 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3186 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3198 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3202 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3214 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3221 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3227 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3236 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3243 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3249 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3260 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3267 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3273 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3282 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3291 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3298 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3309 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3316 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3328 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3334 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3346 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3352 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3363 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3369 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3380 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3386 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3397 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3406 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3410 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3419 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3423 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3431 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3435 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 347:

/* Line 678 of lalr1.cc  */
#line 3445 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3452 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3461 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3470 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3475 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3484 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3493 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3502 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3515 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3519 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3531 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3535 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3542 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3546 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3555 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3559 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3563 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3572 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3576 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3582 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3588 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3594 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3605 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3609 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3613 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3621 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3625 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3631 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3641 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3645 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3655 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3659 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3669 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3673 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3683 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3687 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3697 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3701 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3709 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3713 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3717 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3721 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3731 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3735 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3739 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3747 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3751 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3755 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3759 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3763 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3767 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3775 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3779 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3783 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3791 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3795 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3799 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3803 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3814 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3820 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3830 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3836 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3846 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3850 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3854 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3892 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3896 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3906 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3916 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3929 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3938 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 418:

/* Line 678 of lalr1.cc  */
#line 3948 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3952 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3961 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3965 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3974 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3980 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3988 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3994 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 4006 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 4012 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 4022 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 4026 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 4030 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4034 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4038 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4044 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4050 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4058 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4062 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4070 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4074 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4085 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4089 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4093 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4099 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4103 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4117 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4121 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4129 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4133 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4143 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4147 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4151 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4155 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4164 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4168 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4172 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4176 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4184 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4190 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4200 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4208 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4212 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4216 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4220 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4224 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4228 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4232 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4236 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4240 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4250 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4258 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4262 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4270 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4277 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4284 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4295 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4303 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4307 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4315 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4323 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4331 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4385 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4389 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 4402 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4408 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4418 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4422 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4430 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4434 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4438 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4446 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 4456 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 4466 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 4476 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 4486 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 4496 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 4511 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4517 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4528 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4534 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4545 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 4562 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4567 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4576 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4580 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4587 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4593 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4599 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 4607 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 4619 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4623 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4630 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4636 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4642 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4649 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4660 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4664 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4674 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4678 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4688 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4692 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4696 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4701 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4710 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4716 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4722 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4728 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4736 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4741 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4749 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4754 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4762 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4770 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4775 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4780 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4785 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4790 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4795 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4804 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4812 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4816 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4833 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4837 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4845 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4853 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4861 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4865 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4889 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4897 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4901 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4905 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4940 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4946 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4952 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4962 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4966 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4970 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4974 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 4978 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 4985 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 4991 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 5001 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5009 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5013 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5017 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5021 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5025 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5029 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5033 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5037 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5041 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5049 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5057 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5061 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5065 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5075 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5083 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5091 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5095 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5099 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5107 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5111 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5117 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5123 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5127 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5137 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5145 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5149 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5155 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5164 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5173 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5179 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5185 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5195 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5212 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5219 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5234 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5270 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5274 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5282 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5290 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5302 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5306 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5314 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5322 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5326 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5337 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5354 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5360 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5366 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5376 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5380 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5386 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5392 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5396 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5402 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5406 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5412 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5418 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5425 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5435 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5440 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5448 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5454 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5464 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5486 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5495 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5501 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5514 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5528 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5535 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5541 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5551 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5556 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5561 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 638:

/* Line 678 of lalr1.cc  */
#line 5571 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 639:

/* Line 678 of lalr1.cc  */
#line 5585 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5593 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5599 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5617 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5625 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5629 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5636 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5641 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5649 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5653 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5660 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5664 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5671 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5675 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5682 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5686 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5695 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5707 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5711 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5718 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5722 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5730 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5738 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5746 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5750 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5757 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5761 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5769 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5780 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5784 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5792 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5804 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5810 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5819 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5823 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5831 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5835 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5839 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5846 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5850 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5857 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5861 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5869 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5877 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5885 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5893 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5901 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5913 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5925 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5929 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5933 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5941 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5947 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5957 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5961 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5965 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5969 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5973 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5977 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5981 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5985 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5993 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5997 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 6001 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 6005 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 6013 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 6019 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 6029 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 6039 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 6043 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 6051 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 712:

/* Line 678 of lalr1.cc  */
#line 6061 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 713:

/* Line 678 of lalr1.cc  */
#line 6072 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 6079 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 6083 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 6090 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 6094 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 6101 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 6106 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 6115 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 6124 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 6128 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 6135 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 6139 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 6147 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 6156 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 6163 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 6173 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 6177 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 6184 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 6190 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 6199 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 6203 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 6210 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 6215 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 6227 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 6235 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 6247 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 6255 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 6259 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 6267 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 6271 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 6275 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 6283 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 6291 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 6295 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 6299 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 6303 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 6311 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 6319 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 6331 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 6335 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 6343 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 6361 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 758:

/* Line 678 of lalr1.cc  */
#line 6374 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 6375 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 6376 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 6377 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 6378 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 6379 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 6380 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 6381 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 6382 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 6383 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 6384 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 6385 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 6386 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 6387 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 6388 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 6393 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 6394 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 6395 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 6396 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 6397 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 6398 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 6399 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 6400 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 6401 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 6402 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 6403 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 6404 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 6405 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 6406 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 6407 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 6408 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 6409 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 6410 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 6411 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 6412 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 6413 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 6414 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 6415 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 6416 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 6417 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 6418 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 6419 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 6420 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 6421 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 6422 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 6423 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 6424 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 6425 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 6426 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 6427 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 6428 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 6429 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 6430 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 6431 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 6432 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 6433 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 6434 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 6435 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 6436 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 6437 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 6438 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 6439 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 6440 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 6441 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 6442 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 6443 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 6444 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 6445 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 6446 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 6447 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 6448 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 6449 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 6450 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 6451 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 6452 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 6453 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 6454 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 6455 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 6456 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 6457 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 6458 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 6459 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 6460 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 6461 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 6462 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 6463 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 6464 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 6465 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 6466 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 6467 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 6468 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 6469 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 6470 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 6471 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 6472 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 6473 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 6474 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 6475 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 6476 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 6477 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 6478 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 6479 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6480 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6481 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6482 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6483 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6484 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6485 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6486 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6487 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6488 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6489 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6490 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6491 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6492 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6493 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6494 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6495 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6496 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6497 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6498 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6499 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6500 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6501 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6502 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6503 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6504 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6505 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6506 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6507 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6508 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6509 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6510 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6511 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6512 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6513 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6514 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6515 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6516 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6517 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6518 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6519 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6520 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6521 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6522 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6523 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6524 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6525 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6526 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6527 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6528 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6529 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6530 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6531 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6532 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6533 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6534 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6535 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6536 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6537 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 919:

/* Line 678 of lalr1.cc  */
#line 6538 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("local"))); }
    break;

  case 920:

/* Line 678 of lalr1.cc  */
#line 6539 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 921:

/* Line 678 of lalr1.cc  */
#line 6540 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 922:

/* Line 678 of lalr1.cc  */
#line 6541 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 923:

/* Line 678 of lalr1.cc  */
#line 6542 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 924:

/* Line 678 of lalr1.cc  */
#line 6543 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 925:

/* Line 678 of lalr1.cc  */
#line 6544 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 926:

/* Line 678 of lalr1.cc  */
#line 6545 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 927:

/* Line 678 of lalr1.cc  */
#line 6546 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 928:

/* Line 678 of lalr1.cc  */
#line 6547 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 929:

/* Line 678 of lalr1.cc  */
#line 6548 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 930:

/* Line 678 of lalr1.cc  */
#line 6549 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 931:

/* Line 678 of lalr1.cc  */
#line 6550 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 932:

/* Line 678 of lalr1.cc  */
#line 6551 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 933:

/* Line 678 of lalr1.cc  */
#line 6552 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 934:

/* Line 678 of lalr1.cc  */
#line 6553 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 935:

/* Line 678 of lalr1.cc  */
#line 6554 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 936:

/* Line 678 of lalr1.cc  */
#line 6555 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 937:

/* Line 678 of lalr1.cc  */
#line 6556 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 938:

/* Line 678 of lalr1.cc  */
#line 6557 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 939:

/* Line 678 of lalr1.cc  */
#line 6558 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 940:

/* Line 678 of lalr1.cc  */
#line 6559 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 941:

/* Line 678 of lalr1.cc  */
#line 6560 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 942:

/* Line 678 of lalr1.cc  */
#line 6561 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 943:

/* Line 678 of lalr1.cc  */
#line 6562 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 944:

/* Line 678 of lalr1.cc  */
#line 6563 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 945:

/* Line 678 of lalr1.cc  */
#line 6564 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 946:

/* Line 678 of lalr1.cc  */
#line 6565 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 947:

/* Line 678 of lalr1.cc  */
#line 6566 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 948:

/* Line 678 of lalr1.cc  */
#line 6567 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 949:

/* Line 678 of lalr1.cc  */
#line 6568 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 950:

/* Line 678 of lalr1.cc  */
#line 6569 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 951:

/* Line 678 of lalr1.cc  */
#line 6570 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 952:

/* Line 678 of lalr1.cc  */
#line 6571 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 953:

/* Line 678 of lalr1.cc  */
#line 6572 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 954:

/* Line 678 of lalr1.cc  */
#line 6573 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 955:

/* Line 678 of lalr1.cc  */
#line 6574 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 956:

/* Line 678 of lalr1.cc  */
#line 6575 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 957:

/* Line 678 of lalr1.cc  */
#line 6576 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 958:

/* Line 678 of lalr1.cc  */
#line 6577 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 959:

/* Line 678 of lalr1.cc  */
#line 6578 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 960:

/* Line 678 of lalr1.cc  */
#line 6579 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 961:

/* Line 678 of lalr1.cc  */
#line 6580 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 962:

/* Line 678 of lalr1.cc  */
#line 6581 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 963:

/* Line 678 of lalr1.cc  */
#line 6582 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 964:

/* Line 678 of lalr1.cc  */
#line 6583 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 965:

/* Line 678 of lalr1.cc  */
#line 6584 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 966:

/* Line 678 of lalr1.cc  */
#line 6585 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 967:

/* Line 678 of lalr1.cc  */
#line 6586 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 968:

/* Line 678 of lalr1.cc  */
#line 6587 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 969:

/* Line 678 of lalr1.cc  */
#line 6588 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 970:

/* Line 678 of lalr1.cc  */
#line 6589 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 971:

/* Line 678 of lalr1.cc  */
#line 6590 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 972:

/* Line 678 of lalr1.cc  */
#line 6596 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          // EQName's namespace URI value is whitespace normalized according to the rules for the xs:anyURI type
          std::string uri = "\"" + SYMTAB((yysemantic_stack_[(3) - (1)].sval)) + "\"";
          std::string eqname = SYMTAB(driver.symtab.put_uri(uri.c_str(), uri.size())) + ":" + SYMTAB((yysemantic_stack_[(3) - (3)].sval));
          (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT(eqname.c_str())), true);
        }
    break;

  case 973:

/* Line 678 of lalr1.cc  */
#line 6602 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 678 of lalr1.cc  */
#line 11696 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1389;
  const short int
  xquery_parser::yypact_[] =
  {
      2758, -1389, -1389, -1389,  4244,  4244,  4244, -1389, -1389,    -9,
     131,    64,   671,   155, -1389, -1389, -1389,   733, -1389, -1389,
   -1389,   210,   246,   767,   572,   303,   349,   618, -1389,   -41,
   -1389, -1389, -1389, -1389, -1389, -1389,   769, -1389,   356,   375,
   -1389, -1389, -1389, -1389,   444, -1389,   771, -1389,   556,   579,
   -1389,   242, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389,
   -1389, -1389, -1389, -1389, -1389,   543,   639, -1389, -1389, -1389,
   -1389,   586,  8699, -1389, -1389, -1389,   647, -1389, -1389, -1389,
     625, -1389,   657,   698, -1389, -1389, 12426, -1389, -1389, -1389,
   -1389, -1389, -1389, -1389, -1389,   738, -1389, -1389,   763,   783,
   -1389, -1389, -1389, -1389, -1389, -1389, -1389,  3056,  6026, 12426,
   -1389, -1389, -1389, -1389, -1389, -1389, -1389,   777, -1389, -1389,
     793,  9580, -1389,  9870,   797,   816, -1389, -1389, -1389,   837,
   -1389,  8402, -1389, -1389, -1389, -1389, -1389, -1389,   804, -1389,
   -1389, -1389, -1389, -1389, -1389, -1389, -1389,    76,   746, -1389,
   -1389, -1389, -1389, -1389, -1389, -1389, -1389,   614,   822,   636,
   -1389,   759,   576, -1389, -1389, -1389, -1389, -1389, -1389,   882,
   -1389,   113,   760,   761,   764, -1389, -1389,   847,   852, -1389,
   -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389,
   -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389,
   -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389,
   -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389,
   -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389,
   -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389,
   -1389, -1389,  4541,  1012, -1389,  4838, -1389, -1389,   154,    80,
   -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389,
   -1389, -1389, -1389, -1389,    82, -1389, -1389, -1389, -1389, -1389,
   -1389,   331, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389,
    4244, -1389, -1389, -1389, -1389,    20, -1389, -1389, -1389, -1389,
   -1389, -1389, -1389, -1389,   908, -1389,   826, -1389, -1389, -1389,
     455, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389,   851,
     927, -1389,   805,   772,   488,   514,   659,   366, -1389,   971,
     825,   926,   928,  7214, -1389, -1389, -1389,    16, -1389, -1389,
    8402, -1389,   611, -1389,   874,  8699, -1389,   874,  8699, -1389,
   -1389, -1389,   741, -1389, -1389, -1389, -1389, -1389, -1389, -1389,
   -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389,
   -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389,
   -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389,
   -1389, -1389, -1389, -1389, -1389,   911,   888,   878, -1389, -1389,
   -1389, -1389, -1389,   854, -1389,  4244,   855,   856,   297,   297,
    1004,   648,   670,   477, 12710, 12426,   470,   987, 12426,   889,
     924,   609,  9580,   720,   798, 12426, 12426,   745,   241,    31,
   -1389, -1389, -1389,  9580,  4244,   860,  4244,   120,  7511, 10438,
     770,   773, 12426,   925,    15,   897,  7511,  1052,   100,   149,
   12426,   938,   921,   957, -1389,  7511,  9288, 12426, 12426, 12426,
    4244,   883,  7511,  7511, 12426,  4244,   912,   918, -1389, -1389,
   -1389,  7511, 10722, -1389,   916, -1389,   919, -1389, -1389, -1389,
   -1389,   920, -1389,   922, -1389, -1389, -1389, -1389, -1389,   923,
   -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389,
   -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389,
   -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, 12426, -1389,
   -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389,
   -1389,   932, 12426, -1389, -1389, -1389,   893,  3353,   933,   934,
     936, 12426,  4244, -1389,   929,   205, -1389,   705,  1044,  7511,
   -1389, -1389,   106, -1389, -1389, -1389,  1069, -1389, -1389, -1389,
   -1389,  7511,   880, -1389,  1063,  7511,  7511,   909,  7511,  7511,
    7511,  7511,   865, 12426,   625,   388,   910,   913,  7511,  7511,
    3056,   853, -1389, -1389, -1389, -1389,   671,   618,    83,    95,
    1096,  5135,  5135,  5432,  5432,   625, -1389, -1389,   908,   625,
   -1389,  7511, -1389,   984,   572,   -41,   937,   939,   940,  4244,
    7511, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389,  7808,
    7808,  7808, -1389,  7808,  7808, -1389,  7808, -1389,  7808, -1389,
   -1389, -1389, -1389, -1389, -1389, -1389,  7808,  7808,  1032,  7808,
    7808,  7808,  7808,  7808,  7808,  7808,  7808,  7808,  7808,  7808,
     876,  1013,  1016,  1017, -1389, -1389, -1389,  6323, -1389, -1389,
    8402,  8402,  7511,   874, -1389, -1389,   874, -1389,  6620,   874,
    9580,   958,  6917, -1389, -1389, -1389, -1389,   228, -1389,   237,
   -1389, -1389, -1389, -1389, -1389,  1006,  1007,   303,  1084, -1389,
   -1389, 12710,   904,    61, 12426,   956,   960,   904,  1004,   990,
     986, -1389, -1389, -1389,    68,   877,   -19,   823, 12426,   982,
    7511,  1008, 12426, 12426, -1389,   993,   943,  4244, -1389,   944,
     919,   375, -1389,   942,   945,    37, -1389,   263,   291, -1389,
   -1389,  1023, -1389,    40, 12426,    24, 12426,  1036,   320, -1389,
    4244, -1389,   322, -1389,  9580,  1037,  1086,  9580,  1004,  1038,
      59, 12426,  7511,   -41,   229,   949, -1389,   950,   951,   952,
      39, -1389,    62,   959, -1389,   330,   333,   988, -1389,   961,
    4244,  4244,   302, -1389,   340,   359,    84,  7511,    46, -1389,
   -1389,  7511,  7511,  7511, -1389,  7511, -1389,  7511, 12426,  1044,
   -1389,   172,   370, -1389, -1389, -1389,   441, -1389,    21, -1389,
   -1389, -1389,   135,   159,  1045,   906,   930,    52, -1389,  1002,
   -1389,   625, -1389, -1389,   962,   360,  3650,   451,  8996,   853,
   -1389,   154,   717,  1111,  1111, -1389, -1389,    98, -1389, -1389,
     102, -1389,    38, -1389, -1389, -1389, -1389, -1389, -1389, -1389,
   12426,   977,  7511,  1030, -1389, -1389, -1389,   927, -1389, -1389,
   -1389, -1389, -1389,  7808, -1389, -1389, -1389,    51,   514,   514,
      14,   659,   659,   659,   659,   366,   366, -1389, -1389, 11858,
   11858, 12426, 12426, -1389,   510, -1389, -1389,   259, -1389, -1389,
   -1389,   376, -1389, -1389, -1389,   377,   297, -1389, -1389,   353,
     583,   635, -1389,   303, -1389, -1389, -1389, -1389, -1389, -1389,
   -1389, -1389, -1389, -1389,   904, -1389,  1018, 12142,  1009,  7511,
   -1389, -1389, -1389,  1054,  1004,  1004,   904, -1389,   749,  1004,
     656, 12426,   394,   561,  1122, -1389, -1389,   869,    58, -1389,
   -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389,
      68,   347,   652, -1389,   935,   198,  7511, -1389, 12426,    33,
     859,  1004, -1389, -1389, -1389, -1389,  1003, 12426, -1389, 12426,
   -1389,  1041,  1035, 11858,  1046,  7511,    -8,  1019,    41,    65,
     917, -1389, -1389,   663,    24,  1054, 11858,  1055,  1068,   991,
     975,  1042,  1004,  1021,  1047,  1079,  1004,  7511,   -50, -1389,
   -1389, -1389,  1024, -1389, -1389, -1389, -1389,  1064,  7511,  7511,
    1039, -1389,  1083,  1085,  4244, -1389,  1000,  1005,  1034, 12426,
   -1389, 12426, -1389,  7511,  1048,   998,  7511,   389,   391,   403,
    1154, -1389,   507, -1389,   110, -1389, -1389,  1162, -1389,   716,
    7511,  7511,  7511,   722,  7511,  7511,  7511,  7511,  7511,  7511,
    1076,  7511,  7511, -1389, -1389,  5729,  1040,  1049,  1050,  1056,
     826,   743,   953, -1389,   580, -1389,   103,   123,    38,  5432,
    5432,  5432,  1115, -1389,  7511,   786,  1090, -1389, 12426,  1094,
   -1389, -1389,  7511,    51,   528,    17, -1389,   946,   134,   954,
     947, -1389, -1389,   798, -1389,   941,   551,  1057,  1058, 12142,
    1059, -1389,   486, -1389, -1389, -1389, -1389, -1389, -1389, -1389,
   -1389, -1389,  1060, -1389, -1389, -1389,  7511, -1389, -1389, -1389,
   -1389, -1389, -1389, -1389, -1389, -1389,   673, -1389,  1171,   762,
   -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389,   931,
   -1389, -1389,  1179, -1389, -1389, -1389, -1389, -1389,   550,  1187,
   -1389,   715, -1389, -1389, -1389,   916,   246,   920,   356,   922,
     923,   822,   983,   486,   994,   995,  8105,   955,   948, -1389,
    1054,   347, -1389,   997,  1043,  4244,  1053,  1061,  1080,  1065,
    1066, 12426,   243, -1389, 12426, -1389,  7511,  1081,  7511,  1100,
    7511,    26,  1082,  7511,  1087, -1389,  1114,  1118,  7511, 12426,
     857,  1159, -1389, -1389, -1389, -1389, -1389, -1389, 11858, -1389,
    4244,  1004,  1131, -1389, -1389, -1389,  1004,  1131, -1389,  7511,
    1097,  4244, 12426, -1389, -1389,  7511,  7511,   548, -1389,    11,
     766, -1389, 11006,   774, -1389,   780, -1389,  1062, -1389, -1389,
    4244,  1070,  1071, -1389,  7511, -1389, -1389,  1074,  1083,  1143,
   -1389,  1119, -1389,   621, -1389, -1389,  1238, -1389, -1389,  4244,
   12426, -1389,   714, -1389, -1389, -1389,  1072,  1027,  1028, -1389,
   -1389, -1389,  1029,  1031, -1389, -1389, -1389, -1389, -1389,  1014,
   12426,  1088, -1389, -1389,  7511,  7511,  7511,  3947,  5729,  8996,
     953, -1389,  1137,  8996, -1389,  1111,   365, -1389, -1389, -1389,
    1090, -1389,  1004, -1389,   835, -1389,    72,  1150, -1389,  7511,
    1160,  1030,   513,  1078, -1389,    51,  1022, -1389, -1389,   -80,
   -1389,    55,    -7,  1025,    51,    55,  7808, -1389,   148, -1389,
   -1389, -1389, -1389, -1389, -1389,    51,  1120,  1001,   877,    -7,
   -1389, -1389,   996,  1189, -1389, -1389, -1389, 10154,  1089,  1092,
    1093, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389,
   -1389, -1389, -1389,  1242,   185,  1254,   185,  1015,  1180, -1389,
   -1389, -1389, -1389,  1121, 12426,  1067, -1389,   983,  8105, -1389,
    1104, -1389, -1389, -1389, -1389, -1389, -1389,  7511,  1142, -1389,
   -1389,  7511, -1389,   364, -1389,  7511,  1146,  7511, -1389,  7511,
   12426, 12426, -1389,   667, -1389,  7511, -1389,  1168,  1169,  1199,
    1004,  1131, -1389,  7511,  1113, -1389, -1389, -1389,  1112, -1389,
      29,  7511,  4244,  1116,    34, -1389, 12426,  1117, 11290,    22,
   -1389, 11574,  1124, -1389, -1389,  1123, -1389, -1389, -1389,  7511,
     794,  1154, 12426,   872, -1389,  1128,  1154, 12426, -1389, -1389,
    7511,  7511,  7511,  7511,  7511, -1389,  7511,   449,   463,   466,
     581, -1389, 12426, -1389, -1389, -1389, -1389,  1150, -1389, -1389,
   -1389,  1004, -1389, -1389, -1389, -1389, -1389,  1129,  7808, -1389,
   -1389, -1389, -1389, -1389,    66,  7808,  7808,    85, -1389,   954,
   -1389,   162, -1389,   947,    51,  1147, -1389, -1389,  1026, -1389,
   -1389, -1389, -1389,  1206,  1130, -1389,   468, -1389, -1389, -1389,
   -1389,   219,   219, -1389,   185, -1389, -1389,   495, -1389,  1273,
      -7,  1208,  1132,  8105,   -48,  1033, -1389,  1145, -1389, -1389,
    7511, -1389,  7511,  1174, -1389,  7511, -1389, -1389, -1389,  1261,
   -1389, -1389,  5729,  7511,  1004, -1389, -1389, -1389,  7511,  7511,
   -1389, -1389, -1389,  5729,  5729,  1223,  4244, 12426,  1139, 12426,
    7511, 12426,  1140,  5729, -1389,    30,    36,  1154, 12426, -1389,
    1127,  1154, -1389, -1389, -1389, -1389, -1389, -1389,  1133,  1083,
    1085,  7511,  1209, -1389,   498, -1389, -1389, -1389,   659,  7808,
    7808,    14,   540, -1389, -1389, -1389, -1389, -1389, -1389,  7511,
   -1389, 11858, -1389, 11858,  1234, -1389, -1389, -1389,  1300, -1389,
   -1389, -1389,  1073,  1226, -1389, -1389,  1227, -1389,   739, 12426,
    1217,  1125, 12426,  8105, -1389, -1389,  7511, -1389,  1218, -1389,
   -1389,  1131, -1389, -1389, 11858, -1389, -1389,  1244,  7511,  1151,
   -1389,  1245,  5729, -1389, 12426,   428,   351, -1389,  1148,  1154,
   -1389,  1152,  5729,   796,   517, 12426,  1224,  1056,    14,    14,
    7808,   520, -1389, -1389, 11858, -1389, -1389,  1208,  8105, -1389,
    1150,  1077, 12426,  1225,  1126,  1227, -1389, 12426,  1155, 11858,
    4244, 11858,  1161, -1389, -1389,  1252,   481, -1389, -1389, -1389,
   -1389,  1170,   568, -1389, -1389, -1389,  1156, -1389,  1233, -1389,
     500, 12426, -1389,    14, -1389, -1389, -1389, -1389, -1389,  7511,
    1091, 12426,  1236, -1389,  4244,  1172, -1389, -1389,  1175,  7511,
   -1389, -1389, -1389, -1389, -1389, -1389, -1389, 12426,  1237,  1210,
     508, -1389,  1075,  1095, 12426, -1389, -1389,  7511,  5729,  1176,
   12426, -1389,  1246,  1056,  1101,  7511,  1103,  5729,   509, 12426,
   -1389,  8105, -1389,  8105,  1247,  1210,  1182, -1389,  1173, 12426,
   -1389,  1056,  1098,  1183, -1389, 12426,  1210,  1149, -1389,  1249,
   12426,  1105,  8105, -1389
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       165,   449,   450,   451,   168,   168,   168,   774,   973,   116,
     118,   599,   865,   874,   815,   779,   777,   759,   866,   869,
     822,   783,   760,   761,   814,   875,   763,   872,   844,   824,
     799,   819,   820,   870,   867,   818,   765,   873,   766,   767,
     914,   927,   913,   816,   835,   829,   768,   817,   770,   769,
     915,   853,   821,   796,   937,   938,   939,   940,   941,   942,
     943,   944,   945,   946,   947,   961,   968,   843,   839,   830,
     810,   758,     0,   838,   846,   854,   962,   834,   471,   811,
     812,   868,   963,   969,   831,   848,     0,   477,   438,   473,
     841,   776,   832,   833,   861,   836,   852,   860,   967,   970,
     782,   823,   863,   472,   851,   856,   762,     0,     0,     0,
     386,   849,   859,   864,   862,   842,   828,   916,   826,   827,
     964,     0,   385,     0,   965,   971,   857,   813,   837,   966,
     416,     0,   448,   858,   840,   847,   855,   850,   917,   804,
     809,   808,   807,   806,   805,   771,   825,     0,   775,   871,
     797,   905,   904,   906,   781,   780,   800,   911,   764,   903,
     908,   909,   900,   803,   845,   902,   912,   910,   901,   801,
     907,   919,   922,   923,   920,   921,   918,   772,   924,   925,
     926,   891,   890,   877,   795,   788,   884,   880,   798,   794,
     892,   893,   784,   785,   778,   787,   889,   888,   885,   881,
     898,   899,   897,   887,   883,   876,   786,   896,   895,   790,
     792,   791,   882,   886,   878,   793,   879,   789,   894,   948,
     949,   950,   951,   952,   953,   929,   930,   928,   934,   935,
     936,   931,   932,   933,   802,   954,   955,   956,   957,   958,
     959,   960,   165,     0,     2,   165,     5,     7,    19,     0,
      24,    27,    32,    33,    34,    35,    36,    37,    38,    28,
      54,    55,    29,    30,     0,    72,    75,    76,    31,    77,
      78,     0,   114,    79,    80,    81,    82,    14,   162,   163,
     164,   171,   173,   468,   174,     0,   175,   176,   177,   178,
     179,   180,   181,   184,   169,   215,   222,   217,   244,   250,
       0,   242,   243,   224,   218,   183,   219,   182,   220,   223,
     341,   343,   345,   355,   359,   361,   364,   369,   372,   375,
     377,   379,   381,     0,   383,   389,   391,     0,   407,   390,
     412,   415,   417,   420,   422,     0,   427,   424,     0,   435,
     445,   447,   421,   452,   459,   469,   460,   461,   462,   465,
     466,   463,   464,   484,   486,   487,   488,   485,   533,   534,
     535,   536,   537,   538,   444,   573,   565,   572,   571,   570,
     567,   569,   566,   568,   470,   467,   600,   601,    39,   225,
     226,   228,   227,   229,   221,     0,   446,   757,   773,   865,
     874,   872,   775,     0,   166,   167,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     122,   124,   125,     0,     0,     0,   168,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   269,   270,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   440,   443,
     430,     0,     0,   754,   759,   783,   761,   814,   875,   763,
     824,   765,   835,   768,   770,   769,   853,   961,   968,   758,
     962,   812,   963,   969,   836,   967,   970,   916,   964,   965,
     971,   966,   917,   911,   903,   909,   900,   801,   919,   922,
     923,   920,   772,   924,   436,   446,   757,   428,     0,   191,
     429,   432,   759,   760,   761,   765,   766,   767,   768,   758,
     764,   474,     0,   434,   433,   186,     0,     0,   763,   770,
     769,     0,   168,   475,   924,     0,   222,     0,   500,     0,
     439,   755,     0,   756,   410,   411,     0,   442,   441,   431,
     414,     0,     0,   529,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     1,     6,     8,     0,     0,     0,     0,
       0,   165,   165,   165,   165,     0,   115,   172,   170,     0,
     189,     0,   200,     0,     0,     0,     0,     0,     0,     0,
       0,   205,   230,   249,   245,   251,   246,   248,   247,     0,
       0,     0,   400,     0,     0,   398,     0,   350,     0,   399,
     392,   397,   396,   395,   394,   393,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   388,   387,   384,     0,   408,   413,
       0,     0,     0,   423,   456,   426,   425,   437,     0,   453,
       0,     0,     0,   540,   542,   546,   599,     0,   120,     0,
      43,    40,    41,    44,    45,     0,     0,     0,     0,    46,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   610,   611,   612,     0,    99,   138,     0,     0,   108,
       0,     0,     0,     0,   123,     0,     0,     0,   579,     0,
       0,     0,   575,     0,     0,     0,   589,     0,     0,   232,
     233,   252,   253,     0,     0,     0,     0,   130,     0,   134,
     168,   603,     0,    56,     0,    65,     0,     0,     0,    57,
       0,     0,     0,     0,     0,   754,   580,     0,     0,     0,
       0,   314,     0,     0,   578,     0,     0,     0,   597,     0,
       0,     0,     0,   583,     0,     0,   195,     0,     0,   187,
     185,     0,     0,     0,   474,     0,   476,     0,   501,   500,
     497,     0,     0,   531,   530,   409,     0,   528,     0,   623,
     624,   574,     0,     0,     0,     0,     0,     0,   629,     0,
     192,     0,   203,   204,     0,     0,     0,     0,     0,   208,
     209,    20,     0,    21,     0,     4,    25,     0,    11,    26,
       0,    15,   865,    73,    12,    74,    16,   193,   190,   216,
       0,     0,     0,     0,   206,   231,   287,   342,   344,   348,
     354,   353,   352,     0,   349,   346,   347,     0,   363,   362,
     360,   366,   367,   368,   365,   370,   371,   374,   373,     0,
       0,     0,     0,   405,     0,   418,   419,     0,   457,   454,
     482,     0,   972,   602,   480,     0,     0,   117,   119,     0,
       0,     0,    98,     0,    88,    90,    91,    92,    93,    95,
      96,    97,    89,    94,    84,    85,     0,     0,   104,     0,
     100,   102,   103,   110,     0,     0,    83,    42,     0,     0,
       0,     0,     0,     0,     0,   704,   709,     0,     0,   705,
     739,   692,   694,   695,   696,   698,   700,   699,   697,   701,
       0,     0,     0,   139,     0,     0,     0,   107,     0,   142,
       0,     0,   545,   539,   576,   577,     0,     0,   593,     0,
     590,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   234,   235,     0,   240,   136,     0,     0,   131,     0,
       0,     0,     0,     0,     0,    58,     0,     0,     0,   268,
     274,   271,     0,   582,   581,   588,   596,     0,     0,     0,
       0,   544,     0,     0,     0,   401,     0,     0,     0,     0,
     586,     0,   584,     0,   196,     0,     0,     0,     0,     0,
     500,   498,     0,   489,     0,   478,   479,     0,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   194,   201,     0,   763,   770,   769,   924,
       0,     0,     0,   640,     0,   210,     0,     0,     0,   165,
     165,   165,     0,   241,     0,   298,   294,   296,     0,   288,
     289,   351,     0,     0,     0,     0,   670,   357,   643,   647,
     649,   651,   653,   656,   663,   664,   672,   875,   762,     0,
     771,   376,   551,   557,   558,   560,   604,   605,   561,   564,
     378,   380,   548,   382,   406,   458,     0,   455,   481,   121,
      52,    53,    50,    51,   127,   126,     0,    86,     0,     0,
     105,   106,   111,    70,    71,    48,    49,    69,   710,     0,
     713,   740,     0,   703,   702,   707,   706,   738,     0,     0,
     715,     0,   711,   714,   693,     0,     0,     0,     0,     0,
       0,     0,   140,   146,     0,     0,     0,     0,     0,   109,
     112,     0,   143,     0,     0,   168,     0,     0,   597,     0,
       0,     0,     0,   550,     0,   255,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   236,     0,     0,     0,     0,
     281,     0,   278,   283,   239,   137,   132,   135,     0,   188,
       0,     0,    67,    61,    64,    63,     0,    59,   272,     0,
       0,   168,     0,   312,   316,     0,     0,     0,   319,     0,
       0,   325,     0,     0,   332,     0,   336,     0,   403,   402,
     168,     0,     0,   197,     0,   199,   313,     0,     0,     0,
     501,     0,   490,     0,   524,   521,     0,   525,   526,     0,
       0,   520,     0,   495,   523,   522,     0,     0,     0,   616,
     617,   613,     0,     0,   621,   622,   618,   627,   625,     0,
       0,     0,   631,   202,     0,     0,     0,     0,     0,     0,
     632,   633,     0,     0,   211,    22,     0,    13,    17,    18,
     295,   307,     0,   308,     0,   299,   300,   301,   302,     0,
     291,     0,     0,     0,   654,   667,     0,   356,   358,     0,
     686,     0,     0,     0,     0,     0,     0,   642,   644,   645,
     681,   682,   683,   685,   684,     0,     0,   658,   657,     0,
     661,   665,   679,   677,   676,   669,   673,     0,     0,     0,
       0,   554,   556,   555,   552,   549,   483,   129,   128,    87,
     101,   727,   708,     0,   732,     0,   732,   721,   716,   141,
     147,   149,   148,     0,     0,     0,   113,   144,     0,    23,
       0,   594,   595,   598,   591,   592,   254,     0,     0,   267,
     259,     0,   263,     0,   257,     0,     0,     0,   276,     0,
       0,     0,   238,   279,   282,     0,   133,     0,     0,    66,
       0,    60,   273,     0,     0,   315,   317,   322,     0,   320,
       0,     0,     0,     0,     0,   326,     0,     0,     0,     0,
     333,     0,     0,   337,   404,     0,   587,   585,   198,     0,
       0,   500,     0,     0,   532,     0,   500,     0,   496,    10,
       0,     0,     0,     0,     0,   630,     0,     0,     0,     0,
       0,   634,     0,   641,   311,   309,   310,   303,   304,   305,
     297,     0,   292,   290,   671,   662,   668,     0,     0,   741,
     742,   752,   751,   750,     0,     0,     0,     0,   743,   648,
     749,     0,   646,   650,     0,     0,   655,   659,     0,   680,
     675,   678,   674,     0,     0,   562,     0,   559,   609,   553,
     728,     0,     0,   726,   733,   734,   730,     0,   725,     0,
     723,     0,     0,     0,     0,     0,   145,     0,   541,   256,
       0,   265,     0,     0,   261,     0,   264,   277,   285,   286,
     280,   237,     0,     0,     0,    62,   275,   547,     0,     0,
     323,   327,   321,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   543,     0,     0,   500,     0,   527,
       0,   500,   614,   615,   619,   620,   626,   628,     0,     0,
       0,     0,     0,   635,     0,   306,   293,   666,   753,     0,
       0,   745,     0,   691,   690,   689,   688,   687,   652,     0,
     744,     0,   606,     0,     0,   737,   736,   735,     0,   729,
     722,   720,     0,   717,   718,   712,   150,   152,   154,     0,
       0,     0,     0,     0,   260,   258,     0,   266,     0,   207,
     340,    68,   318,   324,     0,   338,   334,     0,     0,     0,
     328,     0,     0,   330,     0,   510,   504,   499,     0,   500,
     491,     0,     0,     0,     0,     0,     0,     0,   747,   746,
       0,     0,   607,   563,     0,   731,   724,     0,     0,   156,
     155,     0,     0,     0,     0,   151,   262,     0,     0,     0,
       0,     0,     0,   518,   512,     0,   511,   513,   519,   516,
     506,     0,   505,   507,   517,   493,     0,   492,     0,   639,
       0,     0,   212,   748,   660,   608,   719,   153,   157,     0,
       0,     0,     0,   284,     0,     0,   331,   329,     0,     0,
     503,   514,   515,   502,   508,   509,   494,     0,     0,     0,
       0,   158,     0,     0,     0,   339,   335,     0,     0,     0,
       0,   636,     0,     0,     0,     0,     0,     0,     0,     0,
     213,     0,   160,     0,     0,     0,     0,   159,     0,     0,
     637,     0,     0,     0,   214,     0,     0,     0,   638,     0,
       0,     0,     0,   161
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1389, -1389,  -208,  1134, -1389,  1136,  1163, -1389,  1144,  -519,
   -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389,
    -961, -1389, -1389, -1389, -1389,  -226,  -558, -1389,   683,   -67,
   -1389, -1389, -1389, -1389, -1389,   264,   474, -1389, -1389,    18,
    -240,   976, -1389,   965, -1389, -1389,  -606, -1389,   407, -1389,
     226,  -891, -1389,  -218,  -260, -1389,  -530, -1389,    13,    87,
      23,  -179,  -177, -1389,  -811, -1389, -1389,  -503, -1389, -1389,
   -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389,   584,   -99,
    1051,     0, -1389, -1389, -1389, -1389,   431, -1389, -1389,  -293,
   -1389,     8, -1389, -1389,   235,  -683,  -684, -1389, -1389,   658,
   -1389, -1389,    28,   220, -1389, -1389, -1389,   108, -1389, -1389,
     350,   124, -1389, -1389,   126, -1227, -1389,   894,   213, -1389,
   -1389,   211,  -948, -1389, -1389,   207, -1389, -1389, -1197, -1171,
   -1389,   204, -1389, -1389,   815,   817, -1389,  -516, -1389, -1389,
    -620,   337,  -597,   332,   336, -1389, -1389, -1389, -1389, -1389,
    1102, -1389, -1389, -1389, -1389,  -827,  -311, -1136, -1389,   -64,
   -1389, -1389, -1389, -1389, -1389, -1389, -1389,   -29,  -784, -1389,
   -1389,   592,   245, -1389,  -396, -1389, -1389, -1389, -1389, -1389,
   -1389, -1389,   768, -1389,  -969, -1389,   193, -1389,   650,  -756,
   -1389, -1389, -1389, -1389, -1389,  -241,  -234, -1134,  -861, -1389,
   -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389,   571,
    -719,  -791,   292,  -780, -1389,   109,  -810, -1389, -1389, -1389,
   -1389, -1389, -1389, -1389,  1010,  1011,  -192,   485,   334, -1389,
   -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389,
   -1389, -1389, -1389,   179, -1389, -1389,   170,  -983,   175, -1017,
   -1389, -1389, -1389,   137,   132,   -28,   384, -1389, -1389, -1389,
   -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389, -1389,
     141, -1389, -1389, -1389,   -21,   378,   522, -1389, -1389, -1389,
   -1389, -1389,   323, -1389, -1389, -1388, -1389, -1389, -1389,  -495,
   -1389,   111, -1389,   -39, -1389, -1389, -1389, -1389, -1196, -1389,
     151, -1389,  -366,  -357,   974,   118, -1389
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   243,   814,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
    1192,   738,   261,   262,   263,   264,   265,   266,   894,   895,
     896,   267,   268,   269,   900,   901,   902,   270,   418,   271,
     272,   667,   273,   420,   421,   422,   435,   728,   729,   274,
    1142,   933,   275,  1596,  1597,   276,   277,   278,   526,   279,
     280,   281,   282,   283,   731,   284,   285,   509,   286,   287,
     288,   289,   290,   291,   601,   292,   293,   809,   810,   294,
     295,   536,   297,   602,   433,   963,   964,   298,   603,   299,
     605,   537,   301,   721,   722,  1180,   442,   302,   443,   444,
     725,  1181,  1182,  1183,   606,   607,  1059,  1060,  1452,   608,
    1056,  1057,  1285,  1286,  1287,  1288,   303,   750,   751,   304,
    1207,  1208,  1400,   305,  1210,  1211,   306,   307,  1213,  1214,
    1215,  1216,   308,   309,   310,   311,   843,   312,  1297,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   626,   627,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   653,   654,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   871,   352,   353,   354,  1242,   779,   780,   781,
    1627,  1671,  1672,  1665,  1666,  1673,  1667,  1243,  1244,   355,
     356,  1245,   357,   358,   359,   360,   361,   362,   363,  1091,
     958,  1081,  1334,  1082,  1486,  1083,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   757,  1157,   374,   375,
     376,   377,  1085,  1086,  1087,  1088,   378,   379,   380,   381,
     382,   383,   797,   798,   384,  1270,  1271,  1563,  1044,  1067,
    1307,  1308,  1068,  1069,  1070,  1071,  1072,  1317,  1476,  1477,
    1073,  1320,  1074,  1457,  1075,  1076,  1325,  1326,  1482,  1480,
    1309,  1310,  1311,  1312,  1576,   695,   921,   922,   923,   924,
     925,   926,  1132,  1502,  1593,  1133,  1500,  1591,   927,  1346,
    1497,  1493,  1494,  1495,   928,   929,  1313,  1321,  1467,  1314,
    1463,  1298,   385,   542,   386,   387,   388
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int xquery_parser::yytable_ninf_ = -755;
  const short int
  xquery_parser::yytable_[] =
  {
       296,   571,   668,   668,   296,   296,   296,   604,   300,   535,
    1353,   850,   300,   300,   300,  1197,   648,   393,   396,   397,
    1065,   978,   579,  1012,  1043,   823,   825,   395,   395,   395,
     419,   586,  1420,   990,   670,   851,   852,   853,   854,   957,
     956,   582,  1410,   504,  1209,  1241,  1293,  1004,  1152,  1084,
    1084,   818,   821,   824,   826,   690,   584,     9,    10,  1448,
    1449,   800,   816,   819,     9,    10,   705,   550,  1599,  1090,
    1105,   881,   735,   739,   931,   440,   952,  1169,   404,   960,
     666,   580,   827,   580,   580,   404,   828,  1084,  1464,   747,
    1199,   394,   394,   394,   405,   839,   580,   840,   841,   580,
     842,   587,   844,   580,   580,   407,   552,   296,  1428,  1401,
     845,   846,   407,  1594,   783,   300,   408,  1109,  1569,  1234,
    1235,  1143,   910,  1478,   911,   589,  1151,  1401,  1625,   463,
     527,   726,  1401,   953,  1459,   954,   954,  1166,  1539,     9,
      10,   701,   591,  1084,   987,   398,  1624,   409,   410,  1052,
    1017,   987,   953,  1129,   897,   953,  1084,  1030,   953,    78,
     400,   401,  1163,   402,   403,   710,   912,   647,  1295,  1130,
     629,  1375,  1460,    89,  1600,  1186,  1282,   953,   463,   586,
     406,   588,   711,  -754,  1112,   955,  1170,   576,   630,   565,
     506,   123,   123,  1570,   394,  1402,   898,  1284,   103,   977,
     727,   899,  1062,   577,   506,  1063,  1540,   989,   590,  1018,
    1173,  1236,  1131,  1529,  1540,   932,   587,  1626,  1534,   946,
    1565,   441,  1507,   564,  1003,   988,   123,   506,  1019,  1299,
     441,  1237,  1006,  1238,  1276,  1391,  1065,  1065,   961,   506,
    1174,   506,   296,  1299,   604,   296,  1185,  1465,  1466,  1410,
     300,  1349,  1023,   300,  1231,   823,   825,  1601,   734,  1686,
     736,  1239,  1404,   441,  1241,   109,   649,   932,   581,  1084,
     583,   811,  1167,  1241,  1172,  1171,   962,  1106,  1456,   784,
     296,   412,   121,   813,  1031,   399,  1049,   553,   300,  1428,
    1051,  1275,   816,   819,  1200,  1338,   588,   441,  1033,  1329,
    1013,  1300,  1240,   872,  1592,   712,   655,   737,  1064,   657,
     591,   441,   441,   423,  1343,  1300,   702,   913,   629,  1491,
     147,  1461,   907,   415,   703,   586,   666,  1061,  1462,   715,
     914,   416,   915,   876,   591,   454,   630,   732,   954,   417,
     413,  1143,   876,   916,   917,   918,   744,   919,   587,   920,
    1020,  1021,  1573,   755,   756,   817,   820,     9,    10,  1574,
    1234,   426,   762,  1633,   591,  1022,  1014,  1598,   947,  1575,
     812,  1649,   975,  1345,  1024,  1025,   699,   971,  1084,  1669,
     974,   700,   414,  1492,  1301,  1302,  1135,  1303,  1367,  1026,
     776,  1136,   710,   455,  1304,   296,   949,  1386,  1301,  1302,
     427,  1303,  1084,   300,  1305,    78,  1137,   591,  1138,   711,
     685,   982,   686,   877,     9,    10,  1306,  1139,  1305,    89,
     834,  1407,   878,  1688,   296,   967,   296,   591,   588,  1573,
    1306,  1356,   300,  1663,   300,   591,  1574,  1234,   591,   709,
     782,   585,  1095,  1140,   103,   999,  1575,   707,   948,   395,
     296,  1066,   786,   506,  1241,   296,   506,   434,   300,   954,
     456,   457,  1410,   300,  1001,   591,  1506,  1598,  1065,   688,
     805,   807,  1237,   707,  1238,   591,   950,  1065,   707,  1368,
    1099,  1096,  1096,  1670,   998,  1043,  1663,  1376,  1065,  1443,
    1234,   823,   825,   823,   591,  1147,   591,   593,   801,  1100,
     638,   594,  1239,   436,  1148,   968,   595,   970,   591,  1512,
     447,   706,  1598,   394,   639,   992,  1101,  1084,   993,  1277,
    1278,  1279,   677,   506,   596,  1000,   506,   296,   587,   448,
     506,   689,   296,   506,   506,   300,  1485,   753,  1113,  1114,
     300,   506,   759,  1117,  1002,  1035,   591,   506,   864,  1237,
     506,  1238,  1015,   867,   591,   395,   591,   666,   506,  1664,
     449,  1097,  1098,  1611,   506,   506,   506,   506,   591,  1141,
     296,   591,   506,  1583,  1227,  1154,  1228,  1234,   300,  1239,
     506,   296,   296,   296,   296,  1046,   865,   866,  1229,   300,
     300,   300,   300,   806,   419,  1737,  1669,  1738,  1084,   296,
    1588,  1084,  1237,  1636,  1238,  1708,  1193,   300,   588,  1050,
    1193,  1404,  1701,  1722,  1734,   591,  1753,  1538,   591,   394,
    1542,   597,   591,  1016,   598,   591,   506,   587,  1331,   632,
    1234,  1235,  1239,  1042,  1558,  1232,    78,   679,   430,   599,
     506,   675,   437,   431,   629,  1343,  1206,  1065,  1559,   506,
      89,  1560,   438,  1584,   685,  1123,   686,   676,   633,  1398,
    1332,  1344,   630,   458,   600,  1546,  1124,  1066,  1066,   680,
    1550,   634,  1007,  1008,  1009,   103,   807,  1333,   439,  1062,
    1589,   506,  1063,  1637,   631,  1709,  1471,   687,   432,  1237,
    1513,  1238,  1094,  1723,  1735,  1454,   629,     9,    10,  1679,
    1704,  1233,  1684,   123,  1345,   635,   460,   296,   400,   401,
     452,   402,   403,   688,   630,   300,  1176,   823,   404,  1239,
    1176,  1177,  1236,  1234,  1235,  1177,  1721,   405,   406,  1102,
     296,  1267,  1561,   453,  1272,  1562,  1640,   461,   300,  1178,
     462,   508,  1237,   969,  1238,   407,  1103,   593,   604,   408,
    1047,   594,  1740,   395,   648,  1156,   595,  1159,   954,   459,
     296,   296,   954,  1748,  1668,  1674,   577,   507,   300,   300,
    1104,  1084,  1239,  1084,   596,   689,   109,   510,   506,  1179,
     409,   410,   411,   707,   707,   593,   730,  1273,  1273,   594,
    1642,  1628,  1643,   121,   595,  1631,  1322,  1323,   561,   883,
     650,   651,   506,   562,  1084,  1668,  1040,  1221,  1337,  1222,
    1129,  1674,   596,  1422,  1041,  1236,   506,   394,   511,  1324,
     506,   506,  1125,  1658,   730,  1389,  1130,  1107,   671,   412,
    1193,   147,   953,  1126,  1084,  1237,   555,  1238,   556,  1107,
     419,   672,   506,  1282,   506,  1571,  1572,   996,   997,  1084,
     673,  1084,   506,  1685,   522,   506,  1263,   636,   558,   506,
     559,  1568,   571,   674,  1206,  1239,   637,  1274,  1695,   109,
    1698,   597,  1408,  1676,   598,  1115,  1116,  1403,  1411,  1650,
    1281,  1234,  1235,   523,   424,  1409,   121,   425,   413,   777,
    1282,  1412,  1408,   652,  1408,   658,   506,   898,   868,  1066,
    1283,   868,   899,   524,   868,  1545,  1427,  1678,  1066,   597,
    1176,  1284,   598,   540,   600,  1177,  1444,   547,   428,  1066,
     445,   429,   450,   446,   147,   451,   506,  1268,   539,   656,
     414,  1118,  1119,  1120,   659,   611,   548,  1121,   691,   692,
     693,  1144,  1145,   612,   613,  1247,   614,  1248,   506,  1638,
    1639,  1252,   600,  1253,   615,   551,   415,   549,   616,   554,
     617,  1445,  1446,  1292,   416,   618,   848,   849,   855,   856,
    1092,  1092,   417,  1236,   857,   858,   557,   506,   506,   506,
     506,   560,   619,   884,   885,   886,   887,   888,   889,   890,
     891,   892,   893,  1237,   296,  1238,  1585,  1586,   563,   566,
     567,   569,   300,   570,   568,   620,   621,   622,   623,   624,
     625,  1387,   573,   591,   592,   506,   609,   707,   610,   628,
    1683,   640,   641,  1239,  1525,   642,   652,   109,   643,   506,
     660,   661,   662,   463,   681,  1040,   663,   664,   665,   683,
     684,   724,   694,  1041,   121,   708,   505,   698,   730,   296,
     296,   296,   719,   733,   741,   720,   506,   300,   300,   300,
     521,   742,   743,   760,  1548,   506,   419,   506,   754,   761,
     425,   506,   767,   429,   446,   769,   451,   462,  1066,   778,
     775,  1217,   147,   538,   506,  1566,   785,   771,   772,   834,
     773,   787,   788,   796,   791,   543,   808,   546,   802,   815,
     830,   803,   847,   831,   859,   873,   860,   832,   833,   861,
     862,   879,   880,   882,   904,   908,   909,   506,   905,   506,
     934,   930,   936,   941,   938,   942,   943,   944,   951,   966,
     945,   973,   972,   976,   983,   984,   985,   986,  1027,   994,
    1028,   991,  1032,   995,  1048,  1054,  1058,   953,  1108,   899,
    1034,  1127,  1029,  1128,  1155,   296,  1153,  1161,  1193,  1146,
    1162,  1188,  1164,   300,  1168,  1437,  1438,  1439,  1360,  1175,
    1190,   726,  1191,  1189,  1196,  1201,   506,  1195,   395,  1194,
    1202,  1206,  1218,  1212,  1205,  1220,  1225,  1219,  1224,  1230,
     296,  1246,  1260,   687,  1264,  1289,  1269,   506,   300,  1291,
     666,   296,  1335,  1265,  1266,  1316,  1319,  1267,  1342,   300,
    1315,  1327,  1328,  1330,  1394,  1341,  1347,   932,  1351,  1352,
     296,  1358,  1363,  1531,   395,  1373,  1371,  1377,   300,  1296,
    1380,  1359,  1379,  1415,  1381,  1385,  1390,  1393,  1361,   296,
    1354,  1408,   394,   395,  1414,  1424,  1362,   300,  1434,  1421,
    1364,  1365,  1355,  1442,  1282,  1416,  1417,  1430,  1431,  1432,
    1429,  1433,   707,  1455,  1451,  1474,  1481,  1040,  1040,  1419,
    1458,  1490,  1436,  1468,  1487,  1041,  1041,  1488,  1489,   506,
    1479,  1475,   506,  1496,  1499,  1501,  1508,  1510,   394,  1503,
     806,  1515,  1522,  1523,  1524,  1527,  1528,   506,  1579,  1581,
    1533,  1536,  1590,  1129,  1580,  1544,   506,   394,  1543,   505,
    1549,  1567,   505,  1603,  1608,  1582,  1614,  1595,  1602,  1606,
     506,  1630,  1505,  1618,  1622,  1635,  1425,  1644,  1632,  1645,
     506,  1647,  1648,  1652,  1657,  1660,  1646,  1659,  1661,  1694,
    1681,  1691,  1675,  1609,  1700,  1699,  1677,  1653,  1692,  1707,
    1706,  1703,  1714,  1720,  1613,  1531,  1717,  1615,   506,  1718,
    1727,  1561,  1729,  1739,  1623,  1750,  1724,  1741,  1746,  1742,
     906,  1749,  1110,  1340,  1187,   669,   572,  1357,   506,   678,
    1689,   574,   682,  1745,   704,  1655,   543,   506,  1687,   696,
     697,   506,   578,  1045,  1712,  1184,  1366,   543,  1725,  1453,
    1384,   981,   296,   718,  1280,  1731,   723,  1733,   575,  1752,
     300,  1520,  1447,  1450,   740,  1395,   768,  1405,  1399,  1413,
     543,   748,   749,   752,   837,   646,  1423,   838,   758,  1011,
     875,  1705,  1702,  1093,  1160,  1350,   765,   713,   714,  1435,
    1441,  1469,  1339,  1615,  1440,   506,  1578,  1473,  1294,  1472,
    1577,  1318,  1134,  1387,  1348,  1587,  1470,  1498,     0,     0,
    1682,     0,  1634,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   506,     0,     0,     0,     0,     0,     0,     0,
    1641,  1696,   766,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   752,     0,   506,   506,
       0,     0,     0,     0,     0,   774,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1715,     0,     0,     0,     0,
       0,     0,  1040,     0,   506,     0,   506,     0,     0,   506,
    1041,     0,     0,  1040,  1040,     0,   296,   799,     0,  1715,
     506,  1041,  1041,  1040,   300,   506,  1730,     0,  1696,     0,
       0,  1041,     0,     0,     0,     0,     0,     0,     0,     0,
     506,     0,     0,     0,  1744,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   789,   790,     0,   792,
     793,   794,   795,     0,     0,     0,     0,     0,     0,   804,
       0,     0,  1040,     0,     0,     0,     0,     0,     0,     0,
    1041,     0,  1040,     0,   543,     0,     0,     0,     0,     0,
    1041,     0,   829,     0,     0,     0,     0,     0,     0,     0,
     835,   836,     0,     0,     0,   506,     0,   506,   903,   506,
     296,     0,     0,     0,     0,     0,   506,     0,   300,     0,
       0,     0,   935,     0,     0,     0,   939,   940,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   296,     0,     0,     0,   959,   506,
     965,   506,   300,     0,     0,     0,     0,     0,   543,   870,
       0,   543,     0,   870,     0,   979,     0,   506,  1040,     0,
     506,     0,     0,     0,     0,     0,  1041,  1040,     0,     0,
       0,     0,   506,     0,     0,  1041,     0,     0,     0,     0,
       0,     0,   506,     0,     0,     0,     0,     0,     0,     0,
       0,   937,  1010,   506,     0,     0,     0,     0,     0,     0,
       0,     0,   506,     0,     0,     0,     0,     0,     0,     0,
     506,     0,     0,     0,     0,   506,     0,   506,     0,   506,
       0,     0,   505,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   980,     0,     0,     0,     0,     0,   506,
       0,     0,     0,     0,  1053,     0,     0,     0,     0,   506,
       0,     0,     0,     0,     0,     0,     0,     0,  1005,     0,
       0,     0,     0,     0,     0,   506,     0,     0,   835,     0,
       0,     0,   506,  1089,  1089,  1089,  1089,     0,   506,     0,
       0,     0,     0,     0,     0,     0,     0,   506,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   506,     0,     0,
       0,     0,     0,   506,     0,     0,     0,     0,   506,     0,
       0,  1089,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1055,     0,  1122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1150,     0,     0,     0,     0,     0,     0,     0,
       0,  1158,     0,  1158,     0,     0,     0,  1089,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1089,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1111,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   758,     0,   758,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1149,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1165,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1198,     0,
       0,     0,  1290,     0,     0,     0,     0,     0,     0,  1203,
    1204,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1089,  1223,     0,     0,  1226,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1249,  1250,  1251,     0,  1254,  1255,  1256,  1257,  1258,
    1259,     0,  1261,  1262,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1055,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   723,     0,     0,  1369,     0,
       0,     0,     0,     0,     0,     0,     0,  1336,     0,     0,
       0,     0,     0,  1383,     0,     0,     0,     0,     0,     0,
       0,     0,  1089,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   752,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1089,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1426,     0,     0,  1370,     0,  1372,
       0,  1374,     0,     0,  1378,     0,     0,     0,     0,  1382,
       0,     0,     0,     0,   799,     0,     0,     0,     0,     0,
       0,  1388,     0,   505,     0,     0,     0,   505,     0,     0,
    1392,     0,     0,     0,     0,     0,  1396,  1397,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1418,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1089,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1504,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1055,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1518,  1519,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1535,     0,  1089,     0,     0,  1089,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1547,     0,     0,     0,
       0,  1551,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1564,     0,  1509,     0,
       0,     0,  1511,     0,     0,     0,  1514,     0,  1516,     0,
    1517,     0,     0,     0,     0,     0,  1521,     0,     0,     0,
       0,     0,     0,     0,  1526,     0,     0,     0,     0,     0,
       0,     0,  1530,  1532,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1388,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1552,  1553,  1554,  1555,  1556,     0,  1557,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1617,     0,  1619,     0,  1621,     0,     0,     0,     0,
       0,     0,  1629,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1089,     0,  1089,     0,     0,
       0,  1604,     0,  1605,     0,     0,  1607,     0,     0,     0,
       0,     0,     0,  1651,  1610,     0,  1654,     0,     0,  1612,
    1532,     0,     0,     0,     0,     0,     0,  1616,  1089,     0,
       0,  1620,     0,     0,     0,     0,     0,     0,  1662,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1680,
       0,     0,     0,     0,     0,     0,     0,     0,  1089,     0,
       0,     0,     0,     0,     0,     0,  1690,     0,     0,     0,
       0,  1693,     0,  1089,     0,  1089,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1710,     0,  1656,     0,     0,
       0,     0,     0,     0,     0,  1713,     0,     0,     0,  1616,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1719,     0,     0,     0,     0,     0,     0,  1726,     0,
       0,     0,     0,     0,  1728,     0,     0,     0,     0,     0,
       0,     0,     0,  1736,     0,     0,     0,     0,     0,     0,
       0,  1697,     0,  1743,     0,     0,     0,     0,     0,  1747,
       0,     0,     0,     0,  1751,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1711,     0,     0,     0,     0,  1716,     0,     0,     0,     0,
    1697,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1716,     1,
       2,     0,     0,     0,     0,     0,  1732,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,    12,    13,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
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
       0,     0,   127,     0,   128,   129,     0,   130,   131,   132,
       0,   133,     0,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,     0,     0,   145,   146,   147,     0,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,     0,     0,     0,   389,
     390,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,   391,    28,    29,    30,    31,
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
     122,   123,     0,     0,   124,   125,   126,     0,   525,     0,
     127,     0,   128,   129,     0,   130,   131,   132,     0,   133,
       0,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,     0,     0,   145,   146,   147,     0,   392,   149,
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
      10,     0,    11,     0,     0,     0,   389,   390,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,   391,    28,    29,    30,    31,     0,    32,    33,
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
       0,   124,   125,   126,     0,   770,     0,   127,     0,   128,
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
       0,     0,     0,   389,   390,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,  1036,   391,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,  1037,  1038,    50,    51,    52,    53,    54,    55,
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
     126,     0,   770,     0,   127,     0,   128,   129,     0,   130,
     131,   132,     0,   133,     0,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,     0,     0,   145,   146,
     147,     0,   392,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,  1039,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,     0,    11,     0,     0,     0,
     389,   390,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,  1036,   391,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,  1037,
    1038,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
      76,    77,     0,     0,     0,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,     0,     0,     0,    89,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,   106,   107,     0,
       0,   108,   109,   110,   111,   112,     0,     0,     0,     0,
     113,   114,   115,   116,   117,   118,   119,   120,     0,   121,
       0,   122,   123,     0,     0,   124,   125,   126,     0,   525,
       0,   127,     0,   128,   129,     0,   130,   131,   132,     0,
     133,     0,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,     0,     0,   145,   146,   147,     0,   392,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,  1039,
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
      24,    25,    26,   391,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,    48,    49,    50,    51,
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
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,     0,
      11,     0,     0,     0,    12,    13,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,     0,    32,    33,    34,    35,
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
     125,   126,     0,     0,     0,   127,     0,   128,   129,     0,
     130,   131,   132,     0,   133,     0,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,     0,     0,   145,
     146,   147,     0,   148,   149,   150,   151,   152,   153,   154,
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
       0,    12,    13,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
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
       0,     0,   127,     0,   128,   129,     0,   130,   131,   132,
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
       8,     9,    10,     0,    11,     0,     0,     0,    12,   390,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,    48,    49,    50,
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
     123,     0,     0,   124,   125,   126,     0,     0,     0,   127,
       0,   128,   129,     0,   130,   131,   132,     0,   133,     0,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,     0,     0,   145,   146,   147,     0,   392,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,     0,     0,     0,   822,   390,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   391,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,    48,    49,    50,    51,    52,    53,
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
     124,   125,   126,     0,     0,     0,   127,     0,   128,   129,
       0,   130,   131,   132,     0,   133,     0,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,     0,     0,
     145,   146,   147,     0,   392,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,     0,    11,     0,
       0,     0,   389,   390,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,  1036,   391,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,  1037,  1038,    50,    51,    52,    53,    54,    55,    56,
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
     177,  1039,   179,   180,   181,   182,   183,   184,   185,   186,
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
     127,   533,   128,   129,     0,   130,   131,   132,     0,   133,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   528,   391,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,   529,   530,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
      72,    73,    74,    75,     0,     0,    76,    77,     0,     0,
       0,    78,    79,   481,    81,    82,    83,    84,    85,   531,
      87,    88,     0,     0,     0,    89,     0,    90,    91,    92,
      93,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,     0,     0,     0,     0,     0,     0,   100,   101,   102,
     103,   104,   105,   106,   532,     0,     0,   108,   109,   110,
     111,   112,     0,     0,     0,     0,   113,   114,   115,   116,
     117,   118,   119,   120,     0,   121,     0,   122,   123,     0,
       0,   124,   125,   126,     0,   863,     0,   127,     0,   128,
     129,     0,   130,   131,   132,     0,   133,     0,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,     0,
       0,   145,   146,   147,     0,   392,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   498,   499,
     500,   501,   175,   176,   502,   534,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     0,     0,     0,    11,
       0,     0,     0,   389,   390,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   528,   391,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,   529,   530,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,    72,    73,    74,
      75,     0,     0,    76,    77,     0,     0,     0,    78,    79,
     481,    81,    82,    83,    84,    85,   531,    87,    88,     0,
       0,     0,    89,     0,    90,    91,    92,    93,     0,    94,
       0,     0,     0,    95,    96,    97,    98,    99,     0,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
     106,   532,     0,     0,   108,   109,   110,   111,   112,     0,
       0,     0,     0,   113,   114,   115,   116,   117,   118,   119,
     120,     0,   121,     0,   122,   123,     0,     0,   124,   125,
     126,     0,     0,     0,   127,   869,   128,   129,     0,   130,
     131,   132,     0,   133,     0,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,     0,     0,   145,   146,
     147,     0,   392,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   498,   499,   500,   501,   175,
     176,   502,   534,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     0,     0,     0,    11,     0,     0,     0,
     389,   390,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   528,   391,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,   529,
     530,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
      76,    77,     0,     0,     0,    78,    79,   481,    81,    82,
      83,    84,    85,   531,    87,    88,     0,     0,     0,    89,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,   106,   532,     0,
       0,   108,   109,   110,   111,   112,     0,     0,     0,     0,
     113,   114,   115,   116,   117,   118,   119,   120,     0,   121,
       0,   122,   123,     0,     0,   124,   125,   126,     0,     0,
       0,   127,   874,   128,   129,     0,   130,   131,   132,     0,
     133,     0,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,     0,     0,   145,   146,   147,     0,   392,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   498,   499,   500,   501,   175,   176,   502,   534,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   389,   390,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     467,    25,   469,   391,    28,   470,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,   472,     0,    45,    46,    47,   474,   475,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,    72,    73,    74,    75,     0,     0,    76,    77,     0,
       0,     0,    78,    79,   481,    81,    82,    83,    84,    85,
     531,    87,    88,     0,     0,     0,    89,     0,    90,    91,
      92,    93,     0,    94,     0,     0,     0,   484,    96,    97,
      98,    99,     0,     0,     0,     0,     0,     0,   100,   101,
     102,   103,   104,   105,   106,   532,     0,     0,   108,   109,
     644,   111,   112,     0,     0,     0,     0,   113,   114,   115,
     116,   117,   118,   119,   120,     0,   121,     0,   645,   123,
       0,     0,   124,   125,   126,     0,     0,     0,   127,     0,
     128,   129,     0,   130,   131,   132,     0,   133,     0,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
       0,     0,   145,   146,   147,     0,   392,   149,   150,   151,
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
     125,   126,     0,     0,     0,   127,     0,   128,   129,     0,
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
      20,    21,    22,    23,   467,    25,   469,   391,    28,   470,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   472,     0,    45,    46,    47,
     474,   475,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,    72,    73,    74,    75,     0,
       0,    76,    77,     0,     0,     0,    78,    79,   481,    81,
      82,    83,    84,    85,   531,    87,    88,     0,     0,     0,
      89,     0,    90,    91,    92,    93,     0,    94,     0,     0,
       0,   484,    96,    97,    98,    99,     0,     0,     0,     0,
       0,     0,   100,   101,   102,   103,   104,   105,   106,   532,
       0,     0,   108,   109,   110,   111,   112,     0,     0,     0,
       0,   113,   114,   115,   116,   117,   118,   119,   120,     0,
     121,     0,   122,   123,     0,     0,   124,   125,   126,     0,
       0,     0,   127,     0,   128,   129,     0,   130,   131,   132,
       0,   133,     0,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,     0,     0,   145,   146,   147,     0,
     392,   149,   150,   151,   152,   153,   154,   155,   156,   493,
     158,   494,   160,   495,   496,   163,   164,   165,   166,   167,
     168,   497,   170,   498,   499,   500,   501,   175,   176,   502,
     503,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     0,     0,    11,     0,     0,     0,   389,   390,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   467,    25,   469,   391,    28,   470,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,   472,     0,    45,    46,    47,   474,   475,    50,
     476,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,    72,    73,    74,    75,     0,     0,    76,    77,
       0,     0,     0,    78,    79,   481,    81,    82,    83,    84,
      85,   531,    87,    88,     0,     0,     0,    89,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,   484,    96,
      97,    98,    99,     0,     0,     0,     0,     0,     0,   100,
     101,   102,   103,   104,   105,   106,   532,     0,     0,   108,
     109,     0,   111,   112,     0,     0,     0,     0,   113,   114,
     115,   116,   117,   118,   119,   120,     0,   121,     0,     0,
       0,     0,     0,   124,   125,   126,     0,     0,     0,   127,
       0,   128,   129,     0,   130,   131,   132,     0,   133,     0,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,     0,     0,   145,   146,   147,     0,   392,   149,   150,
     151,   152,   153,   154,   155,   156,   493,   158,   494,   160,
     495,   496,   163,   164,   165,   166,   167,   168,   497,   170,
     498,   499,   500,   501,   175,   176,   502,   503,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   389,   390,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   467,    25,
     469,   391,    28,   470,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,   472,
       0,    45,    46,    47,   474,   475,    50,   476,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,    72,
      73,    74,    75,     0,     0,    76,    77,     0,     0,     0,
      78,    79,   481,    81,    82,    83,    84,    85,   531,    87,
      88,     0,     0,     0,    89,     0,    90,    91,    92,    93,
       0,    94,     0,     0,     0,   484,    96,    97,    98,    99,
       0,     0,     0,     0,     0,     0,   100,   101,   102,   103,
     104,   105,   106,   532,     0,     0,   108,   109,     0,   111,
     112,     0,     0,     0,     0,   113,   114,   115,   116,   117,
     118,   119,   120,     0,   121,     0,     0,     0,     0,     0,
     124,   125,   126,     0,     0,     0,   127,     0,   128,   129,
       0,     0,     0,   132,     0,   133,     0,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,     0,     0,
     145,   146,   147,     0,   392,   149,   150,   151,   152,   153,
     154,   155,   156,   493,   158,   494,   160,   495,   496,   163,
     164,   165,   166,   167,   168,   497,   170,   498,   499,   500,
     501,   175,   176,   502,   503,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       0,     0,     0,     7,     8,     0,     0,     0,   463,     0,
       0,     0,   389,   390,     0,    14,    15,    16,   464,    18,
      19,    20,   465,    22,   466,   467,   468,   469,   391,    28,
     470,    30,    31,     0,    32,    33,    34,    35,   471,    37,
      38,    39,    40,    41,    42,    43,   472,     0,    45,   473,
      47,   474,   475,    50,   476,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,   477,   478,
      67,     0,    68,    69,    70,   479,     0,    73,    74,    75,
       0,     0,   480,    77,     0,     0,     0,     0,    79,   481,
      81,   482,   483,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,    93,     0,    94,     0,
       0,     0,   484,    96,    97,   485,   486,     0,     0,     0,
       0,     0,     0,   100,   101,   102,     0,   104,   105,   106,
       0,     0,     0,     0,     0,     0,   111,   112,     0,     0,
       0,     0,   113,   114,   115,   116,   487,   118,   119,   488,
       0,     0,     0,     0,     0,     0,     0,   489,   490,   126,
       0,     0,     0,   127,     0,   128,   491,     0,     0,     0,
     132,     0,   133,     0,   134,   135,   136,   137,   492,   139,
     140,   141,   142,   143,   144,     0,     0,   145,   146,     0,
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
       0,     0,     0,     0,     0,     0,     3,     0,     0,     0,
       7,     8,     0,     0,     0,   463,     0,     0,     0,   389,
     390,     0,    14,    15,    16,   512,    18,    19,    20,   465,
     513,   514,   467,   468,   469,   391,    28,   470,    30,    31,
       0,    32,    33,    34,    35,   515,    37,   516,   517,    40,
      41,    42,    43,   472,     0,    45,   518,    47,   474,   475,
      50,   476,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,   477,   478,    67,     0,    68,
      69,    70,   519,     0,    73,    74,    75,     0,     0,   480,
      77,     0,     0,     0,     0,    79,   481,    81,   482,   483,
      84,    85,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    92,    93,     0,    94,     0,     0,     0,   484,
      96,    97,   485,   486,     0,     0,     0,     0,     0,     0,
     100,   101,   102,     0,   104,   105,   106,     0,     0,     0,
       0,     0,     0,   111,   112,     0,     0,     0,     0,   113,
     114,   115,   116,   487,   118,   119,   488,     0,     0,     0,
       0,     0,     0,     0,   489,   490,   126,     0,     0,     0,
     127,     0,   128,   491,     0,     0,     0,   132,     0,   133,
       0,   134,   135,   136,   137,   492,   139,   140,   141,   142,
     143,   144,     0,     0,   145,   146,     0,     0,   392,   149,
     150,   151,   152,   153,   154,   155,   156,   493,   520,   494,
     160,   495,   496,   163,   164,   165,   166,   167,   168,   497,
     170,   498,   499,   500,   501,   175,   176,   502,   503,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   541,     0,     0,     0,     0,     0,
       0,     0,     7,     8,     0,     0,     0,   745,     0,     0,
       0,   389,   390,     0,    14,    15,    16,   512,    18,    19,
      20,   465,   513,   514,   467,   468,   469,   391,    28,   470,
      30,    31,     0,    32,    33,    34,    35,   515,    37,   516,
     517,    40,    41,    42,    43,   472,     0,    45,   518,    47,
     474,   475,    50,   476,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,   477,   478,    67,
       0,    68,    69,    70,   519,     0,    73,    74,    75,     0,
       0,   480,    77,     0,     0,     0,     0,    79,   481,    81,
     482,   483,    84,    85,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92,    93,     0,    94,     0,     0,
       0,   484,    96,    97,   485,   486,     0,     0,     0,     0,
       0,     0,   100,   101,   102,     0,   104,   105,   106,     0,
       0,     0,     0,     0,     0,   111,   112,     0,     0,     0,
       0,   113,   114,   115,   116,   487,   118,   119,   488,     0,
       0,     0,     0,     0,     0,     0,   489,   490,   126,     0,
       0,     0,   127,   746,   128,   491,     0,     0,     0,     0,
       0,   133,     0,   134,   135,   136,   137,   492,   139,   140,
     141,   142,   143,   144,     0,     0,   145,   146,     0,     0,
     392,   149,   150,   151,   152,   153,   154,   155,   156,   493,
     520,   494,   160,   495,   496,   163,   164,   165,   166,   167,
     168,   497,   170,   498,   499,   500,   501,   175,   176,   502,
     503,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   541,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     0,     0,   463,
       0,     0,     0,   389,   390,     0,    14,    15,    16,   512,
      18,    19,    20,   465,   513,   514,   467,   468,   469,   391,
      28,   470,    30,    31,     0,    32,    33,    34,    35,   515,
      37,   516,   517,    40,    41,    42,    43,   472,     0,    45,
     518,    47,   474,   475,    50,   476,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,   477,
     478,    67,     0,    68,    69,    70,   519,     0,    73,    74,
      75,     0,     0,   480,    77,     0,     0,     0,     0,    79,
     481,    81,   482,   483,    84,    85,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,    93,     0,    94,
       0,     0,     0,   484,    96,    97,   485,   486,     0,     0,
       0,     0,     0,     0,   100,   101,   102,     0,   104,   105,
     106,     0,     0,     0,     0,     0,     0,   111,   112,     0,
       0,     0,     0,   113,   114,   115,   116,   487,   118,   119,
     488,     0,     0,     0,     0,     0,     0,     0,   489,   490,
     126,     0,     0,     0,   127,     0,   128,   491,     0,     0,
       0,     0,     0,   133,     0,   134,   135,   136,   137,   492,
     139,   140,   141,   142,   143,   144,     0,     0,   145,   146,
       0,     0,   392,   149,   150,   151,   152,   153,   154,   155,
     156,   493,   520,   494,   160,   495,   496,   163,   164,   165,
     166,   167,   168,   497,   170,   498,   499,   500,   501,   175,
     176,   502,   503,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   544,   545,
       0,     0,     0,     0,     7,     8,     0,     0,     0,   463,
       0,     0,     0,   389,   390,     0,    14,    15,    16,   512,
      18,    19,    20,   465,   513,   514,   467,   468,   469,   391,
      28,   470,    30,    31,     0,    32,    33,    34,    35,   515,
      37,   516,   517,    40,    41,    42,    43,   472,     0,    45,
     518,    47,   474,   475,    50,   476,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,   477,
     478,    67,     0,    68,    69,    70,   519,     0,    73,    74,
      75,     0,     0,   480,    77,     0,     0,     0,     0,    79,
     481,    81,   482,   483,    84,    85,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,    93,     0,    94,
       0,     0,     0,   484,    96,    97,   485,   486,     0,     0,
       0,     0,     0,     0,   100,   101,   102,     0,   104,   105,
     106,     0,     0,     0,     0,     0,     0,   111,   112,     0,
       0,     0,     0,   113,   114,   115,   116,   487,   118,   119,
     488,     0,     0,     0,     0,     0,     0,     0,   489,   490,
     126,     0,     0,     0,   127,     0,   128,   491,     0,     0,
       0,     0,     0,   133,     0,   134,   135,   136,   137,   492,
     139,   140,   141,   142,   143,   144,     0,     0,   145,   146,
       0,     0,   392,   149,   150,   151,   152,   153,   154,   155,
     156,   493,   520,   494,   160,   495,   496,   163,   164,   165,
     166,   167,   168,   497,   170,   498,   499,   500,   501,   175,
     176,   502,   503,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     7,     8,
       0,     0,     0,   463,     0,     0,     0,   389,   390,     0,
      14,    15,    16,   464,    18,    19,    20,   465,    22,   466,
     467,  1077,   469,   391,    28,   470,    30,    31,     0,    32,
      33,    34,    35,   471,    37,    38,    39,    40,    41,    42,
      43,   472,     0,    45,   473,    47,   474,   475,    50,   476,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,   477,   478,    67,     0,    68,    69,    70,
     479,     0,    73,    74,    75,     0,     0,   480,    77,     0,
       0,     0,     0,    79,   481,    81,   482,   483,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      92,    93,     0,    94,     0,     0,     0,   484,    96,    97,
     485,   486,     0,     0,     0,     0,     0,     0,   100,   101,
     102,     0,   104,   105,  1078,     0,     0,     0,  1079,     0,
       0,   111,   112,     0,     0,     0,     0,   113,   114,   115,
     116,   487,   118,   119,   488,     0,     0,     0,     0,     0,
       0,     0,   489,   490,   126,     0,     0,     0,   127,  1483,
     128,   491,     0,     0,     0,  1484,     0,   133,     0,   134,
     135,   136,   137,   492,   139,   140,   141,   142,   143,   144,
       0,     0,  1080,   146,     0,     0,   392,   149,   150,   151,
     152,   153,   154,   155,   156,   493,   158,   494,   160,   495,
     496,   163,   164,   165,   166,   167,   168,   497,   170,   498,
     499,   500,   501,   175,   176,   502,   503,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     7,     8,     0,     0,     0,   463,     0,     0,
       0,   389,   390,     0,    14,    15,    16,   512,    18,    19,
      20,   465,   513,   514,   467,   468,   469,   391,    28,   470,
      30,    31,     0,    32,    33,    34,    35,   515,    37,   516,
     517,    40,    41,    42,    43,   472,     0,    45,   518,    47,
     474,   475,    50,   476,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,   477,   478,    67,
       0,    68,    69,    70,   519,     0,    73,    74,    75,     0,
       0,   480,    77,     0,     0,     0,     0,    79,   481,    81,
     482,   483,    84,    85,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92,    93,     0,    94,     0,     0,
       0,   484,    96,    97,   485,   486,     0,     0,     0,     0,
       0,     0,   100,   101,   102,     0,   104,   105,   106,     0,
       0,     0,     0,     0,     0,   111,   112,     0,     0,     0,
       0,   113,   114,   115,   116,   487,   118,   119,   488,     0,
       0,     0,     0,     0,     0,     0,   489,   490,   126,     0,
       0,     0,   127,   716,   128,   491,     0,     0,     0,   717,
       0,   133,     0,   134,   135,   136,   137,   492,   139,   140,
     141,   142,   143,   144,     0,     0,   145,   146,     0,     0,
     392,   149,   150,   151,   152,   153,   154,   155,   156,   493,
     520,   494,   160,   495,   496,   163,   164,   165,   166,   167,
     168,   497,   170,   498,   499,   500,   501,   175,   176,   502,
     503,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     7,     8,     0,     0,
       0,   463,     0,     0,     0,   389,   390,     0,    14,    15,
      16,   512,    18,    19,    20,   465,   513,   514,   467,   468,
     469,   391,    28,   470,    30,    31,     0,    32,    33,    34,
      35,   515,    37,   516,   517,    40,    41,    42,    43,   472,
       0,    45,   518,    47,   474,   475,    50,   476,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   477,   478,    67,     0,    68,    69,    70,   519,     0,
      73,    74,    75,     0,     0,   480,    77,     0,     0,     0,
       0,    79,   481,    81,   482,   483,    84,    85,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,    93,
       0,    94,     0,     0,     0,   484,    96,    97,   485,   486,
       0,     0,     0,     0,     0,     0,   100,   101,   102,     0,
     104,   105,   106,     0,     0,     0,     0,     0,     0,   111,
     112,     0,     0,     0,     0,   113,   114,   115,   116,   487,
     118,   119,   488,     0,     0,     0,     0,     0,     0,     0,
     489,   490,   126,     0,     0,     0,   127,   763,   128,   491,
       0,     0,     0,   764,     0,   133,     0,   134,   135,   136,
     137,   492,   139,   140,   141,   142,   143,   144,     0,     0,
     145,   146,     0,     0,   392,   149,   150,   151,   152,   153,
     154,   155,   156,   493,   520,   494,   160,   495,   496,   163,
     164,   165,   166,   167,   168,   497,   170,   498,   499,   500,
     501,   175,   176,   502,   503,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       7,     8,     0,     0,     0,   463,     0,     0,     0,   389,
     390,     0,    14,    15,    16,   464,    18,    19,    20,   465,
      22,   466,   467,  1077,   469,   391,    28,   470,    30,    31,
       0,    32,    33,    34,    35,   471,    37,    38,    39,    40,
      41,    42,    43,   472,     0,    45,   473,    47,   474,   475,
      50,   476,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,   477,   478,    67,     0,    68,
      69,    70,   479,     0,    73,    74,    75,     0,     0,   480,
      77,     0,     0,     0,     0,    79,   481,    81,   482,   483,
      84,    85,  1406,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    92,    93,     0,    94,     0,     0,     0,   484,
      96,    97,   485,   486,     0,     0,     0,     0,     0,     0,
     100,   101,   102,     0,   104,   105,  1078,     0,     0,     0,
    1079,     0,     0,   111,   112,     0,     0,     0,     0,   113,
     114,   115,   116,   487,   118,   119,   488,     0,     0,     0,
       0,     0,     0,     0,   489,   490,   126,     0,     0,     0,
     127,     0,   128,   491,     0,     0,     0,     0,     0,   133,
       0,   134,   135,   136,   137,   492,   139,   140,   141,   142,
     143,   144,     0,     0,  1080,   146,     0,     0,   392,   149,
     150,   151,   152,   153,   154,   155,   156,   493,   158,   494,
     160,   495,   496,   163,   164,   165,   166,   167,   168,   497,
     170,   498,   499,   500,   501,   175,   176,   502,   503,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,     7,     8,     0,     0,     0,   463,
       0,     0,     0,   389,   390,     0,    14,    15,    16,   464,
      18,    19,    20,   465,    22,   466,   467,  1077,   469,   391,
      28,   470,    30,    31,     0,    32,    33,    34,    35,   471,
      37,    38,    39,    40,    41,    42,    43,   472,     0,    45,
     473,    47,   474,   475,    50,   476,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,   477,
     478,    67,     0,    68,    69,    70,   479,     0,    73,    74,
      75,     0,     0,   480,    77,     0,     0,     0,     0,    79,
     481,    81,   482,   483,    84,    85,  1537,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,    93,     0,    94,
       0,     0,     0,   484,    96,    97,   485,   486,     0,     0,
       0,     0,     0,     0,   100,   101,   102,     0,   104,   105,
    1078,     0,     0,     0,  1079,     0,     0,   111,   112,     0,
       0,     0,     0,   113,   114,   115,   116,   487,   118,   119,
     488,     0,     0,     0,     0,     0,     0,     0,   489,   490,
     126,     0,     0,     0,   127,     0,   128,   491,     0,     0,
       0,     0,     0,   133,     0,   134,   135,   136,   137,   492,
     139,   140,   141,   142,   143,   144,     0,     0,  1080,   146,
       0,     0,   392,   149,   150,   151,   152,   153,   154,   155,
     156,   493,   158,   494,   160,   495,   496,   163,   164,   165,
     166,   167,   168,   497,   170,   498,   499,   500,   501,   175,
     176,   502,   503,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     7,     8,
       0,     0,     0,   463,     0,     0,     0,   389,   390,     0,
      14,    15,    16,   464,    18,    19,    20,   465,    22,   466,
     467,  1077,   469,   391,    28,   470,    30,    31,     0,    32,
      33,    34,    35,   471,    37,    38,    39,    40,    41,    42,
      43,   472,     0,    45,   473,    47,   474,   475,    50,   476,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,   477,   478,    67,     0,    68,    69,    70,
     479,     0,    73,    74,    75,     0,     0,   480,    77,     0,
       0,     0,     0,    79,   481,    81,   482,   483,    84,    85,
    1541,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      92,    93,     0,    94,     0,     0,     0,   484,    96,    97,
     485,   486,     0,     0,     0,     0,     0,     0,   100,   101,
     102,     0,   104,   105,  1078,     0,     0,     0,  1079,     0,
       0,   111,   112,     0,     0,     0,     0,   113,   114,   115,
     116,   487,   118,   119,   488,     0,     0,     0,     0,     0,
       0,     0,   489,   490,   126,     0,     0,     0,   127,     0,
     128,   491,     0,     0,     0,     0,     0,   133,     0,   134,
     135,   136,   137,   492,   139,   140,   141,   142,   143,   144,
       0,     0,  1080,   146,     0,     0,   392,   149,   150,   151,
     152,   153,   154,   155,   156,   493,   158,   494,   160,   495,
     496,   163,   164,   165,   166,   167,   168,   497,   170,   498,
     499,   500,   501,   175,   176,   502,   503,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     7,     8,     0,     0,     0,   463,     0,     0,
       0,   389,   390,     0,    14,    15,    16,   464,    18,    19,
      20,   465,    22,   466,   467,  1077,   469,   391,    28,   470,
      30,    31,     0,    32,    33,    34,    35,   471,    37,    38,
      39,    40,    41,    42,    43,   472,     0,    45,   473,    47,
     474,   475,    50,   476,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,   477,   478,    67,
       0,    68,    69,    70,   479,     0,    73,    74,    75,     0,
       0,   480,    77,     0,     0,     0,     0,    79,   481,    81,
     482,   483,    84,    85,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92,    93,     0,    94,     0,     0,
       0,   484,    96,    97,   485,   486,     0,     0,     0,     0,
       0,     0,   100,   101,   102,     0,   104,   105,  1078,     0,
       0,     0,  1079,     0,     0,   111,   112,     0,     0,     0,
       0,   113,   114,   115,   116,   487,   118,   119,   488,     0,
       0,     0,     0,     0,     0,     0,   489,   490,   126,     0,
       0,     0,   127,     0,   128,   491,     0,     0,     0,     0,
       0,   133,     0,   134,   135,   136,   137,   492,   139,   140,
     141,   142,   143,   144,     0,     0,  1080,   146,     0,     0,
     392,   149,   150,   151,   152,   153,   154,   155,   156,   493,
     158,   494,   160,   495,   496,   163,   164,   165,   166,   167,
     168,   497,   170,   498,   499,   500,   501,   175,   176,   502,
     503,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     7,     8,     0,     0,
       0,   463,     0,     0,     0,   389,   390,     0,    14,    15,
      16,   464,    18,    19,    20,   465,    22,   466,   467,  1077,
     469,   391,    28,   470,    30,    31,     0,    32,    33,    34,
      35,   471,    37,    38,    39,    40,    41,    42,    43,   472,
       0,    45,   473,    47,   474,   475,    50,   476,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   477,   478,    67,     0,    68,    69,    70,   479,     0,
      73,    74,    75,     0,     0,   480,    77,     0,     0,     0,
       0,    79,   481,    81,   482,   483,    84,    85,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,    93,
       0,    94,     0,     0,     0,   484,    96,    97,   485,   486,
       0,     0,     0,     0,     0,     0,   100,   101,   102,     0,
     104,   105,  1078,     0,     0,     0,  1079,     0,     0,   111,
     112,     0,     0,     0,     0,   113,   114,   115,   116,   487,
     118,   119,   488,     0,     0,     0,     0,     0,     0,     0,
     489,   490,   126,     0,     0,     0,   127,     0,   128,   491,
       0,     0,     0,     0,     0,   133,     0,   134,   135,   136,
     137,   492,   139,   140,   141,   142,   143,   144,     0,     0,
     145,   146,     0,     0,   392,   149,   150,   151,   152,   153,
     154,   155,   156,   493,   158,   494,   160,   495,   496,   163,
     164,   165,   166,   167,   168,   497,   170,   498,   499,   500,
     501,   175,   176,   502,   503,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       7,     8,     0,     0,     0,   463,     0,     0,     0,   389,
     390,     0,    14,    15,    16,   512,    18,    19,    20,   465,
     513,   514,   467,   468,   469,   391,    28,   470,    30,    31,
       0,    32,    33,    34,    35,   515,    37,   516,   517,    40,
      41,    42,    43,   472,     0,    45,   518,    47,   474,   475,
      50,   476,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,   477,   478,    67,     0,    68,
      69,    70,   519,     0,    73,    74,    75,     0,     0,   480,
      77,     0,     0,     0,     0,    79,   481,    81,   482,   483,
      84,    85,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    92,    93,     0,    94,     0,     0,     0,   484,
      96,    97,   485,   486,     0,     0,     0,     0,     0,     0,
     100,   101,   102,     0,   104,   105,   106,     0,     0,     0,
       0,     0,     0,   111,   112,     0,     0,     0,     0,   113,
     114,   115,   116,   487,   118,   119,   488,     0,     0,     0,
       0,     0,     0,     0,   489,   490,   126,     0,     0,     0,
     127,     0,   128,   491,     0,     0,     0,     0,     0,   133,
       0,   134,   135,   136,   137,   492,   139,   140,   141,   142,
     143,   144,     0,     0,   145,   146,     0,     0,   392,   149,
     150,   151,   152,   153,   154,   155,   156,   493,   520,   494,
     160,   495,   496,   163,   164,   165,   166,   167,   168,   497,
     170,   498,   499,   500,   501,   175,   176,   502,   503,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,     7,     8,     0,     0,     0,   463,
       0,     0,     0,   389,   390,     0,    14,    15,    16,     0,
      18,    19,    20,   465,     0,     0,   467,   468,     0,   391,
      28,   470,    30,    31,     0,    32,    33,    34,    35,     0,
      37,     0,     0,    40,    41,    42,    43,   472,     0,    45,
       0,    47,     0,     0,    50,   476,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,   477,
     478,    67,     0,    68,    69,    70,     0,     0,    73,    74,
      75,     0,     0,   480,    77,     0,     0,     0,     0,    79,
     481,    81,   482,   483,    84,    85,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,    93,     0,    94,
       0,     0,     0,   484,    96,    97,   485,   486,     0,     0,
       0,     0,     0,     0,   100,   101,   102,     0,   104,   105,
       0,     0,     0,     0,     0,     0,     0,   111,   112,     0,
       0,     0,     0,   113,   114,   115,   116,   487,   118,   119,
     488,     0,     0,     0,     0,     0,     0,     0,   489,   490,
     126,     0,     0,     0,   127,     0,   128,   491,     0,     0,
       0,     0,     0,   133,     0,   134,   135,   136,   137,   492,
     139,   140,   141,   142,   143,   144,     0,     0,     0,   146,
       0,     0,   392,   149,   150,   151,   152,   153,   154,   155,
     156,   493,     0,   494,   160,   495,   496,   163,   164,   165,
     166,   167,   168,   497,   170,   498,   499,   500,   501,   175,
     176,     0,   503,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   178,   398,   399,     4,     5,     6,   300,     0,   108,
    1146,   631,     4,     5,     6,   976,   327,     4,     5,     6,
     847,   740,   248,   779,   808,   583,   584,     4,     5,     6,
      12,   271,  1229,   752,   400,   632,   633,   634,   635,   723,
     723,   249,  1213,    72,   992,  1014,  1063,   766,   939,   859,
     860,   581,   582,   583,   584,   412,   264,    26,    27,  1286,
    1287,   564,   581,   582,    26,    27,   423,   131,   116,   860,
     881,   677,   438,   439,    93,   116,    36,    36,    47,    55,
      29,     1,   585,     1,     1,    47,   589,   897,    95,   446,
     140,     4,     5,     6,    56,   611,     1,   613,   614,     1,
     616,   280,   618,     1,     1,    74,    30,   107,  1242,    98,
     626,   627,    74,  1501,     8,   107,    78,   897,    52,     9,
      10,   931,    54,  1319,    56,   105,    93,    98,    92,    29,
     107,   116,    98,    93,   214,    95,    95,   145,   116,    26,
      27,   110,   105,   953,   105,   154,   116,   109,   110,   111,
     129,   105,    93,    95,    93,    93,   966,   105,    93,   108,
      37,    38,   953,    40,    41,    45,    98,   151,   151,   111,
     156,   145,   252,   122,   222,   966,   104,    93,    29,   419,
      57,   280,    62,   119,   903,   145,   145,    33,   174,   171,
      72,   175,   175,   127,   107,   184,   135,   125,   147,   140,
     185,   140,   151,    49,    86,   154,   184,   145,   188,   188,
     145,   101,   154,   184,   184,   234,   395,   181,   184,   182,
    1447,   271,  1358,   110,   140,   186,   175,   109,    93,    95,
     271,   121,   186,   123,   111,  1196,  1063,  1064,   214,   121,
     959,   123,   242,    95,   537,   245,   965,   254,   255,  1420,
     242,  1142,    93,   245,  1010,   813,   814,   305,   158,  1647,
     111,   151,  1210,   271,  1233,   155,   330,   234,   188,  1079,
     188,   188,   956,  1242,   958,   958,   252,   883,  1295,   173,
     280,   158,   172,   188,   232,   154,   188,   211,   280,  1423,
     188,   188,   811,   812,   978,  1106,   395,   271,   801,  1079,
     128,   167,   192,   660,  1500,   185,   335,   158,   257,   338,
     105,   271,   271,   158,    95,   167,   285,   249,   156,   134,
     210,   266,   688,   285,   293,   565,    29,   843,   273,   428,
     262,   293,   264,   105,   105,    93,   174,   436,    95,   301,
     217,  1151,   105,   275,   276,   277,   445,   279,   527,   281,
     215,   216,   267,   452,   453,   581,   582,    26,    27,   274,
       9,   151,   461,  1560,   105,   230,   194,  1503,   105,   284,
     578,  1598,   738,   154,   215,   216,   135,   734,  1188,    28,
     737,   140,   259,   198,   250,   251,    39,   253,   145,   230,
     185,    44,    45,   151,   260,   395,   105,  1188,   250,   251,
     154,   253,  1212,   395,   270,   108,    59,   105,    61,    62,
      45,   182,    47,   185,    26,    27,   282,    70,   270,   122,
     599,  1212,   185,  1650,   424,   105,   426,   105,   527,   267,
     282,  1150,   424,     5,   426,   105,   274,     9,   105,   426,
     539,   110,   183,    96,   147,   105,   284,   424,   185,   426,
     450,   847,   551,   335,  1423,   455,   338,   154,   450,    95,
     218,   219,  1633,   455,   105,   105,  1357,  1603,  1295,   104,
     569,   570,   121,   450,   123,   105,   185,  1304,   455,  1162,
     876,   105,   105,   132,   182,  1269,     5,  1171,  1315,  1273,
       9,  1049,  1050,  1051,   105,   297,   105,    42,   110,   146,
     134,    46,   151,   154,   306,   185,    51,   185,   105,   145,
     154,   424,  1648,   426,   148,   185,   163,  1327,   185,  1049,
    1050,  1051,   404,   405,    69,   185,   408,   527,   707,   154,
     412,   166,   532,   415,   416,   527,  1327,   450,   904,   905,
     532,   423,   455,   909,   185,   185,   105,   429,   647,   121,
     432,   123,   182,   652,   105,   532,   105,    29,   440,   131,
     116,   185,   185,  1524,   446,   447,   448,   449,   105,   222,
     570,   105,   454,   105,   185,   941,   185,     9,   570,   151,
     462,   581,   582,   583,   584,   811,   650,   651,   185,   581,
     582,   583,   584,   570,   576,  1731,    28,  1733,  1408,   599,
     105,  1411,   121,   105,   123,   105,   972,   599,   707,   817,
     976,  1559,   131,   105,   105,   105,  1752,  1408,   105,   532,
    1411,   166,   105,   182,   169,   105,   508,   806,   142,   115,
       9,    10,   151,   182,   185,   128,   108,   167,    66,   184,
     522,   164,    24,    71,   156,    95,    98,  1474,   185,   531,
     122,   185,    34,   185,    45,   261,    47,   180,   144,   111,
     174,   111,   174,   120,   209,  1421,   272,  1063,  1064,   199,
    1426,   157,   771,   772,   773,   147,   775,   191,    60,   151,
     185,   563,   154,   185,   196,   185,  1306,    78,   116,   121,
    1373,   123,   182,   185,   185,   182,   156,    26,    27,   182,
     132,   194,   182,   175,   154,   191,   120,   707,    37,    38,
     154,    40,    41,   104,   174,   707,    53,  1275,    47,   151,
      53,    58,   101,     9,    10,    58,  1709,    56,    57,   146,
     730,   151,   151,   154,   154,   154,   196,   151,   730,    76,
     154,   116,   121,   730,   123,    74,   163,    42,  1041,    78,
      33,    46,  1735,   730,  1065,   947,    51,   949,    95,   120,
     760,   761,    95,  1746,  1625,  1626,    49,   120,   760,   761,
     135,  1581,   151,  1583,    69,   166,   155,   120,   660,   116,
     109,   110,   111,   760,   761,    42,   151,   207,   207,    46,
    1581,  1547,  1583,   172,    51,  1551,   245,   246,   222,   681,
     189,   190,   684,   227,  1614,  1666,   806,   999,   135,  1001,
      95,  1672,    69,   192,   806,   101,   698,   730,   120,   268,
     702,   703,   261,  1614,   151,  1191,   111,   894,   180,   158,
    1196,   210,    93,   272,  1644,   121,   222,   123,   224,   906,
     822,   193,   724,   104,   726,  1465,  1466,   760,   761,  1659,
     180,  1661,   734,  1644,   116,   737,  1035,   198,   222,   741,
     224,  1458,  1039,   193,    98,   151,   207,  1044,  1659,   155,
    1661,   166,    98,  1629,   169,   126,   127,   111,    98,  1598,
      94,     9,    10,   120,   151,   111,   172,   154,   217,   184,
     104,   111,    98,   152,    98,   154,   778,   135,   653,  1295,
     114,   656,   140,   120,   659,   111,   192,   111,  1304,   166,
      53,   125,   169,   120,   209,    58,  1282,   120,   151,  1315,
     151,   154,   151,   154,   210,   154,   808,   184,   151,   337,
     259,   275,   276,   277,   342,   130,   120,   281,   218,   219,
     220,   289,   290,   138,   139,   229,   141,   231,   830,  1569,
    1570,   229,   209,   231,   149,   151,   285,   120,   153,   213,
     155,   126,   127,  1062,   293,   160,   629,   630,   636,   637,
     861,   862,   301,   101,   638,   639,   154,   859,   860,   861,
     862,   222,   177,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,   121,   994,   123,  1491,  1492,   116,   239,
     239,   154,   994,   151,   240,   200,   201,   202,   203,   204,
     205,  1190,     0,   105,   188,   897,   165,   994,    91,   247,
    1640,    50,   197,   151,  1390,    99,   152,   155,   100,   911,
     119,   143,   154,    29,    47,  1035,   182,   182,   182,   150,
     116,   116,   244,  1035,   172,   185,    72,   302,   151,  1049,
    1050,  1051,   282,     1,   116,   282,   938,  1049,  1050,  1051,
      86,   140,   105,   151,   192,   947,  1048,   949,   185,   151,
     154,   953,   140,   154,   154,   182,   154,   154,  1474,    35,
     151,   994,   210,   109,   966,  1451,    17,   154,   154,  1268,
     154,   211,    29,   228,   185,   121,   243,   123,   188,     3,
     116,   188,    70,   166,   228,   147,    93,   168,   168,    93,
      93,   105,   105,    29,   158,   125,   130,   999,   158,  1001,
     297,   244,   140,   130,   116,   182,   182,   185,   105,    93,
     185,    45,    95,    95,   185,   185,   185,   185,    93,   151,
     234,   182,   140,   182,    33,   168,   116,    93,   130,   140,
     188,    29,   222,   284,   151,  1155,   297,   116,  1524,   224,
     125,    93,   116,  1155,   145,  1264,  1265,  1266,  1155,   252,
     195,   116,   130,   182,    95,   151,  1058,   130,  1155,   158,
     116,    98,   182,    98,   145,   151,   188,   182,   140,    35,
    1190,    29,   116,    78,   154,   105,   243,  1079,  1190,   105,
      29,  1201,   142,   154,   154,   258,   265,   151,    29,  1201,
     256,   154,   154,   154,  1201,   284,    29,   234,   224,   224,
    1220,   224,   142,  1402,  1201,   125,   145,   145,  1220,   283,
     116,   188,   145,  1220,   116,    76,   105,   140,   185,  1239,
     285,    98,  1155,  1220,   182,     7,   185,  1239,   234,   130,
     185,   185,   304,   116,   104,   185,   185,   230,   230,   230,
     188,   230,  1239,   185,   104,   145,    77,  1267,  1268,   195,
     248,    29,   184,   248,   185,  1267,  1268,   185,   185,  1161,
     284,   280,  1164,    29,   269,   105,   182,   145,  1201,   168,
    1267,   145,   124,   124,    95,   182,   184,  1179,   151,    93,
     184,   184,    29,    95,   278,   182,  1188,  1220,   184,   335,
     182,   182,   338,   168,    53,   185,    93,   185,   285,   145,
    1202,   194,   255,   184,   184,   116,  1239,    93,   195,    29,
    1212,   105,   105,   116,   116,   184,   263,    93,    93,   184,
     116,   116,   194,  1522,    92,   184,   194,   222,   222,   116,
     194,   181,   116,   116,  1533,  1534,   184,  1536,  1240,   184,
     184,   151,   116,   116,  1543,   116,   291,   185,   185,   196,
     687,   222,   898,  1109,   967,   399,   242,  1151,  1260,   405,
     303,   245,   408,   285,   419,  1603,   412,  1269,  1648,   415,
     416,  1273,   248,   809,   303,   964,  1161,   423,   303,  1291,
    1180,   743,  1402,   429,  1054,   304,   432,   304,   245,   304,
    1402,  1383,  1286,  1289,   440,  1202,   522,  1210,  1207,  1215,
     446,   447,   448,   449,   609,   323,  1233,   610,   454,   779,
     662,  1672,  1666,   862,   949,  1143,   462,   427,   427,  1260,
    1270,  1304,  1108,  1622,  1269,  1327,  1474,  1315,  1064,  1308,
    1471,  1073,   930,  1632,  1131,  1494,  1305,  1346,    -1,    -1,
    1637,    -1,  1561,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1354,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1579,  1660,   508,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   522,    -1,  1380,  1381,
      -1,    -1,    -1,    -1,    -1,   531,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1694,    -1,    -1,    -1,    -1,
      -1,    -1,  1522,    -1,  1406,    -1,  1408,    -1,    -1,  1411,
    1522,    -1,    -1,  1533,  1534,    -1,  1536,   563,    -1,  1718,
    1422,  1533,  1534,  1543,  1536,  1427,  1723,    -1,  1727,    -1,
      -1,  1543,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1442,    -1,    -1,    -1,  1741,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   555,   556,    -1,   558,
     559,   560,   561,    -1,    -1,    -1,    -1,    -1,    -1,   568,
      -1,    -1,  1622,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1622,    -1,  1632,    -1,   660,    -1,    -1,    -1,    -1,    -1,
    1632,    -1,   591,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     599,   600,    -1,    -1,    -1,  1537,    -1,  1539,   684,  1541,
    1660,    -1,    -1,    -1,    -1,    -1,  1548,    -1,  1660,    -1,
      -1,    -1,   698,    -1,    -1,    -1,   702,   703,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1694,    -1,    -1,    -1,   724,  1581,
     726,  1583,  1694,    -1,    -1,    -1,    -1,    -1,   734,   658,
      -1,   737,    -1,   662,    -1,   741,    -1,  1599,  1718,    -1,
    1602,    -1,    -1,    -1,    -1,    -1,  1718,  1727,    -1,    -1,
      -1,    -1,  1614,    -1,    -1,  1727,    -1,    -1,    -1,    -1,
      -1,    -1,  1624,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   700,   778,  1635,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1644,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1652,    -1,    -1,    -1,    -1,  1657,    -1,  1659,    -1,  1661,
      -1,    -1,   808,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   742,    -1,    -1,    -1,    -1,    -1,  1681,
      -1,    -1,    -1,    -1,   830,    -1,    -1,    -1,    -1,  1691,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   767,    -1,
      -1,    -1,    -1,    -1,    -1,  1707,    -1,    -1,   777,    -1,
      -1,    -1,  1714,   859,   860,   861,   862,    -1,  1720,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1729,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1739,    -1,    -1,
      -1,    -1,    -1,  1745,    -1,    -1,    -1,    -1,  1750,    -1,
      -1,   897,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   832,    -1,   911,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   938,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   947,    -1,   949,    -1,    -1,    -1,   953,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     966,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     899,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   999,    -1,  1001,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   936,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   955,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   977,    -1,
      -1,    -1,  1058,    -1,    -1,    -1,    -1,    -1,    -1,   988,
     989,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1079,  1003,    -1,    -1,  1006,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1020,  1021,  1022,    -1,  1024,  1025,  1026,  1027,  1028,
    1029,    -1,  1031,  1032,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1054,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1161,    -1,    -1,  1164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1096,    -1,    -1,
      -1,    -1,    -1,  1179,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1202,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1212,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1240,    -1,    -1,  1166,    -1,  1168,
      -1,  1170,    -1,    -1,  1173,    -1,    -1,    -1,    -1,  1178,
      -1,    -1,    -1,    -1,  1260,    -1,    -1,    -1,    -1,    -1,
      -1,  1190,    -1,  1269,    -1,    -1,    -1,  1273,    -1,    -1,
    1199,    -1,    -1,    -1,    -1,    -1,  1205,  1206,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1224,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1327,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1354,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1380,  1381,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1406,    -1,  1408,    -1,    -1,  1411,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1422,    -1,    -1,    -1,
      -1,  1427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1442,    -1,  1367,    -1,
      -1,    -1,  1371,    -1,    -1,    -1,  1375,    -1,  1377,    -1,
    1379,    -1,    -1,    -1,    -1,    -1,  1385,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1393,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1401,  1402,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1419,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1430,  1431,  1432,  1433,  1434,    -1,  1436,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1537,    -1,  1539,    -1,  1541,    -1,    -1,    -1,    -1,
      -1,    -1,  1548,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1581,    -1,  1583,    -1,    -1,
      -1,  1510,    -1,  1512,    -1,    -1,  1515,    -1,    -1,    -1,
      -1,    -1,    -1,  1599,  1523,    -1,  1602,    -1,    -1,  1528,
    1529,    -1,    -1,    -1,    -1,    -1,    -1,  1536,  1614,    -1,
      -1,  1540,    -1,    -1,    -1,    -1,    -1,    -1,  1624,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1635,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1644,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1652,    -1,    -1,    -1,
      -1,  1657,    -1,  1659,    -1,  1661,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1681,    -1,  1606,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1691,    -1,    -1,    -1,  1618,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1707,    -1,    -1,    -1,    -1,    -1,    -1,  1714,    -1,
      -1,    -1,    -1,    -1,  1720,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1729,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1660,    -1,  1739,    -1,    -1,    -1,    -1,    -1,  1745,
      -1,    -1,    -1,    -1,  1750,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1689,    -1,    -1,    -1,    -1,  1694,    -1,    -1,    -1,    -1,
    1699,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1717,    11,
      12,    -1,    -1,    -1,    -1,    -1,  1725,    -1,    20,    21,
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
      -1,    -1,   184,    -1,   186,   187,    -1,   189,   190,   191,
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
     302,   303,   304,   305,   306,   307,   308,    11,    12,    -1,
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
     174,   175,    -1,    -1,   178,   179,   180,    -1,   182,    -1,
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
      -1,   178,   179,   180,    -1,   182,    -1,   184,    -1,   186,
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
     180,    -1,   182,    -1,   184,    -1,   186,   187,    -1,   189,
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
      -1,   174,   175,    -1,    -1,   178,   179,   180,    -1,   182,
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
     179,   180,    -1,    -1,    -1,   184,    -1,   186,   187,    -1,
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
      -1,    -1,   184,    -1,   186,   187,    -1,   189,   190,   191,
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
     175,    -1,    -1,   178,   179,   180,    -1,    -1,    -1,   184,
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
     178,   179,   180,    -1,    -1,    -1,   184,    -1,   186,   187,
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
     184,   185,   186,   187,    -1,   189,   190,   191,    -1,   193,
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
      -1,   178,   179,   180,    -1,   182,    -1,   184,    -1,   186,
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
     150,   151,    -1,    -1,   154,   155,   156,   157,   158,    -1,
      -1,    -1,    -1,   163,   164,   165,   166,   167,   168,   169,
     170,    -1,   172,    -1,   174,   175,    -1,    -1,   178,   179,
     180,    -1,    -1,    -1,   184,   185,   186,   187,    -1,   189,
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
      -1,   154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,    -1,   172,
      -1,   174,   175,    -1,    -1,   178,   179,   180,    -1,    -1,
      -1,   184,   185,   186,   187,    -1,   189,   190,   191,    -1,
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
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
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
     179,   180,    -1,    -1,    -1,   184,    -1,   186,   187,    -1,
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
      -1,    -1,   184,    -1,   186,   187,    -1,   189,   190,   191,
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
     155,    -1,   157,   158,    -1,    -1,    -1,    -1,   163,   164,
     165,   166,   167,   168,   169,   170,    -1,   172,    -1,    -1,
      -1,    -1,    -1,   178,   179,   180,    -1,    -1,    -1,   184,
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
     148,   149,   150,   151,    -1,    -1,   154,   155,    -1,   157,
     158,    -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,    -1,   172,    -1,    -1,    -1,    -1,    -1,
     178,   179,   180,    -1,    -1,    -1,   184,    -1,   186,   187,
      -1,    -1,    -1,   191,    -1,   193,    -1,   195,   196,   197,
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
      -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    29,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,   157,   158,    -1,    -1,
      -1,    -1,   163,   164,   165,   166,   167,   168,   169,   170,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,   179,   180,
      -1,    -1,    -1,   184,    -1,   186,   187,    -1,    -1,    -1,
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
     301,   302,   303,   304,   305,   306,   307,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    -1,    93,
      94,    95,    96,    -1,    98,    99,   100,    -1,    -1,   103,
     104,    -1,    -1,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     124,   125,   126,   127,    -1,   129,    -1,    -1,    -1,   133,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,    -1,   148,   149,   150,    -1,    -1,    -1,
      -1,    -1,    -1,   157,   158,    -1,    -1,    -1,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   178,   179,   180,    -1,    -1,    -1,
     184,    -1,   186,   187,    -1,    -1,    -1,   191,    -1,   193,
      -1,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,    -1,    -1,   208,   209,    -1,    -1,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,   257,   258,   259,    -1,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    93,    94,    95,    96,    -1,    98,    99,   100,    -1,
      -1,   103,   104,    -1,    -1,    -1,    -1,   109,   110,   111,
     112,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,   125,   126,   127,    -1,   129,    -1,    -1,
      -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,   146,    -1,   148,   149,   150,    -1,
      -1,    -1,    -1,    -1,    -1,   157,   158,    -1,    -1,    -1,
      -1,   163,   164,   165,   166,   167,   168,   169,   170,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   178,   179,   180,    -1,
      -1,    -1,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,    -1,    -1,   208,   209,    -1,    -1,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,   257,   258,   259,    -1,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    -1,    93,    94,    95,    96,    -1,    98,    99,
     100,    -1,    -1,   103,   104,    -1,    -1,    -1,    -1,   109,
     110,   111,   112,   113,   114,   115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,   126,   127,    -1,   129,
      -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   145,   146,    -1,   148,   149,
     150,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,    -1,
      -1,    -1,    -1,   163,   164,   165,   166,   167,   168,   169,
     170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,   179,
     180,    -1,    -1,    -1,   184,    -1,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,    -1,    -1,   208,   209,
      -1,    -1,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,   257,   258,   259,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,    18,    19,
      -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    -1,    93,    94,    95,    96,    -1,    98,    99,
     100,    -1,    -1,   103,   104,    -1,    -1,    -1,    -1,   109,
     110,   111,   112,   113,   114,   115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,   126,   127,    -1,   129,
      -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   145,   146,    -1,   148,   149,
     150,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,    -1,
      -1,    -1,    -1,   163,   164,   165,   166,   167,   168,   169,
     170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,   179,
     180,    -1,    -1,    -1,   184,    -1,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,    -1,    -1,   208,   209,
      -1,    -1,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,   257,   258,   259,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,    24,    25,
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
     146,    -1,   148,   149,   150,    -1,    -1,    -1,   154,    -1,
      -1,   157,   158,    -1,    -1,    -1,    -1,   163,   164,   165,
     166,   167,   168,   169,   170,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   178,   179,   180,    -1,    -1,    -1,   184,   185,
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
     306,   307,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    93,    94,    95,    96,    -1,    98,    99,   100,    -1,
      -1,   103,   104,    -1,    -1,    -1,    -1,   109,   110,   111,
     112,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,   125,   126,   127,    -1,   129,    -1,    -1,
      -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,   146,    -1,   148,   149,   150,    -1,
      -1,    -1,    -1,    -1,    -1,   157,   158,    -1,    -1,    -1,
      -1,   163,   164,   165,   166,   167,   168,   169,   170,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   178,   179,   180,    -1,
      -1,    -1,   184,   185,   186,   187,    -1,    -1,    -1,   191,
      -1,   193,    -1,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,    -1,    -1,   208,   209,    -1,    -1,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,   257,   258,   259,    -1,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,    24,    25,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    -1,    93,    94,    95,    96,    -1,
      98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,
      -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,    -1,
     148,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,   157,
     158,    -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     178,   179,   180,    -1,    -1,    -1,   184,   185,   186,   187,
      -1,    -1,    -1,   191,    -1,   193,    -1,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    -1,    -1,
     208,   209,    -1,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    -1,    93,
      94,    95,    96,    -1,    98,    99,   100,    -1,    -1,   103,
     104,    -1,    -1,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     124,   125,   126,   127,    -1,   129,    -1,    -1,    -1,   133,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,    -1,   148,   149,   150,    -1,    -1,    -1,
     154,    -1,    -1,   157,   158,    -1,    -1,    -1,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   178,   179,   180,    -1,    -1,    -1,
     184,    -1,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,    -1,    -1,   208,   209,    -1,    -1,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,   257,   258,   259,    -1,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,    24,    25,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    -1,    93,    94,    95,    96,    -1,    98,    99,
     100,    -1,    -1,   103,   104,    -1,    -1,    -1,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,   126,   127,    -1,   129,
      -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   145,   146,    -1,   148,   149,
     150,    -1,    -1,    -1,   154,    -1,    -1,   157,   158,    -1,
      -1,    -1,    -1,   163,   164,   165,   166,   167,   168,   169,
     170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,   179,
     180,    -1,    -1,    -1,   184,    -1,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,    -1,    -1,   208,   209,
      -1,    -1,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,   257,   258,   259,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    95,
      96,    -1,    98,    99,   100,    -1,    -1,   103,   104,    -1,
      -1,    -1,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,
     126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,   135,
     136,   137,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,    -1,   148,   149,   150,    -1,    -1,    -1,   154,    -1,
      -1,   157,   158,    -1,    -1,    -1,    -1,   163,   164,   165,
     166,   167,   168,   169,   170,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   178,   179,   180,    -1,    -1,    -1,   184,    -1,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,   195,
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
     306,   307,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    93,    94,    95,    96,    -1,    98,    99,   100,    -1,
      -1,   103,   104,    -1,    -1,    -1,    -1,   109,   110,   111,
     112,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,   125,   126,   127,    -1,   129,    -1,    -1,
      -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,   146,    -1,   148,   149,   150,    -1,
      -1,    -1,   154,    -1,    -1,   157,   158,    -1,    -1,    -1,
      -1,   163,   164,   165,   166,   167,   168,   169,   170,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   178,   179,   180,    -1,
      -1,    -1,   184,    -1,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,    -1,    -1,   208,   209,    -1,    -1,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,   257,   258,   259,    -1,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,    24,    25,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    -1,    93,    94,    95,    96,    -1,
      98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,
      -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,    -1,
     148,   149,   150,    -1,    -1,    -1,   154,    -1,    -1,   157,
     158,    -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     178,   179,   180,    -1,    -1,    -1,   184,    -1,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    -1,    -1,
     208,   209,    -1,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    -1,    93,
      94,    95,    96,    -1,    98,    99,   100,    -1,    -1,   103,
     104,    -1,    -1,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     124,   125,   126,   127,    -1,   129,    -1,    -1,    -1,   133,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,    -1,   148,   149,   150,    -1,    -1,    -1,
      -1,    -1,    -1,   157,   158,    -1,    -1,    -1,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   178,   179,   180,    -1,    -1,    -1,
     184,    -1,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,    -1,    -1,   208,   209,    -1,    -1,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,   257,   258,   259,    -1,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,    24,    25,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    -1,
      40,    41,    42,    43,    -1,    -1,    46,    47,    -1,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    -1,
      60,    -1,    -1,    63,    64,    65,    66,    67,    -1,    69,
      -1,    71,    -1,    -1,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    -1,    93,    94,    95,    -1,    -1,    98,    99,
     100,    -1,    -1,   103,   104,    -1,    -1,    -1,    -1,   109,
     110,   111,   112,   113,   114,   115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,   126,   127,    -1,   129,
      -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   145,   146,    -1,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,    -1,
      -1,    -1,    -1,   163,   164,   165,   166,   167,   168,   169,
     170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,   179,
     180,    -1,    -1,    -1,   184,    -1,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,    -1,    -1,    -1,   209,
      -1,    -1,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,    -1,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,   257,   258,   259,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307
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
     359,   361,   362,   364,   371,   374,   377,   378,   379,   381,
     382,   383,   384,   385,   387,   388,   390,   391,   392,   393,
     394,   395,   397,   398,   401,   402,   403,   404,   409,   411,
     413,   414,   419,   438,   441,   445,   448,   449,   454,   455,
     456,   457,   459,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   505,   506,   507,   521,   522,   524,   525,   526,
     527,   528,   529,   530,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   550,   551,   552,   553,   558,   559,
     560,   561,   562,   563,   566,   624,   626,   627,   628,    33,
      34,    49,   212,   380,   381,   382,   380,   380,   154,   154,
      37,    38,    40,    41,    47,    56,    57,    74,    78,   109,
     110,   111,   158,   217,   259,   285,   293,   301,   360,   361,
     365,   366,   367,   158,   151,   154,   151,   154,   151,   154,
      66,    71,   116,   406,   154,   368,   154,    24,    34,    60,
     116,   271,   418,   420,   421,   151,   154,   154,   154,   116,
     151,   154,   154,   154,    93,   151,   218,   219,   120,   120,
     120,   151,   154,    29,    39,    43,    45,    46,    47,    48,
      51,    59,    67,    70,    72,    73,    75,    89,    90,    96,
     103,   110,   112,   113,   133,   136,   137,   167,   170,   178,
     179,   187,   199,   221,   223,   225,   226,   233,   235,   236,
     237,   238,   241,   242,   489,   626,   627,   120,   116,   389,
     120,   120,    39,    44,    45,    59,    61,    62,    70,    96,
     222,   626,   116,   120,   120,   182,   380,   382,    48,    72,
      73,   116,   151,   185,   242,   401,   403,   413,   626,   151,
     120,    16,   625,   626,    18,    19,   626,   120,   120,   120,
     481,   151,    30,   211,   213,   222,   224,   154,   222,   224,
     222,   222,   227,   116,   110,   361,   239,   239,   240,   154,
     151,   384,   325,     0,   327,   328,    33,    49,   330,   347,
       1,   188,   324,   188,   324,   110,   362,   383,   401,   105,
     188,   105,   188,    42,    46,    51,    69,   166,   169,   184,
     209,   396,   405,   410,   411,   412,   426,   427,   431,   165,
      91,   130,   138,   139,   141,   149,   153,   155,   160,   177,
     200,   201,   202,   203,   204,   205,   473,   474,   247,   156,
     174,   196,   115,   144,   157,   191,   198,   207,   134,   148,
      50,   197,    99,   100,   156,   174,   472,   151,   478,   481,
     189,   190,   152,   493,   494,   489,   493,   489,   154,   493,
     119,   143,   154,   182,   182,   182,    29,   363,   496,   363,
     624,   180,   193,   180,   193,   164,   180,   627,   626,   167,
     199,    47,   626,   150,   116,    45,    47,    78,   104,   166,
     625,   218,   219,   220,   244,   597,   626,   626,   302,   135,
     140,   110,   285,   293,   365,   625,   381,   382,   185,   380,
      45,    62,   185,   546,   547,   401,   185,   191,   626,   282,
     282,   415,   416,   626,   116,   422,   116,   185,   369,   370,
     151,   386,   401,     1,   158,   624,   111,   158,   343,   624,
     626,   116,   140,   105,   401,    29,   185,   625,   626,   626,
     439,   440,   626,   381,   185,   401,   401,   548,   626,   381,
     151,   151,   401,   185,   191,   626,   626,   140,   439,   182,
     182,   154,   154,   154,   626,   151,   185,   184,    35,   509,
     510,   511,   401,     8,   173,    17,   401,   211,    29,   402,
     402,   185,   402,   402,   402,   402,   228,   564,   565,   626,
     389,   110,   188,   188,   402,   401,   382,   401,   243,   399,
     400,   188,   324,   188,   324,     3,   331,   347,   378,   331,
     347,   378,    33,   348,   378,   348,   378,   389,   389,   402,
     116,   166,   168,   168,   383,   402,   402,   456,   457,   459,
     459,   459,   459,   458,   459,   459,   459,    70,   463,   463,
     462,   464,   464,   464,   464,   465,   465,   466,   466,   228,
      93,    93,    93,   182,   401,   481,   481,   401,   494,   185,
     402,   504,   625,   147,   185,   504,   105,   185,   185,   105,
     105,   368,    29,   627,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,   350,   351,   352,    93,   135,   140,
     356,   357,   358,   626,   158,   158,   350,   624,   125,   130,
      54,    56,    98,   249,   262,   264,   275,   276,   277,   279,
     281,   598,   599,   600,   601,   602,   603,   610,   616,   617,
     244,    93,   234,   373,   297,   626,   140,   402,   116,   626,
     626,   130,   182,   182,   185,   185,   182,   105,   185,   105,
     185,   105,    36,    93,    95,   145,   417,   418,   532,   626,
      55,   214,   252,   407,   408,   626,    93,   105,   185,   380,
     185,   625,    95,    45,   625,   624,    95,   140,   532,   626,
     402,   421,   182,   185,   185,   185,   185,   105,   186,   145,
     532,   182,   185,   185,   151,   182,   381,   381,   182,   105,
     185,   105,   185,   140,   532,   402,   186,   401,   401,   401,
     626,   510,   511,   128,   194,   182,   182,   129,   188,    93,
     215,   216,   230,    93,   215,   216,   230,    93,   234,   222,
     105,   232,   140,   389,   188,   185,    48,    72,    73,   242,
     403,   413,   182,   490,   570,   400,   347,    33,    33,   188,
     324,   188,   111,   626,   168,   402,   432,   433,   116,   428,
     429,   459,   151,   154,   257,   477,   496,   571,   574,   575,
     576,   577,   578,   582,   584,   586,   587,    47,   150,   154,
     208,   533,   535,   537,   538,   554,   555,   556,   557,   626,
     533,   531,   537,   531,   182,   183,   105,   185,   185,   496,
     146,   163,   146,   163,   135,   386,   368,   351,   130,   535,
     358,   402,   532,   624,   624,   126,   127,   624,   275,   276,
     277,   281,   626,   261,   272,   261,   272,    29,   284,    95,
     111,   154,   604,   607,   598,    39,    44,    59,    61,    70,
      96,   222,   372,   538,   289,   290,   224,   297,   306,   402,
     626,    93,   373,   297,   624,   151,   548,   549,   626,   548,
     549,   116,   125,   533,   116,   402,   145,   418,   145,    36,
     145,   417,   418,   145,   532,   252,    53,    58,    76,   116,
     417,   423,   424,   425,   408,   532,   533,   370,    93,   182,
     195,   130,   342,   624,   158,   130,    95,   342,   402,   140,
     418,   151,   116,   402,   402,   145,    98,   442,   443,   444,
     446,   447,    98,   450,   451,   452,   453,   381,   182,   182,
     151,   548,   548,   402,   140,   188,   402,   185,   185,   185,
      35,   511,   128,   194,     9,    10,   101,   121,   123,   151,
     192,   506,   508,   519,   520,   523,    29,   229,   231,   402,
     402,   402,   229,   231,   402,   402,   402,   402,   402,   402,
     116,   402,   402,   383,   154,   154,   154,   151,   184,   243,
     567,   568,   154,   207,   384,   188,   111,   378,   378,   378,
     432,    94,   104,   114,   125,   434,   435,   436,   437,   105,
     626,   105,   401,   571,   578,   151,   283,   460,   623,    95,
     167,   250,   251,   253,   260,   270,   282,   572,   573,   592,
     593,   594,   595,   618,   621,   256,   258,   579,   597,   265,
     583,   619,   245,   246,   268,   588,   589,   154,   154,   535,
     154,   142,   174,   191,   534,   142,   402,   135,   386,   550,
     357,   284,    29,    95,   111,   154,   611,    29,   604,   373,
     534,   224,   224,   479,   285,   304,   532,   372,   224,   188,
     380,   185,   185,   142,   185,   185,   416,   145,   417,   626,
     402,   145,   402,   125,   402,   145,   418,   145,   402,   145,
     116,   116,   402,   626,   425,    76,   533,   383,   402,   624,
     105,   342,   402,   140,   380,   440,   402,   402,   111,   443,
     444,    98,   184,   111,   444,   447,   116,   533,    98,   111,
     451,    98,   111,   453,   182,   380,   185,   185,   402,   195,
     450,   130,   192,   508,     7,   381,   626,   192,   519,   188,
     230,   230,   230,   230,   234,   565,   184,   401,   401,   401,
     570,   568,   116,   490,   624,   126,   127,   436,   437,   437,
     433,   104,   430,   429,   182,   185,   571,   585,   248,   214,
     252,   266,   273,   622,    95,   254,   255,   620,   248,   575,
     622,   462,   592,   576,   145,   280,   580,   581,   620,   284,
     591,    77,   590,   185,   191,   533,   536,   185,   185,   185,
      29,   134,   198,   613,   614,   615,    29,   612,   613,   269,
     608,   105,   605,   168,   626,   255,   373,   479,   182,   402,
     145,   402,   145,   417,   402,   145,   402,   402,   626,   626,
     424,   402,   124,   124,    95,   624,   402,   182,   184,   184,
     402,   383,   402,   184,   184,   626,   184,   116,   533,   116,
     184,   116,   533,   184,   182,   111,   511,   626,   192,   182,
     511,   626,   402,   402,   402,   402,   402,   402,   185,   185,
     185,   151,   154,   569,   626,   437,   624,   182,   464,    52,
     127,   462,   462,   267,   274,   284,   596,   596,   577,   151,
     278,    93,   185,   105,   185,   611,   611,   615,   105,   185,
      29,   609,   620,   606,   607,   185,   375,   376,   479,   116,
     222,   305,   285,   168,   402,   402,   145,   402,    53,   383,
     402,   342,   402,   383,    93,   383,   402,   626,   184,   626,
     402,   626,   184,   383,   116,    92,   181,   512,   511,   626,
     194,   511,   195,   450,   401,   116,   105,   185,   462,   462,
     196,   401,   533,   533,    93,    29,   263,   105,   105,   437,
     532,   626,   116,   222,   626,   375,   402,   116,   533,    93,
     184,    93,   626,     5,   131,   515,   516,   518,   520,    28,
     132,   513,   514,   517,   520,   194,   511,   194,   111,   182,
     626,   116,   384,   462,   182,   533,   607,   376,   437,   303,
     626,   116,   222,   626,   184,   533,   383,   402,   533,   184,
      92,   131,   518,   181,   132,   517,   194,   116,   105,   185,
     626,   402,   303,   626,   116,   383,   402,   184,   184,   626,
     116,   569,   105,   185,   291,   303,   626,   184,   626,   116,
     384,   304,   402,   304,   105,   185,   626,   479,   479,   116,
     569,   185,   196,   626,   384,   285,   185,   626,   569,   222,
     116,   626,   304,   479
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
     371,   371,   371,   371,   371,   371,   372,   372,   373,   373,
     374,   374,   375,   375,   376,   376,   376,   376,   377,   377,
     377,   377,   378,   379,   379,   379,   380,   380,   380,   381,
     381,   382,   382,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   384,   384,   385,   386,   387,
     388,   388,   388,   388,   388,   389,   389,   389,   389,   390,
     391,   392,   393,   394,   394,   395,   396,   397,   398,   399,
     399,   400,   400,   400,   400,   401,   401,   402,   402,   402,
     402,   402,   402,   403,   403,   403,   403,   403,   403,   403,
     404,   405,   406,   406,   407,   407,   407,   408,   408,   409,
     409,   410,   411,   411,   411,   412,   412,   412,   412,   412,
     413,   413,   414,   415,   415,   416,   416,   416,   416,   416,
     416,   416,   416,   416,   416,   416,   416,   417,   418,   419,
     420,   420,   421,   421,   421,   421,   422,   422,   423,   423,
     423,   424,   424,   424,   425,   425,   425,   426,   427,   428,
     428,   429,   429,   430,   431,   431,   432,   432,   433,   433,
     434,   434,   434,   434,   434,   434,   434,   435,   435,   436,
     436,   437,   438,   438,   439,   439,   440,   440,   441,   442,
     442,   443,   444,   444,   445,   446,   446,   447,   448,   448,
     449,   449,   450,   450,   451,   451,   452,   452,   453,   453,
     454,   455,   455,   456,   456,   457,   457,   457,   457,   457,
     458,   457,   457,   457,   457,   459,   459,   460,   460,   461,
     461,   462,   462,   462,   463,   463,   463,   463,   463,   464,
     464,   464,   465,   465,   465,   466,   466,   467,   467,   468,
     468,   469,   469,   470,   470,   471,   471,   471,   471,   472,
     472,   472,   473,   473,   473,   473,   473,   473,   474,   474,
     474,   475,   475,   475,   475,   476,   476,   477,   477,   478,
     478,   478,   479,   479,   479,   479,   480,   481,   481,   481,
     482,   482,   483,   483,   483,   483,   484,   484,   485,   485,
     485,   485,   485,   485,   485,   486,   486,   487,   487,   488,
     488,   488,   488,   488,   489,   489,   490,   490,   491,   491,
     491,   491,   492,   492,   492,   492,   493,   493,   494,   495,
     495,   495,   495,   495,   495,   495,   495,   495,   495,   496,
     496,   497,   497,   497,   498,   499,   499,   500,   501,   502,
     503,   503,   504,   504,   505,   505,   506,   506,   506,   507,
     507,   507,   507,   507,   507,   508,   508,   509,   509,   510,
     511,   511,   512,   512,   513,   513,   514,   514,   514,   514,
     515,   515,   516,   516,   516,   516,   517,   517,   518,   518,
     519,   519,   519,   519,   520,   520,   520,   520,   521,   521,
     522,   522,   523,   524,   524,   524,   524,   524,   524,   525,
     526,   526,   527,   527,   528,   529,   530,   530,   531,   531,
     532,   533,   533,   533,   534,   534,   534,   535,   535,   535,
     535,   535,   536,   536,   537,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   539,   540,   540,   540,   541,   542,
     543,   543,   543,   544,   544,   544,   544,   544,   545,   546,
     546,   546,   546,   546,   546,   546,   547,   548,   549,   550,
     551,   551,   552,   553,   554,   554,   555,   556,   556,   557,
     558,   558,   558,   559,   559,   559,   559,   559,   559,   559,
     559,   559,   559,   560,   560,   561,   561,   562,   563,   564,
     564,   565,   566,   567,   567,   568,   568,   568,   568,   569,
     570,   570,   571,   572,   572,   573,   573,   574,   574,   575,
     575,   576,   576,   577,   577,   578,   579,   579,   580,   580,
     581,   582,   582,   582,   583,   583,   584,   585,   585,   586,
     587,   587,   588,   588,   589,   589,   589,   590,   590,   591,
     591,   592,   592,   592,   592,   592,   593,   594,   595,   596,
     596,   596,   597,   597,   598,   598,   598,   598,   598,   598,
     598,   598,   599,   599,   599,   599,   600,   600,   601,   602,
     602,   603,   603,   603,   604,   604,   605,   605,   606,   606,
     607,   608,   608,   609,   609,   610,   610,   610,   611,   611,
     612,   612,   613,   613,   614,   614,   615,   615,   616,   617,
     617,   618,   618,   618,   619,   620,   620,   620,   620,   621,
     621,   622,   622,   623,   624,   625,   625,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   627,   627,   627,   627,   627,   627,   627,
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
     627,   627,   628,   628
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
       2,     3,     4,     5,     1,     3,     2,     3,     3,     4,
       5,     6,     4,     5,     6,     7,     1,     2,     3,     3,
       8,     9,     1,     3,     1,     2,     2,     3,    11,    14,
      13,    22,     1,     1,     1,     0,     1,     1,     0,     1,
       2,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     3,     3,     2,
       3,     2,     3,     3,     4,     2,     3,     4,     5,     5,
       2,     4,     5,     3,     3,     2,     2,     8,     3,     1,
       2,     3,     7,    10,    13,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     1,     1,     2,     4,     3,     5,
       4,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     1,     4,     3,     5,     4,     6,     4,
       6,     5,     7,     4,     5,     5,     6,     3,     3,     2,
       1,     3,     4,     5,     3,     6,     4,     5,     1,     2,
       3,     1,     2,     1,     6,     3,     3,     2,     3,     1,
       3,     2,     3,     2,     3,     4,     1,     3,     1,     2,
       1,     1,     1,     2,     2,     2,     3,     1,     1,     2,
       2,     2,     5,     5,     1,     4,     3,     4,     8,     1,
       2,     3,     2,     3,     8,     1,     2,     3,     8,    10,
       8,    10,     1,     2,     4,     7,     1,     2,     4,     7,
       8,     1,     3,     1,     3,     1,     3,     3,     3,     3,
       0,     4,     3,     3,     3,     1,     5,     0,     1,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     4,     1,     4,     1,
       4,     1,     4,     1,     2,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     5,     5,     6,     3,     4,     1,     2,     3,
       2,     2,     1,     2,     2,     1,     1,     1,     3,     3,
       1,     1,     1,     2,     1,     2,     2,     1,     2,     2,
       2,     2,     2,     2,     2,     1,     2,     2,     1,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     4,     1,     2,     3,     1,
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
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     4,     4,     3,     3,
       3,     4,     4,     3,     4,     6,     4,     6,     4,     3,
       4,     6,     6,     4,     6,     6,     4,     1,     2,     1,
       1,     1,     3,     3,     1,     1,     4,     5,     6,     3,
       3,     3,     3,     5,     7,     7,     5,     5,     5,     7,
       7,     5,     5,     3,     3,     5,     7,     5,     7,     1,
       4,     3,     5,     1,     2,     3,     7,    10,    13,     3,
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
       2,     1,     1,     3,     1,     1,     1,     1,     1,     1,
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
       1,     1,     3,     1
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
  "Param", "CollectionDecl", "CollectionTypeDecl", "NodeModifier",
  "IndexDecl", "IndexKeyList", "IndexKeySpec", "IntegrityConstraintDecl",
  "QueryBody", "StatementsAndOptionalExprTop", "StatementsAndOptionalExpr",
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
      29,   188,    -1,   330,   188,   378,    -1,   347,   188,   378,
      -1,   330,   188,   347,   188,   378,    -1,   378,    -1,   330,
     324,   378,    -1,   347,   324,   378,    -1,   330,   188,   347,
     324,   378,    -1,   330,   324,   347,   188,   378,    -1,   329,
      -1,   329,   330,   188,    -1,   329,   347,   188,    -1,   329,
     330,   188,   347,   188,    -1,    34,   158,   625,   130,   624,
     188,    -1,   331,    -1,   330,   188,   331,    -1,   330,   324,
     331,    -1,   332,    -1,   340,    -1,   345,    -1,   346,    -1,
     354,    -1,   333,    -1,   334,    -1,   335,    -1,   336,    -1,
     337,    -1,   338,    -1,   339,    -1,   558,    -1,    33,    38,
     180,    -1,    33,    38,   193,    -1,    33,   111,   104,   624,
      -1,    33,    37,   624,    -1,    33,    40,   180,    -1,    33,
      40,   193,    -1,    33,    57,   167,    -1,    33,    57,   199,
      -1,    33,   111,   166,   125,   126,    -1,    33,   111,   166,
     125,   127,    -1,    33,    41,   180,   105,   146,    -1,    33,
      41,   180,   105,   163,    -1,    33,    41,   164,   105,   146,
      -1,    33,    41,   164,   105,   163,    -1,   341,    -1,   344,
      -1,    49,    24,     1,    -1,    49,    60,   624,    -1,    49,
      60,   343,   624,    -1,    49,    60,   624,    95,   342,    -1,
      49,    60,   343,   624,    95,   342,    -1,   624,    -1,   342,
     105,   624,    -1,   158,   625,   130,    -1,   111,    45,   158,
      -1,    49,    34,   624,    -1,    49,    34,   158,   625,   130,
     624,    -1,    49,    34,   624,    95,   342,    -1,    49,    34,
     158,   625,   130,   624,    95,   342,    -1,    33,   158,   625,
     130,   624,    -1,    33,   111,    45,   158,   624,    -1,    33,
     111,    47,   158,   624,    -1,   348,    -1,   347,   188,   348,
      -1,   347,   324,   348,    -1,   349,    -1,   353,    -1,   355,
      -1,   359,    -1,   364,    -1,   371,    -1,   374,    -1,   377,
      -1,    33,   111,    78,   350,    -1,    33,    78,   626,   350,
      -1,   351,    -1,   350,   351,    -1,   352,   130,   550,    -1,
      79,    -1,    87,    -1,    80,    -1,    81,    -1,    82,    -1,
      83,    -1,    88,    -1,    84,    -1,    85,    -1,    86,    -1,
      33,    56,   626,    29,    -1,    33,   259,   597,    -1,    33,
     109,   150,   356,    -1,    93,   535,   357,    -1,   357,    -1,
     358,    -1,   135,    -1,   135,   358,    -1,   140,   402,    -1,
      33,   360,   140,   402,    -1,    33,   360,   135,    -1,    33,
     360,   135,   140,   402,    -1,   110,   116,   626,    -1,   110,
     116,   626,   532,    -1,   361,   110,   116,   626,    -1,   361,
     110,   116,   626,   532,    -1,   362,    -1,   361,   362,    -1,
      26,    -1,    26,   154,   363,   185,    -1,    27,    -1,    27,
     154,   363,   185,    -1,   496,    -1,   363,   105,   496,    -1,
      33,   365,    -1,    33,   361,   365,    -1,   366,    -1,   367,
      -1,    47,   627,   368,   386,    -1,    47,   627,   368,   135,
      -1,    74,    47,   627,   368,   386,    -1,    74,    47,   627,
     368,   135,    -1,   154,   185,    -1,   154,   369,   185,    -1,
     154,   185,    93,   533,    -1,   154,   369,   185,    93,   533,
      -1,   370,    -1,   369,   105,   370,    -1,   116,   626,    -1,
     116,   626,   532,    -1,    33,   285,   626,    -1,    33,   285,
     626,   373,    -1,    33,   285,   626,    93,   372,    -1,    33,
     285,   626,    93,   372,   373,    -1,    33,   361,   285,   626,
      -1,    33,   361,   285,   626,   373,    -1,    33,   361,   285,
     626,    93,   372,    -1,    33,   361,   285,   626,    93,   372,
     373,    -1,   538,    -1,   538,   534,    -1,   234,   290,   224,
      -1,   234,   289,   224,    -1,    33,   293,   626,   297,   224,
     479,   168,   375,    -1,    33,   361,   293,   626,   297,   224,
     479,   168,   375,    -1,   376,    -1,   375,   105,   376,    -1,
     479,    -1,   479,   532,    -1,   479,   437,    -1,   479,   532,
     437,    -1,    33,   301,   302,   626,   297,   285,   626,   116,
     626,   303,   402,    -1,    33,   301,   302,   626,   297,   285,
     626,   222,   116,   626,   303,   291,   304,   479,    -1,    33,
     301,   302,   626,   297,   285,   626,   305,   222,   116,   626,
     303,   402,    -1,    33,   301,   302,   626,   306,   304,   255,
     285,   626,   222,   116,   626,   304,   479,   196,   285,   626,
     222,   116,   626,   304,   479,    -1,   379,    -1,   381,    -1,
     382,    -1,    -1,   381,    -1,   382,    -1,    -1,   401,    -1,
     382,   401,    -1,   383,    -1,   382,   383,    -1,   384,    -1,
     387,    -1,   390,    -1,   391,    -1,   392,    -1,   393,    -1,
     394,    -1,   395,    -1,   397,    -1,   449,    -1,   445,    -1,
     398,    -1,   151,   382,   182,    -1,   151,   182,    -1,   151,
     380,   182,    -1,   151,   380,   182,    -1,   388,   188,    -1,
     388,   105,   389,    -1,   110,   389,    -1,   235,   110,   389,
      -1,   361,   110,   389,    -1,   235,   361,   110,   389,    -1,
     116,   626,    -1,   116,   626,   532,    -1,   116,   626,   140,
     402,    -1,   116,   626,   532,   140,   402,    -1,   116,   626,
     140,   402,   188,    -1,   403,   188,    -1,   238,   240,   402,
     188,    -1,   241,   154,   401,   185,   383,    -1,   236,   239,
     188,    -1,   237,   239,   188,    -1,   413,   396,    -1,   184,
     383,    -1,    48,   154,   401,   185,   195,   383,   124,   383,
      -1,   242,   384,   399,    -1,   400,    -1,   399,   400,    -1,
     243,   570,   384,    -1,   243,   570,   154,   116,   626,   185,
     384,    -1,   243,   570,   154,   116,   626,   105,   116,   626,
     185,   384,    -1,   243,   570,   154,   116,   626,   105,   116,
     626,   105,   116,   626,   185,   384,    -1,   402,    -1,   401,
     105,   402,    -1,   404,    -1,   441,    -1,   448,    -1,   454,
      -1,   566,    -1,   403,    -1,   455,    -1,   438,    -1,   559,
      -1,   560,    -1,   562,    -1,   561,    -1,   563,    -1,   413,
     405,    -1,   184,   402,    -1,    66,   282,    -1,    71,   282,
      -1,   214,    -1,   252,    -1,    55,   252,    -1,   407,   423,
      76,   402,    -1,   407,    76,   402,    -1,    46,   406,   422,
     408,   408,    -1,    46,   406,   422,   408,    -1,    42,   116,
     626,    -1,   414,    -1,   419,    -1,   409,    -1,   411,    -1,
     426,    -1,   431,    -1,   427,    -1,   410,    -1,   411,    -1,
     413,   412,    -1,    46,   116,   415,    -1,   416,    -1,   415,
     105,   116,   416,    -1,   626,   145,   402,    -1,   626,    36,
     125,   145,   402,    -1,   626,   532,   145,   402,    -1,   626,
     532,    36,   125,   145,   402,    -1,   626,   417,   145,   402,
      -1,   626,    36,   125,   417,   145,   402,    -1,   626,   532,
     417,   145,   402,    -1,   626,   532,    36,   125,   417,   145,
     402,    -1,   626,   418,   145,   402,    -1,   626,   532,   418,
     145,   402,    -1,   626,   417,   418,   145,   402,    -1,   626,
     532,   417,   418,   145,   402,    -1,    95,   116,   626,    -1,
     271,   116,   626,    -1,    51,   420,    -1,   421,    -1,   420,
     105,   421,    -1,   116,   626,   140,   402,    -1,   116,   626,
     532,   140,   402,    -1,   418,   140,   402,    -1,   116,   626,
     532,   418,   140,   402,    -1,   116,   626,   145,   402,    -1,
     116,   626,   532,   145,   402,    -1,   424,    -1,   116,   626,
      -1,   116,   626,   424,    -1,   417,    -1,   417,   425,    -1,
     425,    -1,    58,   116,   626,    53,   116,   626,    -1,    53,
     116,   626,    -1,    58,   116,   626,    -1,   209,   402,    -1,
     169,   168,   428,    -1,   429,    -1,   428,   105,   429,    -1,
     116,   626,    -1,   116,   626,   430,    -1,   104,   624,    -1,
     166,   168,   432,    -1,    69,   166,   168,   432,    -1,   433,
      -1,   432,   105,   433,    -1,   402,    -1,   402,   434,    -1,
     435,    -1,   436,    -1,   437,    -1,   435,   436,    -1,   435,
     437,    -1,   436,   437,    -1,   435,   436,   437,    -1,    94,
      -1,   114,    -1,   125,   126,    -1,   125,   127,    -1,   104,
     624,    -1,    67,   116,   439,   186,   402,    -1,   133,   116,
     439,   186,   402,    -1,   440,    -1,   439,   105,   116,   440,
      -1,   626,   145,   402,    -1,   626,   532,   145,   402,    -1,
      72,   154,   401,   185,   442,   111,   184,   402,    -1,   443,
      -1,   442,   443,    -1,   444,   184,   402,    -1,    98,   402,
      -1,   444,    98,   402,    -1,    72,   154,   401,   185,   446,
     111,   184,   383,    -1,   447,    -1,   446,   447,    -1,   444,
     184,   383,    -1,    73,   154,   401,   185,   450,   111,   184,
     402,    -1,    73,   154,   401,   185,   450,   111,   116,   626,
     184,   402,    -1,    73,   154,   401,   185,   452,   111,   184,
     383,    -1,    73,   154,   401,   185,   450,   111,   116,   626,
     184,   383,    -1,   451,    -1,   450,   451,    -1,    98,   533,
     184,   402,    -1,    98,   116,   626,    93,   533,   184,   402,
      -1,   453,    -1,   452,   453,    -1,    98,   533,   184,   383,
      -1,    98,   116,   626,    93,   533,   184,   383,    -1,    48,
     154,   401,   185,   195,   402,   124,   402,    -1,   456,    -1,
     455,   165,   456,    -1,   457,    -1,   456,    91,   457,    -1,
     459,    -1,   459,   473,   459,    -1,   459,   474,   459,    -1,
     459,   130,   459,    -1,   459,   160,   459,    -1,    -1,   459,
     155,   458,   459,    -1,   459,   153,   459,    -1,   459,   141,
     459,    -1,   459,   139,   459,    -1,   461,    -1,   461,   247,
      70,   571,   460,    -1,    -1,   623,    -1,   462,    -1,   462,
     196,   462,    -1,   463,    -1,   462,   174,   463,    -1,   462,
     156,   463,    -1,   464,    -1,   463,   191,   464,    -1,   463,
     115,   464,    -1,   463,   144,   464,    -1,   463,   157,   464,
      -1,   465,    -1,   464,   198,   465,    -1,   464,   207,   465,
      -1,   466,    -1,   465,   148,   466,    -1,   465,   134,   466,
      -1,   467,    -1,   467,    50,   228,   533,    -1,   468,    -1,
     468,   197,    93,   533,    -1,   469,    -1,   469,    99,    93,
     531,    -1,   470,    -1,   470,   100,    93,   531,    -1,   472,
      -1,   471,   472,    -1,   174,    -1,   156,    -1,   471,   174,
      -1,   471,   156,    -1,   475,    -1,   479,    -1,   476,    -1,
     200,    -1,   205,    -1,   204,    -1,   203,    -1,   202,    -1,
     201,    -1,   149,    -1,   177,    -1,   138,    -1,    75,   151,
     381,   182,    -1,    75,   219,   151,   381,   182,    -1,    75,
     218,   151,   381,   182,    -1,    75,    93,   548,   151,   381,
     182,    -1,   477,   151,   182,    -1,   477,   151,   401,   182,
      -1,   478,    -1,   477,   478,    -1,   175,   626,    17,    -1,
     175,    18,    -1,   175,    19,    -1,   480,    -1,   480,   481,
      -1,   190,   481,    -1,   481,    -1,   189,    -1,   482,    -1,
     482,   189,   481,    -1,   482,   190,   481,    -1,   483,    -1,
     492,    -1,   484,    -1,   484,   493,    -1,   487,    -1,   487,
     493,    -1,   485,   489,    -1,   486,    -1,   103,   120,    -1,
     112,   120,    -1,    96,   120,    -1,   187,   120,    -1,   113,
     120,    -1,   137,   120,    -1,   136,   120,    -1,   489,    -1,
      97,   489,    -1,   488,   489,    -1,   118,    -1,   170,   120,
      -1,    89,   120,    -1,   179,   120,    -1,   178,   120,    -1,
      90,   120,    -1,   538,    -1,   490,    -1,   626,    -1,   491,
      -1,   191,    -1,    11,    -1,    12,    -1,    20,    -1,   495,
      -1,   492,   493,    -1,   492,   154,   185,    -1,   492,   154,
     504,   185,    -1,   494,    -1,   493,   494,    -1,   152,   401,
     183,    -1,   496,    -1,   498,    -1,   499,    -1,   500,    -1,
     503,    -1,   505,    -1,   501,    -1,   502,    -1,   551,    -1,
     385,    -1,   497,    -1,   550,    -1,   108,    -1,   147,    -1,
     122,    -1,   116,   626,    -1,   154,   185,    -1,   154,   401,
     185,    -1,   117,    -1,   167,   151,   401,   182,    -1,   199,
     151,   401,   182,    -1,   627,   154,   185,    -1,   627,   154,
     504,   185,    -1,   402,    -1,   504,   105,   402,    -1,   506,
      -1,   524,    -1,   507,    -1,   521,    -1,   522,    -1,   155,
     626,   511,   128,    -1,   155,   626,   509,   511,   128,    -1,
     155,   626,   511,   194,   192,   626,   511,   194,    -1,   155,
     626,   511,   194,   508,   192,   626,   511,   194,    -1,   155,
     626,   509,   511,   194,   192,   626,   511,   194,    -1,   155,
     626,   509,   511,   194,   508,   192,   626,   511,   194,    -1,
     519,    -1,   508,   519,    -1,   510,    -1,   509,   510,    -1,
      35,   626,   511,   130,   511,   512,    -1,    -1,    35,    -1,
     181,   513,   181,    -1,    92,   515,    92,    -1,    -1,   514,
      -1,   132,    -1,   517,    -1,   514,   132,    -1,   514,   517,
      -1,    -1,   516,    -1,   131,    -1,   518,    -1,   516,   131,
      -1,   516,   518,    -1,    28,    -1,   520,    -1,     5,    -1,
     520,    -1,   506,    -1,    10,    -1,   523,    -1,   520,    -1,
       9,    -1,   121,    -1,   123,    -1,   151,   381,   182,    -1,
     210,    30,   211,    -1,   210,   211,    -1,   172,   625,   173,
      -1,   172,   625,     8,    -1,   101,     7,    -1,   525,    -1,
     526,    -1,   527,    -1,   528,    -1,   529,    -1,   530,    -1,
      43,   151,   380,   182,    -1,    21,   380,   182,    -1,    45,
     151,   401,   182,   151,   380,   182,    -1,    22,   380,   182,
      -1,    96,   151,   401,   182,   151,   380,   182,    -1,    70,
     151,   381,   182,    -1,    39,   151,   381,   182,    -1,    23,
     380,   182,    -1,    59,   151,   401,   182,   151,   380,   182,
      -1,   537,    -1,   537,   142,    -1,    93,   533,    -1,   535,
      -1,   535,   534,    -1,   208,   154,   185,    -1,   142,    -1,
     191,    -1,   174,    -1,   537,    -1,   538,    -1,   150,   154,
     185,    -1,   554,    -1,   557,    -1,   533,    -1,   536,   105,
     533,    -1,   626,    -1,   540,    -1,   546,    -1,   544,    -1,
     547,    -1,   545,    -1,   543,    -1,   542,    -1,   541,    -1,
     539,    -1,   222,   154,   185,    -1,    44,   154,   185,    -1,
      44,   154,   546,   185,    -1,    44,   154,   547,   185,    -1,
      70,   154,   185,    -1,    39,   154,   185,    -1,    59,   154,
     185,    -1,    59,   154,   625,   185,    -1,    59,   154,    29,
     185,    -1,    96,   154,   185,    -1,    96,   154,   626,   185,
      -1,    96,   154,   626,   105,   548,   185,    -1,    96,   154,
     191,   185,    -1,    96,   154,   191,   105,   548,   185,    -1,
      61,   154,   626,   185,    -1,    45,   154,   185,    -1,    45,
     154,   626,   185,    -1,    45,   154,   626,   105,   548,   185,
      -1,    45,   154,   626,   105,   549,   185,    -1,    45,   154,
     191,   185,    -1,    45,   154,   191,   105,   548,   185,    -1,
      45,   154,   191,   105,   549,   185,    -1,    62,   154,   626,
     185,    -1,   626,    -1,   626,   142,    -1,    29,    -1,   552,
      -1,   553,    -1,   626,   143,   147,    -1,    47,   368,   386,
      -1,   555,    -1,   556,    -1,    47,   154,   191,   185,    -1,
      47,   154,   185,    93,   533,    -1,    47,   154,   536,   185,
      93,   533,    -1,   154,   535,   185,    -1,    33,   217,   218,
      -1,    33,   217,   219,    -1,    33,   217,   220,    -1,   223,
     222,   402,   230,   402,    -1,   223,   222,   402,    93,   229,
     230,   402,    -1,   223,   222,   402,    93,   231,   230,   402,
      -1,   223,   222,   402,   215,   402,    -1,   223,   222,   402,
     216,   402,    -1,   223,   224,   402,   230,   402,    -1,   223,
     224,   402,    93,   229,   230,   402,    -1,   223,   224,   402,
      93,   231,   230,   402,    -1,   223,   224,   402,   215,   402,
      -1,   223,   224,   402,   216,   402,    -1,   221,   222,   402,
      -1,   221,   224,   402,    -1,   226,   222,   402,   234,   402,
      -1,   226,   227,   228,   222,   402,   234,   402,    -1,   225,
     222,   402,    93,   402,    -1,   233,   116,   564,   232,   402,
     184,   402,    -1,   565,    -1,   564,   105,   116,   565,    -1,
     626,   140,   402,    -1,   242,   151,   401,   182,   567,    -1,
     568,    -1,   567,   568,    -1,   243,   570,   569,    -1,   243,
     570,   154,   116,   626,   185,   569,    -1,   243,   570,   154,
     116,   626,   105,   116,   626,   185,   569,    -1,   243,   570,
     154,   116,   626,   105,   116,   626,   105,   116,   626,   185,
     569,    -1,   151,   401,   182,    -1,   490,    -1,   570,   207,
     490,    -1,   574,   572,    -1,    -1,   573,    -1,   592,    -1,
     573,   592,    -1,   575,    -1,   574,   260,   575,    -1,   576,
      -1,   575,   256,   576,    -1,   577,    -1,   576,   258,   145,
     577,    -1,   578,    -1,   257,   578,    -1,   582,   579,   580,
      -1,    -1,   597,    -1,    -1,   581,    -1,   280,   151,   401,
     182,    -1,   586,   583,    -1,   154,   571,   185,    -1,   584,
      -1,    -1,   619,    -1,   477,   151,   585,   182,    -1,    -1,
     571,    -1,   587,   588,    -1,   496,    -1,   151,   401,   182,
      -1,    -1,   589,    -1,   246,   590,    -1,   245,   591,    -1,
     268,    -1,    -1,    77,    -1,    -1,   284,    -1,   593,    -1,
     594,    -1,   595,    -1,   621,    -1,   618,    -1,   167,    -1,
     282,   462,   596,    -1,   251,   620,   596,    -1,   284,    -1,
     274,    -1,   267,    -1,   244,   598,    -1,   597,   244,   598,
      -1,   599,    -1,   600,    -1,   601,    -1,   616,    -1,   602,
      -1,   610,    -1,   603,    -1,   617,    -1,    98,   272,    -1,
      98,   261,    -1,   264,    -1,   279,    -1,   249,   272,    -1,
     249,   261,    -1,    56,   626,    29,    -1,   275,    -1,    54,
     275,    -1,   277,   604,    -1,   277,   154,   604,   605,   185,
      -1,    54,   277,    -1,   607,    -1,   111,    -1,    -1,   105,
     606,    -1,   607,    -1,   606,   105,   607,    -1,    95,    29,
     608,   609,    -1,    -1,   269,    29,    -1,    -1,   620,   263,
      -1,   276,   284,   611,   613,    -1,   276,   284,   111,   613,
      -1,    54,   276,   284,    -1,    95,    29,    -1,   154,   612,
     185,    -1,    29,    -1,   612,   105,    29,    -1,    -1,   614,
      -1,   615,    -1,   614,   615,    -1,   198,   611,    -1,   134,
     611,    -1,   262,    29,    -1,   281,    -1,    54,   281,    -1,
      95,   214,    -1,    95,   252,    -1,   253,   248,    -1,   265,
     620,   278,    -1,   254,   462,    -1,    95,   127,   462,    -1,
      95,    52,   462,    -1,   255,   462,   196,   462,    -1,   270,
     622,    -1,   250,   622,    -1,   273,    -1,   266,    -1,   283,
     248,   464,    -1,    29,    -1,    16,    -1,   626,    -1,   627,
      -1,    96,    -1,    39,    -1,    44,    -1,    45,    -1,   150,
      -1,    48,    -1,   222,    -1,    59,    -1,    61,    -1,    62,
      -1,    70,    -1,    73,    -1,    72,    -1,   208,    -1,   241,
      -1,   628,    -1,    24,    -1,   212,    -1,   125,    -1,    38,
      -1,   259,    -1,    37,    -1,   219,    -1,   218,    -1,   144,
      -1,    43,    -1,   257,    -1,   258,    -1,   272,    -1,   261,
      -1,   249,    -1,   283,    -1,   275,    -1,   277,    -1,   276,
      -1,   281,    -1,   253,    -1,   248,    -1,    77,    -1,   214,
      -1,   252,    -1,    52,    -1,   220,    -1,   233,    -1,   300,
      -1,   227,    -1,   200,    -1,   205,    -1,   204,    -1,   203,
      -1,   202,    -1,   201,    -1,    95,    -1,   109,    -1,   110,
      -1,   184,    -1,    46,    -1,    36,    -1,    66,    -1,    71,
      -1,    58,    -1,    53,    -1,    55,    -1,    76,    -1,    42,
      -1,   145,    -1,    51,    -1,   209,    -1,   168,    -1,   169,
      -1,   166,    -1,    69,    -1,    94,    -1,   114,    -1,   126,
      -1,   127,    -1,   104,    -1,    67,    -1,   133,    -1,   186,
      -1,    98,    -1,    93,    -1,   195,    -1,   124,    -1,   165,
      -1,    91,    -1,    50,    -1,   228,    -1,    99,    -1,   196,
      -1,   115,    -1,   157,    -1,   198,    -1,   148,    -1,   134,
      -1,    75,    -1,   100,    -1,   197,    -1,   149,    -1,   180,
      -1,   193,    -1,   158,    -1,   135,    -1,   129,    -1,   164,
      -1,   146,    -1,   163,    -1,    33,    -1,    40,    -1,    57,
      -1,   111,    -1,    41,    -1,    56,    -1,   213,    -1,    49,
      -1,    60,    -1,    34,    -1,    47,    -1,   271,    -1,   247,
      -1,   280,    -1,   282,    -1,   251,    -1,   265,    -1,   278,
      -1,   270,    -1,   250,    -1,   264,    -1,   279,    -1,   269,
      -1,   263,    -1,   262,    -1,   246,    -1,   245,    -1,   254,
      -1,   255,    -1,   284,    -1,   274,    -1,   273,    -1,   268,
      -1,   266,    -1,   267,    -1,   226,    -1,   232,    -1,   229,
      -1,   223,    -1,   216,    -1,   215,    -1,   217,    -1,   234,
      -1,   224,    -1,   225,    -1,   231,    -1,   221,    -1,   230,
      -1,    65,    -1,    63,    -1,    74,    -1,   167,    -1,   199,
      -1,   240,    -1,   235,    -1,   238,    -1,   239,    -1,   236,
      -1,   237,    -1,   242,    -1,   243,    -1,   244,    -1,    64,
      -1,   293,    -1,   291,    -1,   292,    -1,   297,    -1,   298,
      -1,   299,    -1,   294,    -1,   295,    -1,   296,    -1,    78,
      -1,    79,    -1,    80,    -1,    81,    -1,    82,    -1,    83,
      -1,    84,    -1,    85,    -1,    86,    -1,    87,    -1,    88,
      -1,   285,    -1,   286,    -1,   287,    -1,   288,    -1,   289,
      -1,   290,    -1,   301,    -1,   302,    -1,   303,    -1,   304,
      -1,   305,    -1,   306,    -1,   307,    -1,    89,    -1,   103,
      -1,   112,    -1,   170,    -1,   178,    -1,   187,    -1,   136,
      -1,    90,    -1,   113,    -1,   137,    -1,   179,    -1,   624,
     119,   625,    -1,    25,    -1
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
     513,   519,   526,   531,   537,   544,   552,   554,   557,   561,
     565,   574,   584,   586,   590,   592,   595,   598,   602,   614,
     629,   643,   666,   668,   670,   672,   673,   675,   677,   678,
     680,   683,   685,   688,   690,   692,   694,   696,   698,   700,
     702,   704,   706,   708,   710,   712,   716,   719,   723,   727,
     730,   734,   737,   741,   745,   750,   753,   757,   762,   768,
     774,   777,   782,   788,   792,   796,   799,   802,   811,   815,
     817,   820,   824,   832,   843,   857,   859,   863,   865,   867,
     869,   871,   873,   875,   877,   879,   881,   883,   885,   887,
     889,   892,   895,   898,   901,   903,   905,   908,   913,   917,
     923,   928,   932,   934,   936,   938,   940,   942,   944,   946,
     948,   950,   953,   957,   959,   964,   968,   974,   979,   986,
     991,   998,  1004,  1012,  1017,  1023,  1029,  1036,  1040,  1044,
    1047,  1049,  1053,  1058,  1064,  1068,  1075,  1080,  1086,  1088,
    1091,  1095,  1097,  1100,  1102,  1109,  1113,  1117,  1120,  1124,
    1126,  1130,  1133,  1137,  1140,  1144,  1149,  1151,  1155,  1157,
    1160,  1162,  1164,  1166,  1169,  1172,  1175,  1179,  1181,  1183,
    1186,  1189,  1192,  1198,  1204,  1206,  1211,  1215,  1220,  1229,
    1231,  1234,  1238,  1241,  1245,  1254,  1256,  1259,  1263,  1272,
    1283,  1292,  1303,  1305,  1308,  1313,  1321,  1323,  1326,  1331,
    1339,  1348,  1350,  1354,  1356,  1360,  1362,  1366,  1370,  1374,
    1378,  1379,  1384,  1388,  1392,  1396,  1398,  1404,  1405,  1407,
    1409,  1413,  1415,  1419,  1423,  1425,  1429,  1433,  1437,  1441,
    1443,  1447,  1451,  1453,  1457,  1461,  1463,  1468,  1470,  1475,
    1477,  1482,  1484,  1489,  1491,  1494,  1496,  1498,  1501,  1504,
    1506,  1508,  1510,  1512,  1514,  1516,  1518,  1520,  1522,  1524,
    1526,  1528,  1533,  1539,  1545,  1552,  1556,  1561,  1563,  1566,
    1570,  1573,  1576,  1578,  1581,  1584,  1586,  1588,  1590,  1594,
    1598,  1600,  1602,  1604,  1607,  1609,  1612,  1615,  1617,  1620,
    1623,  1626,  1629,  1632,  1635,  1638,  1640,  1643,  1646,  1648,
    1651,  1654,  1657,  1660,  1663,  1665,  1667,  1669,  1671,  1673,
    1675,  1677,  1679,  1681,  1684,  1688,  1693,  1695,  1698,  1702,
    1704,  1706,  1708,  1710,  1712,  1714,  1716,  1718,  1720,  1722,
    1724,  1726,  1728,  1730,  1732,  1735,  1738,  1742,  1744,  1749,
    1754,  1758,  1763,  1765,  1769,  1771,  1773,  1775,  1777,  1779,
    1784,  1790,  1799,  1809,  1819,  1830,  1832,  1835,  1837,  1840,
    1847,  1848,  1850,  1854,  1858,  1859,  1861,  1863,  1865,  1868,
    1871,  1872,  1874,  1876,  1878,  1881,  1884,  1886,  1888,  1890,
    1892,  1894,  1896,  1898,  1900,  1902,  1904,  1906,  1910,  1914,
    1917,  1921,  1925,  1928,  1930,  1932,  1934,  1936,  1938,  1940,
    1945,  1949,  1957,  1961,  1969,  1974,  1979,  1983,  1991,  1993,
    1996,  1999,  2001,  2004,  2008,  2010,  2012,  2014,  2016,  2018,
    2022,  2024,  2026,  2028,  2032,  2034,  2036,  2038,  2040,  2042,
    2044,  2046,  2048,  2050,  2052,  2056,  2060,  2065,  2070,  2074,
    2078,  2082,  2087,  2092,  2096,  2101,  2108,  2113,  2120,  2125,
    2129,  2134,  2141,  2148,  2153,  2160,  2167,  2172,  2174,  2177,
    2179,  2181,  2183,  2187,  2191,  2193,  2195,  2200,  2206,  2213,
    2217,  2221,  2225,  2229,  2235,  2243,  2251,  2257,  2263,  2269,
    2277,  2285,  2291,  2297,  2301,  2305,  2311,  2319,  2325,  2333,
    2335,  2340,  2344,  2350,  2352,  2355,  2359,  2367,  2378,  2392,
    2396,  2398,  2402,  2405,  2406,  2408,  2410,  2413,  2415,  2419,
    2421,  2425,  2427,  2432,  2434,  2437,  2441,  2442,  2444,  2445,
    2447,  2452,  2455,  2459,  2461,  2462,  2464,  2469,  2470,  2472,
    2475,  2477,  2481,  2482,  2484,  2487,  2490,  2492,  2493,  2495,
    2496,  2498,  2500,  2502,  2504,  2506,  2508,  2510,  2514,  2518,
    2520,  2522,  2524,  2527,  2531,  2533,  2535,  2537,  2539,  2541,
    2543,  2545,  2547,  2550,  2553,  2555,  2557,  2560,  2563,  2567,
    2569,  2572,  2575,  2581,  2584,  2586,  2588,  2589,  2592,  2594,
    2598,  2603,  2604,  2607,  2608,  2611,  2616,  2621,  2625,  2628,
    2632,  2634,  2638,  2639,  2641,  2643,  2646,  2649,  2652,  2655,
    2657,  2660,  2663,  2666,  2669,  2673,  2676,  2680,  2684,  2689,
    2692,  2695,  2697,  2699,  2703,  2705,  2707,  2709,  2711,  2713,
    2715,  2717,  2719,  2721,  2723,  2725,  2727,  2729,  2731,  2733,
    2735,  2737,  2739,  2741,  2743,  2745,  2747,  2749,  2751,  2753,
    2755,  2757,  2759,  2761,  2763,  2765,  2767,  2769,  2771,  2773,
    2775,  2777,  2779,  2781,  2783,  2785,  2787,  2789,  2791,  2793,
    2795,  2797,  2799,  2801,  2803,  2805,  2807,  2809,  2811,  2813,
    2815,  2817,  2819,  2821,  2823,  2825,  2827,  2829,  2831,  2833,
    2835,  2837,  2839,  2841,  2843,  2845,  2847,  2849,  2851,  2853,
    2855,  2857,  2859,  2861,  2863,  2865,  2867,  2869,  2871,  2873,
    2875,  2877,  2879,  2881,  2883,  2885,  2887,  2889,  2891,  2893,
    2895,  2897,  2899,  2901,  2903,  2905,  2907,  2909,  2911,  2913,
    2915,  2917,  2919,  2921,  2923,  2925,  2927,  2929,  2931,  2933,
    2935,  2937,  2939,  2941,  2943,  2945,  2947,  2949,  2951,  2953,
    2955,  2957,  2959,  2961,  2963,  2965,  2967,  2969,  2971,  2973,
    2975,  2977,  2979,  2981,  2983,  2985,  2987,  2989,  2991,  2993,
    2995,  2997,  2999,  3001,  3003,  3005,  3007,  3009,  3011,  3013,
    3015,  3017,  3019,  3021,  3023,  3025,  3027,  3029,  3031,  3033,
    3035,  3037,  3039,  3041,  3043,  3045,  3047,  3049,  3051,  3053,
    3055,  3057,  3059,  3061,  3063,  3065,  3067,  3069,  3071,  3073,
    3075,  3077,  3079,  3081,  3083,  3085,  3087,  3089,  3091,  3093,
    3095,  3097,  3099,  3101,  3103,  3105,  3107,  3109,  3111,  3113,
    3115,  3117,  3119,  3121,  3123,  3125,  3127,  3129,  3131,  3133,
    3135,  3137,  3139,  3143
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
    1813,  1818,  1823,  1828,  1836,  1843,  1854,  1859,  1869,  1877,
    1885,  1893,  1901,  1908,  1916,  1924,  1935,  1939,  1948,  1952,
    1959,  1967,  1978,  1984,  1993,  1998,  2005,  2012,  2023,  2033,
    2043,  2053,  2071,  2091,  2096,  2101,  2108,  2113,  2118,  2125,
    2130,  2142,  2149,  2161,  2162,  2163,  2164,  2165,  2166,  2167,
    2169,  2170,  2171,  2172,  2173,  2178,  2183,  2191,  2208,  2216,
    2224,  2231,  2238,  2245,  2252,  2262,  2274,  2287,  2299,  2315,
    2323,  2331,  2339,  2354,  2359,  2367,  2381,  2398,  2423,  2431,
    2438,  2449,  2455,  2461,  2472,  2487,  2492,  2507,  2508,  2509,
    2510,  2511,  2512,  2517,  2518,  2521,  2522,  2523,  2524,  2525,
    2530,  2544,  2552,  2557,  2565,  2570,  2575,  2583,  2592,  2604,
    2614,  2627,  2635,  2636,  2637,  2642,  2643,  2644,  2645,  2646,
    2651,  2658,  2668,  2676,  2683,  2693,  2703,  2713,  2723,  2733,
    2743,  2753,  2763,  2774,  2783,  2793,  2803,  2819,  2828,  2837,
    2845,  2851,  2863,  2871,  2881,  2889,  2901,  2907,  2918,  2920,
    2924,  2932,  2936,  2941,  2945,  2949,  2953,  2963,  2971,  2978,
    2984,  2995,  2999,  3008,  3016,  3022,  3032,  3038,  3048,  3052,
    3062,  3068,  3074,  3080,  3089,  3098,  3107,  3120,  3124,  3132,
    3138,  3148,  3156,  3165,  3178,  3185,  3197,  3201,  3213,  3220,
    3226,  3235,  3242,  3248,  3259,  3266,  3272,  3281,  3290,  3297,
    3308,  3315,  3327,  3333,  3345,  3351,  3362,  3368,  3379,  3385,
    3396,  3405,  3409,  3418,  3422,  3430,  3434,  3444,  3451,  3460,
    3470,  3469,  3483,  3492,  3501,  3514,  3518,  3531,  3534,  3541,
    3545,  3554,  3558,  3562,  3571,  3575,  3581,  3587,  3593,  3604,
    3608,  3612,  3620,  3624,  3630,  3640,  3644,  3654,  3658,  3668,
    3672,  3682,  3686,  3696,  3700,  3708,  3712,  3716,  3720,  3730,
    3734,  3738,  3746,  3750,  3754,  3758,  3762,  3766,  3774,  3778,
    3782,  3790,  3794,  3798,  3802,  3813,  3819,  3829,  3835,  3845,
    3849,  3853,  3891,  3895,  3905,  3915,  3928,  3937,  3947,  3951,
    3960,  3964,  3973,  3979,  3987,  3993,  4005,  4011,  4021,  4025,
    4029,  4033,  4037,  4043,  4049,  4057,  4061,  4069,  4073,  4084,
    4088,  4092,  4098,  4102,  4116,  4120,  4128,  4132,  4142,  4146,
    4150,  4154,  4163,  4167,  4171,  4175,  4183,  4189,  4199,  4207,
    4211,  4215,  4219,  4223,  4227,  4231,  4235,  4239,  4249,  4257,
    4261,  4269,  4276,  4283,  4294,  4302,  4306,  4314,  4322,  4330,
    4384,  4388,  4401,  4407,  4417,  4421,  4429,  4433,  4437,  4445,
    4455,  4465,  4475,  4485,  4495,  4510,  4516,  4527,  4533,  4544,
    4555,  4557,  4561,  4566,  4576,  4579,  4586,  4592,  4598,  4606,
    4619,  4622,  4629,  4635,  4641,  4648,  4659,  4663,  4673,  4677,
    4687,  4691,  4695,  4700,  4709,  4715,  4721,  4727,  4735,  4740,
    4748,  4753,  4761,  4769,  4774,  4779,  4784,  4789,  4794,  4803,
    4811,  4815,  4832,  4836,  4844,  4852,  4860,  4864,  4872,  4878,
    4888,  4896,  4900,  4904,  4939,  4945,  4951,  4961,  4965,  4969,
    4973,  4977,  4984,  4990,  5000,  5008,  5012,  5016,  5020,  5024,
    5028,  5032,  5036,  5040,  5048,  5056,  5060,  5064,  5074,  5082,
    5090,  5094,  5098,  5106,  5110,  5116,  5122,  5126,  5136,  5144,
    5148,  5154,  5163,  5172,  5178,  5184,  5194,  5211,  5218,  5233,
    5269,  5273,  5281,  5289,  5301,  5305,  5313,  5321,  5325,  5336,
    5353,  5359,  5365,  5375,  5379,  5385,  5391,  5395,  5401,  5405,
    5411,  5417,  5424,  5434,  5439,  5447,  5453,  5463,  5485,  5494,
    5500,  5513,  5527,  5534,  5540,  5550,  5555,  5560,  5570,  5584,
    5592,  5598,  5616,  5625,  5628,  5635,  5640,  5648,  5652,  5659,
    5663,  5670,  5674,  5681,  5685,  5694,  5707,  5710,  5718,  5721,
    5729,  5737,  5745,  5749,  5757,  5760,  5768,  5780,  5783,  5791,
    5803,  5809,  5819,  5822,  5830,  5834,  5838,  5846,  5849,  5857,
    5860,  5868,  5872,  5876,  5880,  5884,  5892,  5900,  5912,  5924,
    5928,  5932,  5940,  5946,  5956,  5960,  5964,  5968,  5972,  5976,
    5980,  5984,  5992,  5996,  6000,  6004,  6012,  6018,  6028,  6038,
    6042,  6050,  6060,  6071,  6078,  6082,  6090,  6093,  6100,  6105,
    6114,  6124,  6127,  6135,  6138,  6146,  6155,  6162,  6172,  6176,
    6183,  6189,  6199,  6202,  6209,  6214,  6226,  6234,  6246,  6254,
    6258,  6266,  6270,  6274,  6282,  6290,  6294,  6298,  6302,  6310,
    6318,  6330,  6334,  6342,  6355,  6359,  6360,  6373,  6374,  6375,
    6376,  6377,  6378,  6379,  6380,  6381,  6382,  6383,  6384,  6385,
    6386,  6387,  6388,  6392,  6393,  6394,  6395,  6396,  6397,  6398,
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
    6539,  6540,  6541,  6542,  6543,  6544,  6545,  6546,  6547,  6548,
    6549,  6550,  6551,  6552,  6553,  6554,  6555,  6556,  6557,  6558,
    6559,  6560,  6561,  6562,  6563,  6564,  6565,  6566,  6567,  6568,
    6569,  6570,  6571,  6572,  6573,  6574,  6575,  6576,  6577,  6578,
    6579,  6580,  6581,  6582,  6583,  6584,  6585,  6586,  6587,  6588,
    6589,  6590,  6595,  6602
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
  const int xquery_parser::yylast_ = 13017;
  const int xquery_parser::yynnts_ = 307;
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
#line 16217 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6606 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"


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

