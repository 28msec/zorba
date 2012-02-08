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
#line 87 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"


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
#line 77 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 892 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 299 of lalr1.cc  */
#line 1016 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 299 of lalr1.cc  */
#line 107 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"

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
#line 193 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"

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
        case 109: /* "\"'DECIMAL'\"" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 298 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 123: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 307 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 148: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 316 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 325 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 334 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 343 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 352 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 361 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 370 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 379 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 388 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 397 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 406 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 415 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 424 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 433 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 442 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 451 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 460 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 469 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 478 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 487 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 496 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 505 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 514 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 523 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 532 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 541 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 550 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 559 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 568 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 577 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 586 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 595 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 604 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 613 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 622 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 631 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 640 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 649 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 658 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 667 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 676 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 685 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 694 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 703 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 712 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 721 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 730 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 739 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 748 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 757 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 766 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 775 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 784 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 793 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 802 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 811 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 820 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 829 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 838 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 847 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 856 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 865 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 874 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 883 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 892 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 901 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 910 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 919 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 928 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 937 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 946 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 955 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 964 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 973 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 982 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 991 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1000 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1009 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1018 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1027 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1036 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1045 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1054 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1063 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1072 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1081 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1090 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1099 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1108 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1117 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1126 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1135 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1144 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1153 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1162 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1171 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1180 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1189 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1198 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1207 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1216 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1225 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1234 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1243 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1252 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1261 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1270 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1279 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1288 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1297 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1306 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1315 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1324 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1333 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1342 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1351 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1360 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1369 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1378 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1387 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1396 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1405 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1414 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1423 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "JSONPairConstructor" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1432 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1441 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1450 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1459 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1468 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1477 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1486 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1495 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1504 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1513 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1522 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1531 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1540 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1549 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1558 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1567 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1576 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1585 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1594 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1603 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1612 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1621 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1630 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1639 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1648 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1657 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1666 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1675 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1684 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1693 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1702 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1711 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1720 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1729 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1738 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1747 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1756 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1765 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1774 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1783 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1792 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1801 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1810 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1819 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1828 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1837 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1846 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1855 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1864 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1873 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1882 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1891 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1900 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1909 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1918 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1927 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1936 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1945 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1954 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1963 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1972 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1981 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1990 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1999 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2008 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2017 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2026 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2035 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2044 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2053 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2062 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2071 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2080 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2089 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2098 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2107 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2116 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2125 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2134 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2143 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2152 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2161 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2170 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2179 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2188 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2197 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2206 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2215 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2224 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2233 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2242 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2251 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2260 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2269 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2278 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2287 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2296 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2305 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2314 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2323 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2332 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2341 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2350 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2359 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2368 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2377 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2386 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2395 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2404 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2413 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2422 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2431 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2440 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2449 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2458 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2467 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2476 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2485 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2494 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2503 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2512 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2521 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2530 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2539 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2548 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2557 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2566 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2575 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2584 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 615: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2593 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2602 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2611 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2620 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 622: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2629 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 623: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2638 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 624: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2647 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 625: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2656 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 626: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2665 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 627: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2674 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2683 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* "JSONConstructor" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2692 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 630: /* "JSONDirectArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2701 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 638: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2710 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 639: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2719 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 640: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2728 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
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
#line 140 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 565 of lalr1.cc  */
#line 2825 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"

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
#line 1034 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 1043 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 1052 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 1058 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 1066 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 1072 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 1083 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 1088 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 1096 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 1103 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 1110 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 1119 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 1126 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 1134 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 1142 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 1150 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 1161 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 1166 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 1173 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 1180 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 1192 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 1202 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 1209 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 1216 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      // error
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 1251 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 1256 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 1264 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 1272 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 1280 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 1285 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 1293 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1298 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1306 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1311 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1319 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1326 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1333 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1340 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1355 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1365 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 1370 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 1378 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 1386 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 1397 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1404 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1415 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1420 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1428 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1435 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1442 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1451 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 1464 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1472 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1479 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1489 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 1496 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1503 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 1526 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 1532 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 1541 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 1548 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1558 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1567 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1568 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1569 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1570 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1571 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1572 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1573 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1574 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1575 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1576 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1582 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1590 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1598 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1606 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1613 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1621 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1628 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1633 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1641 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1649 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1664 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1679 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1697 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1702 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1710 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1718 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 1729 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1734 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1743 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1748 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1755 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1760 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1770 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1775 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1784 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1790 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1803 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1808 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1816 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1827 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1842 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1854 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1869 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1874 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1879 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1884 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1892 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1899 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1910 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1915 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1925 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1932 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1939 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1946 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1956 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1960 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1970 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);
    }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1978 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(9) - (4)].expr)),
                             (yysemantic_stack_[(9) - (7)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (9)].node)),
                             static_cast<AnnotationListParsenode*>((yysemantic_stack_[(9) - (2)].node)));
    }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1989 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1995 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 2004 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 2009 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 2016 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 2023 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 2035 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 2045 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 2055 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 2066 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2082 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2102 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 2106 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 2110 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 2118 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 2122 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 2126 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 2134 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 2139 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 2151 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 2158 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 2187 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 2192 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 2200 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2217 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 2225 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 2233 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 2240 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 2247 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 2257 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2269 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2282 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2294 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2310 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 2318 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 2326 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 2334 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2349 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 2354 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 2362 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2376 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2393 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2418 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2426 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 2433 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2444 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 2454 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 2459 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2497 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2511 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 2519 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 2524 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 2532 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 2537 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 2542 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 2550 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 2559 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 228:

/* Line 690 of lalr1.cc  */
#line 2571 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2581 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2594 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2618 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2625 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2635 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 2643 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 2650 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 2660 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2670 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2680 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2690 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2700 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2710 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2720 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2730 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2741 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2750 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2760 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2770 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2786 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2795 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2804 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2812 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2818 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2830 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2838 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2848 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2856 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 2868 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 2874 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 2887 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 2891 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 2899 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 2903 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2912 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2916 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2920 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2930 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2938 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2945 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2951 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2962 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2966 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2975 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2983 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2989 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2999 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 3005 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 3015 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 3019 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 3029 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 3035 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 3041 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 3047 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3056 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3065 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3074 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3087 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 3091 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 3099 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 3105 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 3115 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 3123 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3132 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3145 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 3152 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 3164 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 3168 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 3180 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 3187 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 3193 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 3202 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 3209 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 3215 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 3226 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 3233 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 3239 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 3248 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 3257 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 3264 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 3275 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 3282 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 3294 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 3300 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 3312 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 3318 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 3329 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 3335 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 3346 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 3352 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 3363 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 3372 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 3376 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 3385 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 3389 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 3397 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 3401 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3411 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 3418 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3427 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3436 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 3441 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3450 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3459 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3468 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3481 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 3485 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3497 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 3501 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 3508 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 3512 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 3519 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 3523 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new JSON_PairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 3531 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 3535 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 3539 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3547 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3551 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3557 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 3563 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3569 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 3579 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 3583 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3587 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 3595 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 3599 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 3605 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 3615 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3619 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 368:

/* Line 690 of lalr1.cc  */
#line 3629 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3633 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3643 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3647 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3657 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3661 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3671 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3675 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3683 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3687 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3691 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3695 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3705 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3709 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3713 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3721 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3725 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3729 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3733 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3737 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3741 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3749 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3753 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3757 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3765 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3769 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3773 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3777 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3788 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3794 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3804 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3810 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3820 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3824 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3828 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3866 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3870 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3880 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3890 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3903 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3912 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 409:

/* Line 690 of lalr1.cc  */
#line 3922 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3926 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3935 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3939 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3948 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3954 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3962 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3968 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3980 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3986 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3996 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 4000 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 4004 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 4008 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 4012 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 4018 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 4024 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 4032 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 4036 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 4044 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 4048 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 4059 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 4063 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 4067 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 4073 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 4077 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 4091 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 4095 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 4103 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 4107 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 4117 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 4121 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 4125 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 4129 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 4138 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 4142 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 4146 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 4150 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 4158 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 4164 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 4174 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 4182 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 4186 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 4190 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 4194 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 4198 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 4202 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 4206 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 4210 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 4214 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 4218 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 4222 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 4230 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 4234 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 4242 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 4249 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 4256 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 4267 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 4275 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 4279 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 4287 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 4295 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 4303 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 4357 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 4361 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 4374 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 4380 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 4390 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 4394 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 4402 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 4406 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 4410 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 4418 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 4428 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 4438 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 4448 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 4458 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 4468 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 4483 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 4489 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 4500 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 4506 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 4517 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 4534 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 4539 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 4548 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 4552 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 4559 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 4565 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 4571 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 4579 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 4591 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 4595 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 4602 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 4608 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 4614 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 4621 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 4632 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 4636 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 4646 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 4650 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 4660 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 4664 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 4668 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 4673 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 4682 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 4688 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 4694 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 4700 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 4708 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 4713 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 4721 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 4726 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 4734 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 4742 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 4747 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 4752 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 4757 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 4762 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 4767 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 4776 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 4784 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 4788 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 4805 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 4809 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 4817 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 4825 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 4833 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 4837 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 4845 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 4851 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 4861 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 4869 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 4873 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 4877 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 4912 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 4918 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 4924 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 4934 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 4938 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 4942 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 4946 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 4950 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 4954 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 4958 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 4965 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 4971 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 4981 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 4989 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 4993 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 4997 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 5001 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 5005 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 5009 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 5013 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 5017 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 5021 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 5029 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 5037 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 5041 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 5045 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 5055 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 5063 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 5071 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 5075 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 5079 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 5087 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 5091 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 5097 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 5103 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 5107 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 5117 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 5125 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 5129 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 5135 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 5144 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 5153 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 5159 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 5165 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 5175 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 5192 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 5199 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 5214 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 5250 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 5254 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 5262 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 5270 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 5282 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 5286 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 5294 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 5302 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 5306 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 5317 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 5334 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 5340 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 5346 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 5356 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 5360 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 5366 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 5372 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 5376 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 5382 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 5386 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 5392 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 5398 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 5405 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 5415 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 5420 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 5428 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 5434 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 5444 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 5466 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 5475 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 5481 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 5494 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 5508 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 5515 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 5521 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 5531 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 5540 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 5548 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 5554 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 5572 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 5580 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 5584 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 5591 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 5596 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 5604 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 5608 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 5615 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 5619 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 5626 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 5630 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 5637 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 5641 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 5650 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 5662 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 5666 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 5673 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 5677 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 5685 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 5693 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 5701 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 5705 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 5712 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 5716 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 5724 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 5735 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 5739 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 5747 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 5759 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 5765 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 5774 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 5778 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 5786 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 5790 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 5794 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 5801 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 5805 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 5812 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 5816 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 5824 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 5828 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 5832 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 5836 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 5840 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 5848 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 5856 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 5868 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 5880 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 5884 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 5888 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 5896 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 5902 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 5912 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 5916 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 5920 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 5924 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 5928 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 5932 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 5936 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 5940 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 5948 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 5952 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 5956 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 5960 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 5968 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 5974 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 5984 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 5994 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 5998 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 6006 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 703:

/* Line 690 of lalr1.cc  */
#line 6016 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 704:

/* Line 690 of lalr1.cc  */
#line 6027 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 6034 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 6038 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 6045 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 6049 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 6056 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 6061 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 6070 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 6079 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 6083 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 6090 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 6094 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 6102 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 6111 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 6118 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 6128 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 6132 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 6139 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 6145 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 6154 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 6158 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 6165 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 6170 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 6182 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 6190 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 6202 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 6210 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 6214 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 6222 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 6226 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 6230 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 6238 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 6246 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 6250 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 6254 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 6258 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 6266 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 6274 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 6286 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 6290 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 6298 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 6307 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 6315 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new JSON_ArrayConstructor(LOC((yyloc)), NULL);
    }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 6319 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new JSON_ArrayConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 6327 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 6332 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 6337 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 6342 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 6350 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
    }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 6357 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
    }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 6364 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
    }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 6372 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonPair);
    }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 6390 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 760:

/* Line 690 of lalr1.cc  */
#line 6403 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 6404 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 6405 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 6406 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 6407 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 6408 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 6409 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 6410 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 6411 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 6412 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 6413 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 6414 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 6415 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 6416 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 6417 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 6422 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 6423 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 6424 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 6425 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 6426 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 6427 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 6428 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 6429 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 6430 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 6431 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 6432 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 6433 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 6434 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 789:

/* Line 690 of lalr1.cc  */
#line 6435 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 6436 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 791:

/* Line 690 of lalr1.cc  */
#line 6437 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 792:

/* Line 690 of lalr1.cc  */
#line 6438 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 793:

/* Line 690 of lalr1.cc  */
#line 6439 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 6440 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 6441 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 796:

/* Line 690 of lalr1.cc  */
#line 6442 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 6443 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 798:

/* Line 690 of lalr1.cc  */
#line 6444 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 6445 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 6446 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 6447 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 802:

/* Line 690 of lalr1.cc  */
#line 6448 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 803:

/* Line 690 of lalr1.cc  */
#line 6449 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 6450 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 805:

/* Line 690 of lalr1.cc  */
#line 6451 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 6452 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 6453 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 6454 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 6455 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 6456 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 6457 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 6458 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 6459 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 6460 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 6461 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 6462 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 6463 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 6464 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 6465 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 6466 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 6467 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 6468 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 6469 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 6470 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 6471 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 6472 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 6473 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 6474 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 6475 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 6476 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 6477 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 6478 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 6479 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 6480 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 6481 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 6482 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 6483 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 6484 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 6485 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 6486 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 6487 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 6488 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 6489 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 6490 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 6491 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 6492 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 6493 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 6494 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 6495 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 6496 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 6497 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 6498 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 6499 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 6500 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 6501 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 6502 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 6503 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 6504 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 6505 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 6506 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 6507 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 6508 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 6509 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 6510 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 6511 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 6512 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 6513 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 6514 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 6515 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 6516 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 6517 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 6518 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 6519 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 6520 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 6521 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 6522 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 6523 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 6524 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 6525 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 6526 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 6527 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 6528 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 6529 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 6530 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 6531 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 6532 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 6533 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 6534 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 6535 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 6536 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 6537 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 6538 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 6539 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 6540 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 6541 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 6542 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 6543 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 6544 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 6545 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 6546 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 6547 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 6548 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 6549 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 6550 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 6551 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 6552 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 6553 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 6554 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 6555 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 6556 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 6557 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 6558 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 6559 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 6560 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 6561 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 6562 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 6563 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 6564 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 6565 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 6566 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 6567 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 6568 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 6569 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 6570 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 6571 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 6572 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 6573 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 6574 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 6575 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 6576 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 6577 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 6578 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 6579 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 6580 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 6581 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 6582 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 6583 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 6584 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 6585 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 6586 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 6587 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 6588 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 6589 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 6590 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 6591 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 6592 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 6593 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 6594 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 6595 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 6596 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 6597 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 6598 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 6599 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 6600 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 6601 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 6602 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 6603 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 6604 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 6605 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 6606 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 6607 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 6608 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 6609 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 6610 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 6611 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 6612 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 6613 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 6614 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 6615 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 6616 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 6617 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 6618 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 6619 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 6620 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 6621 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 6622 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pair"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 6623 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 6624 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 6629 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 11731 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1445;
  const short int
  xquery_parser::yypact_[] =
  {
      2721, -1445, -1445, -1445,  4232,  4232,  4232, -1445, -1445,    -3,
      22, -1445,    84,   131, -1445, -1445, -1445,   395, -1445, -1445,
   -1445,   171,   189,   740,   644,   232,   262,   609, -1445,   -48,
   -1445, -1445, -1445, -1445, -1445, -1445,   753, -1445,   295,   322,
   -1445, -1445, -1445, -1445,   504, -1445,   758, -1445,   481,   510,
   -1445,   141, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445,
   -1445, -1445, -1445, -1445, -1445, -1445,   574,   602, -1445, -1445,
   -1445, -1445,   486,  9366, -1445, -1445, -1445,   661, -1445, -1445,
   -1445,   613, -1445,   719,   725, -1445, -1445, 13158, -1445, -1445,
   -1445, -1445, -1445, -1445, -1445, -1445,   634, -1445, -1445,   754,
     764, -1445, -1445, -1445, -1445, -1445, -1445, -1445,  3024,  6044,
    6346, 13158, -1445, -1445, -1445, -1445, -1445, -1445, -1445,   748,
   -1445, -1445,   783, 10262, -1445, 10557,   796,   819, -1445, -1445,
   -1445,   824, -1445,  8762, -1445, -1445, -1445, -1445, -1445, -1445,
     797, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445,    51,
     734, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445,   -40,
     795,   297, -1445,   731,   558, -1445, -1445, -1445, -1445, -1445,
   -1445,   838, -1445,   718,   722,   723, -1445, -1445,   801,   806,
   -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445,
   -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445,
   -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445,
   -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445,
   -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445,
   -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445,
   -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445,  4534,   962,
   -1445,  4836, -1445, -1445,   341,    55, -1445, -1445, -1445, -1445,
   -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445,
      75, -1445, -1445, -1445, -1445, -1445, -1445,   288, -1445, -1445,
   -1445, -1445, -1445, -1445, -1445, -1445,  4232, -1445, -1445, -1445,
   -1445,    17, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445,
     858, -1445,   776, -1445, -1445, -1445,   303, -1445, -1445, -1445,
   -1445, -1445, -1445, -1445, -1445,   800,   876, -1445,   940,   724,
     772,   547,   519,   669,   287, -1445,   922,   775,   875,   877,
    7554, -1445, -1445, -1445,    -1, -1445, -1445,  9064, -1445,   630,
   -1445,   823,  9366, -1445,   823,  9366, -1445, -1445, -1445,   489,
   -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445,
   -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445,
   -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445,
   -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445,
   -1445, -1445, -1445, -1445,   835,   825, -1445, -1445, -1445, -1445,
   -1445,   799, -1445,  4232,   804,   805,   412,   412,   954,   157,
     591,   578, 13447, 13158,   -36,   939, 13158,   840,   873,   137,
   10262,   714,   749, 13158, 13158,   693,   588,    28, -1445, -1445,
   -1445, 10262,  4232,   810,  4232,   103,  7856, 11135,   720,   726,
   13158,   882,   308,   848,  7856,  1002,    98,    77, 13158,   887,
     865,   901, -1445,  7856,  9965, 13158, 13158, 13158,  4232,   826,
    7856,  7856, 13158,  4232,   859,   861, -1445, -1445, -1445,  7856,
   11424,   855, -1445,   869, -1445, -1445, -1445, -1445,   870, -1445,
     871, -1445, -1445, -1445, -1445, -1445,   874, -1445, -1445, -1445,
   -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445,
   -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445,
   -1445, -1445, -1445, -1445, 13158, -1445, -1445, -1445, -1445, -1445,
   -1445, -1445, -1445, -1445, -1445, -1445, -1445,   889, 13158, -1445,
   -1445, -1445,   831,  3326,   878,   879,   880, 13158,  4232, -1445,
     884,    20, -1445,   488, -1445,   193,   993,  7856, -1445, -1445,
      56, -1445, -1445, -1445,  1021, -1445, -1445, -1445, -1445,  7856,
     828, -1445,  1012,  7856,  7856,   856,  7856,  7856,  7856,  7856,
     814, 13158,   857,   860,  7856,  7856,  3024,   812, -1445, -1445,
   -1445, -1445,    84,   609,    82,    87,  1041,  5138,  5138,  5440,
    5440,   613, -1445, -1445,   858,   613, -1445,  7856, -1445,   930,
     644,   -48,   881,   888,   893,  4232,  7856, -1445, -1445, -1445,
   -1445, -1445, -1445, -1445, -1445,  8158,  8158,  8158, -1445,  8158,
    8158, -1445,  8158, -1445,  8158, -1445, -1445, -1445, -1445, -1445,
   -1445, -1445,  8158,  8158,   980,  8158,  8158,  8158,  8158,  8158,
    8158,  8158,  8158,  8158,  8158,  8158,  8158,   834,   970,   972,
     973, -1445, -1445, -1445,  6648, -1445, -1445,  8762,  8762,  7856,
     823, -1445, -1445,   823, -1445,  6950,   823,   920,  7252, -1445,
   -1445, -1445,   195, -1445,   202, -1445, -1445, -1445, -1445, -1445,
   -1445,   963,   966,   232,  1044, -1445, -1445, 13447,   839,   622,
   13158,   915,   917,   839,   954,   951,   950, -1445, -1445, -1445,
     116,   841,   989,   787, 13158,   945,  7856,   971, 13158, 13158,
   -1445,   956,   908,  4232, -1445,   909,   869,   322, -1445,   907,
     911,   218, -1445,   222,   229, -1445, -1445,   994, -1445,    21,
   13158,   -14, 13158,  1008,   276, -1445,  4232, -1445,   283, -1445,
   10262,  1007,  1060, 10262,   954,  1011,   585, 13158,  7856,   -48,
     278,   923, -1445,   925,   926,   927,    23, -1445,    40,   931,
   -1445,   292,   294,   964, -1445,   932,  4232,  4232,   307, -1445,
     299,   300,   624,  7856,    48, -1445, -1445,  7856,  7856,  7856,
   -1445,  7856, -1445,  7856, -1445, 13158,   993, -1445,   257,   314,
   -1445, -1445, -1445,   321, -1445,   286, -1445, -1445, -1445,   115,
     125,  1014,   885,   894,    54, -1445,   978, -1445, -1445,   933,
     337,  3628,   353,  9668,   812, -1445,   341,   746,  1088,  1088,
   -1445, -1445,    95, -1445, -1445,    96, -1445,    33, -1445, -1445,
   -1445, -1445, -1445, -1445, -1445, 13158,   955,  7856,  1009, -1445,
   -1445, -1445,   876, -1445, -1445, -1445, -1445, -1445,  8158, -1445,
   -1445, -1445,    50, -1445,   627,   519,   519,   669,   669,   669,
     669,   287,   287, -1445, -1445, 12580, 12580, 13158, 13158, -1445,
     376, -1445, -1445,    24, -1445, -1445, -1445,   339, -1445, -1445,
     343,   412, -1445, -1445,    10,   636,   658, -1445,   232, -1445,
   -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445,   839,
   -1445,   996, 12869,   984,  7856, -1445, -1445, -1445,  1034,   954,
     954,   839, -1445,   763,   954,   612, 13158,   545,   587,  1101,
   -1445, -1445,   847,   535, -1445, -1445, -1445, -1445, -1445, -1445,
   -1445, -1445, -1445, -1445, -1445,   116,   394,   910,   576,  7856,
   -1445, 13158,  1039,   837,   954, -1445, -1445, -1445, -1445,   985,
   13158, -1445, 13158, -1445,  1019,  1013, 12580,  1023,  7856,   -42,
     992,    32,    53,   895, -1445, -1445,   643,   -14,  1034, 12580,
    1031,  1055,   967,   957,  1020,   954,   995,  1024,  1056,   954,
    7856,   -46, -1445, -1445, -1445,  1005, -1445, -1445, -1445, -1445,
    1042,  7856,  7856,  1015, -1445,  1061,  1063,  4232, -1445,   982,
     983,  1016, 13158, -1445, 13158, -1445,  7856,  1022,   981,  7856,
     351,   354,   359,  1132, -1445,   451, -1445,   203, -1445, -1445,
    1142, -1445,   606,  7856,  7856,  7856,   682,  7856,  7856,  7856,
    7856,  7856,  7856,  1057,  7856,  7856, -1445,  5742,  1018,  1025,
    1026,  1027,   776,   620,   934, -1445,   421, -1445,   117,   150,
      33,  5440,  5440,  5440,  1096, -1445,  7856,   683,  1070, -1445,
   13158,  1072, -1445, -1445,  7856,    50,   625,   366, -1445,   899,
     311,   928,   929, -1445, -1445,   749, -1445,   918,   482,  1033,
    1035, 12869,  1036,  1037,  1038,  1040,  1043,  1045, -1445,   565,
   -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445,
   -1445, -1445, -1445, -1445,  1046, -1445, -1445, -1445,  7856, -1445,
   -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445,   671, -1445,
    1156,   716, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445,
   -1445,   902, -1445, -1445,  1165, -1445, -1445, -1445, -1445, -1445,
     544,  1167, -1445,   712, -1445, -1445, -1445,   855,   189,   870,
     295,   871,   874,   795, -1445,   565,  8460,   912,   897, -1445,
    1034,   394,   977,  1017,  4232,  1047,  1050,  1062,  1052,  1053,
   13158,    72, -1445, 13158, -1445,  7856,  1058,  7856,  1077,  7856,
      -4,  1065,  7856,  1066, -1445,  1091,  1092,  7856, 13158,   807,
    1136, -1445, -1445, -1445, -1445, -1445, -1445, 12580, -1445,  4232,
     954,  1110, -1445, -1445, -1445,   954,  1110, -1445,  7856,  1076,
    4232, 13158, -1445, -1445,  7856,  7856,   713, -1445,    -5,   717,
   -1445, 11713,   733, -1445,   738, -1445,  1048, -1445, -1445,  4232,
    1054,  1059, -1445,  7856, -1445, -1445,  1028,  1061,  1120, -1445,
    1089, -1445,   501, -1445, -1445,  1214, -1445, -1445,  4232, 13158,
   -1445,   640, -1445, -1445, -1445,  1064,   991,   997, -1445, -1445,
   -1445,   999,  1029, -1445, -1445, -1445, -1445, -1445,   988, 13158,
    1069, -1445, -1445,  7856,  7856,  7856,  3930,  5742,  9668,   934,
   -1445,  9668, -1445,  1088,   305, -1445, -1445, -1445,  1070, -1445,
     954, -1445,   803, -1445,   318,  1121, -1445,  7856,  1122,  1009,
     392,  1071, -1445,    50,   998, -1445, -1445,   -60, -1445,  -117,
      41,  1001,    50,  -117,  8158, -1445,    66, -1445, -1445, -1445,
   -1445, -1445, -1445,    50,  1098,   975,   841,    41, -1445, -1445,
     974,  1169, -1445, -1445, -1445, 10846,  1073,  1075,  1081,  1082,
    1086,  1093,  1094,  1095, -1445, -1445, -1445, -1445, -1445, -1445,
   -1445, -1445, -1445, -1445, -1445, -1445,  1221,   313,  1233,   313,
    1006,  1168, -1445,  1113, 13158,  1032, -1445, -1445,  8460, -1445,
    1100, -1445, -1445, -1445, -1445, -1445, -1445,  7856,  1140, -1445,
   -1445,  7856, -1445,   505, -1445,  7856,  1143,  7856, -1445,  7856,
   13158, 13158, -1445,   656, -1445,  7856, -1445,  1163,  1170,  1196,
     954,  1110, -1445,  7856,  1111, -1445, -1445, -1445,  1114, -1445,
      37,  7856,  4232,  1115,    62, -1445, 13158,  1117, 12002,    18,
   -1445, 12291,  1118, -1445, -1445,  1123, -1445, -1445, -1445,  7856,
     743,  1132, 13158,   759, -1445,  1124,  1132, 13158, -1445, -1445,
    7856,  7856,  7856,  7856,  7856, -1445,  7856,   383,   459,   466,
     480, -1445, -1445, -1445, -1445, -1445,  1121, -1445, -1445, -1445,
     954, -1445, -1445, -1445, -1445, -1445,  1127,  8158, -1445, -1445,
   -1445, -1445, -1445,    86,  8158,  8158,   433, -1445,   928, -1445,
     200, -1445,   929,    50,  1144, -1445, -1445,  1051, -1445, -1445,
   -1445, -1445,  1204,  1119, -1445,   473, -1445, -1445, -1445, -1445,
   -1445, -1445, -1445, -1445, -1445,   413,   413, -1445,   313, -1445,
   -1445,   506, -1445,  1282,    41,  1216,  1128,  8460,   -77,  1049,
    1146, -1445, -1445,  7856, -1445,  7856,  1171, -1445,  7856, -1445,
   -1445, -1445,  1260, -1445, -1445,  5742,  7856,   954, -1445, -1445,
   -1445,  7856,  7856, -1445, -1445, -1445,  5742,  5742,  1224,  4232,
   13158,  1134, 13158,  7856, 13158,  1135,  5742, -1445,    64,   -11,
    1132, 13158, -1445,  1126,  1132, -1445, -1445, -1445, -1445, -1445,
   -1445,  1129,  1061,  1063,  7856, -1445, -1445, -1445, -1445,   669,
    8158,  8158,   627,   596, -1445, -1445, -1445, -1445, -1445, -1445,
    7856, -1445, 12580, -1445, 12580,  1228, -1445, -1445, -1445,  1294,
   -1445, -1445, -1445,  1067,  1220, -1445, -1445,  1222, -1445,   721,
   13158,  1215,  1108, 13158,  8460, -1445, -1445,  7856, -1445,  1218,
   -1445, -1445,  1110, -1445, -1445, 12580, -1445, -1445,  1239,  7856,
    1151, -1445,  1244,  5742, -1445, 13158,   188,   302, -1445,  1145,
    1132, -1445,  1148,  5742,   744,   514,   627,   627,  8158,   520,
   -1445, -1445, 12580, -1445, -1445,  1216,  8460, -1445,  1121,  1068,
   13158,  1227,  1116,  1222, -1445, 13158,  1160, 12580,  4232, 12580,
    1162, -1445, -1445,  1248,   215, -1445, -1445, -1445, -1445,  1166,
     554, -1445, -1445, -1445,  1154, -1445,  1235, -1445,   627, -1445,
   -1445, -1445, -1445, -1445,  7856,  1074, 13158,  1236, -1445,  4232,
    1172, -1445, -1445,  1173,  7856, -1445, -1445, -1445, -1445, -1445,
   -1445, -1445, 13158, -1445,  1078,  1079, 13158, -1445, -1445,  7856,
    5742,  1174,  1080,  7856,  1083,  5742,  8460, -1445,  8460, -1445,
    1157,  1085, 13158,  1133,  1238, 13158,  1084,  8460, -1445
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       159,   440,   441,   442,   162,   162,   162,   776,   979,   116,
     118,   593,   868,   877,   817,   781,   779,   761,   869,   872,
     824,   785,   762,   763,   816,   878,   765,   875,   846,   826,
     801,   821,   822,   873,   870,   820,   767,   876,   768,   769,
     917,   929,   916,   818,   837,   831,   770,   819,   772,   771,
     918,   855,   856,   823,   798,   939,   940,   941,   942,   943,
     944,   945,   946,   947,   948,   949,   963,   970,   845,   841,
     832,   812,   760,     0,   840,   848,   857,   964,   836,   463,
     813,   814,   871,   965,   971,   833,   850,     0,   469,   429,
     465,   843,   778,   834,   835,   864,   838,   854,   863,   969,
     972,   784,   825,   866,   464,   853,   859,   764,     0,     0,
       0,     0,   377,   851,   862,   867,   865,   844,   830,   919,
     828,   829,   966,     0,   376,     0,   967,   973,   860,   815,
     839,   968,   407,     0,   439,   861,   842,   849,   858,   852,
     920,   806,   811,   810,   809,   808,   807,   773,   827,     0,
     777,   874,   799,   908,   907,   909,   783,   782,   802,   914,
     766,   906,   911,   912,   903,   805,   847,   905,   915,   913,
     904,   803,   910,   924,   925,   922,   923,   921,   774,   926,
     927,   928,   894,   893,   880,   797,   790,   887,   883,   800,
     796,   895,   896,   786,   787,   780,   789,   892,   891,   888,
     884,   901,   902,   900,   890,   886,   879,   788,   899,   898,
     792,   794,   793,   885,   889,   881,   795,   882,   791,   897,
     950,   951,   952,   953,   954,   955,   931,   932,   930,   936,
     937,   938,   933,   934,   935,   804,   956,   957,   958,   959,
     960,   961,   962,   978,   975,   977,   974,   976,   159,     0,
       2,   159,     5,     7,    19,     0,    24,    27,    32,    33,
      34,    35,    36,    37,    38,    28,    54,    55,    29,    30,
       0,    72,    75,    76,    31,    77,    78,     0,   114,    79,
      80,    81,    82,    14,   156,   157,   158,   165,   167,   459,
     168,     0,   169,   170,   171,   172,   173,   174,   175,   178,
     163,   204,   211,   206,   233,   239,     0,   231,   232,   213,
     207,   177,   208,   176,   209,   212,   330,   332,   334,   344,
     348,   350,   352,   355,   360,   363,   366,   368,   370,   372,
       0,   374,   380,   382,     0,   398,   381,   403,   406,   408,
     411,   413,     0,   418,   415,     0,   426,   436,   438,   412,
     443,   450,   461,   451,   452,   453,   456,   457,   454,   455,
     476,   478,   479,   480,   477,   525,   526,   527,   528,   529,
     530,   435,   567,   559,   566,   565,   564,   561,   563,   560,
     562,   462,   458,   594,   595,    39,   214,   215,   217,   216,
     218,   210,   460,   745,   437,   759,   775,   868,   877,   875,
     777,     0,   160,   161,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   122,   124,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   258,   259,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   431,   434,   421,     0,
       0,   761,   785,   763,   816,   878,   765,   826,   767,   837,
     770,   772,   771,   855,   963,   970,   760,   964,   814,   965,
     971,   838,   969,   972,   919,   966,   967,   973,   968,   920,
     914,   906,   912,   903,   803,   924,   925,   922,   774,   926,
     427,   437,   759,   419,     0,   185,   420,   423,   761,   762,
     763,   767,   768,   769,   770,   760,   766,   466,     0,   425,
     424,   180,     0,     0,   765,   772,   771,     0,   162,   746,
     926,     0,   211,     0,   467,     0,   492,     0,   430,   757,
       0,   758,   401,   402,     0,   433,   432,   422,   405,     0,
       0,   521,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,     1,
       6,     8,     0,     0,     0,     0,     0,   159,   159,   159,
     159,     0,   115,   166,   164,     0,   183,     0,   192,     0,
       0,     0,     0,     0,     0,     0,     0,   197,   219,   238,
     234,   240,   235,   237,   236,     0,     0,     0,   391,     0,
       0,   389,     0,   339,     0,   390,   383,   388,   387,   386,
     385,   384,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   379,   378,   375,     0,   399,   404,     0,     0,     0,
     414,   447,   417,   416,   428,     0,   444,     0,     0,   532,
     534,   538,     0,   120,     0,   756,    43,    40,    41,    44,
      45,     0,     0,     0,     0,    46,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   604,   605,   606,
       0,    99,   138,     0,     0,   108,     0,     0,     0,     0,
     123,     0,     0,     0,   573,     0,     0,     0,   569,     0,
       0,     0,   583,     0,     0,   221,   222,   241,   242,     0,
       0,     0,     0,   130,     0,   134,   162,   597,     0,    56,
       0,    65,     0,     0,     0,    57,     0,     0,     0,     0,
       0,     0,   574,     0,     0,     0,     0,   303,     0,     0,
     572,     0,     0,     0,   591,     0,     0,     0,     0,   577,
       0,     0,   187,     0,     0,   181,   179,     0,     0,     0,
     466,     0,   747,     0,   468,   493,   492,   489,     0,     0,
     523,   522,   400,     0,   520,     0,   617,   618,   568,     0,
       0,     0,     0,     0,     0,   623,     0,   195,   196,     0,
       0,     0,     0,     0,   200,   201,    20,     0,    21,     0,
       4,    25,     0,    11,    26,     0,    15,   868,    73,    12,
      74,    16,   186,   184,   205,     0,     0,     0,     0,   198,
     220,   276,   331,   333,   337,   343,   342,   341,     0,   338,
     335,   336,     0,   349,   351,   354,   353,   357,   358,   359,
     356,   361,   362,   365,   364,     0,     0,     0,     0,   396,
       0,   409,   410,     0,   448,   445,   474,     0,   596,   472,
       0,     0,   117,   119,     0,     0,     0,    98,     0,    88,
      90,    91,    92,    93,    95,    96,    97,    89,    94,    84,
      85,     0,     0,   104,     0,   100,   102,   103,   110,     0,
       0,    83,    42,     0,     0,     0,     0,     0,     0,     0,
     695,   700,     0,     0,   696,   730,   683,   685,   686,   687,
     689,   691,   690,   688,   692,     0,     0,     0,     0,     0,
     107,     0,   140,     0,     0,   537,   531,   570,   571,     0,
       0,   587,     0,   584,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   223,   224,     0,   229,   136,     0,
       0,   131,     0,     0,     0,     0,     0,     0,    58,     0,
       0,     0,   257,   263,   260,     0,   576,   575,   582,   590,
       0,     0,     0,     0,   536,     0,     0,     0,   392,     0,
       0,     0,     0,   580,     0,   578,     0,   188,     0,     0,
       0,     0,     0,   492,   490,     0,   481,     0,   470,   471,
       0,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   193,     0,   765,   772,
     771,   926,     0,     0,     0,   631,     0,   202,     0,     0,
       0,   159,   159,   159,     0,   230,     0,   287,   283,   285,
       0,   277,   278,   340,     0,     0,     0,     0,   661,   346,
     634,   638,   640,   642,   644,   647,   654,   655,   663,   878,
     764,     0,   773,   978,   975,   977,   974,   976,   367,   543,
     549,   550,   553,   598,   599,   554,   555,   748,   749,   750,
     751,   558,   369,   371,   540,   373,   397,   449,     0,   446,
     473,   121,    52,    53,    50,    51,   127,   126,     0,    86,
       0,     0,   105,   106,   111,    70,    71,    48,    49,    69,
     701,     0,   704,   731,     0,   694,   693,   698,   697,   729,
       0,     0,   706,     0,   702,   705,   684,     0,     0,     0,
       0,     0,     0,     0,   139,   142,     0,     0,     0,   109,
     112,     0,     0,     0,   162,     0,     0,   591,     0,     0,
       0,     0,   542,     0,   244,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   225,     0,     0,     0,     0,   270,
       0,   267,   272,   228,   137,   132,   135,     0,   182,     0,
       0,    67,    61,    64,    63,     0,    59,   261,     0,     0,
     162,     0,   301,   305,     0,     0,     0,   308,     0,     0,
     314,     0,     0,   321,     0,   325,     0,   394,   393,   162,
       0,     0,   189,     0,   191,   302,     0,     0,     0,   493,
       0,   482,     0,   516,   513,     0,   517,   518,     0,     0,
     512,     0,   487,   515,   514,     0,     0,     0,   610,   611,
     607,     0,     0,   615,   616,   612,   621,   619,     0,     0,
       0,   625,   194,     0,     0,     0,     0,     0,     0,   626,
     627,     0,   203,    22,     0,    13,    17,    18,   284,   296,
       0,   297,     0,   288,   289,   290,   291,     0,   280,     0,
       0,     0,   645,   658,     0,   345,   347,     0,   677,     0,
       0,     0,     0,     0,     0,   633,   635,   636,   672,   673,
     674,   676,   675,     0,     0,   649,   648,     0,   652,   656,
     670,   668,   667,   660,   664,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   546,   548,   547,   544,   541,   475,
     129,   128,    87,   101,   718,   699,     0,   723,     0,   723,
     712,   707,   143,     0,     0,     0,   113,   141,     0,    23,
       0,   588,   589,   592,   585,   586,   243,     0,     0,   256,
     248,     0,   252,     0,   246,     0,     0,     0,   265,     0,
       0,     0,   227,   268,   271,     0,   133,     0,     0,    66,
       0,    60,   262,     0,     0,   304,   306,   311,     0,   309,
       0,     0,     0,     0,     0,   315,     0,     0,     0,     0,
     322,     0,     0,   326,   395,     0,   581,   579,   190,     0,
       0,   492,     0,     0,   524,     0,   492,     0,   488,    10,
       0,     0,     0,     0,     0,   624,     0,     0,     0,     0,
       0,   628,   632,   300,   298,   299,   292,   293,   294,   286,
       0,   281,   279,   662,   653,   659,     0,     0,   732,   733,
     743,   742,   741,     0,     0,     0,     0,   734,   639,   740,
       0,   637,   641,     0,     0,   646,   650,     0,   671,   666,
     669,   665,     0,     0,   556,     0,   551,   603,   545,   552,
     754,   752,   753,   755,   719,     0,     0,   717,   724,   725,
     721,     0,   716,     0,   714,     0,     0,     0,     0,     0,
       0,   533,   245,     0,   254,     0,     0,   250,     0,   253,
     266,   274,   275,   269,   226,     0,     0,     0,    62,   264,
     539,     0,     0,   312,   316,   310,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   535,     0,     0,
     492,     0,   519,     0,   492,   608,   609,   613,   614,   620,
     622,     0,     0,     0,     0,   629,   295,   282,   657,   744,
       0,     0,   736,     0,   682,   681,   680,   679,   678,   643,
       0,   735,     0,   600,     0,     0,   728,   727,   726,     0,
     720,   713,   711,     0,   708,   709,   703,   144,   146,   148,
       0,     0,     0,     0,     0,   249,   247,     0,   255,     0,
     199,   329,    68,   307,   313,     0,   327,   323,     0,     0,
       0,   317,     0,     0,   319,     0,   502,   496,   491,     0,
     492,   483,     0,     0,     0,     0,   738,   737,     0,     0,
     601,   557,     0,   722,   715,     0,     0,   150,   149,     0,
       0,     0,     0,   145,   251,     0,     0,     0,     0,     0,
       0,   510,   504,     0,   503,   505,   511,   508,   498,     0,
     497,   499,   509,   485,     0,   484,     0,   630,   739,   651,
     602,   710,   147,   151,     0,     0,     0,     0,   273,     0,
       0,   320,   318,     0,     0,   495,   506,   507,   494,   500,
     501,   486,     0,   152,     0,     0,     0,   328,   324,     0,
       0,     0,     0,     0,     0,     0,     0,   154,     0,   153,
       0,     0,     0,     0,     0,     0,     0,     0,   155
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1445, -1445,  -222,  1125, -1445,  1112,  1130, -1445,  1107,  -535,
   -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445,
    -933, -1445, -1445, -1445, -1445,  -224,  -545, -1445,   673,  -180,
   -1445, -1445, -1445, -1445, -1445,   241,   461, -1445, -1445,     4,
    -190,   960, -1445,   941, -1445, -1445,  -613, -1445,   402, -1445,
     217, -1445,  -238,  -277, -1445,  -497, -1445,     5,    68,    61,
    -283,  -172, -1445,  -835, -1445, -1445,   223, -1445, -1445, -1445,
   -1445, -1445, -1445, -1445, -1445, -1445, -1445,   566,   -32,  1030,
       0, -1445, -1445, -1445, -1445,   416, -1445, -1445,  -288, -1445,
       8, -1445, -1445,   216,  -703,  -693, -1445, -1445,   641, -1445,
   -1445,    -2,   204, -1445, -1445, -1445,    90, -1445, -1445,   336,
      97, -1445, -1445,   101, -1256, -1445,   872,   186, -1445, -1445,
     182,  -958, -1445, -1445,   180, -1445, -1445, -1207, -1198, -1445,
     177, -1445, -1445,   789,   786, -1445,  -519, -1445, -1445,   770,
    -621,   233,  -620,   298,   301, -1445, -1445, -1445, -1445, -1445,
    1087, -1445, -1445, -1445, -1445,  -820,  -311, -1098, -1445,  -106,
   -1445, -1445, -1445, -1445, -1445, -1445, -1445,   -45,  -764, -1445,
   -1445,   523,   236, -1445,  -405, -1445, -1445, -1445, -1445, -1445,
   -1445, -1445,   739, -1445,  -982, -1445,   164, -1445,   623,  -761,
   -1445, -1445, -1445, -1445, -1445,  -272,  -264, -1142,  -904, -1445,
   -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445,   543,
    -729,  -716,   258,  -783, -1445,    70,  -803, -1445, -1445, -1445,
   -1445, -1445, -1445, -1445,   979,   986,  -267,   463,   304, -1445,
   -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445,
   -1445, -1445, -1445,   149, -1445, -1445,   140, -1445,   144, -1023,
   -1445, -1445, -1445,   113,   107,   -52,   367, -1445, -1445, -1445,
   -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445,
     118, -1445, -1445, -1445,   -44,   363,   508, -1445, -1445, -1445,
   -1445, -1445,   296, -1445, -1445, -1444, -1445, -1445, -1445,  -562,
   -1445,    81, -1445,   -67, -1445, -1445, -1445, -1445, -1293, -1445,
     132, -1445, -1445, -1445, -1445, -1445, -1445, -1445, -1445,  -361,
    -370,   561,   154, -1445
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   249,   819,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
    1201,   744,   267,   268,   269,   270,   271,   272,   899,   900,
     901,   273,   274,   275,   905,   906,   907,   276,   426,   277,
     278,   672,   279,   428,   429,   430,   443,   734,   735,   280,
    1154,   281,  1607,  1608,   282,   283,   284,   532,   285,   286,
     287,   288,   289,   737,   290,   291,   515,   292,   293,   294,
     295,   296,   297,   607,   298,   299,   814,   815,   300,   301,
     542,   303,   608,   441,   966,   967,   304,   609,   305,   611,
     543,   307,   727,   728,  1189,   450,   308,   451,   452,   731,
    1190,  1191,  1192,   612,   613,  1061,  1062,  1461,   614,  1058,
    1059,  1293,  1294,  1295,  1296,   309,   756,   757,   310,  1216,
    1217,  1410,   311,  1219,  1220,   312,   313,  1222,  1223,  1224,
    1225,   314,   315,   316,   317,   848,   318,  1305,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   632,   633,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   660,   661,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   877,   359,   360,   361,  1251,   786,   787,   788,
    1638,  1679,  1680,  1673,  1674,  1681,  1675,  1252,  1253,   362,
     363,  1254,   364,   365,   366,   367,   368,   369,   370,  1103,
     961,  1088,  1347,  1089,  1495,  1090,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   763,  1166,   381,   382,
     383,   384,  1092,  1093,  1094,  1095,   385,   386,   387,   388,
     389,   390,   804,   805,   391,  1279,  1280,  1575,  1046,  1069,
    1315,  1316,  1070,  1071,  1072,  1073,  1074,  1325,  1485,  1486,
    1075,  1328,  1076,  1466,  1077,  1078,  1333,  1334,  1491,  1489,
    1317,  1318,  1319,  1320,  1587,   701,   926,   927,   928,   929,
     930,   931,  1144,  1516,  1604,  1145,  1514,  1602,   932,  1359,
    1511,  1507,  1508,  1509,   933,   934,  1321,  1329,  1476,  1322,
    1472,  1306,   392,   393,  1096,  1097,  1098,  1099,  1100,  1202,
     550,   394,   395,   396
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       302,   673,   673,   593,   302,   302,   302,   577,   306,   401,
     404,   405,   306,   306,   306,   854,   427,   981,   610,   857,
     858,   859,   860,   655,  1420,  1015,   959,   558,   510,   993,
     585,  1430,  1067,   588,  1487,  1250,   960,  1218,  1457,  1458,
    1610,   963,  1301,  1007,   828,   830,  1206,   676,   590,  1045,
     696,  1117,   821,   824,     9,    10,   586,   955,  1363,     9,
      10,   711,  1091,  1091,   790,   403,   403,   403,  1178,   448,
     886,  1605,   402,   402,   402,   412,   586,   541,   545,    11,
     412,   560,  1636,   586,   753,   741,   745,   592,   586,   413,
     823,   826,   829,   831,  1411,  1208,   586,   586,   844,  1091,
     845,   846,   415,   847,  1175,   849,   675,   415,   302,  1438,
       9,    10,   416,   850,   851,   956,   306,   957,   586,  1121,
     593,   408,   409,   595,   410,   411,   597,   675,   957,   990,
     597,   412,   685,  1155,   956,  1552,  1411,  1473,  1580,   707,
     413,   414,  1385,   417,   418,  1054,  1611,   956,   716,  1470,
    1102,   654,   406,  1091,   990,  1468,  1471,  1112,   415,    79,
    1033,  1411,  1307,   416,   686,   717,  1091,   958,   957,   533,
     915,  1637,   916,    90,  1113,   125,   402,   407,  1179,  1124,
    1412,  1635,   691,   563,   692,   564,   992,   408,   409,   742,
     410,   411,  1469,  1671,   417,   418,   419,  1243,   104,  1182,
    1576,   964,  1064,  1553,   782,  1065,   596,   414,  1107,  1022,
     991,  1691,  1243,  1244,  1581,   917,   693,   462,  1377,  1026,
    1671,  1603,  1542,   449,  1243,   449,   125,   512,  1612,   449,
     791,   656,  1420,  1183,  1308,  1009,   743,   592,   965,  1194,
    1172,   512,   694,   420,   587,  1067,  1067,  1547,   302,  1553,
     593,   302,  1240,  1195,   594,   610,   306,   740,  1180,   306,
    1250,  1414,  1284,   561,   589,   512,  1176,   449,  1181,  1250,
    1520,   816,  1401,   828,   830,  1118,   818,   512,  1091,   512,
    1465,   821,   824,  1351,  1051,  1053,   302,  1034,  1209,   718,
     431,  1438,   449,   463,   306,  1474,  1475,   662,  1337,   597,
     664,   881,   421,   449,   695,  1245,  1283,  1066,   881,   420,
    1246,  1243,  1247,   708,     9,    10,  1309,  1310,   423,  1311,
    1672,   709,   839,   434,   597,  1246,   424,  1247,   950,  1063,
    1677,  1023,  1024,   912,   425,   952,  1313,  1246,   677,  1247,
    1248,  1027,  1028,   422,   435,   599,  1025,  1706,  1314,   600,
     691,   678,   692,  1657,   601,  1248,  1029,   637,  1155,   111,
     464,   465,   817,   822,   825,   918,  1644,  1248,   421,   423,
     974,   594,   602,   977,   582,   638,   123,   424,   919,   784,
     920,   882,   970,   978,   597,   425,  1016,   442,   883,   597,
     583,   921,   922,   923,  1091,   924,  1249,   925,   597,   591,
     597,   949,  1693,   302,   721,  1002,  1004,  1307,   951,   422,
     694,   306,   738,   597,   149,   953,  1020,   444,  1091,  1609,
     597,   750,   645,  1290,  1246,   732,  1247,   597,   761,   762,
     593,  1366,   302,  1147,   302,  1678,   646,   768,  1148,   716,
     306,    11,   306,   597,  1292,  1108,  1420,  1068,  1505,  1108,
     455,  1250,  1017,  1149,  1248,  1150,   717,   597,   302,   597,
     597,   985,   971,   302,  1151,   597,   306,  1584,  1378,   973,
     603,   306,   695,   604,  1585,  1021,  1111,   456,   995,  1308,
     996,  1396,   597,  1067,  1586,  1003,  1005,  1386,   605,   597,
    1001,  1152,  1067,   713,   733,   713,   512,  1018,   597,   512,
     712,   594,   715,  1067,  1019,  1417,   828,   830,   828,  1356,
    1243,  1244,  1506,   606,  1045,   789,  1609,  1452,  1303,   713,
     566,    79,   567,  1037,   713,  1109,   759,   793,   593,  1110,
     599,   765,  1091,   302,   600,    90,  1044,  1236,   302,   601,
    1237,   306,   125,   810,   812,  1238,   306,   432,  1125,  1126,
     433,   871,   872,  1129,  1285,  1286,  1287,   602,  1609,  1106,
     104,  1309,  1310,  1243,  1311,   597,   683,   512,  1358,  1571,
     512,  1312,   597,  1276,   512,  1463,   302,   512,   512,  1594,
    1241,  1313,  1677,  1163,   306,   512,   427,   302,   302,   302,
     302,   512,  1048,  1314,   512,   306,   306,   306,   306,   403,
    1052,   957,   512,  1245,  1622,   302,   402,   468,   512,   512,
     512,   512,  1599,   306,  1414,  1091,   512,  1153,  1091,  1494,
     597,   457,   870,  1246,   512,  1247,   597,   873,  1729,  1281,
    1730,  1141,  1574,   445,   511,   639,   460,   811,   469,  1738,
    1356,   470,   659,   446,   665,  1572,  1242,  1142,   527,  1243,
    1244,  1525,  1573,  1248,    11,   603,  1357,   111,   604,  1595,
    1068,  1068,   599,  1067,   640,   461,   600,   636,   512,   447,
    1559,   601,   546,   783,   123,  1563,  1246,   641,  1247,   956,
    1526,   594,   512,  1165,   551,  1168,   554,  1709,  1281,   602,
    1143,   512,  1600,  1480,  1432,   466,  1185,  1687,   606,  1358,
    1584,  1186,  1551,  1689,   637,  1555,  1248,  1585,  1344,  1185,
     438,   642,   149,   302,  1186,   439,   902,  1586,   956,  1119,
    1187,   306,   638,   467,   705,   512,   980,  1330,  1331,   706,
     514,  1119,  1676,  1682,    79,  1230,   302,  1231,   828,   957,
    1345,   972,  1245,   681,   306,  1010,  1011,  1012,    90,   812,
    1332,   528,   957,   637,  1272,   610,   655,  1346,   903,   682,
    1188,   440,  1246,   904,  1247,  1006,   302,   302,  1243,  1244,
    1676,   638,   679,   104,   306,   306,  1682,  1064,  1289,  1049,
    1065,   569,   513,  1114,   637,   680,   570,   603,  1290,  1091,
     604,  1091,  1248,  1648,  1116,   583,   111,   403,  1291,  1639,
    1115,   125,   638,  1642,   402,  1277,  1135,  1350,  1141,  1292,
     736,  1042,  1215,   123,   832,   956,  1215,  1136,   833,  1043,
     657,   658,  1091,   736,  1142,  1408,  1290,   713,   713,  1413,
     606,   427,  1418,  1437,   999,  1000,  1256,  1421,  1257,  1399,
     516,   888,  1418,  1418,   512,  1419,   517,  1579,  1137,  1091,
    1422,   149,   903,  1582,  1583,  1558,  1686,   904,   512,  1138,
    1185,  1245,   512,   512,  1091,  1186,  1091,   663,   643,   577,
     855,   856,   666,  1157,  1282,   529,  1650,   644,  1651,  1684,
    1658,  1246,  1158,  1247,   512,   530,   512,  1130,  1131,  1132,
    1127,  1128,   436,  1133,   512,   437,   874,   512,  1068,   874,
     547,   512,   874,   511,   548,   453,   511,  1068,   454,  1666,
     458,  1248,  1261,   459,  1262,   111,  1397,   555,  1068,   889,
     890,   891,   892,   893,   894,   895,   896,   897,   898,  1453,
    1454,  1455,   123,   697,   698,   699,  1690,  1104,  1104,   512,
     556,   861,   862,  1596,  1597,   557,   863,   864,   562,   559,
     565,  1700,  1561,  1703,   568,   571,   575,   572,   576,  1646,
    1647,   573,   579,   574,   597,   598,   615,   512,   616,   635,
     149,   634,   647,   648,   684,   649,   659,   688,   650,   667,
     668,   551,   669,   675,   702,   703,   687,   670,   671,   512,
     690,   689,   551,   700,   839,   704,   714,   302,   724,   730,
     736,   729,   725,   739,   747,   306,   748,   749,   726,   746,
     433,   766,   760,   767,   775,   551,   754,   755,   758,   512,
     512,   512,   512,   764,   437,   454,   459,  1688,   785,   470,
     773,   771,  1300,   777,   778,   779,   781,  1042,   792,  1538,
     794,   795,   798,   803,   820,  1043,   807,   835,   836,   808,
     852,   302,   302,   302,   427,   813,   512,   837,   713,   306,
     306,   306,   838,   865,   866,  1226,   867,   868,   878,   884,
     512,   617,   885,   887,   909,   772,   910,   913,  1068,   618,
     619,   914,   620,   936,   937,   935,   939,   944,   941,   758,
     621,   945,   946,   947,   622,   512,   623,   948,   780,  1577,
     954,   624,   969,   975,   512,   976,   512,   979,  1030,   986,
     512,   987,   988,   989,   994,   998,   997,  1032,   625,  1035,
    1031,  1050,  1036,   512,  1056,   904,  1060,  1120,   956,  1544,
    1139,  1140,   806,  1161,  1162,  1156,  1170,  1164,  1177,  1171,
    1173,   626,   627,   628,   629,   630,   631,  1184,   732,  1197,
    1198,  1200,  1205,  1199,  1203,  1204,   512,  1210,   512,  1211,
    1215,  1214,  1221,  1233,   302,  1227,  1228,  1239,  1229,  1370,
    1234,  1255,   306,  1273,  1269,   693,  1297,  1278,  1299,  1276,
    1274,  1275,  1304,  1327,  1323,    11,  1354,  1324,  1335,  1348,
    1336,  1338,  1339,  1340,  1355,  1341,  1360,  1364,  1342,   302,
    1343,  1365,  1368,  1383,  1381,  1373,  1369,   306,  1390,  1391,
     302,  1387,  1389,  1395,   512,  1404,  1400,  1403,   306,  1418,
    1431,  1434,  1440,  1444,  1429,   403,  1290,  1460,  1441,   302,
    1442,  1424,   402,  1371,  1425,   512,  1372,   306,  1374,  1375,
    1426,  1447,  1448,  1449,  1483,  1427,  1467,  1490,   302,  1477,
    1504,   908,  1620,  1439,  1446,  1484,   306,  1464,  1488,  1496,
    1443,  1497,  1510,  1624,  1544,   938,  1626,  1498,  1499,   942,
     943,   403,  1500,  1634,  1515,  1513,  1042,  1042,   402,  1501,
    1502,  1503,  1517,  1521,  1043,  1043,  1523,  1519,  1535,  1528,
     403,   962,  1537,   968,  1540,  1536,  1590,   402,  1592,  1541,
    1546,   551,  1549,  1556,   551,  1593,  1557,  1562,   982,   713,
    1578,  1601,  1141,  1619,  1606,  1614,  1435,  1617,  1625,  1629,
    1633,  1641,  1652,  1653,   512,  1643,  1655,   512,  1656,  1591,
    1654,  1661,  1660,  1667,  1613,  1665,  1668,   811,  1669,  1697,
    1683,  1705,   512,  1685,  1696,  1699,  1013,  1704,  1708,  1711,
    1626,   512,  1712,  1716,  1731,  1735,  1734,  1719,  1720,  1725,
    1397,   584,  1353,   580,  1122,   512,   911,   674,   710,  1722,
    1732,  1694,  1196,   578,   511,   512,  1663,  1714,  1367,  1692,
    1047,   581,  1723,  1193,  1726,  1701,  1376,  1728,  1737,  1462,
     984,  1533,  1288,  1394,  1459,  1456,  1055,  1405,  1409,  1415,
     774,  1423,   843,   512,   842,   853,  1433,   880,  1710,  1014,
    1707,  1105,   302,  1362,   719,  1169,  1717,   653,  1445,  1451,
     306,   720,  1450,   512,  1352,  1478,  1101,  1101,  1101,  1101,
    1482,  1589,   512,  1302,  1481,   512,  1588,  1717,  1326,  1361,
    1512,  1598,  1701,  1146,     0,  1479,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1101,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1134,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   512,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1160,     0,     0,     0,     0,     0,     0,     0,
       0,  1167,     0,  1167,     0,     0,     0,  1101,   512,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1101,     0,     0,     0,     0,  1042,     0,     0,     0,     0,
       0,     0,  1645,  1043,   512,   512,  1042,  1042,     0,   302,
       0,     0,     0,     0,  1043,  1043,  1042,   306,  1649,     0,
       0,     0,     0,   764,  1043,   764,     0,     0,     0,     0,
     512,     0,   512,     0,     0,   512,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   512,     0,     0,     0,
       0,   512,     0,   796,   797,     0,   799,   800,   801,   802,
       0,     0,     0,     0,   809,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1298,     0,     0,     0,     0,     0,   834,     0,     0,
       0,     0,     0,  1042,     0,   840,   841,     0,     0,     0,
       0,  1043,  1101,  1042,     0,     0,     0,     0,     0,     0,
       0,  1043,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   302,     0,
       0,     0,     0,     0,     0,     0,   306,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   876,     0,     0,   876,   302,
       0,     0,     0,     0,   512,     0,   512,   306,   512,     0,
       0,     0,     0,     0,     0,   512,     0,     0,     0,     0,
    1042,     0,     0,     0,     0,  1042,     0,     0,  1043,     0,
       0,   729,     0,  1043,  1379,     0,   940,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   512,     0,   512,  1393,
       0,     0,     0,     0,     0,     0,     0,     0,  1101,     0,
       0,     0,     0,     0,   512,     0,     0,   512,     0,     0,
       0,     0,   758,     0,     0,     0,     0,     0,   983,   512,
       0,     0,  1101,     0,     0,     0,     0,     0,     0,   512,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1008,     0,     0,   512,     0,     0,     0,
    1436,     0,     0,   840,   512,     0,     0,     0,     0,   512,
       0,   512,     0,   512,     0,     0,     0,     0,     0,     0,
     806,     0,     0,     0,     0,     0,     0,     0,     0,   511,
       0,     0,   511,     0,     0,     0,     0,     0,     0,     0,
     512,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   512,  1057,     0,     0,
     512,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   512,     0,     0,   512,
       0,     0,     0,     0,     0,     0,  1101,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1518,     0,     0,     0,     0,
       0,     0,     0,     0,  1123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1531,  1532,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1159,
       0,     0,     0,     0,     0,     0,     0,  1548,     0,  1101,
       0,     0,  1101,     0,     0,     0,     0,     0,  1174,     0,
       0,     0,     0,  1560,     0,     0,     0,     0,  1564,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1207,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1212,  1213,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1232,     0,     0,  1235,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1258,  1259,  1260,     0,  1263,  1264,  1265,
    1266,  1267,  1268,     0,  1270,  1271,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1057,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1628,     0,  1630,     0,  1632,     0,     0,     0,     0,
       0,     0,  1640,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1349,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1101,     0,  1101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1659,     0,     0,  1662,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1101,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1670,     0,     0,     0,
       0,     0,     0,     0,     0,  1380,     0,  1382,     0,  1384,
       0,     0,  1388,  1101,     0,     0,     0,  1392,     0,     0,
       0,  1695,     0,     0,     0,     0,  1698,     0,  1101,  1398,
    1101,     0,     0,     0,     0,     0,     0,     0,  1402,     0,
       0,     0,     0,     0,  1406,  1407,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1715,     0,     0,
       0,     0,     0,  1428,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1721,     0,     0,     0,  1724,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1733,     0,     0,  1736,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1057,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1522,     0,     0,
       0,  1524,     0,     0,     0,  1527,     0,  1529,     0,  1530,
       0,     0,     0,     0,     0,  1534,     0,     0,     0,     0,
       0,     0,     0,  1539,     0,     0,     0,     0,     0,     0,
       0,  1543,  1545,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1398,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1565,  1566,  1567,  1568,  1569,     0,  1570,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
     244,   245,   246,   247,   248,     1,     2,     0,     0,     0,
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
     125,     0,     0,   126,   127,   128,     0,   531,     0,   129,
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
     241,   242,   243,   244,   245,   246,   247,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,     0,     0,     0,   397,
     398,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,   399,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,    48,    49,
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
       0,   124,   125,     0,     0,   126,   127,   128,     0,   776,
       0,   129,     0,   130,   131,     0,   132,   133,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   400,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,   397,   398,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,  1038,   399,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
    1039,  1040,    50,    51,    52,    53,    54,    55,    56,    57,
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
       0,   776,     0,   129,     0,   130,   131,     0,   132,   133,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   400,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
    1041,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
       0,     0,     0,   397,   398,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,  1038,   399,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,  1039,  1040,    50,    51,    52,    53,    54,    55,
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
     127,   128,     0,   531,     0,   129,     0,   130,   131,     0,
     132,   133,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   400,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,  1041,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,     0,     0,     0,   397,   398,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   399,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,    48,    49,    50,    51,    52,    53,
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
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,    12,    13,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,     0,    32,
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
     125,     0,     0,   126,   127,   128,     0,     0,     0,   129,
       0,   130,   131,     0,   132,   133,   134,     0,   135,     0,
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
     241,   242,   243,   244,   245,   246,   247,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,     0,     0,     0,    12,
      13,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,    48,    49,
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
       0,   124,   125,     0,     0,   126,   127,   128,     0,     0,
       0,   129,     0,   130,   131,     0,   132,   133,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   400,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,    12,   398,     0,    14,    15,    16,    17,    18,    19,
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
       0,   400,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
       0,     0,     0,   827,   398,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,   399,
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
     245,   246,   247,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,     0,     0,     0,   397,   398,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    1038,   399,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,  1039,  1040,    50,    51,    52,    53,
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
     175,   176,   177,   178,  1041,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   397,   398,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   534,   399,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   535,   536,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,    74,    75,    76,     0,     0,    77,    78,
       0,     0,     0,    79,    80,   488,    82,    83,    84,    85,
      86,   537,    88,    89,     0,     0,     0,    90,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,    96,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   538,   109,     0,   110,
     111,   112,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,     0,   123,     0,   124,
     125,     0,     0,   126,   127,   128,     0,     0,   539,   129,
       0,   130,   131,     0,   132,   133,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   400,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     505,   506,   507,   176,   177,   508,   540,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     0,     0,     0,    11,     0,     0,     0,   397,
     398,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   534,   399,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,   535,   536,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,   488,    82,    83,
      84,    85,    86,   537,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
      96,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   538,   109,
       0,   110,   111,   112,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,     0,   123,
       0,   124,   125,     0,     0,   126,   127,   128,     0,     0,
       0,   129,   544,   130,   131,     0,   132,   133,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   400,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   505,   506,   507,   176,   177,   508,   540,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   397,   398,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   534,   399,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     535,   536,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,    74,    75,    76,
       0,     0,    77,    78,     0,     0,     0,    79,    80,   488,
      82,    83,    84,    85,    86,   537,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,    96,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     538,   109,     0,   110,   111,   112,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,     0,   124,   125,     0,     0,   126,   127,   128,
       0,   869,     0,   129,     0,   130,   131,     0,   132,   133,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   400,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   505,   506,   507,   176,   177,   508,
     540,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     0,     0,     0,    11,
       0,     0,     0,   397,   398,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   534,   399,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,   535,   536,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,    74,
      75,    76,     0,     0,    77,    78,     0,     0,     0,    79,
      80,   488,    82,    83,    84,    85,    86,   537,    88,    89,
       0,     0,     0,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,    96,    97,    98,    99,   100,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   538,   109,     0,   110,   111,   112,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,     0,   123,     0,   124,   125,     0,     0,   126,
     127,   128,     0,     0,     0,   129,   875,   130,   131,     0,
     132,   133,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   400,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   505,   506,   507,   176,
     177,   508,   540,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   397,   398,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     534,   399,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,   535,   536,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,    74,    75,    76,     0,     0,    77,    78,     0,     0,
       0,    79,    80,   488,    82,    83,    84,    85,    86,   537,
      88,    89,     0,     0,     0,    90,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,    96,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   538,   109,     0,   110,   111,   112,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,     0,   123,     0,   124,   125,     0,
       0,   126,   127,   128,     0,     0,     0,   129,   879,   130,
     131,     0,   132,   133,   134,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,   149,     0,   400,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   505,   506,
     507,   176,   177,   508,   540,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   397,   398,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     474,    25,   476,   399,    28,   477,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,   479,     0,    45,    46,    47,   481,   482,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,    74,    75,    76,     0,     0,    77,    78,
       0,     0,     0,    79,    80,   488,    82,    83,    84,    85,
      86,   537,    88,    89,     0,     0,     0,    90,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   491,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   538,   109,     0,   110,
     111,   651,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,     0,   123,     0,   652,
     125,     0,     0,   126,   127,   128,     0,     0,     0,   129,
       0,   130,   131,     0,   132,   133,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   400,   151,   152,
     153,   154,   155,   156,   157,   158,   500,   160,   501,   162,
     502,   503,   165,   166,   167,   168,   169,   170,   504,   172,
     505,   506,   507,   176,   177,   508,   509,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     0,     0,     0,    11,     0,     0,     0,   397,
     398,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   534,   399,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,   535,   536,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,   488,    82,    83,
      84,    85,    86,   537,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
      96,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   538,   109,
       0,   110,   111,   112,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,     0,   123,
       0,   124,   125,     0,     0,   126,   127,   128,     0,     0,
       0,   129,     0,   130,   131,     0,   132,   133,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   400,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   505,   506,   507,   176,   177,   508,   540,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,     1,
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
      82,    83,    84,    85,    86,   537,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   491,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     538,   109,     0,   110,   111,   112,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,     0,   124,   125,     0,     0,   126,   127,   128,
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
     247,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     0,     0,     0,    11,
       0,     0,     0,   397,   398,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   474,    25,   476,   399,
      28,   477,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,   479,     0,    45,
      46,    47,   481,   482,    50,   483,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,    74,
      75,    76,     0,     0,    77,    78,     0,     0,     0,    79,
      80,   488,    82,    83,    84,    85,    86,   537,    88,    89,
       0,     0,     0,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   491,    97,    98,    99,   100,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   538,   109,     0,   110,   111,     0,   113,   114,
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
     245,   246,   247,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   397,   398,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   474,    25,
     476,   399,    28,   477,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,   479,
       0,    45,    46,    47,   481,   482,    50,   483,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,    74,    75,    76,     0,     0,    77,    78,     0,     0,
       0,    79,    80,   488,    82,    83,    84,    85,    86,   537,
      88,    89,     0,     0,     0,    90,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   491,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   538,   109,     0,   110,   111,     0,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,     0,   123,     0,     0,     0,     0,
       0,   126,   127,   128,     0,     0,     0,   129,     0,   130,
     131,     0,     0,     0,   134,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,   149,     0,   400,   151,   152,   153,   154,
     155,   156,   157,   158,   500,   160,   501,   162,   502,   503,
     165,   166,   167,   168,   169,   170,   504,   172,   505,   506,
     507,   176,   177,   508,   509,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   397,   398,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     474,    25,   476,   399,    28,   477,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,   479,     0,    45,    46,    47,   481,   482,    50,   483,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,    74,    75,    76,     0,     0,    77,    78,
       0,     0,     0,    79,    80,   488,    82,    83,    84,    85,
      86,   537,    88,    89,     0,     0,     0,    90,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   491,     0,
      98,    99,   100,     0,     0,     0,     0,     0,     0,   101,
     102,   103,   104,     0,   106,   107,   538,   109,     0,   110,
     111,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,     0,   123,     0,     0,
       0,     0,     0,   126,   127,   128,     0,     0,     0,   129,
       0,   130,   131,     0,     0,     0,   134,     0,   135,     0,
     136,     0,   138,     0,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   400,   151,   152,
     153,   154,   155,   156,   157,   158,   500,   160,   501,   162,
     502,   503,   165,   166,   167,   168,   169,   170,   504,   172,
     505,   506,   507,   176,   177,   508,   509,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     0,     0,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,   397,
     398,     0,    14,    15,    16,   471,    18,    19,    20,   472,
      22,   473,   474,   475,   476,   399,    28,   477,    30,    31,
       0,    32,    33,    34,    35,   478,    37,    38,    39,    40,
      41,    42,    43,   479,     0,    45,   480,    47,   481,   482,
      50,   483,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   484,   485,    68,     0,
      69,    70,    71,   486,     0,    74,    75,    76,     0,     0,
     487,    78,     0,     0,     0,     0,    80,   488,    82,   489,
     490,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     491,    97,    98,   492,   493,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,   107,     0,     0,
       0,     0,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   494,   120,   121,   495,     0,     0,
       0,     0,     0,     0,     0,   496,   497,   128,     0,     0,
       0,   129,     0,   130,   498,     0,     0,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   499,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,     0,     0,   400,
     151,   152,   153,   154,   155,   156,   157,   158,   500,   160,
     501,   162,   502,   503,   165,   166,   167,   168,   169,   170,
     504,   172,   505,   506,   507,   176,   177,   508,   509,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,   397,   398,     0,    14,    15,    16,   518,    18,    19,
      20,   472,   519,   520,   474,   475,   476,   399,    28,   477,
      30,    31,     0,    32,    33,    34,    35,   521,    37,   522,
     523,    40,    41,    42,    43,   479,     0,    45,   524,    47,
     481,   482,    50,   483,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,   484,   485,
      68,     0,    69,    70,    71,   525,     0,    74,    75,    76,
       0,     0,   487,    78,     0,     0,     0,     0,    80,   488,
      82,   489,   490,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   491,    97,    98,   492,   493,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,   107,
       0,     0,     0,     0,     0,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   494,   120,   121,   495,
       0,     0,     0,     0,     0,     0,     0,   496,   497,   128,
       0,     0,     0,   129,     0,   130,   498,     0,     0,     0,
     134,     0,   135,     0,   136,   137,   138,   139,   499,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,     0,
       0,   400,   151,   152,   153,   154,   155,   156,   157,   158,
     500,   526,   501,   162,   502,   503,   165,   166,   167,   168,
     169,   170,   504,   172,   505,   506,   507,   176,   177,   508,
     509,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   549,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     0,     0,     0,   751,     0,     0,     0,   397,   398,
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
     129,   752,   130,   498,     0,     0,     0,     0,     0,   135,
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
     240,   241,   242,   243,   244,   245,   246,   247,   549,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,   397,   398,     0,    14,    15,
      16,   518,    18,    19,    20,   472,   519,   520,   474,   475,
     476,   399,    28,   477,    30,    31,     0,    32,    33,    34,
      35,   521,    37,   522,   523,    40,    41,    42,    43,   479,
       0,    45,   524,    47,   481,   482,    50,   483,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   484,   485,    68,     0,    69,    70,    71,   525,
       0,    74,    75,    76,     0,     0,   487,    78,     0,     0,
       0,     0,    80,   488,    82,   489,   490,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   491,    97,    98,   492,
     493,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,   107,     0,     0,     0,     0,     0,     0,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     494,   120,   121,   495,     0,     0,     0,     0,     0,     0,
       0,   496,   497,   128,     0,     0,     0,   129,     0,   130,
     498,     0,     0,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   499,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,     0,     0,   400,   151,   152,   153,   154,
     155,   156,   157,   158,   500,   526,   501,   162,   502,   503,
     165,   166,   167,   168,   169,   170,   504,   172,   505,   506,
     507,   176,   177,   508,   509,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   552,   553,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
     397,   398,     0,    14,    15,    16,   518,    18,    19,    20,
     472,   519,   520,   474,   475,   476,   399,    28,   477,    30,
      31,     0,    32,    33,    34,    35,   521,    37,   522,   523,
      40,    41,    42,    43,   479,     0,    45,   524,    47,   481,
     482,    50,   483,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   484,   485,    68,
       0,    69,    70,    71,   525,     0,    74,    75,    76,     0,
       0,   487,    78,     0,     0,     0,     0,    80,   488,    82,
     489,   490,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   491,    97,    98,   492,   493,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   494,   120,   121,   495,     0,
       0,     0,     0,     0,     0,     0,   496,   497,   128,     0,
       0,     0,   129,     0,   130,   498,     0,     0,     0,     0,
       0,   135,     0,   136,   137,   138,   139,   499,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,     0,     0,
     400,   151,   152,   153,   154,   155,   156,   157,   158,   500,
     526,   501,   162,   502,   503,   165,   166,   167,   168,   169,
     170,   504,   172,   505,   506,   507,   176,   177,   508,   509,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
       7,     8,     0,     0,     0,     0,     0,     0,     0,   397,
     398,     0,    14,    15,    16,   471,    18,    19,    20,   472,
      22,   473,   474,  1079,   476,   399,    28,   477,    30,    31,
       0,    32,    33,    34,    35,   478,    37,    38,    39,    40,
      41,    42,    43,   479,     0,    45,   480,    47,   481,   482,
      50,   483,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   484,   485,    68,     0,
      69,    70,    71,   486,     0,    74,    75,    76,     0,     0,
     487,    78,     0,     0,     0,     0,    80,   488,    82,   489,
     490,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     491,    97,    98,   492,   493,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,  1080,     0,     0,
       0,  1081,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   494,   120,   121,   495,     0,     0,
       0,     0,     0,     0,     0,   496,   497,   128,     0,     0,
       0,   129,  1492,   130,   498,     0,     0,     0,  1493,     0,
     135,     0,   136,   137,   138,   139,   499,   141,   142,   143,
     144,   145,   146,     0,     0,  1082,   148,     0,     0,   400,
     151,   152,   153,   154,   155,   156,   157,   158,   500,   160,
     501,   162,   502,   503,   165,   166,   167,   168,   169,   170,
     504,   172,   505,   506,   507,   176,   177,   508,   509,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,  1083,  1084,  1085,  1086,  1087,     7,
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
     129,   722,   130,   498,     0,     0,     0,   723,     0,   135,
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
     240,   241,   242,   243,   244,   245,   246,   247,     7,     8,
       0,     0,     0,     0,     0,     0,     0,   397,   398,     0,
      14,    15,    16,   518,    18,    19,    20,   472,   519,   520,
     474,   475,   476,   399,    28,   477,    30,    31,     0,    32,
      33,    34,    35,   521,    37,   522,   523,    40,    41,    42,
      43,   479,     0,    45,   524,    47,   481,   482,    50,   483,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   484,   485,    68,     0,    69,    70,
      71,   525,     0,    74,    75,    76,     0,     0,   487,    78,
       0,     0,     0,     0,    80,   488,    82,   489,   490,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   491,    97,
      98,   492,   493,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,   107,     0,     0,     0,     0,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   494,   120,   121,   495,     0,     0,     0,     0,
       0,     0,     0,   496,   497,   128,     0,     0,     0,   129,
     769,   130,   498,     0,     0,     0,   770,     0,   135,     0,
     136,   137,   138,   139,   499,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,     0,     0,   400,   151,   152,
     153,   154,   155,   156,   157,   158,   500,   526,   501,   162,
     502,   503,   165,   166,   167,   168,   169,   170,   504,   172,
     505,   506,   507,   176,   177,   508,   509,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,     7,     8,     0,
       0,     0,     0,     0,     0,     0,   397,   398,     0,    14,
      15,    16,   471,    18,    19,    20,   472,    22,   473,   474,
    1079,   476,   399,    28,   477,    30,    31,     0,    32,    33,
      34,    35,   478,    37,    38,    39,    40,    41,    42,    43,
     479,     0,    45,   480,    47,   481,   482,    50,   483,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   484,   485,    68,     0,    69,    70,    71,
     486,     0,    74,    75,    76,     0,     0,   487,    78,     0,
       0,     0,     0,    80,   488,    82,   489,   490,    85,    86,
    1416,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   491,    97,    98,
     492,   493,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,  1080,     0,     0,     0,  1081,     0,
       0,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   494,   120,   121,   495,     0,     0,     0,     0,     0,
       0,     0,   496,   497,   128,     0,     0,     0,   129,     0,
     130,   498,     0,     0,     0,     0,     0,   135,     0,   136,
     137,   138,   139,   499,   141,   142,   143,   144,   145,   146,
       0,     0,  1082,   148,     0,     0,   400,   151,   152,   153,
     154,   155,   156,   157,   158,   500,   160,   501,   162,   502,
     503,   165,   166,   167,   168,   169,   170,   504,   172,   505,
     506,   507,   176,   177,   508,   509,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,  1083,  1084,  1085,  1086,  1087,     7,     8,     0,     0,
       0,     0,     0,     0,     0,   397,   398,     0,    14,    15,
      16,   471,    18,    19,    20,   472,    22,   473,   474,  1079,
     476,   399,    28,   477,    30,    31,     0,    32,    33,    34,
      35,   478,    37,    38,    39,    40,    41,    42,    43,   479,
       0,    45,   480,    47,   481,   482,    50,   483,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   484,   485,    68,     0,    69,    70,    71,   486,
       0,    74,    75,    76,     0,     0,   487,    78,     0,     0,
       0,     0,    80,   488,    82,   489,   490,    85,    86,  1550,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   491,    97,    98,   492,
     493,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,  1080,     0,     0,     0,  1081,     0,     0,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     494,   120,   121,   495,     0,     0,     0,     0,     0,     0,
       0,   496,   497,   128,     0,     0,     0,   129,     0,   130,
     498,     0,     0,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   499,   141,   142,   143,   144,   145,   146,     0,
       0,  1082,   148,     0,     0,   400,   151,   152,   153,   154,
     155,   156,   157,   158,   500,   160,   501,   162,   502,   503,
     165,   166,   167,   168,   169,   170,   504,   172,   505,   506,
     507,   176,   177,   508,   509,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
    1083,  1084,  1085,  1086,  1087,     7,     8,     0,     0,     0,
       0,     0,     0,     0,   397,   398,     0,    14,    15,    16,
     471,    18,    19,    20,   472,    22,   473,   474,  1079,   476,
     399,    28,   477,    30,    31,     0,    32,    33,    34,    35,
     478,    37,    38,    39,    40,    41,    42,    43,   479,     0,
      45,   480,    47,   481,   482,    50,   483,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   484,   485,    68,     0,    69,    70,    71,   486,     0,
      74,    75,    76,     0,     0,   487,    78,     0,     0,     0,
       0,    80,   488,    82,   489,   490,    85,    86,  1554,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   491,    97,    98,   492,   493,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,  1080,     0,     0,     0,  1081,     0,     0,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   494,
     120,   121,   495,     0,     0,     0,     0,     0,     0,     0,
     496,   497,   128,     0,     0,     0,   129,     0,   130,   498,
       0,     0,     0,     0,     0,   135,     0,   136,   137,   138,
     139,   499,   141,   142,   143,   144,   145,   146,     0,     0,
    1082,   148,     0,     0,   400,   151,   152,   153,   154,   155,
     156,   157,   158,   500,   160,   501,   162,   502,   503,   165,
     166,   167,   168,   169,   170,   504,   172,   505,   506,   507,
     176,   177,   508,   509,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,  1083,
    1084,  1085,  1086,  1087,     7,     8,     0,     0,     0,     0,
       0,     0,     0,   397,   398,     0,    14,    15,    16,   471,
      18,    19,    20,   472,    22,   473,   474,  1079,   476,   399,
      28,   477,    30,    31,     0,    32,    33,    34,    35,   478,
      37,    38,    39,    40,    41,    42,    43,   479,     0,    45,
     480,    47,   481,   482,    50,   483,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     484,   485,    68,     0,    69,    70,    71,   486,     0,    74,
      75,    76,     0,     0,   487,    78,     0,     0,     0,     0,
      80,   488,    82,   489,   490,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   491,    97,    98,   492,   493,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,  1080,     0,     0,     0,  1081,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   494,   120,
     121,   495,     0,     0,     0,     0,     0,     0,     0,   496,
     497,   128,     0,     0,     0,   129,     0,   130,   498,     0,
       0,     0,     0,     0,   135,     0,   136,   137,   138,   139,
     499,   141,   142,   143,   144,   145,   146,     0,     0,  1082,
     148,     0,     0,   400,   151,   152,   153,   154,   155,   156,
     157,   158,   500,   160,   501,   162,   502,   503,   165,   166,
     167,   168,   169,   170,   504,   172,   505,   506,   507,   176,
     177,   508,   509,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,  1083,  1084,
    1085,  1086,  1087,     7,     8,     0,     0,     0,     0,     0,
       0,     0,   397,   398,     0,    14,    15,    16,   471,    18,
      19,    20,   472,    22,   473,   474,  1079,   476,   399,    28,
     477,    30,    31,     0,    32,    33,    34,    35,   478,    37,
      38,    39,    40,    41,    42,    43,   479,     0,    45,   480,
      47,   481,   482,    50,   483,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   484,
     485,    68,     0,    69,    70,    71,   486,     0,    74,    75,
      76,     0,     0,   487,    78,     0,     0,     0,     0,    80,
     488,    82,   489,   490,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   491,    97,    98,   492,   493,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
    1080,     0,     0,     0,  1081,     0,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   494,   120,   121,
     495,     0,     0,     0,     0,     0,     0,     0,   496,   497,
     128,     0,     0,     0,   129,     0,   130,   498,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   499,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
       0,     0,   400,   151,   152,   153,   154,   155,   156,   157,
     158,   500,   160,   501,   162,   502,   503,   165,   166,   167,
     168,   169,   170,   504,   172,   505,   506,   507,   176,   177,
     508,   509,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,  1083,  1084,  1085,
    1086,  1087,     7,     8,     0,     0,     0,     0,     0,     0,
       0,   397,   398,     0,    14,    15,    16,   518,    18,    19,
      20,   472,   519,   520,   474,   475,   476,   399,    28,   477,
      30,    31,     0,    32,    33,    34,    35,   521,    37,   522,
     523,    40,    41,    42,    43,   479,     0,    45,   524,    47,
     481,   482,    50,   483,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,   484,   485,
      68,     0,    69,    70,    71,   525,     0,    74,    75,    76,
       0,     0,   487,    78,     0,     0,     0,     0,    80,   488,
      82,   489,   490,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   491,    97,    98,   492,   493,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,   107,
       0,     0,     0,     0,     0,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   494,   120,   121,   495,
       0,     0,     0,     0,     0,     0,     0,   496,   497,   128,
       0,     0,     0,   129,     0,   130,   498,     0,     0,     0,
       0,     0,   135,     0,   136,   137,   138,   139,   499,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,     0,
       0,   400,   151,   152,   153,   154,   155,   156,   157,   158,
     500,   526,   501,   162,   502,   503,   165,   166,   167,   168,
     169,   170,   504,   172,   505,   506,   507,   176,   177,   508,
     509,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     7,     8,     0,     0,     0,     0,     0,     0,     0,
     397,   398,     0,    14,    15,    16,     0,    18,    19,    20,
     472,     0,     0,   474,   475,     0,   399,    28,   477,    30,
      31,     0,    32,    33,    34,    35,     0,    37,     0,     0,
      40,    41,    42,    43,   479,     0,    45,     0,    47,     0,
       0,    50,   483,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   484,   485,    68,
       0,    69,    70,    71,     0,     0,    74,    75,    76,     0,
       0,   487,    78,     0,     0,     0,     0,    80,   488,    82,
     489,   490,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   491,    97,    98,   492,   493,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,     0,     0,
       0,     0,     0,     0,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   494,   120,   121,   495,     0,
       0,     0,     0,     0,     0,     0,   496,   497,   128,     0,
       0,     0,   129,     0,   130,   498,     0,     0,     0,     0,
       0,   135,     0,   136,   137,   138,   139,   499,   141,   142,
     143,   144,   145,   146,     0,     0,     0,   148,     0,     0,
     400,   151,   152,   153,   154,   155,   156,   157,   158,   500,
       0,   501,   162,   502,   503,   165,   166,   167,   168,   169,
     170,   504,   172,   505,   506,   507,   176,   177,     0,   509,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   406,   407,   286,     4,     5,     6,   179,     0,     4,
       5,     6,     4,     5,     6,   636,    12,   746,   306,   639,
     640,   641,   642,   334,  1222,   786,   729,   133,    73,   758,
     254,  1238,   852,   255,  1327,  1017,   729,   995,  1294,  1295,
     117,    55,  1065,   772,   589,   590,   979,   408,   270,   813,
     420,   886,   587,   588,    26,    27,     1,    36,  1156,    26,
      27,   431,   865,   866,     8,     4,     5,     6,    36,   117,
     683,  1515,     4,     5,     6,    47,     1,   109,   110,    29,
      47,    30,    93,     1,   454,   446,   447,   277,     1,    56,
     587,   588,   589,   590,    99,   141,     1,     1,   617,   902,
     619,   620,    74,   622,   146,   624,    29,    74,   108,  1251,
      26,    27,    79,   632,   633,    94,   108,    96,     1,   902,
     403,    37,    38,   106,    40,    41,   106,    29,    96,   106,
     106,    47,   168,   936,    94,   117,    99,    96,    52,   111,
      56,    57,   146,   110,   111,   112,   223,    94,    45,   266,
     866,   152,   155,   956,   106,   215,   273,   147,    74,   109,
     106,    99,    96,    79,   200,    62,   969,   146,    96,   108,
      54,   182,    56,   123,   164,   176,   108,   155,   146,   908,
     185,   117,    45,   223,    47,   225,   146,    37,    38,   112,
      40,    41,   252,     5,   110,   111,   112,     9,   148,   146,
    1456,   215,   152,   185,   184,   155,   189,    57,   184,    94,
     187,  1655,     9,    10,   128,    99,    79,    76,   146,    94,
       5,  1514,   185,   271,     9,   271,   176,    73,   305,   271,
     174,   337,  1430,   962,   168,   187,   159,   427,   252,   968,
     956,    87,   105,   159,   189,  1065,  1066,   185,   248,   185,
     533,   251,  1013,   969,   286,   543,   248,   159,   961,   251,
    1242,  1219,   112,   212,   189,   111,   959,   271,   961,  1251,
    1368,   189,  1205,   818,   819,   888,   189,   123,  1081,   125,
    1303,   816,   817,  1118,   189,   189,   286,   233,   981,   186,
     159,  1433,   271,   152,   286,   254,   255,   342,  1081,   106,
     345,   106,   218,   271,   167,   102,   189,   257,   106,   159,
     122,     9,   124,   285,    26,    27,   250,   251,   285,   253,
     132,   293,   605,   152,   106,   122,   293,   124,   106,   848,
      28,   216,   217,   694,   301,   106,   270,   122,   181,   124,
     152,   216,   217,   259,   155,    42,   231,   132,   282,    46,
      45,   194,    47,  1609,    51,   152,   231,   157,  1161,   156,
     219,   220,   584,   587,   588,   249,  1573,   152,   218,   285,
     740,   403,    69,   743,    33,   175,   173,   293,   262,   186,
     264,   186,   106,   744,   106,   301,   129,   155,   186,   106,
      49,   275,   276,   277,  1197,   279,   193,   281,   106,   111,
     106,   183,  1658,   403,   436,   106,   106,    96,   186,   259,
     105,   403,   444,   106,   211,   186,   130,   155,  1221,  1517,
     106,   453,   135,   105,   122,   117,   124,   106,   460,   461,
     713,  1160,   432,    39,   434,   133,   149,   469,    44,    45,
     432,    29,   434,   106,   126,   106,  1644,   852,   135,   106,
     155,  1433,   195,    59,   152,    61,    62,   106,   458,   106,
     106,   183,   186,   463,    70,   106,   458,   267,  1171,   186,
     167,   463,   167,   170,   274,   189,   881,   155,   186,   168,
     186,  1197,   106,  1303,   284,   186,   186,  1180,   185,   106,
     183,    97,  1312,   432,   186,   434,   342,   183,   106,   345,
     432,   533,   434,  1323,   183,  1221,  1051,  1052,  1053,    96,
       9,    10,   199,   210,  1278,   547,  1614,  1281,   152,   458,
     223,   109,   225,   186,   463,   186,   458,   559,   811,   186,
      42,   463,  1335,   533,    46,   123,   183,   186,   538,    51,
     186,   533,   176,   575,   576,   186,   538,   152,   909,   910,
     155,   657,   658,   914,  1051,  1052,  1053,    69,  1656,   183,
     148,   250,   251,     9,   253,   106,   412,   413,   155,   186,
     416,   260,   106,   152,   420,   183,   576,   423,   424,   106,
     129,   270,    28,   944,   576,   431,   582,   587,   588,   589,
     590,   437,   816,   282,   440,   587,   588,   589,   590,   538,
     822,    96,   448,   102,  1537,   605,   538,   121,   454,   455,
     456,   457,   106,   605,  1572,  1418,   462,   223,  1421,  1335,
     106,   117,   654,   122,   470,   124,   106,   659,  1726,   208,
    1728,    96,   152,    24,    73,   116,   155,   576,   152,  1737,
      96,   155,   153,    34,   155,   186,   195,   112,    87,     9,
      10,   146,   186,   152,    29,   167,   112,   156,   170,   186,
    1065,  1066,    42,  1483,   145,   155,    46,   120,   514,    60,
    1431,    51,   111,   185,   173,  1436,   122,   158,   124,    94,
    1383,   713,   528,   950,   123,   952,   125,   133,   208,    69,
     155,   537,   186,  1314,   193,   121,    53,   183,   210,   155,
     267,    58,  1418,   183,   157,  1421,   152,   274,   143,    53,
      66,   192,   211,   713,    58,    71,    94,   284,    94,   899,
      77,   713,   175,   121,   136,   571,   141,   245,   246,   141,
     117,   911,  1636,  1637,   109,  1002,   736,  1004,  1283,    96,
     175,   736,   102,   165,   736,   777,   778,   779,   123,   781,
     268,   117,    96,   157,  1037,  1043,  1067,   192,   136,   181,
     117,   117,   122,   141,   124,   141,   766,   767,     9,    10,
    1674,   175,   181,   148,   766,   767,  1680,   152,    95,    33,
     155,   223,   121,   147,   157,   194,   228,   167,   105,  1592,
     170,  1594,   152,   197,   136,    49,   156,   736,   115,  1560,
     164,   176,   175,  1564,   736,   185,   261,   136,    96,   126,
     152,   811,    99,   173,   591,    94,    99,   272,   595,   811,
     190,   191,  1625,   152,   112,   112,   105,   766,   767,   112,
     210,   827,    99,   193,   766,   767,   230,    99,   232,  1200,
     121,   687,    99,    99,   690,   112,   121,  1467,   261,  1652,
     112,   211,   136,  1474,  1475,   112,   112,   141,   704,   272,
      53,   102,   708,   709,  1667,    58,  1669,   344,   199,  1041,
     637,   638,   349,   297,  1046,   121,  1592,   208,  1594,  1640,
    1609,   122,   306,   124,   730,   121,   732,   275,   276,   277,
     127,   128,   152,   281,   740,   155,   660,   743,  1303,   663,
     152,   747,   666,   342,   121,   152,   345,  1312,   155,  1625,
     152,   152,   230,   155,   232,   156,  1199,   121,  1323,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,  1290,
     127,   128,   173,   219,   220,   221,  1652,   867,   868,   785,
     121,   643,   644,  1505,  1506,   121,   645,   646,   214,   152,
     155,  1667,   193,  1669,   223,   117,   155,   239,   152,  1580,
    1581,   239,     0,   240,   106,   189,   166,   813,    92,   197,
     211,   247,    50,   198,   413,   100,   153,   416,   101,   144,
     155,   420,   183,    29,   423,   424,    47,   183,   183,   835,
     117,   151,   431,   244,  1277,   302,   186,   997,   437,   117,
     152,   440,   282,     1,   117,   997,   141,   106,   282,   448,
     155,   152,   186,   152,   183,   454,   455,   456,   457,   865,
     866,   867,   868,   462,   155,   155,   155,  1648,    35,   155,
     141,   470,  1064,   155,   155,   155,   152,  1037,    17,  1400,
     212,    29,   186,   229,     3,  1037,   189,   117,   167,   189,
      70,  1051,  1052,  1053,  1050,   243,   902,   169,   997,  1051,
    1052,  1053,   169,   229,    94,   997,    94,    94,   148,   106,
     916,   131,   106,    29,   159,   514,   159,   126,  1483,   139,
     140,   131,   142,    94,   297,   244,   141,   131,   117,   528,
     150,   183,   183,   186,   154,   941,   156,   186,   537,  1460,
     106,   161,    94,    96,   950,    45,   952,    96,    94,   186,
     956,   186,   186,   186,   183,   183,   152,   223,   178,   141,
     235,    33,   189,   969,   169,   141,   117,   131,    94,  1412,
      29,   284,   571,    94,   297,   225,   117,   152,   146,   126,
     117,   201,   202,   203,   204,   205,   206,   252,   117,    94,
     183,   131,    96,   196,   159,   131,  1002,   152,  1004,   117,
      99,   146,    99,   141,  1164,   183,   183,    35,   152,  1164,
     189,    29,  1164,   155,   117,    79,   106,   243,   106,   152,
     155,   155,   283,   265,   256,    29,   284,   258,   155,   143,
     155,   155,   155,   155,    29,   155,    29,   285,   155,  1199,
     155,   304,   225,   126,   146,   143,   189,  1199,   117,   117,
    1210,   146,   146,    77,  1060,  1210,   106,   141,  1210,    99,
     131,     7,   231,   235,   196,  1164,   105,   105,   231,  1229,
     231,   183,  1164,   186,  1229,  1081,   186,  1229,   186,   186,
     186,  1273,  1274,  1275,   146,   186,   248,    78,  1248,   248,
      29,   690,  1535,   189,   185,   280,  1248,   186,   284,   186,
     231,   186,    29,  1546,  1547,   704,  1549,   186,   186,   708,
     709,  1210,   186,  1556,   106,   269,  1276,  1277,  1210,   186,
     186,   186,   169,   183,  1276,  1277,   146,   255,   125,   146,
    1229,   730,    96,   732,   183,   125,   152,  1229,    94,   185,
     185,   740,   185,   185,   743,   186,   183,   183,   747,  1248,
     183,    29,    96,    53,   186,   169,  1248,   146,    94,   185,
     185,   195,    94,    29,  1170,   196,   106,  1173,   106,   278,
     263,   223,   117,    94,   285,   117,   185,  1276,    94,   223,
     195,    93,  1188,   195,   117,   185,   785,   185,   182,   195,
    1633,  1197,   117,   117,   197,   117,   223,   185,   185,   185,
    1643,   254,  1121,   251,   903,  1211,   693,   407,   427,   291,
     285,   303,   970,   248,   813,  1221,  1614,   303,  1161,  1656,
     814,   251,   303,   967,   304,  1668,  1170,   304,   304,  1299,
     749,  1393,  1056,  1189,  1297,  1294,   835,  1211,  1216,  1219,
     528,  1224,   616,  1249,   615,   635,  1242,   668,  1680,   786,
    1674,   868,  1412,  1155,   435,   952,  1699,   330,  1269,  1279,
    1412,   435,  1278,  1269,  1120,  1312,   865,   866,   867,   868,
    1323,  1483,  1278,  1066,  1316,  1281,  1480,  1720,  1075,  1143,
    1359,  1508,  1725,   935,    -1,  1313,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   902,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   916,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1335,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   941,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   950,    -1,   952,    -1,    -1,    -1,   956,  1364,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     969,    -1,    -1,    -1,    -1,  1535,    -1,    -1,    -1,    -1,
      -1,    -1,  1574,  1535,  1390,  1391,  1546,  1547,    -1,  1549,
      -1,    -1,    -1,    -1,  1546,  1547,  1556,  1549,  1590,    -1,
      -1,    -1,    -1,  1002,  1556,  1004,    -1,    -1,    -1,    -1,
    1416,    -1,  1418,    -1,    -1,  1421,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1432,    -1,    -1,    -1,
      -1,  1437,    -1,   563,   564,    -1,   566,   567,   568,   569,
      -1,    -1,    -1,    -1,   574,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1060,    -1,    -1,    -1,    -1,    -1,   597,    -1,    -1,
      -1,    -1,    -1,  1633,    -1,   605,   606,    -1,    -1,    -1,
      -1,  1633,  1081,  1643,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1643,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1668,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1668,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   665,    -1,    -1,   668,  1699,
      -1,    -1,    -1,    -1,  1550,    -1,  1552,  1699,  1554,    -1,
      -1,    -1,    -1,    -1,    -1,  1561,    -1,    -1,    -1,    -1,
    1720,    -1,    -1,    -1,    -1,  1725,    -1,    -1,  1720,    -1,
      -1,  1170,    -1,  1725,  1173,    -1,   706,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1592,    -1,  1594,  1188,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1197,    -1,
      -1,    -1,    -1,    -1,  1610,    -1,    -1,  1613,    -1,    -1,
      -1,    -1,  1211,    -1,    -1,    -1,    -1,    -1,   748,  1625,
      -1,    -1,  1221,    -1,    -1,    -1,    -1,    -1,    -1,  1635,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   773,    -1,    -1,  1652,    -1,    -1,    -1,
    1249,    -1,    -1,   783,  1660,    -1,    -1,    -1,    -1,  1665,
      -1,  1667,    -1,  1669,    -1,    -1,    -1,    -1,    -1,    -1,
    1269,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1278,
      -1,    -1,  1281,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1696,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1712,   837,    -1,    -1,
    1716,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1732,    -1,    -1,  1735,
      -1,    -1,    -1,    -1,    -1,    -1,  1335,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1364,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   904,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1390,  1391,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   939,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1416,    -1,  1418,
      -1,    -1,  1421,    -1,    -1,    -1,    -1,    -1,   958,    -1,
      -1,    -1,    -1,  1432,    -1,    -1,    -1,    -1,  1437,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     980,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   991,   992,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1006,    -1,    -1,  1009,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1023,  1024,  1025,    -1,  1027,  1028,  1029,
    1030,  1031,  1032,    -1,  1034,  1035,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1056,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1550,    -1,  1552,    -1,  1554,    -1,    -1,    -1,    -1,
      -1,    -1,  1561,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1108,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1592,    -1,  1594,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1610,    -1,    -1,  1613,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1625,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1635,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1175,    -1,  1177,    -1,  1179,
      -1,    -1,  1182,  1652,    -1,    -1,    -1,  1187,    -1,    -1,
      -1,  1660,    -1,    -1,    -1,    -1,  1665,    -1,  1667,  1199,
    1669,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1208,    -1,
      -1,    -1,    -1,    -1,  1214,  1215,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1696,    -1,    -1,
      -1,    -1,    -1,  1233,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1712,    -1,    -1,    -1,  1716,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1732,    -1,    -1,  1735,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1297,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1377,    -1,    -1,
      -1,  1381,    -1,    -1,    -1,  1385,    -1,  1387,    -1,  1389,
      -1,    -1,    -1,    -1,    -1,  1395,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1403,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1411,  1412,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1429,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1440,  1441,  1442,  1443,  1444,    -1,  1446,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     309,   310,   311,   312,   313,    11,    12,    -1,    -1,    -1,
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
     306,   307,   308,   309,   310,   311,   312,    11,    12,    -1,
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
     304,   305,   306,   307,   308,   309,   310,   311,   312,    11,
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
      -1,   183,    -1,   185,    -1,   187,   188,    -1,   190,   191,
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
     312,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     180,   181,    -1,   183,    -1,   185,    -1,   187,   188,    -1,
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
     310,   311,   312,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
     308,   309,   310,   311,   312,    11,    12,    -1,    -1,    -1,
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
     176,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,
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
     306,   307,   308,   309,   310,   311,   312,    11,    12,    -1,
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
      -1,   175,   176,    -1,    -1,   179,   180,   181,    -1,    -1,
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
     304,   305,   306,   307,   308,   309,   310,   311,   312,    11,
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
     312,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     310,   311,   312,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
     308,   309,   310,   311,   312,    11,    12,    -1,    -1,    -1,
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
     176,    -1,    -1,   179,   180,   181,    -1,    -1,   184,   185,
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
     306,   307,   308,   309,   310,   311,   312,    11,    12,    -1,
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
     304,   305,   306,   307,   308,   309,   310,   311,   312,    11,
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
      -1,   183,    -1,   185,    -1,   187,   188,    -1,   190,   191,
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
     312,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     150,   151,   152,   153,    -1,   155,   156,   157,   158,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,   173,    -1,   175,   176,    -1,    -1,   179,
     180,   181,    -1,    -1,    -1,   185,   186,   187,   188,    -1,
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
     310,   311,   312,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
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
      -1,   179,   180,   181,    -1,    -1,    -1,   185,   186,   187,
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
     308,   309,   310,   311,   312,    11,    12,    -1,    -1,    -1,
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
     176,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,
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
     306,   307,   308,   309,   310,   311,   312,    11,    12,    -1,
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
     304,   305,   306,   307,   308,   309,   310,   311,   312,    11,
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
     312,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     310,   311,   312,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
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
     148,   149,   150,   151,   152,   153,    -1,   155,   156,    -1,
     158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,    -1,    -1,    -1,    -1,
      -1,   179,   180,   181,    -1,    -1,    -1,   185,    -1,   187,
     188,    -1,    -1,    -1,   192,    -1,   194,    -1,   196,   197,
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
     308,   309,   310,   311,   312,    11,    12,    -1,    -1,    -1,
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
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,    -1,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,    -1,   150,   151,   152,   153,    -1,   155,
     156,    -1,   158,   159,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,   173,    -1,    -1,
      -1,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,
      -1,   187,   188,    -1,    -1,    -1,   192,    -1,   194,    -1,
     196,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
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
     306,   307,   308,   309,   310,   311,   312,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    -1,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,    -1,   149,   150,   151,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   159,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   179,   180,   181,    -1,    -1,
      -1,   185,    -1,   187,   188,    -1,    -1,    -1,   192,    -1,
     194,    -1,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,    -1,    -1,   209,   210,    -1,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,   257,   258,   259,    -1,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    -1,    99,   100,   101,
      -1,    -1,   104,   105,    -1,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   125,   126,   127,   128,    -1,   130,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,    -1,   149,   150,   151,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
      -1,    -1,    -1,   185,    -1,   187,   188,    -1,    -1,    -1,
     192,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,   209,   210,    -1,
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
     312,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,
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
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
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
     305,   306,   307,   308,   309,   310,   311,   312,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    -1,    -1,
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
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,   197,
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
     308,   309,   310,   311,   312,    18,    19,    -1,    -1,    -1,
      -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    -1,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,    -1,   149,   150,   151,    -1,    -1,
      -1,   155,    -1,    -1,   158,   159,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   179,   180,   181,    -1,    -1,
      -1,   185,   186,   187,   188,    -1,    -1,    -1,   192,    -1,
     194,    -1,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,    -1,    -1,   209,   210,    -1,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,   257,   258,   259,    -1,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,    24,
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
     305,   306,   307,   308,   309,   310,   311,   312,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
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
      -1,   257,   258,   259,    -1,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    -1,    99,   100,   101,    -1,    -1,   104,   105,    -1,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,
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
     307,   308,   309,   310,   311,   312,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      -1,    99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,
     128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,
      -1,   149,   150,   151,    -1,    -1,    -1,   155,    -1,    -1,
     158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   179,   180,   181,    -1,    -1,    -1,   185,    -1,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,   197,
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
     308,   309,   310,   311,   312,    24,    25,    -1,    -1,    -1,
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
     309,   310,   311,   312,    24,    25,    -1,    -1,    -1,    -1,
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
     150,   151,    -1,    -1,    -1,   155,    -1,    -1,   158,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,
     180,   181,    -1,    -1,    -1,   185,    -1,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,   209,
     210,    -1,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,   257,   258,   259,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,    24,    25,    -1,    -1,    -1,    -1,    -1,
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
     251,   252,   253,   254,   255,    -1,   257,   258,   259,    -1,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    -1,    99,   100,   101,
      -1,    -1,   104,   105,    -1,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   125,   126,   127,   128,    -1,   130,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,    -1,   149,   150,   151,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
      -1,    -1,    -1,   185,    -1,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,   209,   210,    -1,
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
     312,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    -1,    40,    41,    42,
      43,    -1,    -1,    46,    47,    -1,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    -1,    60,    -1,    -1,
      63,    64,    65,    66,    67,    -1,    69,    -1,    71,    -1,
      -1,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    -1,    -1,    99,   100,   101,    -1,
      -1,   104,   105,    -1,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,
      -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,
      -1,    -1,   145,   146,   147,    -1,   149,   150,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   159,    -1,    -1,    -1,
      -1,   164,   165,   166,   167,   168,   169,   170,   171,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,    -1,
      -1,    -1,   185,    -1,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,    -1,    -1,    -1,   210,    -1,    -1,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,   257,   258,   259,    -1,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   328,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   349,   350,   351,
     352,   353,   354,   358,   359,   360,   364,   366,   367,   369,
     376,   378,   381,   382,   383,   385,   386,   387,   388,   389,
     391,   392,   394,   395,   396,   397,   398,   399,   401,   402,
     405,   406,   407,   408,   413,   415,   417,   418,   423,   442,
     445,   449,   452,   453,   458,   459,   460,   461,   463,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   510,
     511,   512,   526,   527,   529,   530,   531,   532,   533,   534,
     535,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   555,   556,   557,   558,   563,   564,   565,   566,   567,
     568,   571,   629,   630,   638,   639,   640,    33,    34,    49,
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
     494,   638,   639,   121,   117,   393,   121,   121,    39,    44,
      45,    59,    61,    62,    70,    97,   223,   638,   117,   121,
     121,   183,   384,   386,    48,    72,    73,   117,   152,   184,
     242,   405,   407,   417,   186,   405,   638,   152,   121,    16,
     637,   638,    18,    19,   638,   121,   121,   121,   486,   152,
      30,   212,   214,   223,   225,   155,   223,   225,   223,   223,
     228,   117,   239,   239,   240,   155,   152,   388,   330,     0,
     332,   333,    33,    49,   335,   352,     1,   189,   329,   189,
     329,   111,   367,   387,   405,   106,   189,   106,   189,    42,
      46,    51,    69,   167,   170,   185,   210,   400,   409,   414,
     415,   416,   430,   431,   435,   166,    92,   131,   139,   140,
     142,   150,   154,   156,   161,   178,   201,   202,   203,   204,
     205,   206,   478,   479,   247,   197,   120,   157,   175,   116,
     145,   158,   192,   199,   208,   135,   149,    50,   198,   100,
     101,   157,   175,   477,   152,   483,   486,   190,   191,   153,
     498,   499,   494,   498,   494,   155,   498,   144,   155,   183,
     183,   183,   368,   501,   368,    29,   636,   181,   194,   181,
     194,   165,   181,   639,   638,   168,   200,    47,   638,   151,
     117,    45,    47,    79,   105,   167,   637,   219,   220,   221,
     244,   602,   638,   638,   302,   136,   141,   111,   285,   293,
     370,   637,   385,   386,   186,   385,    45,    62,   186,   551,
     552,   405,   186,   192,   638,   282,   282,   419,   420,   638,
     117,   426,   117,   186,   374,   375,   152,   390,   405,     1,
     159,   636,   112,   159,   348,   636,   638,   117,   141,   106,
     405,    29,   186,   637,   638,   638,   443,   444,   638,   385,
     186,   405,   405,   553,   638,   385,   152,   152,   405,   186,
     192,   638,   638,   141,   443,   183,   183,   155,   155,   155,
     638,   152,   184,   185,   186,    35,   514,   515,   516,   405,
       8,   174,    17,   405,   212,    29,   406,   406,   186,   406,
     406,   406,   406,   229,   569,   570,   638,   189,   189,   406,
     405,   386,   405,   243,   403,   404,   189,   329,   189,   329,
       3,   336,   352,   382,   336,   352,   382,    33,   353,   382,
     353,   382,   393,   393,   406,   117,   167,   169,   169,   387,
     406,   406,   460,   461,   463,   463,   463,   463,   462,   463,
     463,   463,    70,   466,   467,   468,   468,   469,   469,   469,
     469,   470,   470,   471,   471,   229,    94,    94,    94,   183,
     405,   486,   486,   405,   499,   186,   406,   509,   148,   186,
     509,   106,   186,   186,   106,   106,   373,    29,   639,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,   355,
     356,   357,    94,   136,   141,   361,   362,   363,   638,   159,
     159,   355,   636,   126,   131,    54,    56,    99,   249,   262,
     264,   275,   276,   277,   279,   281,   603,   604,   605,   606,
     607,   608,   615,   621,   622,   244,    94,   297,   638,   141,
     406,   117,   638,   638,   131,   183,   183,   186,   186,   183,
     106,   186,   106,   186,   106,    36,    94,    96,   146,   421,
     422,   537,   638,    55,   215,   252,   411,   412,   638,    94,
     106,   186,   384,   186,   637,    96,    45,   637,   636,    96,
     141,   537,   638,   406,   425,   183,   186,   186,   186,   186,
     106,   187,   146,   537,   183,   186,   186,   152,   183,   385,
     385,   183,   106,   186,   106,   186,   141,   537,   406,   187,
     405,   405,   405,   638,   515,   516,   129,   195,   183,   183,
     130,   189,    94,   216,   217,   231,    94,   216,   217,   231,
      94,   235,   223,   106,   233,   141,   189,   186,    48,    72,
      73,   242,   407,   417,   183,   495,   575,   404,   352,    33,
      33,   189,   329,   189,   112,   638,   169,   406,   436,   437,
     117,   432,   433,   463,   152,   155,   257,   482,   501,   576,
     579,   580,   581,   582,   583,   587,   589,   591,   592,    47,
     151,   155,   209,   308,   309,   310,   311,   312,   538,   540,
     542,   543,   559,   560,   561,   562,   631,   632,   633,   634,
     635,   638,   538,   536,   542,   536,   183,   184,   106,   186,
     186,   501,   147,   164,   147,   164,   136,   390,   373,   356,
     131,   540,   363,   406,   537,   636,   636,   127,   128,   636,
     275,   276,   277,   281,   638,   261,   272,   261,   272,    29,
     284,    96,   112,   155,   609,   612,   603,    39,    44,    59,
      61,    70,    97,   223,   377,   543,   225,   297,   306,   406,
     638,    94,   297,   636,   152,   553,   554,   638,   553,   554,
     117,   126,   538,   117,   406,   146,   422,   146,    36,   146,
     421,   422,   146,   537,   252,    53,    58,    77,   117,   421,
     427,   428,   429,   412,   537,   538,   375,    94,   183,   196,
     131,   347,   636,   159,   131,    96,   347,   406,   141,   422,
     152,   117,   406,   406,   146,    99,   446,   447,   448,   450,
     451,    99,   454,   455,   456,   457,   385,   183,   183,   152,
     553,   553,   406,   141,   189,   406,   186,   186,   186,    35,
     516,   129,   195,     9,    10,   102,   122,   124,   152,   193,
     511,   513,   524,   525,   528,    29,   230,   232,   406,   406,
     406,   230,   232,   406,   406,   406,   406,   406,   406,   117,
     406,   406,   387,   155,   155,   155,   152,   185,   243,   572,
     573,   208,   388,   189,   112,   382,   382,   382,   436,    95,
     105,   115,   126,   438,   439,   440,   441,   106,   638,   106,
     405,   576,   583,   152,   283,   464,   628,    96,   168,   250,
     251,   253,   260,   270,   282,   577,   578,   597,   598,   599,
     600,   623,   626,   256,   258,   584,   602,   265,   588,   624,
     245,   246,   268,   593,   594,   155,   155,   540,   155,   155,
     155,   155,   155,   155,   143,   175,   192,   539,   143,   406,
     136,   390,   555,   362,   284,    29,    96,   112,   155,   616,
      29,   609,   539,   484,   285,   304,   537,   377,   225,   189,
     384,   186,   186,   143,   186,   186,   420,   146,   421,   638,
     406,   146,   406,   126,   406,   146,   422,   146,   406,   146,
     117,   117,   406,   638,   429,    77,   538,   387,   406,   636,
     106,   347,   406,   141,   384,   444,   406,   406,   112,   447,
     448,    99,   185,   112,   448,   451,   117,   538,    99,   112,
     455,    99,   112,   457,   183,   384,   186,   186,   406,   196,
     454,   131,   193,   513,     7,   385,   638,   193,   524,   189,
     231,   231,   231,   231,   235,   570,   185,   405,   405,   405,
     575,   573,   495,   636,   127,   128,   440,   441,   441,   437,
     105,   434,   433,   183,   186,   576,   590,   248,   215,   252,
     266,   273,   627,    96,   254,   255,   625,   248,   580,   627,
     467,   597,   581,   146,   280,   585,   586,   625,   284,   596,
      78,   595,   186,   192,   538,   541,   186,   186,   186,   186,
     186,   186,   186,   186,    29,   135,   199,   618,   619,   620,
      29,   617,   618,   269,   613,   106,   610,   169,   638,   255,
     484,   183,   406,   146,   406,   146,   421,   406,   146,   406,
     406,   638,   638,   428,   406,   125,   125,    96,   636,   406,
     183,   185,   185,   406,   387,   406,   185,   185,   638,   185,
     117,   538,   117,   185,   117,   538,   185,   183,   112,   516,
     638,   193,   183,   516,   638,   406,   406,   406,   406,   406,
     406,   186,   186,   186,   152,   574,   441,   636,   183,   469,
      52,   128,   467,   467,   267,   274,   284,   601,   601,   582,
     152,   278,    94,   186,   106,   186,   616,   616,   620,   106,
     186,    29,   614,   625,   611,   612,   186,   379,   380,   484,
     117,   223,   305,   285,   169,   406,   406,   146,   406,    53,
     387,   406,   347,   406,   387,    94,   387,   406,   638,   185,
     638,   406,   638,   185,   387,   117,    93,   182,   517,   516,
     638,   195,   516,   196,   454,   405,   467,   467,   197,   405,
     538,   538,    94,    29,   263,   106,   106,   441,   537,   638,
     117,   223,   638,   379,   406,   117,   538,    94,   185,    94,
     638,     5,   132,   520,   521,   523,   525,    28,   133,   518,
     519,   522,   525,   195,   516,   195,   112,   183,   467,   183,
     538,   612,   380,   441,   303,   638,   117,   223,   638,   185,
     538,   387,   406,   538,   185,    93,   132,   523,   182,   133,
     522,   195,   117,   406,   303,   638,   117,   387,   406,   185,
     185,   638,   291,   303,   638,   185,   304,   406,   304,   484,
     484,   197,   285,   638,   223,   117,   638,   304,   484
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
     540,   540,   540,   540,   540,   540,   541,   541,   542,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   544,   545,
     545,   545,   546,   547,   548,   548,   548,   549,   549,   549,
     549,   549,   550,   551,   551,   551,   551,   551,   551,   551,
     552,   553,   554,   555,   556,   556,   557,   558,   559,   559,
     560,   561,   561,   562,   563,   563,   563,   564,   564,   564,
     564,   564,   564,   564,   564,   564,   564,   565,   565,   566,
     566,   567,   568,   569,   569,   570,   571,   572,   572,   573,
     574,   575,   575,   576,   577,   577,   578,   578,   579,   579,
     580,   580,   581,   581,   582,   582,   583,   584,   584,   585,
     585,   586,   587,   587,   587,   588,   588,   589,   590,   590,
     591,   592,   592,   593,   593,   594,   594,   594,   595,   595,
     596,   596,   597,   597,   597,   597,   597,   598,   599,   600,
     601,   601,   601,   602,   602,   603,   603,   603,   603,   603,
     603,   603,   603,   604,   604,   604,   604,   605,   605,   606,
     607,   607,   608,   608,   608,   609,   609,   610,   610,   611,
     611,   612,   613,   613,   614,   614,   615,   615,   615,   616,
     616,   617,   617,   618,   618,   619,   619,   620,   620,   621,
     622,   622,   623,   623,   623,   624,   625,   625,   625,   625,
     626,   626,   627,   627,   628,   629,   630,   630,   631,   631,
     631,   631,   632,   633,   634,   635,   636,   637,   637,   638,
     638,   638,   638,   638,   638,   638,   638,   638,   638,   638,
     638,   638,   638,   638,   638,   639,   639,   639,   639,   639,
     639,   639,   639,   639,   639,   639,   639,   639,   639,   639,
     639,   639,   639,   639,   639,   639,   639,   639,   639,   639,
     639,   639,   639,   639,   639,   639,   639,   639,   639,   639,
     639,   639,   639,   639,   639,   639,   639,   639,   639,   639,
     639,   639,   639,   639,   639,   639,   639,   639,   639,   639,
     639,   639,   639,   639,   639,   639,   639,   639,   639,   639,
     639,   639,   639,   639,   639,   639,   639,   639,   639,   639,
     639,   639,   639,   639,   639,   639,   639,   639,   639,   639,
     639,   639,   639,   639,   639,   639,   639,   639,   639,   639,
     639,   639,   639,   639,   639,   639,   639,   639,   639,   639,
     639,   639,   639,   639,   639,   639,   639,   639,   639,   639,
     639,   639,   639,   639,   639,   639,   639,   639,   639,   639,
     639,   639,   639,   639,   639,   639,   639,   639,   639,   639,
     639,   639,   639,   639,   639,   639,   639,   639,   639,   639,
     639,   639,   639,   639,   639,   639,   639,   639,   639,   639,
     639,   639,   639,   639,   639,   639,   639,   639,   639,   639,
     639,   639,   639,   639,   639,   639,   639,   639,   639,   639,
     639,   639,   639,   639,   639,   639,   639,   639,   639,   639,
     639,   639,   639,   639,   639,   639,   639,   639,   639,   639,
     639,   639,   639,   639,   639,   639,   639,   639,   639,   640
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
       1,     3,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       4,     4,     3,     3,     3,     4,     4,     3,     4,     6,
       4,     6,     4,     3,     4,     6,     6,     4,     6,     6,
       4,     1,     2,     1,     1,     1,     3,     3,     1,     1,
       4,     5,     6,     3,     3,     3,     3,     5,     7,     7,
       5,     5,     5,     7,     7,     5,     5,     3,     3,     5,
       7,     5,     7,     1,     4,     3,     5,     1,     2,     3,
       3,     1,     3,     2,     0,     1,     1,     2,     1,     3,
       1,     3,     1,     4,     1,     2,     3,     0,     1,     0,
       1,     4,     2,     3,     1,     0,     1,     4,     0,     1,
       2,     1,     3,     0,     1,     2,     2,     1,     0,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     1,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     2,     2,     3,
       1,     2,     2,     5,     2,     1,     1,     0,     2,     1,
       3,     4,     0,     2,     0,     2,     4,     4,     3,     2,
       3,     1,     3,     0,     1,     1,     2,     2,     2,     2,
       1,     2,     2,     2,     2,     3,     2,     3,     3,     4,
       2,     2,     1,     1,     3,     1,     2,     3,     1,     1,
       1,     1,     3,     3,     3,     3,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
  "\"'keys'\"", "\"'structured-item'\"", "\"'array'\"", "\"'json-item'\"",
  "\"'object'\"", "\"'pair'\"", "\"'BOM_UTF8'\"", "RANGE_REDUCE",
  "SEQUENCE_TYPE_REDUCE", "ADDITIVE_REDUCE", "UNION_REDUCE",
  "INTERSECT_EXCEPT_REDUCE", "QVARINDECLLIST_REDUCE", "COMMA_DOLLAR",
  "UNARY_PREC", "OCCURS_STAR", "OCCURS_PLUS", "OCCURS_HOOK", "STEP_REDUCE",
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
  "FTIgnoreOption", "JSONConstructor", "JSONDirectArrayConstructor",
  "JSONTest", "JSONItemTest", "JSONObjectTest", "JSONArrayTest",
  "JSONPairTest", "URI_LITERAL", "NCNAME", "QNAME", "FUNCTION_NAME",
  "EQNAME", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const xquery_parser::rhs_number_type
  xquery_parser::yyrhs_[] =
  {
       328,     0,    -1,   330,    -1,   313,   330,    -1,     1,     3,
      -1,   332,    -1,   331,   332,    -1,   333,    -1,   331,   333,
      -1,   213,   214,    29,   189,    -1,   213,   214,    29,   130,
      29,   189,    -1,   335,   189,   382,    -1,   352,   189,   382,
      -1,   335,   189,   352,   189,   382,    -1,   382,    -1,   335,
     329,   382,    -1,   352,   329,   382,    -1,   335,   189,   352,
     329,   382,    -1,   335,   329,   352,   189,   382,    -1,   334,
      -1,   334,   335,   189,    -1,   334,   352,   189,    -1,   334,
     335,   189,   352,   189,    -1,    34,   159,   637,   131,   636,
     189,    -1,   336,    -1,   335,   189,   336,    -1,   335,   329,
     336,    -1,   337,    -1,   345,    -1,   350,    -1,   351,    -1,
     359,    -1,   338,    -1,   339,    -1,   340,    -1,   341,    -1,
     342,    -1,   343,    -1,   344,    -1,   563,    -1,    33,    38,
     181,    -1,    33,    38,   194,    -1,    33,   112,   105,   636,
      -1,    33,    37,   636,    -1,    33,    40,   181,    -1,    33,
      40,   194,    -1,    33,    57,   168,    -1,    33,    57,   200,
      -1,    33,   112,   167,   126,   127,    -1,    33,   112,   167,
     126,   128,    -1,    33,    41,   181,   106,   147,    -1,    33,
      41,   181,   106,   164,    -1,    33,    41,   165,   106,   147,
      -1,    33,    41,   165,   106,   164,    -1,   346,    -1,   349,
      -1,    49,    24,     1,    -1,    49,    60,   636,    -1,    49,
      60,   348,   636,    -1,    49,    60,   636,    96,   347,    -1,
      49,    60,   348,   636,    96,   347,    -1,   636,    -1,   347,
     106,   636,    -1,   159,   637,   131,    -1,   112,    45,   159,
      -1,    49,    34,   636,    -1,    49,    34,   159,   637,   131,
     636,    -1,    49,    34,   636,    96,   347,    -1,    49,    34,
     159,   637,   131,   636,    96,   347,    -1,    33,   159,   637,
     131,   636,    -1,    33,   112,    45,   159,   636,    -1,    33,
     112,    47,   159,   636,    -1,   353,    -1,   352,   189,   353,
      -1,   352,   329,   353,    -1,   354,    -1,   358,    -1,   360,
      -1,   364,    -1,   369,    -1,   376,    -1,   378,    -1,   381,
      -1,    33,   112,    79,   355,    -1,    33,    79,   638,   355,
      -1,   356,    -1,   355,   356,    -1,   357,   131,   555,    -1,
      80,    -1,    88,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    89,    -1,    85,    -1,    86,    -1,    87,    -1,
      33,    56,   638,    29,    -1,    33,   259,   602,    -1,    33,
     110,   151,   361,    -1,    94,   540,   362,    -1,   362,    -1,
     363,    -1,   136,    -1,   136,   363,    -1,   141,   406,    -1,
      33,   365,   141,   406,    -1,    33,   365,   136,    -1,    33,
     365,   136,   141,   406,    -1,   111,   117,   638,    -1,   111,
     117,   638,   537,    -1,   366,   111,   117,   638,    -1,   366,
     111,   117,   638,   537,    -1,   367,    -1,   366,   367,    -1,
      26,    -1,    26,   155,   368,   186,    -1,    27,    -1,    27,
     155,   368,   186,    -1,   501,    -1,   368,   106,   501,    -1,
      33,   370,    -1,    33,   366,   370,    -1,   371,    -1,   372,
      -1,    47,   639,   373,   390,    -1,    47,   639,   373,   136,
      -1,    74,    47,   639,   373,   390,    -1,    74,    47,   639,
     373,   136,    -1,   155,   186,    -1,   155,   374,   186,    -1,
     155,   186,    94,   538,    -1,   155,   374,   186,    94,   538,
      -1,   375,    -1,   374,   106,   375,    -1,   117,   638,    -1,
     117,   638,   537,    -1,    33,   285,   638,    -1,    33,   285,
     638,    94,   377,    -1,    33,   366,   285,   638,    -1,    33,
     366,   285,   638,    94,   377,    -1,   543,    -1,   543,   539,
      -1,    33,   293,   638,   297,   225,   484,   169,   379,    -1,
      33,   366,   293,   638,   297,   225,   484,   169,   379,    -1,
     380,    -1,   379,   106,   380,    -1,   484,    -1,   484,   537,
      -1,   484,   441,    -1,   484,   537,   441,    -1,    33,   301,
     302,   638,   297,   285,   638,   117,   638,   303,   406,    -1,
      33,   301,   302,   638,   297,   285,   638,   223,   117,   638,
     303,   291,   304,   484,    -1,    33,   301,   302,   638,   297,
     285,   638,   305,   223,   117,   638,   303,   406,    -1,    33,
     301,   302,   638,   306,   304,   255,   285,   638,   223,   117,
     638,   304,   484,   197,   285,   638,   223,   117,   638,   304,
     484,    -1,   383,    -1,   385,    -1,   386,    -1,    -1,   385,
      -1,   386,    -1,    -1,   405,    -1,   386,   405,    -1,   387,
      -1,   386,   387,    -1,   388,    -1,   391,    -1,   394,    -1,
     395,    -1,   396,    -1,   397,    -1,   398,    -1,   399,    -1,
     401,    -1,   453,    -1,   449,    -1,   402,    -1,   152,   386,
     183,    -1,   152,   183,    -1,   152,   384,   183,    -1,   152,
     384,   183,    -1,   392,   189,    -1,   392,   106,   393,    -1,
     111,   393,    -1,   366,   111,   393,    -1,   117,   638,    -1,
     117,   638,   537,    -1,   117,   638,   141,   406,    -1,   117,
     638,   537,   141,   406,    -1,   117,   638,   141,   406,   189,
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
     412,    -1,    42,   117,   638,    -1,   418,    -1,   423,    -1,
     413,    -1,   415,    -1,   430,    -1,   435,    -1,   431,    -1,
     414,    -1,   415,    -1,   417,   416,    -1,    46,   117,   419,
      -1,   420,    -1,   419,   106,   117,   420,    -1,   638,   146,
     406,    -1,   638,    36,   126,   146,   406,    -1,   638,   537,
     146,   406,    -1,   638,   537,    36,   126,   146,   406,    -1,
     638,   421,   146,   406,    -1,   638,    36,   126,   421,   146,
     406,    -1,   638,   537,   421,   146,   406,    -1,   638,   537,
      36,   126,   421,   146,   406,    -1,   638,   422,   146,   406,
      -1,   638,   537,   422,   146,   406,    -1,   638,   421,   422,
     146,   406,    -1,   638,   537,   421,   422,   146,   406,    -1,
      96,   117,   638,    -1,   271,   117,   638,    -1,    51,   424,
      -1,   425,    -1,   424,   106,   425,    -1,   117,   638,   141,
     406,    -1,   117,   638,   537,   141,   406,    -1,   422,   141,
     406,    -1,   117,   638,   537,   422,   141,   406,    -1,   117,
     638,   146,   406,    -1,   117,   638,   537,   146,   406,    -1,
     428,    -1,   117,   638,    -1,   117,   638,   428,    -1,   421,
      -1,   421,   429,    -1,   429,    -1,    58,   117,   638,    53,
     117,   638,    -1,    53,   117,   638,    -1,    58,   117,   638,
      -1,   210,   406,    -1,   170,   169,   432,    -1,   433,    -1,
     432,   106,   433,    -1,   117,   638,    -1,   117,   638,   434,
      -1,   105,   636,    -1,   167,   169,   436,    -1,    69,   167,
     169,   436,    -1,   437,    -1,   436,   106,   437,    -1,   406,
      -1,   406,   438,    -1,   439,    -1,   440,    -1,   441,    -1,
     439,   440,    -1,   439,   441,    -1,   440,   441,    -1,   439,
     440,   441,    -1,    95,    -1,   115,    -1,   126,   127,    -1,
     126,   128,    -1,   105,   636,    -1,    67,   117,   443,   187,
     406,    -1,   134,   117,   443,   187,   406,    -1,   444,    -1,
     443,   106,   117,   444,    -1,   638,   146,   406,    -1,   638,
     537,   146,   406,    -1,    72,   155,   405,   186,   446,   112,
     185,   406,    -1,   447,    -1,   446,   447,    -1,   448,   185,
     406,    -1,    99,   406,    -1,   448,    99,   406,    -1,    72,
     155,   405,   186,   450,   112,   185,   387,    -1,   451,    -1,
     450,   451,    -1,   448,   185,   387,    -1,    73,   155,   405,
     186,   454,   112,   185,   406,    -1,    73,   155,   405,   186,
     454,   112,   117,   638,   185,   406,    -1,    73,   155,   405,
     186,   456,   112,   185,   387,    -1,    73,   155,   405,   186,
     454,   112,   117,   638,   185,   387,    -1,   455,    -1,   454,
     455,    -1,    99,   538,   185,   406,    -1,    99,   117,   638,
      94,   538,   185,   406,    -1,   457,    -1,   456,   457,    -1,
      99,   538,   185,   387,    -1,    99,   117,   638,    94,   538,
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
      -1,   483,    -1,   482,   483,    -1,   176,   638,    17,    -1,
     176,    18,    -1,   176,    19,    -1,   485,    -1,   485,   486,
      -1,   191,   486,    -1,   486,    -1,   190,    -1,   487,    -1,
     487,   190,   486,    -1,   487,   191,   486,    -1,   488,    -1,
     497,    -1,   489,    -1,   489,   498,    -1,   492,    -1,   492,
     498,    -1,   490,   494,    -1,   491,    -1,   104,   121,    -1,
     113,   121,    -1,    97,   121,    -1,   188,   121,    -1,   114,
     121,    -1,   138,   121,    -1,   137,   121,    -1,   494,    -1,
      98,   494,    -1,   493,   494,    -1,   119,    -1,   171,   121,
      -1,    90,   121,    -1,   180,   121,    -1,   179,   121,    -1,
      91,   121,    -1,   543,    -1,   495,    -1,   638,    -1,   496,
      -1,   192,    -1,    11,    -1,    12,    -1,    20,    -1,   500,
      -1,   497,   498,    -1,   497,   155,   186,    -1,   497,   155,
     509,   186,    -1,   499,    -1,   498,   499,    -1,   153,   405,
     184,    -1,   501,    -1,   503,    -1,   504,    -1,   505,    -1,
     508,    -1,   510,    -1,   506,    -1,   507,    -1,   556,    -1,
     389,    -1,   629,    -1,   502,    -1,   555,    -1,   109,    -1,
     148,    -1,   123,    -1,   117,   638,    -1,   155,   186,    -1,
     155,   405,   186,    -1,   118,    -1,   168,   152,   405,   183,
      -1,   200,   152,   405,   183,    -1,   639,   155,   186,    -1,
     639,   155,   509,   186,    -1,   406,    -1,   509,   106,   406,
      -1,   511,    -1,   529,    -1,   512,    -1,   526,    -1,   527,
      -1,   156,   638,   516,   129,    -1,   156,   638,   514,   516,
     129,    -1,   156,   638,   516,   195,   193,   638,   516,   195,
      -1,   156,   638,   516,   195,   513,   193,   638,   516,   195,
      -1,   156,   638,   514,   516,   195,   193,   638,   516,   195,
      -1,   156,   638,   514,   516,   195,   513,   193,   638,   516,
     195,    -1,   524,    -1,   513,   524,    -1,   515,    -1,   514,
     515,    -1,    35,   638,   516,   131,   516,   517,    -1,    -1,
      35,    -1,   182,   518,   182,    -1,    93,   520,    93,    -1,
      -1,   519,    -1,   133,    -1,   522,    -1,   519,   133,    -1,
     519,   522,    -1,    -1,   521,    -1,   132,    -1,   523,    -1,
     521,   132,    -1,   521,   523,    -1,    28,    -1,   525,    -1,
       5,    -1,   525,    -1,   511,    -1,    10,    -1,   528,    -1,
     525,    -1,     9,    -1,   122,    -1,   124,    -1,   152,   385,
     183,    -1,   211,    30,   212,    -1,   211,   212,    -1,   173,
     637,   174,    -1,   173,   637,     8,    -1,   102,     7,    -1,
     530,    -1,   531,    -1,   532,    -1,   533,    -1,   534,    -1,
     535,    -1,    43,   152,   385,   183,    -1,    21,   384,   183,
      -1,    45,   152,   405,   183,   152,   384,   183,    -1,    22,
     384,   183,    -1,    97,   152,   405,   183,   152,   384,   183,
      -1,    70,   152,   385,   183,    -1,    39,   152,   385,   183,
      -1,    23,   384,   183,    -1,    59,   152,   405,   183,   152,
     384,   183,    -1,   542,    -1,   542,   143,    -1,    94,   538,
      -1,   540,    -1,   540,   539,    -1,   209,   155,   186,    -1,
     143,    -1,   192,    -1,   175,    -1,   542,    -1,   543,    -1,
     151,   155,   186,    -1,   308,   155,   186,    -1,   559,    -1,
     562,    -1,   631,    -1,   538,    -1,   541,   106,   538,    -1,
     638,    -1,   545,    -1,   551,    -1,   549,    -1,   552,    -1,
     550,    -1,   548,    -1,   547,    -1,   546,    -1,   544,    -1,
     223,   155,   186,    -1,    44,   155,   186,    -1,    44,   155,
     551,   186,    -1,    44,   155,   552,   186,    -1,    70,   155,
     186,    -1,    39,   155,   186,    -1,    59,   155,   186,    -1,
      59,   155,   637,   186,    -1,    59,   155,    29,   186,    -1,
      97,   155,   186,    -1,    97,   155,   638,   186,    -1,    97,
     155,   638,   106,   553,   186,    -1,    97,   155,   192,   186,
      -1,    97,   155,   192,   106,   553,   186,    -1,    61,   155,
     638,   186,    -1,    45,   155,   186,    -1,    45,   155,   638,
     186,    -1,    45,   155,   638,   106,   553,   186,    -1,    45,
     155,   638,   106,   554,   186,    -1,    45,   155,   192,   186,
      -1,    45,   155,   192,   106,   553,   186,    -1,    45,   155,
     192,   106,   554,   186,    -1,    62,   155,   638,   186,    -1,
     638,    -1,   638,   143,    -1,    29,    -1,   557,    -1,   558,
      -1,   638,   144,   148,    -1,    47,   373,   390,    -1,   560,
      -1,   561,    -1,    47,   155,   192,   186,    -1,    47,   155,
     186,    94,   538,    -1,    47,   155,   541,   186,    94,   538,
      -1,   155,   540,   186,    -1,    33,   218,   219,    -1,    33,
     218,   220,    -1,    33,   218,   221,    -1,   224,   223,   406,
     231,   406,    -1,   224,   223,   406,    94,   230,   231,   406,
      -1,   224,   223,   406,    94,   232,   231,   406,    -1,   224,
     223,   406,   216,   406,    -1,   224,   223,   406,   217,   406,
      -1,   224,   225,   406,   231,   406,    -1,   224,   225,   406,
      94,   230,   231,   406,    -1,   224,   225,   406,    94,   232,
     231,   406,    -1,   224,   225,   406,   216,   406,    -1,   224,
     225,   406,   217,   406,    -1,   222,   223,   406,    -1,   222,
     225,   406,    -1,   227,   223,   406,   235,   406,    -1,   227,
     228,   229,   223,   406,   235,   406,    -1,   226,   223,   406,
      94,   406,    -1,   234,   117,   569,   233,   406,   185,   406,
      -1,   570,    -1,   569,   106,   117,   570,    -1,   638,   141,
     406,    -1,   242,   152,   405,   183,   572,    -1,   573,    -1,
     572,   573,    -1,   243,   575,   574,    -1,   152,   405,   183,
      -1,   495,    -1,   575,   208,   495,    -1,   579,   577,    -1,
      -1,   578,    -1,   597,    -1,   578,   597,    -1,   580,    -1,
     579,   260,   580,    -1,   581,    -1,   580,   256,   581,    -1,
     582,    -1,   581,   258,   146,   582,    -1,   583,    -1,   257,
     583,    -1,   587,   584,   585,    -1,    -1,   602,    -1,    -1,
     586,    -1,   280,   152,   405,   183,    -1,   591,   588,    -1,
     155,   576,   186,    -1,   589,    -1,    -1,   624,    -1,   482,
     152,   590,   183,    -1,    -1,   576,    -1,   592,   593,    -1,
     501,    -1,   152,   405,   183,    -1,    -1,   594,    -1,   246,
     595,    -1,   245,   596,    -1,   268,    -1,    -1,    78,    -1,
      -1,   284,    -1,   598,    -1,   599,    -1,   600,    -1,   626,
      -1,   623,    -1,   168,    -1,   282,   467,   601,    -1,   251,
     625,   601,    -1,   284,    -1,   274,    -1,   267,    -1,   244,
     603,    -1,   602,   244,   603,    -1,   604,    -1,   605,    -1,
     606,    -1,   621,    -1,   607,    -1,   615,    -1,   608,    -1,
     622,    -1,    99,   272,    -1,    99,   261,    -1,   264,    -1,
     279,    -1,   249,   272,    -1,   249,   261,    -1,    56,   638,
      29,    -1,   275,    -1,    54,   275,    -1,   277,   609,    -1,
     277,   155,   609,   610,   186,    -1,    54,   277,    -1,   612,
      -1,   112,    -1,    -1,   106,   611,    -1,   612,    -1,   611,
     106,   612,    -1,    96,    29,   613,   614,    -1,    -1,   269,
      29,    -1,    -1,   625,   263,    -1,   276,   284,   616,   618,
      -1,   276,   284,   112,   618,    -1,    54,   276,   284,    -1,
      96,    29,    -1,   155,   617,   186,    -1,    29,    -1,   617,
     106,    29,    -1,    -1,   619,    -1,   620,    -1,   619,   620,
      -1,   199,   616,    -1,   135,   616,    -1,   262,    29,    -1,
     281,    -1,    54,   281,    -1,    96,   215,    -1,    96,   252,
      -1,   253,   248,    -1,   265,   625,   278,    -1,   254,   467,
      -1,    96,   128,   467,    -1,    96,    52,   467,    -1,   255,
     467,   197,   467,    -1,   270,   627,    -1,   250,   627,    -1,
     273,    -1,   266,    -1,   283,   248,   469,    -1,   630,    -1,
     153,   184,    -1,   153,   405,   184,    -1,   632,    -1,   633,
      -1,   634,    -1,   635,    -1,   310,   155,   186,    -1,   311,
     155,   186,    -1,   309,   155,   186,    -1,   312,   155,   186,
      -1,    29,    -1,    16,    -1,   638,    -1,   639,    -1,    97,
      -1,    39,    -1,    44,    -1,    45,    -1,   151,    -1,    48,
      -1,   223,    -1,    59,    -1,    61,    -1,    62,    -1,    70,
      -1,    73,    -1,    72,    -1,   209,    -1,   241,    -1,   640,
      -1,    24,    -1,   213,    -1,   126,    -1,    38,    -1,   259,
      -1,    37,    -1,   220,    -1,   219,    -1,   145,    -1,    43,
      -1,   257,    -1,   258,    -1,   272,    -1,   261,    -1,   249,
      -1,   283,    -1,   275,    -1,   277,    -1,   276,    -1,   281,
      -1,   253,    -1,   248,    -1,    78,    -1,   215,    -1,   252,
      -1,    52,    -1,   221,    -1,   234,    -1,   300,    -1,   228,
      -1,   201,    -1,   206,    -1,   205,    -1,   204,    -1,   203,
      -1,   202,    -1,    96,    -1,   110,    -1,   111,    -1,   185,
      -1,    46,    -1,    36,    -1,    66,    -1,    71,    -1,    58,
      -1,    53,    -1,    55,    -1,    77,    -1,    42,    -1,   146,
      -1,    51,    -1,   210,    -1,   169,    -1,   170,    -1,   167,
      -1,    69,    -1,    95,    -1,   115,    -1,   127,    -1,   128,
      -1,   105,    -1,    67,    -1,   134,    -1,   187,    -1,    99,
      -1,    94,    -1,   196,    -1,   125,    -1,   166,    -1,    92,
      -1,    50,    -1,   229,    -1,   100,    -1,   197,    -1,   116,
      -1,   158,    -1,   199,    -1,   149,    -1,   135,    -1,    75,
      -1,    76,    -1,   101,    -1,   198,    -1,   150,    -1,   181,
      -1,   194,    -1,   159,    -1,   136,    -1,   130,    -1,   165,
      -1,   147,    -1,   164,    -1,    33,    -1,    40,    -1,    57,
      -1,   112,    -1,    41,    -1,    56,    -1,   214,    -1,    49,
      -1,    60,    -1,    34,    -1,    47,    -1,   271,    -1,   247,
      -1,   280,    -1,   282,    -1,   251,    -1,   265,    -1,   278,
      -1,   270,    -1,   250,    -1,   264,    -1,   279,    -1,   269,
      -1,   263,    -1,   262,    -1,   246,    -1,   245,    -1,   254,
      -1,   255,    -1,   284,    -1,   274,    -1,   273,    -1,   268,
      -1,   266,    -1,   267,    -1,   227,    -1,   233,    -1,   230,
      -1,   224,    -1,   217,    -1,   216,    -1,   218,    -1,   235,
      -1,   225,    -1,   226,    -1,   232,    -1,   222,    -1,   231,
      -1,    65,    -1,    63,    -1,    74,    -1,   168,    -1,   200,
      -1,   240,    -1,   238,    -1,   239,    -1,   236,    -1,   237,
      -1,   242,    -1,   243,    -1,   244,    -1,    64,    -1,   293,
      -1,   291,    -1,   292,    -1,   297,    -1,   298,    -1,   299,
      -1,   294,    -1,   295,    -1,   296,    -1,    79,    -1,    80,
      -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,    85,
      -1,    86,    -1,    87,    -1,    88,    -1,    89,    -1,   285,
      -1,   286,    -1,   287,    -1,   288,    -1,   289,    -1,   290,
      -1,   301,    -1,   302,    -1,   303,    -1,   304,    -1,   305,
      -1,   306,    -1,   307,    -1,    90,    -1,   104,    -1,   113,
      -1,   171,    -1,   179,    -1,   188,    -1,   137,    -1,    91,
      -1,   114,    -1,   138,    -1,   180,    -1,   311,    -1,   309,
      -1,   312,    -1,   310,    -1,   308,    -1,    25,    -1
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
    1948,  1950,  1954,  1958,  1960,  1962,  1964,  1966,  1970,  1972,
    1974,  1976,  1978,  1980,  1982,  1984,  1986,  1988,  1990,  1994,
    1998,  2003,  2008,  2012,  2016,  2020,  2025,  2030,  2034,  2039,
    2046,  2051,  2058,  2063,  2067,  2072,  2079,  2086,  2091,  2098,
    2105,  2110,  2112,  2115,  2117,  2119,  2121,  2125,  2129,  2131,
    2133,  2138,  2144,  2151,  2155,  2159,  2163,  2167,  2173,  2181,
    2189,  2195,  2201,  2207,  2215,  2223,  2229,  2235,  2239,  2243,
    2249,  2257,  2263,  2271,  2273,  2278,  2282,  2288,  2290,  2293,
    2297,  2301,  2303,  2307,  2310,  2311,  2313,  2315,  2318,  2320,
    2324,  2326,  2330,  2332,  2337,  2339,  2342,  2346,  2347,  2349,
    2350,  2352,  2357,  2360,  2364,  2366,  2367,  2369,  2374,  2375,
    2377,  2380,  2382,  2386,  2387,  2389,  2392,  2395,  2397,  2398,
    2400,  2401,  2403,  2405,  2407,  2409,  2411,  2413,  2415,  2419,
    2423,  2425,  2427,  2429,  2432,  2436,  2438,  2440,  2442,  2444,
    2446,  2448,  2450,  2452,  2455,  2458,  2460,  2462,  2465,  2468,
    2472,  2474,  2477,  2480,  2486,  2489,  2491,  2493,  2494,  2497,
    2499,  2503,  2508,  2509,  2512,  2513,  2516,  2521,  2526,  2530,
    2533,  2537,  2539,  2543,  2544,  2546,  2548,  2551,  2554,  2557,
    2560,  2562,  2565,  2568,  2571,  2574,  2578,  2581,  2585,  2589,
    2594,  2597,  2600,  2602,  2604,  2608,  2610,  2613,  2617,  2619,
    2621,  2623,  2625,  2629,  2633,  2637,  2641,  2643,  2645,  2647,
    2649,  2651,  2653,  2655,  2657,  2659,  2661,  2663,  2665,  2667,
    2669,  2671,  2673,  2675,  2677,  2679,  2681,  2683,  2685,  2687,
    2689,  2691,  2693,  2695,  2697,  2699,  2701,  2703,  2705,  2707,
    2709,  2711,  2713,  2715,  2717,  2719,  2721,  2723,  2725,  2727,
    2729,  2731,  2733,  2735,  2737,  2739,  2741,  2743,  2745,  2747,
    2749,  2751,  2753,  2755,  2757,  2759,  2761,  2763,  2765,  2767,
    2769,  2771,  2773,  2775,  2777,  2779,  2781,  2783,  2785,  2787,
    2789,  2791,  2793,  2795,  2797,  2799,  2801,  2803,  2805,  2807,
    2809,  2811,  2813,  2815,  2817,  2819,  2821,  2823,  2825,  2827,
    2829,  2831,  2833,  2835,  2837,  2839,  2841,  2843,  2845,  2847,
    2849,  2851,  2853,  2855,  2857,  2859,  2861,  2863,  2865,  2867,
    2869,  2871,  2873,  2875,  2877,  2879,  2881,  2883,  2885,  2887,
    2889,  2891,  2893,  2895,  2897,  2899,  2901,  2903,  2905,  2907,
    2909,  2911,  2913,  2915,  2917,  2919,  2921,  2923,  2925,  2927,
    2929,  2931,  2933,  2935,  2937,  2939,  2941,  2943,  2945,  2947,
    2949,  2951,  2953,  2955,  2957,  2959,  2961,  2963,  2965,  2967,
    2969,  2971,  2973,  2975,  2977,  2979,  2981,  2983,  2985,  2987,
    2989,  2991,  2993,  2995,  2997,  2999,  3001,  3003,  3005,  3007,
    3009,  3011,  3013,  3015,  3017,  3019,  3021,  3023,  3025,  3027,
    3029,  3031,  3033,  3035,  3037,  3039,  3041,  3043,  3045,  3047,
    3049,  3051,  3053,  3055,  3057,  3059,  3061,  3063,  3065,  3067,
    3069,  3071,  3073,  3075,  3077,  3079,  3081,  3083,  3085,  3087
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1032,  1032,  1033,  1042,  1051,  1057,  1065,  1071,  1082,
    1087,  1095,  1102,  1109,  1118,  1125,  1133,  1141,  1149,  1160,
    1165,  1172,  1179,  1191,  1201,  1208,  1215,  1227,  1228,  1229,
    1230,  1231,  1236,  1237,  1238,  1239,  1240,  1241,  1242,  1245,
    1250,  1255,  1263,  1271,  1279,  1284,  1292,  1297,  1305,  1310,
    1318,  1325,  1332,  1339,  1349,  1351,  1354,  1364,  1369,  1377,
    1385,  1396,  1403,  1414,  1419,  1427,  1434,  1441,  1450,  1463,
    1471,  1478,  1488,  1495,  1502,  1513,  1514,  1515,  1516,  1517,
    1518,  1519,  1520,  1525,  1531,  1540,  1547,  1557,  1567,  1568,
    1569,  1570,  1571,  1572,  1573,  1574,  1575,  1576,  1581,  1589,
    1597,  1605,  1612,  1620,  1627,  1632,  1640,  1648,  1663,  1678,
    1696,  1701,  1709,  1717,  1728,  1733,  1742,  1747,  1754,  1759,
    1769,  1774,  1783,  1789,  1802,  1807,  1815,  1826,  1841,  1853,
    1868,  1873,  1878,  1883,  1891,  1898,  1909,  1914,  1924,  1931,
    1938,  1945,  1955,  1959,  1969,  1977,  1988,  1994,  2003,  2008,
    2015,  2022,  2033,  2043,  2053,  2063,  2081,  2101,  2105,  2110,
    2117,  2121,  2126,  2133,  2138,  2150,  2157,  2169,  2170,  2171,
    2172,  2173,  2174,  2175,  2177,  2178,  2179,  2180,  2181,  2186,
    2191,  2199,  2216,  2224,  2232,  2239,  2246,  2256,  2268,  2281,
    2293,  2309,  2317,  2325,  2333,  2348,  2353,  2361,  2375,  2392,
    2417,  2425,  2432,  2443,  2453,  2458,  2473,  2474,  2475,  2476,
    2477,  2478,  2483,  2484,  2487,  2488,  2489,  2490,  2491,  2496,
    2510,  2518,  2523,  2531,  2536,  2541,  2549,  2558,  2570,  2580,
    2593,  2601,  2602,  2603,  2608,  2609,  2610,  2611,  2612,  2617,
    2624,  2634,  2642,  2649,  2659,  2669,  2679,  2689,  2699,  2709,
    2719,  2729,  2740,  2749,  2759,  2769,  2785,  2794,  2803,  2811,
    2817,  2829,  2837,  2847,  2855,  2867,  2873,  2884,  2886,  2890,
    2898,  2902,  2907,  2911,  2915,  2919,  2929,  2937,  2944,  2950,
    2961,  2965,  2974,  2982,  2988,  2998,  3004,  3014,  3018,  3028,
    3034,  3040,  3046,  3055,  3064,  3073,  3086,  3090,  3098,  3104,
    3114,  3122,  3131,  3144,  3151,  3163,  3167,  3179,  3186,  3192,
    3201,  3208,  3214,  3225,  3232,  3238,  3247,  3256,  3263,  3274,
    3281,  3293,  3299,  3311,  3317,  3328,  3334,  3345,  3351,  3362,
    3371,  3375,  3384,  3388,  3396,  3400,  3410,  3417,  3426,  3436,
    3435,  3449,  3458,  3467,  3480,  3484,  3497,  3500,  3507,  3511,
    3518,  3522,  3530,  3534,  3538,  3546,  3550,  3556,  3562,  3568,
    3578,  3582,  3586,  3594,  3598,  3604,  3614,  3618,  3628,  3632,
    3642,  3646,  3656,  3660,  3670,  3674,  3682,  3686,  3690,  3694,
    3704,  3708,  3712,  3720,  3724,  3728,  3732,  3736,  3740,  3748,
    3752,  3756,  3764,  3768,  3772,  3776,  3787,  3793,  3803,  3809,
    3819,  3823,  3827,  3865,  3869,  3879,  3889,  3902,  3911,  3921,
    3925,  3934,  3938,  3947,  3953,  3961,  3967,  3979,  3985,  3995,
    3999,  4003,  4007,  4011,  4017,  4023,  4031,  4035,  4043,  4047,
    4058,  4062,  4066,  4072,  4076,  4090,  4094,  4102,  4106,  4116,
    4120,  4124,  4128,  4137,  4141,  4145,  4149,  4157,  4163,  4173,
    4181,  4185,  4189,  4193,  4197,  4201,  4205,  4209,  4213,  4217,
    4221,  4229,  4233,  4241,  4248,  4255,  4266,  4274,  4278,  4286,
    4294,  4302,  4356,  4360,  4373,  4379,  4389,  4393,  4401,  4405,
    4409,  4417,  4427,  4437,  4447,  4457,  4467,  4482,  4488,  4499,
    4505,  4516,  4527,  4529,  4533,  4538,  4548,  4551,  4558,  4564,
    4570,  4578,  4591,  4594,  4601,  4607,  4613,  4620,  4631,  4635,
    4645,  4649,  4659,  4663,  4667,  4672,  4681,  4687,  4693,  4699,
    4707,  4712,  4720,  4725,  4733,  4741,  4746,  4751,  4756,  4761,
    4766,  4775,  4783,  4787,  4804,  4808,  4816,  4824,  4832,  4836,
    4844,  4850,  4860,  4868,  4872,  4876,  4911,  4917,  4923,  4933,
    4937,  4941,  4945,  4949,  4953,  4957,  4964,  4970,  4980,  4988,
    4992,  4996,  5000,  5004,  5008,  5012,  5016,  5020,  5028,  5036,
    5040,  5044,  5054,  5062,  5070,  5074,  5078,  5086,  5090,  5096,
    5102,  5106,  5116,  5124,  5128,  5134,  5143,  5152,  5158,  5164,
    5174,  5191,  5198,  5213,  5249,  5253,  5261,  5269,  5281,  5285,
    5293,  5301,  5305,  5316,  5333,  5339,  5345,  5355,  5359,  5365,
    5371,  5375,  5381,  5385,  5391,  5397,  5404,  5414,  5419,  5427,
    5433,  5443,  5465,  5474,  5480,  5493,  5507,  5514,  5520,  5530,
    5539,  5547,  5553,  5571,  5580,  5583,  5590,  5595,  5603,  5607,
    5614,  5618,  5625,  5629,  5636,  5640,  5649,  5662,  5665,  5673,
    5676,  5684,  5692,  5700,  5704,  5712,  5715,  5723,  5735,  5738,
    5746,  5758,  5764,  5774,  5777,  5785,  5789,  5793,  5801,  5804,
    5812,  5815,  5823,  5827,  5831,  5835,  5839,  5847,  5855,  5867,
    5879,  5883,  5887,  5895,  5901,  5911,  5915,  5919,  5923,  5927,
    5931,  5935,  5939,  5947,  5951,  5955,  5959,  5967,  5973,  5983,
    5993,  5997,  6005,  6015,  6026,  6033,  6037,  6045,  6048,  6055,
    6060,  6069,  6079,  6082,  6089,  6093,  6101,  6110,  6117,  6127,
    6131,  6138,  6144,  6154,  6157,  6164,  6169,  6181,  6189,  6201,
    6209,  6213,  6221,  6225,  6229,  6237,  6245,  6249,  6253,  6257,
    6265,  6273,  6285,  6289,  6297,  6306,  6314,  6318,  6326,  6331,
    6336,  6341,  6349,  6356,  6363,  6371,  6384,  6388,  6389,  6402,
    6403,  6404,  6405,  6406,  6407,  6408,  6409,  6410,  6411,  6412,
    6413,  6414,  6415,  6416,  6417,  6421,  6422,  6423,  6424,  6425,
    6426,  6427,  6428,  6429,  6430,  6431,  6432,  6433,  6434,  6435,
    6436,  6437,  6438,  6439,  6440,  6441,  6442,  6443,  6444,  6445,
    6446,  6447,  6448,  6449,  6450,  6451,  6452,  6453,  6454,  6455,
    6456,  6457,  6458,  6459,  6460,  6461,  6462,  6463,  6464,  6465,
    6466,  6467,  6468,  6469,  6470,  6471,  6472,  6473,  6474,  6475,
    6476,  6477,  6478,  6479,  6480,  6481,  6482,  6483,  6484,  6485,
    6486,  6487,  6488,  6489,  6490,  6491,  6492,  6493,  6494,  6495,
    6496,  6497,  6498,  6499,  6500,  6501,  6502,  6503,  6504,  6505,
    6506,  6507,  6508,  6509,  6510,  6511,  6512,  6513,  6514,  6515,
    6516,  6517,  6518,  6519,  6520,  6521,  6522,  6523,  6524,  6525,
    6526,  6527,  6528,  6529,  6530,  6531,  6532,  6533,  6534,  6535,
    6536,  6537,  6538,  6539,  6540,  6541,  6542,  6543,  6544,  6545,
    6546,  6547,  6548,  6549,  6550,  6551,  6552,  6553,  6554,  6555,
    6556,  6557,  6558,  6559,  6560,  6561,  6562,  6563,  6564,  6565,
    6566,  6567,  6568,  6569,  6570,  6571,  6572,  6573,  6574,  6575,
    6576,  6577,  6578,  6579,  6580,  6581,  6582,  6583,  6584,  6585,
    6586,  6587,  6588,  6589,  6590,  6591,  6592,  6593,  6594,  6595,
    6596,  6597,  6598,  6599,  6600,  6601,  6602,  6603,  6604,  6605,
    6606,  6607,  6608,  6609,  6610,  6611,  6612,  6613,  6614,  6615,
    6616,  6617,  6618,  6619,  6620,  6621,  6622,  6623,  6624,  6629
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
  const int xquery_parser::yylast_ = 13759;
  const int xquery_parser::yynnts_ = 314;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 579;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 327;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 581;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 16462 "/home/jsoniq/zorba/debug/src/compiler/parser/xquery_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 6633 "/home/jsoniq/zorba/sandbox/src/compiler/parser/xquery_parser.y"


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

