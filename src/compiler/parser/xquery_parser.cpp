/* A Bison parser, made by GNU Bison 2.5.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2011 Free Software Foundation, Inc.
   
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

/* Line 293 of lalr1.cc  */
#line 87 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"


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



/* Line 293 of lalr1.cc  */
#line 77 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 910 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 299 of lalr1.cc  */
#line 1035 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 299 of lalr1.cc  */
#line 107 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                               \
 do                                                                    \
   if (N)                                                              \
     {                                                                 \
       (Current).begin = YYRHSLOC (Rhs, 1).begin;                      \
       (Current).end   = YYRHSLOC (Rhs, N).end;                        \
     }                                                                 \
   else                                                                \
     {                                                                 \
       (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;        \
     }                                                                 \
 while (false)
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


namespace zorba {

/* Line 382 of lalr1.cc  */
#line 193 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"

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
#line 908 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 298 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 124: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 307 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 149: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 906 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 316 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 325 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 334 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 343 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 352 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 361 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 370 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 379 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 388 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 397 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 406 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 415 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 424 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 433 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 442 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 451 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 460 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 469 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 478 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 487 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 496 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 505 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 514 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 523 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 532 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 541 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 550 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 559 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 568 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 577 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 586 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 595 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 604 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 613 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 622 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 631 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 640 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 649 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 658 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 667 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 676 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 685 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 694 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 703 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 712 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 721 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 730 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 739 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 748 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 757 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 775 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 784 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 820 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 829 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 838 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 847 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 856 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 865 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 874 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 901 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 910 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 919 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 937 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 946 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 955 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 964 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 973 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 982 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 991 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1000 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1009 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1018 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1027 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1036 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1045 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1054 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1063 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1072 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1081 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1090 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1099 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1108 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1117 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1126 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1135 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1144 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1153 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1162 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1171 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1180 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1189 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1198 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1207 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1216 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1225 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1234 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1243 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1252 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1261 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1270 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1279 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1288 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1297 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1306 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1315 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1324 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1333 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1342 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1351 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1360 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1369 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1378 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1387 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1396 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1405 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1414 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1423 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1432 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1441 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1450 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1459 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1468 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1477 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1486 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1495 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1504 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1513 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1522 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1531 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1540 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "SimpleMapExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1549 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1558 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1567 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1576 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1585 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1594 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1603 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1612 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1621 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1630 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1639 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1648 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1657 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1666 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1675 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1684 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1693 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1702 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1711 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1720 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1729 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1738 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1747 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1756 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1765 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1774 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1783 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1792 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1801 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1810 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1819 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1828 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1837 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1846 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1855 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1864 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1873 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1882 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1891 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1900 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1909 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1918 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1927 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1936 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1945 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1954 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1963 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1972 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1981 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1990 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1999 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2008 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2017 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2026 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2035 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2044 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2053 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2062 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2071 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2080 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2089 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2098 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2107 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "SimpleType" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2116 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2125 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2134 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2143 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2152 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2161 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2170 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2179 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2188 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2197 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2206 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2215 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2224 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2233 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2242 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2251 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2260 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2269 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2278 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2287 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2296 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2305 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2314 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2323 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2332 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2341 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2350 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2359 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2368 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2377 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2386 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2395 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2404 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2413 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2422 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2431 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2440 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2449 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2458 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2467 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2476 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2485 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2494 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2503 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2512 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2521 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2530 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2539 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2548 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 613: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2557 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 614: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2566 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 615: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2575 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2584 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2593 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2602 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 624: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2611 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 625: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2620 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2629 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 630: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2638 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 631: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2647 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 632: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2656 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 633: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2665 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 634: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2674 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 635: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2683 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 636: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2692 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 637: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2701 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 638: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2710 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 639: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2719 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 640: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2728 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 641: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2737 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 642: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2746 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 643: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2755 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 644: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2764 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 645: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2773 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 646: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2782 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 647: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2791 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 654: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2800 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 655: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2809 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 656: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2818 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
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

  inline bool
  xquery_parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  xquery_parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

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
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 565 of lalr1.cc  */
#line 140 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 565 of lalr1.cc  */
#line 2915 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"

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
    if (yy_pact_value_is_default_ (yyn))
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
	if (yy_table_value_is_error_ (yyn))
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

/* Line 690 of lalr1.cc  */
#line 1053 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 1057 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 1061 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 1069 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 1075 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 1084 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 1090 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 1098 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 1104 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 1115 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 1120 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 1128 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 1135 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 1142 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 1151 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 1158 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 1166 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 1174 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 1182 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 1193 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 1198 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 1205 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 1212 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 1224 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 1234 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 1241 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 1248 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      // error
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 1283 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 1288 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 1296 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 1304 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1312 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1317 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1325 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1330 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1338 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1343 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1351 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 1356 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 1361 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1366 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 1379 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 1389 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 1394 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1402 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1410 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1421 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1428 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1439 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1444 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1452 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 1459 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1466 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1475 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1488 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 1496 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1503 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 1513 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 1520 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 1527 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 1550 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1556 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1565 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1572 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1582 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1591 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1592 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1593 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1594 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1595 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1596 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1597 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1598 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1599 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1600 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1606 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1614 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1622 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1630 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1637 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1645 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1652 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1657 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1665 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1673 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 111:

/* Line 690 of lalr1.cc  */
#line 1687 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 112:

/* Line 690 of lalr1.cc  */
#line 1701 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 113:

/* Line 690 of lalr1.cc  */
#line 1718 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 1723 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1731 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1739 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1750 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1755 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1764 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1769 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1776 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1781 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1791 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1796 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1805 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1811 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1824 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1829 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1837 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 130:

/* Line 690 of lalr1.cc  */
#line 1848 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 131:

/* Line 690 of lalr1.cc  */
#line 1863 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 132:

/* Line 690 of lalr1.cc  */
#line 1875 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 133:

/* Line 690 of lalr1.cc  */
#line 1890 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1895 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1900 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1905 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1913 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1920 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1936 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1946 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1955 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1964 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1973 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1985 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1989 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1995 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1999 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 2009 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);

      static_cast<AST_IndexDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(8) - (1)].sval)) );
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 2019 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(9) - (4)].expr)),
                             (yysemantic_stack_[(9) - (7)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (9)].node)),
                             static_cast<AnnotationListParsenode*>((yysemantic_stack_[(9) - (2)].node)));

      static_cast<AST_IndexDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(9) - (1)].sval)) );
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 2032 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 2038 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 2047 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 2052 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 2059 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 2066 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 2078 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 2088 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 2098 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 2109 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 161:

/* Line 690 of lalr1.cc  */
#line 2125 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 162:

/* Line 690 of lalr1.cc  */
#line 2145 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 2149 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 2153 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 2161 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 2165 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 2169 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 2177 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 2182 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 2194 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 2201 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 2230 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 2235 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 2243 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 187:

/* Line 690 of lalr1.cc  */
#line 2260 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 2268 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 2276 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 2283 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 2290 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 2301 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)),
                                          NULL,  // no type
                                          NULL,  // no init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 2310 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                                          dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)), // type
                                          NULL,  // no init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 2319 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                          NULL,  // no type
                                          (yysemantic_stack_[(4) - (4)].expr),    // init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 2328 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                          dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)), // type
                                          (yysemantic_stack_[(5) - (5)].expr),    // init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 2341 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 2349 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 2357 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 2365 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 200:

/* Line 690 of lalr1.cc  */
#line 2380 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2385 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 2393 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 203:

/* Line 690 of lalr1.cc  */
#line 2407 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 204:

/* Line 690 of lalr1.cc  */
#line 2424 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 205:

/* Line 690 of lalr1.cc  */
#line 2449 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 2457 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 2464 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 2475 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 2485 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2490 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 211:

/* Line 690 of lalr1.cc  */
#line 2503 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (1)].expr); // to prevent the Bison warning
      (yyval.expr) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected ExprSingle (missing comma \",\" between expressions?)");
      delete (yysemantic_stack_[(3) - (1)].expr); // these need to be deleted here because the parser deallocator will skip them
      delete (yysemantic_stack_[(3) - (3)].expr);
      YYABORT;
    }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 2546 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2560 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 2568 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 2573 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 2581 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 2586 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2591 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2599 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2608 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2620 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2630 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2643 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 250:

/* Line 690 of lalr1.cc  */
#line 2667 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 251:

/* Line 690 of lalr1.cc  */
#line 2674 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 2684 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 2690 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected QName \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (3)].node);
      YYERROR;
    }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2699 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL; // to prevent the Bison warning
      error((yylocation_stack_[(2) - (2)]), ""); // the error message is already set in the driver's parseError member
      YYERROR;
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2709 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2716 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2724 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (3)]), "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yysemantic_stack_[(3) - (3)].node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (1)].node);
      YYERROR;
    }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2736 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 259:

/* Line 690 of lalr1.cc  */
#line 2746 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 260:

/* Line 690 of lalr1.cc  */
#line 2756 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 261:

/* Line 690 of lalr1.cc  */
#line 2766 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 262:

/* Line 690 of lalr1.cc  */
#line 2776 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 263:

/* Line 690 of lalr1.cc  */
#line 2786 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 264:

/* Line 690 of lalr1.cc  */
#line 2796 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 265:

/* Line 690 of lalr1.cc  */
#line 2806 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 266:

/* Line 690 of lalr1.cc  */
#line 2817 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 2826 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 268:

/* Line 690 of lalr1.cc  */
#line 2836 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 269:

/* Line 690 of lalr1.cc  */
#line 2846 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 270:

/* Line 690 of lalr1.cc  */
#line 2862 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 2871 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 2880 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2894 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2906 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2914 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2924 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2932 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2944 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2950 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2963 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2967 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2975 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2979 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 2988 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 2992 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 2996 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 3006 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 3014 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 3021 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 3027 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 3037 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 3041 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 3045 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 3053 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 3061 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 3069 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         NULL,
                         NULL,
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 3081 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 3089 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 3095 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 3105 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 3111 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 3121 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 3125 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 3135 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 3141 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 3147 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 3153 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 3162 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 3171 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 3180 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 3193 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 3197 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 3205 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 3211 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 3221 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 3229 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 3238 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 3251 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 3258 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 3270 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 3274 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 3286 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 3293 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 3299 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 3308 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 3315 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 3321 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 3332 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 3339 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 3345 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 3354 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 3363 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 3370 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 3381 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 3388 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 3400 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 3406 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 3418 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 3424 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 3435 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 3441 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 3452 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 3458 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 3469 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 3478 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 3482 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 3491 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 3495 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 3503 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 3507 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 354:

/* Line 690 of lalr1.cc  */
#line 3517 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3524 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3533 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3542 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 3547 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3556 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 3565 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 3574 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3587 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 3591 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 3603 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 3607 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 3614 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3618 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 368:

/* Line 690 of lalr1.cc  */
#line 3625 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3629 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3638 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3642 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3646 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3654 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3658 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3664 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3670 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3676 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3686 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3690 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3694 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3702 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3706 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3712 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3722 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3726 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3736 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3740 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3750 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3754 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3764 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3768 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3778 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3782 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3791 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3795 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3803 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3807 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3811 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3815 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3825 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3829 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3833 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3840 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3845 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3853 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3857 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3861 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3865 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3869 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3873 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3881 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3889 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3897 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3901 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3905 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3909 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3920 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3926 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3936 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3942 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3952 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3956 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 3960 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 3998 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 4002 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 4012 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 4022 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 4035 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 4044 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 431:

/* Line 690 of lalr1.cc  */
#line 4054 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 4058 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 4067 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 4071 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 4080 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 4086 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 4094 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 4100 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 4112 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 4118 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 4128 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 4132 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 4136 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 4140 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 4144 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 4150 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 4156 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 4164 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 4168 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 4176 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 4180 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 4191 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 4195 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 4199 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 4205 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 4209 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 4223 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 4227 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 4235 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 4239 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 4249 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 4253 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 4257 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 4261 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 4270 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 4274 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 4278 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 4282 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 4290 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 4296 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 4306 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 4314 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 4318 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 4322 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 4326 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 4330 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 4334 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 4338 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 4342 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 4346 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 4350 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 4355 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 4359 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 4363 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 4367 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 4375 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 4379 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 4387 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 4394 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 4401 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 4412 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 4420 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 4424 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 4432 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 4440 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 4448 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 4502 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 4506 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 4519 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 4525 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 4535 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 4539 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 4547 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 4551 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 4555 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 4563 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 507:

/* Line 690 of lalr1.cc  */
#line 4573 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 508:

/* Line 690 of lalr1.cc  */
#line 4583 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            if (static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr))->get_qname())
            {
              error((yylocation_stack_[(8) - (1)]), "syntax error, end tag </" + static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr))->get_qname().str() + "> does not match start tag <"
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

  case 509:

/* Line 690 of lalr1.cc  */
#line 4600 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            if (static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname())
            {
              error((yylocation_stack_[(9) - (1)]), "syntax error, end tag </" + static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname().str() + "> does not match start tag <"
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

  case 510:

/* Line 690 of lalr1.cc  */
#line 4617 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            if (static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname())
            {
              error((yylocation_stack_[(9) - (1)]), "syntax error, end tag </" + static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname().str() + "> does not match start tag <"
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

  case 511:

/* Line 690 of lalr1.cc  */
#line 4634 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            if (static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname())
            {
              error((yylocation_stack_[(10) - (1)]), "syntax error, end tag </" + static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname().str() + "> does not match start tag <"
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

  case 512:

/* Line 690 of lalr1.cc  */
#line 4656 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 4662 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 4673 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 4679 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 4690 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 4707 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 4712 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 4721 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 4725 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 4732 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 4738 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 4744 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 4752 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 4764 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 4768 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 4775 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 4781 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 4787 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 4794 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 4805 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 4809 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 4819 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 4823 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 4833 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 4837 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 4841 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 4846 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 4855 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 4861 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 4867 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 4873 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 4881 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 4886 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 4894 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 4899 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 4907 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 4915 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 4920 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 4925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 4930 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 4935 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 4940 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 4949 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 4957 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 4961 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 4978 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 4982 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 4990 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 4998 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 5006 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 5010 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 5018 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 5026 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 5030 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 5034 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 5069 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 5075 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 5081 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 5091 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 5095 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 5099 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 5103 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 5107 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 5111 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 5115 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 5122 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 5128 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 5138 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 5146 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 5154 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 5158 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 5162 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 5166 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 5170 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 5174 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 5178 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 5182 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 5186 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 5194 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 5202 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 5206 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 5210 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 5220 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 5228 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 5236 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 5240 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 5244 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 5252 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 5256 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 5262 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 5268 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 5272 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 5282 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 5290 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 5294 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 5300 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 5309 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 5318 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 5324 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 5330 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 5340 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 5357 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 5364 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 5379 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 5415 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 5419 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 5427 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 5435 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 5447 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 5451 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 5459 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 5467 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 5471 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 5482 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 5499 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 5505 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 5511 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 5521 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 5525 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 5531 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 5537 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 5541 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 5547 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 5551 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 5557 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 5563 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 5570 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 5580 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 5585 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 5593 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 5599 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 5609 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 5631 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 5640 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 5646 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 5659 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 5673 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 5680 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 5686 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 5696 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 5705 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 5713 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 5719 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 5737 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 5745 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 5749 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 5756 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 5761 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 5769 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 5773 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 5780 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 5784 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 5791 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 5795 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 5802 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 5806 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 5815 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 5827 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 5831 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 5838 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 5842 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 5850 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 5858 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 5866 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 5870 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 5877 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 5881 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 5889 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 5900 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 5904 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 5912 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 5924 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 5930 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 5939 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 5943 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 5951 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 5955 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 5959 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 5966 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 5970 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 5977 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 5981 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 5989 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 5993 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 5997 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 6001 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 6005 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 6013 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 6021 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 6033 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 6045 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 6049 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 6053 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 6061 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 6067 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 6077 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 6081 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 6085 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 6089 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 6093 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 6097 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 6101 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 6105 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 6113 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 6117 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 6121 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 6125 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 6133 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 6139 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 6149 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 6159 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 6163 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 6171 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 727:

/* Line 690 of lalr1.cc  */
#line 6181 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 728:

/* Line 690 of lalr1.cc  */
#line 6192 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 6199 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 6203 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 6210 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 6214 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 6221 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 6226 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 6235 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 6244 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 6248 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 6255 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 6259 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 6267 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 6276 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 6283 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 6293 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 6297 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 6304 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 6310 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 6319 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 6323 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 6330 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 6335 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 6347 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 6355 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 6367 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 6375 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 6379 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 6387 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 6391 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 6395 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 6403 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 6411 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 6415 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 6419 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 6423 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 6431 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 6439 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 6451 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 6455 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 6463 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 6477 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 6481 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 6488 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 6493 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 6501 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 6506 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 6515 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 6523 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 6529 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 6539 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 6545 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 780:

/* Line 690 of lalr1.cc  */
#line 6555 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 6562 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 6569 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 783:

/* Line 690 of lalr1.cc  */
#line 6594 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 784:

/* Line 690 of lalr1.cc  */
#line 6622 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 785:

/* Line 690 of lalr1.cc  */
#line 6650 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 6654 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 6658 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 6665 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 789:

/* Line 690 of lalr1.cc  */
#line 6672 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 6679 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 793:

/* Line 690 of lalr1.cc  */
#line 6696 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 795:

/* Line 690 of lalr1.cc  */
#line 6709 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 796:

/* Line 690 of lalr1.cc  */
#line 6710 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 6711 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 798:

/* Line 690 of lalr1.cc  */
#line 6712 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 6713 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 6714 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 6715 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 802:

/* Line 690 of lalr1.cc  */
#line 6716 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 803:

/* Line 690 of lalr1.cc  */
#line 6717 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 6718 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 805:

/* Line 690 of lalr1.cc  */
#line 6719 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 6720 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 6721 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 6722 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 6723 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 6728 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 6729 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 6730 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 6731 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 6732 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 6733 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 6734 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 6735 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 6736 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 6737 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 6738 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 6739 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 6740 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 6741 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 6742 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 6743 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 6744 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 6745 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 6746 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 6747 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 6748 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 6749 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 6750 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 6751 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 6752 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 6753 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 6754 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 6755 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 6756 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 6757 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 6758 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 6759 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 6760 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 6761 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 6762 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 6763 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 6764 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 6765 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 6766 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 6767 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 6768 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 6769 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 6770 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 6771 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 6772 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 6773 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 6774 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 6775 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 6776 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 6777 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 6778 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 6779 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 6780 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 6781 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 6782 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 6783 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 6784 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 6785 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 6786 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 6787 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 6788 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 6789 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 6790 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 6791 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 6792 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 6793 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 6794 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 6795 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 6796 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 6797 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 6798 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 6799 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 6800 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 6801 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 6802 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 6803 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 6804 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 6805 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 6806 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 6807 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 6808 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 6809 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 6810 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 6811 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 6812 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 6813 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 6814 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 6815 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 6816 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 6817 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 6818 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 6819 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 6820 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 6821 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 6822 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 6823 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 6824 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 6825 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 6826 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 6827 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 6828 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 6829 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 6830 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 6831 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 6832 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 6833 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 6834 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 6835 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 6836 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 6837 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 6838 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 6839 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 6840 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 6841 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 6842 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 6843 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 6844 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 6845 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 6846 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 6847 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 6848 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 6849 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 6850 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 6851 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 6852 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 6853 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 6854 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 6855 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 6856 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 6857 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 6858 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 6859 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 6860 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 6861 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 6862 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 6863 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 6864 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 6865 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 6866 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 6867 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 6868 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 6869 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 6870 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 6871 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 6872 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 6873 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 6874 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 6875 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 6876 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 6877 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 6878 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 6879 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 6880 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 6881 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 6882 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 6883 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 6884 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 6885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 6886 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 6887 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 6888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 6889 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 6890 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 6891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 6892 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 6893 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 6894 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 6895 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 6896 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 6897 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 6898 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 6899 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 6900 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 6901 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 6902 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 6903 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 6904 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 6905 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 6906 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 6907 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 6908 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 6909 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 6910 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 6911 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 6912 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 6913 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 997:

/* Line 690 of lalr1.cc  */
#line 6914 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 998:

/* Line 690 of lalr1.cc  */
#line 6915 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 999:

/* Line 690 of lalr1.cc  */
#line 6916 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 1000:

/* Line 690 of lalr1.cc  */
#line 6917 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 1001:

/* Line 690 of lalr1.cc  */
#line 6918 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 1002:

/* Line 690 of lalr1.cc  */
#line 6919 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1003:

/* Line 690 of lalr1.cc  */
#line 6920 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1004:

/* Line 690 of lalr1.cc  */
#line 6921 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1005:

/* Line 690 of lalr1.cc  */
#line 6922 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1006:

/* Line 690 of lalr1.cc  */
#line 6923 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1007:

/* Line 690 of lalr1.cc  */
#line 6924 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1008:

/* Line 690 of lalr1.cc  */
#line 6925 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1009:

/* Line 690 of lalr1.cc  */
#line 6926 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 1010:

/* Line 690 of lalr1.cc  */
#line 6927 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 1011:

/* Line 690 of lalr1.cc  */
#line 6928 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1012:

/* Line 690 of lalr1.cc  */
#line 6929 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 1013:

/* Line 690 of lalr1.cc  */
#line 6930 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 1014:

/* Line 690 of lalr1.cc  */
#line 6931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 1015:

/* Line 690 of lalr1.cc  */
#line 6932 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 1016:

/* Line 690 of lalr1.cc  */
#line 6937 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 12227 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	default:
          break;
      }
    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action
       invokes YYABORT, YYACCEPT, or YYERROR immediately after altering
       yychar.  In the case of YYABORT or YYACCEPT, an incorrect
       destructor might then be invoked immediately.  In the case of
       YYERROR, subsequent parser actions might lead to an incorrect
       destructor call or verbose syntax error message before the
       lookahead is translated.  */
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
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yytranslate_ (yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	if (yychar == yyempty_)
	  yytoken = yyempty_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[1] = yylloc;
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

    yyerror_range[1] = yylocation_stack_[yylen - 1];
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
	if (!yy_pact_value_is_default_ (yyn))
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

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
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
      {
        /* Make sure we have latest lookahead translation.  See comments
           at user semantic actions for why this is necessary.  */
        yytoken = yytranslate_ (yychar);
        yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval,
                     &yylloc);
      }

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
  xquery_parser::yysyntax_error_ (int yystate, int yytoken)
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yychar.
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            /* Stay within bounds of both yycheck and yytname.  */
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = 0;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int xquery_parser::yypact_ninf_ = -1502;
  const short int
  xquery_parser::yypact_[] =
  {
      3070, -1502, -1502, -1502,  4934,  4934,  4934, -1502, -1502,    37,
     269, -1502,   120,    52, -1502, -1502, -1502,   842, -1502, -1502,
   -1502,    21,   288,   849,  2522,   310,   346,   870, -1502,    84,
   -1502, -1502, -1502, -1502, -1502, -1502,   855, -1502,   453,   483,
   -1502, -1502, -1502, -1502,   557, -1502,   856, -1502,   610,   658,
   -1502,   285, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502,
   -1502, -1502, -1502, -1502, -1502, -1502,   266,   707, -1502, -1502,
   -1502, -1502,   756, 10824, -1502, -1502, -1502,   775, -1502, -1502,
   -1502,   622, -1502,   797,   819, -1502, -1502, 15211, -1502, -1502,
   -1502, -1502, -1502, -1502, -1502, -1502,   829, -1502, -1502,   860,
     874, -1502, -1502, -1502, -1502, -1502, -1502, -1502,  3694,  6794,
    7104, 15211, -1502, -1502, -1502, -1502, -1502, -1502, -1502,   703,
   -1502, -1502,   881, 11719, -1502, 12022,   888,   891, -1502, -1502,
   -1502,   893, -1502, 10204, -1502, -1502, -1502, -1502, -1502, -1502,
     876, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502,   132,
     776, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502,   214,
     871,   443, -1502,  -113,   205, -1502, -1502, -1502, -1502, -1502,
   -1502,   940, -1502,   821,   825,   827, -1502, -1502,   915,   921,
   -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502,
   -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502,
   -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502,
   -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502,
   -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502,
   -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502,
   -1502, -1502, -1502,  7414,  7724, -1502,   759, -1502, -1502, -1502,
   -1502, -1502,  3382,  5244,  1072, -1502,  5554, -1502, -1502,   167,
     102, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502,
   -1502, -1502, -1502, -1502, -1502,   104, -1502, -1502, -1502, -1502,
   -1502, -1502,   466, -1502, -1502, -1502, -1502, -1502, -1502, -1502,
   -1502,  4934, -1502, -1502, -1502, -1502,    14, -1502, -1502, -1502,
   -1502, -1502, -1502, -1502, -1502,   195, -1502,   885, -1502, -1502,
   -1502,   452, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502,
     909,   985, -1502,   828,   831,   979,   725,   587,   698,   792,
   -1502,  1029,   882,   980,   981,  8964, -1502,   892, -1502, -1502,
     582, -1502, -1502, 10514, -1502,   765, -1502,   930, 10824, -1502,
     930, 10824, -1502, -1502, -1502,   371, -1502, -1502, -1502, -1502,
   -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502,
   -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502,
   -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502,
   -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502,
   -1502, -1502, -1502, -1502, -1502, -1502, -1502,   942,   932, -1502,
   -1502, -1502, -1502, -1502,   906, -1502,  4934,   907,   908,   669,
     669,  1067,   711,   753,   588, 15499, 15211,    17,  1050, 15211,
     946,   983,   637, 11719,   743,   853, 15211, 15211,   801,   717,
      68, -1502, -1502, -1502, 11719,  4934,   922,  4934,   130,  9274,
   12907, 15211, -1502,   823,   832, 15211,   995,   255,   961,  9274,
    1114,    77,   114, 15211,   999,   984,  1015, -1502,  9274, 11422,
   15211, 15211, 15211,  4934,   936,  9274,  9274, 15211,  4934,   972,
     974, -1502, -1502, -1502,  9274, 13195,   973, -1502,   975, -1502,
   -1502, -1502, -1502,   977, -1502,   978, -1502, -1502, -1502, -1502,
   -1502,   982, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502,
   -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502,
   -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502,
   15211, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502,
   -1502, -1502, -1502,   986, 15211, -1502, -1502, -1502,   951,  4004,
    1016,    38,   987,   988,   989, 15211,  4934, -1502,   993,   137,
   -1502,   746, -1502,    71,  1101,  9274, -1502, -1502,   176, -1502,
   -1502, -1502,  1123, -1502, -1502, -1502, -1502,  9274,   928, -1502,
    1118,  9274,  9274, 12322,   962,  9274,  9274,  9274,  9274, 12322,
    9274,   917,   923, 15211,   960,   965,  9274,  9274,  3694,   913,
   -1502,    56, -1502,    46,  9274,  5244, -1502, -1502, -1502, -1502,
   -1502,   120,   870,   122,   128,  1148,  5864,  5864,  6174,  6174,
     622, -1502, -1502,   405,   622, -1502,  9274,  9274, -1502,  1034,
     600,    84,   991,   990,   992,  4934,  9274, -1502, -1502, -1502,
   -1502, -1502, -1502, -1502, -1502,  9584,  9584,  9584, -1502,  9584,
    9584, -1502,  9584, -1502,  9584, -1502, -1502, -1502, -1502, -1502,
   -1502, -1502,  9584,  9584,  1091,  9584,  9584,  9584,  9584,  9584,
    9584,  9584,  9584,  9584,  9584,  9584,  9584,   934,  1074,  1075,
    1076, -1502, -1502, -1502,  9894,  8034, -1502, -1502, 10204, 10204,
    9274,   930, -1502, -1502,   930, -1502,  8344,   930,  1017,  8654,
   -1502, -1502, -1502,    49, -1502,    58, -1502, -1502, -1502, -1502,
   -1502, -1502,  1065,  1066,   310,  1147, -1502, -1502, 15499,   957,
     739, 15211,  1018,  1019,   957,  1067,  1053,  1045, -1502, -1502,
   -1502,    55,   935,  1089,   886, 15211,  1042,  9274,  1068, 15211,
   15211, -1502,  1055,  1007,  4934, -1502,  1008,   975,   483, -1502,
    1009,  1010,   228, -1502,   232,   270,  1087, -1502,    41, -1502,
   -1502,  1087, 15211,     9, 15211,  1104,   296, -1502,  4934, -1502,
      72, -1502, 11719,  1099,  1155, 11719,  1067,  1106,   337, 15211,
    9274,    84,   315,  1024, -1502,  1025,  1026,  1027,    -6, -1502,
     606,  1020, -1502,    96,   106,  1052, -1502,  1022,  4934,  4934,
     325, -1502,   326,   336,   575,  9274,   261, -1502, -1502,  9274,
    9274, -1502,  9274,  9274,  9274, -1502,  9274, -1502,  9274, -1502,
   15211,  1101, -1502,   449,   330, -1502, -1502, -1502,   383, -1502,
     286, -1502, -1502,  1063,  1064,  1069,  1071,  1077,   371,   942,
   -1502,   152,   468,   333,    42,  1109,   559,   994,   996,   997,
      -5, -1502,  1078, -1502, -1502,  1028,   113,  4314,   409, 11125,
     913, -1502, -1502, -1502,  1000, -1502,   167,   799,  1192,  1192,
   -1502, -1502,   138, -1502, -1502,   139, -1502,    57, -1502, -1502,
   -1502, -1502, -1502, -1502, -1502, -1502, 15211,  1057,  9274,  1111,
   -1502, -1502, -1502,   985, -1502, -1502, -1502, -1502, -1502,  9584,
   -1502, -1502, -1502,    61, -1502,   587,   587,   597,   698,   698,
     698,   698,   792,   792, -1502, -1502, 14347, 14347, 15211, 15211,
   -1502, -1502,   410, -1502, -1502,   265, -1502, -1502, -1502,   353,
   -1502, -1502,   381,   669, -1502, -1502,   619,   757,   745, -1502,
     310, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502,
   -1502,   957, -1502,  1100, 14635,  1093,  9274, -1502, -1502, -1502,
    1142,  1067,  1067,   957, -1502,   896,  1067,   710, 15211,   560,
     584,  1208, -1502, -1502,   952,   536, -1502, -1502, -1502, -1502,
   -1502, -1502, -1502, -1502, -1502, -1502, -1502,    55,    30,  1012,
     647,  9274, -1502, 15211,  1149,   943,  1067, -1502, -1502, -1502,
   -1502,  1092, 15211, -1502, 15211, -1502, 14923,  1119, 14347,  1129,
    9274,    92,  1105,    34,   618,  1001, -1502, -1502,   793,     9,
    1142, 14347,  1133,  1159,  1070,  1058,  1125,  1067,  1098,  1127,
    1164,  1067,  9274,   -32, -1502, -1502, -1502,  1108, -1502, -1502,
   -1502, -1502,  1145,  9274,  9274,  1117, -1502,  1165,  1166,  4934,
   -1502,  1083,  1085,  1121, 15211, -1502, 15211, -1502,  9274,  1130,
    1081,  9274, -1502,  1154,   143,   158,   171,  1241, -1502,   499,
   -1502,   239, -1502, -1502,  1248, -1502,   788,  9274,  9274,  9274,
     794,  9274,  9274,  9274,  9274,  9274,  9274,  9274,  9274,  9274,
   12322,  1160,  9274,  9274, -1502,  6484,  1124,  1128,  1131,  1126,
     885,   758,  1038, -1502,    11, -1502,  9274,   147,   430,    57,
    6174,  6174,  6174,  1206, -1502,  9274,   800,  1179, -1502, 15211,
    1182, -1502, -1502,  9274,    61,   585,   667, -1502,  1005,   174,
    1036,  1035, -1502, -1502,   853, -1502,  1030,   655,  1140,  1143,
   14635,  1146,  1150,  1152,  1153,  1157, -1502,   666, -1502, -1502,
   -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502,
   -1502,  1161, -1502, -1502, -1502, -1502,  9274, -1502, -1502, -1502,
   -1502, -1502, -1502, -1502, -1502, -1502,   781, -1502,  1269,   830,
   -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502,  1031,
   -1502, -1502,  1274, -1502, -1502, -1502, -1502, -1502,   626,  1275,
   -1502,    93, -1502, -1502, -1502,   973,   288,   977,   453,   978,
     982,   871,  1150,  1152,  1153, -1502,   666,   666,  9894,  1032,
    1021, -1502,  1142,    30,  1084,  1132,  4934,  1134,  1136,  1170,
    1137,  1138, 15211, -1502,   567, -1502, 15211, -1502,  9274,  1168,
    9274,  1189,  9274,   207,  1171,  9274,  1181, -1502,  1211,  1215,
    9274, 15211,   920,  1257, -1502, -1502, -1502, -1502, -1502, -1502,
   14347, -1502,  4934,  1067,  1228, -1502, -1502, -1502,  1067,  1228,
   -1502,  9274,  1197,  4934, 15211, -1502, -1502,  9274,  9274,   837,
   -1502,    54,   838, -1502, 13483,   839, -1502,   840, -1502,  1158,
   -1502, -1502,  4934,  1156,  1162, -1502,  9274, -1502, -1502,  9274,
    1163,  1165,  1246, -1502,  1209, -1502,   537, -1502, -1502,  1343,
   -1502, -1502,  4934, 15211, -1502,   574, -1502, -1502, -1502,  1167,
    1122,  1135, -1502, -1502, -1502,  1139,  1144, -1502, -1502, -1502,
    1258, -1502, -1502, -1502, -1502,  1141,   264, 15211,  1172, -1502,
   -1502,  9274,  9274,  9274,  4624,  6484, 11125,  1038, -1502, 11125,
   -1502, -1502,  1192,   535, -1502, -1502, -1502,  1179, -1502,  1067,
   -1502,   919, -1502,   334,  1250, -1502,  9274,   744,  1111,   474,
    1175, -1502,    61,  1113, -1502, -1502,   420, -1502,   -60,   -14,
    1115,    61,   -60,  9584, -1502,   404, -1502, -1502, -1502, -1502,
   -1502, -1502,    61,  1212,  1082,   935,   -14, -1502, -1502,  1080,
    1291, -1502, -1502, -1502, 12619,  1183,  1184,  1186,  1188,  1193,
    1194,  1195, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502,
   -1502, -1502, -1502, -1502,  1347,   460,  1350,   460,  1112,  1278,
   -1502, -1502,  1216, 15211,  1151, -1502, -1502,  9894, -1502,  1204,
   -1502, -1502, -1502, -1502, -1502, -1502,  9274,  1242, -1502, -1502,
    9274, -1502,   628, -1502,  9274,  1243,  9274, -1502,  9274, 15211,
   15211, -1502,   684, -1502,  9274, -1502,  1265,  1266,  1297,  1067,
    1228, -1502,  9274,  1210, -1502, -1502, -1502,  1213, -1502,   278,
    9274,  4934,  1214,   309, -1502, 15211,  1217, 13771,    48, -1502,
   14059,  1218, -1502, -1502,  1221, -1502, -1502, -1502, -1502,  9274,
     848,  1241, 15211,   671, -1502,  1223,  1241, 15211, -1502, -1502,
    9274,  9274,  9274,  9274,  1079,  9274,  9274, -1502,  9274,   206,
     208,   234,   592, -1502, -1502, -1502, -1502, -1502,  1250, -1502,
   -1502, -1502,  1067,  9274, -1502,  1254, -1502, -1502, -1502, -1502,
    1225,  9584, -1502, -1502, -1502, -1502, -1502,   348,  9584,  9584,
     550, -1502,  1036, -1502,   509, -1502,  1035,    61,  1244, -1502,
   -1502,  1173, -1502, -1502, -1502, -1502,  1304,  1224, -1502,   515,
   -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502,   480,   480,
   -1502,   460, -1502, -1502,   521, -1502,  1372,   -14,  1306,  1227,
    9894,   -20,  1174,  1240, -1502, -1502,  9274, -1502,  9274,  1268,
   -1502,  9274, -1502, -1502, -1502,  1359, -1502, -1502,  6484,  9274,
    1067, -1502, -1502, -1502,  9274,  9274, -1502, -1502, -1502,  6484,
    6484,  1322,  4934, 15211,  1231, 15211,  9274, 15211,  1232,  6484,
   -1502,   493,   191,  1241, 15211, -1502,  1226,  1241, -1502, -1502,
   -1502, -1502,  9274, -1502, -1502, -1502,  1222,  1165,  1166,  9274,
   -1502, -1502, -1502,  1315,  9274, -1502,   698,  9584,  9584,   597,
     734, -1502, -1502, -1502, -1502, -1502, -1502,  9274, -1502, 14347,
   -1502, 14347,  1328, -1502, -1502, -1502,  1395, -1502, -1502, -1502,
    1169,  1318, -1502, -1502,  1319, -1502,   548, 15211,  1309,  1205,
   15211,  9894, -1502, -1502,  9274, -1502,  1311, -1502, -1502,  1228,
   -1502, -1502, 14347, -1502, -1502,  1337,  9274,  1247, -1502,  1338,
    6484, -1502, 15211,   385,   624, -1502,  1238,  1241, -1502,  1239,
   -1502,  6484,   862,   481, -1502,  1315,   597,   597,  9584,   488,
   -1502, -1502, 14347, -1502, -1502,  1306,  9894, -1502,  1250,  1177,
   15211,  1320,  1219,  1319, -1502, 15211,  1255, 14347,  4934, 14347,
    1256, -1502, -1502,  1352,   603, -1502, -1502, -1502, -1502,  1260,
     762, -1502, -1502, -1502,  1251, -1502,  1329, -1502, -1502,   597,
   -1502, -1502, -1502, -1502, -1502,  9274,  1178, 15211,  1332, -1502,
    4934,  1271, -1502, -1502,  1272,  9274, -1502, -1502, -1502, -1502,
   -1502, -1502, -1502, 15211, -1502,  1176,  1180, 15211, -1502, -1502,
    9274,  6484,  1276,  1185,  9274,  1187,  6484,  9894, -1502,  9894,
   -1502,  1252,  1199, 15211,  1229,  1334, 15211,  1190,  9894, -1502
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       164,   462,   463,   464,   167,   167,   167,   811,  1016,   119,
     121,   617,   903,   912,   852,   816,   814,   796,   904,   907,
     859,   820,   797,   798,     0,   913,   800,   910,   881,   861,
     836,   856,   857,   908,   905,   855,   802,   911,   803,   804,
     952,   964,   951,   853,   872,   866,   805,   854,   807,   806,
     953,   890,   891,   858,   833,   974,   975,   976,   977,   978,
     979,   980,   981,   982,   983,   984,   998,  1005,   880,   876,
     867,   847,   795,     0,   875,   883,   892,   999,   871,   488,
     848,   849,   906,  1000,  1006,   868,   885,     0,   494,   451,
     490,   878,   813,   869,   870,   899,   873,   889,   898,  1004,
    1007,   819,   860,   901,   489,   888,   894,   799,     0,     0,
       0,     0,   397,   886,   897,   902,   900,   879,   865,   954,
     863,   864,  1001,     0,   396,     0,  1002,  1008,   895,   850,
     874,  1003,   429,     0,   461,   896,   877,   884,   893,   887,
     955,   841,   846,   845,   844,   843,   842,   808,   862,     0,
     812,   909,   834,   943,   942,   944,   818,   817,   837,   949,
     801,   941,   946,   947,   938,   840,   882,   940,   950,   948,
     939,   838,   945,   959,   960,   957,   958,   956,   809,   961,
     962,   963,   929,   928,   915,   832,   825,   922,   918,   835,
     831,   930,   931,   821,   822,   815,   824,   927,   926,   923,
     919,   936,   937,   935,   925,   921,   914,   823,   934,   933,
     827,   829,   828,   920,   924,   916,   830,   917,   826,   932,
     985,   986,   987,   988,   989,   990,   966,   967,   965,   971,
     972,   973,   968,   969,   970,   839,   991,   992,   993,   994,
     995,   996,   997,     0,     0,  1009,  1010,  1011,  1014,  1013,
    1012,  1015,   164,   164,     0,     2,   164,     8,    10,    22,
       0,    27,    30,    35,    36,    37,    38,    39,    40,    41,
      31,    57,    58,    32,    33,     0,    75,    78,    79,    34,
      80,    81,     0,   117,    82,    83,    84,    85,    17,   161,
     162,   163,   170,   172,   481,   173,     0,   174,   175,   176,
     177,   178,   179,   180,   183,     0,   209,   217,   212,   244,
     250,     0,   242,   243,   219,   213,   182,   214,   181,   215,
     218,   348,   350,   352,   362,   364,   368,   370,   373,   378,
     381,   384,   386,   388,   390,     0,   394,   401,   400,   402,
       0,   420,   403,   425,   428,   430,   433,   435,     0,   440,
     437,     0,   448,   458,   460,   434,   465,   472,   486,   473,
     474,   475,   478,   479,   476,   477,   501,   503,   504,   505,
     502,   550,   551,   552,   553,   554,   555,   457,   591,   583,
     590,   589,   588,   585,   587,   584,   586,   487,   480,   618,
     619,    42,   220,   221,   223,   222,   224,   216,   483,   484,
     485,   482,   226,   229,   225,   227,   228,   459,   794,   810,
     903,   912,   910,   812,     0,   165,   166,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   125,   127,   128,     0,     0,     0,     0,     0,     0,
       0,     0,   254,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   272,   273,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   453,   456,   443,     0,     0,   796,   820,   798,   851,
     913,   800,   861,   802,   872,   805,   807,   806,   890,   998,
    1005,   795,   999,   849,  1000,  1006,   873,  1004,  1007,   954,
    1001,  1002,  1008,  1003,   955,   949,   941,   947,   938,   838,
     959,   960,   957,   809,   961,  1010,   449,   459,   794,   441,
       0,   190,   442,   445,   796,   797,   798,   802,   803,   804,
     805,   795,   801,   491,     0,   447,   446,   185,     0,     0,
     209,     0,   800,   807,   806,     0,   167,   769,   961,     0,
     217,     0,   492,     0,   517,     0,   452,   792,     0,   793,
     423,   424,     0,   455,   454,   444,   427,     0,     0,   546,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     771,     0,   773,     0,     0,   164,     3,     4,     1,     9,
      11,     0,     0,     0,     0,     6,   164,   164,   164,   164,
       0,   118,   171,     0,     0,   188,     0,     0,   197,     0,
       0,     0,     0,     0,     0,     0,     0,   202,   230,   249,
     245,   251,   246,   248,   247,     0,     0,     0,   413,     0,
       0,   411,     0,   357,     0,   412,   405,   410,   409,   408,
     407,   406,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   399,   398,   395,     0,     0,   421,   426,     0,     0,
       0,   436,   469,   439,   438,   450,     0,   466,     0,     0,
     557,   559,   563,     0,   123,     0,   791,    46,    43,    44,
      47,    48,     0,     0,     0,     0,    49,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   628,   629,
     630,     0,   102,   141,     0,     0,   111,     0,     0,     0,
       0,   126,     0,     0,     0,   597,     0,     0,     0,   593,
       0,     0,     0,   607,     0,     0,   253,   255,     0,   232,
     233,   252,     0,     0,     0,   133,     0,   137,   167,   621,
       0,    59,     0,    68,     0,     0,     0,    60,     0,     0,
       0,     0,     0,     0,   598,     0,     0,     0,     0,   321,
       0,     0,   596,     0,     0,     0,   615,     0,     0,     0,
       0,   601,     0,     0,   192,     0,     0,   186,   184,     0,
       0,   775,     0,     0,     0,   491,     0,   770,     0,   493,
     518,   517,   514,     0,     0,   548,   547,   422,     0,   545,
       0,   641,   642,   796,   798,   802,   805,   795,   782,     0,
     592,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   647,     0,   200,   201,     0,     0,     0,     0,     0,
     205,   206,   772,   774,     0,     5,    23,     0,    24,     0,
       7,    28,     0,    14,    29,     0,    18,   903,    76,    15,
      77,    19,   191,   189,   210,   211,     0,     0,     0,     0,
     203,   231,   290,   349,   351,   355,   361,   360,   359,     0,
     356,   353,   354,     0,   365,   372,   371,   369,   375,   376,
     377,   374,   379,   380,   383,   382,     0,     0,     0,     0,
     404,   418,     0,   431,   432,     0,   470,   467,   499,     0,
     620,   497,     0,     0,   120,   122,     0,     0,     0,   101,
       0,    91,    93,    94,    95,    96,    98,    99,   100,    92,
      97,    87,    88,     0,     0,   107,     0,   103,   105,   106,
     113,     0,     0,    86,    45,     0,     0,     0,     0,     0,
       0,     0,   719,   724,     0,     0,   720,   754,   707,   709,
     710,   711,   713,   715,   714,   712,   716,     0,     0,     0,
       0,     0,   110,     0,   143,     0,     0,   562,   556,   594,
     595,     0,     0,   611,     0,   608,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   234,   235,     0,   240,
     139,     0,     0,   134,     0,     0,     0,     0,     0,     0,
      61,     0,     0,     0,   271,   277,   274,     0,   600,   599,
     606,   614,     0,     0,     0,     0,   561,     0,     0,     0,
     414,     0,     0,     0,     0,   604,     0,   602,     0,   193,
       0,     0,   776,     0,     0,     0,     0,   517,   515,     0,
     506,     0,   495,   496,     0,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   198,     0,   800,   807,   806,   961,
       0,     0,     0,   655,     0,   207,     0,     0,     0,     0,
     164,   164,   164,     0,   241,     0,   305,   301,   303,     0,
     291,   292,   358,     0,     0,     0,     0,   685,   366,   658,
     662,   664,   666,   668,   671,   678,   679,   687,   913,   799,
       0,   808,  1014,  1013,  1012,  1015,   385,   566,   572,   573,
     576,   622,   623,   577,   578,   785,   786,   787,   581,   387,
     389,   392,   582,   391,   419,   471,     0,   468,   498,   124,
      55,    56,    53,    54,   130,   129,     0,    89,     0,     0,
     108,   109,   114,    73,    74,    51,    52,    72,   725,     0,
     728,   755,     0,   718,   717,   722,   721,   753,     0,     0,
     730,     0,   726,   729,   708,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   142,   145,   147,     0,     0,
       0,   112,   115,     0,     0,     0,   167,     0,     0,   615,
       0,     0,     0,   257,     0,   565,     0,   258,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   236,     0,     0,
       0,     0,   284,     0,   281,   286,   239,   140,   135,   138,
       0,   187,     0,     0,    70,    64,    67,    66,     0,    62,
     275,     0,     0,   167,     0,   319,   323,     0,     0,     0,
     326,     0,     0,   332,     0,     0,   339,     0,   343,     0,
     416,   415,   167,     0,     0,   194,     0,   196,   320,     0,
       0,     0,     0,   518,     0,   507,     0,   541,   538,     0,
     542,   543,     0,     0,   537,     0,   512,   540,   539,     0,
       0,     0,   634,   635,   631,     0,     0,   639,   640,   636,
     778,   779,   645,   783,   643,     0,     0,     0,     0,   649,
     199,     0,     0,     0,     0,     0,     0,   650,   651,     0,
     208,   781,    25,     0,    16,    20,    21,   302,   314,     0,
     315,     0,   306,   307,   308,   309,     0,   294,     0,     0,
       0,   669,   682,     0,   363,   367,     0,   701,     0,     0,
       0,     0,     0,     0,   657,   659,   660,   696,   697,   698,
     700,   699,     0,     0,   673,   672,     0,   676,   680,   694,
     692,   691,   684,   688,     0,     0,     0,     0,     0,     0,
       0,     0,   569,   571,   570,   567,   393,   500,   132,   131,
      90,   104,   742,   723,     0,   747,     0,   747,   736,   731,
     146,   148,     0,     0,     0,   116,   144,     0,    26,     0,
     612,   613,   616,   609,   610,   256,     0,     0,   270,   262,
       0,   266,     0,   260,     0,     0,     0,   279,     0,     0,
       0,   238,   282,   285,     0,   136,     0,     0,    69,     0,
      63,   276,     0,     0,   322,   324,   329,     0,   327,     0,
       0,     0,     0,     0,   333,     0,     0,     0,     0,   340,
       0,     0,   344,   417,     0,   605,   603,   195,   777,     0,
       0,   517,     0,     0,   549,     0,   517,     0,   513,    13,
       0,     0,     0,     0,     0,     0,     0,   648,     0,     0,
       0,     0,     0,   652,   656,   318,   316,   317,   310,   311,
     312,   304,     0,     0,   299,     0,   293,   686,   677,   683,
       0,     0,   756,   757,   767,   766,   765,     0,     0,     0,
       0,   758,   663,   764,     0,   661,   665,     0,     0,   670,
     674,     0,   695,   690,   693,   689,     0,     0,   579,     0,
     574,   627,   568,   789,   790,   788,   575,   743,     0,     0,
     741,   748,   749,   745,     0,   740,     0,   738,     0,     0,
       0,     0,     0,     0,   558,   259,     0,   268,     0,     0,
     264,     0,   267,   280,   288,   289,   283,   237,     0,     0,
       0,    65,   278,   564,     0,     0,   330,   334,   328,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     560,     0,     0,   517,     0,   544,     0,   517,   632,   633,
     637,   638,     0,   644,   784,   646,     0,     0,     0,     0,
     653,   313,   300,   295,     0,   681,   768,     0,     0,   760,
       0,   706,   705,   704,   703,   702,   667,     0,   759,     0,
     624,     0,     0,   752,   751,   750,     0,   744,   737,   735,
       0,   732,   733,   727,   149,   151,   153,     0,     0,     0,
       0,     0,   263,   261,     0,   269,     0,   204,   347,    71,
     325,   331,     0,   345,   341,     0,     0,     0,   335,     0,
       0,   337,     0,   527,   521,   516,     0,   517,   508,     0,
     780,     0,     0,     0,   298,   296,   762,   761,     0,     0,
     625,   580,     0,   746,   739,     0,     0,   155,   154,     0,
       0,     0,     0,   150,   265,     0,     0,     0,     0,     0,
       0,   535,   529,     0,   528,   530,   536,   533,   523,     0,
     522,   524,   534,   510,     0,   509,     0,   654,   297,   763,
     675,   626,   734,   152,   156,     0,     0,     0,     0,   287,
       0,     0,   338,   336,     0,     0,   520,   531,   532,   519,
     525,   526,   511,     0,   157,     0,     0,     0,   346,   342,
       0,     0,     0,     0,     0,     0,     0,     0,   159,     0,
     158,     0,     0,     0,     0,     0,     0,     0,     0,   160
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1502, -1502,  -227,  -197, -1502,  1207,  1220, -1502,  1196,  -558,
   -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502,
    -995, -1502, -1502, -1502, -1502,  -219,  -580, -1502,   716,  -200,
   -1502, -1502, -1502, -1502, -1502,   281,   510, -1502, -1502,    -9,
    -164,  1044, -1502,  1039, -1502, -1502,  -636, -1502,   445, -1502,
     245, -1502,  -221,  -265, -1502,  -551, -1502,    15,    18,    75,
    -282,  -168, -1502,  -875, -1502, -1502,   357, -1502, -1502, -1502,
   -1502, -1502, -1502, -1502, -1502, -1502, -1502,   612,   -93,  1298,
       0, -1502, -1502, -1502, -1502,   455, -1502, -1502,  -293, -1502,
       8, -1502,  1033,  -921,  -723,  -708, -1502, -1502,   694, -1502,
   -1502,    22,   235, -1502, -1502, -1502,   112, -1501, -1502,   375,
     126, -1502, -1502,   131, -1310, -1502,   953,   221, -1502, -1502,
     220, -1013, -1502, -1502,   219, -1502, -1502, -1259, -1253, -1502,
     216, -1502, -1502,   861,   859, -1502,  -530,   843, -1502, -1502,
    -658,   384,  -641,   379,   380, -1502, -1502, -1502,   590, -1502,
   -1502,  1191, -1502, -1502, -1502, -1502, -1502,  -827,  -314,  -677,
   -1502,   -89, -1502, -1502, -1502, -1502, -1502, -1502, -1502,   -24,
    -807, -1502,  -538,   654,   300, -1502,  -418, -1502, -1502, -1502,
   -1502, -1502, -1502, -1502,   808, -1502, -1029, -1502,   209, -1502,
     690,  -796, -1502, -1502, -1502, -1502, -1502,  -248,  -240, -1222,
    -883, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502,
   -1502,  -763,  -880,  -156,  -855, -1502, -1502, -1502,  -726, -1502,
   -1502, -1502, -1502, -1502, -1502, -1502,  1073,  1086,  -201,   512,
     340, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502,
   -1502, -1502, -1502, -1502, -1502,   183, -1502, -1502,   175, -1502,
     177, -1062, -1502, -1502, -1502,   144,   135,   -29,   406, -1502,
   -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502, -1502,
   -1502, -1502,   145, -1502, -1502, -1502,   -25,   398,   549, -1502,
   -1502, -1502, -1502, -1502,   338, -1502, -1502, -1463, -1502, -1502,
   -1502,  -514, -1502,   108, -1502,   -44, -1502, -1502, -1502, -1502,
   -1308, -1502,   156, -1502, -1502, -1502, -1502, -1502,   954, -1502,
   -1502, -1502, -1502, -1502,  -927, -1502, -1502, -1502,  -375,  -373,
     100,   738, -1502
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   254,   627,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
    1264,   776,   272,   273,   274,   275,   276,   277,   951,   952,
     953,   278,   279,   280,   957,   958,   959,   281,   439,   282,
     283,   703,   284,   441,   442,   443,   458,   766,   767,   285,
    1215,   286,  1684,  1685,   287,   288,   289,   548,   290,   291,
     292,   293,   294,   769,   295,   296,   531,   297,   298,   299,
     300,   301,   302,   637,   303,   304,   860,   861,   305,   306,
     560,   308,   638,   456,  1018,  1019,   309,   639,   310,   641,
     561,   312,   756,   757,  1252,   465,   313,   466,   467,   763,
    1253,  1254,  1255,   642,   643,  1120,  1121,  1534,   644,  1117,
    1118,  1362,  1363,  1364,  1365,   314,   788,   789,   315,  1279,
    1280,  1479,   316,  1282,  1283,   317,   318,  1285,  1286,  1287,
    1288,   319,   320,   321,   322,   899,   323,   324,  1374,   325,
     326,   327,   328,   329,   330,   331,   332,   333,  1160,   334,
     335,   336,   337,   662,   663,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   697,   692,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   929,   365,   366,   367,  1315,   821,
     822,   823,  1715,  1759,  1760,  1753,  1754,  1761,  1755,  1316,
    1317,   368,   369,  1318,   370,   371,   372,   373,   374,   375,
     376,  1013,  1146,  1415,  1147,  1569,  1148,  1161,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   795,  1228,
     387,   388,   389,   390,  1150,  1151,  1152,  1153,   391,   392,
     393,   394,   395,   396,   850,   851,   397,  1347,  1348,  1650,
    1104,  1128,  1384,  1385,  1129,  1130,  1131,  1132,  1133,  1394,
    1559,  1560,  1134,  1397,  1135,  1540,  1136,  1137,  1402,  1403,
    1565,  1563,  1386,  1387,  1388,  1389,  1664,   732,   978,   979,
     980,   981,   982,   983,  1202,  1589,  1681,  1203,  1587,  1679,
     984,  1427,  1584,  1580,  1581,  1582,   985,   986,  1390,  1398,
    1550,  1391,  1546,  1375,   398,   399,   400,   401,   551,   402,
     403,   404,   405,   406,  1154,  1155,  1156,  1157,  1265,   568,
     407,   408,   409
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int xquery_parser::yytable_ninf_ = -852;
  const short int
  xquery_parser::yytable_[] =
  {
       307,   704,   704,   440,   307,   307,   307,   920,   311,   622,
     907,   599,   311,   311,   311,  1033,   559,   563,   640,   414,
     417,   418,   415,   415,   415,  1069,   686,  1045,   908,   909,
     910,   911,  1489,   617,  1281,  1011,  1269,  1159,   878,   880,
     614,  1059,  1314,  1500,   576,   838,   707,   615,   619,   526,
    1012,   846,  1103,  1529,  1530,   606,   607,   615,   871,   874,
     727,  1217,  1370,  1175,  1015,   873,   876,   879,   881,  1205,
    1241,   742,   615,   615,  1206,   747,  1126,  1007,   938,   416,
     416,   416,  1547,     9,    10,  1233,   773,   777,  1561,  1207,
      11,  1208,   748,  1508,     9,    10,   785,   615,  1687,  1179,
    1209,  1042,  1091,   615,   425,   615,   706,   615,   307,   967,
    1271,   968,   588,   426,   615,   425,   311,   895,   621,   896,
     897,   624,   898,   615,   900,  1682,   415,  1210,  1235,   615,
    1009,   428,   901,   902,   622,  1008,   429,  1009,   615,   615,
     615,  1258,   428,   706,   615,   810,     9,    10,   615,   810,
     601,   603,  1724,   626,  1480,   969,   933,   421,   422,   615,
     423,   424,   578,   626,  1344,   933,  1625,   425,   430,   431,
    1113,    79,   615,   527,   447,   747,   426,   427,   626,   626,
     738,  1242,  1043,   549,   825,    90,   716,   543,  1010,  1199,
    1149,  1149,   748,   419,   428,  -168,   615,  1182,   623,   429,
     611,   589,   463,   626,   625,  1688,  1200,   615,  1544,   615,
     104,   564,   444,   626,  1123,  1545,   612,  1124,  1651,   717,
     626,  1349,   811,   569,  1768,   572,  1016,   774,  1149,   615,
    1092,   430,   431,   432,  1626,   615,   934,   772,   125,  1238,
    1481,   464,  1548,  1549,   626,   935,  1076,  1489,  1307,  1308,
     626,  1246,   307,   307,   687,  1211,   307,  1257,   819,  1025,
     311,   311,  1216,  1017,   311,   626,   615,   622,   640,  1483,
    1376,  1304,  1772,  1470,   775,  1085,   621,  1314,   626,  1680,
     433,  1508,  1149,  1047,  1713,  1406,  1314,  1689,   878,   880,
    1243,   307,   616,  1048,   618,  1149,  1217,  1126,  1126,   311,
    1095,  1419,   626,  1239,  1176,  1244,   970,   464,   871,   874,
    1539,  1445,   866,   626,   464,   626,   615,   749,   868,   971,
    1125,   972,   817,   623,   693,  1272,   615,   695,  1110,  1112,
    1300,   615,   973,   974,   975,   626,   976,  1352,   977,  1002,
     434,   626,  1309,  1377,   436,  1301,   579,  1212,  1213,  1214,
     964,   826,   437,   890,  1454,   739,   752,   464,  1302,   863,
     438,   477,  1310,   740,  1311,   464,   770,   862,  1042,  1122,
    1077,  1078,   626,   764,  1714,   782,  1737,  1004,  1480,  -168,
    1465,   435,   793,   794,   615,  1079,   867,   869,   481,  1722,
    1751,   800,  1312,  1646,  1307,  1647,   111,   872,   875,  1026,
    1657,  1030,  1029,  1022,  1486,  -169,   615,   436,   865,  1480,
     615,   615,  1001,   123,  1149,   437,   307,  1074,   690,  1003,
     696,  1648,   626,   438,   311,   420,  1378,  1379,  1774,  1380,
     590,  1008,   626,  1054,  1313,   591,  1381,   626,   478,   581,
    1359,   582,   765,  1056,   448,   307,  1382,   307,   527,  1061,
    1165,   527,   149,   311,   809,   311,   623,  1005,  1383,  1435,
    1166,  1361,   622,   743,  1615,   746,   457,   421,   422,  1489,
     423,   424,   824,   307,  1314,   615,  1075,  1658,   307,  1032,
     464,   311,   615,  1023,   828,  1127,   311,   427,  1166,   615,
     626,   791,     9,    10,   629,  1620,   797,  1216,   630,  1037,
    1376,  1516,   459,   631,   856,   858,   479,   480,  1310,  1053,
    1311,  1447,   626,  1055,  1072,  1169,   626,   626,  1752,   592,
     744,   632,   744,  1057,  1568,   690,   715,   696,   583,   719,
     878,   880,   878,   569,  1149,  1455,   733,   734,  1312,  1103,
    1167,  1432,  1524,  1353,   569,  1126,  1307,  1308,   744,   307,
     755,   758,  1336,   744,  1126,   758,   307,   311,  1149,  1354,
    1355,  1356,  1080,   778,   311,  1126,  1084,  1073,  1168,   569,
     786,   787,   790,  1377,   415,   622,  1424,   796,   620,  1070,
     722,   626,   723,  1307,  1308,   803,  1183,  1184,   626,  -169,
     433,  1187,   922,  1102,  1164,   626,  1578,   925,   307,   923,
     924,   451,   440,   452,  1535,   307,   311,  1624,  1751,   470,
    1628,  1712,  1307,   311,    11,  1699,   307,   307,   307,   307,
     633,  1225,  1671,   634,   311,   311,   311,   311,  1676,  1305,
     804,   416,  1199,  1307,  1483,   307,  1426,  1542,   635,   471,
    1309,   725,  1008,   311,   790,  1111,  1071,  1107,   869,  1200,
     434,   623,  1757,  1087,  1359,   815,  1378,  1379,  1537,  1380,
    1310,  1579,  1311,  1009,   636,  1767,   453,   666,   585,  1008,
     586,   454,  1770,   857,  1543,   472,  1382,  1309,  1149,  1626,
    1307,  1308,   722,   839,   723,   667,  1081,  1082,  1383,   839,
    1312,   435,  1201,   852,   111,    79,  1306,  1310,    11,  1311,
    1008,  1083,  1672,   726,   669,  1632,  1127,  1127,  1677,    90,
    1636,   123,  1008,   690,  1446,   696,   724,  1058,   455,  1064,
    1065,  1066,  1424,   858,  1009,  1554,  1310,  1312,  1311,  1599,
    1126,   111,  1502,   670,   104,   685,  1787,  1248,  1123,  1425,
     530,  1124,  1249,   725,   307,  1649,   671,  1310,   123,  1311,
     149,  1177,   311,  1044,   712,   666,  1312,   587,  1758,   125,
    1593,  1149,   125,  1177,  1149,  1245,   475,  1170,   307,  1507,
     713,  1307,   878,   667,  1309,  1598,   311,  1312,  1661,    79,
    1009,   672,  1426,  1024,  1171,  1662,   415,   149,   629,  1730,
    1757,  1731,   630,    90,  1310,  1663,  1311,   631,   307,   307,
     629,  1227,  1349,  1230,   630,   726,   311,   311,   640,   631,
    1412,   528,   686,  1340,   476,   632,  1051,  1052,   104,  1661,
    1372,   960,  1746,  1193,  1312,   528,  1662,   632,   111,   482,
    1756,  1762,  1108,   954,  1194,   990,  1663,  1716,  1008,   994,
     995,  1719,  1413,   416,   125,   123,  1248,  1195,   612,   528,
    1532,  1249,  1771,  1293,   736,  1294,   565,  1100,  1196,   737,
    1414,   528,  1014,   528,  1020,  1101,  1634,  1781,   440,  1784,
    1250,  1756,   569,   744,   744,   569,   955,  1762,   483,  1034,
     869,   956,  1174,   666,   149,  1310,  1533,  1311,  1468,  1009,
    1659,  1660,   666,   708,   460,  1358,  1790,   529,   768,   673,
    1656,   667,  1399,  1400,   461,  1172,  1359,   709,   674,   484,
     667,  1251,   485,  1686,   633,  1312,  1360,   634,  1418,   532,
    1067,  1764,  1173,  1738,   668,  1401,   633,  1361,   675,   634,
     462,   599,   818,  1728,   768,   710,  1350,  1278,  1278,  1487,
    1490,   533,   676,  1149,  1345,  1149,  1219,   544,  1487,   711,
    1477,  1482,  1488,  1491,  1127,  1220,   688,   689,   636,   527,
     647,  1631,  1487,  1127,   728,   729,   730,   955,   648,   649,
     636,   650,   956,  1248,  1127,  1766,  1149,   882,  1249,   651,
    1466,   883,   545,   652,  1525,   653,  1114,  1188,  1189,  1190,
     654,   926,   580,  1191,   926,   445,   546,   926,   446,  1726,
    1727,   691,   449,   566,   694,   450,  1149,   655,   468,   473,
     573,   469,   474,   574,  1686,   575,  1158,  1158,  1162,  1162,
    1320,  1149,  1321,  1149,  1185,  1186,  1325,   584,  1326,   577,
    1369,   656,   657,   658,   659,   660,   661,   941,   942,   943,
     944,   945,   946,   947,   948,   949,   950,  1526,  1527,   307,
     905,   906,   912,   913,  1158,   914,   915,   311,   593,  1686,
    1430,  1431,   594,   890,  1673,  1674,   595,  1289,  1192,   596,
    1769,   597,   608,   604,   598,   628,   645,   646,   665,   677,
     664,   679,   678,   680,   690,   684,   528,   698,   699,   528,
     700,   701,   702,  1222,  1611,  1100,   706,   718,   720,   731,
     440,   721,  1229,  1101,  1229,   735,   758,   759,  1158,   745,
     307,   307,   307,   762,   768,   771,   760,   779,   311,   311,
     311,  1158,   781,   792,   744,   798,   780,   799,   805,   446,
    1810,   450,  1811,   469,   474,   807,   820,   809,   485,  1127,
     827,  1819,   829,   812,   813,   814,   816,   830,   848,   840,
     853,   870,   886,   849,   796,   854,   796,  1652,   859,   887,
     888,   903,   889,   714,   528,   916,   930,   528,   917,   918,
     919,   528,   936,   937,   528,   528,   939,   966,   961,   962,
     965,   987,   528,   988,   991,   989,   993,   996,   528,   528,
     839,   997,   998,   528,  1006,  1027,   999,  1000,  1021,  1617,
    1028,   528,  1031,  1086,  1046,  1049,  1050,   528,   528,   528,
     528,  1038,  1039,  1040,  1041,   528,   445,   449,  1094,  1367,
    1093,  1089,   468,   528,   473,  1109,   307,  1115,  1090,  1119,
     484,  1088,  1178,  1106,   311,   956,  1008,  1197,  1198,  1218,
    1158,  1439,  1224,  1223,   415,  1226,  1234,  1236,  1519,  1520,
    1521,   764,  1240,  1260,  1261,  1247,  1262,  1263,  1266,  1267,
    1268,  1273,   307,  1274,  1277,  1278,  1284,  1290,   528,  1291,
     311,  1297,  1296,   307,  1292,  1299,  1303,  1319,  1337,  1344,
    1341,   311,   528,  1346,  1342,   724,  1366,  1343,  1473,  1368,
    1373,   415,   307,   528,  1392,  1393,  1404,  1396,    11,  1405,
     311,   416,  1407,  1423,  1428,  1416,  1408,  1494,  1409,  1410,
     415,  1437,   307,  1411,  1442,  1450,  1452,  1422,  1456,  1433,
     311,  1440,  1438,  1441,  1443,  1444,  1697,  1434,  1458,  1459,
    1505,   528,   758,  1460,  1464,  1469,  1448,  1701,  1617,  1472,
    1703,  1501,  1493,  1495,  1100,  1100,  1487,  1711,   416,  1496,
    1504,  1462,  1101,  1101,  1514,  1510,  1359,  1509,  1518,  1557,
    1158,  1499,  1538,  1541,  1558,  1551,  1562,   416,  1511,  1564,
    1570,  1571,  1512,  1572,   790,  1573,  1577,  1513,  1515,  1583,
    1574,  1575,  1576,  1586,  1158,  1588,  1590,   744,  1594,  1596,
    1601,  1608,  1609,  1610,  1613,  1642,  1654,  1667,  1669,  1614,
    1619,  1678,  1199,  1622,  1629,  1630,   550,  1635,  1592,  1655,
    1691,  1670,  1696,  1506,  1683,  1694,  1702,  1706,  1710,   857,
    1721,  1532,  1732,  1718,  1733,  1735,  1736,  1740,  1703,  1745,
    1741,  1747,  1749,  1748,  1734,  1763,  1765,   852,  1777,  1466,
     963,  1780,  1785,  1789,  1778,  1786,   527,  1793,  1792,   527,
    1797,  1812,  1816,  1668,  1815,   613,   940,  1800,  1801,   528,
    1421,  1690,  1806,   609,   705,  1180,  1782,  1259,  1436,  1803,
    1743,  1773,  1105,   528,  1256,  1036,   610,   528,   528,   741,
    1536,   307,  1775,  1795,  1606,  1804,  1813,  1463,   761,   311,
    1357,  1807,  1531,  1809,  1528,  1474,  1818,   806,  1798,  1478,
     528,  1484,   528,  1492,  1158,   894,   893,   932,   904,  1163,
     528,  1068,  1791,   528,  1788,  1503,  1231,   528,  1420,  1798,
    1517,   750,  1523,  1522,  1782,  1552,   683,  1556,  1666,  1665,
    1555,  1371,  1395,  1591,   751,  1585,  1204,  1675,  1553,  1429,
       0,   844,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1723,     0,   528,  1604,
    1605,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1729,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1621,     0,  1158,     0,     0,
    1158,     0,     0,     0,     0,     0,     0,   528,     0,     0,
       0,     0,  1633,     0,     0,     0,     0,  1637,  1100,     0,
       0,     0,     0,     0,     0,     0,  1101,     0,     0,  1100,
    1100,     0,   307,     0,   528,     0,     0,  1101,  1101,  1100,
     311,     0,     0,     0,     0,     0,     0,  1101,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   528,   528,   528,   528,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   528,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   528,     0,     0,     0,
    1100,     0,     0,     0,     0,     0,     0,     0,  1101,     0,
       0,  1100,     0,  1705,     0,  1707,     0,  1709,     0,  1101,
       0,   528,     0,     0,  1717,     0,     0,     0,     0,     0,
     528,     0,   528,     0,   528,     0,   528,     0,   307,     0,
       0,     0,     0,     0,     0,     0,   311,     0,     0,   528,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1158,
       0,  1158,     0,     0,     0,     0,     0,     0,     0,     0,
     307,     0,     0,     0,     0,     0,     0,  1739,   311,     0,
    1742,     0,   528,     0,   528,     0,     0,     0,     0,     0,
       0,  1100,  1158,     0,     0,     0,  1100,     0,     0,  1101,
       0,     0,  1750,     0,  1101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1158,     0,     0,     0,     0,     0,     0,     0,
    1776,     0,     0,     0,     0,  1779,     0,  1158,     0,  1158,
       0,     0,     0,     0,   550,     0,     0,   528,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1796,   528,   831,
     832,     0,     0,   841,   842,   843,   845,     0,   847,     0,
       0,     0,     0,  1802,   855,     0,     0,  1805,     0,     0,
       0,     0,   864,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1814,     0,     0,  1817,     0,     0,     0,
       0,     0,     0,     0,   884,   885,     0,     0,     0,     0,
       0,     0,     0,   891,   892,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     528,     0,     0,     0,   528,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   528,
       0,     0,     0,     0,   928,     0,     0,   928,   528,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   528,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   528,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   992,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   528,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   528,     0,     0,  1035,     0,
       0,     0,     0,     0,   528,     0,     0,   528,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1060,     0,     0,     0,  1062,  1063,     0,
       0,     0,     0,     0,     0,     0,   891,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   528,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   528,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1116,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   528,   528,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   528,     0,   528,     0,     0,   528,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     528,     0,     0,     0,     0,   528,     0,     0,     0,     0,
       0,     0,     0,     0,  1181,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1237,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1270,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1275,  1276,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1295,     0,     0,  1298,
       0,   528,     0,   528,     0,   528,     0,     0,     0,     0,
       0,     0,   528,     0,     0,  1322,  1323,  1324,     0,  1327,
    1328,  1329,  1330,  1331,  1332,  1333,  1334,  1335,     0,     0,
    1338,  1339,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1351,     0,     0,   528,     0,   528,
       0,     0,     0,  1116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   528,     0,     0,   528,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     528,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     528,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1417,     0,     0,     0,     0,     0,
     528,     0,     0,     0,     0,     0,     0,     0,   528,     0,
       0,     0,     0,   528,     0,   528,     0,   528,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   528,     0,     0,     0,     0,
       0,     0,  -851,   451,     0,   452,     0,     0,     0,     0,
       0,   528,     0,     0,     0,   528,  1449,     0,  1451,     0,
    1453,     0,     0,  1457,     0,     0,     0,     0,  1461,     0,
       0,   528,     0,     0,   528,     0,     0,     0,     0,     0,
    1467,     0,     0,     0,  -851,     0,     0,     0,  -851,  1471,
       0,     0,  -851,  -851,     0,  1475,  1476,  -851,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   453,     0,
       0,  -851,     0,   454,  1497,     0,     0,  1498,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -851,     0,  -851,  -851,  -851,     0,
       0,  -851,  -851,  -851,  -851,     0,     0,     0,  -851,  -851,
       0,     0,     0,     0,     0,  -851,     0,     0,  -851,  -851,
     455,     0,     0,  -851,     0,     0,     0,     0,  -851,  -851,
       0,     0,     0,     0,  -851,     0,     0,     0,  -851,     0,
       0,     0,  -851,  -851,  1116,  -851,     0,  -851,  -851,     0,
       0,     0,  -851,  -851,     0,     0,  -851,  -851,  -851,  -851,
    -851,  -851,     0,     0,  -851,     0,     0,     0,     0,  -851,
    -851,     0,     0,  -851,     0,     0,     0,     0,  -851,     0,
       0,  -851,     0,     0,     0,     0,  -851,  -851,  -851,  -851,
    -851,     0,  -851,  -851,  -851,  -851,  -851,     0,     0,     0,
       0,  -851,  -851,  -851,     0,  -851,  -851,  -851,  -851,  -851,
    -851,     0,  -851,     0,  -851,     0,     0,     0,     0,  -851,
    -851,  -851,     0,     0,  1595,     0,     0,     0,  1597,     0,
       0,     0,  1600,     0,  1602,  -851,  1603,  -851,     0,  -851,
       0,     0,  1607,     0,     0,     0,     0,     0,     0,     0,
    1612,  -851,     0,     0,     0,     0,  -851,     0,  1616,  1618,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1467,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1638,  1639,
    1640,  1641,     0,  1643,  1644,     0,  1645,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1653,     0,  -851,     0,  -851,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1692,     0,  1693,     0,     0,  1695,
       0,     0,     0,     0,     0,     0,     0,  1698,     0,     0,
       0,     0,  1700,  1618,     0,     0,     0,     0,     0,     0,
    1704,     0,     0,     0,  1708,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1720,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1725,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1744,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1704,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1783,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1794,     0,     0,     0,     0,  1799,     0,
       0,     1,     2,  1783,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,  1799,    11,
       0,     0,  1808,    12,    13,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
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
       0,   132,   133,     0,   134,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,   149,     0,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,     0,   244,     0,   245,   246,   247,   248,   249,   250,
     251,   252,   253,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,     0,     0,     0,    12,    13,     0,    14,    15,
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
     130,   131,     0,   132,   133,     0,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,   244,     0,   245,   246,   247,   248,
     249,   250,   251,     0,   605,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,   412,    28,    29,    30,    31,     0,    32,
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
     124,   125,     0,     0,   126,   127,   128,     0,   547,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
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
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,   412,    28,    29,    30,    31,     0,    32,
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
     124,   125,     0,     0,   126,   127,   128,     0,   808,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
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
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,  1096,   412,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,  1097,  1098,    50,    51,
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
     124,   125,     0,     0,   126,   127,   128,     0,   808,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,  1099,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,  1096,   412,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,  1097,  1098,    50,    51,
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
     124,   125,     0,     0,   126,   127,   128,     0,   547,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,  1099,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,   412,    28,    29,    30,    31,     0,    32,
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
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
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
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
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
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
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
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
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
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,    12,   411,     0,
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
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
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
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,   877,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,   412,    28,    29,    30,    31,     0,    32,
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
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
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
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,  1096,   412,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,  1097,  1098,    50,    51,
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
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,  1099,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   552,   412,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   553,   554,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   503,    82,    83,    84,
      85,    86,   555,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   556,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,   557,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   520,   521,   522,   176,   177,   523,   558,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   552,   412,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   553,   554,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   503,    82,    83,    84,
      85,    86,   555,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   556,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,   562,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   520,   521,   522,   176,   177,   523,   558,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   552,   412,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   553,   554,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   503,    82,    83,    84,
      85,    86,   555,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   556,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   520,   521,   522,   176,   177,   523,   558,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   600,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   552,   412,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   553,   554,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   503,    82,    83,    84,
      85,    86,   555,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   556,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   520,   521,   522,   176,   177,   523,   558,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,   602,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   552,   412,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   553,   554,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   503,    82,    83,    84,
      85,    86,   555,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   556,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,   921,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   520,   521,   522,   176,   177,   523,   558,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   552,   412,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   553,   554,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   503,    82,    83,    84,
      85,    86,   555,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   556,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,   927,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   520,   521,   522,   176,   177,   523,   558,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   552,   412,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   553,   554,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   503,    82,    83,    84,
      85,    86,   555,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   556,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,   931,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   520,   521,   522,   176,   177,   523,   558,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     489,    25,   491,   412,    28,   492,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,   494,     0,    45,    46,    47,   496,   497,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   503,    82,    83,    84,
      85,    86,   555,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   506,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   556,   109,     0,
     110,   111,   681,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     682,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   515,   160,
     516,   162,   517,   518,   165,   166,   167,   168,   169,   170,
     519,   172,   520,   521,   522,   176,   177,   523,   524,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   525,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   552,   412,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   553,   554,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   503,    82,    83,    84,
      85,    86,   555,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   556,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   520,   521,   522,   176,   177,   523,   558,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     489,    25,   491,   412,    28,   492,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,   494,     0,    45,    46,    47,   496,   497,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   503,    82,    83,    84,
      85,    86,   555,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   506,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   556,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   515,   160,
     516,   162,   517,   518,   165,   166,   167,   168,   169,   170,
     519,   172,   520,   521,   522,   176,   177,   523,   524,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   525,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     489,    25,   491,   412,    28,   492,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,   494,     0,    45,    46,    47,   496,   497,    50,   498,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   503,    82,    83,    84,
      85,    86,   555,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   506,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   556,   109,     0,
     110,   111,     0,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
       0,     0,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   515,   160,
     516,   162,   517,   518,   165,   166,   167,   168,   169,   170,
     519,   172,   520,   521,   522,   176,   177,   523,   524,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   525,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     489,    25,   491,   412,    28,   492,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,   494,     0,    45,    46,    47,   496,   497,    50,   498,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   503,    82,    83,    84,
      85,    86,   555,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   506,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   556,   109,     0,
     110,   111,     0,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
       0,     0,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,     0,     0,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   515,   160,
     516,   162,   517,   518,   165,   166,   167,   168,   169,   170,
     519,   172,   520,   521,   522,   176,   177,   523,   524,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   525,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     489,    25,   491,   412,    28,   492,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,   494,     0,    45,    46,    47,   496,   497,    50,   498,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   503,    82,    83,    84,
      85,    86,   555,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   506,
       0,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,     0,   106,   107,   556,   109,     0,
     110,   111,     0,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
       0,     0,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,     0,     0,     0,   134,     0,
     135,     0,   136,     0,   138,     0,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   515,   160,
     516,   162,   517,   518,   165,   166,   167,   168,   169,   170,
     519,   172,   520,   521,   522,   176,   177,   523,   524,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   525,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,   410,   411,     0,
      14,    15,    16,   486,    18,    19,    20,   487,    22,   488,
     489,   490,   491,   412,    28,   492,    30,    31,     0,    32,
      33,    34,    35,   493,    37,    38,    39,    40,    41,    42,
      43,   494,     0,    45,   495,    47,   496,   497,    50,   498,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   499,   500,    68,     0,    69,    70,
      71,   501,     0,     0,    74,    75,    76,     0,     0,   502,
      78,     0,     0,     0,     0,    80,   503,    82,   504,   505,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   506,
      97,    98,   507,   508,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,   105,   106,   107,     0,     0,     0,
       0,     0,     0,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   509,   120,   121,   510,     0,     0,     0,
       0,     0,     0,     0,   511,   512,   128,     0,     0,     0,
     129,     0,   130,   513,     0,     0,     0,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   514,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,     0,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   515,   160,
     516,   162,   517,   518,   165,   166,   167,   168,   169,   170,
     519,   172,   520,   521,   522,   176,   177,   523,   524,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     0,     0,     1,     2,   245,   525,
     247,   248,   249,   250,   251,     3,     0,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,   410,   411,
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
       0,   129,     0,   130,   513,     0,     0,     0,     0,   134,
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
     238,   239,   240,   241,   242,     0,     0,     0,   567,   245,
     525,   247,   248,   249,   250,   251,     7,     8,     0,     0,
       0,   783,     0,     0,     0,   410,   411,     0,    14,    15,
      16,   534,    18,    19,    20,   487,   535,   536,   489,   490,
     491,   412,    28,   492,    30,    31,     0,    32,    33,    34,
      35,   537,    37,   538,   539,    40,    41,    42,    43,   494,
       0,    45,   540,    47,   496,   497,    50,   498,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   499,   500,    68,     0,    69,    70,    71,   541,
       0,     0,    74,    75,    76,     0,     0,   502,    78,     0,
       0,     0,     0,    80,   503,    82,   504,   505,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   506,    97,    98,
     507,   508,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,   107,     0,     0,     0,     0,     0,
       0,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   509,   120,   121,   510,     0,     0,     0,     0,     0,
       0,     0,   511,   512,   128,     0,     0,     0,   129,   784,
     130,   513,     0,     0,     0,     0,     0,     0,   135,     0,
     136,   137,   138,   139,   514,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,     0,     0,   413,   151,   152,
     153,   154,   155,   156,   157,   158,   515,   542,   516,   162,
     517,   518,   165,   166,   167,   168,   169,   170,   519,   172,
     520,   521,   522,   176,   177,   523,   524,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     0,     0,     0,   567,   245,   525,   247,   248,
     249,   250,   251,     7,     8,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,   135,     0,   136,   137,   138,
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
       0,     0,     0,   245,   525,   247,   248,   249,   250,   251,
     570,   571,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,   410,   411,     0,    14,    15,
      16,   534,    18,    19,    20,   487,   535,   536,   489,   490,
     491,   412,    28,   492,    30,    31,     0,    32,    33,    34,
      35,   537,    37,   538,   539,    40,    41,    42,    43,   494,
       0,    45,   540,    47,   496,   497,    50,   498,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   499,   500,    68,     0,    69,    70,    71,   541,
       0,     0,    74,    75,    76,     0,     0,   502,    78,     0,
       0,     0,     0,    80,   503,    82,   504,   505,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   506,    97,    98,
     507,   508,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,   107,     0,     0,     0,     0,     0,
       0,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   509,   120,   121,   510,     0,     0,     0,     0,     0,
       0,     0,   511,   512,   128,     0,     0,     0,   129,     0,
     130,   513,     0,     0,     0,     0,     0,     0,   135,     0,
     136,   137,   138,   139,   514,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,     0,     0,   413,   151,   152,
     153,   154,   155,   156,   157,   158,   515,   542,   516,   162,
     517,   518,   165,   166,   167,   168,   169,   170,   519,   172,
     520,   521,   522,   176,   177,   523,   524,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     0,     0,     0,     0,   245,   525,   247,   248,
     249,   250,   251,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   410,   411,     0,    14,    15,
      16,   833,    18,    19,    20,    21,   535,   834,   489,    25,
     491,   412,    28,   492,    30,    31,     0,    32,    33,    34,
      35,   835,    37,   538,   539,    40,    41,    42,    43,   494,
       0,    45,   836,    47,   496,   497,    50,   498,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   499,   500,    68,     0,    69,    70,    71,   837,
       0,     0,    74,    75,    76,     0,     0,   502,    78,     0,
       0,     0,    79,    80,   503,    82,   504,   505,    85,    86,
     555,    88,     0,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   506,    97,    98,
     507,   508,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   556,   109,     0,   110,   111,
       0,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   510,     0,   123,     0,     0,     0,
       0,     0,   511,   512,   128,     0,     0,     0,   129,     0,
     130,   513,     0,     0,     0,     0,     0,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   413,   151,   152,
     153,   154,   155,   156,   157,   158,   515,   542,   516,   162,
     517,   518,   165,   166,   167,   168,   169,   170,   519,   172,
     520,   521,   522,   176,   177,   523,   524,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,   244,     0,   245,   525,   247,   248,
     249,   250,   251,     7,     8,     0,     0,     0,     0,     0,
       0,     0,   410,   411,     0,    14,    15,    16,   486,    18,
      19,    20,   487,    22,   488,   489,  1138,   491,   412,    28,
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
     106,  1139,     0,     0,     0,  1140,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   509,   120,
     121,   510,     0,     0,     0,     0,     0,     0,     0,   511,
     512,   128,     0,     0,     0,   129,  1566,   130,   513,     0,
       0,     0,     0,  1567,     0,   135,     0,   136,   137,   138,
     139,   514,   141,   142,   143,   144,   145,   146,     0,     0,
    1141,   148,     0,     0,   413,   151,   152,   153,   154,   155,
     156,   157,   158,   515,   160,   516,   162,   517,   518,   165,
     166,   167,   168,   169,   170,   519,   172,   520,   521,   522,
     176,   177,   523,   524,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     7,     8,   245,   525,   247,  1142,  1143,  1144,  1145,
     410,   411,     0,    14,    15,    16,   534,    18,    19,    20,
     487,   535,   536,   489,   490,   491,   412,    28,   492,    30,
      31,     0,    32,    33,    34,    35,   537,    37,   538,   539,
      40,    41,    42,    43,   494,     0,    45,   540,    47,   496,
     497,    50,   498,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   499,   500,    68,
       0,    69,    70,    71,   541,     0,     0,    74,    75,    76,
       0,     0,   502,    78,     0,     0,     0,     0,    80,   503,
      82,   504,   505,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   506,    97,    98,   507,   508,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,   107,
       0,     0,     0,     0,     0,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   509,   120,   121,   510,
       0,     0,     0,     0,     0,     0,     0,   511,   512,   128,
       0,     0,     0,   129,   753,   130,   513,     0,     0,     0,
       0,   754,     0,   135,     0,   136,   137,   138,   139,   514,
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
       0,   129,   801,   130,   513,     0,     0,     0,     0,   802,
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
      15,    16,   486,    18,    19,    20,   487,    22,   488,   489,
    1138,   491,   412,    28,   492,    30,    31,     0,    32,    33,
      34,    35,   493,    37,    38,    39,    40,    41,    42,    43,
     494,     0,    45,   495,    47,   496,   497,    50,   498,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   499,   500,    68,     0,    69,    70,    71,
     501,     0,     0,    74,    75,    76,     0,     0,   502,    78,
       0,     0,     0,     0,    80,   503,    82,   504,   505,    85,
      86,  1485,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   506,    97,
      98,   507,   508,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,  1139,     0,     0,     0,  1140,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   509,   120,   121,   510,     0,     0,     0,     0,
       0,     0,     0,   511,   512,   128,     0,     0,     0,   129,
       0,   130,   513,     0,     0,     0,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   514,   141,   142,   143,   144,
     145,   146,     0,     0,  1141,   148,     0,     0,   413,   151,
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
    1142,  1143,  1144,  1145,   410,   411,     0,    14,    15,    16,
     486,    18,    19,    20,   487,    22,   488,   489,  1138,   491,
     412,    28,   492,    30,    31,     0,    32,    33,    34,    35,
     493,    37,    38,    39,    40,    41,    42,    43,   494,     0,
      45,   495,    47,   496,   497,    50,   498,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   499,   500,    68,     0,    69,    70,    71,   501,     0,
       0,    74,    75,    76,     0,     0,   502,    78,     0,     0,
       0,     0,    80,   503,    82,   504,   505,    85,    86,  1623,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   506,    97,    98,   507,
     508,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,  1139,     0,     0,     0,  1140,     0,     0,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     509,   120,   121,   510,     0,     0,     0,     0,     0,     0,
       0,   511,   512,   128,     0,     0,     0,   129,     0,   130,
     513,     0,     0,     0,     0,     0,     0,   135,     0,   136,
     137,   138,   139,   514,   141,   142,   143,   144,   145,   146,
       0,     0,  1141,   148,     0,     0,   413,   151,   152,   153,
     154,   155,   156,   157,   158,   515,   160,   516,   162,   517,
     518,   165,   166,   167,   168,   169,   170,   519,   172,   520,
     521,   522,   176,   177,   523,   524,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,     0,     7,     8,   245,   525,   247,  1142,  1143,
    1144,  1145,   410,   411,     0,    14,    15,    16,   486,    18,
      19,    20,   487,    22,   488,   489,  1138,   491,   412,    28,
     492,    30,    31,     0,    32,    33,    34,    35,   493,    37,
      38,    39,    40,    41,    42,    43,   494,     0,    45,   495,
      47,   496,   497,    50,   498,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   499,
     500,    68,     0,    69,    70,    71,   501,     0,     0,    74,
      75,    76,     0,     0,   502,    78,     0,     0,     0,     0,
      80,   503,    82,   504,   505,    85,    86,  1627,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   506,    97,    98,   507,   508,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,  1139,     0,     0,     0,  1140,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   509,   120,
     121,   510,     0,     0,     0,     0,     0,     0,     0,   511,
     512,   128,     0,     0,     0,   129,     0,   130,   513,     0,
       0,     0,     0,     0,     0,   135,     0,   136,   137,   138,
     139,   514,   141,   142,   143,   144,   145,   146,     0,     0,
    1141,   148,     0,     0,   413,   151,   152,   153,   154,   155,
     156,   157,   158,   515,   160,   516,   162,   517,   518,   165,
     166,   167,   168,   169,   170,   519,   172,   520,   521,   522,
     176,   177,   523,   524,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     7,     8,   245,   525,   247,  1142,  1143,  1144,  1145,
     410,   411,     0,    14,    15,    16,   486,    18,    19,    20,
     487,    22,   488,   489,  1138,   491,   412,    28,   492,    30,
      31,     0,    32,    33,    34,    35,   493,    37,    38,    39,
      40,    41,    42,    43,   494,     0,    45,   495,    47,   496,
     497,    50,   498,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   499,   500,    68,
       0,    69,    70,    71,   501,     0,     0,    74,    75,    76,
       0,     0,   502,    78,     0,     0,     0,     0,    80,   503,
      82,   504,   505,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   506,    97,    98,   507,   508,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,  1139,
       0,     0,     0,  1140,     0,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   509,   120,   121,   510,
       0,     0,     0,     0,     0,     0,     0,   511,   512,   128,
       0,     0,     0,   129,     0,   130,   513,     0,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   514,
     141,   142,   143,   144,   145,   146,     0,     0,  1141,   148,
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
       8,   245,   525,   247,  1142,  1143,  1144,  1145,   410,   411,
       0,    14,    15,    16,   486,    18,    19,    20,   487,    22,
     488,   489,  1138,   491,   412,    28,   492,    30,    31,     0,
      32,    33,    34,    35,   493,    37,    38,    39,    40,    41,
      42,    43,   494,     0,    45,   495,    47,   496,   497,    50,
     498,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   499,   500,    68,     0,    69,
      70,    71,   501,     0,     0,    74,    75,    76,     0,     0,
     502,    78,     0,     0,     0,     0,    80,   503,    82,   504,
     505,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     506,    97,    98,   507,   508,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,  1139,     0,     0,
       0,  1140,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   509,   120,   121,   510,     0,     0,
       0,     0,     0,     0,     0,   511,   512,   128,     0,     0,
       0,   129,     0,   130,   513,     0,     0,     0,     0,     0,
       0,   135,     0,   136,   137,   138,   139,   514,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,     0,     0,
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
     525,   247,  1142,  1143,  1144,  1145,   410,   411,     0,    14,
      15,    16,   534,    18,    19,    20,   487,   535,   536,   489,
     490,   491,   412,    28,   492,    30,    31,     0,    32,    33,
      34,    35,   537,    37,   538,   539,    40,    41,    42,    43,
     494,     0,    45,   540,    47,   496,   497,    50,   498,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   499,   500,    68,     0,    69,    70,    71,
     541,     0,     0,    74,    75,    76,     0,     0,   502,    78,
       0,     0,     0,     0,    80,   503,    82,   504,   505,    85,
      86,  1232,     0,     0,     0,     0,     0,     0,     0,    91,
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
     240,   241,   242,     0,     0,     7,     8,   245,   525,   247,
     248,   249,   250,   251,   410,   411,     0,    14,    15,    16,
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
       0,   511,   512,   128,     0,     0,     0,   129,     0,   130,
     513,     0,     0,     0,     0,     0,     0,   135,     0,   136,
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
     250,   251,   410,   411,     0,    14,    15,    16,     0,    18,
      19,    20,   487,     0,     0,   489,   490,     0,   412,    28,
     492,    30,    31,     0,    32,    33,    34,    35,     0,    37,
       0,     0,    40,    41,    42,    43,   494,     0,    45,     0,
      47,     0,     0,    50,   498,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   499,
     500,    68,     0,    69,    70,    71,     0,     0,     0,    74,
      75,    76,     0,     0,   502,    78,     0,     0,     0,     0,
      80,   503,    82,   504,   505,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   506,    97,    98,   507,   508,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,     0,     0,     0,     0,     0,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   509,   120,
     121,   510,     0,     0,     0,     0,     0,     0,     0,   511,
     512,   128,     0,     0,     0,   129,     0,   130,   513,     0,
       0,     0,     0,     0,     0,   135,     0,   136,   137,   138,
     139,   514,   141,   142,   143,   144,   145,   146,     0,     0,
       0,   148,     0,     0,   413,   151,   152,   153,   154,   155,
     156,   157,   158,   515,     0,   516,   162,   517,   518,   165,
     166,   167,   168,   169,   170,   519,   172,   520,   521,   522,
     176,   177,     0,   524,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     0,     0,   245,   525,   247,   248,   249,   250,   251
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   419,   420,    12,     4,     5,     6,   684,     0,   291,
     668,   179,     4,     5,     6,   778,   109,   110,   311,     4,
       5,     6,     4,     5,     6,   821,   340,   790,   669,   670,
     671,   672,  1285,   260,  1047,   758,  1031,   917,   618,   619,
     259,   804,  1071,  1302,   133,   583,   421,     1,   275,    73,
     758,   589,   859,  1363,  1364,   252,   253,     1,   616,   617,
     433,   988,  1124,   938,    55,   616,   617,   618,   619,    39,
      36,   444,     1,     1,    44,    45,   903,    36,   714,     4,
       5,     6,    96,    26,    27,  1006,   461,   462,  1396,    59,
      29,    61,    62,  1315,    26,    27,   469,     1,   118,   954,
      70,   107,   107,     1,    47,     1,    29,     1,   108,    54,
     142,    56,   225,    56,     1,    47,   108,   647,   282,   649,
     650,   107,   652,     1,   654,  1588,   108,    97,  1008,     1,
      96,    74,   662,   663,   416,    94,    79,    96,     1,     1,
       1,  1021,    74,    29,     1,   107,    26,    27,     1,   107,
     243,   244,  1653,   107,   100,   100,   107,    37,    38,     1,
      40,    41,    30,   107,   153,   107,   118,    47,   111,   112,
     113,   110,     1,    73,   153,    45,    56,    57,   107,   107,
     112,   147,   188,   108,     8,   124,   169,    87,   147,    96,
     916,   917,    62,   156,    74,     0,     1,   960,   291,    79,
      33,   314,   118,   107,   190,   225,   113,     1,   268,     1,
     149,   111,   160,   107,   153,   275,    49,   156,  1528,   202,
     107,   210,   184,   123,  1725,   125,   217,   113,   954,     1,
     235,   111,   112,   113,   186,     1,   187,   160,   177,   147,
     186,   273,   256,   257,   107,   187,    94,  1500,     9,    10,
     107,  1014,   252,   253,   343,   225,   256,  1020,   187,   187,
     252,   253,   988,   254,   256,   107,     1,   549,   561,  1282,
      96,  1067,  1735,  1268,   160,   233,   440,  1306,   107,  1587,
     160,  1503,  1008,   187,    93,  1140,  1315,   307,   868,   869,
    1013,   291,   190,   187,   190,  1021,  1223,  1124,  1125,   291,
     187,  1176,   107,  1011,   940,  1013,   251,   273,   866,   867,
    1372,  1232,   190,   107,   273,   107,     1,   187,   190,   264,
     259,   266,   185,   416,   348,  1033,     1,   351,   190,   190,
     187,     1,   277,   278,   279,   107,   281,   190,   283,   107,
     220,   107,   103,   169,   287,   187,   214,   317,   318,   319,
     725,   175,   295,   635,   147,   287,   449,   273,   187,   313,
     303,    76,   123,   295,   125,   273,   459,   311,   107,   899,
     218,   219,   107,   118,   183,   468,  1686,   107,   100,   184,
    1260,   261,   475,   476,     1,   233,   613,   614,   122,  1648,
       5,   484,   153,   187,     9,   187,   157,   616,   617,   772,
      52,   776,   775,   107,  1284,     0,     1,   287,   605,   100,
       1,     1,   184,   174,  1140,   295,   416,   131,   154,   187,
     156,   187,   107,   303,   416,   156,   252,   253,  1738,   255,
     225,    94,   107,   107,   195,   230,   262,   107,   153,   225,
     106,   227,   187,   107,   156,   445,   272,   447,   348,   188,
     185,   351,   213,   445,   121,   447,   549,   187,   284,  1222,
     107,   127,   744,   445,   186,   447,   156,    37,    38,  1722,
      40,    41,   565,   473,  1503,     1,   190,   129,   478,   142,
     273,   473,     1,   187,   577,   903,   478,    57,   107,     1,
     107,   473,    26,    27,    42,   186,   478,  1223,    46,   184,
      96,   237,   156,    51,   597,   598,   221,   222,   123,   184,
     125,  1234,   107,   187,   184,   933,   107,   107,   133,   314,
     445,    69,   447,   187,  1404,   154,   426,   156,   314,   429,
    1110,  1111,  1112,   433,  1260,  1243,   436,   437,   153,  1346,
     187,  1218,  1349,   113,   444,  1372,     9,    10,   473,   549,
     450,   451,  1090,   478,  1381,   455,   556,   549,  1284,  1110,
    1111,  1112,    94,   463,   556,  1392,   233,   184,   187,   469,
     470,   471,   472,   169,   556,   857,    96,   477,   112,   130,
      45,   107,    47,     9,    10,   485,   961,   962,   107,   184,
     160,   966,   685,   184,   184,   107,   136,   690,   598,   688,
     689,     1,   611,     3,  1367,   605,   598,  1487,     5,   156,
    1490,   118,     9,   605,    29,  1610,   616,   617,   618,   619,
     168,   996,   107,   171,   616,   617,   618,   619,   107,   130,
     530,   556,    96,     9,  1647,   635,   156,   217,   186,   156,
     103,   106,    94,   635,   544,   872,   197,   866,   875,   113,
     220,   744,    28,    94,   106,   555,   252,   253,   184,   255,
     123,   201,   125,    96,   212,   184,    66,   158,   225,    94,
     227,    71,   184,   598,   254,   118,   272,   103,  1404,   186,
       9,    10,    45,   583,    47,   176,   218,   219,   284,   589,
     153,   261,   156,   593,   157,   110,   197,   123,    29,   125,
      94,   233,   187,   168,   117,  1501,  1124,  1125,   187,   124,
    1506,   174,    94,   154,   147,   156,    79,   142,   118,   812,
     813,   814,    96,   816,    96,  1383,   123,   153,   125,  1452,
    1557,   157,   195,   146,   149,   153,   133,    53,   153,   113,
     118,   156,    58,   106,   744,   153,   159,   123,   174,   125,
     213,   951,   744,   147,   166,   158,   153,   314,   134,   177,
    1437,  1487,   177,   963,  1490,   147,   156,   148,   768,   195,
     182,     9,  1352,   176,   103,   147,   768,   153,   269,   110,
      96,   194,   156,   768,   165,   276,   768,   213,    42,  1669,
      28,  1671,    46,   124,   123,   286,   125,    51,   798,   799,
      42,  1002,   210,  1004,    46,   168,   798,   799,  1101,    51,
     144,    73,  1126,  1095,   156,    69,   798,   799,   149,   269,
     153,   721,  1702,   263,   153,    87,   276,    69,   157,   122,
    1713,  1714,    33,    94,   274,   735,   286,  1633,    94,   739,
     740,  1637,   176,   768,   177,   174,    53,   263,    49,   111,
     106,    58,  1732,  1054,   137,  1056,   153,   857,   274,   142,
     194,   123,   762,   125,   764,   857,   195,  1747,   877,  1749,
      77,  1754,   772,   798,   799,   775,   137,  1760,   122,   779,
    1107,   142,   137,   158,   213,   123,   142,   125,  1263,    96,
    1548,  1549,   158,   182,    24,    95,   134,   122,   153,   201,
    1541,   176,   247,   248,    34,   148,   106,   196,   210,   153,
     176,   118,   156,  1590,   168,   153,   116,   171,   137,   122,
     820,  1717,   165,  1686,   199,   270,   168,   127,   136,   171,
      60,  1099,   186,   199,   153,   182,  1104,   100,   100,   100,
     100,   122,   150,  1669,   186,  1671,   299,   118,   100,   196,
     113,   113,   113,   113,  1372,   308,   191,   192,   212,   859,
     132,   113,   100,  1381,   221,   222,   223,   137,   140,   141,
     212,   143,   142,    53,  1392,   113,  1702,   620,    58,   151,
    1262,   624,   122,   155,  1359,   157,   886,   277,   278,   279,
     162,   691,   216,   283,   694,   153,   122,   697,   156,  1657,
    1658,   347,   153,   122,   350,   156,  1732,   179,   153,   153,
     122,   156,   156,   122,  1691,   122,   916,   917,   918,   919,
     232,  1747,   234,  1749,   128,   129,   232,   156,   234,   153,
    1123,   203,   204,   205,   206,   207,   208,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,   128,   129,  1049,
     666,   667,   673,   674,   954,   675,   676,  1049,   118,  1736,
    1216,  1217,   241,  1345,  1578,  1579,   241,  1049,   968,   242,
    1728,   156,     0,   314,   153,   190,   167,    92,    99,    50,
     249,   101,   200,   102,   154,   193,   348,   145,   156,   351,
     184,   184,   184,   993,  1469,  1095,    29,    47,   152,   246,
    1109,   118,  1002,  1095,  1004,   304,  1006,   284,  1008,   187,
    1110,  1111,  1112,   118,   153,     1,   284,   118,  1110,  1111,
    1112,  1021,   107,   187,  1049,   153,   142,   153,   142,   156,
    1807,   156,  1809,   156,   156,   184,    35,   121,   156,  1557,
      17,  1818,   214,   156,   156,   156,   153,    29,   231,   187,
     190,     3,   118,   230,  1054,   190,  1056,  1532,   245,   168,
     170,    70,   170,   425,   426,   231,   149,   429,    94,    94,
      94,   433,   107,   107,   436,   437,    29,   132,   160,   160,
     127,   246,   444,    94,   142,   299,   118,   132,   450,   451,
    1090,   184,   184,   455,   107,    96,   187,   187,    94,  1481,
      45,   463,    96,    94,   184,   153,   184,   469,   470,   471,
     472,   187,   187,   187,   187,   477,   153,   153,   190,  1119,
     142,   225,   153,   485,   153,    33,  1226,   170,   231,   118,
     153,   237,   132,   233,  1226,   142,    94,    29,   286,   227,
    1140,  1226,   299,    94,  1226,   153,   127,   118,  1341,  1342,
    1343,   118,   147,    94,   184,   254,   198,   132,   160,   132,
      96,   153,  1262,   118,   147,   100,   100,   184,   530,   184,
    1262,   190,   142,  1273,   153,   121,    35,    29,   118,   153,
     156,  1273,   544,   245,   156,    79,   107,   156,  1273,   107,
     285,  1273,  1292,   555,   258,   260,   156,   267,    29,   156,
    1292,  1226,   156,    29,    29,   144,   156,  1292,   156,   156,
    1292,   227,  1312,   156,   144,   147,   127,   286,   147,   287,
    1312,   187,   190,   187,   187,   187,  1608,   306,   147,   118,
    1312,   593,  1232,   118,    77,   107,  1236,  1619,  1620,   142,
    1622,   132,   184,   187,  1344,  1345,   100,  1629,  1273,   187,
       7,  1251,  1344,  1345,    96,   233,   106,   190,   186,   147,
    1260,   198,   187,   250,   282,   250,   286,  1292,   233,    78,
     187,   187,   233,   187,  1274,   187,    29,   233,   237,    29,
     187,   187,   187,   271,  1284,   107,   170,  1312,   184,   147,
     147,   126,   126,    96,   184,   316,   142,   153,    94,   186,
     186,    29,    96,   186,   186,   184,   108,   184,   257,   184,
     170,   187,    53,  1313,   187,   147,    94,   186,   186,  1344,
     198,   106,    94,   197,    29,   107,   107,   118,  1710,   118,
     225,    94,    94,   186,   265,   197,   197,  1337,   118,  1721,
     724,   186,   186,   183,   225,    93,  1346,   118,   197,  1349,
     118,   199,   118,   280,   225,   259,   718,   186,   186,   721,
    1179,   287,   186,   256,   420,   955,  1748,  1022,  1223,   293,
    1691,  1736,   860,   735,  1019,   781,   256,   739,   740,   440,
    1368,  1481,   305,   305,  1462,   305,   287,  1252,   455,  1481,
    1115,   306,  1366,   306,  1363,  1274,   306,   544,  1780,  1279,
     762,  1282,   764,  1287,  1404,   646,   645,   699,   665,   919,
     772,   821,  1760,   775,  1754,  1306,  1004,   779,  1178,  1801,
    1337,   448,  1347,  1346,  1806,  1381,   335,  1392,  1557,  1554,
    1385,  1125,  1134,  1433,   448,  1427,   987,  1581,  1382,  1201,
      -1,   587,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1649,    -1,   820,  1459,
    1460,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1667,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1485,    -1,  1487,    -1,    -1,
    1490,    -1,    -1,    -1,    -1,    -1,    -1,   859,    -1,    -1,
      -1,    -1,  1502,    -1,    -1,    -1,    -1,  1507,  1608,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1608,    -1,    -1,  1619,
    1620,    -1,  1622,    -1,   886,    -1,    -1,  1619,  1620,  1629,
    1622,    -1,    -1,    -1,    -1,    -1,    -1,  1629,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   916,   917,   918,   919,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   954,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   968,    -1,    -1,    -1,
    1710,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1710,    -1,
      -1,  1721,    -1,  1623,    -1,  1625,    -1,  1627,    -1,  1721,
      -1,   993,    -1,    -1,  1634,    -1,    -1,    -1,    -1,    -1,
    1002,    -1,  1004,    -1,  1006,    -1,  1008,    -1,  1748,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1748,    -1,    -1,  1021,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1669,
      -1,  1671,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1780,    -1,    -1,    -1,    -1,    -1,    -1,  1687,  1780,    -1,
    1690,    -1,  1054,    -1,  1056,    -1,    -1,    -1,    -1,    -1,
      -1,  1801,  1702,    -1,    -1,    -1,  1806,    -1,    -1,  1801,
      -1,    -1,  1712,    -1,  1806,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1732,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1740,    -1,    -1,    -1,    -1,  1745,    -1,  1747,    -1,  1749,
      -1,    -1,    -1,    -1,   556,    -1,    -1,  1119,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1777,  1140,   581,
     582,    -1,    -1,   585,   586,   587,   588,    -1,   590,    -1,
      -1,    -1,    -1,  1793,   596,    -1,    -1,  1797,    -1,    -1,
      -1,    -1,   604,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1813,    -1,    -1,  1816,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   626,   627,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   635,   636,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1232,    -1,    -1,    -1,  1236,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1251,
      -1,    -1,    -1,    -1,   696,    -1,    -1,   699,  1260,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1284,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   737,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1313,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1337,    -1,    -1,   780,    -1,
      -1,    -1,    -1,    -1,  1346,    -1,    -1,  1349,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   805,    -1,    -1,    -1,   809,   810,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   818,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1404,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1433,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   888,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1459,  1460,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1485,    -1,  1487,    -1,    -1,  1490,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1502,    -1,    -1,    -1,    -1,  1507,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   956,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   991,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1010,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1032,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1043,  1044,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1058,    -1,    -1,  1061,
      -1,  1623,    -1,  1625,    -1,  1627,    -1,    -1,    -1,    -1,
      -1,    -1,  1634,    -1,    -1,  1077,  1078,  1079,    -1,  1081,
    1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,    -1,    -1,
    1092,  1093,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1106,    -1,    -1,  1669,    -1,  1671,
      -1,    -1,    -1,  1115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1687,    -1,    -1,  1690,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1702,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1712,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1166,    -1,    -1,    -1,    -1,    -1,
    1732,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1740,    -1,
      -1,    -1,    -1,  1745,    -1,  1747,    -1,  1749,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1777,    -1,    -1,    -1,    -1,
      -1,    -1,     0,     1,    -1,     3,    -1,    -1,    -1,    -1,
      -1,  1793,    -1,    -1,    -1,  1797,  1238,    -1,  1240,    -1,
    1242,    -1,    -1,  1245,    -1,    -1,    -1,    -1,  1250,    -1,
      -1,  1813,    -1,    -1,  1816,    -1,    -1,    -1,    -1,    -1,
    1262,    -1,    -1,    -1,    42,    -1,    -1,    -1,    46,  1271,
      -1,    -1,    50,    51,    -1,  1277,  1278,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,
      -1,    69,    -1,    71,  1296,    -1,    -1,  1299,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    94,    95,    96,    -1,
      -1,    99,   100,   101,   102,    -1,    -1,    -1,   106,   107,
      -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,   116,   117,
     118,    -1,    -1,   121,    -1,    -1,    -1,    -1,   126,   127,
      -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,   136,    -1,
      -1,    -1,   140,   141,  1366,   143,    -1,   145,   146,    -1,
      -1,    -1,   150,   151,    -1,    -1,   154,   155,   156,   157,
     158,   159,    -1,    -1,   162,    -1,    -1,    -1,    -1,   167,
     168,    -1,    -1,   171,    -1,    -1,    -1,    -1,   176,    -1,
      -1,   179,    -1,    -1,    -1,    -1,   184,   185,   186,   187,
     188,    -1,   190,   191,   192,   193,   194,    -1,    -1,    -1,
      -1,   199,   200,   201,    -1,   203,   204,   205,   206,   207,
     208,    -1,   210,    -1,   212,    -1,    -1,    -1,    -1,   217,
     218,   219,    -1,    -1,  1446,    -1,    -1,    -1,  1450,    -1,
      -1,    -1,  1454,    -1,  1456,   233,  1458,   235,    -1,   237,
      -1,    -1,  1464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1472,   249,    -1,    -1,    -1,    -1,   254,    -1,  1480,  1481,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1499,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1510,  1511,
    1512,  1513,    -1,  1515,  1516,    -1,  1518,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1533,    -1,   311,    -1,   313,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1596,    -1,  1598,    -1,    -1,  1601,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1609,    -1,    -1,
      -1,    -1,  1614,  1615,    -1,    -1,    -1,    -1,    -1,    -1,
    1622,    -1,    -1,    -1,  1626,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1642,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1654,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1694,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1706,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1748,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1775,    -1,    -1,    -1,    -1,  1780,    -1,
      -1,    11,    12,  1785,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,  1800,    29,
      -1,    -1,  1804,    33,    34,    -1,    36,    37,    38,    39,
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
      -1,   191,   192,    -1,   194,    -1,   196,    -1,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,    -1,
      -1,   211,   212,   213,    -1,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    -1,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,    -1,   312,    -1,   314,   315,   316,   317,   318,   319,
     320,   321,   322,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
     308,   309,   310,    -1,   312,    -1,   314,   315,   316,   317,
     318,   319,   320,    -1,   322,    11,    12,    -1,    -1,    -1,
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
     176,   177,    -1,    -1,   180,   181,   182,    -1,   184,    -1,
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
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
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
     176,   177,    -1,    -1,   180,   181,   182,    -1,   184,    -1,
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
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
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
     176,   177,    -1,    -1,   180,   181,   182,    -1,   184,    -1,
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
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
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
     176,   177,    -1,    -1,   180,   181,   182,    -1,   184,    -1,
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
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
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
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
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
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
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
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
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
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
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
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
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
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
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
     176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,   185,
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
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
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
     186,   187,   188,   189,    -1,   191,   192,    -1,   194,    -1,
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
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
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
     306,   307,   308,   309,   310,   311,   312,    -1,   314,   315,
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
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
     306,   307,   308,   309,   310,    -1,   312,   313,   314,   315,
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
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
     176,   177,    -1,    -1,   180,   181,   182,    -1,   184,    -1,
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
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
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
     186,   187,   188,   189,    -1,   191,   192,    -1,   194,    -1,
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
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
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
     186,   187,   188,   189,    -1,   191,   192,    -1,   194,    -1,
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
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
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
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
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
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
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
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
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
     156,   157,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
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
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
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
     156,   157,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,    -1,    -1,    -1,   194,    -1,
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
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
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
      -1,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,    -1,   151,   152,   153,   154,    -1,
     156,   157,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,    -1,    -1,    -1,   194,    -1,
     196,    -1,   198,    -1,   200,    -1,   202,   203,   204,   205,
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
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
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
      -1,    -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,    -1,    -1,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,    -1,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,    -1,    -1,    11,    12,   314,   315,
     316,   317,   318,   319,   320,    20,    -1,    -1,    -1,    24,
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
      -1,    -1,    -1,    -1,   159,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,   194,
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
     305,   306,   307,   308,   309,    -1,    -1,    -1,    16,   314,
     315,   316,   317,   318,   319,   320,    24,    25,    -1,    -1,
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
     188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,    -1,    -1,   211,   212,    -1,    -1,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,    -1,    -1,    -1,    16,   314,   315,   316,   317,
     318,   319,   320,    24,    25,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,   314,   315,   316,   317,   318,   319,   320,
      18,    19,    -1,    -1,    -1,    -1,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
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
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,    -1,    -1,   211,   212,    -1,    -1,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,    -1,    -1,    -1,    -1,   314,   315,   316,   317,
     318,   319,   320,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      -1,    -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,    -1,   124,    -1,   126,   127,
     128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,
     138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
      -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,   174,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,
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
     318,   319,   320,    24,    25,    -1,    -1,    -1,    -1,    -1,
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
     151,   152,    -1,    -1,    -1,   156,    -1,    -1,   159,   160,
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
     113,   114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,   152,
      -1,    -1,    -1,    -1,    -1,    -1,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,   187,   188,   189,    -1,    -1,    -1,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
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
      -1,   186,   187,   188,   189,    -1,    -1,    -1,    -1,   194,
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
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
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
     111,   112,   113,   114,   115,   116,   117,   118,    -1,    -1,
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
     113,   114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,
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
     115,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     319,   320,    33,    34,    -1,    36,    37,    38,    -1,    40,
      41,    42,    43,    -1,    -1,    46,    47,    -1,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    -1,    60,
      -1,    -1,    63,    64,    65,    66,    67,    -1,    69,    -1,
      71,    -1,    -1,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    -1,    -1,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
      -1,    -1,    -1,    -1,    -1,   196,    -1,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,    -1,    -1,
      -1,   212,    -1,    -1,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    -1,
      -1,    -1,    -1,   314,   315,   316,   317,   318,   319,   320
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
     422,   424,   425,   430,   449,   452,   456,   459,   460,   465,
     466,   467,   468,   470,   471,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   483,   484,   485,   486,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   519,   520,   521,   535,   536,
     538,   539,   540,   541,   542,   543,   544,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   564,   565,   566,
     567,   572,   573,   574,   575,   576,   577,   580,   638,   639,
     640,   641,   643,   644,   645,   646,   647,   654,   655,   656,
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
     238,   239,   240,   243,   244,   315,   503,   654,   655,   122,
     118,   400,   122,   122,    39,    44,    45,    59,    61,    62,
      70,    97,   225,   654,   118,   122,   122,   184,   391,   393,
     413,   642,    48,    72,    73,   118,   153,   185,   244,   412,
     414,   424,   187,   412,   654,   153,   122,    16,   653,   654,
      18,    19,   654,   122,   122,   122,   495,   153,    30,   214,
     216,   225,   227,   314,   156,   225,   227,   314,   225,   314,
     225,   230,   314,   118,   241,   241,   242,   156,   153,   395,
     311,   412,   313,   412,   314,   322,   337,   337,     0,   339,
     340,    33,    49,   342,   359,     1,   190,   336,   190,   336,
     112,   374,   394,   412,   107,   190,   107,   336,   190,    42,
      46,    51,    69,   168,   171,   186,   212,   407,   416,   421,
     422,   423,   437,   438,   442,   167,    92,   132,   140,   141,
     143,   151,   155,   157,   162,   179,   203,   204,   205,   206,
     207,   208,   487,   488,   249,    99,   158,   176,   199,   117,
     146,   159,   194,   201,   210,   136,   150,    50,   200,   101,
     102,   158,   176,   485,   193,   153,   492,   495,   191,   192,
     154,   507,   508,   503,   507,   503,   156,   507,   145,   156,
     184,   184,   184,   375,   510,   375,    29,   652,   182,   196,
     182,   196,   166,   182,   655,   654,   169,   202,    47,   654,
     152,   118,    45,    47,    79,   106,   168,   653,   221,   222,
     223,   246,   611,   654,   654,   304,   137,   142,   112,   287,
     295,   377,   653,   392,   393,   187,   392,    45,    62,   187,
     560,   561,   412,   187,   194,   654,   426,   427,   654,   284,
     284,   426,   118,   433,   118,   187,   381,   382,   153,   397,
     412,     1,   160,   652,   113,   160,   355,   652,   654,   118,
     142,   107,   412,    29,   187,   653,   654,   654,   450,   451,
     654,   392,   187,   412,   412,   562,   654,   392,   153,   153,
     412,   187,   194,   654,   654,   142,   450,   184,   184,   121,
     107,   184,   156,   156,   156,   654,   153,   185,   186,   187,
      35,   523,   524,   525,   412,     8,   175,    17,   412,   214,
      29,   413,   413,    39,    45,    59,    70,    97,   506,   654,
     187,   413,   413,   413,   642,   413,   506,   413,   231,   230,
     578,   579,   654,   190,   190,   413,   412,   393,   412,   245,
     410,   411,   311,   313,   413,   337,   190,   336,   190,   336,
       3,   343,   359,   389,   343,   359,   389,    33,   360,   389,
     360,   389,   400,   400,   413,   413,   118,   168,   170,   170,
     394,   413,   413,   467,   468,   470,   470,   470,   470,   469,
     470,   470,   470,    70,   471,   475,   475,   474,   476,   476,
     476,   476,   477,   477,   478,   478,   231,    94,    94,    94,
     493,   184,   412,   495,   495,   412,   508,   187,   413,   518,
     149,   187,   518,   107,   187,   187,   107,   107,   380,    29,
     655,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,   362,   363,   364,    94,   137,   142,   368,   369,   370,
     654,   160,   160,   362,   652,   127,   132,    54,    56,   100,
     251,   264,   266,   277,   278,   279,   281,   283,   612,   613,
     614,   615,   616,   617,   624,   630,   631,   246,    94,   299,
     654,   142,   413,   118,   654,   654,   132,   184,   184,   187,
     187,   184,   107,   187,   107,   187,   107,    36,    94,    96,
     147,   428,   429,   545,   654,    55,   217,   254,   418,   419,
     654,    94,   107,   187,   391,   187,   653,    96,    45,   653,
     652,    96,   142,   545,   654,   413,   432,   184,   187,   187,
     187,   187,   107,   188,   147,   545,   184,   187,   187,   153,
     184,   392,   392,   184,   107,   187,   107,   187,   142,   545,
     413,   188,   413,   413,   412,   412,   412,   654,   524,   525,
     130,   197,   184,   184,   131,   190,    94,   218,   219,   233,
      94,   218,   219,   233,   233,   233,    94,    94,   237,   225,
     231,   107,   235,   142,   190,   187,    48,    72,    73,   244,
     414,   424,   184,   504,   584,   411,   233,   359,    33,    33,
     190,   336,   190,   113,   654,   170,   413,   443,   444,   118,
     439,   440,   470,   153,   156,   259,   491,   510,   585,   588,
     589,   590,   591,   592,   596,   598,   600,   601,    47,   152,
     156,   211,   317,   318,   319,   320,   546,   548,   550,   552,
     568,   569,   570,   571,   648,   649,   650,   651,   654,   546,
     482,   551,   654,   482,   184,   185,   107,   187,   187,   510,
     148,   165,   148,   165,   137,   397,   380,   363,   132,   548,
     370,   413,   545,   652,   652,   128,   129,   652,   277,   278,
     279,   283,   654,   263,   274,   263,   274,    29,   286,    96,
     113,   156,   618,   621,   612,    39,    44,    59,    61,    70,
      97,   225,   317,   318,   319,   384,   552,   648,   227,   299,
     308,   413,   654,    94,   299,   652,   153,   562,   563,   654,
     562,   563,   118,   427,   127,   546,   118,   413,   147,   429,
     147,    36,   147,   428,   429,   147,   545,   254,    53,    58,
      77,   118,   428,   434,   435,   436,   419,   545,   546,   382,
      94,   184,   198,   132,   354,   652,   160,   132,    96,   354,
     413,   142,   429,   153,   118,   413,   413,   147,   100,   453,
     454,   455,   457,   458,   100,   461,   462,   463,   464,   392,
     184,   184,   153,   562,   562,   413,   142,   190,   413,   121,
     187,   187,   187,    35,   525,   130,   197,     9,    10,   103,
     123,   125,   153,   195,   520,   522,   533,   534,   537,    29,
     232,   234,   413,   413,   413,   232,   234,   413,   413,   413,
     413,   413,   413,   413,   413,   413,   506,   118,   413,   413,
     394,   156,   156,   156,   153,   186,   245,   581,   582,   210,
     395,   413,   190,   113,   389,   389,   389,   443,    95,   106,
     116,   127,   445,   446,   447,   448,   107,   654,   107,   412,
     585,   592,   153,   285,   472,   637,    96,   169,   252,   253,
     255,   262,   272,   284,   586,   587,   606,   607,   608,   609,
     632,   635,   258,   260,   593,   611,   267,   597,   633,   247,
     248,   270,   602,   603,   156,   156,   548,   156,   156,   156,
     156,   156,   144,   176,   194,   547,   144,   413,   137,   397,
     564,   369,   286,    29,    96,   113,   156,   625,    29,   618,
     547,   547,   493,   287,   306,   545,   384,   227,   190,   391,
     187,   187,   144,   187,   187,   427,   147,   428,   654,   413,
     147,   413,   127,   413,   147,   429,   147,   413,   147,   118,
     118,   413,   654,   436,    77,   546,   394,   413,   652,   107,
     354,   413,   142,   391,   451,   413,   413,   113,   454,   455,
     100,   186,   113,   455,   458,   118,   546,   100,   113,   462,
     100,   113,   464,   184,   391,   187,   187,   413,   413,   198,
     461,   132,   195,   522,     7,   392,   654,   195,   533,   190,
     233,   233,   233,   233,    96,   237,   237,   579,   186,   412,
     412,   412,   584,   582,   504,   652,   128,   129,   447,   448,
     448,   444,   106,   142,   441,   545,   440,   184,   187,   585,
     599,   250,   217,   254,   268,   275,   636,    96,   256,   257,
     634,   250,   589,   636,   474,   606,   590,   147,   282,   594,
     595,   634,   286,   605,    78,   604,   187,   194,   546,   549,
     187,   187,   187,   187,   187,   187,   187,    29,   136,   201,
     627,   628,   629,    29,   626,   627,   271,   622,   107,   619,
     170,   654,   257,   493,   184,   413,   147,   413,   147,   428,
     413,   147,   413,   413,   654,   654,   435,   413,   126,   126,
      96,   652,   413,   184,   186,   186,   413,   394,   413,   186,
     186,   654,   186,   118,   546,   118,   186,   118,   546,   186,
     184,   113,   525,   654,   195,   184,   525,   654,   413,   413,
     413,   413,   316,   413,   413,   413,   187,   187,   187,   153,
     583,   448,   652,   413,   142,   184,   476,    52,   129,   474,
     474,   269,   276,   286,   610,   610,   591,   153,   280,    94,
     187,   107,   187,   625,   625,   629,   107,   187,    29,   623,
     634,   620,   621,   187,   386,   387,   493,   118,   225,   307,
     287,   170,   413,   413,   147,   413,    53,   394,   413,   354,
     413,   394,    94,   394,   413,   654,   186,   654,   413,   654,
     186,   394,   118,    93,   183,   526,   525,   654,   197,   525,
     413,   198,   461,   412,   441,   413,   474,   474,   199,   412,
     546,   546,    94,    29,   265,   107,   107,   448,   545,   654,
     118,   225,   654,   386,   413,   118,   546,    94,   186,    94,
     654,     5,   133,   529,   530,   532,   534,    28,   134,   527,
     528,   531,   534,   197,   525,   197,   113,   184,   441,   474,
     184,   546,   621,   387,   448,   305,   654,   118,   225,   654,
     186,   546,   394,   413,   546,   186,    93,   133,   532,   183,
     134,   531,   197,   118,   413,   305,   654,   118,   394,   413,
     186,   186,   654,   293,   305,   654,   186,   306,   413,   306,
     493,   493,   199,   287,   654,   225,   118,   654,   306,   493
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
         0,   334,   335,   335,   335,   335,   336,   336,   337,   337,
     337,   337,   338,   338,   339,   339,   339,   339,   339,   339,
     339,   339,   340,   340,   340,   340,   341,   342,   342,   342,
     343,   343,   343,   343,   343,   344,   344,   344,   344,   344,
     344,   344,   344,   345,   345,   346,   347,   348,   348,   349,
     349,   350,   350,   351,   351,   351,   351,   352,   352,   352,
     353,   353,   353,   353,   354,   354,   355,   355,   356,   356,
     356,   356,   357,   358,   358,   359,   359,   359,   360,   360,
     360,   360,   360,   360,   360,   360,   361,   361,   362,   362,
     363,   364,   364,   364,   364,   364,   364,   364,   364,   364,
     364,   365,   366,   367,   368,   368,   369,   369,   369,   370,
     371,   371,   371,   372,   372,   372,   372,   373,   373,   374,
     374,   374,   374,   375,   375,   376,   376,   377,   377,   378,
     378,   379,   379,   380,   380,   380,   380,   381,   381,   382,
     382,   383,   383,   383,   383,   384,   384,   384,   384,   385,
     385,   386,   386,   387,   387,   387,   387,   388,   388,   388,
     388,   389,   390,   390,   390,   391,   391,   391,   392,   392,
     393,   393,   394,   394,   394,   394,   394,   394,   394,   394,
     394,   394,   394,   394,   395,   395,   396,   397,   398,   399,
     399,   399,   400,   400,   400,   400,   401,   402,   403,   404,
     405,   405,   406,   407,   408,   409,   410,   410,   411,   412,
     412,   412,   413,   413,   413,   413,   413,   413,   414,   414,
     414,   414,   414,   414,   414,   414,   414,   414,   414,   414,
     415,   416,   417,   417,   418,   418,   418,   419,   419,   420,
     420,   421,   422,   422,   422,   423,   423,   423,   423,   423,
     424,   424,   425,   425,   425,   426,   426,   426,   427,   427,
     427,   427,   427,   427,   427,   427,   427,   427,   427,   427,
     428,   429,   430,   431,   431,   432,   432,   432,   432,   433,
     433,   434,   434,   434,   435,   435,   435,   436,   436,   436,
     437,   438,   439,   439,   440,   440,   440,   440,   440,   440,
     441,   442,   442,   443,   443,   444,   444,   445,   445,   445,
     445,   445,   445,   445,   446,   446,   447,   447,   448,   449,
     449,   450,   450,   451,   451,   452,   453,   453,   454,   455,
     455,   456,   457,   457,   458,   459,   459,   460,   460,   461,
     461,   462,   462,   463,   463,   464,   464,   465,   466,   466,
     467,   467,   468,   468,   468,   468,   468,   469,   468,   468,
     468,   468,   470,   470,   471,   471,   472,   472,   473,   473,
     474,   474,   474,   475,   475,   475,   475,   475,   476,   476,
     476,   477,   477,   477,   478,   478,   479,   479,   480,   480,
     481,   481,   482,   482,   483,   483,   484,   484,   484,   484,
     485,   485,   485,   486,   486,   487,   487,   487,   487,   487,
     487,   488,   488,   488,   489,   489,   489,   489,   490,   490,
     491,   491,   492,   492,   492,   493,   493,   493,   493,   494,
     495,   495,   495,   496,   496,   497,   497,   497,   497,   498,
     498,   499,   499,   499,   499,   499,   499,   499,   500,   500,
     501,   501,   502,   502,   502,   502,   502,   503,   503,   504,
     504,   505,   505,   505,   505,   506,   506,   506,   506,   507,
     507,   508,   509,   509,   509,   509,   509,   509,   509,   509,
     509,   509,   509,   509,   509,   509,   510,   510,   511,   511,
     511,   512,   513,   513,   514,   515,   516,   517,   517,   518,
     518,   519,   519,   520,   520,   520,   521,   521,   521,   521,
     521,   521,   522,   522,   523,   523,   524,   525,   525,   526,
     526,   527,   527,   528,   528,   528,   528,   529,   529,   530,
     530,   530,   530,   531,   531,   532,   532,   533,   533,   533,
     533,   534,   534,   534,   534,   535,   535,   536,   536,   537,
     538,   538,   538,   538,   538,   538,   539,   540,   540,   541,
     541,   542,   543,   544,   544,   545,   546,   546,   546,   547,
     547,   547,   548,   548,   548,   548,   548,   548,   548,   549,
     549,   550,   551,   552,   552,   552,   552,   552,   552,   552,
     552,   552,   553,   554,   554,   554,   555,   556,   557,   557,
     557,   558,   558,   558,   558,   558,   559,   560,   560,   560,
     560,   560,   560,   560,   561,   562,   563,   564,   565,   565,
     566,   567,   568,   568,   569,   570,   570,   571,   572,   572,
     572,   573,   573,   573,   573,   573,   573,   573,   573,   573,
     573,   574,   574,   575,   575,   576,   577,   578,   578,   579,
     580,   581,   581,   582,   583,   584,   584,   585,   586,   586,
     587,   587,   588,   588,   589,   589,   590,   590,   591,   591,
     592,   593,   593,   594,   594,   595,   596,   596,   596,   597,
     597,   598,   599,   599,   600,   601,   601,   602,   602,   603,
     603,   603,   604,   604,   605,   605,   606,   606,   606,   606,
     606,   607,   608,   609,   610,   610,   610,   611,   611,   612,
     612,   612,   612,   612,   612,   612,   612,   613,   613,   613,
     613,   614,   614,   615,   616,   616,   617,   617,   617,   618,
     618,   619,   619,   620,   620,   621,   622,   622,   623,   623,
     624,   624,   624,   625,   625,   626,   626,   627,   627,   628,
     628,   629,   629,   630,   631,   631,   632,   632,   632,   633,
     634,   634,   634,   634,   635,   635,   636,   636,   637,   638,
     638,   639,   639,   640,   640,   641,   642,   642,   643,   643,
     643,   644,   645,   646,   647,   648,   648,   648,   649,   650,
     651,   652,   653,   653,   654,   654,   654,   654,   654,   654,
     654,   654,   654,   654,   654,   654,   654,   654,   654,   654,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   656
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
  {
         0,     2,     1,     2,     2,     3,     1,     2,     1,     2,
       1,     2,     4,     6,     3,     3,     5,     1,     3,     3,
       5,     5,     1,     3,     3,     5,     6,     1,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     4,     3,     3,     3,     3,
       3,     5,     5,     5,     5,     5,     5,     1,     1,     3,
       3,     4,     5,     6,     1,     3,     3,     3,     3,     6,
       5,     8,     5,     5,     5,     1,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     3,     4,     3,     1,     1,     1,     2,     2,
       4,     3,     5,     3,     4,     4,     5,     1,     2,     1,
       4,     1,     4,     1,     3,     2,     3,     1,     1,     4,
       4,     5,     5,     2,     3,     4,     5,     1,     3,     2,
       3,     3,     5,     4,     6,     1,     2,     1,     2,     8,
       9,     1,     3,     1,     2,     2,     3,    11,    14,    13,
      22,     1,     1,     1,     0,     1,     1,     0,     1,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     3,     3,     2,     3,
       2,     3,     2,     3,     4,     5,     5,     2,     4,     5,
       3,     3,     2,     2,     8,     3,     1,     2,     3,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     1,     1,     2,     4,     3,     5,
       4,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     3,     2,     1,     4,     3,     3,     5,
       4,     6,     4,     6,     5,     7,     4,     5,     5,     6,
       3,     3,     2,     1,     3,     4,     5,     3,     6,     4,
       5,     1,     2,     3,     1,     2,     1,     6,     3,     3,
       2,     3,     1,     3,     2,     4,     5,     6,     5,     3,
       2,     3,     4,     1,     3,     1,     2,     1,     1,     1,
       2,     2,     2,     3,     1,     1,     2,     2,     2,     5,
       5,     1,     4,     3,     4,     8,     1,     2,     3,     2,
       3,     8,     1,     2,     3,     8,    10,     8,    10,     1,
       2,     4,     7,     1,     2,     4,     7,     8,     1,     3,
       1,     3,     1,     3,     3,     3,     3,     0,     4,     3,
       3,     3,     1,     5,     1,     3,     0,     1,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     4,     1,     4,     1,     4,
       1,     4,     1,     2,     1,     2,     1,     1,     2,     2,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     5,     5,     6,     3,     4,
       1,     2,     3,     2,     2,     1,     2,     2,     1,     1,
       1,     3,     3,     1,     1,     1,     2,     1,     2,     2,
       1,     2,     2,     2,     2,     2,     2,     2,     1,     2,
       2,     1,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     4,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     1,     4,     4,     3,     4,     1,
       3,     1,     1,     1,     1,     1,     4,     5,     8,     9,
       9,    10,     1,     2,     1,     2,     6,     0,     1,     3,
       3,     0,     1,     1,     1,     2,     2,     0,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     2,     3,     3,     2,
       1,     1,     1,     1,     1,     1,     4,     3,     7,     3,
       7,     4,     4,     3,     7,     2,     1,     2,     3,     1,
       1,     1,     1,     1,     3,     3,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     4,     4,     3,     3,     3,     4,
       4,     3,     4,     6,     4,     6,     4,     3,     4,     6,
       6,     4,     6,     6,     4,     1,     2,     1,     1,     1,
       3,     3,     1,     1,     4,     5,     6,     3,     3,     3,
       3,     5,     7,     7,     5,     5,     5,     7,     7,     5,
       5,     3,     3,     5,     7,     5,     7,     1,     4,     3,
       5,     1,     2,     3,     3,     1,     3,     2,     0,     1,
       1,     2,     1,     3,     1,     3,     1,     4,     1,     2,
       3,     0,     1,     0,     1,     4,     2,     3,     1,     0,
       1,     4,     0,     1,     2,     1,     3,     0,     1,     2,
       2,     1,     0,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     1,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     2,     2,     3,     1,     2,     2,     5,     2,     1,
       1,     0,     2,     1,     3,     4,     0,     2,     0,     2,
       4,     4,     3,     2,     3,     1,     3,     0,     1,     1,
       2,     2,     2,     2,     1,     2,     2,     2,     2,     3,
       2,     3,     3,     4,     2,     2,     1,     1,     3,     2,
       3,     2,     3,     2,     3,     3,     3,     5,     5,     5,
       8,     5,     3,     5,     7,     1,     1,     1,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1
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
  "IfExpr", "OrExpr", "AndExpr", "ComparisonExpr", "$@1", "FTContainsExpr",
  "StringConcatExpr", "opt_FTIgnoreOption", "RangeExpr", "AdditiveExpr",
  "MultiplicativeExpr", "UnionExpr", "IntersectExceptExpr",
  "InstanceofExpr", "TreatExpr", "CastableExpr", "CastExpr", "SingleType",
  "UnaryExpr", "SignList", "ValueExpr", "SimpleMapExpr", "ValueComp",
  "NodeComp", "ValidateExpr", "ExtensionExpr", "Pragma_list", "Pragma",
  "PathExpr", "LeadingSlash", "RelativePathExpr", "StepExpr", "AxisStep",
  "ForwardStep", "ForwardAxis", "AbbrevForwardStep", "ReverseStep",
  "ReverseAxis", "NodeTest", "NameTest", "Wildcard", "FilterExpr",
  "PredicateList", "Predicate", "PrimaryExpr", "Literal", "NumericLiteral",
  "VarRef", "ParenthesizedExpr", "ContextItemExpr", "OrderedExpr",
  "UnorderedExpr", "FunctionCall", "ArgList", "Constructor",
  "DirectConstructor", "DirElemConstructor", "DirElemContentList",
  "DirAttributeList", "DirAttr", "OptionalBlank", "DirAttributeValue",
  "opt_QuoteAttrContentList", "QuoteAttrContentList",
  "opt_AposAttrContentList", "AposAttrContentList",
  "QuoteAttrValueContent", "AposAttrValueContent", "DirElemContent",
  "CommonContent", "DirCommentConstructor", "DirPIConstructor",
  "CDataSection", "ComputedConstructor", "CompDocConstructor",
  "CompElemConstructor", "CompAttrConstructor", "CompTextConstructor",
  "CompCommentConstructor", "CompPIConstructor", "TypeDeclaration",
  "SequenceType", "OccurrenceIndicator", "ItemType", "TypeList",
  "AtomicType", "SimpleType", "KindTest", "AnyKindTest", "DocumentTest",
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
     339,    -1,   338,   339,    -1,   340,    -1,   338,   340,    -1,
     215,   216,    29,   190,    -1,   215,   216,    29,   131,    29,
     190,    -1,   342,   190,   389,    -1,   359,   190,   389,    -1,
     342,   190,   359,   190,   389,    -1,   389,    -1,   342,   336,
     389,    -1,   359,   336,   389,    -1,   342,   190,   359,   336,
     389,    -1,   342,   336,   359,   190,   389,    -1,   341,    -1,
     341,   342,   190,    -1,   341,   359,   190,    -1,   341,   342,
     190,   359,   190,    -1,    34,   160,   653,   132,   652,   190,
      -1,   343,    -1,   342,   190,   343,    -1,   342,   336,   343,
      -1,   344,    -1,   352,    -1,   357,    -1,   358,    -1,   366,
      -1,   345,    -1,   346,    -1,   347,    -1,   348,    -1,   349,
      -1,   350,    -1,   351,    -1,   572,    -1,    33,    38,   182,
      -1,    33,    38,   196,    -1,    33,   113,   106,   652,    -1,
      33,    37,   652,    -1,    33,    40,   182,    -1,    33,    40,
     196,    -1,    33,    57,   169,    -1,    33,    57,   202,    -1,
      33,   113,   168,   127,   128,    -1,    33,   113,   168,   127,
     129,    -1,    33,    41,   182,   107,   148,    -1,    33,    41,
     182,   107,   165,    -1,    33,    41,   166,   107,   148,    -1,
      33,    41,   166,   107,   165,    -1,   353,    -1,   356,    -1,
      49,    24,     1,    -1,    49,    60,   652,    -1,    49,    60,
     355,   652,    -1,    49,    60,   652,    96,   354,    -1,    49,
      60,   355,   652,    96,   354,    -1,   652,    -1,   354,   107,
     652,    -1,   160,   653,   132,    -1,   113,    45,   160,    -1,
      49,    34,   652,    -1,    49,    34,   160,   653,   132,   652,
      -1,    49,    34,   652,    96,   354,    -1,    49,    34,   160,
     653,   132,   652,    96,   354,    -1,    33,   160,   653,   132,
     652,    -1,    33,   113,    45,   160,   652,    -1,    33,   113,
      47,   160,   652,    -1,   360,    -1,   359,   190,   360,    -1,
     359,   336,   360,    -1,   361,    -1,   365,    -1,   367,    -1,
     371,    -1,   376,    -1,   383,    -1,   385,    -1,   388,    -1,
      33,   113,    79,   362,    -1,    33,    79,   654,   362,    -1,
     363,    -1,   362,   363,    -1,   364,   132,   564,    -1,    80,
      -1,    88,    -1,    81,    -1,    82,    -1,    83,    -1,    84,
      -1,    89,    -1,    85,    -1,    86,    -1,    87,    -1,    33,
      56,   654,    29,    -1,    33,   261,   611,    -1,    33,   111,
     152,   368,    -1,    94,   548,   369,    -1,   369,    -1,   370,
      -1,   137,    -1,   137,   370,    -1,   142,   413,    -1,    33,
     372,   142,   413,    -1,    33,   372,   137,    -1,    33,   372,
     137,   142,   413,    -1,   112,   118,   654,    -1,   112,   118,
     654,   545,    -1,   373,   112,   118,   654,    -1,   373,   112,
     118,   654,   545,    -1,   374,    -1,   373,   374,    -1,    26,
      -1,    26,   156,   375,   187,    -1,    27,    -1,    27,   156,
     375,   187,    -1,   510,    -1,   375,   107,   510,    -1,    33,
     377,    -1,    33,   373,   377,    -1,   378,    -1,   379,    -1,
      47,   655,   380,   397,    -1,    47,   655,   380,   137,    -1,
      74,    47,   655,   380,   397,    -1,    74,    47,   655,   380,
     137,    -1,   156,   187,    -1,   156,   381,   187,    -1,   156,
     187,    94,   546,    -1,   156,   381,   187,    94,   546,    -1,
     382,    -1,   381,   107,   382,    -1,   118,   654,    -1,   118,
     654,   545,    -1,    33,   287,   654,    -1,    33,   287,   654,
      94,   384,    -1,    33,   373,   287,   654,    -1,    33,   373,
     287,   654,    94,   384,    -1,   552,    -1,   552,   547,    -1,
     648,    -1,   648,   547,    -1,    33,   295,   654,   299,   227,
     493,   170,   386,    -1,    33,   373,   295,   654,   299,   227,
     493,   170,   386,    -1,   387,    -1,   386,   107,   387,    -1,
     493,    -1,   493,   545,    -1,   493,   448,    -1,   493,   545,
     448,    -1,    33,   303,   304,   654,   299,   287,   654,   118,
     654,   305,   413,    -1,    33,   303,   304,   654,   299,   287,
     654,   225,   118,   654,   305,   293,   306,   493,    -1,    33,
     303,   304,   654,   299,   287,   654,   307,   225,   118,   654,
     305,   413,    -1,    33,   303,   304,   654,   308,   306,   257,
     287,   654,   225,   118,   654,   306,   493,   199,   287,   654,
     225,   118,   654,   306,   493,    -1,   390,    -1,   392,    -1,
     393,    -1,    -1,   392,    -1,   393,    -1,    -1,   412,    -1,
     393,   412,    -1,   394,    -1,   393,   394,    -1,   395,    -1,
     398,    -1,   401,    -1,   402,    -1,   403,    -1,   404,    -1,
     405,    -1,   406,    -1,   408,    -1,   460,    -1,   456,    -1,
     409,    -1,   153,   393,   184,    -1,   153,   184,    -1,   153,
     391,   184,    -1,   153,   391,   184,    -1,   399,   190,    -1,
     399,   107,   400,    -1,   112,   400,    -1,   373,   112,   400,
      -1,   118,   654,    -1,   118,   654,   545,    -1,   118,   654,
     142,   413,    -1,   118,   654,   545,   142,   413,    -1,   118,
     654,   142,   413,   190,    -1,   414,   190,    -1,   240,   242,
     413,   190,    -1,   243,   156,   412,   187,   394,    -1,   238,
     241,   190,    -1,   239,   241,   190,    -1,   424,   407,    -1,
     186,   394,    -1,    48,   156,   412,   187,   198,   394,   126,
     394,    -1,   244,   395,   410,    -1,   411,    -1,   410,   411,
      -1,   245,   584,   395,    -1,   413,    -1,   412,   107,   413,
      -1,   412,   336,   413,    -1,   415,    -1,   452,    -1,   459,
      -1,   465,    -1,   580,    -1,   414,    -1,   466,    -1,   449,
      -1,   573,    -1,   574,    -1,   576,    -1,   575,    -1,   577,
      -1,   645,    -1,   643,    -1,   646,    -1,   647,    -1,   644,
      -1,   424,   416,    -1,   186,   413,    -1,    66,   284,    -1,
      71,   284,    -1,   217,    -1,   254,    -1,    55,   254,    -1,
     418,   434,    77,   413,    -1,   418,    77,   413,    -1,    46,
     417,   433,   419,   419,    -1,    46,   417,   433,   419,    -1,
      42,   118,   654,    -1,   425,    -1,   430,    -1,   420,    -1,
     422,    -1,   437,    -1,   442,    -1,   438,    -1,   421,    -1,
     422,    -1,   424,   423,    -1,    46,   118,   426,    -1,    46,
       1,   426,    -1,    46,     3,    -1,   427,    -1,   426,   107,
     118,   427,    -1,   426,   107,   427,    -1,   654,   147,   413,
      -1,   654,    36,   127,   147,   413,    -1,   654,   545,   147,
     413,    -1,   654,   545,    36,   127,   147,   413,    -1,   654,
     428,   147,   413,    -1,   654,    36,   127,   428,   147,   413,
      -1,   654,   545,   428,   147,   413,    -1,   654,   545,    36,
     127,   428,   147,   413,    -1,   654,   429,   147,   413,    -1,
     654,   545,   429,   147,   413,    -1,   654,   428,   429,   147,
     413,    -1,   654,   545,   428,   429,   147,   413,    -1,    96,
     118,   654,    -1,   273,   118,   654,    -1,    51,   431,    -1,
     432,    -1,   431,   107,   432,    -1,   118,   654,   142,   413,
      -1,   118,   654,   545,   142,   413,    -1,   429,   142,   413,
      -1,   118,   654,   545,   429,   142,   413,    -1,   118,   654,
     147,   413,    -1,   118,   654,   545,   147,   413,    -1,   435,
      -1,   118,   654,    -1,   118,   654,   435,    -1,   428,    -1,
     428,   436,    -1,   436,    -1,    58,   118,   654,    53,   118,
     654,    -1,    53,   118,   654,    -1,    58,   118,   654,    -1,
     212,   413,    -1,   171,   170,   439,    -1,   440,    -1,   439,
     107,   440,    -1,   118,   654,    -1,   118,   654,   142,   413,
      -1,   118,   654,   545,   142,   413,    -1,   118,   654,   545,
     142,   413,   441,    -1,   118,   654,   142,   413,   441,    -1,
     118,   654,   441,    -1,   106,   652,    -1,   168,   170,   443,
      -1,    69,   168,   170,   443,    -1,   444,    -1,   443,   107,
     444,    -1,   413,    -1,   413,   445,    -1,   446,    -1,   447,
      -1,   448,    -1,   446,   447,    -1,   446,   448,    -1,   447,
     448,    -1,   446,   447,   448,    -1,    95,    -1,   116,    -1,
     127,   128,    -1,   127,   129,    -1,   106,   652,    -1,    67,
     118,   450,   188,   413,    -1,   135,   118,   450,   188,   413,
      -1,   451,    -1,   450,   107,   118,   451,    -1,   654,   147,
     413,    -1,   654,   545,   147,   413,    -1,    72,   156,   412,
     187,   453,   113,   186,   413,    -1,   454,    -1,   453,   454,
      -1,   455,   186,   413,    -1,   100,   413,    -1,   455,   100,
     413,    -1,    72,   156,   412,   187,   457,   113,   186,   394,
      -1,   458,    -1,   457,   458,    -1,   455,   186,   394,    -1,
      73,   156,   412,   187,   461,   113,   186,   413,    -1,    73,
     156,   412,   187,   461,   113,   118,   654,   186,   413,    -1,
      73,   156,   412,   187,   463,   113,   186,   394,    -1,    73,
     156,   412,   187,   461,   113,   118,   654,   186,   394,    -1,
     462,    -1,   461,   462,    -1,   100,   546,   186,   413,    -1,
     100,   118,   654,    94,   546,   186,   413,    -1,   464,    -1,
     463,   464,    -1,   100,   546,   186,   394,    -1,   100,   118,
     654,    94,   546,   186,   394,    -1,    48,   156,   412,   187,
     198,   413,   126,   413,    -1,   467,    -1,   466,   167,   467,
      -1,   468,    -1,   467,    92,   468,    -1,   470,    -1,   470,
     487,   470,    -1,   470,   488,   470,    -1,   470,   132,   470,
      -1,   470,   162,   470,    -1,    -1,   470,   157,   469,   470,
      -1,   470,   155,   470,    -1,   470,   143,   470,    -1,   470,
     141,   470,    -1,   471,    -1,   471,   249,    70,   585,   472,
      -1,   473,    -1,   473,    99,   471,    -1,    -1,   637,    -1,
     474,    -1,   474,   199,   474,    -1,   475,    -1,   474,   176,
     475,    -1,   474,   158,   475,    -1,   476,    -1,   475,   194,
     476,    -1,   475,   117,   476,    -1,   475,   146,   476,    -1,
     475,   159,   476,    -1,   477,    -1,   476,   201,   477,    -1,
     476,   210,   477,    -1,   478,    -1,   477,   150,   478,    -1,
     477,   136,   478,    -1,   479,    -1,   479,    50,   231,   546,
      -1,   480,    -1,   480,   200,    94,   546,    -1,   481,    -1,
     481,   101,    94,   482,    -1,   483,    -1,   483,   102,    94,
     482,    -1,   551,    -1,   551,   144,    -1,   485,    -1,   484,
     485,    -1,   176,    -1,   158,    -1,   484,   176,    -1,   484,
     158,    -1,   489,    -1,   486,    -1,   490,    -1,   493,    -1,
     486,   193,   493,    -1,   203,    -1,   208,    -1,   207,    -1,
     206,    -1,   205,    -1,   204,    -1,   151,    -1,   179,    -1,
     140,    -1,    75,   153,   392,   184,    -1,    75,   222,   153,
     392,   184,    -1,    75,   221,   153,   392,   184,    -1,    75,
      76,   562,   153,   392,   184,    -1,   491,   153,   184,    -1,
     491,   153,   412,   184,    -1,   492,    -1,   491,   492,    -1,
     177,   654,    17,    -1,   177,    18,    -1,   177,    19,    -1,
     494,    -1,   494,   495,    -1,   192,   495,    -1,   495,    -1,
     191,    -1,   496,    -1,   496,   191,   495,    -1,   496,   192,
     495,    -1,   497,    -1,   506,    -1,   498,    -1,   498,   507,
      -1,   501,    -1,   501,   507,    -1,   499,   503,    -1,   500,
      -1,   105,   122,    -1,   114,   122,    -1,    97,   122,    -1,
     189,   122,    -1,   115,   122,    -1,   139,   122,    -1,   138,
     122,    -1,   503,    -1,    98,   503,    -1,   502,   503,    -1,
     120,    -1,   172,   122,    -1,    90,   122,    -1,   181,   122,
      -1,   180,   122,    -1,    91,   122,    -1,   552,    -1,   504,
      -1,   654,    -1,   505,    -1,   194,    -1,    11,    -1,    12,
      -1,    20,    -1,   509,    -1,   506,   507,    -1,   506,   156,
     187,    -1,   506,   156,   518,   187,    -1,   508,    -1,   507,
     508,    -1,   154,   412,   185,    -1,   510,    -1,   512,    -1,
     513,    -1,   514,    -1,   517,    -1,   519,    -1,   515,    -1,
     516,    -1,   565,    -1,   396,    -1,   641,    -1,   638,    -1,
     639,    -1,   640,    -1,   511,    -1,   564,    -1,   110,    -1,
     149,    -1,   124,    -1,   118,   654,    -1,   156,   187,    -1,
     156,   412,   187,    -1,   119,    -1,   169,   153,   412,   184,
      -1,   202,   153,   412,   184,    -1,   655,   156,   187,    -1,
     655,   156,   518,   187,    -1,   413,    -1,   518,   107,   413,
      -1,   520,    -1,   538,    -1,   521,    -1,   535,    -1,   536,
      -1,   157,   654,   525,   130,    -1,   157,   654,   523,   525,
     130,    -1,   157,   654,   525,   197,   195,   654,   525,   197,
      -1,   157,   654,   525,   197,   522,   195,   654,   525,   197,
      -1,   157,   654,   523,   525,   197,   195,   654,   525,   197,
      -1,   157,   654,   523,   525,   197,   522,   195,   654,   525,
     197,    -1,   533,    -1,   522,   533,    -1,   524,    -1,   523,
     524,    -1,    35,   654,   525,   132,   525,   526,    -1,    -1,
      35,    -1,   183,   527,   183,    -1,    93,   529,    93,    -1,
      -1,   528,    -1,   134,    -1,   531,    -1,   528,   134,    -1,
     528,   531,    -1,    -1,   530,    -1,   133,    -1,   532,    -1,
     530,   133,    -1,   530,   532,    -1,    28,    -1,   534,    -1,
       5,    -1,   534,    -1,   520,    -1,    10,    -1,   537,    -1,
     534,    -1,     9,    -1,   123,    -1,   125,    -1,   153,   392,
     184,    -1,   213,    30,   214,    -1,   213,   214,    -1,   174,
     653,   175,    -1,   174,   653,     8,    -1,   103,     7,    -1,
     539,    -1,   540,    -1,   541,    -1,   542,    -1,   543,    -1,
     544,    -1,    43,   153,   392,   184,    -1,    21,   391,   184,
      -1,    45,   153,   412,   184,   153,   391,   184,    -1,    22,
     391,   184,    -1,    97,   153,   412,   184,   153,   391,   184,
      -1,    70,   153,   392,   184,    -1,    39,   153,   392,   184,
      -1,    23,   391,   184,    -1,    59,   153,   412,   184,   153,
     391,   184,    -1,    94,   546,    -1,   548,    -1,   548,   547,
      -1,   211,   156,   187,    -1,   144,    -1,   194,    -1,   176,
      -1,   550,    -1,   552,    -1,   152,   156,   187,    -1,   320,
     156,   187,    -1,   568,    -1,   571,    -1,   648,    -1,   546,
      -1,   549,   107,   546,    -1,   654,    -1,   654,    -1,   554,
      -1,   560,    -1,   558,    -1,   561,    -1,   559,    -1,   557,
      -1,   556,    -1,   555,    -1,   553,    -1,   225,   156,   187,
      -1,    44,   156,   187,    -1,    44,   156,   560,   187,    -1,
      44,   156,   561,   187,    -1,    70,   156,   187,    -1,    39,
     156,   187,    -1,    59,   156,   187,    -1,    59,   156,   653,
     187,    -1,    59,   156,    29,   187,    -1,    97,   156,   187,
      -1,    97,   156,   654,   187,    -1,    97,   156,   654,   107,
     562,   187,    -1,    97,   156,   194,   187,    -1,    97,   156,
     194,   107,   562,   187,    -1,    61,   156,   654,   187,    -1,
      45,   156,   187,    -1,    45,   156,   654,   187,    -1,    45,
     156,   654,   107,   562,   187,    -1,    45,   156,   654,   107,
     563,   187,    -1,    45,   156,   194,   187,    -1,    45,   156,
     194,   107,   562,   187,    -1,    45,   156,   194,   107,   563,
     187,    -1,    62,   156,   654,   187,    -1,   654,    -1,   654,
     144,    -1,    29,    -1,   566,    -1,   567,    -1,   654,   145,
     149,    -1,    47,   380,   397,    -1,   569,    -1,   570,    -1,
      47,   156,   194,   187,    -1,    47,   156,   187,    94,   546,
      -1,    47,   156,   549,   187,    94,   546,    -1,   156,   548,
     187,    -1,    33,   220,   221,    -1,    33,   220,   222,    -1,
      33,   220,   223,    -1,   226,   225,   413,   233,   413,    -1,
     226,   225,   413,    94,   232,   233,   413,    -1,   226,   225,
     413,    94,   234,   233,   413,    -1,   226,   225,   413,   218,
     413,    -1,   226,   225,   413,   219,   413,    -1,   226,   227,
     413,   233,   413,    -1,   226,   227,   413,    94,   232,   233,
     413,    -1,   226,   227,   413,    94,   234,   233,   413,    -1,
     226,   227,   413,   218,   413,    -1,   226,   227,   413,   219,
     413,    -1,   224,   225,   413,    -1,   224,   227,   413,    -1,
     229,   225,   413,   237,   413,    -1,   229,   230,   231,   225,
     413,   237,   413,    -1,   228,   225,   413,    94,   413,    -1,
     236,   118,   578,   235,   413,   186,   413,    -1,   579,    -1,
     578,   107,   118,   579,    -1,   654,   142,   413,    -1,   244,
     153,   412,   184,   581,    -1,   582,    -1,   581,   582,    -1,
     245,   584,   583,    -1,   153,   412,   184,    -1,   504,    -1,
     584,   210,   504,    -1,   588,   586,    -1,    -1,   587,    -1,
     606,    -1,   587,   606,    -1,   589,    -1,   588,   262,   589,
      -1,   590,    -1,   589,   258,   590,    -1,   591,    -1,   590,
     260,   147,   591,    -1,   592,    -1,   259,   592,    -1,   596,
     593,   594,    -1,    -1,   611,    -1,    -1,   595,    -1,   282,
     153,   412,   184,    -1,   600,   597,    -1,   156,   585,   187,
      -1,   598,    -1,    -1,   633,    -1,   491,   153,   599,   184,
      -1,    -1,   585,    -1,   601,   602,    -1,   510,    -1,   153,
     412,   184,    -1,    -1,   603,    -1,   248,   604,    -1,   247,
     605,    -1,   270,    -1,    -1,    78,    -1,    -1,   286,    -1,
     607,    -1,   608,    -1,   609,    -1,   635,    -1,   632,    -1,
     169,    -1,   284,   474,   610,    -1,   253,   634,   610,    -1,
     286,    -1,   276,    -1,   269,    -1,   246,   612,    -1,   611,
     246,   612,    -1,   613,    -1,   614,    -1,   615,    -1,   630,
      -1,   616,    -1,   624,    -1,   617,    -1,   631,    -1,   100,
     274,    -1,   100,   263,    -1,   266,    -1,   281,    -1,   251,
     274,    -1,   251,   263,    -1,    56,   654,    29,    -1,   277,
      -1,    54,   277,    -1,   279,   618,    -1,   279,   156,   618,
     619,   187,    -1,    54,   279,    -1,   621,    -1,   113,    -1,
      -1,   107,   620,    -1,   621,    -1,   620,   107,   621,    -1,
      96,    29,   622,   623,    -1,    -1,   271,    29,    -1,    -1,
     634,   265,    -1,   278,   286,   625,   627,    -1,   278,   286,
     113,   627,    -1,    54,   278,   286,    -1,    96,    29,    -1,
     156,   626,   187,    -1,    29,    -1,   626,   107,    29,    -1,
      -1,   628,    -1,   629,    -1,   628,   629,    -1,   201,   625,
      -1,   136,   625,    -1,   264,    29,    -1,   283,    -1,    54,
     283,    -1,    96,   217,    -1,    96,   254,    -1,   255,   250,
      -1,   267,   634,   280,    -1,   256,   474,    -1,    96,   129,
     474,    -1,    96,    52,   474,    -1,   257,   474,   199,   474,
      -1,   272,   636,    -1,   252,   636,    -1,   275,    -1,   268,
      -1,   285,   250,   476,    -1,   154,   185,    -1,   154,   412,
     185,    -1,   310,   311,    -1,   310,   412,   311,    -1,   312,
     313,    -1,   312,   412,   313,    -1,   153,   642,   184,    -1,
     413,   121,   413,    -1,   642,   107,   413,   121,   413,    -1,
     226,   314,   413,   233,   413,    -1,   226,   314,   642,   233,
     413,    -1,   226,   314,   413,   233,   413,    96,   316,   413,
      -1,   315,   314,   413,   233,   413,    -1,   224,   314,   506,
      -1,   228,   314,   506,    94,   413,    -1,   229,   314,   230,
     231,   506,   237,   413,    -1,   649,    -1,   650,    -1,   651,
      -1,   319,   156,   187,    -1,   317,   156,   187,    -1,   318,
     156,   187,    -1,    29,    -1,    16,    -1,   654,    -1,   655,
      -1,    97,    -1,    39,    -1,    44,    -1,    45,    -1,   152,
      -1,    48,    -1,   225,    -1,    59,    -1,    61,    -1,    62,
      -1,    70,    -1,    73,    -1,    72,    -1,   211,    -1,   243,
      -1,   656,    -1,    24,    -1,   215,    -1,   127,    -1,    38,
      -1,   261,    -1,    37,    -1,   222,    -1,   221,    -1,   146,
      -1,    43,    -1,   259,    -1,   260,    -1,   274,    -1,   263,
      -1,   251,    -1,   285,    -1,   277,    -1,   279,    -1,   278,
      -1,   283,    -1,   255,    -1,   250,    -1,    78,    -1,   217,
      -1,   254,    -1,    52,    -1,   223,    -1,   236,    -1,   302,
      -1,   230,    -1,   203,    -1,   208,    -1,   207,    -1,   206,
      -1,   205,    -1,   204,    -1,    96,    -1,   111,    -1,   112,
      -1,   186,    -1,    46,    -1,    36,    -1,    66,    -1,    71,
      -1,    58,    -1,    53,    -1,    55,    -1,    77,    -1,    42,
      -1,   147,    -1,    51,    -1,   212,    -1,   170,    -1,   171,
      -1,   168,    -1,    69,    -1,    95,    -1,   116,    -1,   128,
      -1,   129,    -1,   106,    -1,    67,    -1,   135,    -1,   188,
      -1,   100,    -1,    94,    -1,   198,    -1,   126,    -1,   167,
      -1,    92,    -1,    50,    -1,   231,    -1,   101,    -1,   199,
      -1,   117,    -1,   159,    -1,   201,    -1,   150,    -1,   136,
      -1,    75,    -1,    76,    -1,   102,    -1,   200,    -1,   151,
      -1,   182,    -1,   196,    -1,   160,    -1,   137,    -1,   131,
      -1,   166,    -1,   148,    -1,   165,    -1,    33,    -1,    40,
      -1,    57,    -1,   113,    -1,    41,    -1,    56,    -1,   216,
      -1,    49,    -1,    60,    -1,    34,    -1,    47,    -1,   273,
      -1,   249,    -1,   282,    -1,   284,    -1,   253,    -1,   267,
      -1,   280,    -1,   272,    -1,   252,    -1,   266,    -1,   281,
      -1,   271,    -1,   265,    -1,   264,    -1,   248,    -1,   247,
      -1,   256,    -1,   257,    -1,   286,    -1,   276,    -1,   275,
      -1,   270,    -1,   268,    -1,   269,    -1,   229,    -1,   235,
      -1,   232,    -1,   226,    -1,   219,    -1,   218,    -1,   220,
      -1,   237,    -1,   227,    -1,   228,    -1,   234,    -1,   224,
      -1,   233,    -1,    65,    -1,    63,    -1,    74,    -1,   169,
      -1,   202,    -1,   242,    -1,   240,    -1,   241,    -1,   238,
      -1,   239,    -1,   244,    -1,   245,    -1,   246,    -1,    64,
      -1,   295,    -1,   293,    -1,   294,    -1,   299,    -1,   300,
      -1,   301,    -1,   296,    -1,   297,    -1,   298,    -1,    79,
      -1,    80,    -1,    81,    -1,    82,    -1,    83,    -1,    84,
      -1,    85,    -1,    86,    -1,    87,    -1,    88,    -1,    89,
      -1,   287,    -1,   288,    -1,   289,    -1,   290,    -1,   291,
      -1,   292,    -1,   303,    -1,   304,    -1,   305,    -1,   306,
      -1,   307,    -1,   308,    -1,   309,    -1,    90,    -1,   105,
      -1,   114,    -1,   172,    -1,   180,    -1,   189,    -1,   138,
      -1,    91,    -1,   115,    -1,   139,    -1,   181,    -1,   314,
      -1,   315,    -1,   316,    -1,   319,    -1,   318,    -1,   317,
      -1,   320,    -1,    25,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  xquery_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    11,    15,    17,    20,    22,
      25,    27,    30,    35,    42,    46,    50,    56,    58,    62,
      66,    72,    78,    80,    84,    88,    94,   101,   103,   107,
     111,   113,   115,   117,   119,   121,   123,   125,   127,   129,
     131,   133,   135,   137,   141,   145,   150,   154,   158,   162,
     166,   170,   176,   182,   188,   194,   200,   206,   208,   210,
     214,   218,   223,   229,   236,   238,   242,   246,   250,   254,
     261,   267,   276,   282,   288,   294,   296,   300,   304,   306,
     308,   310,   312,   314,   316,   318,   320,   325,   330,   332,
     335,   339,   341,   343,   345,   347,   349,   351,   353,   355,
     357,   359,   364,   368,   373,   377,   379,   381,   383,   386,
     389,   394,   398,   404,   408,   413,   418,   424,   426,   429,
     431,   436,   438,   443,   445,   449,   452,   456,   458,   460,
     465,   470,   476,   482,   485,   489,   494,   500,   502,   506,
     509,   513,   517,   523,   528,   535,   537,   540,   542,   545,
     554,   564,   566,   570,   572,   575,   578,   582,   594,   609,
     623,   646,   648,   650,   652,   653,   655,   657,   658,   660,
     663,   665,   668,   670,   672,   674,   676,   678,   680,   682,
     684,   686,   688,   690,   692,   696,   699,   703,   707,   710,
     714,   717,   721,   724,   728,   733,   739,   745,   748,   753,
     759,   763,   767,   770,   773,   782,   786,   788,   791,   795,
     797,   801,   805,   807,   809,   811,   813,   815,   817,   819,
     821,   823,   825,   827,   829,   831,   833,   835,   837,   839,
     841,   844,   847,   850,   853,   855,   857,   860,   865,   869,
     875,   880,   884,   886,   888,   890,   892,   894,   896,   898,
     900,   902,   905,   909,   913,   916,   918,   923,   927,   931,
     937,   942,   949,   954,   961,   967,   975,   980,   986,   992,
     999,  1003,  1007,  1010,  1012,  1016,  1021,  1027,  1031,  1038,
    1043,  1049,  1051,  1054,  1058,  1060,  1063,  1065,  1072,  1076,
    1080,  1083,  1087,  1089,  1093,  1096,  1101,  1107,  1114,  1120,
    1124,  1127,  1131,  1136,  1138,  1142,  1144,  1147,  1149,  1151,
    1153,  1156,  1159,  1162,  1166,  1168,  1170,  1173,  1176,  1179,
    1185,  1191,  1193,  1198,  1202,  1207,  1216,  1218,  1221,  1225,
    1228,  1232,  1241,  1243,  1246,  1250,  1259,  1270,  1279,  1290,
    1292,  1295,  1300,  1308,  1310,  1313,  1318,  1326,  1335,  1337,
    1341,  1343,  1347,  1349,  1353,  1357,  1361,  1365,  1366,  1371,
    1375,  1379,  1383,  1385,  1391,  1393,  1397,  1398,  1400,  1402,
    1406,  1408,  1412,  1416,  1418,  1422,  1426,  1430,  1434,  1436,
    1440,  1444,  1446,  1450,  1454,  1456,  1461,  1463,  1468,  1470,
    1475,  1477,  1482,  1484,  1487,  1489,  1492,  1494,  1496,  1499,
    1502,  1504,  1506,  1508,  1510,  1514,  1516,  1518,  1520,  1522,
    1524,  1526,  1528,  1530,  1532,  1537,  1543,  1549,  1556,  1560,
    1565,  1567,  1570,  1574,  1577,  1580,  1582,  1585,  1588,  1590,
    1592,  1594,  1598,  1602,  1604,  1606,  1608,  1611,  1613,  1616,
    1619,  1621,  1624,  1627,  1630,  1633,  1636,  1639,  1642,  1644,
    1647,  1650,  1652,  1655,  1658,  1661,  1664,  1667,  1669,  1671,
    1673,  1675,  1677,  1679,  1681,  1683,  1685,  1688,  1692,  1697,
    1699,  1702,  1706,  1708,  1710,  1712,  1714,  1716,  1718,  1720,
    1722,  1724,  1726,  1728,  1730,  1732,  1734,  1736,  1738,  1740,
    1742,  1744,  1747,  1750,  1754,  1756,  1761,  1766,  1770,  1775,
    1777,  1781,  1783,  1785,  1787,  1789,  1791,  1796,  1802,  1811,
    1821,  1831,  1842,  1844,  1847,  1849,  1852,  1859,  1860,  1862,
    1866,  1870,  1871,  1873,  1875,  1877,  1880,  1883,  1884,  1886,
    1888,  1890,  1893,  1896,  1898,  1900,  1902,  1904,  1906,  1908,
    1910,  1912,  1914,  1916,  1918,  1922,  1926,  1929,  1933,  1937,
    1940,  1942,  1944,  1946,  1948,  1950,  1952,  1957,  1961,  1969,
    1973,  1981,  1986,  1991,  1995,  2003,  2006,  2008,  2011,  2015,
    2017,  2019,  2021,  2023,  2025,  2029,  2033,  2035,  2037,  2039,
    2041,  2045,  2047,  2049,  2051,  2053,  2055,  2057,  2059,  2061,
    2063,  2065,  2067,  2071,  2075,  2080,  2085,  2089,  2093,  2097,
    2102,  2107,  2111,  2116,  2123,  2128,  2135,  2140,  2144,  2149,
    2156,  2163,  2168,  2175,  2182,  2187,  2189,  2192,  2194,  2196,
    2198,  2202,  2206,  2208,  2210,  2215,  2221,  2228,  2232,  2236,
    2240,  2244,  2250,  2258,  2266,  2272,  2278,  2284,  2292,  2300,
    2306,  2312,  2316,  2320,  2326,  2334,  2340,  2348,  2350,  2355,
    2359,  2365,  2367,  2370,  2374,  2378,  2380,  2384,  2387,  2388,
    2390,  2392,  2395,  2397,  2401,  2403,  2407,  2409,  2414,  2416,
    2419,  2423,  2424,  2426,  2427,  2429,  2434,  2437,  2441,  2443,
    2444,  2446,  2451,  2452,  2454,  2457,  2459,  2463,  2464,  2466,
    2469,  2472,  2474,  2475,  2477,  2478,  2480,  2482,  2484,  2486,
    2488,  2490,  2492,  2496,  2500,  2502,  2504,  2506,  2509,  2513,
    2515,  2517,  2519,  2521,  2523,  2525,  2527,  2529,  2532,  2535,
    2537,  2539,  2542,  2545,  2549,  2551,  2554,  2557,  2563,  2566,
    2568,  2570,  2571,  2574,  2576,  2580,  2585,  2586,  2589,  2590,
    2593,  2598,  2603,  2607,  2610,  2614,  2616,  2620,  2621,  2623,
    2625,  2628,  2631,  2634,  2637,  2639,  2642,  2645,  2648,  2651,
    2655,  2658,  2662,  2666,  2671,  2674,  2677,  2679,  2681,  2685,
    2688,  2692,  2695,  2699,  2702,  2706,  2710,  2714,  2720,  2726,
    2732,  2741,  2747,  2751,  2757,  2765,  2767,  2769,  2771,  2775,
    2779,  2783,  2785,  2787,  2789,  2791,  2793,  2795,  2797,  2799,
    2801,  2803,  2805,  2807,  2809,  2811,  2813,  2815,  2817,  2819,
    2821,  2823,  2825,  2827,  2829,  2831,  2833,  2835,  2837,  2839,
    2841,  2843,  2845,  2847,  2849,  2851,  2853,  2855,  2857,  2859,
    2861,  2863,  2865,  2867,  2869,  2871,  2873,  2875,  2877,  2879,
    2881,  2883,  2885,  2887,  2889,  2891,  2893,  2895,  2897,  2899,
    2901,  2903,  2905,  2907,  2909,  2911,  2913,  2915,  2917,  2919,
    2921,  2923,  2925,  2927,  2929,  2931,  2933,  2935,  2937,  2939,
    2941,  2943,  2945,  2947,  2949,  2951,  2953,  2955,  2957,  2959,
    2961,  2963,  2965,  2967,  2969,  2971,  2973,  2975,  2977,  2979,
    2981,  2983,  2985,  2987,  2989,  2991,  2993,  2995,  2997,  2999,
    3001,  3003,  3005,  3007,  3009,  3011,  3013,  3015,  3017,  3019,
    3021,  3023,  3025,  3027,  3029,  3031,  3033,  3035,  3037,  3039,
    3041,  3043,  3045,  3047,  3049,  3051,  3053,  3055,  3057,  3059,
    3061,  3063,  3065,  3067,  3069,  3071,  3073,  3075,  3077,  3079,
    3081,  3083,  3085,  3087,  3089,  3091,  3093,  3095,  3097,  3099,
    3101,  3103,  3105,  3107,  3109,  3111,  3113,  3115,  3117,  3119,
    3121,  3123,  3125,  3127,  3129,  3131,  3133,  3135,  3137,  3139,
    3141,  3143,  3145,  3147,  3149,  3151,  3153,  3155,  3157,  3159,
    3161,  3163,  3165,  3167,  3169,  3171,  3173,  3175,  3177,  3179,
    3181,  3183,  3185,  3187,  3189,  3191,  3193,  3195,  3197,  3199,
    3201,  3203,  3205,  3207,  3209,  3211,  3213,  3215,  3217,  3219,
    3221,  3223,  3225,  3227,  3229,  3231,  3233
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1051,  1051,  1052,  1056,  1060,  1068,  1074,  1083,  1089,
    1097,  1103,  1114,  1119,  1127,  1134,  1141,  1150,  1157,  1165,
    1173,  1181,  1192,  1197,  1204,  1211,  1223,  1233,  1240,  1247,
    1259,  1260,  1261,  1262,  1263,  1268,  1269,  1270,  1271,  1272,
    1273,  1274,  1277,  1282,  1287,  1295,  1303,  1311,  1316,  1324,
    1329,  1337,  1342,  1350,  1355,  1360,  1365,  1373,  1375,  1378,
    1388,  1393,  1401,  1409,  1420,  1427,  1438,  1443,  1451,  1458,
    1465,  1474,  1487,  1495,  1502,  1512,  1519,  1526,  1537,  1538,
    1539,  1540,  1541,  1542,  1543,  1544,  1549,  1555,  1564,  1571,
    1581,  1591,  1592,  1593,  1594,  1595,  1596,  1597,  1598,  1599,
    1600,  1605,  1613,  1621,  1629,  1636,  1644,  1651,  1656,  1664,
    1672,  1686,  1700,  1717,  1722,  1730,  1738,  1749,  1754,  1763,
    1768,  1775,  1780,  1790,  1795,  1804,  1810,  1823,  1828,  1836,
    1847,  1862,  1874,  1889,  1894,  1899,  1904,  1912,  1919,  1930,
    1935,  1945,  1954,  1963,  1972,  1984,  1988,  1994,  1998,  2008,
    2018,  2031,  2037,  2046,  2051,  2058,  2065,  2076,  2086,  2096,
    2106,  2124,  2144,  2148,  2153,  2160,  2164,  2169,  2176,  2181,
    2193,  2200,  2212,  2213,  2214,  2215,  2216,  2217,  2218,  2220,
    2221,  2222,  2223,  2224,  2229,  2234,  2242,  2259,  2267,  2275,
    2282,  2289,  2300,  2309,  2318,  2327,  2340,  2348,  2356,  2364,
    2379,  2384,  2392,  2406,  2423,  2448,  2456,  2463,  2474,  2484,
    2489,  2502,  2515,  2516,  2517,  2518,  2519,  2520,  2525,  2526,
    2529,  2530,  2531,  2532,  2533,  2536,  2537,  2538,  2539,  2540,
    2545,  2559,  2567,  2572,  2580,  2585,  2590,  2598,  2607,  2619,
    2629,  2642,  2650,  2651,  2652,  2657,  2658,  2659,  2660,  2661,
    2666,  2673,  2683,  2689,  2698,  2708,  2715,  2723,  2735,  2745,
    2755,  2765,  2775,  2785,  2795,  2805,  2816,  2825,  2835,  2845,
    2861,  2870,  2879,  2887,  2893,  2905,  2913,  2923,  2931,  2943,
    2949,  2960,  2962,  2966,  2974,  2978,  2983,  2987,  2991,  2995,
    3005,  3013,  3020,  3026,  3036,  3040,  3044,  3052,  3060,  3068,
    3080,  3088,  3094,  3104,  3110,  3120,  3124,  3134,  3140,  3146,
    3152,  3161,  3170,  3179,  3192,  3196,  3204,  3210,  3220,  3228,
    3237,  3250,  3257,  3269,  3273,  3285,  3292,  3298,  3307,  3314,
    3320,  3331,  3338,  3344,  3353,  3362,  3369,  3380,  3387,  3399,
    3405,  3417,  3423,  3434,  3440,  3451,  3457,  3468,  3477,  3481,
    3490,  3494,  3502,  3506,  3516,  3523,  3532,  3542,  3541,  3555,
    3564,  3573,  3586,  3590,  3602,  3606,  3614,  3617,  3624,  3628,
    3637,  3641,  3645,  3653,  3657,  3663,  3669,  3675,  3685,  3689,
    3693,  3701,  3705,  3711,  3721,  3725,  3735,  3739,  3749,  3753,
    3763,  3767,  3777,  3781,  3790,  3794,  3802,  3806,  3810,  3814,
    3824,  3828,  3832,  3839,  3844,  3852,  3856,  3860,  3864,  3868,
    3872,  3880,  3884,  3888,  3896,  3900,  3904,  3908,  3919,  3925,
    3935,  3941,  3951,  3955,  3959,  3997,  4001,  4011,  4021,  4034,
    4043,  4053,  4057,  4066,  4070,  4079,  4085,  4093,  4099,  4111,
    4117,  4127,  4131,  4135,  4139,  4143,  4149,  4155,  4163,  4167,
    4175,  4179,  4190,  4194,  4198,  4204,  4208,  4222,  4226,  4234,
    4238,  4248,  4252,  4256,  4260,  4269,  4273,  4277,  4281,  4289,
    4295,  4305,  4313,  4317,  4321,  4325,  4329,  4333,  4337,  4341,
    4345,  4349,  4354,  4358,  4362,  4366,  4374,  4378,  4386,  4393,
    4400,  4411,  4419,  4423,  4431,  4439,  4447,  4501,  4505,  4518,
    4524,  4534,  4538,  4546,  4550,  4554,  4562,  4572,  4582,  4599,
    4616,  4633,  4655,  4661,  4672,  4678,  4689,  4700,  4702,  4706,
    4711,  4721,  4724,  4731,  4737,  4743,  4751,  4764,  4767,  4774,
    4780,  4786,  4793,  4804,  4808,  4818,  4822,  4832,  4836,  4840,
    4845,  4854,  4860,  4866,  4872,  4880,  4885,  4893,  4898,  4906,
    4914,  4919,  4924,  4929,  4934,  4939,  4948,  4956,  4960,  4977,
    4981,  4989,  4997,  5005,  5009,  5017,  5025,  5029,  5033,  5068,
    5074,  5080,  5090,  5094,  5098,  5102,  5106,  5110,  5114,  5121,
    5127,  5137,  5145,  5153,  5157,  5161,  5165,  5169,  5173,  5177,
    5181,  5185,  5193,  5201,  5205,  5209,  5219,  5227,  5235,  5239,
    5243,  5251,  5255,  5261,  5267,  5271,  5281,  5289,  5293,  5299,
    5308,  5317,  5323,  5329,  5339,  5356,  5363,  5378,  5414,  5418,
    5426,  5434,  5446,  5450,  5458,  5466,  5470,  5481,  5498,  5504,
    5510,  5520,  5524,  5530,  5536,  5540,  5546,  5550,  5556,  5562,
    5569,  5579,  5584,  5592,  5598,  5608,  5630,  5639,  5645,  5658,
    5672,  5679,  5685,  5695,  5704,  5712,  5718,  5736,  5744,  5748,
    5755,  5760,  5768,  5772,  5779,  5783,  5790,  5794,  5801,  5805,
    5814,  5827,  5830,  5838,  5841,  5849,  5857,  5865,  5869,  5877,
    5880,  5888,  5900,  5903,  5911,  5923,  5929,  5939,  5942,  5950,
    5954,  5958,  5966,  5969,  5977,  5980,  5988,  5992,  5996,  6000,
    6004,  6012,  6020,  6032,  6044,  6048,  6052,  6060,  6066,  6076,
    6080,  6084,  6088,  6092,  6096,  6100,  6104,  6112,  6116,  6120,
    6124,  6132,  6138,  6148,  6158,  6162,  6170,  6180,  6191,  6198,
    6202,  6210,  6213,  6220,  6225,  6234,  6244,  6247,  6254,  6258,
    6266,  6275,  6282,  6292,  6296,  6303,  6309,  6319,  6322,  6329,
    6334,  6346,  6354,  6366,  6374,  6378,  6386,  6390,  6394,  6402,
    6410,  6414,  6418,  6422,  6430,  6438,  6450,  6454,  6462,  6476,
    6480,  6487,  6492,  6500,  6505,  6514,  6522,  6528,  6538,  6544,
    6554,  6561,  6568,  6593,  6621,  6649,  6653,  6657,  6664,  6671,
    6678,  6690,  6694,  6695,  6708,  6709,  6710,  6711,  6712,  6713,
    6714,  6715,  6716,  6717,  6718,  6719,  6720,  6721,  6722,  6723,
    6727,  6728,  6729,  6730,  6731,  6732,  6733,  6734,  6735,  6736,
    6737,  6738,  6739,  6740,  6741,  6742,  6743,  6744,  6745,  6746,
    6747,  6748,  6749,  6750,  6751,  6752,  6753,  6754,  6755,  6756,
    6757,  6758,  6759,  6760,  6761,  6762,  6763,  6764,  6765,  6766,
    6767,  6768,  6769,  6770,  6771,  6772,  6773,  6774,  6775,  6776,
    6777,  6778,  6779,  6780,  6781,  6782,  6783,  6784,  6785,  6786,
    6787,  6788,  6789,  6790,  6791,  6792,  6793,  6794,  6795,  6796,
    6797,  6798,  6799,  6800,  6801,  6802,  6803,  6804,  6805,  6806,
    6807,  6808,  6809,  6810,  6811,  6812,  6813,  6814,  6815,  6816,
    6817,  6818,  6819,  6820,  6821,  6822,  6823,  6824,  6825,  6826,
    6827,  6828,  6829,  6830,  6831,  6832,  6833,  6834,  6835,  6836,
    6837,  6838,  6839,  6840,  6841,  6842,  6843,  6844,  6845,  6846,
    6847,  6848,  6849,  6850,  6851,  6852,  6853,  6854,  6855,  6856,
    6857,  6858,  6859,  6860,  6861,  6862,  6863,  6864,  6865,  6866,
    6867,  6868,  6869,  6870,  6871,  6872,  6873,  6874,  6875,  6876,
    6877,  6878,  6879,  6880,  6881,  6882,  6883,  6884,  6885,  6886,
    6887,  6888,  6889,  6890,  6891,  6892,  6893,  6894,  6895,  6896,
    6897,  6898,  6899,  6900,  6901,  6902,  6903,  6904,  6905,  6906,
    6907,  6908,  6909,  6910,  6911,  6912,  6913,  6914,  6915,  6916,
    6917,  6918,  6919,  6920,  6921,  6922,  6923,  6924,  6925,  6926,
    6927,  6928,  6929,  6930,  6931,  6932,  6937
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
  const int xquery_parser::yylast_ = 15819;
  const int xquery_parser::yynnts_ = 323;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 608;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 334;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 588;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 17432 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 6941 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"


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
      // and the old message has a "','" text, the replace the old message with the new one. Unfortunately this 
      // makes the parser error messages harder to internationalize.
      if ( ! (msg.find("(missing comma \",\" between expressions?)") != string::npos
              &&
              prevErr->msg.find(zstring("\",\"")) != zstring::npos))
        return;
    }

    // remove the double quoting "''" from every token description
    string message = msg;
    int pos;
    while ((pos = message.find("\"'")) != -1 || (pos = message.find("'\"")) != -1)
      message.replace(pos, 2, "\"");
    driver.set_expr(new ParseErrorNode(driver.createQueryLoc(loc), err::XPST0003, message));
  }
}

} // namespace zorba

