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
#line 87 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"


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
#line 77 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 894 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 299 of lalr1.cc  */
#line 999 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 299 of lalr1.cc  */
#line 107 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"

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
#line 193 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"

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
#line 892 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 298 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 123: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 891 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 307 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 148: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 316 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 325 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 334 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 343 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 352 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 361 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 370 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 379 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 388 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 397 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 406 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 415 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 424 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 433 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 442 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 451 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 460 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 469 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 478 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 487 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 496 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 505 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 514 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 523 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 532 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 541 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 550 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 559 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 568 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 577 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 586 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 595 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 604 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 613 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 622 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 631 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 640 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 649 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 658 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 667 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 676 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 685 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 694 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 703 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 712 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 721 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 730 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 739 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 748 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 757 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 766 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 775 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 784 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 793 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 802 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 811 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 820 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 829 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 838 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 856 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 865 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 883 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 892 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 901 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 910 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 919 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 928 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 937 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 946 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 955 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 964 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 973 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 982 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 991 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1000 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1009 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1018 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1027 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1036 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1045 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1054 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1063 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1072 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1081 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1090 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1099 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1108 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1117 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1126 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1135 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1144 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1153 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1162 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1171 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1180 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1189 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1198 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1207 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1216 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1225 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1234 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1243 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1252 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1261 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1270 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1279 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1288 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1297 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1306 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1315 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1324 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1333 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1342 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1351 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1360 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1369 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1378 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1387 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1396 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1405 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1414 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1423 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1432 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1441 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1450 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1459 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1468 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1477 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1486 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1495 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1504 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1513 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1522 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1531 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1540 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1549 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1558 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1567 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1576 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1585 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1594 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1603 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1612 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1621 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1630 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1639 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1648 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1657 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1666 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1675 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1684 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1693 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1702 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1711 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1720 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1729 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1738 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1747 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1756 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1765 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1774 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1783 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1792 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1801 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1810 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1819 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1828 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1837 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1846 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1855 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1864 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1873 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1882 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1891 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1900 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1918 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1927 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1936 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1945 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1954 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1963 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1972 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1981 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1990 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1999 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2008 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2017 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2026 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2035 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2044 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2053 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2062 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2071 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2080 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2089 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2098 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2107 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2116 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2125 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2134 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2143 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2152 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2161 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2170 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2179 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2188 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2197 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2206 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2215 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2224 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2233 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2242 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2251 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2260 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2269 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2278 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2287 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2296 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2305 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2314 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2323 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2332 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2341 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2350 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2359 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2368 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2377 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2386 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2395 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2404 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2413 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2422 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2431 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2440 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2449 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2458 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2467 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2476 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2485 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2494 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2503 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2512 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2521 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2530 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2539 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2548 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2557 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2566 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2575 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 615: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2584 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2593 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2602 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2611 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 622: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2620 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 623: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2629 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 624: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2638 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 625: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2647 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 626: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2656 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 627: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2665 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2674 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 631: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2683 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 632: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2692 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 633: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2701 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
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
#line 140 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 565 of lalr1.cc  */
#line 2798 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"

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
#line 1017 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 1026 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 1035 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 1041 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 1049 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 1055 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 1066 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 1071 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 1079 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 1086 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 1093 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 1102 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 1109 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 1117 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 1125 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 1133 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 1144 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 1149 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 1156 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 1163 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 1175 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 1185 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 1192 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 1199 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1234 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 1239 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 1247 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 1255 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 1263 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 1268 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 1276 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1281 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1289 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1294 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1302 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1309 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1316 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1323 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1338 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1348 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 1353 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 1361 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 1369 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 1380 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1387 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1398 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1403 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1411 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1418 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1425 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1434 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1447 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1455 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1462 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1472 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 1479 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1486 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 1509 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 1515 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 1524 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 1531 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1541 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1550 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1551 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1552 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1553 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1554 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1555 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1556 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1557 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1558 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1559 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1565 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1573 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1581 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1589 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1596 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1604 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1611 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1616 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1624 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1632 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1647 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1662 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1680 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1685 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1693 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1701 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 1712 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1717 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1726 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1731 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1738 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1743 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1753 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1758 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1767 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1773 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1786 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1791 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1799 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1810 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1825 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1837 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1852 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1857 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1862 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1867 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1875 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1882 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1893 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1898 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1908 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1915 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1922 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1929 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1939 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1943 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1953 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1961 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1972 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1978 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1987 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1992 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1999 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 2006 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 2018 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2028 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2038 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2049 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2065 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2085 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 2090 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 2094 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 2102 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 2107 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 2111 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 2119 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 2124 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 2136 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 2143 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 2172 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 2177 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 2185 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2202 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 2210 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 2218 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 2225 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 2232 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 2242 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2254 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2267 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2279 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2295 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 2303 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 2311 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 2319 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2334 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 2339 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 2347 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2361 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2378 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2403 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2411 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 2418 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2429 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 2439 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 2444 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2482 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2496 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 2504 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 2509 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 2517 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 2522 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 2527 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 2535 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2544 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2556 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2566 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2579 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2603 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2610 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2620 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 2628 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 2635 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 2645 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2655 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2665 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2675 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2685 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2695 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2705 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2715 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2726 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2735 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2745 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2755 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2771 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2780 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2789 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2797 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2803 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2815 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2823 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2833 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2841 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2853 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 2859 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 2872 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 2876 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 2884 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 2888 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2897 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2901 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2905 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2915 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2923 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2930 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2936 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2947 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2951 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2960 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2968 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2974 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2984 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2990 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 3000 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 3004 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 3014 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 3020 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 3026 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 3032 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3041 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3050 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3059 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3072 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 3076 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 3084 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 3090 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 3100 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 3108 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3117 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3130 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 3137 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 3149 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 3153 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 3165 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 3172 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 3178 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 3187 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 3194 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 3200 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 3211 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 3218 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 3224 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 3233 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 3242 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 3249 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3260 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 3267 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3279 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 3285 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 3297 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 3303 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 3314 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 3320 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 3331 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 3337 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 3348 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 3357 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 3361 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 3370 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 3374 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 3382 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 3386 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3396 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 3403 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3412 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3421 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 3426 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3435 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3444 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3453 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3466 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 3470 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3482 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 3486 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 3493 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 3497 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 3506 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 3510 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 3514 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 3523 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 3527 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3533 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3539 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3545 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 3556 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3560 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 3564 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 3572 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3576 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 3582 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 3592 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 3596 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 3606 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3610 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 368:

/* Line 690 of lalr1.cc  */
#line 3620 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3624 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3634 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3638 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3648 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3652 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3660 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3664 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3668 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3672 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3682 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3686 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3690 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3698 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3702 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3706 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3710 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3714 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3718 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3726 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3730 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3734 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3742 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3746 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3750 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3754 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3765 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3771 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3781 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3787 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3797 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3801 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3805 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3843 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3847 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3857 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3867 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3880 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3889 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 407:

/* Line 690 of lalr1.cc  */
#line 3899 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3903 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3912 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3916 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3925 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3931 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3939 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3945 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3957 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3963 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3973 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3977 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3981 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3985 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3989 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3995 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 4001 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 4009 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 4013 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 4021 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 4025 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 4036 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 4040 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 4044 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 4050 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 4054 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 4068 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 4072 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 4080 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 4084 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 4094 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 4098 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 4102 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 4106 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 4115 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 4119 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 4123 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 4127 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 4135 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 4141 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 4151 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 4159 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 4163 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 4167 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 4171 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 4175 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 4179 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 4183 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 4187 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 4191 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 4201 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 4215 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 4219 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 4227 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 4234 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 4241 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 4252 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 4260 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 4264 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 4272 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 4280 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 4288 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 4342 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 4346 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 4359 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 4365 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 4375 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 4379 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 4387 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 4391 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 4395 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 4403 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 479:

/* Line 690 of lalr1.cc  */
#line 4413 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 480:

/* Line 690 of lalr1.cc  */
#line 4423 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 481:

/* Line 690 of lalr1.cc  */
#line 4433 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 482:

/* Line 690 of lalr1.cc  */
#line 4443 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 483:

/* Line 690 of lalr1.cc  */
#line 4453 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 484:

/* Line 690 of lalr1.cc  */
#line 4468 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 4474 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 4485 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 4491 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 4502 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 4519 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 4524 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 4533 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 4537 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 4544 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 4550 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 4556 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 4564 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 4576 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 4580 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 4587 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 4593 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 4599 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 4606 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 4617 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 4621 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 4631 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 4635 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 4645 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 4649 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 4653 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 4658 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 4667 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 4673 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 4679 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 4685 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 4693 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 4698 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 4706 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 4711 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 4719 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 4727 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 4732 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 4737 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 4742 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 4747 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 4752 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 4761 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 4769 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 4773 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 4790 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 4794 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 4802 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 4810 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 4818 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 4822 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 4830 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 4836 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 4846 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 4854 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 4858 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 4862 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 4897 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 4903 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 4909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 4919 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 4923 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 4927 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 4931 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 4935 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 4942 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 4948 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 4958 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 4966 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 4970 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 4974 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 4978 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 4982 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 4986 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 4990 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 4994 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 4998 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 5006 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 5014 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 5018 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 5022 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 5032 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 5040 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 5048 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 5052 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 5056 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 5064 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 5068 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 5074 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 5080 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 5084 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 5094 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 5102 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 5106 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 5112 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 5121 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 5130 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 5136 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 5142 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 5152 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 5169 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 5176 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 5191 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 5227 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 5231 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 5239 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 5247 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 5259 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 5263 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 5271 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 5279 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 5283 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 5294 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 5311 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 5317 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 5323 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 5333 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 5337 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 5343 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 5349 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 5353 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 5359 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 5363 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 5369 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 5375 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 5382 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 5392 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 5397 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 5405 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 5411 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 5421 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 5443 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 5452 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 5458 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 5471 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 5485 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 5492 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 5498 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 5508 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 5517 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 5525 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 5531 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 5549 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 5557 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 5561 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 5568 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 5573 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 5581 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 5585 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 5592 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 5596 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 5603 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 5607 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 5614 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 5618 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 5627 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 5639 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 5643 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 5650 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 5654 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 5662 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 5670 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 5678 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 5682 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 5689 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 5693 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 5701 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 5712 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 5716 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 5724 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 5736 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 5742 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 5751 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 5755 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 5763 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 5767 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 5771 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 5778 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 5782 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 5789 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 5793 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 5801 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 5805 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 5809 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 5813 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 5817 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 5825 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 5833 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 5845 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 5857 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 5861 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 5865 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 5873 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 5879 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 5889 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 5893 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 5897 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 5901 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 5905 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 5909 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 5913 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 5917 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 5925 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 5929 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 5933 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 5937 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 5945 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 5951 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 5961 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 5971 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 5975 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 5983 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 698:

/* Line 690 of lalr1.cc  */
#line 5993 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 699:

/* Line 690 of lalr1.cc  */
#line 6004 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 6011 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 6015 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 6022 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 6026 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 6033 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 6038 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 6047 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 6056 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 6060 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 6067 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 6071 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 6079 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 6088 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 6095 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 6105 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 6109 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 6116 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 6122 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 6131 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 6135 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 6142 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 6147 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 6159 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 6167 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 6179 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 6187 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 6191 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 6199 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 6203 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 6207 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 6215 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 6223 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 6227 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 6231 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 6235 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 6243 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 6251 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 6263 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 6267 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 6275 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 6365 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 744:

/* Line 690 of lalr1.cc  */
#line 6378 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 6379 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 6380 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 6381 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 6382 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 6383 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 6384 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 6385 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 6386 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 6387 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 6388 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 6389 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 6390 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 6391 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 6392 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 6397 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 6398 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 6399 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 6400 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 6401 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 6402 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 6403 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 6404 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 6405 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 6406 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 6407 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 6408 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 6409 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 6410 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 6411 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 6412 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 6413 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 6414 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 6415 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 6416 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 6417 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 6418 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 6419 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 6420 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 6421 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 6422 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 6423 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 6424 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 6425 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 789:

/* Line 690 of lalr1.cc  */
#line 6426 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 6427 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 791:

/* Line 690 of lalr1.cc  */
#line 6428 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 792:

/* Line 690 of lalr1.cc  */
#line 6429 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 793:

/* Line 690 of lalr1.cc  */
#line 6430 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 6431 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 6432 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 796:

/* Line 690 of lalr1.cc  */
#line 6433 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 6434 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 798:

/* Line 690 of lalr1.cc  */
#line 6435 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 6436 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 6437 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 6438 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 802:

/* Line 690 of lalr1.cc  */
#line 6439 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 803:

/* Line 690 of lalr1.cc  */
#line 6440 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 6441 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 805:

/* Line 690 of lalr1.cc  */
#line 6442 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 6443 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 6444 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 6445 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 6446 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 6447 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 6448 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 6449 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 6450 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 6451 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 6452 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 6453 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 6454 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 6455 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 6456 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 6457 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 6458 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 6459 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 6460 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 6461 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 6462 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 6463 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 6464 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 6465 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 6466 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 6467 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 6468 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 6469 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 6470 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 6471 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 6472 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 6473 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 6474 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 6475 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 6476 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 6477 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 6478 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 6479 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 6480 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 6481 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 6482 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 6483 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 6484 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 6485 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 6486 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 6487 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 6488 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 6489 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 6490 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 6491 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 6492 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 6493 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 6494 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 6495 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 6496 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 6497 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 6498 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 6499 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 6500 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 6501 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 6502 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 6503 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 6504 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 6505 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 6506 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 6507 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 6508 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 6509 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 6510 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 6511 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 6512 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 6513 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 6514 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 6515 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 6516 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 6517 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 6518 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 6519 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 6520 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 6521 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 6522 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 6523 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 6524 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 6525 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 6526 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 6527 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 6528 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 6529 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 6530 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 6531 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 6532 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 6533 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 6534 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 6535 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 6536 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 6537 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 6538 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 6539 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 6540 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 6541 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 6542 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 6543 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 6544 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 6545 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 6546 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 6547 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 6548 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 6549 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 6550 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 6551 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 6552 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 6553 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 6554 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 6555 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 6556 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 6557 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 6558 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 6559 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 6560 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 6561 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 6562 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 6563 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 6564 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 6565 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 6566 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 6567 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 6568 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 6569 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 6570 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 6571 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 6572 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 6573 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 6574 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 6575 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 6576 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 6577 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 6578 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 6579 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 6580 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 6581 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 6582 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 6583 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 6584 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 6585 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 6586 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 6587 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 6588 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 6589 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 6590 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 6591 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 6592 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 6593 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 6594 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 6600 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          // EQName's namespace URI value is whitespace normalized according to the rules for the xs:anyURI type
          std::string uri = "\"" + SYMTAB((yysemantic_stack_[(3) - (1)].sval)) + "\"";
          std::string eqname = SYMTAB(driver.symtab.put_uri(uri.c_str(), uri.size())) + ":" + SYMTAB((yysemantic_stack_[(3) - (3)].sval));
          (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT(eqname.c_str())), true);
        }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 6606 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 11537 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1394;
  const short int
  xquery_parser::yypact_[] =
  {
      2898, -1394, -1394, -1394,  4383,  4383,  4383, -1394, -1394,   198,
     260,   200,    30,   410, -1394, -1394, -1394,   594, -1394, -1394,
   -1394,   386,   439,   612,   556,   476,   558,   328, -1394,   -32,
   -1394, -1394, -1394, -1394, -1394, -1394,   696, -1394,   573,   587,
   -1394, -1394, -1394, -1394,   662, -1394,   734, -1394,   644,   679,
   -1394,    15, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394,   748,   755, -1394, -1394,
   -1394, -1394,   543,  8838, -1394, -1394, -1394,   759, -1394, -1394,
   -1394,   700, -1394,   771,   783, -1394, -1394, 12565, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394,   793, -1394, -1394,   794,
     806, -1394, -1394, -1394, -1394, -1394, -1394, -1394,  3195,  6165,
   12565, -1394, -1394, -1394, -1394, -1394, -1394, -1394,   781, -1394,
   -1394,   816,  9719, -1394, 10009,   820,   821, -1394, -1394, -1394,
     835, -1394,  8541, -1394, -1394, -1394, -1394, -1394, -1394,   805,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,    39,   745,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,   668,   807,
     675, -1394,   737,   593, -1394, -1394, -1394, -1394, -1394, -1394,
     844, -1394,   724,   725,   726, -1394, -1394,   812,   817, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394,  4680,   968, -1394,  4977, -1394, -1394,   120,    77,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394,    79, -1394, -1394, -1394, -1394, -1394,
   -1394,   311, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
    4383, -1394, -1394, -1394, -1394,    27, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394,   864, -1394,   782, -1394, -1394, -1394,
     501, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,   808,
     880, -1394,   870,   728,   475,   259,   -20,   516, -1394,   923,
     778,   877,   879,  7353, -1394, -1394, -1394,   447, -1394, -1394,
    8541, -1394,   650, -1394,   825,  8838, -1394,   825,  8838, -1394,
   -1394, -1394,   742, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394,   861,   838,   829, -1394, -1394,
   -1394, -1394, -1394,   802, -1394,  4383,   803,   813,   322,   322,
     959,   -16,   224,   169, 12849, 12565,   286,   942, 12565,   839,
     874,   269,  9719,   699,   753, 12565, 12565,   697,   682,    47,
   -1394, -1394, -1394,  9719,  4383,   814,  4383,   118,  7650, 10577,
     721,   722, 12565,   885,    -3,   853,  7650,  1006,   125,    78,
   12565,   891,   872,   908, -1394,  7650,  9427, 12565, 12565, 12565,
    4383,   831,  7650,  7650, 12565,  4383,   863,   867, -1394, -1394,
   -1394,  7650, 10861, -1394,   868, -1394,   878, -1394, -1394, -1394,
   -1394,   881, -1394,   882, -1394, -1394, -1394, -1394, -1394,   883,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, 12565, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
     884, 12565, -1394, -1394, -1394,   846,  3492,   890,   892,   898,
   12565,  4383, -1394,   869,   197, -1394,   507,   987,  7650, -1394,
   -1394,    73, -1394, -1394, -1394,  1015, -1394, -1394, -1394, -1394,
    7650,   822, -1394,  1011,  7650,  7650,   871,  7650,  7650,  7650,
    7650,   826, 12565,   865,   873,  7650,  7650,  3195,   815, -1394,
   -1394, -1394, -1394,    30,   328,    83,    87,  1053,  5274,  5274,
    5571,  5571,   700, -1394, -1394,   864,   700, -1394,  7650, -1394,
     943,   556,   -32,   894,   895,   896,  4383,  7650, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394,  7947,  7947,  7947, -1394,
    7947,  7947, -1394,  7947, -1394,  7947, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394,  7947,  7947,   989,  7947,  7947,  7947,  7947,
    7947,  7947,  7947,  7947,  7947,  7947,  7947,   834,   972,   973,
     974, -1394, -1394, -1394,  6462, -1394, -1394,  8541,  8541,  7650,
     825, -1394, -1394,   825, -1394,  6759,   825,  9719,   921,  7056,
   -1394, -1394, -1394, -1394,   199, -1394,   239, -1394, -1394, -1394,
   -1394, -1394,   964,   971,   476,  1050, -1394, -1394, 12849,   866,
     372, 12565,   922,   924,   866,   959,   954,   953, -1394, -1394,
   -1394,   165,   841,   992,   790, 12565,   947,  7650,   975, 12565,
   12565, -1394,   958,   907,  4383, -1394,   911,   878,   587, -1394,
     905,   909,    32, -1394,   249,   267, -1394, -1394,   990, -1394,
      24, 12565,    10, 12565,  1003,   288, -1394,  4383, -1394,   296,
   -1394,  9719,  1002,  1055,  9719,   959,  1005,    41, 12565,  7650,
     -32,   412,   917, -1394,   918,   919,   920,     9, -1394,   264,
     925, -1394,   301,   310,   955, -1394,   926,  4383,  4383,   423,
   -1394,   317,   341,   431,  7650,    43, -1394, -1394,  7650,  7650,
    7650, -1394,  7650, -1394,  7650, 12565,   987, -1394,    22,   429,
   -1394, -1394, -1394,   442, -1394,    18, -1394, -1394, -1394,   110,
     112,  1016,   876,   889,    13, -1394,   976, -1394, -1394,   927,
     342,  3789,   451,  9135,   815, -1394,   120,   657,  1080,  1080,
   -1394, -1394,    88, -1394, -1394,    92, -1394,    16, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, 12565,   945,  7650,   998, -1394,
   -1394, -1394,   880, -1394, -1394, -1394, -1394, -1394,  7947, -1394,
   -1394, -1394,    50,   259,   259,   546,   -20,   -20,   -20,   -20,
     516,   516, -1394, -1394, 11997, 11997, 12565, 12565, -1394,   471,
   -1394, -1394,    11, -1394, -1394, -1394,   365, -1394, -1394, -1394,
     398,   322, -1394, -1394,    21,   550,   586, -1394,   476, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,   866,
   -1394,   988, 12281,   977,  7650, -1394, -1394, -1394,  1026,   959,
     959,   866, -1394,   733,   959,   590, 12565,  -115,   524,  1092,
   -1394, -1394,   840,   523, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394,   165,   274,   897,   529,  7650,
   -1394, 12565,  1031,   830,   959, -1394, -1394, -1394, -1394,   978,
   12565, -1394, 12565, -1394,  1009,  1007, 11997,  1012,  7650,   -33,
     982,    26,   326,   886, -1394, -1394,   643,    10,  1026, 11997,
    1014,  1038,   951,   939,  1008,   959,   981,  1010,  1040,   959,
    7650,    19, -1394, -1394, -1394,   985, -1394, -1394, -1394, -1394,
    1025,  7650,  7650,   997, -1394,  1046,  1047,  4383, -1394,   967,
     970,   995, 12565, -1394, 12565, -1394,  7650,  1013,   962,  7650,
     404,   405,   406,  1120, -1394,   217, -1394,   514, -1394, -1394,
    1127, -1394,   681,  7650,  7650,  7650,   684,  7650,  7650,  7650,
    7650,  7650,  7650,  1041,  7650,  7650, -1394,  5868,  1004,  1017,
    1018,  1022,   782,   559,   914, -1394,   -22, -1394,    96,   171,
      16,  5571,  5571,  5571,  1081, -1394,  7650,   677,  1056, -1394,
   12565,  1057, -1394, -1394,  7650,    50,   245,   491, -1394,   887,
     126,   912,   903, -1394, -1394,   753, -1394,   902,   509,  1020,
    1021, 12281,  1023, -1394,   428, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394,  1034, -1394, -1394, -1394,  7650, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,   598, -1394,
    1140,   695, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394,   899, -1394, -1394,  1151, -1394, -1394, -1394, -1394, -1394,
     588,  1152, -1394,   693, -1394, -1394, -1394,   868,   439,   881,
     573,   882,   883,   807, -1394,   428,  8244,   900,   888, -1394,
    1026,   274,   957,   999,  4383,  1000,  1024,  1048,  1027,  1029,
   12565,   347, -1394, 12565, -1394,  7650,  1043,  7650,  1058,  7650,
      29,  1051,  7650,  1054, -1394,  1076,  1077,  7650, 12565,   789,
    1119, -1394, -1394, -1394, -1394, -1394, -1394, 11997, -1394,  4383,
     959,  1093, -1394, -1394, -1394,   959,  1093, -1394,  7650,  1060,
    4383, 12565, -1394, -1394,  7650,  7650,   625, -1394,    51,   672,
   -1394, 11145,   694, -1394,   698, -1394,  1028, -1394, -1394,  4383,
    1030,  1032, -1394,  7650, -1394, -1394,  1035,  1046,  1104, -1394,
    1073, -1394,   639, -1394, -1394,  1199, -1394, -1394,  4383, 12565,
   -1394,   646, -1394, -1394, -1394,  1019,   991,   993, -1394, -1394,
   -1394,   994,   996, -1394, -1394, -1394, -1394, -1394,   984, 12565,
    1036, -1394, -1394,  7650,  7650,  7650,  4086,  5868,  9135,   914,
   -1394,  9135, -1394,  1080,   154, -1394, -1394, -1394,  1056, -1394,
     959, -1394,   757, -1394,    66,  1102, -1394,  7650,  1107,   998,
     502,  1037, -1394,    50,   986, -1394, -1394,   -68, -1394,   236,
      70,  1001,    50,   236,  7947, -1394,   131, -1394, -1394, -1394,
   -1394, -1394, -1394,    50,  1084,   946,   841,    70, -1394, -1394,
     948,  1155, -1394, -1394, -1394, 10293,  1049,  1052,  1059, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394,  1208,   -12,  1211,   -12,   979,  1136, -1394,  1078, 12565,
    1033, -1394, -1394,  8244, -1394,  1063, -1394, -1394, -1394, -1394,
   -1394, -1394,  7650,  1105, -1394, -1394,  7650, -1394,   562, -1394,
    7650,  1106,  7650, -1394,  7650, 12565, 12565, -1394,   678, -1394,
    7650, -1394,  1129,  1130,  1162,   959,  1093, -1394,  7650,  1079,
   -1394, -1394, -1394,  1074, -1394,    56,  7650,  4383,  1075,   101,
   -1394, 12565,  1082, 11429,    35, -1394, 11713,  1083, -1394, -1394,
    1086, -1394, -1394, -1394,  7650,   708,  1120, 12565,   706, -1394,
    1087,  1120, 12565, -1394, -1394,  7650,  7650,  7650,  7650,  7650,
   -1394,  7650,   414,   416,   427,   -15, -1394, -1394, -1394, -1394,
   -1394,  1102, -1394, -1394, -1394,   959, -1394, -1394, -1394, -1394,
   -1394,  1088,  7947, -1394, -1394, -1394, -1394, -1394,   250,  7947,
    7947,   520, -1394,   912, -1394,   379, -1394,   903,    50,  1109,
   -1394, -1394,  1039, -1394, -1394, -1394, -1394,  1169,  1089, -1394,
     438, -1394, -1394, -1394, -1394,   214,   214, -1394,   -12, -1394,
   -1394,   459, -1394,  1243,    70,  1177,  1090,  8244,   -42,  1042,
    1110, -1394, -1394,  7650, -1394,  7650,  1128, -1394,  7650, -1394,
   -1394, -1394,  1229, -1394, -1394,  5868,  7650,   959, -1394, -1394,
   -1394,  7650,  7650, -1394, -1394, -1394,  5868,  5868,  1189,  4383,
   12565,  1099, 12565,  7650, 12565,  1101,  5868, -1394,   195,    31,
    1120, 12565, -1394,  1094,  1120, -1394, -1394, -1394, -1394, -1394,
   -1394,  1095,  1046,  1047,  7650, -1394, -1394, -1394, -1394,   -20,
    7947,  7947,   546,   548, -1394, -1394, -1394, -1394, -1394, -1394,
    7650, -1394, 11997, -1394, 11997,  1196, -1394, -1394, -1394,  1263,
   -1394, -1394, -1394,  1044,  1187, -1394, -1394,  1188, -1394,   720,
   12565,  1178,  1085, 12565,  8244, -1394, -1394,  7650, -1394,  1180,
   -1394, -1394,  1093, -1394, -1394, 11997, -1394, -1394,  1204,  7650,
    1114, -1394,  1206,  5868, -1394, 12565,   287,   750, -1394,  1108,
    1120, -1394,  1111,  5868,   712,   505,   546,   546,  7947,   511,
   -1394, -1394, 11997, -1394, -1394,  1177,  8244, -1394,  1102,  1045,
   12565,  1185,  1096,  1188, -1394, 12565,  1124, 11997,  4383, 11997,
    1131, -1394, -1394,  1212,   537, -1394, -1394, -1394, -1394,  1138,
     772, -1394, -1394, -1394,  1117, -1394,  1207, -1394,   546, -1394,
   -1394, -1394, -1394, -1394,  7650,  1062, 12565,  1209, -1394,  4383,
    1143, -1394, -1394,  1145,  7650, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, 12565, -1394,  1065,  1066, 12565, -1394, -1394,  7650,
    5868,  1146,  1067,  7650,  1068,  5868,  8244, -1394,  8244, -1394,
    1135,  1064, 12565,  1113,  1216, 12565,  1069,  8244, -1394
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       159,   438,   439,   440,   162,   162,   162,   760,   959,   116,
     118,   588,   852,   861,   801,   765,   763,   745,   853,   856,
     808,   769,   746,   747,   800,   862,   749,   859,   830,   810,
     785,   805,   806,   857,   854,   804,   751,   860,   752,   753,
     901,   913,   900,   802,   821,   815,   754,   803,   756,   755,
     902,   839,   840,   807,   782,   923,   924,   925,   926,   927,
     928,   929,   930,   931,   932,   933,   947,   954,   829,   825,
     816,   796,   744,     0,   824,   832,   841,   948,   820,   460,
     797,   798,   855,   949,   955,   817,   834,     0,   466,   427,
     462,   827,   762,   818,   819,   848,   822,   838,   847,   953,
     956,   768,   809,   850,   461,   837,   843,   748,     0,     0,
       0,   375,   835,   846,   851,   849,   828,   814,   903,   812,
     813,   950,     0,   374,     0,   951,   957,   844,   799,   823,
     952,   405,     0,   437,   845,   826,   833,   842,   836,   904,
     790,   795,   794,   793,   792,   791,   757,   811,     0,   761,
     858,   783,   892,   891,   893,   767,   766,   786,   898,   750,
     890,   895,   896,   887,   789,   831,   889,   899,   897,   888,
     787,   894,   908,   909,   906,   907,   905,   758,   910,   911,
     912,   878,   877,   864,   781,   774,   871,   867,   784,   780,
     879,   880,   770,   771,   764,   773,   876,   875,   872,   868,
     885,   886,   884,   874,   870,   863,   772,   883,   882,   776,
     778,   777,   869,   873,   865,   779,   866,   775,   881,   934,
     935,   936,   937,   938,   939,   915,   916,   914,   920,   921,
     922,   917,   918,   919,   788,   940,   941,   942,   943,   944,
     945,   946,   159,     0,     2,   159,     5,     7,    19,     0,
      24,    27,    32,    33,    34,    35,    36,    37,    38,    28,
      54,    55,    29,    30,     0,    72,    75,    76,    31,    77,
      78,     0,   114,    79,    80,    81,    82,    14,   156,   157,
     158,   165,   167,   457,   168,     0,   169,   170,   171,   172,
     173,   174,   175,   178,   163,   204,   211,   206,   233,   239,
       0,   231,   232,   213,   207,   177,   208,   176,   209,   212,
     330,   332,   334,   344,   348,   350,   353,   358,   361,   364,
     366,   368,   370,     0,   372,   378,   380,     0,   396,   379,
     401,   404,   406,   409,   411,     0,   416,   413,     0,   424,
     434,   436,   410,   441,   448,   458,   449,   450,   451,   454,
     455,   452,   453,   473,   475,   476,   477,   474,   522,   523,
     524,   525,   526,   527,   433,   562,   554,   561,   560,   559,
     556,   558,   555,   557,   459,   456,   589,   590,    39,   214,
     215,   217,   216,   218,   210,     0,   435,   743,   759,   852,
     861,   859,   761,     0,   160,   161,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     122,   124,   125,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   258,   259,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   429,   432,
     419,     0,     0,   740,   745,   769,   747,   800,   862,   749,
     810,   751,   821,   754,   756,   755,   839,   947,   954,   744,
     948,   798,   949,   955,   822,   953,   956,   903,   950,   951,
     957,   952,   904,   898,   890,   896,   887,   787,   908,   909,
     906,   758,   910,   425,   435,   743,   417,     0,   185,   418,
     421,   745,   746,   747,   751,   752,   753,   754,   744,   750,
     463,     0,   423,   422,   180,     0,     0,   749,   756,   755,
       0,   162,   464,   910,     0,   211,     0,   489,     0,   428,
     741,     0,   742,   399,   400,     0,   431,   430,   420,   403,
       0,     0,   518,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     3,
       1,     6,     8,     0,     0,     0,     0,     0,   159,   159,
     159,   159,     0,   115,   166,   164,     0,   183,     0,   192,
       0,     0,     0,     0,     0,     0,     0,     0,   197,   219,
     238,   234,   240,   235,   237,   236,     0,     0,     0,   389,
       0,     0,   387,     0,   339,     0,   388,   381,   386,   385,
     384,   383,   382,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   377,   376,   373,     0,   397,   402,     0,     0,     0,
     412,   445,   415,   414,   426,     0,   442,     0,     0,     0,
     529,   531,   535,   588,     0,   120,     0,    43,    40,    41,
      44,    45,     0,     0,     0,     0,    46,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   599,   600,
     601,     0,    99,   138,     0,     0,   108,     0,     0,     0,
       0,   123,     0,     0,     0,   568,     0,     0,     0,   564,
       0,     0,     0,   578,     0,     0,   221,   222,   241,   242,
       0,     0,     0,     0,   130,     0,   134,   162,   592,     0,
      56,     0,    65,     0,     0,     0,    57,     0,     0,     0,
       0,     0,   740,   569,     0,     0,     0,     0,   303,     0,
       0,   567,     0,     0,     0,   586,     0,     0,     0,     0,
     572,     0,     0,   187,     0,     0,   181,   179,     0,     0,
       0,   463,     0,   465,     0,   490,   489,   486,     0,     0,
     520,   519,   398,     0,   517,     0,   612,   613,   563,     0,
       0,     0,     0,     0,     0,   618,     0,   195,   196,     0,
       0,     0,     0,     0,   200,   201,    20,     0,    21,     0,
       4,    25,     0,    11,    26,     0,    15,   852,    73,    12,
      74,    16,   186,   184,   205,     0,     0,     0,     0,   198,
     220,   276,   331,   333,   337,   343,   342,   341,     0,   338,
     335,   336,     0,   352,   351,   349,   355,   356,   357,   354,
     359,   360,   363,   362,     0,     0,     0,     0,   394,     0,
     407,   408,     0,   446,   443,   471,     0,   958,   591,   469,
       0,     0,   117,   119,     0,     0,     0,    98,     0,    88,
      90,    91,    92,    93,    95,    96,    97,    89,    94,    84,
      85,     0,     0,   104,     0,   100,   102,   103,   110,     0,
       0,    83,    42,     0,     0,     0,     0,     0,     0,     0,
     690,   695,     0,     0,   691,   725,   678,   680,   681,   682,
     684,   686,   685,   683,   687,     0,     0,     0,     0,     0,
     107,     0,   140,     0,     0,   534,   528,   565,   566,     0,
       0,   582,     0,   579,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   223,   224,     0,   229,   136,     0,
       0,   131,     0,     0,     0,     0,     0,     0,    58,     0,
       0,     0,   257,   263,   260,     0,   571,   570,   577,   585,
       0,     0,     0,     0,   533,     0,     0,     0,   390,     0,
       0,     0,     0,   575,     0,   573,     0,   188,     0,     0,
       0,     0,     0,   489,   487,     0,   478,     0,   467,   468,
       0,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   193,     0,   749,   756,
     755,   910,     0,     0,     0,   626,     0,   202,     0,     0,
       0,   159,   159,   159,     0,   230,     0,   287,   283,   285,
       0,   277,   278,   340,     0,     0,     0,     0,   656,   346,
     629,   633,   635,   637,   639,   642,   649,   650,   658,   862,
     748,     0,   757,   365,   540,   546,   547,   549,   593,   594,
     550,   553,   367,   369,   537,   371,   395,   447,     0,   444,
     470,   121,    52,    53,    50,    51,   127,   126,     0,    86,
       0,     0,   105,   106,   111,    70,    71,    48,    49,    69,
     696,     0,   699,   726,     0,   689,   688,   693,   692,   724,
       0,     0,   701,     0,   697,   700,   679,     0,     0,     0,
       0,     0,     0,     0,   139,   142,     0,     0,     0,   109,
     112,     0,     0,     0,   162,     0,     0,   586,     0,     0,
       0,     0,   539,     0,   244,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   225,     0,     0,     0,     0,   270,
       0,   267,   272,   228,   137,   132,   135,     0,   182,     0,
       0,    67,    61,    64,    63,     0,    59,   261,     0,     0,
     162,     0,   301,   305,     0,     0,     0,   308,     0,     0,
     314,     0,     0,   321,     0,   325,     0,   392,   391,   162,
       0,     0,   189,     0,   191,   302,     0,     0,     0,   490,
       0,   479,     0,   513,   510,     0,   514,   515,     0,     0,
     509,     0,   484,   512,   511,     0,     0,     0,   605,   606,
     602,     0,     0,   610,   611,   607,   616,   614,     0,     0,
       0,   620,   194,     0,     0,     0,     0,     0,     0,   621,
     622,     0,   203,    22,     0,    13,    17,    18,   284,   296,
       0,   297,     0,   288,   289,   290,   291,     0,   280,     0,
       0,     0,   640,   653,     0,   345,   347,     0,   672,     0,
       0,     0,     0,     0,     0,   628,   630,   631,   667,   668,
     669,   671,   670,     0,     0,   644,   643,     0,   647,   651,
     665,   663,   662,   655,   659,     0,     0,     0,     0,   543,
     545,   544,   541,   538,   472,   129,   128,    87,   101,   713,
     694,     0,   718,     0,   718,   707,   702,   143,     0,     0,
       0,   113,   141,     0,    23,     0,   583,   584,   587,   580,
     581,   243,     0,     0,   256,   248,     0,   252,     0,   246,
       0,     0,     0,   265,     0,     0,     0,   227,   268,   271,
       0,   133,     0,     0,    66,     0,    60,   262,     0,     0,
     304,   306,   311,     0,   309,     0,     0,     0,     0,     0,
     315,     0,     0,     0,     0,   322,     0,     0,   326,   393,
       0,   576,   574,   190,     0,     0,   489,     0,     0,   521,
       0,   489,     0,   485,    10,     0,     0,     0,     0,     0,
     619,     0,     0,     0,     0,     0,   623,   627,   300,   298,
     299,   292,   293,   294,   286,     0,   281,   279,   657,   648,
     654,     0,     0,   727,   728,   738,   737,   736,     0,     0,
       0,     0,   729,   634,   735,     0,   632,   636,     0,     0,
     641,   645,     0,   666,   661,   664,   660,     0,     0,   551,
       0,   548,   598,   542,   714,     0,     0,   712,   719,   720,
     716,     0,   711,     0,   709,     0,     0,     0,     0,     0,
       0,   530,   245,     0,   254,     0,     0,   250,     0,   253,
     266,   274,   275,   269,   226,     0,     0,     0,    62,   264,
     536,     0,     0,   312,   316,   310,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   532,     0,     0,
     489,     0,   516,     0,   489,   603,   604,   608,   609,   615,
     617,     0,     0,     0,     0,   624,   295,   282,   652,   739,
       0,     0,   731,     0,   677,   676,   675,   674,   673,   638,
       0,   730,     0,   595,     0,     0,   723,   722,   721,     0,
     715,   708,   706,     0,   703,   704,   698,   144,   146,   148,
       0,     0,     0,     0,     0,   249,   247,     0,   255,     0,
     199,   329,    68,   307,   313,     0,   327,   323,     0,     0,
       0,   317,     0,     0,   319,     0,   499,   493,   488,     0,
     489,   480,     0,     0,     0,     0,   733,   732,     0,     0,
     596,   552,     0,   717,   710,     0,     0,   150,   149,     0,
       0,     0,     0,   145,   251,     0,     0,     0,     0,     0,
       0,   507,   501,     0,   500,   502,   508,   505,   495,     0,
     494,   496,   506,   482,     0,   481,     0,   625,   734,   646,
     597,   705,   147,   151,     0,     0,     0,     0,   273,     0,
       0,   320,   318,     0,     0,   492,   503,   504,   491,   497,
     498,   483,     0,   152,     0,     0,     0,   328,   324,     0,
       0,     0,     0,     0,     0,     0,     0,   154,     0,   153,
       0,     0,     0,     0,     0,     0,     0,     0,   155
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1394, -1394,  -215,  1097, -1394,  1098,  1100, -1394,  1115,  -528,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
    -924, -1394, -1394, -1394, -1394,  -213,  -553, -1394,   641,  -259,
   -1394, -1394, -1394, -1394, -1394,   240,   444, -1394, -1394,    12,
    -175,   941, -1394,   928, -1394, -1394,  -608, -1394,   382, -1394,
     203, -1394,  -234,  -269, -1394,  -526, -1394,     5,   106,    95,
    -239,  -177, -1394,  -800, -1394, -1394,  -113, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394,   554,   -89,  1237,
       0, -1394, -1394, -1394, -1394,   402, -1394, -1394,  -293, -1394,
       8, -1394, -1394,   211,  -718,  -680, -1394, -1394,   622, -1394,
   -1394,    -2,   201, -1394, -1394, -1394,    97, -1394, -1394,   329,
     100, -1394, -1394,   104, -1237, -1394,   858,   189, -1394, -1394,
     185,  -968, -1394, -1394,   183, -1394, -1394, -1182, -1176, -1394,
     179, -1394, -1394,   779,   777, -1394,  -479, -1394, -1394,  -612,
     295,  -599,   292,   294, -1394, -1394, -1394, -1394, -1394,  1070,
   -1394, -1394, -1394, -1394,  -798,  -304, -1089, -1394,  -107, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394,   -27,  -782, -1394, -1394,
     545,   225, -1394,  -380, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394,   727, -1394,  -949, -1394,   166, -1394,   613,  -754, -1394,
   -1394, -1394, -1394, -1394,  -260,  -252, -1148,  -888, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,   539,  -734,
    -694,   262,  -831, -1394,    75,  -749, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394,   980,   983,  -301,   452,   298, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394,   151, -1394, -1394,   142, -1394,   144, -1016, -1394,
   -1394, -1394,   111,   102,   -54,   350, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,   113,
   -1394, -1394, -1394,   -47,   346,   487, -1394, -1394, -1394, -1394,
   -1394,   291, -1394, -1394, -1393, -1394, -1394, -1394,  -540, -1394,
      81, -1394,   -62, -1394, -1394, -1394, -1394, -1209, -1394,   127,
   -1394,  -336,  -364,   906,    52, -1394
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   243,   809,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
    1181,   735,   261,   262,   263,   264,   265,   266,   889,   890,
     891,   267,   268,   269,   895,   896,   897,   270,   418,   271,
     272,   664,   273,   420,   421,   422,   435,   725,   726,   274,
    1134,   275,  1577,  1578,   276,   277,   278,   525,   279,   280,
     281,   282,   283,   728,   284,   285,   508,   286,   287,   288,
     289,   290,   291,   598,   292,   293,   804,   805,   294,   295,
     535,   297,   599,   433,   956,   957,   298,   600,   299,   602,
     536,   301,   718,   719,  1169,   442,   302,   443,   444,   722,
    1170,  1171,  1172,   603,   604,  1051,  1052,  1436,   605,  1048,
    1049,  1273,  1274,  1275,  1276,   303,   747,   748,   304,  1196,
    1197,  1385,   305,  1199,  1200,   306,   307,  1202,  1203,  1204,
    1205,   308,   309,   310,   311,   838,   312,  1285,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     623,   624,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     650,   651,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   866,   352,   353,   354,  1231,   776,   777,   778,  1608,
    1649,  1650,  1643,  1644,  1651,  1645,  1232,  1233,   355,   356,
    1234,   357,   358,   359,   360,   361,   362,   363,  1083,   951,
    1073,  1322,  1074,  1470,  1075,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   754,  1146,   374,   375,   376,
     377,  1077,  1078,  1079,  1080,   378,   379,   380,   381,   382,
     383,   794,   795,   384,  1259,  1260,  1545,  1036,  1059,  1295,
    1296,  1060,  1061,  1062,  1063,  1064,  1305,  1460,  1461,  1065,
    1308,  1066,  1441,  1067,  1068,  1313,  1314,  1466,  1464,  1297,
    1298,  1299,  1300,  1557,   692,   916,   917,   918,   919,   920,
     921,  1124,  1486,  1574,  1125,  1484,  1572,   922,  1334,  1481,
    1477,  1478,  1479,   923,   924,  1301,  1309,  1451,  1302,  1447,
    1286,   385,   541,   386,   387,   388
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int xquery_parser::yytable_ninf_ = -741;
  const short int
  xquery_parser::yytable_[] =
  {
       296,   568,   949,   971,   296,   296,   296,   601,   300,   393,
     396,   397,   300,   300,   300,   983,   845,  1198,   665,   665,
     534,  1035,  1005,   645,   419,   549,  1395,   818,   820,   997,
     846,   847,   848,   849,   579,   576,  1405,  1432,  1433,  1281,
     950,   584,     9,    10,  1057,  1186,   503,  1338,   687,   581,
     811,   814,   813,   816,   819,   821,     9,    10,  1230,   702,
     945,  1101,  1158,   404,   667,   953,   876,   400,   401,   551,
     402,   403,   405,     9,    10,  1580,  1097,   404,   577,   663,
     577,   780,   744,  1413,   577,   440,   405,   406,   577,   577,
     407,   454,  1575,   577,   404,   408,   583,   577,  1462,   395,
     395,   395,   732,   736,   407,  1076,  1076,   463,   296,   408,
     394,   394,   394,  1155,   723,   980,   300,   588,   946,  1023,
     947,   407,   947,  1475,  1606,   505,   409,   410,  1044,   834,
    1256,   835,   836,   586,   837,   946,   839,  1544,   588,   505,
     409,   410,   411,  1076,   840,   841,  1115,  1443,  1010,   980,
    1386,  1006,  1522,   573,   463,  1386,   584,  1116,   698,    79,
    1188,  1082,   505,   707,  1104,   668,  1448,   455,  1092,   574,
     948,  1270,  1159,    90,   505,  1360,   505,  1135,   669,   633,
     708,  1581,   970,   724,  1444,  1093,  1261,  1476,   634,   412,
     733,   585,  1272,  1261,  1546,  1087,   981,  1076,   104,   682,
    1386,   683,  1054,   526,  1012,  1055,  1016,  1011,   400,   401,
    1076,   402,   403,  1607,   394,   939,   587,  1007,  1163,   905,
    1523,   906,  1287,   646,  1174,   954,   124,  1287,   406,  1395,
     999,  1389,  1661,  1160,   456,   457,  1387,   734,   441,   441,
    1317,  1512,   296,   601,   583,   296,  1024,   781,   413,  1220,
     300,   552,  1152,   300,  1490,   818,   820,  1057,  1057,   685,
    1413,  1376,   955,  1582,   907,  1175,   578,  1440,   580,  1156,
    1098,  1161,   806,  1230,   663,  1573,   808,  1041,   811,   814,
     296,  1043,  1230,  1264,   731,  1263,  1517,   584,   300,   414,
     441,  1189,  1641,   867,  1288,   441,  1223,   441,  1326,  1288,
     441,   415,  1550,   588,   709,   871,   585,  1056,   652,   416,
    1331,   654,  1605,  1127,   682,   415,   683,   417,  1128,   707,
    -740,   686,  1076,   416,  1449,  1450,  1013,  1014,  1017,  1018,
     412,   417,   699,  1129,   672,  1130,   708,     9,    10,   712,
     700,  1015,  1627,  1019,  1131,   871,  1221,   729,   684,   902,
     673,   663,   437,   398,    79,   940,   741,   829,   946,  1053,
     807,  1614,   438,   752,   753,   812,   815,   964,    90,  1333,
     967,  1132,   759,   942,   685,   629,  1289,  1290,  1551,  1291,
    1523,  1289,  1290,   773,  1291,   872,  1292,   505,   439,   413,
     505,  1663,  1135,   104,   960,   296,  1293,  1054,  1579,   968,
    1055,  1293,   588,   300,   630,   670,  1341,   588,  1294,  1226,
     982,  1227,  1222,  1294,   908,   399,   588,   631,   671,  1642,
     946,   124,   582,   992,   296,   873,   296,   909,  1076,   910,
     414,    79,   300,  1353,   300,   941,   686,   585,  1395,  1228,
     911,   912,   913,   947,   914,    90,   915,   994,   588,   779,
     296,   632,  1076,   943,   676,   296,   674,   505,   300,  1230,
     505,   783,  1058,   300,   505,   584,   892,   505,   505,   822,
     104,  1088,  1162,   823,   961,   505,  1035,   800,   802,  1427,
    1361,   505,   963,  1371,   505,  1057,   677,   985,   818,   820,
     818,  1091,   505,  1352,  1057,  1579,   986,  1133,   505,   505,
     505,   505,  1445,   993,  1088,  1057,   505,  1392,   893,  1446,
     588,   588,   588,   894,   505,  1265,  1266,  1267,   588,   704,
     588,   704,   588,  1223,  1224,   946,   296,   995,  1027,   588,
     703,   296,   706,   588,   300,   588,   626,  1579,   426,   300,
     860,   861,  1641,   590,  1564,   704,  1223,   591,   588,   590,
     704,  1089,   592,   591,   627,   859,   750,   588,   592,   505,
     862,   756,   584,  1105,  1106,  1569,  1076,   296,  1109,   423,
     593,  1319,   996,   505,  1389,   300,   593,   588,   296,   296,
     296,   296,   505,  1592,  1090,   419,   300,   300,   300,   300,
    1216,  1217,  1218,  1038,   427,   975,   296,  1042,  1143,   644,
    1541,   590,  1542,  1320,   300,   591,   991,  1699,   588,  1700,
     592,   588,  1008,  1543,   505,   585,  1225,   588,  1708,  1121,
    1321,  1469,   430,   124,  1565,  1009,   395,   431,   593,  1182,
    1099,   434,   626,  1182,  1034,  1122,  1226,   394,  1227,  1145,
    1496,  1148,  1099,  1283,  1076,  1570,  1554,  1076,  1223,  1224,
     627,   635,  1529,  1555,  1086,  1223,  1224,  1533,   947,  1226,
    1057,  1227,   801,  1556,   460,   636,  1228,   124,   594,  1676,
     110,   595,   628,   432,   594,  1058,  1058,   595,  1123,  1000,
    1001,  1002,  1455,   802,  1331,  1438,   596,   122,  1657,  1228,
    1039,  1210,   774,  1211,  1659,   461,  1165,  1094,   462,  1521,
    1332,  1166,  1525,   626,   296,   626,   574,  1229,  1495,   505,
     818,   597,   300,   436,  1095,  1223,  1224,   597,  1646,  1652,
    1167,   627,  1096,   627,  1195,   148,   594,   296,   447,   595,
     878,  1165,   962,   505,  1325,   300,  1166,  1383,   727,   947,
     601,  1225,   448,  1333,  1257,  1618,   424,   505,  1225,   425,
     727,   505,   505,   645,  1310,  1311,  1646,   296,   296,  1223,
    1168,  1226,  1652,  1227,   428,   300,   300,   429,  1226,   597,
    1227,  1195,  1269,   505,   947,   505,  1609,  1312,  1647,   449,
    1612,  1223,  1270,   505,  1388,  1117,   505,  1554,  1252,  1121,
     505,  1228,  1271,  1393,  1555,   110,  1118,  1396,  1228,   452,
    1647,  1032,   110,  1272,  1556,  1122,  1394,  1393,  1225,  1033,
    1397,  1393,   122,  1076,   946,  1076,   560,   507,   696,   122,
    1528,   561,   395,   697,  1656,  1270,  1137,   505,  1226,   419,
    1227,   893,  1407,   394,   453,  1138,   894,  1552,  1553,  1412,
     647,   648,  1165,  1549,  1374,  1628,  1076,  1166,   445,  1182,
     148,   446,   704,   704,   568,   505,  1654,   148,  1228,  1262,
    1107,  1108,   110,   989,   990,  1110,  1111,  1112,  1620,   458,
    1621,  1113,  1226,  1076,  1227,   863,   459,   505,   863,   122,
     506,   863,   653,  1648,  1429,  1430,   450,   656,  1076,   451,
    1076,   554,   509,   555,  1226,   649,  1227,   655,   557,  1531,
     558,  1636,  1228,  1058,   510,  1679,   505,   505,   505,   505,
     521,  1236,  1058,  1237,  1241,   522,  1242,   148,   688,   689,
     690,   843,   844,  1058,  1228,   850,   851,   523,  1660,   852,
     853,  1084,  1084,   538,  1428,  1566,  1567,   539,  1616,  1617,
    1372,   546,   547,  1670,   505,  1673,   879,   880,   881,   882,
     883,   884,   885,   886,   887,   888,   548,   550,   505,   553,
     559,   562,   556,   563,   564,  1280,   565,   566,   570,   567,
     588,   589,   607,   637,   606,   625,   638,   639,   649,   504,
     640,   657,   658,   505,   659,   660,   661,   296,   463,   678,
     680,   681,   505,   520,   505,   300,   662,   691,   505,   695,
     705,   608,   721,   716,   717,   727,  1658,   730,   738,   609,
     610,   505,   611,   739,   740,   757,   537,   751,   829,   758,
     612,   772,   775,   425,   613,   764,   614,  1032,   542,   766,
     545,   615,   782,   429,   784,  1033,   446,   451,   462,  1508,
     785,   296,   296,   296,   505,   768,   505,   769,   616,   300,
     300,   300,   419,   770,   797,   793,   810,   788,   803,   842,
     825,   826,   798,   854,   827,   828,   855,   856,   857,   868,
     874,   617,   618,   619,   620,   621,   622,   875,  1058,   877,
     903,   899,   704,   900,   904,   925,   926,   927,   929,   934,
     935,   937,   931,  1206,   936,   938,   944,   959,   965,  1547,
     966,   969,   505,   976,   977,   978,   979,   987,   984,   988,
    1020,  1021,  1022,  1040,  1046,  1050,  1026,  1025,   894,  1100,
     946,  1119,  1136,   505,  1120,  1141,  1150,  1142,  1157,  1153,
    1144,   723,  1177,  1151,  1178,  1179,  1185,  1190,  1164,  1180,
    1183,  1184,  1191,  1194,   296,  1195,  1201,  1209,  1514,  1345,
    1207,  1214,   300,  1208,  1213,  1219,  1235,  1258,  1249,  1253,
     684,  1304,  1277,  1279,  1422,  1423,  1424,  1307,  1303,   663,
    1284,  1182,  1254,  1255,  1256,  1315,  1316,  1323,  1318,   296,
    1330,  1335,  1343,  1329,  1358,  1339,  1346,   300,  1344,  1356,
     296,  1348,  1340,  1365,  1366,  1379,  1370,  1362,   300,  1375,
    1364,  1378,   505,  1393,  1406,   505,  1409,  1270,  1414,   296,
    1347,  1399,  1435,  1349,  1400,  1350,  1401,   300,  1402,  1419,
     505,  1421,  1415,  1439,  1416,  1417,  1459,  1418,   296,   505,
    1458,  1404,  1463,  1465,  1442,  1471,   300,  1474,  1472,   395,
    1480,   504,  1485,   505,   504,  1473,  1491,  1487,  1483,  1452,
     394,  1493,  1498,   505,  1505,  1506,  1032,  1032,  1507,  1511,
    1516,  1560,  1510,  1562,  1033,  1033,  1590,  1519,  1526,  1527,
    1532,  1548,  1571,  1121,  1587,  1563,  1576,  1594,  1514,  1584,
    1596,   505,  1589,  1595,  1599,   395,  1603,  1604,  1489,  1611,
    1622,  1613,  1623,  1625,  1626,  1630,   394,  1635,  1637,  1638,
    1639,   505,  1666,  1653,   395,  1675,  1655,  1624,  1631,  1669,
     505,   675,  1681,   505,   679,   394,  1674,  1561,   542,  1667,
    1678,   693,   694,   704,  1682,   901,  1686,  1583,  1689,   542,
    1690,  1695,  1701,  1705,  1410,   715,  1704,  1102,   720,   569,
     666,  1328,  1176,   571,  1342,   572,   737,   701,  1664,  1702,
    1633,   801,   542,   745,   746,   749,  1692,  1662,  1037,  1173,
     755,  1351,   974,   575,  1596,  1684,  1503,   505,   762,  1693,
    1369,  1696,  1698,  1707,  1372,  1268,  1437,  1434,  1431,   765,
    1380,  1384,  1390,  1398,   833,   832,   870,   296,  1408,  1004,
    1680,   505,  1677,   643,  1149,   300,  1085,  1337,  1327,  1671,
    1420,  1426,  1425,  1453,  1559,  1457,  1282,   710,  1558,  1456,
     711,  1306,  1126,   763,  1336,  1482,  1568,   505,   505,     0,
    1454,     0,     0,     0,     0,     0,     0,   749,     0,     0,
    1687,     0,     0,     0,     0,     0,   771,     0,     0,     0,
       0,     0,     0,   505,     0,   505,     0,     0,   505,     0,
       0,  1687,     0,     0,     0,  1615,  1671,     0,     0,   505,
       0,     0,     0,     0,   505,     0,     0,     0,   796,     0,
       0,  1619,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1032,     0,     0,     0,     0,
       0,     0,     0,  1033,     0,     0,  1032,  1032,     0,   296,
       0,     0,     0,     0,  1033,  1033,  1032,   300,     0,     0,
       0,     0,     0,     0,  1033,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   542,     0,     0,     0,     0,     0,     0,
       0,     0,   505,     0,   505,     0,   505,     0,     0,     0,
       0,     0,     0,   505,     0,     0,     0,   898,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   928,     0,  1032,     0,   932,   933,     0,     0,     0,
       0,  1033,     0,  1032,   505,     0,   505,     0,     0,     0,
       0,  1033,     0,     0,     0,     0,     0,   952,     0,   958,
       0,     0,   505,     0,     0,   505,     0,   542,   296,     0,
     542,     0,     0,     0,   972,     0,   300,   505,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   505,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   296,
       0,     0,     0,     0,   505,     0,     0,   300,     0,     0,
       0,  1003,   505,     0,     0,     0,     0,   505,     0,   505,
    1032,   505,     0,     0,     0,  1032,     0,     0,  1033,     0,
       0,     0,     0,  1033,     0,     0,     0,     0,     0,   504,
       0,     0,     0,     0,     0,     0,     0,     0,   505,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1045,     0,     0,   505,     0,     0,     0,   505,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   505,     0,     0,   505,     0,     0,
    1081,  1081,  1081,  1081,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   786,   787,     0,   789,   790,   791,   792,  1081,     0,
       0,     0,   799,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   824,     0,     0,     0,     0,
       0,     0,     0,   830,   831,     0,     0,  1140,     0,     0,
       0,     0,     0,     0,     0,     0,  1147,     0,  1147,     0,
       0,     0,  1081,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1081,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   865,     0,     0,     0,   865,     0,   755,     0,
     755,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   930,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1278,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   973,  1081,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   998,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   830,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   720,     0,     0,  1354,
       0,     0,     0,     0,  1047,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1368,     0,     0,     0,     0,     0,
       0,     0,     0,  1081,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   749,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1081,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1103,     0,     0,     0,  1411,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   796,     0,     0,     0,     0,
       0,     0,     0,     0,   504,     0,  1139,   504,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1154,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1187,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1192,  1193,
       0,  1081,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1212,     0,     0,  1215,     0,     0,     0,
       0,     0,     0,     0,     0,  1488,     0,     0,     0,     0,
    1238,  1239,  1240,     0,  1243,  1244,  1245,  1246,  1247,  1248,
       0,  1250,  1251,     0,     0,     0,     0,     0,     0,     0,
       0,  1501,  1502,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1047,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1518,     0,  1081,
       0,     0,  1081,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1530,     0,     0,     0,     0,  1534,     0,
       0,     0,     0,     0,     0,  1324,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1355,     0,  1357,     0,  1359,     0,     0,  1363,
       0,     0,     0,     0,  1367,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1373,     0,     0,     0,
       0,     0,     0,     0,     0,  1377,  1598,     0,  1600,     0,
    1602,  1381,  1382,     0,     0,     0,     0,  1610,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1403,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1081,     0,
    1081,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1629,     0,     0,  1632,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1081,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1640,     0,     0,  1047,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1081,     0,
       0,     0,     0,     0,     0,     0,  1665,     0,     0,     0,
       0,  1668,     0,  1081,     0,  1081,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1685,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1691,  1492,
       0,     0,  1694,  1494,     0,     0,     0,  1497,     0,  1499,
       0,  1500,     0,     0,     0,     0,     0,  1504,  1703,     0,
       0,  1706,     0,     0,     0,  1509,     0,     0,     0,     0,
       0,     0,     0,  1513,  1515,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1373,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1535,  1536,  1537,  1538,  1539,     0,  1540,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1585,     0,  1586,     0,     0,  1588,     0,     0,     0,     0,
       0,     0,     0,  1591,     0,     0,     0,     0,  1593,  1515,
       0,     0,     0,     0,     0,     0,  1597,     0,     0,     0,
    1601,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1634,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1597,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1672,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1683,     0,     0,     0,     0,  1688,     0,     0,     1,
       2,  1672,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,  1688,    11,     0,     0,
    1697,    12,    13,     0,    14,    15,    16,    17,    18,    19,
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
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     1,     2,     0,     0,
       0,     0,   242,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,     0,    11,     0,     0,     0,   389,   390,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,   391,    28,    29,    30,    31,     0,
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
     123,   124,     0,     0,   125,   126,   127,     0,   524,     0,
     128,     0,   129,   130,     0,   131,   132,   133,     0,   134,
       0,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,     0,     0,   146,   147,   148,     0,   392,   150,
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
       0,    11,     0,     0,     0,   389,   390,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   391,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,    74,    75,    76,     0,     0,    77,    78,     0,     0,
       0,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     0,     0,     0,    90,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,    96,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   108,     0,     0,   109,   110,   111,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,     0,   122,     0,   123,   124,     0,
       0,   125,   126,   127,     0,   767,     0,   128,     0,   129,
     130,     0,   131,   132,   133,     0,   134,     0,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,     0,
       0,   146,   147,   148,     0,   392,   150,   151,   152,   153,
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
      19,    20,    21,    22,    23,    24,    25,  1028,   391,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,  1029,  1030,    50,    51,    52,    53,    54,    55,    56,
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
     127,     0,   767,     0,   128,     0,   129,   130,     0,   131,
     132,   133,     0,   134,     0,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,     0,     0,   146,   147,
     148,     0,   392,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,  1031,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,     0,     0,     0,   389,
     390,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,  1028,   391,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,  1029,  1030,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
      96,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   108,     0,
       0,   109,   110,   111,   112,   113,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,     0,   122,
       0,   123,   124,     0,     0,   125,   126,   127,     0,   524,
       0,   128,     0,   129,   130,     0,   131,   132,   133,     0,
     134,     0,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,     0,     0,   146,   147,   148,     0,   392,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,  1031,   179,
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
       0,     0,   146,   147,   148,     0,   392,   150,   151,   152,
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
       0,     0,     0,    12,    13,     0,    14,    15,    16,    17,
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
     106,   107,   108,     0,     0,   109,   110,   111,   112,   113,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,     0,   122,     0,   123,   124,     0,     0,   125,
     126,   127,     0,     0,     0,   128,     0,   129,   130,     0,
     131,   132,   133,     0,   134,     0,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,     0,     0,   146,
     147,   148,     0,   149,   150,   151,   152,   153,   154,   155,
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
     392,   150,   151,   152,   153,   154,   155,   156,   157,   158,
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
       9,    10,     0,    11,     0,     0,     0,    12,   390,     0,
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
     102,   103,   104,   105,   106,   107,   108,     0,     0,   109,
     110,   111,   112,   113,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,     0,   122,     0,   123,
     124,     0,     0,   125,   126,   127,     0,     0,     0,   128,
       0,   129,   130,     0,   131,   132,   133,     0,   134,     0,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,     0,   146,   147,   148,     0,   392,   150,   151,
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
      11,     0,     0,     0,   817,   390,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
     391,    28,    29,    30,    31,     0,    32,    33,    34,    35,
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
     146,   147,   148,     0,   392,   150,   151,   152,   153,   154,
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
      20,    21,    22,    23,    24,    25,  1028,   391,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
    1029,  1030,    50,    51,    52,    53,    54,    55,    56,    57,
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
       0,   392,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
    1031,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     0,     0,    11,     0,     0,     0,   389,   390,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   527,   391,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,   528,   529,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   481,    82,    83,    84,
      85,    86,   530,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   531,     0,     0,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,     0,   122,     0,
     123,   124,     0,     0,   125,   126,   127,     0,     0,     0,
     128,   532,   129,   130,     0,   131,   132,   133,     0,   134,
       0,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,     0,     0,   146,   147,   148,     0,   392,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   498,   499,   500,   175,   176,   501,   533,   179,   180,
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
     527,   391,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,   528,   529,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,    74,    75,    76,     0,     0,    77,    78,     0,     0,
       0,    79,    80,   481,    82,    83,    84,    85,    86,   530,
      88,    89,     0,     0,     0,    90,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,    96,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   531,     0,     0,   109,   110,   111,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,     0,   122,     0,   123,   124,     0,
       0,   125,   126,   127,     0,   858,     0,   128,     0,   129,
     130,     0,   131,   132,   133,     0,   134,     0,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,     0,
       0,   146,   147,   148,     0,   392,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   498,   499,
     500,   175,   176,   501,   533,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     0,     0,     0,    11,     0,
       0,     0,   389,   390,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   527,   391,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,   528,   529,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     481,    82,    83,    84,    85,    86,   530,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   531,     0,     0,   109,   110,   111,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,     0,   122,     0,   123,   124,     0,     0,   125,   126,
     127,     0,     0,     0,   128,   864,   129,   130,     0,   131,
     132,   133,     0,   134,     0,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,     0,     0,   146,   147,
     148,     0,   392,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   498,   499,   500,   175,   176,
     501,   533,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     0,     0,     0,    11,     0,     0,     0,   389,
     390,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   527,   391,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,   528,   529,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,   481,    82,    83,
      84,    85,    86,   530,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
      96,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   531,     0,
       0,   109,   110,   111,   112,   113,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,     0,   122,
       0,   123,   124,     0,     0,   125,   126,   127,     0,     0,
       0,   128,   869,   129,   130,     0,   131,   132,   133,     0,
     134,     0,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,     0,     0,   146,   147,   148,     0,   392,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   498,   499,   500,   175,   176,   501,   533,   179,
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
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   481,    82,    83,    84,    85,    86,
     530,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   484,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   531,     0,     0,   109,   110,
     641,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,     0,   122,     0,   642,   124,
       0,     0,   125,   126,   127,     0,     0,     0,   128,     0,
     129,   130,     0,   131,   132,   133,     0,   134,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
       0,     0,   146,   147,   148,     0,   392,   150,   151,   152,
     153,   154,   155,   156,   157,   493,   159,   494,   161,   495,
     496,   164,   165,   166,   167,   168,   169,   497,   171,   498,
     499,   500,   175,   176,   501,   502,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     0,     0,     0,    11,
       0,     0,     0,   389,   390,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   527,   391,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,   528,   529,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,    74,
      75,    76,     0,     0,    77,    78,     0,     0,     0,    79,
      80,   481,    82,    83,    84,    85,    86,   530,    88,    89,
       0,     0,     0,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,    96,    97,    98,    99,   100,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   531,     0,     0,   109,   110,   111,   112,   113,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,     0,   122,     0,   123,   124,     0,     0,   125,
     126,   127,     0,     0,     0,   128,     0,   129,   130,     0,
     131,   132,   133,     0,   134,     0,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,     0,     0,   146,
     147,   148,     0,   392,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   498,   499,   500,   175,
     176,   501,   533,   179,   180,   181,   182,   183,   184,   185,
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
     475,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,   481,    82,
      83,    84,    85,    86,   530,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   484,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   531,
       0,     0,   109,   110,   111,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,     0,
     122,     0,   123,   124,     0,     0,   125,   126,   127,     0,
       0,     0,   128,     0,   129,   130,     0,   131,   132,   133,
       0,   134,     0,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,     0,     0,   146,   147,   148,     0,
     392,   150,   151,   152,   153,   154,   155,   156,   157,   493,
     159,   494,   161,   495,   496,   164,   165,   166,   167,   168,
     169,   497,   171,   498,   499,   500,   175,   176,   501,   502,
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
      43,   472,     0,    45,    46,    47,   474,   475,    50,   476,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,    74,    75,    76,     0,     0,    77,    78,
       0,     0,     0,    79,    80,   481,    82,    83,    84,    85,
      86,   530,    88,    89,     0,     0,     0,    90,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   484,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   531,     0,     0,   109,
     110,     0,   112,   113,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,     0,   122,     0,     0,
       0,     0,     0,   125,   126,   127,     0,     0,     0,   128,
       0,   129,   130,     0,   131,   132,   133,     0,   134,     0,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,     0,   146,   147,   148,     0,   392,   150,   151,
     152,   153,   154,   155,   156,   157,   493,   159,   494,   161,
     495,   496,   164,   165,   166,   167,   168,   169,   497,   171,
     498,   499,   500,   175,   176,   501,   502,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     0,     0,     0,
      11,     0,     0,     0,   389,   390,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   467,    25,   469,
     391,    28,   470,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,   472,     0,
      45,    46,    47,   474,   475,    50,   476,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,   481,    82,    83,    84,    85,    86,   530,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   484,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   531,     0,     0,   109,   110,     0,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,     0,   122,     0,     0,     0,     0,     0,
     125,   126,   127,     0,     0,     0,   128,     0,   129,   130,
       0,     0,     0,   133,     0,   134,     0,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,     0,     0,
     146,   147,   148,     0,   392,   150,   151,   152,   153,   154,
     155,   156,   157,   493,   159,   494,   161,   495,   496,   164,
     165,   166,   167,   168,   169,   497,   171,   498,   499,   500,
     175,   176,   501,   502,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     0,
       0,     0,     7,     8,     0,     0,     0,   463,     0,     0,
       0,   389,   390,     0,    14,    15,    16,   464,    18,    19,
      20,   465,    22,   466,   467,   468,   469,   391,    28,   470,
      30,    31,     0,    32,    33,    34,    35,   471,    37,    38,
      39,    40,    41,    42,    43,   472,     0,    45,   473,    47,
     474,   475,    50,   476,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,   477,   478,
      68,     0,    69,    70,    71,   479,     0,    74,    75,    76,
       0,     0,   480,    78,     0,     0,     0,     0,    80,   481,
      82,   482,   483,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   484,    97,    98,   485,   486,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,   107,
       0,     0,     0,     0,     0,     0,   112,   113,     0,     0,
       0,     0,   114,   115,   116,   117,   487,   119,   120,   488,
       0,     0,     0,     0,     0,     0,     0,   489,   490,   127,
       0,     0,     0,   128,     0,   129,   491,     0,     0,     0,
     133,     0,   134,     0,   135,   136,   137,   138,   492,   140,
     141,   142,   143,   144,   145,     0,     0,   146,   147,     0,
       0,   392,   150,   151,   152,   153,   154,   155,   156,   157,
     493,   159,   494,   161,   495,   496,   164,   165,   166,   167,
     168,   169,   497,   171,   498,   499,   500,   175,   176,   501,
     502,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     0,     0,     0,     7,
       8,     0,     0,     0,   463,     0,     0,     0,   389,   390,
       0,    14,    15,    16,   511,    18,    19,    20,   465,   512,
     513,   467,   468,   469,   391,    28,   470,    30,    31,     0,
      32,    33,    34,    35,   514,    37,   515,   516,    40,    41,
      42,    43,   472,     0,    45,   517,    47,   474,   475,    50,
     476,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   477,   478,    68,     0,    69,
      70,    71,   518,     0,    74,    75,    76,     0,     0,   480,
      78,     0,     0,     0,     0,    80,   481,    82,   482,   483,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   484,
      97,    98,   485,   486,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,   105,   106,   107,     0,     0,     0,
       0,     0,     0,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   487,   119,   120,   488,     0,     0,     0,
       0,     0,     0,     0,   489,   490,   127,     0,     0,     0,
     128,     0,   129,   491,     0,     0,     0,   133,     0,   134,
       0,   135,   136,   137,   138,   492,   140,   141,   142,   143,
     144,   145,     0,     0,   146,   147,     0,     0,   392,   150,
     151,   152,   153,   154,   155,   156,   157,   493,   519,   494,
     161,   495,   496,   164,   165,   166,   167,   168,   169,   497,
     171,   498,   499,   500,   175,   176,   501,   502,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   540,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     0,     0,   742,     0,     0,     0,
     389,   390,     0,    14,    15,    16,   511,    18,    19,    20,
     465,   512,   513,   467,   468,   469,   391,    28,   470,    30,
      31,     0,    32,    33,    34,    35,   514,    37,   515,   516,
      40,    41,    42,    43,   472,     0,    45,   517,    47,   474,
     475,    50,   476,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   477,   478,    68,
       0,    69,    70,    71,   518,     0,    74,    75,    76,     0,
       0,   480,    78,     0,     0,     0,     0,    80,   481,    82,
     482,   483,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   484,    97,    98,   485,   486,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   487,   119,   120,   488,     0,
       0,     0,     0,     0,     0,     0,   489,   490,   127,     0,
       0,     0,   128,   743,   129,   491,     0,     0,     0,     0,
       0,   134,     0,   135,   136,   137,   138,   492,   140,   141,
     142,   143,   144,   145,     0,     0,   146,   147,     0,     0,
     392,   150,   151,   152,   153,   154,   155,   156,   157,   493,
     519,   494,   161,   495,   496,   164,   165,   166,   167,   168,
     169,   497,   171,   498,   499,   500,   175,   176,   501,   502,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   540,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     0,     0,     0,   463,     0,
       0,     0,   389,   390,     0,    14,    15,    16,   511,    18,
      19,    20,   465,   512,   513,   467,   468,   469,   391,    28,
     470,    30,    31,     0,    32,    33,    34,    35,   514,    37,
     515,   516,    40,    41,    42,    43,   472,     0,    45,   517,
      47,   474,   475,    50,   476,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   477,
     478,    68,     0,    69,    70,    71,   518,     0,    74,    75,
      76,     0,     0,   480,    78,     0,     0,     0,     0,    80,
     481,    82,   482,   483,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   484,    97,    98,   485,   486,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
     107,     0,     0,     0,     0,     0,     0,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   487,   119,   120,
     488,     0,     0,     0,     0,     0,     0,     0,   489,   490,
     127,     0,     0,     0,   128,     0,   129,   491,     0,     0,
       0,     0,     0,   134,     0,   135,   136,   137,   138,   492,
     140,   141,   142,   143,   144,   145,     0,     0,   146,   147,
       0,     0,   392,   150,   151,   152,   153,   154,   155,   156,
     157,   493,   519,   494,   161,   495,   496,   164,   165,   166,
     167,   168,   169,   497,   171,   498,   499,   500,   175,   176,
     501,   502,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   543,   544,     0,
       0,     0,     0,     7,     8,     0,     0,     0,   463,     0,
       0,     0,   389,   390,     0,    14,    15,    16,   511,    18,
      19,    20,   465,   512,   513,   467,   468,   469,   391,    28,
     470,    30,    31,     0,    32,    33,    34,    35,   514,    37,
     515,   516,    40,    41,    42,    43,   472,     0,    45,   517,
      47,   474,   475,    50,   476,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   477,
     478,    68,     0,    69,    70,    71,   518,     0,    74,    75,
      76,     0,     0,   480,    78,     0,     0,     0,     0,    80,
     481,    82,   482,   483,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   484,    97,    98,   485,   486,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
     107,     0,     0,     0,     0,     0,     0,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   487,   119,   120,
     488,     0,     0,     0,     0,     0,     0,     0,   489,   490,
     127,     0,     0,     0,   128,     0,   129,   491,     0,     0,
       0,     0,     0,   134,     0,   135,   136,   137,   138,   492,
     140,   141,   142,   143,   144,   145,     0,     0,   146,   147,
       0,     0,   392,   150,   151,   152,   153,   154,   155,   156,
     157,   493,   519,   494,   161,   495,   496,   164,   165,   166,
     167,   168,   169,   497,   171,   498,   499,   500,   175,   176,
     501,   502,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     7,     8,     0,
       0,     0,   463,     0,     0,     0,   389,   390,     0,    14,
      15,    16,   464,    18,    19,    20,   465,    22,   466,   467,
    1069,   469,   391,    28,   470,    30,    31,     0,    32,    33,
      34,    35,   471,    37,    38,    39,    40,    41,    42,    43,
     472,     0,    45,   473,    47,   474,   475,    50,   476,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   477,   478,    68,     0,    69,    70,    71,
     479,     0,    74,    75,    76,     0,     0,   480,    78,     0,
       0,     0,     0,    80,   481,    82,   482,   483,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   484,    97,    98,
     485,   486,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,  1070,     0,     0,     0,  1071,     0,
       0,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     117,   487,   119,   120,   488,     0,     0,     0,     0,     0,
       0,     0,   489,   490,   127,     0,     0,     0,   128,  1467,
     129,   491,     0,     0,     0,  1468,     0,   134,     0,   135,
     136,   137,   138,   492,   140,   141,   142,   143,   144,   145,
       0,     0,  1072,   147,     0,     0,   392,   150,   151,   152,
     153,   154,   155,   156,   157,   493,   159,   494,   161,   495,
     496,   164,   165,   166,   167,   168,   169,   497,   171,   498,
     499,   500,   175,   176,   501,   502,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     7,     8,     0,     0,     0,   463,     0,     0,     0,
     389,   390,     0,    14,    15,    16,   511,    18,    19,    20,
     465,   512,   513,   467,   468,   469,   391,    28,   470,    30,
      31,     0,    32,    33,    34,    35,   514,    37,   515,   516,
      40,    41,    42,    43,   472,     0,    45,   517,    47,   474,
     475,    50,   476,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   477,   478,    68,
       0,    69,    70,    71,   518,     0,    74,    75,    76,     0,
       0,   480,    78,     0,     0,     0,     0,    80,   481,    82,
     482,   483,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   484,    97,    98,   485,   486,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   487,   119,   120,   488,     0,
       0,     0,     0,     0,     0,     0,   489,   490,   127,     0,
       0,     0,   128,   713,   129,   491,     0,     0,     0,   714,
       0,   134,     0,   135,   136,   137,   138,   492,   140,   141,
     142,   143,   144,   145,     0,     0,   146,   147,     0,     0,
     392,   150,   151,   152,   153,   154,   155,   156,   157,   493,
     519,   494,   161,   495,   496,   164,   165,   166,   167,   168,
     169,   497,   171,   498,   499,   500,   175,   176,   501,   502,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     7,     8,     0,     0,     0,
     463,     0,     0,     0,   389,   390,     0,    14,    15,    16,
     511,    18,    19,    20,   465,   512,   513,   467,   468,   469,
     391,    28,   470,    30,    31,     0,    32,    33,    34,    35,
     514,    37,   515,   516,    40,    41,    42,    43,   472,     0,
      45,   517,    47,   474,   475,    50,   476,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   477,   478,    68,     0,    69,    70,    71,   518,     0,
      74,    75,    76,     0,     0,   480,    78,     0,     0,     0,
       0,    80,   481,    82,   482,   483,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   484,    97,    98,   485,   486,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,   107,     0,     0,     0,     0,     0,     0,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   487,
     119,   120,   488,     0,     0,     0,     0,     0,     0,     0,
     489,   490,   127,     0,     0,     0,   128,   760,   129,   491,
       0,     0,     0,   761,     0,   134,     0,   135,   136,   137,
     138,   492,   140,   141,   142,   143,   144,   145,     0,     0,
     146,   147,     0,     0,   392,   150,   151,   152,   153,   154,
     155,   156,   157,   493,   519,   494,   161,   495,   496,   164,
     165,   166,   167,   168,   169,   497,   171,   498,   499,   500,
     175,   176,   501,   502,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     7,
       8,     0,     0,     0,   463,     0,     0,     0,   389,   390,
       0,    14,    15,    16,   464,    18,    19,    20,   465,    22,
     466,   467,  1069,   469,   391,    28,   470,    30,    31,     0,
      32,    33,    34,    35,   471,    37,    38,    39,    40,    41,
      42,    43,   472,     0,    45,   473,    47,   474,   475,    50,
     476,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   477,   478,    68,     0,    69,
      70,    71,   479,     0,    74,    75,    76,     0,     0,   480,
      78,     0,     0,     0,     0,    80,   481,    82,   482,   483,
      85,    86,  1391,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   484,
      97,    98,   485,   486,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,   105,   106,  1070,     0,     0,     0,
    1071,     0,     0,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   487,   119,   120,   488,     0,     0,     0,
       0,     0,     0,     0,   489,   490,   127,     0,     0,     0,
     128,     0,   129,   491,     0,     0,     0,     0,     0,   134,
       0,   135,   136,   137,   138,   492,   140,   141,   142,   143,
     144,   145,     0,     0,  1072,   147,     0,     0,   392,   150,
     151,   152,   153,   154,   155,   156,   157,   493,   159,   494,
     161,   495,   496,   164,   165,   166,   167,   168,   169,   497,
     171,   498,   499,   500,   175,   176,   501,   502,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     7,     8,     0,     0,     0,   463,     0,
       0,     0,   389,   390,     0,    14,    15,    16,   464,    18,
      19,    20,   465,    22,   466,   467,  1069,   469,   391,    28,
     470,    30,    31,     0,    32,    33,    34,    35,   471,    37,
      38,    39,    40,    41,    42,    43,   472,     0,    45,   473,
      47,   474,   475,    50,   476,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   477,
     478,    68,     0,    69,    70,    71,   479,     0,    74,    75,
      76,     0,     0,   480,    78,     0,     0,     0,     0,    80,
     481,    82,   482,   483,    85,    86,  1520,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   484,    97,    98,   485,   486,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
    1070,     0,     0,     0,  1071,     0,     0,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   487,   119,   120,
     488,     0,     0,     0,     0,     0,     0,     0,   489,   490,
     127,     0,     0,     0,   128,     0,   129,   491,     0,     0,
       0,     0,     0,   134,     0,   135,   136,   137,   138,   492,
     140,   141,   142,   143,   144,   145,     0,     0,  1072,   147,
       0,     0,   392,   150,   151,   152,   153,   154,   155,   156,
     157,   493,   159,   494,   161,   495,   496,   164,   165,   166,
     167,   168,   169,   497,   171,   498,   499,   500,   175,   176,
     501,   502,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     7,     8,     0,
       0,     0,   463,     0,     0,     0,   389,   390,     0,    14,
      15,    16,   464,    18,    19,    20,   465,    22,   466,   467,
    1069,   469,   391,    28,   470,    30,    31,     0,    32,    33,
      34,    35,   471,    37,    38,    39,    40,    41,    42,    43,
     472,     0,    45,   473,    47,   474,   475,    50,   476,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   477,   478,    68,     0,    69,    70,    71,
     479,     0,    74,    75,    76,     0,     0,   480,    78,     0,
       0,     0,     0,    80,   481,    82,   482,   483,    85,    86,
    1524,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   484,    97,    98,
     485,   486,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,  1070,     0,     0,     0,  1071,     0,
       0,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     117,   487,   119,   120,   488,     0,     0,     0,     0,     0,
       0,     0,   489,   490,   127,     0,     0,     0,   128,     0,
     129,   491,     0,     0,     0,     0,     0,   134,     0,   135,
     136,   137,   138,   492,   140,   141,   142,   143,   144,   145,
       0,     0,  1072,   147,     0,     0,   392,   150,   151,   152,
     153,   154,   155,   156,   157,   493,   159,   494,   161,   495,
     496,   164,   165,   166,   167,   168,   169,   497,   171,   498,
     499,   500,   175,   176,   501,   502,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     7,     8,     0,     0,     0,   463,     0,     0,     0,
     389,   390,     0,    14,    15,    16,   464,    18,    19,    20,
     465,    22,   466,   467,  1069,   469,   391,    28,   470,    30,
      31,     0,    32,    33,    34,    35,   471,    37,    38,    39,
      40,    41,    42,    43,   472,     0,    45,   473,    47,   474,
     475,    50,   476,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   477,   478,    68,
       0,    69,    70,    71,   479,     0,    74,    75,    76,     0,
       0,   480,    78,     0,     0,     0,     0,    80,   481,    82,
     482,   483,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   484,    97,    98,   485,   486,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,  1070,     0,
       0,     0,  1071,     0,     0,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   487,   119,   120,   488,     0,
       0,     0,     0,     0,     0,     0,   489,   490,   127,     0,
       0,     0,   128,     0,   129,   491,     0,     0,     0,     0,
       0,   134,     0,   135,   136,   137,   138,   492,   140,   141,
     142,   143,   144,   145,     0,     0,  1072,   147,     0,     0,
     392,   150,   151,   152,   153,   154,   155,   156,   157,   493,
     159,   494,   161,   495,   496,   164,   165,   166,   167,   168,
     169,   497,   171,   498,   499,   500,   175,   176,   501,   502,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     7,     8,     0,     0,     0,
     463,     0,     0,     0,   389,   390,     0,    14,    15,    16,
     464,    18,    19,    20,   465,    22,   466,   467,  1069,   469,
     391,    28,   470,    30,    31,     0,    32,    33,    34,    35,
     471,    37,    38,    39,    40,    41,    42,    43,   472,     0,
      45,   473,    47,   474,   475,    50,   476,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   477,   478,    68,     0,    69,    70,    71,   479,     0,
      74,    75,    76,     0,     0,   480,    78,     0,     0,     0,
       0,    80,   481,    82,   482,   483,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   484,    97,    98,   485,   486,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,  1070,     0,     0,     0,  1071,     0,     0,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   487,
     119,   120,   488,     0,     0,     0,     0,     0,     0,     0,
     489,   490,   127,     0,     0,     0,   128,     0,   129,   491,
       0,     0,     0,     0,     0,   134,     0,   135,   136,   137,
     138,   492,   140,   141,   142,   143,   144,   145,     0,     0,
     146,   147,     0,     0,   392,   150,   151,   152,   153,   154,
     155,   156,   157,   493,   159,   494,   161,   495,   496,   164,
     165,   166,   167,   168,   169,   497,   171,   498,   499,   500,
     175,   176,   501,   502,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     7,
       8,     0,     0,     0,   463,     0,     0,     0,   389,   390,
       0,    14,    15,    16,   511,    18,    19,    20,   465,   512,
     513,   467,   468,   469,   391,    28,   470,    30,    31,     0,
      32,    33,    34,    35,   514,    37,   515,   516,    40,    41,
      42,    43,   472,     0,    45,   517,    47,   474,   475,    50,
     476,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   477,   478,    68,     0,    69,
      70,    71,   518,     0,    74,    75,    76,     0,     0,   480,
      78,     0,     0,     0,     0,    80,   481,    82,   482,   483,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   484,
      97,    98,   485,   486,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,   105,   106,   107,     0,     0,     0,
       0,     0,     0,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   487,   119,   120,   488,     0,     0,     0,
       0,     0,     0,     0,   489,   490,   127,     0,     0,     0,
     128,     0,   129,   491,     0,     0,     0,     0,     0,   134,
       0,   135,   136,   137,   138,   492,   140,   141,   142,   143,
     144,   145,     0,     0,   146,   147,     0,     0,   392,   150,
     151,   152,   153,   154,   155,   156,   157,   493,   519,   494,
     161,   495,   496,   164,   165,   166,   167,   168,   169,   497,
     171,   498,   499,   500,   175,   176,   501,   502,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     7,     8,     0,     0,     0,   463,     0,
       0,     0,   389,   390,     0,    14,    15,    16,     0,    18,
      19,    20,   465,     0,     0,   467,   468,     0,   391,    28,
     470,    30,    31,     0,    32,    33,    34,    35,     0,    37,
       0,     0,    40,    41,    42,    43,   472,     0,    45,     0,
      47,     0,     0,    50,   476,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   477,
     478,    68,     0,    69,    70,    71,     0,     0,    74,    75,
      76,     0,     0,   480,    78,     0,     0,     0,     0,    80,
     481,    82,   482,   483,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   484,    97,    98,   485,   486,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
       0,     0,     0,     0,     0,     0,     0,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   487,   119,   120,
     488,     0,     0,     0,     0,     0,     0,     0,   489,   490,
     127,     0,     0,     0,   128,     0,   129,   491,     0,     0,
       0,     0,     0,   134,     0,   135,   136,   137,   138,   492,
     140,   141,   142,   143,   144,   145,     0,     0,     0,   147,
       0,     0,   392,   150,   151,   152,   153,   154,   155,   156,
     157,   493,     0,   494,   161,   495,   496,   164,   165,   166,
     167,   168,   169,   497,   171,   498,   499,   500,   175,   176,
       0,   502,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   178,   720,   737,     4,     5,     6,   300,     0,     4,
       5,     6,     4,     5,     6,   749,   628,   985,   398,   399,
     109,   803,   776,   327,    12,   132,  1202,   580,   581,   763,
     629,   630,   631,   632,   249,   248,  1218,  1274,  1275,  1055,
     720,   280,    26,    27,   842,   969,    73,  1136,   412,   264,
     578,   579,   578,   579,   580,   581,    26,    27,  1007,   423,
      36,   892,    36,    47,   400,    55,   674,    37,    38,    30,
      40,    41,    56,    26,    27,   117,   876,    47,     1,    29,
       1,     8,   446,  1231,     1,   117,    56,    57,     1,     1,
      74,    76,  1485,     1,    47,    79,   271,     1,  1307,     4,
       5,     6,   438,   439,    74,   854,   855,    29,   108,    79,
       4,     5,     6,   146,   117,   106,   108,   106,    94,   106,
      96,    74,    96,   135,    93,    73,   110,   111,   112,   608,
     152,   610,   611,   106,   613,    94,   615,   152,   106,    87,
     110,   111,   112,   892,   623,   624,   261,   215,   130,   106,
      99,   129,   117,    33,    29,    99,   395,   272,   111,   109,
     141,   855,   110,    45,   898,   181,    96,   152,   147,    49,
     146,   105,   146,   123,   122,   146,   124,   926,   194,   199,
      62,   223,   141,   186,   252,   164,   208,   199,   208,   159,
     112,   280,   126,   208,  1431,   184,   187,   946,   148,    45,
      99,    47,   152,   108,    94,   155,    94,   189,    37,    38,
     959,    40,    41,   182,   108,   183,   189,   195,   952,    54,
     185,    56,    96,   330,   958,   215,   176,    96,    57,  1405,
     187,  1199,  1625,   951,   219,   220,   185,   159,   271,   271,
    1071,   185,   242,   536,   419,   245,   233,   174,   218,  1003,
     242,   212,   946,   245,  1343,   808,   809,  1055,  1056,   105,
    1408,  1185,   252,   305,    99,   959,   189,  1283,   189,   949,
     878,   951,   189,  1222,    29,  1484,   189,   189,   806,   807,
     280,   189,  1231,   112,   159,   189,   185,   526,   280,   259,
     271,   971,     5,   657,   168,   271,     9,   271,  1098,   168,
     271,   285,    52,   106,   186,   106,   395,   257,   335,   293,
      96,   338,   117,    39,    45,   285,    47,   301,    44,    45,
     120,   167,  1071,   293,   254,   255,   216,   217,   216,   217,
     159,   301,   285,    59,   165,    61,    62,    26,    27,   428,
     293,   231,  1579,   231,    70,   106,   129,   436,    79,   685,
     181,    29,    24,   155,   109,   106,   445,   596,    94,   838,
     575,  1543,    34,   452,   453,   578,   579,   731,   123,   155,
     734,    97,   461,   106,   105,   116,   250,   251,   128,   253,
     185,   250,   251,   186,   253,   186,   260,   335,    60,   218,
     338,  1628,  1141,   148,   106,   395,   270,   152,  1487,   735,
     155,   270,   106,   395,   145,   181,  1140,   106,   282,   122,
     146,   124,   195,   282,   249,   155,   106,   158,   194,   132,
      94,   176,   111,   106,   424,   186,   426,   262,  1177,   264,
     259,   109,   424,  1151,   426,   186,   167,   526,  1614,   152,
     275,   276,   277,    96,   279,   123,   281,   106,   106,   538,
     450,   192,  1201,   186,   168,   455,   404,   405,   450,  1408,
     408,   550,   842,   455,   412,   704,    94,   415,   416,   582,
     148,   106,   146,   586,   186,   423,  1258,   566,   567,  1261,
    1160,   429,   186,  1177,   432,  1283,   200,   186,  1041,  1042,
    1043,   871,   440,   146,  1292,  1584,   186,   223,   446,   447,
     448,   449,   266,   186,   106,  1303,   454,  1201,   136,   273,
     106,   106,   106,   141,   462,  1041,  1042,  1043,   106,   424,
     106,   426,   106,     9,    10,    94,   526,   186,   186,   106,
     424,   531,   426,   106,   526,   106,   157,  1626,   152,   531,
     647,   648,     5,    42,   106,   450,     9,    46,   106,    42,
     455,   186,    51,    46,   175,   644,   450,   106,    51,   507,
     649,   455,   801,   899,   900,   106,  1315,   567,   904,   159,
      69,   143,   141,   521,  1542,   567,    69,   106,   578,   579,
     580,   581,   530,  1507,   186,   573,   578,   579,   580,   581,
     186,   186,   186,   806,   155,   183,   596,   812,   934,   152,
     186,    42,   186,   175,   596,    46,   183,  1696,   106,  1698,
      51,   106,   183,   186,   562,   704,   102,   106,  1707,    96,
     192,  1315,    66,   176,   186,   183,   531,    71,    69,   965,
     889,   155,   157,   969,   183,   112,   122,   531,   124,   940,
    1358,   942,   901,   152,  1393,   186,   267,  1396,     9,    10,
     175,   135,  1406,   274,   183,     9,    10,  1411,    96,   122,
    1458,   124,   567,   284,   121,   149,   152,   176,   167,   132,
     156,   170,   197,   117,   167,  1055,  1056,   170,   155,   768,
     769,   770,  1294,   772,    96,   183,   185,   173,   183,   152,
      33,   992,   185,   994,   183,   152,    53,   147,   155,  1393,
     112,    58,  1396,   157,   704,   157,    49,   193,   146,   657,
    1263,   210,   704,   155,   164,     9,    10,   210,  1606,  1607,
      77,   175,   136,   175,    99,   211,   167,   727,   155,   170,
     678,    53,   727,   681,   136,   727,    58,   112,   152,    96,
    1033,   102,   155,   155,   185,   197,   152,   695,   102,   155,
     152,   699,   700,  1057,   245,   246,  1644,   757,   758,     9,
     117,   122,  1650,   124,   152,   757,   758,   155,   122,   210,
     124,    99,    95,   721,    96,   723,  1530,   268,    28,   117,
    1534,     9,   105,   731,   112,   261,   734,   267,  1027,    96,
     738,   152,   115,    99,   274,   156,   272,    99,   152,   155,
      28,   801,   156,   126,   284,   112,   112,    99,   102,   801,
     112,    99,   173,  1562,    94,  1564,   223,   117,   136,   173,
     112,   228,   727,   141,   112,   105,   297,   775,   122,   817,
     124,   136,   193,   727,   155,   306,   141,  1449,  1450,   193,
     190,   191,    53,  1442,  1180,  1579,  1595,    58,   152,  1185,
     211,   155,   757,   758,  1031,   803,  1610,   211,   152,  1036,
     127,   128,   156,   757,   758,   275,   276,   277,  1562,   121,
    1564,   281,   122,  1622,   124,   650,   121,   825,   653,   173,
     121,   656,   337,   133,   127,   128,   152,   342,  1637,   155,
    1639,   223,   121,   225,   122,   153,   124,   155,   223,   193,
     225,  1595,   152,  1283,   121,   133,   854,   855,   856,   857,
     117,   230,  1292,   232,   230,   121,   232,   211,   219,   220,
     221,   626,   627,  1303,   152,   633,   634,   121,  1622,   635,
     636,   856,   857,   152,  1270,  1475,  1476,   121,  1550,  1551,
    1179,   121,   121,  1637,   892,  1639,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,   121,   152,   906,   214,
     223,   117,   155,   239,   239,  1054,   240,   155,     0,   152,
     106,   189,    92,    50,   166,   247,   198,   100,   153,    73,
     101,   120,   144,   931,   155,   183,   183,   987,    29,    47,
     151,   117,   940,    87,   942,   987,   183,   244,   946,   302,
     186,   131,   117,   282,   282,   152,  1618,     1,   117,   139,
     140,   959,   142,   141,   106,   152,   110,   186,  1257,   152,
     150,   152,    35,   155,   154,   141,   156,  1027,   122,   183,
     124,   161,    17,   155,   212,  1027,   155,   155,   155,  1375,
      29,  1041,  1042,  1043,   992,   155,   994,   155,   178,  1041,
    1042,  1043,  1040,   155,   189,   229,     3,   186,   243,    70,
     117,   167,   189,   229,   169,   169,    94,    94,    94,   148,
     106,   201,   202,   203,   204,   205,   206,   106,  1458,    29,
     126,   159,   987,   159,   131,   244,    94,   297,   141,   131,
     183,   186,   117,   987,   183,   186,   106,    94,    96,  1435,
      45,    96,  1050,   186,   186,   186,   186,   152,   183,   183,
      94,   235,   223,    33,   169,   117,   189,   141,   141,   131,
      94,    29,   225,  1071,   284,    94,   117,   297,   146,   117,
     152,   117,    94,   126,   183,   196,    96,   152,   252,   131,
     159,   131,   117,   146,  1144,    99,    99,   152,  1387,  1144,
     183,   189,  1144,   183,   141,    35,    29,   243,   117,   155,
      79,   258,   106,   106,  1253,  1254,  1255,   265,   256,    29,
     283,  1507,   155,   155,   152,   155,   155,   143,   155,  1179,
      29,    29,   225,   284,   126,   285,   186,  1179,   189,   146,
    1190,   143,   304,   117,   117,  1190,    77,   146,  1190,   106,
     146,   141,  1150,    99,   131,  1153,     7,   105,   189,  1209,
     186,   183,   105,   186,  1209,   186,   186,  1209,   186,   235,
    1168,   185,   231,   186,   231,   231,   280,   231,  1228,  1177,
     146,   196,   284,    78,   248,   186,  1228,    29,   186,  1144,
      29,   335,   106,  1191,   338,   186,   183,   169,   269,   248,
    1144,   146,   146,  1201,   125,   125,  1256,  1257,    96,   185,
     185,   152,   183,    94,  1256,  1257,  1505,   185,   185,   183,
     183,   183,    29,    96,   146,   186,   186,  1516,  1517,   169,
    1519,  1229,    53,    94,   185,  1190,   185,  1526,   255,   195,
      94,   196,    29,   106,   106,   117,  1190,   117,    94,   185,
      94,  1249,   117,   195,  1209,    93,   195,   263,   223,   185,
    1258,   405,   195,  1261,   408,  1209,   185,   278,   412,   223,
     182,   415,   416,  1228,   117,   684,   117,   285,   185,   423,
     185,   185,   197,   117,  1228,   429,   223,   893,   432,   242,
     399,  1101,   960,   245,  1141,   245,   440,   419,   303,   285,
    1584,  1256,   446,   447,   448,   449,   291,  1626,   804,   957,
     454,  1150,   740,   248,  1603,   303,  1368,  1315,   462,   303,
    1169,   304,   304,   304,  1613,  1046,  1279,  1277,  1274,   521,
    1191,  1196,  1199,  1204,   607,   606,   659,  1387,  1222,   776,
    1650,  1339,  1644,   323,   942,  1387,   857,  1135,  1100,  1638,
    1249,  1259,  1258,  1292,  1458,  1303,  1056,   427,  1455,  1296,
     427,  1065,   925,   507,  1123,  1334,  1478,  1365,  1366,    -1,
    1293,    -1,    -1,    -1,    -1,    -1,    -1,   521,    -1,    -1,
    1669,    -1,    -1,    -1,    -1,    -1,   530,    -1,    -1,    -1,
      -1,    -1,    -1,  1391,    -1,  1393,    -1,    -1,  1396,    -1,
      -1,  1690,    -1,    -1,    -1,  1544,  1695,    -1,    -1,  1407,
      -1,    -1,    -1,    -1,  1412,    -1,    -1,    -1,   562,    -1,
      -1,  1560,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1505,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1505,    -1,    -1,  1516,  1517,    -1,  1519,
      -1,    -1,    -1,    -1,  1516,  1517,  1526,  1519,    -1,    -1,
      -1,    -1,    -1,    -1,  1526,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   657,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1520,    -1,  1522,    -1,  1524,    -1,    -1,    -1,
      -1,    -1,    -1,  1531,    -1,    -1,    -1,   681,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   695,    -1,  1603,    -1,   699,   700,    -1,    -1,    -1,
      -1,  1603,    -1,  1613,  1562,    -1,  1564,    -1,    -1,    -1,
      -1,  1613,    -1,    -1,    -1,    -1,    -1,   721,    -1,   723,
      -1,    -1,  1580,    -1,    -1,  1583,    -1,   731,  1638,    -1,
     734,    -1,    -1,    -1,   738,    -1,  1638,  1595,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1605,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1669,
      -1,    -1,    -1,    -1,  1622,    -1,    -1,  1669,    -1,    -1,
      -1,   775,  1630,    -1,    -1,    -1,    -1,  1635,    -1,  1637,
    1690,  1639,    -1,    -1,    -1,  1695,    -1,    -1,  1690,    -1,
      -1,    -1,    -1,  1695,    -1,    -1,    -1,    -1,    -1,   803,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1666,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   825,    -1,    -1,  1682,    -1,    -1,    -1,  1686,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1702,    -1,    -1,  1705,    -1,    -1,
     854,   855,   856,   857,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   554,   555,    -1,   557,   558,   559,   560,   892,    -1,
      -1,    -1,   565,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   906,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   588,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   596,   597,    -1,    -1,   931,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   940,    -1,   942,    -1,
      -1,    -1,   946,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   959,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   655,    -1,    -1,    -1,   659,    -1,   992,    -1,
     994,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   697,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1050,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   739,  1071,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   764,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   774,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1150,    -1,    -1,  1153,
      -1,    -1,    -1,    -1,   827,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1191,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1201,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   894,    -1,    -1,    -1,  1229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1249,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1258,    -1,   929,  1261,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   948,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   970,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   981,   982,
      -1,  1315,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   996,    -1,    -1,   999,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1339,    -1,    -1,    -1,    -1,
    1013,  1014,  1015,    -1,  1017,  1018,  1019,  1020,  1021,  1022,
      -1,  1024,  1025,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1365,  1366,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1046,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1391,    -1,  1393,
      -1,    -1,  1396,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1407,    -1,    -1,    -1,    -1,  1412,    -1,
      -1,    -1,    -1,    -1,    -1,  1088,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1155,    -1,  1157,    -1,  1159,    -1,    -1,  1162,
      -1,    -1,    -1,    -1,  1167,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1179,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1188,  1520,    -1,  1522,    -1,
    1524,  1194,  1195,    -1,    -1,    -1,    -1,  1531,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1562,    -1,
    1564,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1580,    -1,    -1,  1583,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1595,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1605,    -1,    -1,  1277,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1622,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1630,    -1,    -1,    -1,
      -1,  1635,    -1,  1637,    -1,  1639,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1666,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1682,  1352,
      -1,    -1,  1686,  1356,    -1,    -1,    -1,  1360,    -1,  1362,
      -1,  1364,    -1,    -1,    -1,    -1,    -1,  1370,  1702,    -1,
      -1,  1705,    -1,    -1,    -1,  1378,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1386,  1387,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1404,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1415,  1416,  1417,  1418,  1419,    -1,  1421,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1493,    -1,  1495,    -1,    -1,  1498,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1506,    -1,    -1,    -1,    -1,  1511,  1512,
      -1,    -1,    -1,    -1,    -1,    -1,  1519,    -1,    -1,    -1,
    1523,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1587,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1599,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1638,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1664,    -1,    -1,    -1,    -1,  1669,    -1,    -1,    11,
      12,  1674,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,  1689,    29,    -1,    -1,
    1693,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
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
     252,   253,   254,   255,    -1,   257,   258,   259,    -1,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,    11,    12,    -1,    -1,
      -1,    -1,   314,    -1,    -1,    20,    21,    22,    23,    24,
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
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,   123,    -1,   125,   126,   127,
     128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,    -1,   155,   156,   157,
     158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,    -1,   175,   176,    -1,
      -1,   179,   180,   181,    -1,   183,    -1,   185,    -1,   187,
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
     181,    -1,   183,    -1,   185,    -1,   187,   188,    -1,   190,
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
     301,   302,   303,   304,   305,   306,   307,    11,    12,    -1,
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
      -1,   145,   146,   147,   148,   149,   150,   151,   152,    -1,
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
     304,   305,   306,   307,    11,    12,    -1,    -1,    -1,    -1,
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
      90,    91,    92,    -1,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,    -1,    -1,   123,    -1,   125,   126,   127,   128,    -1,
     130,    -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,   152,    -1,    -1,   155,   156,   157,   158,   159,
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
     300,   301,   302,   303,   304,   305,   306,   307,    11,    12,
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
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,   123,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,   151,   152,    -1,    -1,   155,
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
     306,   307,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
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
     305,   306,   307,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
     148,   149,   150,   151,   152,    -1,    -1,   155,   156,   157,
     158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,    -1,   175,   176,    -1,
      -1,   179,   180,   181,    -1,   183,    -1,   185,    -1,   187,
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
     181,    -1,    -1,    -1,   185,   186,   187,   188,    -1,   190,
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
     301,   302,   303,   304,   305,   306,   307,    11,    12,    -1,
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
      -1,   145,   146,   147,   148,   149,   150,   151,   152,    -1,
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
     304,   305,   306,   307,    11,    12,    -1,    -1,    -1,    -1,
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
      -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,    -1,
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
     307,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     150,   151,   152,    -1,    -1,   155,   156,   157,   158,   159,
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
     300,   301,   302,   303,   304,   305,   306,   307,    11,    12,
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
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,   123,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,   151,   152,    -1,    -1,   155,
     156,    -1,   158,   159,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,   173,    -1,    -1,
      -1,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,
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
     306,   307,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
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
     249,   250,   251,   252,   253,   254,   255,    -1,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
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
     302,   303,   304,   305,   306,   307,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    24,
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
     185,    -1,   187,   188,    -1,    -1,    -1,   192,    -1,   194,
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
     305,   306,   307,    16,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
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
     303,   304,   305,   306,   307,    16,    -1,    -1,    -1,    -1,
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
     301,   302,   303,   304,   305,   306,   307,    18,    19,    -1,
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
     301,   302,   303,   304,   305,   306,   307,    24,    25,    -1,
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
     147,    -1,   149,   150,   151,    -1,    -1,    -1,   155,    -1,
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
     307,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
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
     303,   304,   305,   306,   307,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
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
     179,   180,   181,    -1,    -1,    -1,   185,   186,   187,   188,
      -1,    -1,    -1,   192,    -1,   194,    -1,   196,   197,   198,
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
     299,   300,   301,   302,   303,   304,   305,   306,   307,    24,
      25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    -1,    99,   100,   101,    -1,    -1,   104,
     105,    -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     305,   306,   307,    24,    25,    -1,    -1,    -1,    29,    -1,
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
     301,   302,   303,   304,   305,   306,   307,    24,    25,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
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
     307,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
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
     303,   304,   305,   306,   307,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
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
     299,   300,   301,   302,   303,   304,   305,   306,   307,    24,
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
     305,   306,   307,    24,    25,    -1,    -1,    -1,    29,    -1,
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
     301,   302,   303,   304,   305,   306,   307
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
     254,   255,   257,   258,   259,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   314,   329,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   350,   351,   352,   353,   354,   355,   359,   360,   361,
     365,   367,   368,   370,   377,   379,   382,   383,   384,   386,
     387,   388,   389,   390,   392,   393,   395,   396,   397,   398,
     399,   400,   402,   403,   406,   407,   408,   409,   414,   416,
     418,   419,   424,   443,   446,   450,   453,   454,   459,   460,
     461,   462,   464,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   510,   511,   512,   526,   527,   529,   530,   531,
     532,   533,   534,   535,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   555,   556,   557,   558,   563,   564,
     565,   566,   567,   568,   571,   629,   631,   632,   633,    33,
      34,    49,   213,   385,   386,   387,   385,   385,   155,   155,
      37,    38,    40,    41,    47,    56,    57,    74,    79,   110,
     111,   112,   159,   218,   259,   285,   293,   301,   366,   367,
     371,   372,   373,   159,   152,   155,   152,   155,   152,   155,
      66,    71,   117,   411,   155,   374,   155,    24,    34,    60,
     117,   271,   423,   425,   426,   152,   155,   155,   155,   117,
     152,   155,   155,   155,    76,   152,   219,   220,   121,   121,
     121,   152,   155,    29,    39,    43,    45,    46,    47,    48,
      51,    59,    67,    70,    72,    73,    75,    90,    91,    97,
     104,   111,   113,   114,   134,   137,   138,   168,   171,   179,
     180,   188,   200,   222,   224,   226,   227,   234,   236,   237,
     238,   241,   242,   494,   631,   632,   121,   117,   394,   121,
     121,    39,    44,    45,    59,    61,    62,    70,    97,   223,
     631,   117,   121,   121,   183,   385,   387,    48,    72,    73,
     117,   152,   186,   242,   406,   408,   418,   631,   152,   121,
      16,   630,   631,    18,    19,   631,   121,   121,   121,   486,
     152,    30,   212,   214,   223,   225,   155,   223,   225,   223,
     223,   228,   117,   239,   239,   240,   155,   152,   389,   331,
       0,   333,   334,    33,    49,   336,   353,     1,   189,   330,
     189,   330,   111,   368,   388,   406,   106,   189,   106,   189,
      42,    46,    51,    69,   167,   170,   185,   210,   401,   410,
     415,   416,   417,   431,   432,   436,   166,    92,   131,   139,
     140,   142,   150,   154,   156,   161,   178,   201,   202,   203,
     204,   205,   206,   478,   479,   247,   157,   175,   197,   116,
     145,   158,   192,   199,   208,   135,   149,    50,   198,   100,
     101,   157,   175,   477,   152,   483,   486,   190,   191,   153,
     498,   499,   494,   498,   494,   155,   498,   120,   144,   155,
     183,   183,   183,    29,   369,   501,   369,   629,   181,   194,
     181,   194,   165,   181,   632,   631,   168,   200,    47,   631,
     151,   117,    45,    47,    79,   105,   167,   630,   219,   220,
     221,   244,   602,   631,   631,   302,   136,   141,   111,   285,
     293,   371,   630,   386,   387,   186,   386,    45,    62,   186,
     551,   552,   406,   186,   192,   631,   282,   282,   420,   421,
     631,   117,   427,   117,   186,   375,   376,   152,   391,   406,
       1,   159,   629,   112,   159,   349,   629,   631,   117,   141,
     106,   406,    29,   186,   630,   631,   631,   444,   445,   631,
     386,   186,   406,   406,   553,   631,   386,   152,   152,   406,
     186,   192,   631,   631,   141,   444,   183,   183,   155,   155,
     155,   631,   152,   186,   185,    35,   514,   515,   516,   406,
       8,   174,    17,   406,   212,    29,   407,   407,   186,   407,
     407,   407,   407,   229,   569,   570,   631,   189,   189,   407,
     406,   387,   406,   243,   404,   405,   189,   330,   189,   330,
       3,   337,   353,   383,   337,   353,   383,    33,   354,   383,
     354,   383,   394,   394,   407,   117,   167,   169,   169,   388,
     407,   407,   461,   462,   464,   464,   464,   464,   463,   464,
     464,   464,    70,   468,   468,   467,   469,   469,   469,   469,
     470,   470,   471,   471,   229,    94,    94,    94,   183,   406,
     486,   486,   406,   499,   186,   407,   509,   630,   148,   186,
     509,   106,   186,   186,   106,   106,   374,    29,   632,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,   356,
     357,   358,    94,   136,   141,   362,   363,   364,   631,   159,
     159,   356,   629,   126,   131,    54,    56,    99,   249,   262,
     264,   275,   276,   277,   279,   281,   603,   604,   605,   606,
     607,   608,   615,   621,   622,   244,    94,   297,   631,   141,
     407,   117,   631,   631,   131,   183,   183,   186,   186,   183,
     106,   186,   106,   186,   106,    36,    94,    96,   146,   422,
     423,   537,   631,    55,   215,   252,   412,   413,   631,    94,
     106,   186,   385,   186,   630,    96,    45,   630,   629,    96,
     141,   537,   631,   407,   426,   183,   186,   186,   186,   186,
     106,   187,   146,   537,   183,   186,   186,   152,   183,   386,
     386,   183,   106,   186,   106,   186,   141,   537,   407,   187,
     406,   406,   406,   631,   515,   516,   129,   195,   183,   183,
     130,   189,    94,   216,   217,   231,    94,   216,   217,   231,
      94,   235,   223,   106,   233,   141,   189,   186,    48,    72,
      73,   242,   408,   418,   183,   495,   575,   405,   353,    33,
      33,   189,   330,   189,   112,   631,   169,   407,   437,   438,
     117,   433,   434,   464,   152,   155,   257,   482,   501,   576,
     579,   580,   581,   582,   583,   587,   589,   591,   592,    47,
     151,   155,   209,   538,   540,   542,   543,   559,   560,   561,
     562,   631,   538,   536,   542,   536,   183,   184,   106,   186,
     186,   501,   147,   164,   147,   164,   136,   391,   374,   357,
     131,   540,   364,   407,   537,   629,   629,   127,   128,   629,
     275,   276,   277,   281,   631,   261,   272,   261,   272,    29,
     284,    96,   112,   155,   609,   612,   603,    39,    44,    59,
      61,    70,    97,   223,   378,   543,   225,   297,   306,   407,
     631,    94,   297,   629,   152,   553,   554,   631,   553,   554,
     117,   126,   538,   117,   407,   146,   423,   146,    36,   146,
     422,   423,   146,   537,   252,    53,    58,    77,   117,   422,
     428,   429,   430,   413,   537,   538,   376,    94,   183,   196,
     131,   348,   629,   159,   131,    96,   348,   407,   141,   423,
     152,   117,   407,   407,   146,    99,   447,   448,   449,   451,
     452,    99,   455,   456,   457,   458,   386,   183,   183,   152,
     553,   553,   407,   141,   189,   407,   186,   186,   186,    35,
     516,   129,   195,     9,    10,   102,   122,   124,   152,   193,
     511,   513,   524,   525,   528,    29,   230,   232,   407,   407,
     407,   230,   232,   407,   407,   407,   407,   407,   407,   117,
     407,   407,   388,   155,   155,   155,   152,   185,   243,   572,
     573,   208,   389,   189,   112,   383,   383,   383,   437,    95,
     105,   115,   126,   439,   440,   441,   442,   106,   631,   106,
     406,   576,   583,   152,   283,   465,   628,    96,   168,   250,
     251,   253,   260,   270,   282,   577,   578,   597,   598,   599,
     600,   623,   626,   256,   258,   584,   602,   265,   588,   624,
     245,   246,   268,   593,   594,   155,   155,   540,   155,   143,
     175,   192,   539,   143,   407,   136,   391,   555,   363,   284,
      29,    96,   112,   155,   616,    29,   609,   539,   484,   285,
     304,   537,   378,   225,   189,   385,   186,   186,   143,   186,
     186,   421,   146,   422,   631,   407,   146,   407,   126,   407,
     146,   423,   146,   407,   146,   117,   117,   407,   631,   430,
      77,   538,   388,   407,   629,   106,   348,   407,   141,   385,
     445,   407,   407,   112,   448,   449,    99,   185,   112,   449,
     452,   117,   538,    99,   112,   456,    99,   112,   458,   183,
     385,   186,   186,   407,   196,   455,   131,   193,   513,     7,
     386,   631,   193,   524,   189,   231,   231,   231,   231,   235,
     570,   185,   406,   406,   406,   575,   573,   495,   629,   127,
     128,   441,   442,   442,   438,   105,   435,   434,   183,   186,
     576,   590,   248,   215,   252,   266,   273,   627,    96,   254,
     255,   625,   248,   580,   627,   467,   597,   581,   146,   280,
     585,   586,   625,   284,   596,    78,   595,   186,   192,   538,
     541,   186,   186,   186,    29,   135,   199,   618,   619,   620,
      29,   617,   618,   269,   613,   106,   610,   169,   631,   255,
     484,   183,   407,   146,   407,   146,   422,   407,   146,   407,
     407,   631,   631,   429,   407,   125,   125,    96,   629,   407,
     183,   185,   185,   407,   388,   407,   185,   185,   631,   185,
     117,   538,   117,   185,   117,   538,   185,   183,   112,   516,
     631,   193,   183,   516,   631,   407,   407,   407,   407,   407,
     407,   186,   186,   186,   152,   574,   442,   629,   183,   469,
      52,   128,   467,   467,   267,   274,   284,   601,   601,   582,
     152,   278,    94,   186,   106,   186,   616,   616,   620,   106,
     186,    29,   614,   625,   611,   612,   186,   380,   381,   484,
     117,   223,   305,   285,   169,   407,   407,   146,   407,    53,
     388,   407,   348,   407,   388,    94,   388,   407,   631,   185,
     631,   407,   631,   185,   388,   117,    93,   182,   517,   516,
     631,   195,   516,   196,   455,   406,   467,   467,   197,   406,
     538,   538,    94,    29,   263,   106,   106,   442,   537,   631,
     117,   223,   631,   380,   407,   117,   538,    94,   185,    94,
     631,     5,   132,   520,   521,   523,   525,    28,   133,   518,
     519,   522,   525,   195,   516,   195,   112,   183,   467,   183,
     538,   612,   381,   442,   303,   631,   117,   223,   631,   185,
     538,   388,   407,   538,   185,    93,   132,   523,   182,   133,
     522,   195,   117,   407,   303,   631,   117,   388,   407,   185,
     185,   631,   291,   303,   631,   185,   304,   407,   304,   484,
     484,   197,   285,   631,   223,   117,   631,   304,   484
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
     575,   576,   577,   578,   579,   580,   581,   582
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   328,   329,   329,   330,   331,   331,   331,   331,   332,
     332,   333,   333,   333,   333,   333,   333,   333,   333,   334,
     334,   334,   334,   335,   336,   336,   336,   337,   337,   337,
     337,   337,   338,   338,   338,   338,   338,   338,   338,   338,
     339,   339,   340,   341,   342,   342,   343,   343,   344,   344,
     345,   345,   345,   345,   346,   346,   346,   347,   347,   347,
     347,   348,   348,   349,   349,   350,   350,   350,   350,   351,
     352,   352,   353,   353,   353,   354,   354,   354,   354,   354,
     354,   354,   354,   355,   355,   356,   356,   357,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   359,   360,
     361,   362,   362,   363,   363,   363,   364,   365,   365,   365,
     366,   366,   366,   366,   367,   367,   368,   368,   368,   368,
     369,   369,   370,   370,   371,   371,   372,   372,   373,   373,
     374,   374,   374,   374,   375,   375,   376,   376,   377,   377,
     377,   377,   378,   378,   379,   379,   380,   380,   381,   381,
     381,   381,   382,   382,   382,   382,   383,   384,   384,   384,
     385,   385,   385,   386,   386,   387,   387,   388,   388,   388,
     388,   388,   388,   388,   388,   388,   388,   388,   388,   389,
     389,   390,   391,   392,   393,   393,   393,   394,   394,   394,
     394,   395,   396,   397,   398,   399,   399,   400,   401,   402,
     403,   404,   404,   405,   406,   406,   407,   407,   407,   407,
     407,   407,   408,   408,   408,   408,   408,   408,   408,   409,
     410,   411,   411,   412,   412,   412,   413,   413,   414,   414,
     415,   416,   416,   416,   417,   417,   417,   417,   417,   418,
     418,   419,   420,   420,   421,   421,   421,   421,   421,   421,
     421,   421,   421,   421,   421,   421,   422,   423,   424,   425,
     425,   426,   426,   426,   426,   427,   427,   428,   428,   428,
     429,   429,   429,   430,   430,   430,   431,   432,   433,   433,
     434,   434,   435,   436,   436,   437,   437,   438,   438,   439,
     439,   439,   439,   439,   439,   439,   440,   440,   441,   441,
     442,   443,   443,   444,   444,   445,   445,   446,   447,   447,
     448,   449,   449,   450,   451,   451,   452,   453,   453,   454,
     454,   455,   455,   456,   456,   457,   457,   458,   458,   459,
     460,   460,   461,   461,   462,   462,   462,   462,   462,   463,
     462,   462,   462,   462,   464,   464,   465,   465,   466,   466,
     467,   467,   467,   468,   468,   468,   468,   468,   469,   469,
     469,   470,   470,   470,   471,   471,   472,   472,   473,   473,
     474,   474,   475,   475,   476,   476,   476,   476,   477,   477,
     477,   478,   478,   478,   478,   478,   478,   479,   479,   479,
     480,   480,   480,   480,   481,   481,   482,   482,   483,   483,
     483,   484,   484,   484,   484,   485,   486,   486,   486,   487,
     487,   488,   488,   488,   488,   489,   489,   490,   490,   490,
     490,   490,   490,   490,   491,   491,   492,   492,   493,   493,
     493,   493,   493,   494,   494,   495,   495,   496,   496,   496,
     496,   497,   497,   497,   497,   498,   498,   499,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   501,   501,
     502,   502,   502,   503,   504,   504,   505,   506,   507,   508,
     508,   509,   509,   510,   510,   511,   511,   511,   512,   512,
     512,   512,   512,   512,   513,   513,   514,   514,   515,   516,
     516,   517,   517,   518,   518,   519,   519,   519,   519,   520,
     520,   521,   521,   521,   521,   522,   522,   523,   523,   524,
     524,   524,   524,   525,   525,   525,   525,   526,   526,   527,
     527,   528,   529,   529,   529,   529,   529,   529,   530,   531,
     531,   532,   532,   533,   534,   535,   535,   536,   536,   537,
     538,   538,   538,   539,   539,   539,   540,   540,   540,   540,
     540,   541,   541,   542,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   544,   545,   545,   545,   546,   547,   548,
     548,   548,   549,   549,   549,   549,   549,   550,   551,   551,
     551,   551,   551,   551,   551,   552,   553,   554,   555,   556,
     556,   557,   558,   559,   559,   560,   561,   561,   562,   563,
     563,   563,   564,   564,   564,   564,   564,   564,   564,   564,
     564,   564,   565,   565,   566,   566,   567,   568,   569,   569,
     570,   571,   572,   572,   573,   574,   575,   575,   576,   577,
     577,   578,   578,   579,   579,   580,   580,   581,   581,   582,
     582,   583,   584,   584,   585,   585,   586,   587,   587,   587,
     588,   588,   589,   590,   590,   591,   592,   592,   593,   593,
     594,   594,   594,   595,   595,   596,   596,   597,   597,   597,
     597,   597,   598,   599,   600,   601,   601,   601,   602,   602,
     603,   603,   603,   603,   603,   603,   603,   603,   604,   604,
     604,   604,   605,   605,   606,   607,   607,   608,   608,   608,
     609,   609,   610,   610,   611,   611,   612,   613,   613,   614,
     614,   615,   615,   615,   616,   616,   617,   617,   618,   618,
     619,   619,   620,   620,   621,   622,   622,   623,   623,   623,
     624,   625,   625,   625,   625,   626,   626,   627,   627,   628,
     629,   630,   630,   631,   631,   631,   631,   631,   631,   631,
     631,   631,   631,   631,   631,   631,   631,   631,   631,   632,
     632,   632,   632,   632,   632,   632,   632,   632,   632,   632,
     632,   632,   632,   632,   632,   632,   632,   632,   632,   632,
     632,   632,   632,   632,   632,   632,   632,   632,   632,   632,
     632,   632,   632,   632,   632,   632,   632,   632,   632,   632,
     632,   632,   632,   632,   632,   632,   632,   632,   632,   632,
     632,   632,   632,   632,   632,   632,   632,   632,   632,   632,
     632,   632,   632,   632,   632,   632,   632,   632,   632,   632,
     632,   632,   632,   632,   632,   632,   632,   632,   632,   632,
     632,   632,   632,   632,   632,   632,   632,   632,   632,   632,
     632,   632,   632,   632,   632,   632,   632,   632,   632,   632,
     632,   632,   632,   632,   632,   632,   632,   632,   632,   632,
     632,   632,   632,   632,   632,   632,   632,   632,   632,   632,
     632,   632,   632,   632,   632,   632,   632,   632,   632,   632,
     632,   632,   632,   632,   632,   632,   632,   632,   632,   632,
     632,   632,   632,   632,   632,   632,   632,   632,   632,   632,
     632,   632,   632,   632,   632,   632,   632,   632,   632,   632,
     632,   632,   632,   632,   632,   632,   632,   632,   632,   632,
     632,   632,   632,   632,   632,   632,   632,   632,   632,   632,
     632,   632,   632,   632,   632,   632,   632,   632,   632,   632,
     632,   632,   632,   632,   632,   632,   632,   632,   633,   633
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
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     4,     1,     4,     1,     4,
       1,     4,     1,     2,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     5,     5,     6,     3,     4,     1,     2,     3,     2,
       2,     1,     2,     2,     1,     1,     1,     3,     3,     1,
       1,     1,     2,     1,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     1,     2,     2,     1,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     4,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     1,     4,     4,     3,
       4,     1,     3,     1,     1,     1,     1,     1,     4,     5,
       8,     9,     9,    10,     1,     2,     1,     2,     6,     0,
       1,     3,     3,     0,     1,     1,     1,     2,     2,     0,
       1,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     2,     3,
       3,     2,     1,     1,     1,     1,     1,     1,     4,     3,
       7,     3,     7,     4,     4,     3,     7,     1,     2,     2,
       1,     2,     3,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     4,     4,     3,     3,     3,
       4,     4,     3,     4,     6,     4,     6,     4,     3,     4,
       6,     6,     4,     6,     6,     4,     1,     2,     1,     1,
       1,     3,     3,     1,     1,     4,     5,     6,     3,     3,
       3,     3,     5,     7,     7,     5,     5,     5,     7,     7,
       5,     5,     3,     3,     5,     7,     5,     7,     1,     4,
       3,     5,     1,     2,     3,     3,     1,     3,     2,     0,
       1,     1,     2,     1,     3,     1,     3,     1,     4,     1,
       2,     3,     0,     1,     0,     1,     4,     2,     3,     1,
       0,     1,     4,     0,     1,     2,     1,     3,     0,     1,
       2,     2,     1,     0,     1,     0,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     1,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     2,     2,     3,     1,     2,     2,     5,     2,
       1,     1,     0,     2,     1,     3,     4,     0,     2,     0,
       2,     4,     4,     3,     2,     3,     1,     3,     0,     1,
       1,     2,     2,     2,     2,     1,     2,     2,     2,     2,
       3,     2,     3,     3,     4,     2,     2,     1,     1,     3,
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
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1
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
  "\"'keys'\"", "\"'array'\"", "\"'array-pair'\"", "\"'json-item'\"",
  "\"'object'\"", "\"'object-pair'\"", "\"'pair'\"", "\"'BOM_UTF8'\"",
  "RANGE_REDUCE", "ADDITIVE_REDUCE", "MULTIPLICATIVE_REDUCE",
  "UNION_REDUCE", "INTERSECT_EXCEPT_REDUCE", "QVARINDECLLIST_REDUCE",
  "COMMA_DOLLAR", "UNARY_PREC", "SEQUENCE_TYPE_REDUCE", "OCCURS_STAR",
  "OCCURS_PLUS", "OCCURS_HOOK", "STEP_REDUCE", "$accept", "Module",
  "ERROR", "ModuleWithoutBOM", "VersionDecl", "MainModule",
  "LibraryModule", "ModuleDecl", "SIND_DeclList", "SIND_Decl", "Setter",
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
       329,     0,    -1,   331,    -1,   314,   331,    -1,     1,     3,
      -1,   333,    -1,   332,   333,    -1,   334,    -1,   332,   334,
      -1,   213,   214,    29,   189,    -1,   213,   214,    29,   130,
      29,   189,    -1,   336,   189,   383,    -1,   353,   189,   383,
      -1,   336,   189,   353,   189,   383,    -1,   383,    -1,   336,
     330,   383,    -1,   353,   330,   383,    -1,   336,   189,   353,
     330,   383,    -1,   336,   330,   353,   189,   383,    -1,   335,
      -1,   335,   336,   189,    -1,   335,   353,   189,    -1,   335,
     336,   189,   353,   189,    -1,    34,   159,   630,   131,   629,
     189,    -1,   337,    -1,   336,   189,   337,    -1,   336,   330,
     337,    -1,   338,    -1,   346,    -1,   351,    -1,   352,    -1,
     360,    -1,   339,    -1,   340,    -1,   341,    -1,   342,    -1,
     343,    -1,   344,    -1,   345,    -1,   563,    -1,    33,    38,
     181,    -1,    33,    38,   194,    -1,    33,   112,   105,   629,
      -1,    33,    37,   629,    -1,    33,    40,   181,    -1,    33,
      40,   194,    -1,    33,    57,   168,    -1,    33,    57,   200,
      -1,    33,   112,   167,   126,   127,    -1,    33,   112,   167,
     126,   128,    -1,    33,    41,   181,   106,   147,    -1,    33,
      41,   181,   106,   164,    -1,    33,    41,   165,   106,   147,
      -1,    33,    41,   165,   106,   164,    -1,   347,    -1,   350,
      -1,    49,    24,     1,    -1,    49,    60,   629,    -1,    49,
      60,   349,   629,    -1,    49,    60,   629,    96,   348,    -1,
      49,    60,   349,   629,    96,   348,    -1,   629,    -1,   348,
     106,   629,    -1,   159,   630,   131,    -1,   112,    45,   159,
      -1,    49,    34,   629,    -1,    49,    34,   159,   630,   131,
     629,    -1,    49,    34,   629,    96,   348,    -1,    49,    34,
     159,   630,   131,   629,    96,   348,    -1,    33,   159,   630,
     131,   629,    -1,    33,   112,    45,   159,   629,    -1,    33,
     112,    47,   159,   629,    -1,   354,    -1,   353,   189,   354,
      -1,   353,   330,   354,    -1,   355,    -1,   359,    -1,   361,
      -1,   365,    -1,   370,    -1,   377,    -1,   379,    -1,   382,
      -1,    33,   112,    79,   356,    -1,    33,    79,   631,   356,
      -1,   357,    -1,   356,   357,    -1,   358,   131,   555,    -1,
      80,    -1,    88,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    89,    -1,    85,    -1,    86,    -1,    87,    -1,
      33,    56,   631,    29,    -1,    33,   259,   602,    -1,    33,
     110,   151,   362,    -1,    94,   540,   363,    -1,   363,    -1,
     364,    -1,   136,    -1,   136,   364,    -1,   141,   407,    -1,
      33,   366,   141,   407,    -1,    33,   366,   136,    -1,    33,
     366,   136,   141,   407,    -1,   111,   117,   631,    -1,   111,
     117,   631,   537,    -1,   367,   111,   117,   631,    -1,   367,
     111,   117,   631,   537,    -1,   368,    -1,   367,   368,    -1,
      26,    -1,    26,   155,   369,   186,    -1,    27,    -1,    27,
     155,   369,   186,    -1,   501,    -1,   369,   106,   501,    -1,
      33,   371,    -1,    33,   367,   371,    -1,   372,    -1,   373,
      -1,    47,   632,   374,   391,    -1,    47,   632,   374,   136,
      -1,    74,    47,   632,   374,   391,    -1,    74,    47,   632,
     374,   136,    -1,   155,   186,    -1,   155,   375,   186,    -1,
     155,   186,    94,   538,    -1,   155,   375,   186,    94,   538,
      -1,   376,    -1,   375,   106,   376,    -1,   117,   631,    -1,
     117,   631,   537,    -1,    33,   285,   631,    -1,    33,   285,
     631,    94,   378,    -1,    33,   367,   285,   631,    -1,    33,
     367,   285,   631,    94,   378,    -1,   543,    -1,   543,   539,
      -1,    33,   293,   631,   297,   225,   484,   169,   380,    -1,
      33,   367,   293,   631,   297,   225,   484,   169,   380,    -1,
     381,    -1,   380,   106,   381,    -1,   484,    -1,   484,   537,
      -1,   484,   442,    -1,   484,   537,   442,    -1,    33,   301,
     302,   631,   297,   285,   631,   117,   631,   303,   407,    -1,
      33,   301,   302,   631,   297,   285,   631,   223,   117,   631,
     303,   291,   304,   484,    -1,    33,   301,   302,   631,   297,
     285,   631,   305,   223,   117,   631,   303,   407,    -1,    33,
     301,   302,   631,   306,   304,   255,   285,   631,   223,   117,
     631,   304,   484,   197,   285,   631,   223,   117,   631,   304,
     484,    -1,   384,    -1,   386,    -1,   387,    -1,    -1,   386,
      -1,   387,    -1,    -1,   406,    -1,   387,   406,    -1,   388,
      -1,   387,   388,    -1,   389,    -1,   392,    -1,   395,    -1,
     396,    -1,   397,    -1,   398,    -1,   399,    -1,   400,    -1,
     402,    -1,   454,    -1,   450,    -1,   403,    -1,   152,   387,
     183,    -1,   152,   183,    -1,   152,   385,   183,    -1,   152,
     385,   183,    -1,   393,   189,    -1,   393,   106,   394,    -1,
     111,   394,    -1,   367,   111,   394,    -1,   117,   631,    -1,
     117,   631,   537,    -1,   117,   631,   141,   407,    -1,   117,
     631,   537,   141,   407,    -1,   117,   631,   141,   407,   189,
      -1,   408,   189,    -1,   238,   240,   407,   189,    -1,   241,
     155,   406,   186,   388,    -1,   236,   239,   189,    -1,   237,
     239,   189,    -1,   418,   401,    -1,   185,   388,    -1,    48,
     155,   406,   186,   196,   388,   125,   388,    -1,   242,   389,
     404,    -1,   405,    -1,   404,   405,    -1,   243,   575,   389,
      -1,   407,    -1,   406,   106,   407,    -1,   409,    -1,   446,
      -1,   453,    -1,   459,    -1,   571,    -1,   408,    -1,   460,
      -1,   443,    -1,   564,    -1,   565,    -1,   567,    -1,   566,
      -1,   568,    -1,   418,   410,    -1,   185,   407,    -1,    66,
     282,    -1,    71,   282,    -1,   215,    -1,   252,    -1,    55,
     252,    -1,   412,   428,    77,   407,    -1,   412,    77,   407,
      -1,    46,   411,   427,   413,   413,    -1,    46,   411,   427,
     413,    -1,    42,   117,   631,    -1,   419,    -1,   424,    -1,
     414,    -1,   416,    -1,   431,    -1,   436,    -1,   432,    -1,
     415,    -1,   416,    -1,   418,   417,    -1,    46,   117,   420,
      -1,   421,    -1,   420,   106,   117,   421,    -1,   631,   146,
     407,    -1,   631,    36,   126,   146,   407,    -1,   631,   537,
     146,   407,    -1,   631,   537,    36,   126,   146,   407,    -1,
     631,   422,   146,   407,    -1,   631,    36,   126,   422,   146,
     407,    -1,   631,   537,   422,   146,   407,    -1,   631,   537,
      36,   126,   422,   146,   407,    -1,   631,   423,   146,   407,
      -1,   631,   537,   423,   146,   407,    -1,   631,   422,   423,
     146,   407,    -1,   631,   537,   422,   423,   146,   407,    -1,
      96,   117,   631,    -1,   271,   117,   631,    -1,    51,   425,
      -1,   426,    -1,   425,   106,   426,    -1,   117,   631,   141,
     407,    -1,   117,   631,   537,   141,   407,    -1,   423,   141,
     407,    -1,   117,   631,   537,   423,   141,   407,    -1,   117,
     631,   146,   407,    -1,   117,   631,   537,   146,   407,    -1,
     429,    -1,   117,   631,    -1,   117,   631,   429,    -1,   422,
      -1,   422,   430,    -1,   430,    -1,    58,   117,   631,    53,
     117,   631,    -1,    53,   117,   631,    -1,    58,   117,   631,
      -1,   210,   407,    -1,   170,   169,   433,    -1,   434,    -1,
     433,   106,   434,    -1,   117,   631,    -1,   117,   631,   435,
      -1,   105,   629,    -1,   167,   169,   437,    -1,    69,   167,
     169,   437,    -1,   438,    -1,   437,   106,   438,    -1,   407,
      -1,   407,   439,    -1,   440,    -1,   441,    -1,   442,    -1,
     440,   441,    -1,   440,   442,    -1,   441,   442,    -1,   440,
     441,   442,    -1,    95,    -1,   115,    -1,   126,   127,    -1,
     126,   128,    -1,   105,   629,    -1,    67,   117,   444,   187,
     407,    -1,   134,   117,   444,   187,   407,    -1,   445,    -1,
     444,   106,   117,   445,    -1,   631,   146,   407,    -1,   631,
     537,   146,   407,    -1,    72,   155,   406,   186,   447,   112,
     185,   407,    -1,   448,    -1,   447,   448,    -1,   449,   185,
     407,    -1,    99,   407,    -1,   449,    99,   407,    -1,    72,
     155,   406,   186,   451,   112,   185,   388,    -1,   452,    -1,
     451,   452,    -1,   449,   185,   388,    -1,    73,   155,   406,
     186,   455,   112,   185,   407,    -1,    73,   155,   406,   186,
     455,   112,   117,   631,   185,   407,    -1,    73,   155,   406,
     186,   457,   112,   185,   388,    -1,    73,   155,   406,   186,
     455,   112,   117,   631,   185,   388,    -1,   456,    -1,   455,
     456,    -1,    99,   538,   185,   407,    -1,    99,   117,   631,
      94,   538,   185,   407,    -1,   458,    -1,   457,   458,    -1,
      99,   538,   185,   388,    -1,    99,   117,   631,    94,   538,
     185,   388,    -1,    48,   155,   406,   186,   196,   407,   125,
     407,    -1,   461,    -1,   460,   166,   461,    -1,   462,    -1,
     461,    92,   462,    -1,   464,    -1,   464,   478,   464,    -1,
     464,   479,   464,    -1,   464,   131,   464,    -1,   464,   161,
     464,    -1,    -1,   464,   156,   463,   464,    -1,   464,   154,
     464,    -1,   464,   142,   464,    -1,   464,   140,   464,    -1,
     466,    -1,   466,   247,    70,   576,   465,    -1,    -1,   628,
      -1,   467,    -1,   467,   197,   467,    -1,   468,    -1,   467,
     175,   468,    -1,   467,   157,   468,    -1,   469,    -1,   468,
     192,   469,    -1,   468,   116,   469,    -1,   468,   145,   469,
      -1,   468,   158,   469,    -1,   470,    -1,   469,   199,   470,
      -1,   469,   208,   470,    -1,   471,    -1,   470,   149,   471,
      -1,   470,   135,   471,    -1,   472,    -1,   472,    50,   229,
     538,    -1,   473,    -1,   473,   198,    94,   538,    -1,   474,
      -1,   474,   100,    94,   536,    -1,   475,    -1,   475,   101,
      94,   536,    -1,   477,    -1,   476,   477,    -1,   175,    -1,
     157,    -1,   476,   175,    -1,   476,   157,    -1,   480,    -1,
     484,    -1,   481,    -1,   201,    -1,   206,    -1,   205,    -1,
     204,    -1,   203,    -1,   202,    -1,   150,    -1,   178,    -1,
     139,    -1,    75,   152,   386,   183,    -1,    75,   220,   152,
     386,   183,    -1,    75,   219,   152,   386,   183,    -1,    75,
      76,   553,   152,   386,   183,    -1,   482,   152,   183,    -1,
     482,   152,   406,   183,    -1,   483,    -1,   482,   483,    -1,
     176,   631,    17,    -1,   176,    18,    -1,   176,    19,    -1,
     485,    -1,   485,   486,    -1,   191,   486,    -1,   486,    -1,
     190,    -1,   487,    -1,   487,   190,   486,    -1,   487,   191,
     486,    -1,   488,    -1,   497,    -1,   489,    -1,   489,   498,
      -1,   492,    -1,   492,   498,    -1,   490,   494,    -1,   491,
      -1,   104,   121,    -1,   113,   121,    -1,    97,   121,    -1,
     188,   121,    -1,   114,   121,    -1,   138,   121,    -1,   137,
     121,    -1,   494,    -1,    98,   494,    -1,   493,   494,    -1,
     119,    -1,   171,   121,    -1,    90,   121,    -1,   180,   121,
      -1,   179,   121,    -1,    91,   121,    -1,   543,    -1,   495,
      -1,   631,    -1,   496,    -1,   192,    -1,    11,    -1,    12,
      -1,    20,    -1,   500,    -1,   497,   498,    -1,   497,   155,
     186,    -1,   497,   155,   509,   186,    -1,   499,    -1,   498,
     499,    -1,   153,   406,   184,    -1,   501,    -1,   503,    -1,
     504,    -1,   505,    -1,   508,    -1,   510,    -1,   506,    -1,
     507,    -1,   556,    -1,   390,    -1,   502,    -1,   555,    -1,
     109,    -1,   148,    -1,   123,    -1,   117,   631,    -1,   155,
     186,    -1,   155,   406,   186,    -1,   118,    -1,   168,   152,
     406,   183,    -1,   200,   152,   406,   183,    -1,   632,   155,
     186,    -1,   632,   155,   509,   186,    -1,   407,    -1,   509,
     106,   407,    -1,   511,    -1,   529,    -1,   512,    -1,   526,
      -1,   527,    -1,   156,   631,   516,   129,    -1,   156,   631,
     514,   516,   129,    -1,   156,   631,   516,   195,   193,   631,
     516,   195,    -1,   156,   631,   516,   195,   513,   193,   631,
     516,   195,    -1,   156,   631,   514,   516,   195,   193,   631,
     516,   195,    -1,   156,   631,   514,   516,   195,   513,   193,
     631,   516,   195,    -1,   524,    -1,   513,   524,    -1,   515,
      -1,   514,   515,    -1,    35,   631,   516,   131,   516,   517,
      -1,    -1,    35,    -1,   182,   518,   182,    -1,    93,   520,
      93,    -1,    -1,   519,    -1,   133,    -1,   522,    -1,   519,
     133,    -1,   519,   522,    -1,    -1,   521,    -1,   132,    -1,
     523,    -1,   521,   132,    -1,   521,   523,    -1,    28,    -1,
     525,    -1,     5,    -1,   525,    -1,   511,    -1,    10,    -1,
     528,    -1,   525,    -1,     9,    -1,   122,    -1,   124,    -1,
     152,   386,   183,    -1,   211,    30,   212,    -1,   211,   212,
      -1,   173,   630,   174,    -1,   173,   630,     8,    -1,   102,
       7,    -1,   530,    -1,   531,    -1,   532,    -1,   533,    -1,
     534,    -1,   535,    -1,    43,   152,   386,   183,    -1,    21,
     385,   183,    -1,    45,   152,   406,   183,   152,   385,   183,
      -1,    22,   385,   183,    -1,    97,   152,   406,   183,   152,
     385,   183,    -1,    70,   152,   386,   183,    -1,    39,   152,
     386,   183,    -1,    23,   385,   183,    -1,    59,   152,   406,
     183,   152,   385,   183,    -1,   542,    -1,   542,   143,    -1,
      94,   538,    -1,   540,    -1,   540,   539,    -1,   209,   155,
     186,    -1,   143,    -1,   192,    -1,   175,    -1,   542,    -1,
     543,    -1,   151,   155,   186,    -1,   559,    -1,   562,    -1,
     538,    -1,   541,   106,   538,    -1,   631,    -1,   545,    -1,
     551,    -1,   549,    -1,   552,    -1,   550,    -1,   548,    -1,
     547,    -1,   546,    -1,   544,    -1,   223,   155,   186,    -1,
      44,   155,   186,    -1,    44,   155,   551,   186,    -1,    44,
     155,   552,   186,    -1,    70,   155,   186,    -1,    39,   155,
     186,    -1,    59,   155,   186,    -1,    59,   155,   630,   186,
      -1,    59,   155,    29,   186,    -1,    97,   155,   186,    -1,
      97,   155,   631,   186,    -1,    97,   155,   631,   106,   553,
     186,    -1,    97,   155,   192,   186,    -1,    97,   155,   192,
     106,   553,   186,    -1,    61,   155,   631,   186,    -1,    45,
     155,   186,    -1,    45,   155,   631,   186,    -1,    45,   155,
     631,   106,   553,   186,    -1,    45,   155,   631,   106,   554,
     186,    -1,    45,   155,   192,   186,    -1,    45,   155,   192,
     106,   553,   186,    -1,    45,   155,   192,   106,   554,   186,
      -1,    62,   155,   631,   186,    -1,   631,    -1,   631,   143,
      -1,    29,    -1,   557,    -1,   558,    -1,   631,   144,   148,
      -1,    47,   374,   391,    -1,   560,    -1,   561,    -1,    47,
     155,   192,   186,    -1,    47,   155,   186,    94,   538,    -1,
      47,   155,   541,   186,    94,   538,    -1,   155,   540,   186,
      -1,    33,   218,   219,    -1,    33,   218,   220,    -1,    33,
     218,   221,    -1,   224,   223,   407,   231,   407,    -1,   224,
     223,   407,    94,   230,   231,   407,    -1,   224,   223,   407,
      94,   232,   231,   407,    -1,   224,   223,   407,   216,   407,
      -1,   224,   223,   407,   217,   407,    -1,   224,   225,   407,
     231,   407,    -1,   224,   225,   407,    94,   230,   231,   407,
      -1,   224,   225,   407,    94,   232,   231,   407,    -1,   224,
     225,   407,   216,   407,    -1,   224,   225,   407,   217,   407,
      -1,   222,   223,   407,    -1,   222,   225,   407,    -1,   227,
     223,   407,   235,   407,    -1,   227,   228,   229,   223,   407,
     235,   407,    -1,   226,   223,   407,    94,   407,    -1,   234,
     117,   569,   233,   407,   185,   407,    -1,   570,    -1,   569,
     106,   117,   570,    -1,   631,   141,   407,    -1,   242,   152,
     406,   183,   572,    -1,   573,    -1,   572,   573,    -1,   243,
     575,   574,    -1,   152,   406,   183,    -1,   495,    -1,   575,
     208,   495,    -1,   579,   577,    -1,    -1,   578,    -1,   597,
      -1,   578,   597,    -1,   580,    -1,   579,   260,   580,    -1,
     581,    -1,   580,   256,   581,    -1,   582,    -1,   581,   258,
     146,   582,    -1,   583,    -1,   257,   583,    -1,   587,   584,
     585,    -1,    -1,   602,    -1,    -1,   586,    -1,   280,   152,
     406,   183,    -1,   591,   588,    -1,   155,   576,   186,    -1,
     589,    -1,    -1,   624,    -1,   482,   152,   590,   183,    -1,
      -1,   576,    -1,   592,   593,    -1,   501,    -1,   152,   406,
     183,    -1,    -1,   594,    -1,   246,   595,    -1,   245,   596,
      -1,   268,    -1,    -1,    78,    -1,    -1,   284,    -1,   598,
      -1,   599,    -1,   600,    -1,   626,    -1,   623,    -1,   168,
      -1,   282,   467,   601,    -1,   251,   625,   601,    -1,   284,
      -1,   274,    -1,   267,    -1,   244,   603,    -1,   602,   244,
     603,    -1,   604,    -1,   605,    -1,   606,    -1,   621,    -1,
     607,    -1,   615,    -1,   608,    -1,   622,    -1,    99,   272,
      -1,    99,   261,    -1,   264,    -1,   279,    -1,   249,   272,
      -1,   249,   261,    -1,    56,   631,    29,    -1,   275,    -1,
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
     283,   248,   469,    -1,    29,    -1,    16,    -1,   631,    -1,
     632,    -1,    97,    -1,    39,    -1,    44,    -1,    45,    -1,
     151,    -1,    48,    -1,   223,    -1,    59,    -1,    61,    -1,
      62,    -1,    70,    -1,    73,    -1,    72,    -1,   209,    -1,
     241,    -1,   633,    -1,    24,    -1,   213,    -1,   126,    -1,
      38,    -1,   259,    -1,    37,    -1,   220,    -1,   219,    -1,
     145,    -1,    43,    -1,   257,    -1,   258,    -1,   272,    -1,
     261,    -1,   249,    -1,   283,    -1,   275,    -1,   277,    -1,
     276,    -1,   281,    -1,   253,    -1,   248,    -1,    78,    -1,
     215,    -1,   252,    -1,    52,    -1,   221,    -1,   234,    -1,
     300,    -1,   228,    -1,   201,    -1,   206,    -1,   205,    -1,
     204,    -1,   203,    -1,   202,    -1,    96,    -1,   110,    -1,
     111,    -1,   185,    -1,    46,    -1,    36,    -1,    66,    -1,
      71,    -1,    58,    -1,    53,    -1,    55,    -1,    77,    -1,
      42,    -1,   146,    -1,    51,    -1,   210,    -1,   169,    -1,
     170,    -1,   167,    -1,    69,    -1,    95,    -1,   115,    -1,
     127,    -1,   128,    -1,   105,    -1,    67,    -1,   134,    -1,
     187,    -1,    99,    -1,    94,    -1,   196,    -1,   125,    -1,
     166,    -1,    92,    -1,    50,    -1,   229,    -1,   100,    -1,
     197,    -1,   116,    -1,   158,    -1,   199,    -1,   149,    -1,
     135,    -1,    75,    -1,    76,    -1,   101,    -1,   198,    -1,
     150,    -1,   181,    -1,   194,    -1,   159,    -1,   136,    -1,
     130,    -1,   165,    -1,   147,    -1,   164,    -1,    33,    -1,
      40,    -1,    57,    -1,   112,    -1,    41,    -1,    56,    -1,
     214,    -1,    49,    -1,    60,    -1,    34,    -1,    47,    -1,
     271,    -1,   247,    -1,   280,    -1,   282,    -1,   251,    -1,
     265,    -1,   278,    -1,   270,    -1,   250,    -1,   264,    -1,
     279,    -1,   269,    -1,   263,    -1,   262,    -1,   246,    -1,
     245,    -1,   254,    -1,   255,    -1,   284,    -1,   274,    -1,
     273,    -1,   268,    -1,   266,    -1,   267,    -1,   227,    -1,
     233,    -1,   230,    -1,   224,    -1,   217,    -1,   216,    -1,
     218,    -1,   235,    -1,   225,    -1,   226,    -1,   232,    -1,
     222,    -1,   231,    -1,    65,    -1,    63,    -1,    74,    -1,
     168,    -1,   200,    -1,   240,    -1,   238,    -1,   239,    -1,
     236,    -1,   237,    -1,   242,    -1,   243,    -1,   244,    -1,
      64,    -1,   293,    -1,   291,    -1,   292,    -1,   297,    -1,
     298,    -1,   299,    -1,   294,    -1,   295,    -1,   296,    -1,
      79,    -1,    80,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    85,    -1,    86,    -1,    87,    -1,    88,    -1,
      89,    -1,   285,    -1,   286,    -1,   287,    -1,   288,    -1,
     289,    -1,   290,    -1,   301,    -1,   302,    -1,   303,    -1,
     304,    -1,   305,    -1,   306,    -1,   307,    -1,    90,    -1,
     104,    -1,   113,    -1,   171,    -1,   179,    -1,   188,    -1,
     137,    -1,    91,    -1,   114,    -1,   138,    -1,   180,    -1,
     629,   120,   630,    -1,    25,    -1
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
    1337,  1339,  1343,  1347,  1349,  1353,  1357,  1361,  1365,  1367,
    1371,  1375,  1377,  1381,  1385,  1387,  1392,  1394,  1399,  1401,
    1406,  1408,  1413,  1415,  1418,  1420,  1422,  1425,  1428,  1430,
    1432,  1434,  1436,  1438,  1440,  1442,  1444,  1446,  1448,  1450,
    1452,  1457,  1463,  1469,  1476,  1480,  1485,  1487,  1490,  1494,
    1497,  1500,  1502,  1505,  1508,  1510,  1512,  1514,  1518,  1522,
    1524,  1526,  1528,  1531,  1533,  1536,  1539,  1541,  1544,  1547,
    1550,  1553,  1556,  1559,  1562,  1564,  1567,  1570,  1572,  1575,
    1578,  1581,  1584,  1587,  1589,  1591,  1593,  1595,  1597,  1599,
    1601,  1603,  1605,  1608,  1612,  1617,  1619,  1622,  1626,  1628,
    1630,  1632,  1634,  1636,  1638,  1640,  1642,  1644,  1646,  1648,
    1650,  1652,  1654,  1656,  1659,  1662,  1666,  1668,  1673,  1678,
    1682,  1687,  1689,  1693,  1695,  1697,  1699,  1701,  1703,  1708,
    1714,  1723,  1733,  1743,  1754,  1756,  1759,  1761,  1764,  1771,
    1772,  1774,  1778,  1782,  1783,  1785,  1787,  1789,  1792,  1795,
    1796,  1798,  1800,  1802,  1805,  1808,  1810,  1812,  1814,  1816,
    1818,  1820,  1822,  1824,  1826,  1828,  1830,  1834,  1838,  1841,
    1845,  1849,  1852,  1854,  1856,  1858,  1860,  1862,  1864,  1869,
    1873,  1881,  1885,  1893,  1898,  1903,  1907,  1915,  1917,  1920,
    1923,  1925,  1928,  1932,  1934,  1936,  1938,  1940,  1942,  1946,
    1948,  1950,  1952,  1956,  1958,  1960,  1962,  1964,  1966,  1968,
    1970,  1972,  1974,  1976,  1980,  1984,  1989,  1994,  1998,  2002,
    2006,  2011,  2016,  2020,  2025,  2032,  2037,  2044,  2049,  2053,
    2058,  2065,  2072,  2077,  2084,  2091,  2096,  2098,  2101,  2103,
    2105,  2107,  2111,  2115,  2117,  2119,  2124,  2130,  2137,  2141,
    2145,  2149,  2153,  2159,  2167,  2175,  2181,  2187,  2193,  2201,
    2209,  2215,  2221,  2225,  2229,  2235,  2243,  2249,  2257,  2259,
    2264,  2268,  2274,  2276,  2279,  2283,  2287,  2289,  2293,  2296,
    2297,  2299,  2301,  2304,  2306,  2310,  2312,  2316,  2318,  2323,
    2325,  2328,  2332,  2333,  2335,  2336,  2338,  2343,  2346,  2350,
    2352,  2353,  2355,  2360,  2361,  2363,  2366,  2368,  2372,  2373,
    2375,  2378,  2381,  2383,  2384,  2386,  2387,  2389,  2391,  2393,
    2395,  2397,  2399,  2401,  2405,  2409,  2411,  2413,  2415,  2418,
    2422,  2424,  2426,  2428,  2430,  2432,  2434,  2436,  2438,  2441,
    2444,  2446,  2448,  2451,  2454,  2458,  2460,  2463,  2466,  2472,
    2475,  2477,  2479,  2480,  2483,  2485,  2489,  2494,  2495,  2498,
    2499,  2502,  2507,  2512,  2516,  2519,  2523,  2525,  2529,  2530,
    2532,  2534,  2537,  2540,  2543,  2546,  2548,  2551,  2554,  2557,
    2560,  2564,  2567,  2571,  2575,  2580,  2583,  2586,  2588,  2590,
    2594,  2596,  2598,  2600,  2602,  2604,  2606,  2608,  2610,  2612,
    2614,  2616,  2618,  2620,  2622,  2624,  2626,  2628,  2630,  2632,
    2634,  2636,  2638,  2640,  2642,  2644,  2646,  2648,  2650,  2652,
    2654,  2656,  2658,  2660,  2662,  2664,  2666,  2668,  2670,  2672,
    2674,  2676,  2678,  2680,  2682,  2684,  2686,  2688,  2690,  2692,
    2694,  2696,  2698,  2700,  2702,  2704,  2706,  2708,  2710,  2712,
    2714,  2716,  2718,  2720,  2722,  2724,  2726,  2728,  2730,  2732,
    2734,  2736,  2738,  2740,  2742,  2744,  2746,  2748,  2750,  2752,
    2754,  2756,  2758,  2760,  2762,  2764,  2766,  2768,  2770,  2772,
    2774,  2776,  2778,  2780,  2782,  2784,  2786,  2788,  2790,  2792,
    2794,  2796,  2798,  2800,  2802,  2804,  2806,  2808,  2810,  2812,
    2814,  2816,  2818,  2820,  2822,  2824,  2826,  2828,  2830,  2832,
    2834,  2836,  2838,  2840,  2842,  2844,  2846,  2848,  2850,  2852,
    2854,  2856,  2858,  2860,  2862,  2864,  2866,  2868,  2870,  2872,
    2874,  2876,  2878,  2880,  2882,  2884,  2886,  2888,  2890,  2892,
    2894,  2896,  2898,  2900,  2902,  2904,  2906,  2908,  2910,  2912,
    2914,  2916,  2918,  2920,  2922,  2924,  2926,  2928,  2930,  2932,
    2934,  2936,  2938,  2940,  2942,  2944,  2946,  2948,  2950,  2952,
    2954,  2956,  2958,  2960,  2962,  2964,  2966,  2968,  2970,  2972,
    2974,  2976,  2978,  2980,  2982,  2984,  2986,  2988,  2990,  2992,
    2994,  2996,  2998,  3000,  3002,  3004,  3006,  3008,  3010,  3012,
    3014,  3016,  3018,  3020,  3022,  3024,  3026,  3028,  3030,  3034
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1015,  1015,  1016,  1025,  1034,  1040,  1048,  1054,  1065,
    1070,  1078,  1085,  1092,  1101,  1108,  1116,  1124,  1132,  1143,
    1148,  1155,  1162,  1174,  1184,  1191,  1198,  1210,  1211,  1212,
    1213,  1214,  1219,  1220,  1221,  1222,  1223,  1224,  1225,  1228,
    1233,  1238,  1246,  1254,  1262,  1267,  1275,  1280,  1288,  1293,
    1301,  1308,  1315,  1322,  1332,  1334,  1337,  1347,  1352,  1360,
    1368,  1379,  1386,  1397,  1402,  1410,  1417,  1424,  1433,  1446,
    1454,  1461,  1471,  1478,  1485,  1496,  1497,  1498,  1499,  1500,
    1501,  1502,  1503,  1508,  1514,  1523,  1530,  1540,  1550,  1551,
    1552,  1553,  1554,  1555,  1556,  1557,  1558,  1559,  1564,  1572,
    1580,  1588,  1595,  1603,  1610,  1615,  1623,  1631,  1646,  1661,
    1679,  1684,  1692,  1700,  1711,  1716,  1725,  1730,  1737,  1742,
    1752,  1757,  1766,  1772,  1785,  1790,  1798,  1809,  1824,  1836,
    1851,  1856,  1861,  1866,  1874,  1881,  1892,  1897,  1907,  1914,
    1921,  1928,  1938,  1942,  1952,  1960,  1971,  1977,  1986,  1991,
    1998,  2005,  2016,  2026,  2036,  2046,  2064,  2084,  2089,  2094,
    2101,  2106,  2111,  2118,  2123,  2135,  2142,  2154,  2155,  2156,
    2157,  2158,  2159,  2160,  2162,  2163,  2164,  2165,  2166,  2171,
    2176,  2184,  2201,  2209,  2217,  2224,  2231,  2241,  2253,  2266,
    2278,  2294,  2302,  2310,  2318,  2333,  2338,  2346,  2360,  2377,
    2402,  2410,  2417,  2428,  2438,  2443,  2458,  2459,  2460,  2461,
    2462,  2463,  2468,  2469,  2472,  2473,  2474,  2475,  2476,  2481,
    2495,  2503,  2508,  2516,  2521,  2526,  2534,  2543,  2555,  2565,
    2578,  2586,  2587,  2588,  2593,  2594,  2595,  2596,  2597,  2602,
    2609,  2619,  2627,  2634,  2644,  2654,  2664,  2674,  2684,  2694,
    2704,  2714,  2725,  2734,  2744,  2754,  2770,  2779,  2788,  2796,
    2802,  2814,  2822,  2832,  2840,  2852,  2858,  2869,  2871,  2875,
    2883,  2887,  2892,  2896,  2900,  2904,  2914,  2922,  2929,  2935,
    2946,  2950,  2959,  2967,  2973,  2983,  2989,  2999,  3003,  3013,
    3019,  3025,  3031,  3040,  3049,  3058,  3071,  3075,  3083,  3089,
    3099,  3107,  3116,  3129,  3136,  3148,  3152,  3164,  3171,  3177,
    3186,  3193,  3199,  3210,  3217,  3223,  3232,  3241,  3248,  3259,
    3266,  3278,  3284,  3296,  3302,  3313,  3319,  3330,  3336,  3347,
    3356,  3360,  3369,  3373,  3381,  3385,  3395,  3402,  3411,  3421,
    3420,  3434,  3443,  3452,  3465,  3469,  3482,  3485,  3492,  3496,
    3505,  3509,  3513,  3522,  3526,  3532,  3538,  3544,  3555,  3559,
    3563,  3571,  3575,  3581,  3591,  3595,  3605,  3609,  3619,  3623,
    3633,  3637,  3647,  3651,  3659,  3663,  3667,  3671,  3681,  3685,
    3689,  3697,  3701,  3705,  3709,  3713,  3717,  3725,  3729,  3733,
    3741,  3745,  3749,  3753,  3764,  3770,  3780,  3786,  3796,  3800,
    3804,  3842,  3846,  3856,  3866,  3879,  3888,  3898,  3902,  3911,
    3915,  3924,  3930,  3938,  3944,  3956,  3962,  3972,  3976,  3980,
    3984,  3988,  3994,  4000,  4008,  4012,  4020,  4024,  4035,  4039,
    4043,  4049,  4053,  4067,  4071,  4079,  4083,  4093,  4097,  4101,
    4105,  4114,  4118,  4122,  4126,  4134,  4140,  4150,  4158,  4162,
    4166,  4170,  4174,  4178,  4182,  4186,  4190,  4200,  4214,  4218,
    4226,  4233,  4240,  4251,  4259,  4263,  4271,  4279,  4287,  4341,
    4345,  4358,  4364,  4374,  4378,  4386,  4390,  4394,  4402,  4412,
    4422,  4432,  4442,  4452,  4467,  4473,  4484,  4490,  4501,  4512,
    4514,  4518,  4523,  4533,  4536,  4543,  4549,  4555,  4563,  4576,
    4579,  4586,  4592,  4598,  4605,  4616,  4620,  4630,  4634,  4644,
    4648,  4652,  4657,  4666,  4672,  4678,  4684,  4692,  4697,  4705,
    4710,  4718,  4726,  4731,  4736,  4741,  4746,  4751,  4760,  4768,
    4772,  4789,  4793,  4801,  4809,  4817,  4821,  4829,  4835,  4845,
    4853,  4857,  4861,  4896,  4902,  4908,  4918,  4922,  4926,  4930,
    4934,  4941,  4947,  4957,  4965,  4969,  4973,  4977,  4981,  4985,
    4989,  4993,  4997,  5005,  5013,  5017,  5021,  5031,  5039,  5047,
    5051,  5055,  5063,  5067,  5073,  5079,  5083,  5093,  5101,  5105,
    5111,  5120,  5129,  5135,  5141,  5151,  5168,  5175,  5190,  5226,
    5230,  5238,  5246,  5258,  5262,  5270,  5278,  5282,  5293,  5310,
    5316,  5322,  5332,  5336,  5342,  5348,  5352,  5358,  5362,  5368,
    5374,  5381,  5391,  5396,  5404,  5410,  5420,  5442,  5451,  5457,
    5470,  5484,  5491,  5497,  5507,  5516,  5524,  5530,  5548,  5557,
    5560,  5567,  5572,  5580,  5584,  5591,  5595,  5602,  5606,  5613,
    5617,  5626,  5639,  5642,  5650,  5653,  5661,  5669,  5677,  5681,
    5689,  5692,  5700,  5712,  5715,  5723,  5735,  5741,  5751,  5754,
    5762,  5766,  5770,  5778,  5781,  5789,  5792,  5800,  5804,  5808,
    5812,  5816,  5824,  5832,  5844,  5856,  5860,  5864,  5872,  5878,
    5888,  5892,  5896,  5900,  5904,  5908,  5912,  5916,  5924,  5928,
    5932,  5936,  5944,  5950,  5960,  5970,  5974,  5982,  5992,  6003,
    6010,  6014,  6022,  6025,  6032,  6037,  6046,  6056,  6059,  6067,
    6070,  6078,  6087,  6094,  6104,  6108,  6115,  6121,  6131,  6134,
    6141,  6146,  6158,  6166,  6178,  6186,  6190,  6198,  6202,  6206,
    6214,  6222,  6226,  6230,  6234,  6242,  6250,  6262,  6266,  6274,
    6359,  6363,  6364,  6377,  6378,  6379,  6380,  6381,  6382,  6383,
    6384,  6385,  6386,  6387,  6388,  6389,  6390,  6391,  6392,  6396,
    6397,  6398,  6399,  6400,  6401,  6402,  6403,  6404,  6405,  6406,
    6407,  6408,  6409,  6410,  6411,  6412,  6413,  6414,  6415,  6416,
    6417,  6418,  6419,  6420,  6421,  6422,  6423,  6424,  6425,  6426,
    6427,  6428,  6429,  6430,  6431,  6432,  6433,  6434,  6435,  6436,
    6437,  6438,  6439,  6440,  6441,  6442,  6443,  6444,  6445,  6446,
    6447,  6448,  6449,  6450,  6451,  6452,  6453,  6454,  6455,  6456,
    6457,  6458,  6459,  6460,  6461,  6462,  6463,  6464,  6465,  6466,
    6467,  6468,  6469,  6470,  6471,  6472,  6473,  6474,  6475,  6476,
    6477,  6478,  6479,  6480,  6481,  6482,  6483,  6484,  6485,  6486,
    6487,  6488,  6489,  6490,  6491,  6492,  6493,  6494,  6495,  6496,
    6497,  6498,  6499,  6500,  6501,  6502,  6503,  6504,  6505,  6506,
    6507,  6508,  6509,  6510,  6511,  6512,  6513,  6514,  6515,  6516,
    6517,  6518,  6519,  6520,  6521,  6522,  6523,  6524,  6525,  6526,
    6527,  6528,  6529,  6530,  6531,  6532,  6533,  6534,  6535,  6536,
    6537,  6538,  6539,  6540,  6541,  6542,  6543,  6544,  6545,  6546,
    6547,  6548,  6549,  6550,  6551,  6552,  6553,  6554,  6555,  6556,
    6557,  6558,  6559,  6560,  6561,  6562,  6563,  6564,  6565,  6566,
    6567,  6568,  6569,  6570,  6571,  6572,  6573,  6574,  6575,  6576,
    6577,  6578,  6579,  6580,  6581,  6582,  6583,  6584,  6585,  6586,
    6587,  6588,  6589,  6590,  6591,  6592,  6593,  6594,  6599,  6606
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
     325,   326,   327
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 13156;
  const int xquery_parser::yynnts_ = 306;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 570;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 328;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 582;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 16121 "/Users/pjl/src/flwor/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 6610 "/Users/pjl/src/flwor/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"


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

