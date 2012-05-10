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
#line 87 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"


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
#line 77 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 878 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 299 of lalr1.cc  */
#line 978 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 299 of lalr1.cc  */
#line 107 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"

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
#line 193 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"

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
#line 876 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 298 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 124: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 875 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 307 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 149: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 316 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 325 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 334 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 343 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 352 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 361 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 370 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 379 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 388 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 397 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 406 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 415 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 424 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 433 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 442 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 451 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 460 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 469 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 478 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 487 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 496 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 505 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 514 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 523 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 532 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 899 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 541 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 899 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 550 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 559 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 568 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 577 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 586 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 595 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 604 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 613 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 899 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 622 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 631 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 640 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 649 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 658 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 667 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 676 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 685 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 899 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 694 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 703 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 712 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 721 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 730 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 739 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 748 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 757 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 766 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 775 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 784 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 793 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 802 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 811 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 820 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 829 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 838 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 856 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 865 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 883 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 892 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 901 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 910 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 919 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 928 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 937 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 946 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 955 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 964 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 973 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 982 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 991 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1000 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1009 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1018 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1027 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1036 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1045 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1054 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1063 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1072 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1081 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1090 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1099 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1108 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1117 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1126 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1135 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1144 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1153 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1162 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1171 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1180 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1189 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1198 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1207 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1216 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1225 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1234 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1243 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1252 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1261 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1270 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1279 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1288 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1297 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1306 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1315 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1324 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1333 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1342 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1351 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1360 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1369 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1378 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1387 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1396 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1405 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1414 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1423 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1432 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1441 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1450 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1459 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1468 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1477 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1486 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1495 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1504 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1513 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1522 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1531 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1540 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1549 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1558 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1567 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1576 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1585 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1594 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1603 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1612 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1621 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1630 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1639 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1648 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1657 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1666 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1675 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1684 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1693 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1702 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1711 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1720 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1729 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1738 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1747 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1756 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1765 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1774 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1783 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1792 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1801 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1810 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1819 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1828 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1837 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1846 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1855 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1864 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1873 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1882 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1891 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1900 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1909 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1918 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1927 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1936 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1945 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1954 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1963 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1972 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1981 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1990 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1999 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2008 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2017 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2026 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2035 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2044 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2053 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2062 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2071 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2080 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2089 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2098 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2107 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2116 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2125 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2134 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2143 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2152 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2161 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2170 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2179 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2188 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2197 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2206 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2215 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2224 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2233 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2242 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2251 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2260 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2269 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2278 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2287 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2296 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2305 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2314 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2323 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2332 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 899 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2341 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2350 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2359 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2368 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2377 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2386 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2395 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2404 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2413 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2422 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2431 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2440 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2449 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2458 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2467 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2476 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2485 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2494 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2503 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2512 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2521 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2530 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2539 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2548 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2557 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2566 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2575 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2584 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2593 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2602 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2611 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2620 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 618: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2629 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 619: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2638 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2647 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2656 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 622: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2665 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 623: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2674 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 624: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2683 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 627: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2692 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2701 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2710 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
#line 140 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 565 of lalr1.cc  */
#line 2807 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"

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
#line 996 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 1005 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 1014 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 1020 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 1028 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 1034 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 1045 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 1050 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 1058 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 1065 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 1072 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 1081 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 1088 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 1096 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 1104 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 1112 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 1123 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 1128 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 1135 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 1142 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 1154 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 1164 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 1171 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 1178 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1213 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 1218 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 1226 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 1234 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 1242 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 1247 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 1255 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1260 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1268 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1273 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1281 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1288 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1295 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1302 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1317 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1327 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 1332 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 1340 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 1348 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 1359 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1366 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1377 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1382 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1390 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1397 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1404 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1413 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1426 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1434 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1441 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1451 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 1458 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1465 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 1488 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 1494 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 1503 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 1510 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1520 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1529 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1530 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1531 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1532 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1533 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1534 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1535 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1536 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1537 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1538 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1544 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1552 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1560 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1568 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1575 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1583 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1590 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1595 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1603 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1611 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1626 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1641 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1659 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1664 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1672 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1680 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 1691 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1696 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1705 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1710 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1717 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1722 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1732 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1737 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1746 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1752 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1765 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1770 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1778 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1789 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1804 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1816 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1831 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1836 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1841 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1846 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1854 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1861 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1872 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1877 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1887 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1894 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1901 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1908 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1918 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1922 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1932 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1940 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1951 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1957 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1966 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1971 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1978 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1985 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1997 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2007 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2017 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2028 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2044 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2064 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 2069 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 2073 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 2081 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 2086 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 2090 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 2098 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 2103 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 2115 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 2122 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 2151 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 2156 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 2164 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2181 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 2189 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 2197 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 2204 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 2211 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 2221 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2233 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2246 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2258 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2274 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 2282 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 2290 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 2298 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2313 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 2318 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 2326 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2340 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2357 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2382 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2390 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 2397 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2408 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 2418 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 2423 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2461 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2475 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 2483 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 2488 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 2496 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 2501 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 2506 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 2514 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2523 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2535 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2545 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2558 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2582 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2589 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2599 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 2607 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 2614 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 2624 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2634 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2644 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2654 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2664 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2674 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2684 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2694 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2705 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2714 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2724 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2734 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2750 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2759 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2768 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2776 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2782 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2794 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2802 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2812 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2820 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2832 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 2838 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 2851 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 2855 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 2863 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 2867 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2876 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2880 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2884 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2894 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2902 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2909 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2915 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2926 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2930 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2939 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2947 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2953 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2963 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2969 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 2979 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 2983 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 2993 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 2999 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 3005 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 3011 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3020 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3029 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3038 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3051 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 3055 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 3063 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 3069 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 3079 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 3087 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3096 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3109 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 3116 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 3128 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 3132 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 3144 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 3151 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 3157 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 3166 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 3173 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 3179 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 3190 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 3197 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 3203 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 3212 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 3221 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 3228 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3239 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 3246 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3258 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 3264 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 3276 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 3282 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 3293 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 3299 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 3310 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 3316 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 3327 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 3336 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 3340 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 3349 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 3353 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 3361 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 3365 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3375 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 3382 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3391 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3400 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 3405 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3414 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3423 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3432 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3445 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 3449 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3461 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 3465 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 3472 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 3476 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 3483 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 3487 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 3496 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 3500 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 3504 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3513 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3517 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3523 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 3529 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3535 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 3546 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 3550 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3554 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 3562 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 3566 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 3572 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 3582 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3586 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 368:

/* Line 690 of lalr1.cc  */
#line 3596 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3600 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3610 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3614 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3624 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3628 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3638 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3642 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3650 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3654 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3658 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3662 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3672 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3676 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3680 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3688 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3692 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3696 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3700 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3704 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3708 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3716 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3720 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3724 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3732 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3736 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3740 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3744 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3755 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3761 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3771 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3777 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3787 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3791 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3795 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3833 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3837 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3847 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3857 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3870 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3879 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3889 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3902 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3906 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3915 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3921 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3929 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3935 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3947 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3953 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3963 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3967 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3971 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3975 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3979 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 3985 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 3991 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 3999 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 4003 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 4011 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 4015 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 4026 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 4030 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 4034 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 4040 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 4044 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 4058 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 4062 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 4070 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 4074 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 4084 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 4088 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 4092 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 4096 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 4105 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 4109 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 4113 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 4117 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 4125 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 4131 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 4141 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 4149 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 4153 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 4157 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 4161 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 4165 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 4169 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 4173 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 4177 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 4181 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 4191 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 4199 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 4203 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 4211 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 4218 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 4225 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 4236 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 4244 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 4248 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 4256 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 4264 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 4272 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 4326 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 4330 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 4343 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 4349 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 4359 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 4363 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 4371 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 4375 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 4379 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 4387 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 4397 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 4407 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 4417 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 4427 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 4437 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 4452 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 4458 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 4469 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 4475 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 4486 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 4503 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 4508 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 4517 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 4521 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 4528 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 4534 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 4540 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 4548 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 4560 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 4564 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 4571 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 4577 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 4583 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 4590 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 4601 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 4605 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 4615 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 4619 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 4629 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 4633 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 4637 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 4642 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 4651 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 4657 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 4663 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 4669 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 4677 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 4682 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 4690 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 4695 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 4703 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 4711 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 4716 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 4721 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 4726 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 4731 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 4736 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 4745 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 4753 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 4757 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 4774 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 4778 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 4786 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 4794 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 4802 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 4806 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 4814 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 4820 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 4830 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 4838 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 4842 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 4846 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 4881 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 4887 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 4893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 4903 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 4907 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 4911 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 4915 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 4919 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 4926 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 4932 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 4942 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 4950 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 4954 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 4958 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 4962 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 4966 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 4970 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 4974 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 4978 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 4982 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 4990 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 4998 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 5002 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 5006 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 5016 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 5024 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 5032 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 5036 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 5040 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 5048 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 5052 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 5058 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 5064 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 5068 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 5078 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 5086 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 5090 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 5096 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 5105 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 5114 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 5120 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 5126 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 5136 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 5153 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 5160 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 5175 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 5211 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 5215 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 5223 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 5231 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 5243 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 5247 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 5255 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 5263 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 5267 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 5278 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 5295 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 5301 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 5307 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 5317 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 5321 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 5327 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 5333 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 5337 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 5343 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 5347 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 5353 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 5359 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 5366 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 5376 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 5381 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 5389 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 5395 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 5405 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 5427 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 5436 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 5442 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 5455 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 5469 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 5476 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 5482 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 5492 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 5501 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 5509 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 5515 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 5533 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 5541 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 5545 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 5552 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 5557 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 5565 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 5569 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 5576 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 5580 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 5587 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 5591 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 5598 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 5602 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 5611 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 5623 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 5627 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 5634 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 5638 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 5646 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 5654 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 5662 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 5666 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 5673 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 5677 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 5685 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 5696 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 5700 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 5708 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 5720 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 5726 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 5735 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 5739 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 5747 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 5751 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 5755 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 5762 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 5766 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 5773 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 5777 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 5785 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 5789 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 5793 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 5797 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 5801 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 5809 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 5817 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 5829 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 5841 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 5845 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 5849 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 5857 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 5863 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 5873 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 5877 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 5881 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 5885 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 5889 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 5893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 5897 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 5901 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 5909 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 5913 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 5917 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 5921 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 5929 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 5935 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 5945 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 5955 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 5959 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 5967 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 5977 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 5988 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 5995 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 5999 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 6006 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 6010 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 6017 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 6022 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 6031 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 6040 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 6044 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 6051 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 6055 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 6063 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 6072 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 6079 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 6089 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 6093 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 6100 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 6106 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 6115 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 6119 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 6126 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 6131 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 6143 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 6151 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 6163 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 6171 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 6175 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 6183 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 6187 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 6191 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 6199 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 6207 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 6211 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 6215 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 6219 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 6227 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 6235 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 6247 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 6251 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 6259 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 6277 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 6290 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 6291 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 6292 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 6293 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 6294 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 6295 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 6296 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 6297 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 6298 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 6299 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 6300 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 6301 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 6302 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 6303 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 6304 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 6309 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 6310 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 6311 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 6312 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 6313 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 6314 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 6315 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 6316 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 6317 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 6318 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 6319 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 6320 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 6321 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 6322 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 6323 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 6324 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 6325 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 6326 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 6327 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 6328 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 6329 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 6330 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 6331 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 6332 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 6333 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 6334 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 6335 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 789:

/* Line 690 of lalr1.cc  */
#line 6336 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 6337 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 791:

/* Line 690 of lalr1.cc  */
#line 6338 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 792:

/* Line 690 of lalr1.cc  */
#line 6339 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 793:

/* Line 690 of lalr1.cc  */
#line 6340 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 6341 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 6342 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 796:

/* Line 690 of lalr1.cc  */
#line 6343 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 6344 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 798:

/* Line 690 of lalr1.cc  */
#line 6345 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 6346 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 6347 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 6348 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 802:

/* Line 690 of lalr1.cc  */
#line 6349 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 803:

/* Line 690 of lalr1.cc  */
#line 6350 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 6351 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 805:

/* Line 690 of lalr1.cc  */
#line 6352 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 6353 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 6354 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 6355 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 6356 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 6357 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 6358 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 6359 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 6360 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 6361 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 6362 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 6363 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 6364 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 6365 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 6366 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 6367 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 6368 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 6369 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 6370 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 6371 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 6372 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 6373 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 6374 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 6375 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 6376 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 6377 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 6378 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 6379 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 6380 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 6381 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 6382 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 6383 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 6384 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 6385 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 6386 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 6387 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 6388 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 6389 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 6390 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 6391 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 6392 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 6393 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 6394 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 6395 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 6396 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 6397 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 6398 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 6399 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 6400 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 6401 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 6402 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 6403 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 6404 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 6405 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 6406 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 6407 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 6408 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 6409 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 6410 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 6411 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 6412 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 6413 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 6414 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 6415 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 6416 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 6417 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 6418 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 6419 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 6420 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 6421 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 6422 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 6423 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 6424 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 6425 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 6426 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 6427 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 6428 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 6429 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 6430 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 6431 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 6432 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 6433 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 6434 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 6435 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 6436 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 6437 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 6438 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 6439 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 6440 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 6441 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 6442 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 6443 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 6444 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 6445 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 6446 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 6447 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 6448 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 6449 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 6450 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 6451 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 6452 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 6453 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 6454 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 6455 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 6456 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 6457 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 6458 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 6459 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 6460 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 6461 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 6462 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 6463 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 6464 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 6465 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 6466 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 6467 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 6468 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 6469 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 6470 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 6471 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 6472 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 6473 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 6474 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 6475 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 6476 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 6477 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 6478 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 6479 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 6480 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 6481 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 6482 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 6483 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 6484 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 6485 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 6486 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 6487 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 6488 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 6489 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 6490 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 6491 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 6492 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 6493 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 6494 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 6495 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 6496 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 6497 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 6498 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 6499 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 6500 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 6501 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 6502 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 6503 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 6504 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 6505 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 6506 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 6512 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
          // EQName's namespace URI value is whitespace normalized according to the rules for the xs:anyURI type
          std::string uri = "\"" + SYMTAB((yysemantic_stack_[(3) - (1)].sval)) + "\"";
          std::string eqname = SYMTAB(driver.symtab.put_uri(uri.c_str(), uri.size())) + ":" + SYMTAB((yysemantic_stack_[(3) - (3)].sval));
          (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT(eqname.c_str())), true);
        }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 6518 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 11564 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1380;
  const short int
  xquery_parser::yypact_[] =
  {
      3015, -1380, -1380, -1380,  4506,  4506,  4506, -1380, -1380,    59,
     171,   296,   859,   335, -1380, -1380, -1380,   620, -1380, -1380,
   -1380,   202,   283,   684,   281,   472,   609,   696, -1380,   -38,
   -1380, -1380, -1380, -1380, -1380, -1380,   716, -1380,   671,   677,
   -1380, -1380, -1380, -1380,   406, -1380,   718, -1380,   704,   711,
   -1380,    56, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380,   534,   730, -1380, -1380,
   -1380, -1380,   571,  8976, -1380, -1380, -1380,   762, -1380, -1380,
   -1380,   769, -1380,   780,   801, -1380, -1380, 12716, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380,   773, -1380, -1380,   806,
     807, -1380, -1380, -1380, -1380, -1380, -1380, -1380,  3314,  6294,
   12716, -1380, -1380, -1380, -1380, -1380, -1380, -1380,   745, -1380,
   -1380,   808,  9860, -1380, 10151,   810,   812, -1380, -1380, -1380,
     814, -1380,  8678, -1380, -1380, -1380, -1380, -1380, -1380,   774,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,    71,   722,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,   -42,   783,
     652, -1380,   721,   367, -1380, -1380, -1380, -1380, -1380, -1380,
     822, -1380,   701,   708,   710, -1380, -1380,   793,   797, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380,  4804,   952, -1380,  5102, -1380, -1380,   146,    64,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380,    88, -1380, -1380, -1380, -1380, -1380,
   -1380,   114, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
    4506, -1380, -1380, -1380, -1380,    39, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380,   846, -1380,   765, -1380, -1380, -1380,
     487, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,   789,
     865, -1380,   803,   715,   860,   546,   530,   570,   602, -1380,
     912,   767,   863,   866,  7486, -1380, -1380, -1380,    11, -1380,
   -1380,  8678, -1380,   610, -1380,   813,  8976, -1380,   813,  8976,
   -1380, -1380, -1380,   727, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380,   848,   829,   819, -1380,
   -1380, -1380, -1380, -1380,   792, -1380,  4506,   794,   795,   394,
     394,   948,   195,   566,   469, 13001, 12716,    -9,   933, 12716,
     831,   867,   278,  9860,   628,   736, 12716, 12716,   681,   697,
      25, -1380, -1380, -1380,  9860,  4506,   800,  4506,    73,  7784,
   10721,   705,   713, 12716,   871,    31,   838,  7784,   991,   136,
     293, 12716,   876,   857,   893, -1380,  7784,  9567, 12716, 12716,
   12716,  4506,   816,  7784,  7784, 12716,  4506,   851,   858, -1380,
   -1380, -1380,  7784, 11006, -1380,   861, -1380,   862, -1380, -1380,
   -1380, -1380,   864, -1380,   868, -1380, -1380, -1380, -1380, -1380,
     869, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, 12716, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380,   873, 12716, -1380, -1380, -1380,   832,  3612,   872,   875,
     877, 12716,  4506, -1380,   870,    19, -1380,   506,   978,  7784,
   -1380, -1380,    66, -1380, -1380, -1380,  1004, -1380, -1380, -1380,
   -1380,  7784,   809, -1380,   998,  7784,  7784,   842,  7784,  7784,
    7784,  7784,   804, 12716,   845,   847,  7784,  7784,  3314,   796,
   -1380, -1380, -1380, -1380,   859,   696,    93,    95,  1033,  5400,
    5400,  5698,  5698,   769, -1380, -1380,   846,   769, -1380,  7784,
   -1380,   921,   281,   -38,   874,   878,   880,  4506,  7784, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380,  8082,  8082,  8082,
   -1380,  8082,  8082, -1380,  8082, -1380,  8082, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380,  8082,  8082,   971,  8082,  8082,  8082,
    8082,  8082,  8082,  8082,  8082,  8082,  8082,  8082,  8082,   821,
     949,   972,   973, -1380, -1380, -1380,  6592, -1380, -1380,  8678,
    8678,  7784,   813, -1380, -1380,   813, -1380,  6890,   813,  9860,
     916,  7188, -1380, -1380, -1380, -1380,   224, -1380,   229, -1380,
   -1380, -1380, -1380, -1380,   961,   962,   472,  1041, -1380, -1380,
   13001,   975,   543, 12716,   911,   913,   975,   948,   945,   942,
   -1380, -1380, -1380,   612,   830,   983,   781, 12716,   938,  7784,
     963, 12716, 12716, -1380,   950,   899,  4506, -1380,   900,   862,
     677, -1380,   898,   901,    40, -1380,   231,   237, -1380, -1380,
     980, -1380,     9, 12716,    12, 12716,   995,   242, -1380,  4506,
   -1380,   243, -1380,  9860,   994,  1046,  9860,   948,   996,   234,
   12716,  7784,   -38,   256,   906, -1380,   907,   908,   909,    43,
   -1380,   279,   914, -1380,   249,   258,   946, -1380,   918,  4506,
    4506,   303, -1380,   267,   276,   492,  7784,    79, -1380, -1380,
    7784,  7784,  7784, -1380,  7784, -1380,  7784, 12716,   978, -1380,
       3,   330, -1380, -1380, -1380,   365, -1380,    32, -1380, -1380,
   -1380,    26,   376,  1006,   881,   879,    27, -1380,   964, -1380,
   -1380,   917,   287,  3910,   381,  9274,   796, -1380,   146,   616,
    1071,  1071, -1380, -1380,    96, -1380, -1380,    99, -1380,    57,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, 12716,   939,  7784,
     990, -1380, -1380, -1380,   865, -1380, -1380, -1380, -1380, -1380,
    8082, -1380, -1380, -1380,    48, -1380,   530,   530,   368,   570,
     570,   570,   570,   602,   602, -1380, -1380, 12146, 12146, 12716,
   12716, -1380,   429, -1380, -1380,   286, -1380, -1380, -1380,   307,
   -1380, -1380, -1380,   343,   394, -1380, -1380,   502,   531,   659,
   -1380,   472, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380,   975, -1380,   979, 12431,   968,  7784, -1380, -1380,
   -1380,  1018,   948,   948,   975, -1380,   692,   948,   431, 12716,
     369,   477,  1084, -1380, -1380,   833,   544, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,   612,    83,
     888,   525,  7784, -1380, 12716,  1022,   823,   948, -1380, -1380,
   -1380, -1380,   967, 12716, -1380, 12716, -1380,  1005,   997, 12146,
    1007,  7784,   -36,   981,    28,   501,   882, -1380, -1380,   625,
      12,  1018, 12146,  1009,  1035,   947,   925,  1001,   948,   970,
    1002,  1040,   948,  7784,     1, -1380, -1380, -1380,   984, -1380,
   -1380, -1380, -1380,  1021,  7784,  7784,   993, -1380,  1042,  1043,
    4506, -1380,   957,   960,  1003, 12716, -1380, 12716, -1380,  7784,
    1012,   956,  7784,   374,   384,   385,  1113, -1380,    18, -1380,
     201, -1380, -1380,  1120, -1380,   662,  7784,  7784,  7784,   670,
    7784,  7784,  7784,  7784,  7784,  7784,  1039,  7784,  7784, -1380,
    5996,  1008,  1010,  1011,  1015,   765,   560,   915, -1380,   233,
   -1380,   105,    38,    57,  5698,  5698,  5698,  1072, -1380,  7784,
     683,  1055, -1380, 12716,  1056, -1380, -1380,  7784,    48,   184,
      14, -1380,   886,   151,   919,   920, -1380, -1380,   736, -1380,
     905,   511,  1019,  1024, 12431,  1025, -1380,   245, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380,  1034, -1380, -1380,
   -1380,  7784, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380,   660, -1380,  1136,   714, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380,   892, -1380, -1380,  1154, -1380, -1380,
   -1380, -1380, -1380,   549,  1155, -1380,   603, -1380, -1380, -1380,
     861,   283,   864,   671,   868,   869,   783, -1380,   245,  8380,
     902,   884, -1380,  1018,    83,   959,  1013,  4506,   999,  1000,
    1047,  1017,  1020, 12716,    58, -1380, 12716, -1380,  7784,  1045,
    7784,  1067,  7784,    46,  1048,  7784,  1049, -1380,  1079,  1080,
    7784, 12716,   805,  1122, -1380, -1380, -1380, -1380, -1380, -1380,
   12146, -1380,  4506,   948,  1093, -1380, -1380, -1380,   948,  1093,
   -1380,  7784,  1060,  4506, 12716, -1380, -1380,  7784,  7784,   597,
   -1380,    21,   674, -1380, 11291,   691, -1380,   706, -1380,  1026,
   -1380, -1380,  4506,  1027,  1029, -1380,  7784, -1380, -1380,  1014,
    1042,  1109, -1380,  1081, -1380,   207, -1380, -1380,  1210, -1380,
   -1380,  4506, 12716, -1380,   507, -1380, -1380, -1380,  1031,   986,
     987, -1380, -1380, -1380,   992,  1016, -1380, -1380, -1380, -1380,
   -1380,  1030, 12716,  1036, -1380, -1380,  7784,  7784,  7784,  4208,
    5996,  9274,   915, -1380,  9274, -1380,  1071,    72, -1380, -1380,
   -1380,  1055, -1380,   948, -1380,   776, -1380,    81,  1121, -1380,
    7784,  1123,   990,   462,  1050, -1380,    48,   977, -1380, -1380,
     -50, -1380,   113,    16,   989,    48,   113,  8082, -1380,    63,
   -1380, -1380, -1380, -1380, -1380, -1380,    48,  1083,   954,   830,
      16, -1380, -1380,   943,  1158, -1380, -1380, -1380, 10436,  1053,
    1054,  1057, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380,  1213,   262,  1214,   262,   982,  1138,
   -1380,  1077, 12716,  1032, -1380, -1380,  8380, -1380,  1065, -1380,
   -1380, -1380, -1380, -1380, -1380,  7784,  1104, -1380, -1380,  7784,
   -1380,    65, -1380,  7784,  1107,  7784, -1380,  7784, 12716, 12716,
   -1380,   556, -1380,  7784, -1380,  1129,  1131,  1162,   948,  1093,
   -1380,  7784,  1085, -1380, -1380, -1380,  1086, -1380,   182,  7784,
    4506,  1087,   221, -1380, 12716,  1088, 11576,    34, -1380, 11861,
    1089, -1380, -1380,  1092, -1380, -1380, -1380,  7784,   709,  1113,
   12716,   661, -1380,  1094,  1113, 12716, -1380, -1380,  7784,  7784,
    7784,  7784,  7784, -1380,  7784,   405,   412,   432,   375, -1380,
   -1380, -1380, -1380, -1380,  1121, -1380, -1380, -1380,   948, -1380,
   -1380, -1380, -1380, -1380,  1096,  8082, -1380, -1380, -1380, -1380,
   -1380,   348,  8082,  8082,   515, -1380,   919, -1380,   332, -1380,
     920,    48,  1110, -1380, -1380,  1023, -1380, -1380, -1380, -1380,
    1171,  1090, -1380,   434, -1380, -1380, -1380, -1380,   275,   275,
   -1380,   262, -1380, -1380,   457, -1380,  1241,    16,  1185,  1095,
    8380,    -3,  1037,  1115, -1380, -1380,  7784, -1380,  7784,  1139,
   -1380,  7784, -1380, -1380, -1380,  1230, -1380, -1380,  5996,  7784,
     948, -1380, -1380, -1380,  7784,  7784, -1380, -1380, -1380,  5996,
    5996,  1193,  4506, 12716,  1103, 12716,  7784, 12716,  1105,  5996,
   -1380,    37,    36,  1113, 12716, -1380,  1097,  1113, -1380, -1380,
   -1380, -1380, -1380, -1380,  1098,  1042,  1043,  7784, -1380, -1380,
   -1380, -1380,   570,  8082,  8082,   368,   557, -1380, -1380, -1380,
   -1380, -1380, -1380,  7784, -1380, 12146, -1380, 12146,  1196, -1380,
   -1380, -1380,  1263, -1380, -1380, -1380,  1044,  1187, -1380, -1380,
    1189, -1380,    77, 12716,  1179,  1075, 12716,  8380, -1380, -1380,
    7784, -1380,  1182, -1380, -1380,  1093, -1380, -1380, 12146, -1380,
   -1380,  1207,  7784,  1117, -1380,  1211,  5996, -1380, 12716,   176,
     400, -1380,  1111,  1113, -1380,  1114,  5996,   717,   491,   368,
     368,  8082,   519, -1380, -1380, 12146, -1380, -1380,  1185,  8380,
   -1380,  1121,  1038, 12716,  1188,  1091,  1189, -1380, 12716,  1125,
   12146,  4506, 12146,  1126, -1380, -1380,  1216,   500, -1380, -1380,
   -1380, -1380,  1135,   538, -1380, -1380, -1380,  1118, -1380,  1201,
   -1380,   368, -1380, -1380, -1380, -1380, -1380,  7784,  1051, 12716,
    1202, -1380,  4506,  1140, -1380, -1380,  1141,  7784, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, 12716, -1380,  1052,  1058, 12716,
   -1380, -1380,  7784,  5996,  1142,  1061,  7784,  1063,  5996,  8380,
   -1380,  8380, -1380,  1124,  1064, 12716,  1100,  1203, 12716,  1066,
    8380, -1380
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       159,   440,   441,   442,   162,   162,   162,   762,   961,   116,
     118,   590,   854,   863,   803,   767,   765,   747,   855,   858,
     810,   771,   748,   749,   802,   864,   751,   861,   832,   812,
     787,   807,   808,   859,   856,   806,   753,   862,   754,   755,
     903,   915,   902,   804,   823,   817,   756,   805,   758,   757,
     904,   841,   842,   809,   784,   925,   926,   927,   928,   929,
     930,   931,   932,   933,   934,   935,   949,   956,   831,   827,
     818,   798,   746,     0,   826,   834,   843,   950,   822,   462,
     799,   800,   857,   951,   957,   819,   836,     0,   468,   429,
     464,   829,   764,   820,   821,   850,   824,   840,   849,   955,
     958,   770,   811,   852,   463,   839,   845,   750,     0,     0,
       0,   377,   837,   848,   853,   851,   830,   816,   905,   814,
     815,   952,     0,   376,     0,   953,   959,   846,   801,   825,
     954,   407,     0,   439,   847,   828,   835,   844,   838,   906,
     792,   797,   796,   795,   794,   793,   759,   813,     0,   763,
     860,   785,   894,   893,   895,   769,   768,   788,   900,   752,
     892,   897,   898,   889,   791,   833,   891,   901,   899,   890,
     789,   896,   910,   911,   908,   909,   907,   760,   912,   913,
     914,   880,   879,   866,   783,   776,   873,   869,   786,   782,
     881,   882,   772,   773,   766,   775,   878,   877,   874,   870,
     887,   888,   886,   876,   872,   865,   774,   885,   884,   778,
     780,   779,   871,   875,   867,   781,   868,   777,   883,   936,
     937,   938,   939,   940,   941,   917,   918,   916,   922,   923,
     924,   919,   920,   921,   790,   942,   943,   944,   945,   946,
     947,   948,   159,     0,     2,   159,     5,     7,    19,     0,
      24,    27,    32,    33,    34,    35,    36,    37,    38,    28,
      54,    55,    29,    30,     0,    72,    75,    76,    31,    77,
      78,     0,   114,    79,    80,    81,    82,    14,   156,   157,
     158,   165,   167,   459,   168,     0,   169,   170,   171,   172,
     173,   174,   175,   178,   163,   204,   211,   206,   233,   239,
       0,   231,   232,   213,   207,   177,   208,   176,   209,   212,
     330,   332,   334,   344,   346,   350,   352,   355,   360,   363,
     366,   368,   370,   372,     0,   374,   380,   382,     0,   398,
     381,   403,   406,   408,   411,   413,     0,   418,   415,     0,
     426,   436,   438,   412,   443,   450,   460,   451,   452,   453,
     456,   457,   454,   455,   475,   477,   478,   479,   476,   524,
     525,   526,   527,   528,   529,   435,   564,   556,   563,   562,
     561,   558,   560,   557,   559,   461,   458,   591,   592,    39,
     214,   215,   217,   216,   218,   210,     0,   437,   745,   761,
     854,   863,   861,   763,     0,   160,   161,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   122,   124,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   258,   259,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   431,
     434,   421,     0,     0,   742,   747,   771,   749,   802,   864,
     751,   812,   753,   823,   756,   758,   757,   841,   949,   956,
     746,   950,   800,   951,   957,   824,   955,   958,   905,   952,
     953,   959,   954,   906,   900,   892,   898,   889,   789,   910,
     911,   908,   760,   912,   427,   437,   745,   419,     0,   185,
     420,   423,   747,   748,   749,   753,   754,   755,   756,   746,
     752,   465,     0,   425,   424,   180,     0,     0,   751,   758,
     757,     0,   162,   466,   912,     0,   211,     0,   491,     0,
     430,   743,     0,   744,   401,   402,     0,   433,   432,   422,
     405,     0,     0,   520,     0,     0,     0,     0,     0,     0,
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
       0,     0,   531,   533,   537,   590,     0,   120,     0,    43,
      40,    41,    44,    45,     0,     0,     0,     0,    46,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     601,   602,   603,     0,    99,   138,     0,     0,   108,     0,
       0,     0,     0,   123,     0,     0,     0,   570,     0,     0,
       0,   566,     0,     0,     0,   580,     0,     0,   221,   222,
     241,   242,     0,     0,     0,     0,   130,     0,   134,   162,
     594,     0,    56,     0,    65,     0,     0,     0,    57,     0,
       0,     0,     0,     0,   742,   571,     0,     0,     0,     0,
     303,     0,     0,   569,     0,     0,     0,   588,     0,     0,
       0,     0,   574,     0,     0,   187,     0,     0,   181,   179,
       0,     0,     0,   465,     0,   467,     0,   492,   491,   488,
       0,     0,   522,   521,   400,     0,   519,     0,   614,   615,
     565,     0,     0,     0,     0,     0,     0,   620,     0,   195,
     196,     0,     0,     0,     0,     0,   200,   201,    20,     0,
      21,     0,     4,    25,     0,    11,    26,     0,    15,   854,
      73,    12,    74,    16,   186,   184,   205,     0,     0,     0,
       0,   198,   220,   276,   331,   333,   337,   343,   342,   341,
       0,   338,   335,   336,     0,   347,   354,   353,   351,   357,
     358,   359,   356,   361,   362,   365,   364,     0,     0,     0,
       0,   396,     0,   409,   410,     0,   448,   445,   473,     0,
     960,   593,   471,     0,     0,   117,   119,     0,     0,     0,
      98,     0,    88,    90,    91,    92,    93,    95,    96,    97,
      89,    94,    84,    85,     0,     0,   104,     0,   100,   102,
     103,   110,     0,     0,    83,    42,     0,     0,     0,     0,
       0,     0,     0,   692,   697,     0,     0,   693,   727,   680,
     682,   683,   684,   686,   688,   687,   685,   689,     0,     0,
       0,     0,     0,   107,     0,   140,     0,     0,   536,   530,
     567,   568,     0,     0,   584,     0,   581,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   223,   224,     0,
     229,   136,     0,     0,   131,     0,     0,     0,     0,     0,
       0,    58,     0,     0,     0,   257,   263,   260,     0,   573,
     572,   579,   587,     0,     0,     0,     0,   535,     0,     0,
       0,   392,     0,     0,     0,     0,   577,     0,   575,     0,
     188,     0,     0,     0,     0,     0,   491,   489,     0,   480,
       0,   469,   470,     0,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   193,
       0,   751,   758,   757,   912,     0,     0,     0,   628,     0,
     202,     0,     0,     0,   159,   159,   159,     0,   230,     0,
     287,   283,   285,     0,   277,   278,   340,     0,     0,     0,
       0,   658,   348,   631,   635,   637,   639,   641,   644,   651,
     652,   660,   864,   750,     0,   759,   367,   542,   548,   549,
     551,   595,   596,   552,   555,   369,   371,   539,   373,   397,
     449,     0,   446,   472,   121,    52,    53,    50,    51,   127,
     126,     0,    86,     0,     0,   105,   106,   111,    70,    71,
      48,    49,    69,   698,     0,   701,   728,     0,   691,   690,
     695,   694,   726,     0,     0,   703,     0,   699,   702,   681,
       0,     0,     0,     0,     0,     0,     0,   139,   142,     0,
       0,     0,   109,   112,     0,     0,     0,   162,     0,     0,
     588,     0,     0,     0,     0,   541,     0,   244,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   225,     0,     0,
       0,     0,   270,     0,   267,   272,   228,   137,   132,   135,
       0,   182,     0,     0,    67,    61,    64,    63,     0,    59,
     261,     0,     0,   162,     0,   301,   305,     0,     0,     0,
     308,     0,     0,   314,     0,     0,   321,     0,   325,     0,
     394,   393,   162,     0,     0,   189,     0,   191,   302,     0,
       0,     0,   492,     0,   481,     0,   515,   512,     0,   516,
     517,     0,     0,   511,     0,   486,   514,   513,     0,     0,
       0,   607,   608,   604,     0,     0,   612,   613,   609,   618,
     616,     0,     0,     0,   622,   194,     0,     0,     0,     0,
       0,     0,   623,   624,     0,   203,    22,     0,    13,    17,
      18,   284,   296,     0,   297,     0,   288,   289,   290,   291,
       0,   280,     0,     0,     0,   642,   655,     0,   345,   349,
       0,   674,     0,     0,     0,     0,     0,     0,   630,   632,
     633,   669,   670,   671,   673,   672,     0,     0,   646,   645,
       0,   649,   653,   667,   665,   664,   657,   661,     0,     0,
       0,     0,   545,   547,   546,   543,   540,   474,   129,   128,
      87,   101,   715,   696,     0,   720,     0,   720,   709,   704,
     143,     0,     0,     0,   113,   141,     0,    23,     0,   585,
     586,   589,   582,   583,   243,     0,     0,   256,   248,     0,
     252,     0,   246,     0,     0,     0,   265,     0,     0,     0,
     227,   268,   271,     0,   133,     0,     0,    66,     0,    60,
     262,     0,     0,   304,   306,   311,     0,   309,     0,     0,
       0,     0,     0,   315,     0,     0,     0,     0,   322,     0,
       0,   326,   395,     0,   578,   576,   190,     0,     0,   491,
       0,     0,   523,     0,   491,     0,   487,    10,     0,     0,
       0,     0,     0,   621,     0,     0,     0,     0,     0,   625,
     629,   300,   298,   299,   292,   293,   294,   286,     0,   281,
     279,   659,   650,   656,     0,     0,   729,   730,   740,   739,
     738,     0,     0,     0,     0,   731,   636,   737,     0,   634,
     638,     0,     0,   643,   647,     0,   668,   663,   666,   662,
       0,     0,   553,     0,   550,   600,   544,   716,     0,     0,
     714,   721,   722,   718,     0,   713,     0,   711,     0,     0,
       0,     0,     0,     0,   532,   245,     0,   254,     0,     0,
     250,     0,   253,   266,   274,   275,   269,   226,     0,     0,
       0,    62,   264,   538,     0,     0,   312,   316,   310,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     534,     0,     0,   491,     0,   518,     0,   491,   605,   606,
     610,   611,   617,   619,     0,     0,     0,     0,   626,   295,
     282,   654,   741,     0,     0,   733,     0,   679,   678,   677,
     676,   675,   640,     0,   732,     0,   597,     0,     0,   725,
     724,   723,     0,   717,   710,   708,     0,   705,   706,   700,
     144,   146,   148,     0,     0,     0,     0,     0,   249,   247,
       0,   255,     0,   199,   329,    68,   307,   313,     0,   327,
     323,     0,     0,     0,   317,     0,     0,   319,     0,   501,
     495,   490,     0,   491,   482,     0,     0,     0,     0,   735,
     734,     0,     0,   598,   554,     0,   719,   712,     0,     0,
     150,   149,     0,     0,     0,     0,   145,   251,     0,     0,
       0,     0,     0,     0,   509,   503,     0,   502,   504,   510,
     507,   497,     0,   496,   498,   508,   484,     0,   483,     0,
     627,   736,   648,   599,   707,   147,   151,     0,     0,     0,
       0,   273,     0,     0,   320,   318,     0,     0,   494,   505,
     506,   493,   499,   500,   485,     0,   152,     0,     0,     0,
     328,   324,     0,     0,     0,     0,     0,     0,     0,     0,
     154,     0,   153,     0,     0,     0,     0,     0,     0,     0,
       0,   155
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1380, -1380,  -210,  1099, -1380,  1101,  1102, -1380,  1082,  -517,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
    -951, -1380, -1380, -1380, -1380,  -238,  -548, -1380,   639,   -76,
   -1380, -1380, -1380, -1380, -1380,   225,   435, -1380, -1380,   -11,
    -164,   932, -1380,   923, -1380, -1380,  -615, -1380,   370, -1380,
     190, -1380,  -252,  -293, -1380,  -524, -1380,    13,    22,    86,
    -258,  -175, -1380,  -826, -1380, -1380,   211, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380,   532,   -84,  1351,
       0, -1380, -1380, -1380, -1380,   377, -1380, -1380,  -291, -1380,
       8, -1380, -1380,   186,  -702,  -684, -1380, -1380,   598, -1380,
   -1380,   -22,   179, -1380, -1380, -1380,    70, -1380, -1380,   304,
      74, -1380, -1380,    80, -1234, -1380,   834,   165, -1380, -1380,
     161,  -972, -1380, -1380,   159, -1380, -1380, -1179, -1157, -1380,
     156, -1380, -1380,   758,   761, -1380,  -543,   746, -1380, -1380,
    -628,   112,  -602,   272,   280, -1380, -1380, -1380, -1380, -1380,
    1062, -1380, -1380, -1380, -1380,  -820,  -313, -1098, -1380,   -72,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380,   -23,  -758, -1380,
   -1380,   523,   189, -1380,  -364, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380,   719, -1380,  -970, -1380,   147, -1380,   596,  -771,
   -1380, -1380, -1380, -1380, -1380,  -278,  -271, -1132,  -884, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,   517,
    -728,  -760,   240,  -781, -1380,    54,  -772, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380,   951,   953,  -261,   437,   282, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380,   132, -1380, -1380,   125, -1380,   127, -1012,
   -1380, -1380, -1380,    94,    85,   -69,   334, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
      97, -1380, -1380, -1380,   -63,   329,   471, -1380, -1380, -1380,
   -1380, -1380,   274, -1380, -1380, -1379, -1380, -1380, -1380,  -559,
   -1380,    67, -1380,   -80, -1380, -1380, -1380, -1380, -1200, -1380,
     106, -1380,  -352,  -354,  1028,    52, -1380
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   243,   811,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
    1184,   737,   261,   262,   263,   264,   265,   266,   892,   893,
     894,   267,   268,   269,   898,   899,   900,   270,   419,   271,
     272,   666,   273,   421,   422,   423,   436,   727,   728,   274,
    1137,   275,  1580,  1581,   276,   277,   278,   526,   279,   280,
     281,   282,   283,   730,   284,   285,   509,   286,   287,   288,
     289,   290,   291,   599,   292,   293,   806,   807,   294,   295,
     536,   297,   600,   434,   959,   960,   298,   601,   299,   603,
     537,   301,   720,   721,  1172,   443,   302,   444,   445,   724,
    1173,  1174,  1175,   604,   605,  1054,  1055,  1439,   606,  1051,
    1052,  1276,  1277,  1278,  1279,   303,   749,   750,   304,  1199,
    1200,  1388,   305,  1202,  1203,   306,   307,  1205,  1206,  1207,
    1208,   308,   309,   310,   311,   840,   312,   313,  1288,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   624,   625,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   652,   653,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   869,   353,   354,   355,  1234,   778,   779,   780,
    1611,  1652,  1653,  1646,  1647,  1654,  1648,  1235,  1236,   356,
     357,  1237,   358,   359,   360,   361,   362,   363,   364,  1086,
     954,  1076,  1325,  1077,  1473,  1078,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   756,  1149,   375,   376,
     377,   378,  1080,  1081,  1082,  1083,   379,   380,   381,   382,
     383,   384,   796,   797,   385,  1262,  1263,  1548,  1039,  1062,
    1298,  1299,  1063,  1064,  1065,  1066,  1067,  1308,  1463,  1464,
    1068,  1311,  1069,  1444,  1070,  1071,  1316,  1317,  1469,  1467,
    1300,  1301,  1302,  1303,  1560,   694,   919,   920,   921,   922,
     923,   924,  1127,  1489,  1577,  1128,  1487,  1575,   925,  1337,
    1484,  1480,  1481,  1482,   926,   927,  1304,  1312,  1454,  1305,
    1450,  1289,   386,   542,   387,   388,   389
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int xquery_parser::yytable_ninf_ = -743;
  const short int
  xquery_parser::yytable_[] =
  {
       296,   420,   848,   569,   296,   296,   296,  1008,   300,   602,
     577,   974,   300,   300,   300,   647,  1201,   394,   397,   398,
     952,  1189,   585,   986,  1060,   535,   395,   395,   395,   849,
     850,   851,   852,   820,   822,   667,   667,  1000,   953,   580,
    1233,  1341,  1408,  1435,  1436,   948,  1284,  1038,  1398,   669,
     504,     9,    10,  1100,   582,   815,   818,   821,   823,   689,
     550,   879,   813,   816,  1161,   578,   836,   956,   837,   838,
     704,   839,   405,   841,   782,   401,   402,   665,   403,   404,
     441,   842,   843,     9,    10,  1079,  1079,   734,   738,   578,
     396,   396,   396,   746,   578,   407,   578,   578,  1085,   408,
     578,   552,  1416,   949,   405,   950,   578,   584,   296,  1578,
    1465,  1158,  1451,   406,  1104,  1583,   300,   684,   709,   685,
    1015,  1389,  1130,  1079,   950,   506,   589,  1131,   709,  1609,
     395,   408,   455,  1009,  1026,   710,   409,   700,   585,   506,
       9,    10,  1132,  1191,  1133,   710,   587,   589,  1224,   725,
     983,  1267,  1525,  1134,   950,  1608,   951,  1138,    79,  1290,
     678,   950,   506,  1013,   646,   464,  1446,  1286,   410,   411,
    1047,   949,    90,  1107,   506,  1162,   506,  1079,   687,   574,
    1135,  1644,   555,  1273,   556,  1226,   983,  1273,   124,  1155,
    1079,   124,   679,  1363,   527,   575,   586,   104,   413,  1010,
    1549,  1057,  1178,  1447,  1058,  1355,   775,  1390,  1275,   456,
    1226,  1227,  1498,   665,  1225,   399,  1226,  1227,   726,  1610,
    1526,  1584,  1014,  1526,   942,   124,   583,  1166,   957,   588,
    1392,   984,  1291,  1177,   442,  1223,   442,  1379,  1060,  1060,
     688,   783,   296,  1016,  1017,   296,   602,  1290,  1493,  1664,
     300,  1398,  1163,   300,   579,  1233,   584,   414,  1018,   648,
     711,  1027,   820,   822,  1233,   958,  1101,  1002,  1159,   585,
    1164,  1452,  1453,   442,  1443,  1329,   457,   458,   581,  1416,
     296,   442,  1389,   808,   553,   810,  1044,  1576,   300,  1046,
    1192,   813,   816,  1320,    79,  1266,   733,  1056,   415,  1229,
     442,  1230,  1079,  1585,  1228,   870,  1059,  1136,    90,  1645,
    1228,   701,   586,   654,  1292,  1293,   656,  1294,   442,   702,
    1291,  1389,   464,   684,  1229,   685,  1230,   400,   949,  1231,
    1229,   874,  1230,   104,  1296,   905,   874,  1057,   943,   831,
    1058,   814,   817,   416,   945,   714,  1297,   431,  1630,   963,
     589,   417,   432,   731,  1231,   427,   589,   686,   110,   418,
    1231,   124,   743,   589,   110,   589,   809,  1617,  1515,   754,
     755,  1334,  1138,   949,   995,   122,   973,   670,   761,   967,
    1448,   122,   970,   997,   687,   971,  1259,  1449,   506,  1322,
     671,   506,  1582,   589,   589,  1232,   296,  1666,  1478,   433,
    1553,  1410,  1292,  1293,   300,  1294,   735,  1520,  1079,  1226,
     589,   875,  1295,   148,  1091,  1344,   876,  -742,   944,   148,
    1374,  1323,  1296,   665,   946,   296,   985,   296,  1650,   964,
     966,  1336,  1079,   300,  1297,   300,   988,   589,  1324,   428,
     978,  1233,  1264,   586,  1395,   989,   688,   705,   585,   708,
    1091,   296,  1356,   736,   996,   781,   296,   676,   506,   300,
    1398,   506,  1479,   998,   300,   506,  1060,   785,   506,   506,
    1019,  1090,   589,   752,  1030,  1060,   506,  1554,   758,  1364,
    1061,   589,   506,   802,   804,   506,  1060,   994,   589,  1582,
     628,   589,   589,   506,  1092,   424,   820,   822,   820,   506,
     506,   506,   506,  1038,    79,  1644,  1430,   506,   629,  1226,
    1094,   706,   589,   706,  1011,   506,  1226,  1227,    90,   589,
    1268,  1269,  1270,  1229,   450,  1230,   628,   296,  1547,   591,
    1093,  1582,   296,   592,  1651,   300,   589,   706,   593,   589,
     300,  1567,   706,   104,   629,   585,  1079,  1226,   591,  1012,
    1108,  1109,   592,  1231,   395,  1112,   594,   593,  1472,  1595,
     506,  1219,   862,   420,  1572,  1037,  1650,   865,   296,   589,
    1041,  1220,  1221,  1392,   506,   594,   300,   863,   864,   296,
     296,   296,   296,   506,  1264,  1146,   949,   300,   300,   300,
     300,   561,  1544,  1020,  1021,   949,   562,   296,   589,  1545,
    1557,  1702,   591,  1703,  1045,   300,   592,  1558,  1022,  1168,
    1228,   593,  1711,  1089,  1169,   506,  1185,  1559,   396,  1546,
    1185,  1568,   586,  1229,  1079,  1230,   589,  1079,   435,   594,
    1229,  1118,  1230,  1679,   999,   674,  1524,   895,  1532,  1528,
    1124,  1060,  1119,  1536,  1573,  1334,  1441,   631,  1165,  1042,
    1095,   675,   950,  1231,   803,   595,   459,  1125,   596,  1499,
    1231,  1229,  1335,  1230,   110,   575,   908,  1096,   909,  1458,
    1226,  1227,  1682,   597,   595,  1660,   632,   596,  1168,  1097,
     896,   122,  1148,  1169,  1151,   897,  1003,  1004,  1005,   633,
     804,  1231,   776,   461,  1061,  1061,  1098,  1198,   598,  1124,
    1126,  1415,  1170,  1662,   628,  1336,   296,  1113,  1114,  1115,
    1386,   506,   910,  1116,   300,   628,  1125,   598,   820,   148,
     438,   950,   629,   634,   462,  1649,  1655,   463,   595,   296,
     439,   596,   881,   629,  1213,   506,  1214,   300,   637,  1120,
     846,   847,   965,  1171,   630,   602,  1260,   647,   672,   506,
    1121,   395,   638,   506,   506,  1621,   440,  1313,  1314,   296,
     296,   673,  1612,  1649,  1228,   437,  1615,   300,   300,  1655,
     635,   598,  1255,   425,  1198,   506,   426,   506,  1272,   636,
    1315,   992,   993,  1557,  1229,   506,  1230,  1391,   506,  1273,
    1558,  1396,   506,  1079,   824,  1079,  1099,  1328,   825,  1274,
    1559,   649,   650,  1035,  1397,  1623,  1399,  1624,   420,  1396,
    1275,  1036,   729,   729,  1231,   396,  1102,  1396,   110,  1400,
    1110,  1111,  1531,  1140,  1555,  1556,  1079,   448,  1102,   506,
    1659,  1377,  1141,   449,   698,   122,  1185,   429,  1639,   699,
     430,   866,  1657,  1552,   866,   706,   706,   866,   690,   691,
     692,   896,   460,  1079,  1631,  1534,   897,   506,  1168,   569,
     453,   655,   911,  1169,  1265,  1663,   658,   454,  1079,   446,
    1079,   451,   447,   148,   452,   912,   558,   913,   559,   506,
    1673,   651,  1676,   657,   507,     9,    10,   508,   914,   915,
     916,   522,   917,  1239,   918,  1240,   401,   402,   539,   403,
     404,  1244,   510,  1245,  1432,  1433,   405,   853,   854,   506,
     506,   506,   506,  1087,  1087,   406,   407,   855,   856,  1569,
    1570,  1431,  1061,   511,  1375,  1619,  1620,   551,   523,   524,
     540,  1061,   547,   408,   548,   609,   549,   554,   409,   557,
     563,   564,  1061,   610,   611,   560,   612,   506,   565,   567,
     568,   566,   571,   589,   613,   590,   607,   608,   614,   627,
     615,   506,   639,   626,   641,   616,   640,   651,   642,   659,
     410,   411,   412,  1283,   660,   661,   662,   464,   663,   664,
     680,   693,   617,   682,   697,   683,   506,   707,   718,   723,
     296,   729,   732,  1661,   740,   506,   719,   506,   300,   741,
     742,   506,   831,   753,   759,   618,   619,   620,   621,   622,
     623,   760,  1209,   777,   506,   766,   768,   426,   430,   413,
     447,   784,   786,   774,   452,   463,  1511,   787,   770,   790,
    1035,   771,   420,   772,   795,   799,   812,   800,  1036,   827,
     805,   844,   828,   858,   296,   296,   296,   506,   829,   506,
     830,   857,   300,   300,   300,   882,   883,   884,   885,   886,
     887,   888,   889,   890,   891,   871,   859,   860,   877,   878,
     880,   902,   906,   903,   907,   928,   706,   929,   414,   930,
     932,   934,   937,   938,   939,   940,  1550,   947,   941,   962,
     968,   969,   972,   979,   980,   981,   982,  1061,   987,   990,
    1023,   505,   991,  1025,  1043,   506,  1028,  1029,  1053,  1049,
     897,  1103,   949,  1122,  1139,   521,  1144,  1024,  1123,   415,
    1147,  1145,  1182,  1153,  1154,  1156,   506,   725,  1160,  1180,
    1186,  1181,  1517,  1183,  1187,  1167,  1188,  1193,   538,  1194,
    1197,  1210,  1198,  1204,  1211,   416,  1217,   296,  1222,  1238,
     543,   686,   546,   417,  1216,   300,  1212,  1252,  1185,  1261,
    1348,   418,  1280,  1282,  1256,   665,  1257,  1258,  1259,   395,
    1287,  1310,  1425,  1426,  1427,  1318,  1306,  1332,  1326,  1307,
    1319,  1321,   296,  1333,  1338,  1346,  1349,  1350,  1342,  1343,
     300,  1351,  1359,   296,  1361,  1365,  1367,  1368,  1369,  1373,
    1378,   300,  1381,  1347,  1352,   506,  1382,  1353,   506,  1396,
    1402,  1407,   296,  1409,  1404,   395,  1405,  1412,  1418,  1419,
     300,  1417,  1424,   506,  1420,  1403,  1445,  1273,  1466,  1438,
    1461,   296,   506,   396,   395,  1462,  1468,  1442,  1455,   300,
    1474,  1475,  1477,  1483,  1476,  1488,   506,  1490,  1421,  1494,
    1593,  1496,  1486,  1413,  1501,  1508,   506,  1509,  1510,  1035,
    1035,  1597,  1517,  1563,  1599,  1565,  1422,  1036,  1036,  1513,
    1574,  1607,  1514,  1519,  1522,  1529,  1530,  1566,  1535,   396,
    1551,  1124,  1579,  1592,   506,  1587,  1590,  1598,  1492,  1602,
    1625,  1606,  1626,  1614,  1628,  1616,  1629,  1633,   396,  1634,
    1638,  1640,  1564,  1641,   506,  1642,  1669,  1656,  1627,  1678,
    1658,  1672,  1677,   506,  1684,  1670,   506,   706,  1681,  1685,
    1689,  1708,  1704,  1586,  1707,   904,  1692,  1693,  1698,  1331,
     576,  1105,   668,  1179,  1345,  1636,  1665,  1176,  1040,  1354,
     977,   570,  1667,   703,  1695,   803,   572,   573,  1599,  1506,
    1705,  1372,  1440,  1271,  1437,  1687,   767,  1434,  1375,  1383,
    1387,  1393,  1696,  1401,   505,   834,  1699,   505,  1701,   835,
     506,  1710,  1411,   845,  1007,  1683,  1680,  1088,  1340,   712,
     873,   713,  1152,  1674,  1423,  1330,   645,  1429,  1428,  1456,
     296,  1460,  1562,  1285,   506,  1561,  1459,  1309,   300,  1129,
    1339,  1571,  1457,     0,  1485,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1690,     0,     0,     0,     0,     0,
     506,   506,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   677,  1690,     0,   681,     0,     0,
    1674,   543,     0,     0,   695,   696,   506,     0,   506,     0,
       0,   506,   543,     0,     0,     0,     0,     0,   717,     0,
       0,   722,   506,  1618,     0,     0,     0,   506,     0,   739,
       0,     0,     0,     0,     0,   543,   747,   748,   751,  1622,
       0,     0,     0,   757,     0,     0,     0,     0,     0,     0,
       0,   764,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1035,     0,
       0,     0,     0,     0,     0,     0,  1036,     0,     0,  1035,
    1035,     0,   296,     0,     0,     0,     0,  1036,  1036,  1035,
     300,     0,     0,     0,     0,     0,   765,  1036,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     751,     0,     0,     0,     0,     0,     0,     0,     0,   773,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   506,     0,   506,     0,   506,
       0,     0,     0,     0,     0,     0,   506,     0,     0,     0,
       0,   798,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1035,     0,     0,     0,
       0,     0,     0,     0,  1036,     0,  1035,   506,     0,   506,
       0,     0,     0,     0,  1036,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   506,     0,     0,   506,     0,
       0,   296,     0,     0,     0,     0,     0,     0,     0,   300,
     506,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     506,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   296,     0,     0,     0,     0,   506,     0,     0,
     300,     0,     0,     0,     0,   506,     0,   543,     0,     0,
     506,     0,   506,  1035,   506,     0,     0,     0,  1035,     0,
       0,  1036,     0,     0,     0,     0,  1036,     0,     0,     0,
       0,   901,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   506,     0,     0,     0,   931,     0,     0,     0,   935,
     936,     0,     0,     0,     0,     0,     0,   506,     0,     0,
       0,   506,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   955,     0,   961,     0,     0,     0,   506,     0,     0,
     506,   543,     0,     0,   543,     0,     0,     0,   975,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1006,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   505,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1048,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1084,  1084,  1084,  1084,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   788,   789,     0,   791,
     792,   793,   794,     0,     0,     0,     0,   801,     0,     0,
       0,     0,     0,  1084,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1117,     0,     0,
     826,     0,     0,     0,     0,     0,     0,     0,   832,   833,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1143,     0,     0,     0,     0,     0,     0,     0,
       0,  1150,     0,  1150,     0,     0,     0,  1084,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1084,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   868,     0,
       0,     0,   868,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   757,     0,   757,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     933,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1281,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   976,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1084,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1001,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   832,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1050,   722,     0,     0,  1357,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1371,
       0,     0,     0,     0,     0,     0,     0,     0,  1084,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   751,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1084,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1414,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     798,     0,     0,  1142,     0,     0,     0,     0,     0,   505,
       0,     0,   505,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1157,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1190,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1195,  1196,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1084,     0,     0,     0,
    1215,     0,     0,  1218,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1241,  1242,  1243,
    1491,  1246,  1247,  1248,  1249,  1250,  1251,     0,  1253,  1254,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1504,  1505,     0,     0,
    1050,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1521,     0,  1084,     0,     0,  1084,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1533,     0,
       0,     0,  1327,  1537,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1358,
       0,  1360,     0,  1362,     0,     0,  1366,     0,     0,     0,
       0,  1370,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1376,     0,     0,     0,     0,     0,     0,
       0,     0,  1380,     0,     0,     0,     0,     0,  1384,  1385,
       0,  1601,     0,  1603,     0,  1605,     0,     0,     0,     0,
       0,     0,  1613,     0,     0,     0,     0,  1406,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1084,     0,  1084,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1632,     0,     0,  1635,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1084,     0,     0,     0,
       0,  1050,     0,     0,     0,     0,  1643,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1084,     0,     0,     0,     0,     0,     0,
       0,  1668,     0,     0,     0,     0,  1671,     0,  1084,     0,
    1084,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1688,     0,     0,
       0,     0,     0,     0,     0,     0,  1495,     0,     0,     0,
    1497,     0,     0,  1694,  1500,     0,  1502,  1697,  1503,     0,
       0,     0,     0,     0,  1507,     0,     0,     0,     0,     0,
       0,     0,  1512,  1706,     0,     0,  1709,     0,     0,     0,
    1516,  1518,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1376,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1538,
    1539,  1540,  1541,  1542,     0,  1543,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1588,     0,  1589,
       0,     0,  1591,     0,     0,     0,     0,     0,     0,     0,
    1594,     0,     0,     0,     0,  1596,  1518,     0,     0,     0,
       0,     0,     0,  1600,     0,     0,     0,  1604,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1637,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1600,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1675,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1686,     0,
       0,     0,     0,  1691,     0,     0,     1,     2,  1675,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,  1691,    11,     0,     0,  1700,    12,    13,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,     0,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
      96,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   108,     0,
       0,   109,   110,   111,   112,   113,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,     0,   122,
       0,   123,   124,     0,     0,   125,   126,   127,     0,     0,
       0,   128,     0,   129,   130,     0,   131,   132,   133,     0,
     134,     0,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,     0,     0,   146,   147,   148,     0,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,   390,   391,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,   392,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   108,     0,     0,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,     0,   122,     0,
     123,   124,     0,     0,   125,   126,   127,     0,   525,     0,
     128,     0,   129,   130,     0,   131,   132,   133,     0,   134,
       0,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,     0,     0,   146,   147,   148,     0,   393,   150,
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
       0,    11,     0,     0,     0,   390,   391,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   392,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   108,     0,     0,   109,   110,
     111,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,     0,   122,     0,   123,   124,
       0,     0,   125,   126,   127,     0,   769,     0,   128,     0,
     129,   130,     0,   131,   132,   133,     0,   134,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
       0,     0,   146,   147,   148,     0,   393,   150,   151,   152,
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
       0,     0,     0,   390,   391,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,  1031,   392,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,  1032,  1033,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,     0,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,    96,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   108,     0,     0,   109,   110,   111,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,     0,   122,     0,   123,   124,     0,     0,
     125,   126,   127,     0,   769,     0,   128,     0,   129,   130,
       0,   131,   132,   133,     0,   134,     0,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,     0,     0,
     146,   147,   148,     0,   393,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,  1034,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,   390,   391,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,  1031,   392,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
    1032,  1033,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   108,     0,     0,   109,   110,   111,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,     0,   122,     0,   123,   124,     0,     0,   125,   126,
     127,     0,   525,     0,   128,     0,   129,   130,     0,   131,
     132,   133,     0,   134,     0,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,     0,     0,   146,   147,
     148,     0,   393,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,  1034,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,     0,     0,     0,   390,
     391,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,   392,    28,    29,    30,    31,
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
       0,     0,   109,   110,   111,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,     0,
     122,     0,   123,   124,     0,     0,   125,   126,   127,     0,
       0,     0,   128,     0,   129,   130,     0,   131,   132,   133,
       0,   134,     0,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,     0,     0,   146,   147,   148,     0,
     393,   150,   151,   152,   153,   154,   155,   156,   157,   158,
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
     101,   102,   103,   104,   105,   106,   107,   108,     0,     0,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,     0,   122,     0,
     123,   124,     0,     0,   125,   126,   127,     0,     0,     0,
     128,     0,   129,   130,     0,   131,   132,   133,     0,   134,
       0,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,     0,     0,   146,   147,   148,     0,   149,   150,
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
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
       0,     0,     0,    12,   391,     0,    14,    15,    16,    17,
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
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,   819,   391,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,   392,    28,    29,
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
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,     0,     0,     0,   390,
     391,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,  1031,   392,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,  1032,  1033,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
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
     393,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,  1034,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   390,   391,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   528,   392,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   529,   530,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   482,    82,    83,    84,
      85,    86,   531,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   532,     0,     0,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,     0,   122,     0,
     123,   124,     0,     0,   125,   126,   127,     0,     0,     0,
     128,   533,   129,   130,     0,   131,   132,   133,     0,   134,
       0,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,     0,     0,   146,   147,   148,     0,   393,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   499,   500,   501,   175,   176,   502,   534,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   390,   391,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     528,   392,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,   529,   530,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   482,    82,    83,    84,    85,    86,
     531,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   532,     0,     0,   109,   110,
     111,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,     0,   122,     0,   123,   124,
       0,     0,   125,   126,   127,     0,   861,     0,   128,     0,
     129,   130,     0,   131,   132,   133,     0,   134,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
       0,     0,   146,   147,   148,     0,   393,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   499,
     500,   501,   175,   176,   502,   534,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     0,     0,     0,    11,
       0,     0,     0,   390,   391,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   528,   392,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,   529,   530,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,     0,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,   482,    82,    83,    84,    85,    86,   531,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,    96,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   532,     0,     0,   109,   110,   111,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,     0,   122,     0,   123,   124,     0,     0,
     125,   126,   127,     0,     0,     0,   128,   867,   129,   130,
       0,   131,   132,   133,     0,   134,     0,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,     0,     0,
     146,   147,   148,     0,   393,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   499,   500,   501,
     175,   176,   502,   534,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   390,   391,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   528,   392,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     529,   530,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     482,    82,    83,    84,    85,    86,   531,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   532,     0,     0,   109,   110,   111,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,     0,   122,     0,   123,   124,     0,     0,   125,   126,
     127,     0,     0,     0,   128,   872,   129,   130,     0,   131,
     132,   133,     0,   134,     0,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,     0,     0,   146,   147,
     148,     0,   393,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   499,   500,   501,   175,   176,
     502,   534,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     0,     0,     0,    11,     0,     0,     0,   390,
     391,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   468,    25,   470,   392,    28,   471,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,   473,     0,    45,    46,    47,   475,   476,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,   482,    82,
      83,    84,    85,    86,   531,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   485,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   532,
       0,     0,   109,   110,   643,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,     0,
     122,     0,   644,   124,     0,     0,   125,   126,   127,     0,
       0,     0,   128,     0,   129,   130,     0,   131,   132,   133,
       0,   134,     0,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,     0,     0,   146,   147,   148,     0,
     393,   150,   151,   152,   153,   154,   155,   156,   157,   494,
     159,   495,   161,   496,   497,   164,   165,   166,   167,   168,
     169,   498,   171,   499,   500,   501,   175,   176,   502,   503,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   390,   391,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   528,   392,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   529,   530,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   482,    82,    83,    84,
      85,    86,   531,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   532,     0,     0,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,     0,   122,     0,
     123,   124,     0,     0,   125,   126,   127,     0,     0,     0,
     128,     0,   129,   130,     0,   131,   132,   133,     0,   134,
       0,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,     0,     0,   146,   147,   148,     0,   393,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   499,   500,   501,   175,   176,   502,   534,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   390,   391,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   468,    25,
     470,   392,    28,   471,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,   473,
       0,    45,    46,    47,   475,   476,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   482,    82,    83,    84,    85,    86,
     531,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   485,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   532,     0,     0,   109,   110,
     111,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,     0,   122,     0,   123,   124,
       0,     0,   125,   126,   127,     0,     0,     0,   128,     0,
     129,   130,     0,   131,   132,   133,     0,   134,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
       0,     0,   146,   147,   148,     0,   393,   150,   151,   152,
     153,   154,   155,   156,   157,   494,   159,   495,   161,   496,
     497,   164,   165,   166,   167,   168,   169,   498,   171,   499,
     500,   501,   175,   176,   502,   503,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     0,     0,     0,    11,
       0,     0,     0,   390,   391,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   468,    25,   470,   392,
      28,   471,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,   473,     0,    45,
      46,    47,   475,   476,    50,   477,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,     0,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,   482,    82,    83,    84,    85,    86,   531,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   485,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   532,     0,     0,   109,   110,     0,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,     0,   122,     0,     0,     0,     0,     0,
     125,   126,   127,     0,     0,     0,   128,     0,   129,   130,
       0,   131,   132,   133,     0,   134,     0,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,     0,     0,
     146,   147,   148,     0,   393,   150,   151,   152,   153,   154,
     155,   156,   157,   494,   159,   495,   161,   496,   497,   164,
     165,   166,   167,   168,   169,   498,   171,   499,   500,   501,
     175,   176,   502,   503,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   390,   391,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   468,    25,   470,   392,    28,   471,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   473,     0,    45,    46,    47,
     475,   476,    50,   477,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     482,    82,    83,    84,    85,    86,   531,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   485,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   532,     0,     0,   109,   110,     0,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,     0,   122,     0,     0,     0,     0,     0,   125,   126,
     127,     0,     0,     0,   128,     0,   129,   130,     0,     0,
       0,   133,     0,   134,     0,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,     0,     0,   146,   147,
     148,     0,   393,   150,   151,   152,   153,   154,   155,   156,
     157,   494,   159,   495,   161,   496,   497,   164,   165,   166,
     167,   168,   169,   498,   171,   499,   500,   501,   175,   176,
     502,   503,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     0,     0,     0,
       7,     8,     0,     0,     0,   464,     0,     0,     0,   390,
     391,     0,    14,    15,    16,   465,    18,    19,    20,   466,
      22,   467,   468,   469,   470,   392,    28,   471,    30,    31,
       0,    32,    33,    34,    35,   472,    37,    38,    39,    40,
      41,    42,    43,   473,     0,    45,   474,    47,   475,   476,
      50,   477,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   478,   479,    68,     0,
      69,    70,    71,   480,     0,     0,    74,    75,    76,     0,
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
     159,   495,   161,   496,   497,   164,   165,   166,   167,   168,
     169,   498,   171,   499,   500,   501,   175,   176,   502,   503,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     0,     0,     0,     7,     8,
       0,     0,     0,   464,     0,     0,     0,   390,   391,     0,
      14,    15,    16,   512,    18,    19,    20,   466,   513,   514,
     468,   469,   470,   392,    28,   471,    30,    31,     0,    32,
      33,    34,    35,   515,    37,   516,   517,    40,    41,    42,
      43,   473,     0,    45,   518,    47,   475,   476,    50,   477,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   478,   479,    68,     0,    69,    70,
      71,   519,     0,     0,    74,    75,    76,     0,     0,   481,
      78,     0,     0,     0,     0,    80,   482,    82,   483,   484,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   485,
      97,    98,   486,   487,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,   105,   106,   107,     0,     0,     0,
       0,     0,     0,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   488,   119,   120,   489,     0,     0,     0,
       0,     0,     0,     0,   490,   491,   127,     0,     0,     0,
     128,     0,   129,   492,     0,     0,     0,   133,     0,   134,
       0,   135,   136,   137,   138,   493,   140,   141,   142,   143,
     144,   145,     0,     0,   146,   147,     0,     0,   393,   150,
     151,   152,   153,   154,   155,   156,   157,   494,   520,   495,
     161,   496,   497,   164,   165,   166,   167,   168,   169,   498,
     171,   499,   500,   501,   175,   176,   502,   503,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   541,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     0,     0,   744,     0,     0,     0,
     390,   391,     0,    14,    15,    16,   512,    18,    19,    20,
     466,   513,   514,   468,   469,   470,   392,    28,   471,    30,
      31,     0,    32,    33,    34,    35,   515,    37,   516,   517,
      40,    41,    42,    43,   473,     0,    45,   518,    47,   475,
     476,    50,   477,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   478,   479,    68,
       0,    69,    70,    71,   519,     0,     0,    74,    75,    76,
       0,     0,   481,    78,     0,     0,     0,     0,    80,   482,
      82,   483,   484,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   485,    97,    98,   486,   487,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,   107,
       0,     0,     0,     0,     0,     0,   112,   113,     0,     0,
       0,     0,   114,   115,   116,   117,   488,   119,   120,   489,
       0,     0,     0,     0,     0,     0,     0,   490,   491,   127,
       0,     0,     0,   128,   745,   129,   492,     0,     0,     0,
       0,     0,   134,     0,   135,   136,   137,   138,   493,   140,
     141,   142,   143,   144,   145,     0,     0,   146,   147,     0,
       0,   393,   150,   151,   152,   153,   154,   155,   156,   157,
     494,   520,   495,   161,   496,   497,   164,   165,   166,   167,
     168,   169,   498,   171,   499,   500,   501,   175,   176,   502,
     503,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   541,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     0,     0,   464,
       0,     0,     0,   390,   391,     0,    14,    15,    16,   512,
      18,    19,    20,   466,   513,   514,   468,   469,   470,   392,
      28,   471,    30,    31,     0,    32,    33,    34,    35,   515,
      37,   516,   517,    40,    41,    42,    43,   473,     0,    45,
     518,    47,   475,   476,    50,   477,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     478,   479,    68,     0,    69,    70,    71,   519,     0,     0,
      74,    75,    76,     0,     0,   481,    78,     0,     0,     0,
       0,    80,   482,    82,   483,   484,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   485,    97,    98,   486,   487,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,   107,     0,     0,     0,     0,     0,     0,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   488,
     119,   120,   489,     0,     0,     0,     0,     0,     0,     0,
     490,   491,   127,     0,     0,     0,   128,     0,   129,   492,
       0,     0,     0,     0,     0,   134,     0,   135,   136,   137,
     138,   493,   140,   141,   142,   143,   144,   145,     0,     0,
     146,   147,     0,     0,   393,   150,   151,   152,   153,   154,
     155,   156,   157,   494,   520,   495,   161,   496,   497,   164,
     165,   166,   167,   168,   169,   498,   171,   499,   500,   501,
     175,   176,   502,   503,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   544,
     545,     0,     0,     0,     0,     7,     8,     0,     0,     0,
     464,     0,     0,     0,   390,   391,     0,    14,    15,    16,
     512,    18,    19,    20,   466,   513,   514,   468,   469,   470,
     392,    28,   471,    30,    31,     0,    32,    33,    34,    35,
     515,    37,   516,   517,    40,    41,    42,    43,   473,     0,
      45,   518,    47,   475,   476,    50,   477,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   478,   479,    68,     0,    69,    70,    71,   519,     0,
       0,    74,    75,    76,     0,     0,   481,    78,     0,     0,
       0,     0,    80,   482,    82,   483,   484,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   485,    97,    98,   486,
     487,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,   107,     0,     0,     0,     0,     0,     0,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   117,
     488,   119,   120,   489,     0,     0,     0,     0,     0,     0,
       0,   490,   491,   127,     0,     0,     0,   128,     0,   129,
     492,     0,     0,     0,     0,     0,   134,     0,   135,   136,
     137,   138,   493,   140,   141,   142,   143,   144,   145,     0,
       0,   146,   147,     0,     0,   393,   150,   151,   152,   153,
     154,   155,   156,   157,   494,   520,   495,   161,   496,   497,
     164,   165,   166,   167,   168,   169,   498,   171,   499,   500,
     501,   175,   176,   502,   503,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       7,     8,     0,     0,     0,   464,     0,     0,     0,   390,
     391,     0,    14,    15,    16,   465,    18,    19,    20,   466,
      22,   467,   468,  1072,   470,   392,    28,   471,    30,    31,
       0,    32,    33,    34,    35,   472,    37,    38,    39,    40,
      41,    42,    43,   473,     0,    45,   474,    47,   475,   476,
      50,   477,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   478,   479,    68,     0,
      69,    70,    71,   480,     0,     0,    74,    75,    76,     0,
       0,   481,    78,     0,     0,     0,     0,    80,   482,    82,
     483,   484,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   485,    97,    98,   486,   487,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,  1073,     0,
       0,     0,  1074,     0,     0,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   488,   119,   120,   489,     0,
       0,     0,     0,     0,     0,     0,   490,   491,   127,     0,
       0,     0,   128,  1470,   129,   492,     0,     0,     0,  1471,
       0,   134,     0,   135,   136,   137,   138,   493,   140,   141,
     142,   143,   144,   145,     0,     0,  1075,   147,     0,     0,
     393,   150,   151,   152,   153,   154,   155,   156,   157,   494,
     159,   495,   161,   496,   497,   164,   165,   166,   167,   168,
     169,   498,   171,   499,   500,   501,   175,   176,   502,   503,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     7,     8,     0,     0,     0,
     464,     0,     0,     0,   390,   391,     0,    14,    15,    16,
     512,    18,    19,    20,   466,   513,   514,   468,   469,   470,
     392,    28,   471,    30,    31,     0,    32,    33,    34,    35,
     515,    37,   516,   517,    40,    41,    42,    43,   473,     0,
      45,   518,    47,   475,   476,    50,   477,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   478,   479,    68,     0,    69,    70,    71,   519,     0,
       0,    74,    75,    76,     0,     0,   481,    78,     0,     0,
       0,     0,    80,   482,    82,   483,   484,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   485,    97,    98,   486,
     487,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,   107,     0,     0,     0,     0,     0,     0,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   117,
     488,   119,   120,   489,     0,     0,     0,     0,     0,     0,
       0,   490,   491,   127,     0,     0,     0,   128,   715,   129,
     492,     0,     0,     0,   716,     0,   134,     0,   135,   136,
     137,   138,   493,   140,   141,   142,   143,   144,   145,     0,
       0,   146,   147,     0,     0,   393,   150,   151,   152,   153,
     154,   155,   156,   157,   494,   520,   495,   161,   496,   497,
     164,   165,   166,   167,   168,   169,   498,   171,   499,   500,
     501,   175,   176,   502,   503,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       7,     8,     0,     0,     0,   464,     0,     0,     0,   390,
     391,     0,    14,    15,    16,   512,    18,    19,    20,   466,
     513,   514,   468,   469,   470,   392,    28,   471,    30,    31,
       0,    32,    33,    34,    35,   515,    37,   516,   517,    40,
      41,    42,    43,   473,     0,    45,   518,    47,   475,   476,
      50,   477,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   478,   479,    68,     0,
      69,    70,    71,   519,     0,     0,    74,    75,    76,     0,
       0,   481,    78,     0,     0,     0,     0,    80,   482,    82,
     483,   484,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   485,    97,    98,   486,   487,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   488,   119,   120,   489,     0,
       0,     0,     0,     0,     0,     0,   490,   491,   127,     0,
       0,     0,   128,   762,   129,   492,     0,     0,     0,   763,
       0,   134,     0,   135,   136,   137,   138,   493,   140,   141,
     142,   143,   144,   145,     0,     0,   146,   147,     0,     0,
     393,   150,   151,   152,   153,   154,   155,   156,   157,   494,
     520,   495,   161,   496,   497,   164,   165,   166,   167,   168,
     169,   498,   171,   499,   500,   501,   175,   176,   502,   503,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     7,     8,     0,     0,     0,
     464,     0,     0,     0,   390,   391,     0,    14,    15,    16,
     465,    18,    19,    20,   466,    22,   467,   468,  1072,   470,
     392,    28,   471,    30,    31,     0,    32,    33,    34,    35,
     472,    37,    38,    39,    40,    41,    42,    43,   473,     0,
      45,   474,    47,   475,   476,    50,   477,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   478,   479,    68,     0,    69,    70,    71,   480,     0,
       0,    74,    75,    76,     0,     0,   481,    78,     0,     0,
       0,     0,    80,   482,    82,   483,   484,    85,    86,  1394,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   485,    97,    98,   486,
     487,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,  1073,     0,     0,     0,  1074,     0,     0,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   117,
     488,   119,   120,   489,     0,     0,     0,     0,     0,     0,
       0,   490,   491,   127,     0,     0,     0,   128,     0,   129,
     492,     0,     0,     0,     0,     0,   134,     0,   135,   136,
     137,   138,   493,   140,   141,   142,   143,   144,   145,     0,
       0,  1075,   147,     0,     0,   393,   150,   151,   152,   153,
     154,   155,   156,   157,   494,   159,   495,   161,   496,   497,
     164,   165,   166,   167,   168,   169,   498,   171,   499,   500,
     501,   175,   176,   502,   503,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       7,     8,     0,     0,     0,   464,     0,     0,     0,   390,
     391,     0,    14,    15,    16,   465,    18,    19,    20,   466,
      22,   467,   468,  1072,   470,   392,    28,   471,    30,    31,
       0,    32,    33,    34,    35,   472,    37,    38,    39,    40,
      41,    42,    43,   473,     0,    45,   474,    47,   475,   476,
      50,   477,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   478,   479,    68,     0,
      69,    70,    71,   480,     0,     0,    74,    75,    76,     0,
       0,   481,    78,     0,     0,     0,     0,    80,   482,    82,
     483,   484,    85,    86,  1523,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   485,    97,    98,   486,   487,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,  1073,     0,
       0,     0,  1074,     0,     0,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   488,   119,   120,   489,     0,
       0,     0,     0,     0,     0,     0,   490,   491,   127,     0,
       0,     0,   128,     0,   129,   492,     0,     0,     0,     0,
       0,   134,     0,   135,   136,   137,   138,   493,   140,   141,
     142,   143,   144,   145,     0,     0,  1075,   147,     0,     0,
     393,   150,   151,   152,   153,   154,   155,   156,   157,   494,
     159,   495,   161,   496,   497,   164,   165,   166,   167,   168,
     169,   498,   171,   499,   500,   501,   175,   176,   502,   503,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     7,     8,     0,     0,     0,
     464,     0,     0,     0,   390,   391,     0,    14,    15,    16,
     465,    18,    19,    20,   466,    22,   467,   468,  1072,   470,
     392,    28,   471,    30,    31,     0,    32,    33,    34,    35,
     472,    37,    38,    39,    40,    41,    42,    43,   473,     0,
      45,   474,    47,   475,   476,    50,   477,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   478,   479,    68,     0,    69,    70,    71,   480,     0,
       0,    74,    75,    76,     0,     0,   481,    78,     0,     0,
       0,     0,    80,   482,    82,   483,   484,    85,    86,  1527,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   485,    97,    98,   486,
     487,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,  1073,     0,     0,     0,  1074,     0,     0,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   117,
     488,   119,   120,   489,     0,     0,     0,     0,     0,     0,
       0,   490,   491,   127,     0,     0,     0,   128,     0,   129,
     492,     0,     0,     0,     0,     0,   134,     0,   135,   136,
     137,   138,   493,   140,   141,   142,   143,   144,   145,     0,
       0,  1075,   147,     0,     0,   393,   150,   151,   152,   153,
     154,   155,   156,   157,   494,   159,   495,   161,   496,   497,
     164,   165,   166,   167,   168,   169,   498,   171,   499,   500,
     501,   175,   176,   502,   503,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       7,     8,     0,     0,     0,   464,     0,     0,     0,   390,
     391,     0,    14,    15,    16,   465,    18,    19,    20,   466,
      22,   467,   468,  1072,   470,   392,    28,   471,    30,    31,
       0,    32,    33,    34,    35,   472,    37,    38,    39,    40,
      41,    42,    43,   473,     0,    45,   474,    47,   475,   476,
      50,   477,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   478,   479,    68,     0,
      69,    70,    71,   480,     0,     0,    74,    75,    76,     0,
       0,   481,    78,     0,     0,     0,     0,    80,   482,    82,
     483,   484,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   485,    97,    98,   486,   487,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,  1073,     0,
       0,     0,  1074,     0,     0,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   488,   119,   120,   489,     0,
       0,     0,     0,     0,     0,     0,   490,   491,   127,     0,
       0,     0,   128,     0,   129,   492,     0,     0,     0,     0,
       0,   134,     0,   135,   136,   137,   138,   493,   140,   141,
     142,   143,   144,   145,     0,     0,  1075,   147,     0,     0,
     393,   150,   151,   152,   153,   154,   155,   156,   157,   494,
     159,   495,   161,   496,   497,   164,   165,   166,   167,   168,
     169,   498,   171,   499,   500,   501,   175,   176,   502,   503,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     7,     8,     0,     0,     0,
     464,     0,     0,     0,   390,   391,     0,    14,    15,    16,
     465,    18,    19,    20,   466,    22,   467,   468,  1072,   470,
     392,    28,   471,    30,    31,     0,    32,    33,    34,    35,
     472,    37,    38,    39,    40,    41,    42,    43,   473,     0,
      45,   474,    47,   475,   476,    50,   477,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   478,   479,    68,     0,    69,    70,    71,   480,     0,
       0,    74,    75,    76,     0,     0,   481,    78,     0,     0,
       0,     0,    80,   482,    82,   483,   484,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   485,    97,    98,   486,
     487,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,  1073,     0,     0,     0,  1074,     0,     0,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   117,
     488,   119,   120,   489,     0,     0,     0,     0,     0,     0,
       0,   490,   491,   127,     0,     0,     0,   128,     0,   129,
     492,     0,     0,     0,     0,     0,   134,     0,   135,   136,
     137,   138,   493,   140,   141,   142,   143,   144,   145,     0,
       0,   146,   147,     0,     0,   393,   150,   151,   152,   153,
     154,   155,   156,   157,   494,   159,   495,   161,   496,   497,
     164,   165,   166,   167,   168,   169,   498,   171,   499,   500,
     501,   175,   176,   502,   503,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       7,     8,     0,     0,     0,   464,     0,     0,     0,   390,
     391,     0,    14,    15,    16,   512,    18,    19,    20,   466,
     513,   514,   468,   469,   470,   392,    28,   471,    30,    31,
       0,    32,    33,    34,    35,   515,    37,   516,   517,    40,
      41,    42,    43,   473,     0,    45,   518,    47,   475,   476,
      50,   477,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   478,   479,    68,     0,
      69,    70,    71,   519,     0,     0,    74,    75,    76,     0,
       0,   481,    78,     0,     0,     0,     0,    80,   482,    82,
     483,   484,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   485,    97,    98,   486,   487,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   488,   119,   120,   489,     0,
       0,     0,     0,     0,     0,     0,   490,   491,   127,     0,
       0,     0,   128,     0,   129,   492,     0,     0,     0,     0,
       0,   134,     0,   135,   136,   137,   138,   493,   140,   141,
     142,   143,   144,   145,     0,     0,   146,   147,     0,     0,
     393,   150,   151,   152,   153,   154,   155,   156,   157,   494,
     520,   495,   161,   496,   497,   164,   165,   166,   167,   168,
     169,   498,   171,   499,   500,   501,   175,   176,   502,   503,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     7,     8,     0,     0,     0,
     464,     0,     0,     0,   390,   391,     0,    14,    15,    16,
       0,    18,    19,    20,   466,     0,     0,   468,   469,     0,
     392,    28,   471,    30,    31,     0,    32,    33,    34,    35,
       0,    37,     0,     0,    40,    41,    42,    43,   473,     0,
      45,     0,    47,     0,     0,    50,   477,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   478,   479,    68,     0,    69,    70,    71,     0,     0,
       0,    74,    75,    76,     0,     0,   481,    78,     0,     0,
       0,     0,    80,   482,    82,   483,   484,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   485,    97,    98,   486,
     487,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,     0,     0,     0,     0,     0,     0,     0,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   117,
     488,   119,   120,   489,     0,     0,     0,     0,     0,     0,
       0,   490,   491,   127,     0,     0,     0,   128,     0,   129,
     492,     0,     0,     0,     0,     0,   134,     0,   135,   136,
     137,   138,   493,   140,   141,   142,   143,   144,   145,     0,
       0,     0,   147,     0,     0,   393,   150,   151,   152,   153,
     154,   155,   156,   157,   494,     0,   495,   161,   496,   497,
     164,   165,   166,   167,   168,   169,   498,   171,   499,   500,
     501,   175,   176,     0,   503,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,    12,   630,   178,     4,     5,     6,   778,     0,   300,
     248,   739,     4,     5,     6,   328,   988,     4,     5,     6,
     722,   972,   280,   751,   844,   109,     4,     5,     6,   631,
     632,   633,   634,   581,   582,   399,   400,   765,   722,   249,
    1010,  1139,  1221,  1277,  1278,    36,  1058,   805,  1205,   401,
      73,    26,    27,   879,   264,   579,   580,   581,   582,   413,
     132,   676,   579,   580,    36,     1,   609,    55,   611,   612,
     424,   614,    47,   616,     8,    37,    38,    29,    40,    41,
     118,   624,   625,    26,    27,   857,   858,   439,   440,     1,
       4,     5,     6,   447,     1,    57,     1,     1,   858,    74,
       1,    30,  1234,    94,    47,    96,     1,   271,   108,  1488,
    1310,   147,    96,    56,   895,   118,   108,    45,    45,    47,
      94,   100,    39,   895,    96,    73,   107,    44,    45,    93,
     108,    74,    76,   130,   107,    62,    79,   112,   396,    87,
      26,    27,    59,   142,    61,    62,   107,   107,   130,   118,
     107,   113,   118,    70,    96,   118,   147,   929,   110,    96,
     169,    96,   110,   131,   153,    29,   216,   153,   111,   112,
     113,    94,   124,   901,   122,   147,   124,   949,   106,    33,
      97,     5,   224,   106,   226,     9,   107,   106,   177,   949,
     962,   177,   201,   147,   108,    49,   280,   149,   160,   196,
    1434,   153,   962,   253,   156,   147,   187,   186,   127,   153,
       9,    10,   147,    29,   196,   156,     9,    10,   187,   183,
     186,   224,   190,   186,   184,   177,   112,   955,   216,   190,
    1202,   188,   169,   961,   272,  1006,   272,  1188,  1058,  1059,
     168,   175,   242,   217,   218,   245,   537,    96,  1346,  1628,
     242,  1408,   954,   245,   190,  1225,   420,   219,   232,   331,
     187,   234,   810,   811,  1234,   253,   881,   188,   952,   527,
     954,   255,   256,   272,  1286,  1101,   220,   221,   190,  1411,
     280,   272,   100,   190,   213,   190,   190,  1487,   280,   190,
     974,   808,   809,  1074,   110,   190,   160,   840,   260,   123,
     272,   125,  1074,   306,   103,   659,   258,   224,   124,   133,
     103,   286,   396,   336,   251,   252,   339,   254,   272,   294,
     169,   100,    29,    45,   123,    47,   125,   156,    94,   153,
     123,   107,   125,   149,   271,   687,   107,   153,   107,   597,
     156,   579,   580,   286,   107,   429,   283,    66,  1582,   107,
     107,   294,    71,   437,   153,   153,   107,    79,   157,   302,
     153,   177,   446,   107,   157,   107,   576,  1546,   186,   453,
     454,    96,  1144,    94,   107,   174,   142,   182,   462,   733,
     267,   174,   736,   107,   106,   737,   153,   274,   336,   144,
     195,   339,  1490,   107,   107,   194,   396,  1631,   136,   118,
      52,   194,   251,   252,   396,   254,   113,   186,  1180,     9,
     107,   187,   261,   212,   107,  1143,   187,   121,   187,   212,
    1180,   176,   271,    29,   187,   425,   147,   427,    28,   187,
     187,   156,  1204,   425,   283,   427,   187,   107,   193,   156,
     184,  1411,   209,   527,  1204,   187,   168,   425,   706,   427,
     107,   451,  1154,   160,   187,   539,   456,   405,   406,   451,
    1617,   409,   200,   187,   456,   413,  1286,   551,   416,   417,
      94,   185,   107,   451,   187,  1295,   424,   129,   456,  1163,
     844,   107,   430,   567,   568,   433,  1306,   184,   107,  1587,
     158,   107,   107,   441,   187,   160,  1044,  1045,  1046,   447,
     448,   449,   450,  1261,   110,     5,  1264,   455,   176,     9,
     874,   425,   107,   427,   184,   463,     9,    10,   124,   107,
    1044,  1045,  1046,   123,   118,   125,   158,   527,   153,    42,
     187,  1629,   532,    46,   134,   527,   107,   451,    51,   107,
     532,   107,   456,   149,   176,   803,  1318,     9,    42,   184,
     902,   903,    46,   153,   532,   907,    69,    51,  1318,  1510,
     508,   187,   646,   574,   107,   184,    28,   651,   568,   107,
     808,   187,   187,  1545,   522,    69,   568,   649,   650,   579,
     580,   581,   582,   531,   209,   937,    94,   579,   580,   581,
     582,   224,   187,   217,   218,    94,   229,   597,   107,   187,
     268,  1699,    42,  1701,   814,   597,    46,   275,   232,    53,
     103,    51,  1710,   184,    58,   563,   968,   285,   532,   187,
     972,   187,   706,   123,  1396,   125,   107,  1399,   156,    69,
     123,   262,   125,   133,   142,   166,  1396,    94,  1409,  1399,
      96,  1461,   273,  1414,   187,    96,   184,   117,   147,    33,
     148,   182,    96,   153,   568,   168,   122,   113,   171,  1361,
     153,   123,   113,   125,   157,    49,    54,   165,    56,  1297,
       9,    10,   134,   186,   168,   184,   146,   171,    53,   148,
     137,   174,   943,    58,   945,   142,   770,   771,   772,   159,
     774,   153,   186,   122,  1058,  1059,   165,   100,   211,    96,
     156,   194,    77,   184,   158,   156,   706,   276,   277,   278,
     113,   659,   100,   282,   706,   158,   113,   211,  1266,   212,
      24,    96,   176,   193,   153,  1609,  1610,   156,   168,   729,
      34,   171,   680,   176,   995,   683,   997,   729,   136,   262,
     628,   629,   729,   118,   198,  1036,   186,  1060,   182,   697,
     273,   729,   150,   701,   702,   198,    60,   246,   247,   759,
     760,   195,  1533,  1647,   103,   156,  1537,   759,   760,  1653,
     200,   211,  1030,   153,   100,   723,   156,   725,    95,   209,
     269,   759,   760,   268,   123,   733,   125,   113,   736,   106,
     275,   100,   740,  1565,   583,  1567,   137,   137,   587,   116,
     285,   191,   192,   803,   113,  1565,   100,  1567,   819,   100,
     127,   803,   153,   153,   153,   729,   892,   100,   157,   113,
     128,   129,   113,   298,  1452,  1453,  1598,   156,   904,   777,
     113,  1183,   307,   156,   137,   174,  1188,   153,  1598,   142,
     156,   652,  1613,  1445,   655,   759,   760,   658,   220,   221,
     222,   137,   122,  1625,  1582,   194,   142,   805,    53,  1034,
     156,   338,   250,    58,  1039,  1625,   343,   156,  1640,   153,
    1642,   153,   156,   212,   156,   263,   224,   265,   226,   827,
    1640,   154,  1642,   156,   122,    26,    27,   118,   276,   277,
     278,   118,   280,   231,   282,   233,    37,    38,   153,    40,
      41,   231,   122,   233,   128,   129,    47,   635,   636,   857,
     858,   859,   860,   859,   860,    56,    57,   637,   638,  1478,
    1479,  1273,  1286,   122,  1182,  1553,  1554,   153,   122,   122,
     122,  1295,   122,    74,   122,   132,   122,   215,    79,   156,
     118,   240,  1306,   140,   141,   224,   143,   895,   240,   156,
     153,   241,     0,   107,   151,   190,   167,    92,   155,    99,
     157,   909,    50,   248,   101,   162,   199,   154,   102,   121,
     111,   112,   113,  1057,   145,   156,   184,    29,   184,   184,
      47,   245,   179,   152,   303,   118,   934,   187,   283,   118,
     990,   153,     1,  1621,   118,   943,   283,   945,   990,   142,
     107,   949,  1260,   187,   153,   202,   203,   204,   205,   206,
     207,   153,   990,    35,   962,   142,   184,   156,   156,   160,
     156,    17,   213,   153,   156,   156,  1378,    29,   156,   187,
    1030,   156,  1043,   156,   230,   190,     3,   190,  1030,   118,
     244,    70,   168,    94,  1044,  1045,  1046,   995,   170,   997,
     170,   230,  1044,  1045,  1046,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,   149,    94,    94,   107,   107,
      29,   160,   127,   160,   132,   245,   990,    94,   219,   298,
     142,   118,   132,   184,   184,   187,  1438,   107,   187,    94,
      96,    45,    96,   187,   187,   187,   187,  1461,   184,   153,
      94,    73,   184,   224,    33,  1053,   142,   190,   118,   170,
     142,   132,    94,    29,   226,    87,    94,   236,   285,   260,
     153,   298,   197,   118,   127,   118,  1074,   118,   147,    94,
     160,   184,  1390,   132,   132,   253,    96,   153,   110,   118,
     147,   184,   100,   100,   184,   286,   190,  1147,    35,    29,
     122,    79,   124,   294,   142,  1147,   153,   118,  1510,   244,
    1147,   302,   107,   107,   156,    29,   156,   156,   153,  1147,
     284,   266,  1256,  1257,  1258,   156,   257,   285,   144,   259,
     156,   156,  1182,    29,    29,   226,   187,   187,   286,   305,
    1182,   144,   147,  1193,   127,   147,   147,   118,   118,    77,
     107,  1193,   142,   190,   187,  1153,  1193,   187,  1156,   100,
     184,   197,  1212,   132,   187,  1193,   187,     7,   232,   232,
    1212,   190,   186,  1171,   232,  1212,   249,   106,   285,   106,
     147,  1231,  1180,  1147,  1212,   281,    78,   187,   249,  1231,
     187,   187,    29,    29,   187,   107,  1194,   170,   232,   184,
    1508,   147,   270,  1231,   147,   126,  1204,   126,    96,  1259,
    1260,  1519,  1520,   153,  1522,    94,   236,  1259,  1260,   184,
      29,  1529,   186,   186,   186,   186,   184,   187,   184,  1193,
     184,    96,   187,    53,  1232,   170,   147,    94,   256,   186,
      94,   186,    29,   196,   107,   197,   107,   118,  1212,   224,
     118,    94,   279,   186,  1252,    94,   118,   196,   264,    93,
     196,   186,   186,  1261,   196,   224,  1264,  1231,   183,   118,
     118,   118,   198,   286,   224,   686,   186,   186,   186,  1104,
     248,   896,   400,   963,  1144,  1587,  1629,   960,   806,  1153,
     742,   242,   304,   420,   292,  1259,   245,   245,  1606,  1371,
     286,  1172,  1282,  1049,  1280,   304,   522,  1277,  1616,  1194,
    1199,  1202,   304,  1207,   336,   607,   305,   339,   305,   608,
    1318,   305,  1225,   627,   778,  1653,  1647,   860,  1138,   428,
     661,   428,   945,  1641,  1252,  1103,   324,  1262,  1261,  1295,
    1390,  1306,  1461,  1059,  1342,  1458,  1299,  1068,  1390,   928,
    1126,  1481,  1296,    -1,  1337,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1672,    -1,    -1,    -1,    -1,    -1,
    1368,  1369,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   406,  1693,    -1,   409,    -1,    -1,
    1698,   413,    -1,    -1,   416,   417,  1394,    -1,  1396,    -1,
      -1,  1399,   424,    -1,    -1,    -1,    -1,    -1,   430,    -1,
      -1,   433,  1410,  1547,    -1,    -1,    -1,  1415,    -1,   441,
      -1,    -1,    -1,    -1,    -1,   447,   448,   449,   450,  1563,
      -1,    -1,    -1,   455,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   463,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1508,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1508,    -1,    -1,  1519,
    1520,    -1,  1522,    -1,    -1,    -1,    -1,  1519,  1520,  1529,
    1522,    -1,    -1,    -1,    -1,    -1,   508,  1529,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     522,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   531,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1523,    -1,  1525,    -1,  1527,
      -1,    -1,    -1,    -1,    -1,    -1,  1534,    -1,    -1,    -1,
      -1,   563,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1606,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1606,    -1,  1616,  1565,    -1,  1567,
      -1,    -1,    -1,    -1,  1616,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1583,    -1,    -1,  1586,    -1,
      -1,  1641,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1641,
    1598,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1608,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1672,    -1,    -1,    -1,    -1,  1625,    -1,    -1,
    1672,    -1,    -1,    -1,    -1,  1633,    -1,   659,    -1,    -1,
    1638,    -1,  1640,  1693,  1642,    -1,    -1,    -1,  1698,    -1,
      -1,  1693,    -1,    -1,    -1,    -1,  1698,    -1,    -1,    -1,
      -1,   683,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1669,    -1,    -1,    -1,   697,    -1,    -1,    -1,   701,
     702,    -1,    -1,    -1,    -1,    -1,    -1,  1685,    -1,    -1,
      -1,  1689,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   723,    -1,   725,    -1,    -1,    -1,  1705,    -1,    -1,
    1708,   733,    -1,    -1,   736,    -1,    -1,    -1,   740,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   777,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   805,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   827,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   857,   858,   859,   860,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   555,   556,    -1,   558,
     559,   560,   561,    -1,    -1,    -1,    -1,   566,    -1,    -1,
      -1,    -1,    -1,   895,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   909,    -1,    -1,
     589,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   597,   598,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   934,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   943,    -1,   945,    -1,    -1,    -1,   949,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     962,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   657,    -1,
      -1,    -1,   661,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   995,    -1,   997,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     699,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1053,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   741,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1074,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   766,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   776,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     829,  1153,    -1,    -1,  1156,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   897,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1252,    -1,    -1,   932,    -1,    -1,    -1,    -1,    -1,  1261,
      -1,    -1,  1264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   951,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   973,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   984,   985,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1318,    -1,    -1,    -1,
     999,    -1,    -1,  1002,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1016,  1017,  1018,
    1342,  1020,  1021,  1022,  1023,  1024,  1025,    -1,  1027,  1028,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1368,  1369,    -1,    -1,
    1049,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1394,    -1,  1396,    -1,    -1,  1399,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1410,    -1,
      -1,    -1,  1091,  1415,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1158,
      -1,  1160,    -1,  1162,    -1,    -1,  1165,    -1,    -1,    -1,
      -1,  1170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1182,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1191,    -1,    -1,    -1,    -1,    -1,  1197,  1198,
      -1,  1523,    -1,  1525,    -1,  1527,    -1,    -1,    -1,    -1,
      -1,    -1,  1534,    -1,    -1,    -1,    -1,  1216,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1565,    -1,  1567,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1583,    -1,    -1,  1586,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1598,    -1,    -1,    -1,
      -1,  1280,    -1,    -1,    -1,    -1,  1608,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1625,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1633,    -1,    -1,    -1,    -1,  1638,    -1,  1640,    -1,
    1642,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1669,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1355,    -1,    -1,    -1,
    1359,    -1,    -1,  1685,  1363,    -1,  1365,  1689,  1367,    -1,
      -1,    -1,    -1,    -1,  1373,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1381,  1705,    -1,    -1,  1708,    -1,    -1,    -1,
    1389,  1390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1407,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1418,
    1419,  1420,  1421,  1422,    -1,  1424,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1496,    -1,  1498,
      -1,    -1,  1501,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1509,    -1,    -1,    -1,    -1,  1514,  1515,    -1,    -1,    -1,
      -1,    -1,    -1,  1522,    -1,    -1,    -1,  1526,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1590,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1602,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1641,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1667,    -1,
      -1,    -1,    -1,  1672,    -1,    -1,    11,    12,  1677,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,  1692,    29,    -1,    -1,  1696,    33,    34,
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
      -1,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
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
     305,   306,   307,   308,   309,    11,    12,    -1,    -1,    -1,
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
     146,   147,   148,   149,   150,   151,   152,   153,    -1,    -1,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
     176,   177,    -1,    -1,   180,   181,   182,    -1,   184,    -1,
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
     306,   307,   308,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
     148,   149,   150,   151,   152,   153,    -1,    -1,   156,   157,
     158,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,   174,    -1,   176,   177,
      -1,    -1,   180,   181,   182,    -1,   184,    -1,   186,    -1,
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
     308,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     150,   151,   152,   153,    -1,    -1,   156,   157,   158,   159,
     160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,
     180,   181,   182,    -1,   184,    -1,   186,    -1,   188,   189,
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
     300,   301,   302,   303,   304,   305,   306,   307,   308,    11,
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
     152,   153,    -1,    -1,   156,   157,   158,   159,   160,    -1,
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
     302,   303,   304,   305,   306,   307,   308,    11,    12,    -1,
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
      -1,    -1,   156,   157,   158,   159,   160,    -1,    -1,    -1,
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
     304,   305,   306,   307,   308,    11,    12,    -1,    -1,    -1,
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
     146,   147,   148,   149,   150,   151,   152,   153,    -1,    -1,
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
     306,   307,   308,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
     148,   149,   150,   151,   152,   153,    -1,    -1,   156,   157,
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
     308,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     150,   151,   152,   153,    -1,    -1,   156,   157,   158,   159,
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
     300,   301,   302,   303,   304,   305,   306,   307,   308,    11,
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
     152,   153,    -1,    -1,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
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
     302,   303,   304,   305,   306,   307,   308,    11,    12,    -1,
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
      -1,    -1,   156,   157,   158,   159,   160,    -1,    -1,    -1,
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
     304,   305,   306,   307,   308,    11,    12,    -1,    -1,    -1,
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
     146,   147,   148,   149,   150,   151,   152,   153,    -1,    -1,
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
     306,   307,   308,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
     148,   149,   150,   151,   152,   153,    -1,    -1,   156,   157,
     158,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,   174,    -1,   176,   177,
      -1,    -1,   180,   181,   182,    -1,   184,    -1,   186,    -1,
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
     308,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     150,   151,   152,   153,    -1,    -1,   156,   157,   158,   159,
     160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,   187,   188,   189,
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
     300,   301,   302,   303,   304,   305,   306,   307,   308,    11,
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
     152,   153,    -1,    -1,   156,   157,   158,   159,   160,    -1,
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
     302,   303,   304,   305,   306,   307,   308,    11,    12,    -1,
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
      -1,    -1,   156,   157,   158,   159,   160,    -1,    -1,    -1,
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
     304,   305,   306,   307,   308,    11,    12,    -1,    -1,    -1,
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
     146,   147,   148,   149,   150,   151,   152,   153,    -1,    -1,
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
     306,   307,   308,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
     148,   149,   150,   151,   152,   153,    -1,    -1,   156,   157,
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
     308,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     150,   151,   152,   153,    -1,    -1,   156,   157,    -1,   159,
     160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    -1,    -1,    -1,    -1,    -1,
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
     300,   301,   302,   303,   304,   305,   306,   307,   308,    11,
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
     152,   153,    -1,    -1,   156,   157,    -1,   159,   160,    -1,
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
     302,   303,   304,   305,   306,   307,   308,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,
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
     304,   305,   306,   307,   308,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
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
     186,    -1,   188,   189,    -1,    -1,    -1,   193,    -1,   195,
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
     306,   307,   308,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
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
     303,   304,   305,   306,   307,   308,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    29,
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
     300,   301,   302,   303,   304,   305,   306,   307,   308,    18,
      19,    -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
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
      -1,    -1,   156,    -1,    -1,   159,   160,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,   187,   188,   189,    -1,    -1,    -1,   193,
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
     304,   305,   306,   307,   308,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
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
     189,    -1,    -1,    -1,   193,    -1,   195,    -1,   197,   198,
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
      -1,    -1,   186,   187,   188,   189,    -1,    -1,    -1,   193,
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
     304,   305,   306,   307,   308,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
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
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
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
     304,   305,   306,   307,   308,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
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
     304,   305,   306,   307,   308,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
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
     304,   305,   306,   307,   308,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      -1,    40,    41,    42,    43,    -1,    -1,    46,    47,    -1,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      -1,    60,    -1,    -1,    63,    64,    65,    66,    67,    -1,
      69,    -1,    71,    -1,    -1,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    -1,    -1,
      -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,
     139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
      -1,   150,   151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
     189,    -1,    -1,    -1,    -1,    -1,   195,    -1,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,    -1,
      -1,    -1,   211,    -1,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,    -1,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308
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
     139,   146,   147,   148,   149,   150,   151,   152,   153,   156,
     157,   158,   159,   160,   165,   166,   167,   168,   169,   170,
     171,   172,   174,   176,   177,   180,   181,   182,   186,   188,
     189,   191,   192,   193,   195,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   210,   211,   212,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   258,   259,   260,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   324,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   345,   346,   347,   348,   349,   350,   354,   355,   356,
     360,   362,   363,   365,   372,   374,   377,   378,   379,   381,
     382,   383,   384,   385,   387,   388,   390,   391,   392,   393,
     394,   395,   397,   398,   401,   402,   403,   404,   409,   411,
     413,   414,   419,   438,   441,   445,   448,   449,   454,   455,
     456,   457,   459,   460,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   506,   507,   508,   522,   523,   525,   526,
     527,   528,   529,   530,   531,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   551,   552,   553,   554,   559,
     560,   561,   562,   563,   564,   567,   625,   627,   628,   629,
      33,    34,    49,   214,   380,   381,   382,   380,   380,   156,
     156,    37,    38,    40,    41,    47,    56,    57,    74,    79,
     111,   112,   113,   160,   219,   260,   286,   294,   302,   361,
     362,   366,   367,   368,   160,   153,   156,   153,   156,   153,
     156,    66,    71,   118,   406,   156,   369,   156,    24,    34,
      60,   118,   272,   418,   420,   421,   153,   156,   156,   156,
     118,   153,   156,   156,   156,    76,   153,   220,   221,   122,
     122,   122,   153,   156,    29,    39,    43,    45,    46,    47,
      48,    51,    59,    67,    70,    72,    73,    75,    90,    91,
      97,   105,   112,   114,   115,   135,   138,   139,   169,   172,
     180,   181,   189,   201,   223,   225,   227,   228,   235,   237,
     238,   239,   242,   243,   490,   627,   628,   122,   118,   389,
     122,   122,    39,    44,    45,    59,    61,    62,    70,    97,
     224,   627,   118,   122,   122,   184,   380,   382,    48,    72,
      73,   118,   153,   187,   243,   401,   403,   413,   627,   153,
     122,    16,   626,   627,    18,    19,   627,   122,   122,   122,
     482,   153,    30,   213,   215,   224,   226,   156,   224,   226,
     224,   224,   229,   118,   240,   240,   241,   156,   153,   384,
     326,     0,   328,   329,    33,    49,   331,   348,     1,   190,
     325,   190,   325,   112,   363,   383,   401,   107,   190,   107,
     190,    42,    46,    51,    69,   168,   171,   186,   211,   396,
     405,   410,   411,   412,   426,   427,   431,   167,    92,   132,
     140,   141,   143,   151,   155,   157,   162,   179,   202,   203,
     204,   205,   206,   207,   474,   475,   248,    99,   158,   176,
     198,   117,   146,   159,   193,   200,   209,   136,   150,    50,
     199,   101,   102,   158,   176,   473,   153,   479,   482,   191,
     192,   154,   494,   495,   490,   494,   490,   156,   494,   121,
     145,   156,   184,   184,   184,    29,   364,   497,   364,   625,
     182,   195,   182,   195,   166,   182,   628,   627,   169,   201,
      47,   627,   152,   118,    45,    47,    79,   106,   168,   626,
     220,   221,   222,   245,   598,   627,   627,   303,   137,   142,
     112,   286,   294,   366,   626,   381,   382,   187,   381,    45,
      62,   187,   547,   548,   401,   187,   193,   627,   283,   283,
     415,   416,   627,   118,   422,   118,   187,   370,   371,   153,
     386,   401,     1,   160,   625,   113,   160,   344,   625,   627,
     118,   142,   107,   401,    29,   187,   626,   627,   627,   439,
     440,   627,   381,   187,   401,   401,   549,   627,   381,   153,
     153,   401,   187,   193,   627,   627,   142,   439,   184,   184,
     156,   156,   156,   627,   153,   187,   186,    35,   510,   511,
     512,   401,     8,   175,    17,   401,   213,    29,   402,   402,
     187,   402,   402,   402,   402,   230,   565,   566,   627,   190,
     190,   402,   401,   382,   401,   244,   399,   400,   190,   325,
     190,   325,     3,   332,   348,   378,   332,   348,   378,    33,
     349,   378,   349,   378,   389,   389,   402,   118,   168,   170,
     170,   383,   402,   402,   456,   457,   459,   459,   459,   459,
     458,   459,   459,   459,    70,   460,   464,   464,   463,   465,
     465,   465,   465,   466,   466,   467,   467,   230,    94,    94,
      94,   184,   401,   482,   482,   401,   495,   187,   402,   505,
     626,   149,   187,   505,   107,   187,   187,   107,   107,   369,
      29,   628,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,   351,   352,   353,    94,   137,   142,   357,   358,
     359,   627,   160,   160,   351,   625,   127,   132,    54,    56,
     100,   250,   263,   265,   276,   277,   278,   280,   282,   599,
     600,   601,   602,   603,   604,   611,   617,   618,   245,    94,
     298,   627,   142,   402,   118,   627,   627,   132,   184,   184,
     187,   187,   184,   107,   187,   107,   187,   107,    36,    94,
      96,   147,   417,   418,   533,   627,    55,   216,   253,   407,
     408,   627,    94,   107,   187,   380,   187,   626,    96,    45,
     626,   625,    96,   142,   533,   627,   402,   421,   184,   187,
     187,   187,   187,   107,   188,   147,   533,   184,   187,   187,
     153,   184,   381,   381,   184,   107,   187,   107,   187,   142,
     533,   402,   188,   401,   401,   401,   627,   511,   512,   130,
     196,   184,   184,   131,   190,    94,   217,   218,   232,    94,
     217,   218,   232,    94,   236,   224,   107,   234,   142,   190,
     187,    48,    72,    73,   243,   403,   413,   184,   491,   571,
     400,   348,    33,    33,   190,   325,   190,   113,   627,   170,
     402,   432,   433,   118,   428,   429,   459,   153,   156,   258,
     478,   497,   572,   575,   576,   577,   578,   579,   583,   585,
     587,   588,    47,   152,   156,   210,   534,   536,   538,   539,
     555,   556,   557,   558,   627,   534,   532,   538,   532,   184,
     185,   107,   187,   187,   497,   148,   165,   148,   165,   137,
     386,   369,   352,   132,   536,   359,   402,   533,   625,   625,
     128,   129,   625,   276,   277,   278,   282,   627,   262,   273,
     262,   273,    29,   285,    96,   113,   156,   605,   608,   599,
      39,    44,    59,    61,    70,    97,   224,   373,   539,   226,
     298,   307,   402,   627,    94,   298,   625,   153,   549,   550,
     627,   549,   550,   118,   127,   534,   118,   402,   147,   418,
     147,    36,   147,   417,   418,   147,   533,   253,    53,    58,
      77,   118,   417,   423,   424,   425,   408,   533,   534,   371,
      94,   184,   197,   132,   343,   625,   160,   132,    96,   343,
     402,   142,   418,   153,   118,   402,   402,   147,   100,   442,
     443,   444,   446,   447,   100,   450,   451,   452,   453,   381,
     184,   184,   153,   549,   549,   402,   142,   190,   402,   187,
     187,   187,    35,   512,   130,   196,     9,    10,   103,   123,
     125,   153,   194,   507,   509,   520,   521,   524,    29,   231,
     233,   402,   402,   402,   231,   233,   402,   402,   402,   402,
     402,   402,   118,   402,   402,   383,   156,   156,   156,   153,
     186,   244,   568,   569,   209,   384,   190,   113,   378,   378,
     378,   432,    95,   106,   116,   127,   434,   435,   436,   437,
     107,   627,   107,   401,   572,   579,   153,   284,   461,   624,
      96,   169,   251,   252,   254,   261,   271,   283,   573,   574,
     593,   594,   595,   596,   619,   622,   257,   259,   580,   598,
     266,   584,   620,   246,   247,   269,   589,   590,   156,   156,
     536,   156,   144,   176,   193,   535,   144,   402,   137,   386,
     551,   358,   285,    29,    96,   113,   156,   612,    29,   605,
     535,   480,   286,   305,   533,   373,   226,   190,   380,   187,
     187,   144,   187,   187,   416,   147,   417,   627,   402,   147,
     402,   127,   402,   147,   418,   147,   402,   147,   118,   118,
     402,   627,   425,    77,   534,   383,   402,   625,   107,   343,
     402,   142,   380,   440,   402,   402,   113,   443,   444,   100,
     186,   113,   444,   447,   118,   534,   100,   113,   451,   100,
     113,   453,   184,   380,   187,   187,   402,   197,   450,   132,
     194,   509,     7,   381,   627,   194,   520,   190,   232,   232,
     232,   232,   236,   566,   186,   401,   401,   401,   571,   569,
     491,   625,   128,   129,   436,   437,   437,   433,   106,   430,
     429,   184,   187,   572,   586,   249,   216,   253,   267,   274,
     623,    96,   255,   256,   621,   249,   576,   623,   463,   593,
     577,   147,   281,   581,   582,   621,   285,   592,    78,   591,
     187,   193,   534,   537,   187,   187,   187,    29,   136,   200,
     614,   615,   616,    29,   613,   614,   270,   609,   107,   606,
     170,   627,   256,   480,   184,   402,   147,   402,   147,   417,
     402,   147,   402,   402,   627,   627,   424,   402,   126,   126,
      96,   625,   402,   184,   186,   186,   402,   383,   402,   186,
     186,   627,   186,   118,   534,   118,   186,   118,   534,   186,
     184,   113,   512,   627,   194,   184,   512,   627,   402,   402,
     402,   402,   402,   402,   187,   187,   187,   153,   570,   437,
     625,   184,   465,    52,   129,   463,   463,   268,   275,   285,
     597,   597,   578,   153,   279,    94,   187,   107,   187,   612,
     612,   616,   107,   187,    29,   610,   621,   607,   608,   187,
     375,   376,   480,   118,   224,   306,   286,   170,   402,   402,
     147,   402,    53,   383,   402,   343,   402,   383,    94,   383,
     402,   627,   186,   627,   402,   627,   186,   383,   118,    93,
     183,   513,   512,   627,   196,   512,   197,   450,   401,   463,
     463,   198,   401,   534,   534,    94,    29,   264,   107,   107,
     437,   533,   627,   118,   224,   627,   375,   402,   118,   534,
      94,   186,    94,   627,     5,   133,   516,   517,   519,   521,
      28,   134,   514,   515,   518,   521,   196,   512,   196,   113,
     184,   463,   184,   534,   608,   376,   437,   304,   627,   118,
     224,   627,   186,   534,   383,   402,   534,   186,    93,   133,
     519,   183,   134,   518,   196,   118,   402,   304,   627,   118,
     383,   402,   186,   186,   627,   292,   304,   627,   186,   305,
     402,   305,   480,   480,   198,   286,   627,   224,   118,   627,
     305,   480
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
     384,   385,   386,   387,   388,   388,   388,   389,   389,   389,
     389,   390,   391,   392,   393,   394,   394,   395,   396,   397,
     398,   399,   399,   400,   401,   401,   402,   402,   402,   402,
     402,   402,   403,   403,   403,   403,   403,   403,   403,   404,
     405,   406,   406,   407,   407,   407,   408,   408,   409,   409,
     410,   411,   411,   411,   412,   412,   412,   412,   412,   413,
     413,   414,   415,   415,   416,   416,   416,   416,   416,   416,
     416,   416,   416,   416,   416,   416,   417,   418,   419,   420,
     420,   421,   421,   421,   421,   422,   422,   423,   423,   423,
     424,   424,   424,   425,   425,   425,   426,   427,   428,   428,
     429,   429,   430,   431,   431,   432,   432,   433,   433,   434,
     434,   434,   434,   434,   434,   434,   435,   435,   436,   436,
     437,   438,   438,   439,   439,   440,   440,   441,   442,   442,
     443,   444,   444,   445,   446,   446,   447,   448,   448,   449,
     449,   450,   450,   451,   451,   452,   452,   453,   453,   454,
     455,   455,   456,   456,   457,   457,   457,   457,   457,   458,
     457,   457,   457,   457,   459,   459,   460,   460,   461,   461,
     462,   462,   463,   463,   463,   464,   464,   464,   464,   464,
     465,   465,   465,   466,   466,   466,   467,   467,   468,   468,
     469,   469,   470,   470,   471,   471,   472,   472,   472,   472,
     473,   473,   473,   474,   474,   474,   474,   474,   474,   475,
     475,   475,   476,   476,   476,   476,   477,   477,   478,   478,
     479,   479,   479,   480,   480,   480,   480,   481,   482,   482,
     482,   483,   483,   484,   484,   484,   484,   485,   485,   486,
     486,   486,   486,   486,   486,   486,   487,   487,   488,   488,
     489,   489,   489,   489,   489,   490,   490,   491,   491,   492,
     492,   492,   492,   493,   493,   493,   493,   494,   494,   495,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     497,   497,   498,   498,   498,   499,   500,   500,   501,   502,
     503,   504,   504,   505,   505,   506,   506,   507,   507,   507,
     508,   508,   508,   508,   508,   508,   509,   509,   510,   510,
     511,   512,   512,   513,   513,   514,   514,   515,   515,   515,
     515,   516,   516,   517,   517,   517,   517,   518,   518,   519,
     519,   520,   520,   520,   520,   521,   521,   521,   521,   522,
     522,   523,   523,   524,   525,   525,   525,   525,   525,   525,
     526,   527,   527,   528,   528,   529,   530,   531,   531,   532,
     532,   533,   534,   534,   534,   535,   535,   535,   536,   536,
     536,   536,   536,   537,   537,   538,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   540,   541,   541,   541,   542,
     543,   544,   544,   544,   545,   545,   545,   545,   545,   546,
     547,   547,   547,   547,   547,   547,   547,   548,   549,   550,
     551,   552,   552,   553,   554,   555,   555,   556,   557,   557,
     558,   559,   559,   559,   560,   560,   560,   560,   560,   560,
     560,   560,   560,   560,   561,   561,   562,   562,   563,   564,
     565,   565,   566,   567,   568,   568,   569,   570,   571,   571,
     572,   573,   573,   574,   574,   575,   575,   576,   576,   577,
     577,   578,   578,   579,   580,   580,   581,   581,   582,   583,
     583,   583,   584,   584,   585,   586,   586,   587,   588,   588,
     589,   589,   590,   590,   590,   591,   591,   592,   592,   593,
     593,   593,   593,   593,   594,   595,   596,   597,   597,   597,
     598,   598,   599,   599,   599,   599,   599,   599,   599,   599,
     600,   600,   600,   600,   601,   601,   602,   603,   603,   604,
     604,   604,   605,   605,   606,   606,   607,   607,   608,   609,
     609,   610,   610,   611,   611,   611,   612,   612,   613,   613,
     614,   614,   615,   615,   616,   616,   617,   618,   618,   619,
     619,   619,   620,   621,   621,   621,   621,   622,   622,   623,
     623,   624,   625,   626,   626,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     629,   629
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
       4,     3,     3,     3,     1,     5,     1,     3,     0,     1,
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
       3,     1
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
      -1,   214,   215,    29,   190,    -1,   214,   215,    29,   131,
      29,   190,    -1,   331,   190,   378,    -1,   348,   190,   378,
      -1,   331,   190,   348,   190,   378,    -1,   378,    -1,   331,
     325,   378,    -1,   348,   325,   378,    -1,   331,   190,   348,
     325,   378,    -1,   331,   325,   348,   190,   378,    -1,   330,
      -1,   330,   331,   190,    -1,   330,   348,   190,    -1,   330,
     331,   190,   348,   190,    -1,    34,   160,   626,   132,   625,
     190,    -1,   332,    -1,   331,   190,   332,    -1,   331,   325,
     332,    -1,   333,    -1,   341,    -1,   346,    -1,   347,    -1,
     355,    -1,   334,    -1,   335,    -1,   336,    -1,   337,    -1,
     338,    -1,   339,    -1,   340,    -1,   559,    -1,    33,    38,
     182,    -1,    33,    38,   195,    -1,    33,   113,   106,   625,
      -1,    33,    37,   625,    -1,    33,    40,   182,    -1,    33,
      40,   195,    -1,    33,    57,   169,    -1,    33,    57,   201,
      -1,    33,   113,   168,   127,   128,    -1,    33,   113,   168,
     127,   129,    -1,    33,    41,   182,   107,   148,    -1,    33,
      41,   182,   107,   165,    -1,    33,    41,   166,   107,   148,
      -1,    33,    41,   166,   107,   165,    -1,   342,    -1,   345,
      -1,    49,    24,     1,    -1,    49,    60,   625,    -1,    49,
      60,   344,   625,    -1,    49,    60,   625,    96,   343,    -1,
      49,    60,   344,   625,    96,   343,    -1,   625,    -1,   343,
     107,   625,    -1,   160,   626,   132,    -1,   113,    45,   160,
      -1,    49,    34,   625,    -1,    49,    34,   160,   626,   132,
     625,    -1,    49,    34,   625,    96,   343,    -1,    49,    34,
     160,   626,   132,   625,    96,   343,    -1,    33,   160,   626,
     132,   625,    -1,    33,   113,    45,   160,   625,    -1,    33,
     113,    47,   160,   625,    -1,   349,    -1,   348,   190,   349,
      -1,   348,   325,   349,    -1,   350,    -1,   354,    -1,   356,
      -1,   360,    -1,   365,    -1,   372,    -1,   374,    -1,   377,
      -1,    33,   113,    79,   351,    -1,    33,    79,   627,   351,
      -1,   352,    -1,   351,   352,    -1,   353,   132,   551,    -1,
      80,    -1,    88,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    89,    -1,    85,    -1,    86,    -1,    87,    -1,
      33,    56,   627,    29,    -1,    33,   260,   598,    -1,    33,
     111,   152,   357,    -1,    94,   536,   358,    -1,   358,    -1,
     359,    -1,   137,    -1,   137,   359,    -1,   142,   402,    -1,
      33,   361,   142,   402,    -1,    33,   361,   137,    -1,    33,
     361,   137,   142,   402,    -1,   112,   118,   627,    -1,   112,
     118,   627,   533,    -1,   362,   112,   118,   627,    -1,   362,
     112,   118,   627,   533,    -1,   363,    -1,   362,   363,    -1,
      26,    -1,    26,   156,   364,   187,    -1,    27,    -1,    27,
     156,   364,   187,    -1,   497,    -1,   364,   107,   497,    -1,
      33,   366,    -1,    33,   362,   366,    -1,   367,    -1,   368,
      -1,    47,   628,   369,   386,    -1,    47,   628,   369,   137,
      -1,    74,    47,   628,   369,   386,    -1,    74,    47,   628,
     369,   137,    -1,   156,   187,    -1,   156,   370,   187,    -1,
     156,   187,    94,   534,    -1,   156,   370,   187,    94,   534,
      -1,   371,    -1,   370,   107,   371,    -1,   118,   627,    -1,
     118,   627,   533,    -1,    33,   286,   627,    -1,    33,   286,
     627,    94,   373,    -1,    33,   362,   286,   627,    -1,    33,
     362,   286,   627,    94,   373,    -1,   539,    -1,   539,   535,
      -1,    33,   294,   627,   298,   226,   480,   170,   375,    -1,
      33,   362,   294,   627,   298,   226,   480,   170,   375,    -1,
     376,    -1,   375,   107,   376,    -1,   480,    -1,   480,   533,
      -1,   480,   437,    -1,   480,   533,   437,    -1,    33,   302,
     303,   627,   298,   286,   627,   118,   627,   304,   402,    -1,
      33,   302,   303,   627,   298,   286,   627,   224,   118,   627,
     304,   292,   305,   480,    -1,    33,   302,   303,   627,   298,
     286,   627,   306,   224,   118,   627,   304,   402,    -1,    33,
     302,   303,   627,   307,   305,   256,   286,   627,   224,   118,
     627,   305,   480,   198,   286,   627,   224,   118,   627,   305,
     480,    -1,   379,    -1,   381,    -1,   382,    -1,    -1,   381,
      -1,   382,    -1,    -1,   401,    -1,   382,   401,    -1,   383,
      -1,   382,   383,    -1,   384,    -1,   387,    -1,   390,    -1,
     391,    -1,   392,    -1,   393,    -1,   394,    -1,   395,    -1,
     397,    -1,   449,    -1,   445,    -1,   398,    -1,   153,   382,
     184,    -1,   153,   184,    -1,   153,   380,   184,    -1,   153,
     380,   184,    -1,   388,   190,    -1,   388,   107,   389,    -1,
     112,   389,    -1,   362,   112,   389,    -1,   118,   627,    -1,
     118,   627,   533,    -1,   118,   627,   142,   402,    -1,   118,
     627,   533,   142,   402,    -1,   118,   627,   142,   402,   190,
      -1,   403,   190,    -1,   239,   241,   402,   190,    -1,   242,
     156,   401,   187,   383,    -1,   237,   240,   190,    -1,   238,
     240,   190,    -1,   413,   396,    -1,   186,   383,    -1,    48,
     156,   401,   187,   197,   383,   126,   383,    -1,   243,   384,
     399,    -1,   400,    -1,   399,   400,    -1,   244,   571,   384,
      -1,   402,    -1,   401,   107,   402,    -1,   404,    -1,   441,
      -1,   448,    -1,   454,    -1,   567,    -1,   403,    -1,   455,
      -1,   438,    -1,   560,    -1,   561,    -1,   563,    -1,   562,
      -1,   564,    -1,   413,   405,    -1,   186,   402,    -1,    66,
     283,    -1,    71,   283,    -1,   216,    -1,   253,    -1,    55,
     253,    -1,   407,   423,    77,   402,    -1,   407,    77,   402,
      -1,    46,   406,   422,   408,   408,    -1,    46,   406,   422,
     408,    -1,    42,   118,   627,    -1,   414,    -1,   419,    -1,
     409,    -1,   411,    -1,   426,    -1,   431,    -1,   427,    -1,
     410,    -1,   411,    -1,   413,   412,    -1,    46,   118,   415,
      -1,   416,    -1,   415,   107,   118,   416,    -1,   627,   147,
     402,    -1,   627,    36,   127,   147,   402,    -1,   627,   533,
     147,   402,    -1,   627,   533,    36,   127,   147,   402,    -1,
     627,   417,   147,   402,    -1,   627,    36,   127,   417,   147,
     402,    -1,   627,   533,   417,   147,   402,    -1,   627,   533,
      36,   127,   417,   147,   402,    -1,   627,   418,   147,   402,
      -1,   627,   533,   418,   147,   402,    -1,   627,   417,   418,
     147,   402,    -1,   627,   533,   417,   418,   147,   402,    -1,
      96,   118,   627,    -1,   272,   118,   627,    -1,    51,   420,
      -1,   421,    -1,   420,   107,   421,    -1,   118,   627,   142,
     402,    -1,   118,   627,   533,   142,   402,    -1,   418,   142,
     402,    -1,   118,   627,   533,   418,   142,   402,    -1,   118,
     627,   147,   402,    -1,   118,   627,   533,   147,   402,    -1,
     424,    -1,   118,   627,    -1,   118,   627,   424,    -1,   417,
      -1,   417,   425,    -1,   425,    -1,    58,   118,   627,    53,
     118,   627,    -1,    53,   118,   627,    -1,    58,   118,   627,
      -1,   211,   402,    -1,   171,   170,   428,    -1,   429,    -1,
     428,   107,   429,    -1,   118,   627,    -1,   118,   627,   430,
      -1,   106,   625,    -1,   168,   170,   432,    -1,    69,   168,
     170,   432,    -1,   433,    -1,   432,   107,   433,    -1,   402,
      -1,   402,   434,    -1,   435,    -1,   436,    -1,   437,    -1,
     435,   436,    -1,   435,   437,    -1,   436,   437,    -1,   435,
     436,   437,    -1,    95,    -1,   116,    -1,   127,   128,    -1,
     127,   129,    -1,   106,   625,    -1,    67,   118,   439,   188,
     402,    -1,   135,   118,   439,   188,   402,    -1,   440,    -1,
     439,   107,   118,   440,    -1,   627,   147,   402,    -1,   627,
     533,   147,   402,    -1,    72,   156,   401,   187,   442,   113,
     186,   402,    -1,   443,    -1,   442,   443,    -1,   444,   186,
     402,    -1,   100,   402,    -1,   444,   100,   402,    -1,    72,
     156,   401,   187,   446,   113,   186,   383,    -1,   447,    -1,
     446,   447,    -1,   444,   186,   383,    -1,    73,   156,   401,
     187,   450,   113,   186,   402,    -1,    73,   156,   401,   187,
     450,   113,   118,   627,   186,   402,    -1,    73,   156,   401,
     187,   452,   113,   186,   383,    -1,    73,   156,   401,   187,
     450,   113,   118,   627,   186,   383,    -1,   451,    -1,   450,
     451,    -1,   100,   534,   186,   402,    -1,   100,   118,   627,
      94,   534,   186,   402,    -1,   453,    -1,   452,   453,    -1,
     100,   534,   186,   383,    -1,   100,   118,   627,    94,   534,
     186,   383,    -1,    48,   156,   401,   187,   197,   402,   126,
     402,    -1,   456,    -1,   455,   167,   456,    -1,   457,    -1,
     456,    92,   457,    -1,   459,    -1,   459,   474,   459,    -1,
     459,   475,   459,    -1,   459,   132,   459,    -1,   459,   162,
     459,    -1,    -1,   459,   157,   458,   459,    -1,   459,   155,
     459,    -1,   459,   143,   459,    -1,   459,   141,   459,    -1,
     460,    -1,   460,   248,    70,   572,   461,    -1,   462,    -1,
     462,    99,   460,    -1,    -1,   624,    -1,   463,    -1,   463,
     198,   463,    -1,   464,    -1,   463,   176,   464,    -1,   463,
     158,   464,    -1,   465,    -1,   464,   193,   465,    -1,   464,
     117,   465,    -1,   464,   146,   465,    -1,   464,   159,   465,
      -1,   466,    -1,   465,   200,   466,    -1,   465,   209,   466,
      -1,   467,    -1,   466,   150,   467,    -1,   466,   136,   467,
      -1,   468,    -1,   468,    50,   230,   534,    -1,   469,    -1,
     469,   199,    94,   534,    -1,   470,    -1,   470,   101,    94,
     532,    -1,   471,    -1,   471,   102,    94,   532,    -1,   473,
      -1,   472,   473,    -1,   176,    -1,   158,    -1,   472,   176,
      -1,   472,   158,    -1,   476,    -1,   480,    -1,   477,    -1,
     202,    -1,   207,    -1,   206,    -1,   205,    -1,   204,    -1,
     203,    -1,   151,    -1,   179,    -1,   140,    -1,    75,   153,
     381,   184,    -1,    75,   221,   153,   381,   184,    -1,    75,
     220,   153,   381,   184,    -1,    75,    76,   549,   153,   381,
     184,    -1,   478,   153,   184,    -1,   478,   153,   401,   184,
      -1,   479,    -1,   478,   479,    -1,   177,   627,    17,    -1,
     177,    18,    -1,   177,    19,    -1,   481,    -1,   481,   482,
      -1,   192,   482,    -1,   482,    -1,   191,    -1,   483,    -1,
     483,   191,   482,    -1,   483,   192,   482,    -1,   484,    -1,
     493,    -1,   485,    -1,   485,   494,    -1,   488,    -1,   488,
     494,    -1,   486,   490,    -1,   487,    -1,   105,   122,    -1,
     114,   122,    -1,    97,   122,    -1,   189,   122,    -1,   115,
     122,    -1,   139,   122,    -1,   138,   122,    -1,   490,    -1,
      98,   490,    -1,   489,   490,    -1,   120,    -1,   172,   122,
      -1,    90,   122,    -1,   181,   122,    -1,   180,   122,    -1,
      91,   122,    -1,   539,    -1,   491,    -1,   627,    -1,   492,
      -1,   193,    -1,    11,    -1,    12,    -1,    20,    -1,   496,
      -1,   493,   494,    -1,   493,   156,   187,    -1,   493,   156,
     505,   187,    -1,   495,    -1,   494,   495,    -1,   154,   401,
     185,    -1,   497,    -1,   499,    -1,   500,    -1,   501,    -1,
     504,    -1,   506,    -1,   502,    -1,   503,    -1,   552,    -1,
     385,    -1,   498,    -1,   551,    -1,   110,    -1,   149,    -1,
     124,    -1,   118,   627,    -1,   156,   187,    -1,   156,   401,
     187,    -1,   119,    -1,   169,   153,   401,   184,    -1,   201,
     153,   401,   184,    -1,   628,   156,   187,    -1,   628,   156,
     505,   187,    -1,   402,    -1,   505,   107,   402,    -1,   507,
      -1,   525,    -1,   508,    -1,   522,    -1,   523,    -1,   157,
     627,   512,   130,    -1,   157,   627,   510,   512,   130,    -1,
     157,   627,   512,   196,   194,   627,   512,   196,    -1,   157,
     627,   512,   196,   509,   194,   627,   512,   196,    -1,   157,
     627,   510,   512,   196,   194,   627,   512,   196,    -1,   157,
     627,   510,   512,   196,   509,   194,   627,   512,   196,    -1,
     520,    -1,   509,   520,    -1,   511,    -1,   510,   511,    -1,
      35,   627,   512,   132,   512,   513,    -1,    -1,    35,    -1,
     183,   514,   183,    -1,    93,   516,    93,    -1,    -1,   515,
      -1,   134,    -1,   518,    -1,   515,   134,    -1,   515,   518,
      -1,    -1,   517,    -1,   133,    -1,   519,    -1,   517,   133,
      -1,   517,   519,    -1,    28,    -1,   521,    -1,     5,    -1,
     521,    -1,   507,    -1,    10,    -1,   524,    -1,   521,    -1,
       9,    -1,   123,    -1,   125,    -1,   153,   381,   184,    -1,
     212,    30,   213,    -1,   212,   213,    -1,   174,   626,   175,
      -1,   174,   626,     8,    -1,   103,     7,    -1,   526,    -1,
     527,    -1,   528,    -1,   529,    -1,   530,    -1,   531,    -1,
      43,   153,   381,   184,    -1,    21,   380,   184,    -1,    45,
     153,   401,   184,   153,   380,   184,    -1,    22,   380,   184,
      -1,    97,   153,   401,   184,   153,   380,   184,    -1,    70,
     153,   381,   184,    -1,    39,   153,   381,   184,    -1,    23,
     380,   184,    -1,    59,   153,   401,   184,   153,   380,   184,
      -1,   538,    -1,   538,   144,    -1,    94,   534,    -1,   536,
      -1,   536,   535,    -1,   210,   156,   187,    -1,   144,    -1,
     193,    -1,   176,    -1,   538,    -1,   539,    -1,   152,   156,
     187,    -1,   555,    -1,   558,    -1,   534,    -1,   537,   107,
     534,    -1,   627,    -1,   541,    -1,   547,    -1,   545,    -1,
     548,    -1,   546,    -1,   544,    -1,   543,    -1,   542,    -1,
     540,    -1,   224,   156,   187,    -1,    44,   156,   187,    -1,
      44,   156,   547,   187,    -1,    44,   156,   548,   187,    -1,
      70,   156,   187,    -1,    39,   156,   187,    -1,    59,   156,
     187,    -1,    59,   156,   626,   187,    -1,    59,   156,    29,
     187,    -1,    97,   156,   187,    -1,    97,   156,   627,   187,
      -1,    97,   156,   627,   107,   549,   187,    -1,    97,   156,
     193,   187,    -1,    97,   156,   193,   107,   549,   187,    -1,
      61,   156,   627,   187,    -1,    45,   156,   187,    -1,    45,
     156,   627,   187,    -1,    45,   156,   627,   107,   549,   187,
      -1,    45,   156,   627,   107,   550,   187,    -1,    45,   156,
     193,   187,    -1,    45,   156,   193,   107,   549,   187,    -1,
      45,   156,   193,   107,   550,   187,    -1,    62,   156,   627,
     187,    -1,   627,    -1,   627,   144,    -1,    29,    -1,   553,
      -1,   554,    -1,   627,   145,   149,    -1,    47,   369,   386,
      -1,   556,    -1,   557,    -1,    47,   156,   193,   187,    -1,
      47,   156,   187,    94,   534,    -1,    47,   156,   537,   187,
      94,   534,    -1,   156,   536,   187,    -1,    33,   219,   220,
      -1,    33,   219,   221,    -1,    33,   219,   222,    -1,   225,
     224,   402,   232,   402,    -1,   225,   224,   402,    94,   231,
     232,   402,    -1,   225,   224,   402,    94,   233,   232,   402,
      -1,   225,   224,   402,   217,   402,    -1,   225,   224,   402,
     218,   402,    -1,   225,   226,   402,   232,   402,    -1,   225,
     226,   402,    94,   231,   232,   402,    -1,   225,   226,   402,
      94,   233,   232,   402,    -1,   225,   226,   402,   217,   402,
      -1,   225,   226,   402,   218,   402,    -1,   223,   224,   402,
      -1,   223,   226,   402,    -1,   228,   224,   402,   236,   402,
      -1,   228,   229,   230,   224,   402,   236,   402,    -1,   227,
     224,   402,    94,   402,    -1,   235,   118,   565,   234,   402,
     186,   402,    -1,   566,    -1,   565,   107,   118,   566,    -1,
     627,   142,   402,    -1,   243,   153,   401,   184,   568,    -1,
     569,    -1,   568,   569,    -1,   244,   571,   570,    -1,   153,
     401,   184,    -1,   491,    -1,   571,   209,   491,    -1,   575,
     573,    -1,    -1,   574,    -1,   593,    -1,   574,   593,    -1,
     576,    -1,   575,   261,   576,    -1,   577,    -1,   576,   257,
     577,    -1,   578,    -1,   577,   259,   147,   578,    -1,   579,
      -1,   258,   579,    -1,   583,   580,   581,    -1,    -1,   598,
      -1,    -1,   582,    -1,   281,   153,   401,   184,    -1,   587,
     584,    -1,   156,   572,   187,    -1,   585,    -1,    -1,   620,
      -1,   478,   153,   586,   184,    -1,    -1,   572,    -1,   588,
     589,    -1,   497,    -1,   153,   401,   184,    -1,    -1,   590,
      -1,   247,   591,    -1,   246,   592,    -1,   269,    -1,    -1,
      78,    -1,    -1,   285,    -1,   594,    -1,   595,    -1,   596,
      -1,   622,    -1,   619,    -1,   169,    -1,   283,   463,   597,
      -1,   252,   621,   597,    -1,   285,    -1,   275,    -1,   268,
      -1,   245,   599,    -1,   598,   245,   599,    -1,   600,    -1,
     601,    -1,   602,    -1,   617,    -1,   603,    -1,   611,    -1,
     604,    -1,   618,    -1,   100,   273,    -1,   100,   262,    -1,
     265,    -1,   280,    -1,   250,   273,    -1,   250,   262,    -1,
      56,   627,    29,    -1,   276,    -1,    54,   276,    -1,   278,
     605,    -1,   278,   156,   605,   606,   187,    -1,    54,   278,
      -1,   608,    -1,   113,    -1,    -1,   107,   607,    -1,   608,
      -1,   607,   107,   608,    -1,    96,    29,   609,   610,    -1,
      -1,   270,    29,    -1,    -1,   621,   264,    -1,   277,   285,
     612,   614,    -1,   277,   285,   113,   614,    -1,    54,   277,
     285,    -1,    96,    29,    -1,   156,   613,   187,    -1,    29,
      -1,   613,   107,    29,    -1,    -1,   615,    -1,   616,    -1,
     615,   616,    -1,   200,   612,    -1,   136,   612,    -1,   263,
      29,    -1,   282,    -1,    54,   282,    -1,    96,   216,    -1,
      96,   253,    -1,   254,   249,    -1,   266,   621,   279,    -1,
     255,   463,    -1,    96,   129,   463,    -1,    96,    52,   463,
      -1,   256,   463,   198,   463,    -1,   271,   623,    -1,   251,
     623,    -1,   274,    -1,   267,    -1,   284,   249,   465,    -1,
      29,    -1,    16,    -1,   627,    -1,   628,    -1,    97,    -1,
      39,    -1,    44,    -1,    45,    -1,   152,    -1,    48,    -1,
     224,    -1,    59,    -1,    61,    -1,    62,    -1,    70,    -1,
      73,    -1,    72,    -1,   210,    -1,   242,    -1,   629,    -1,
      24,    -1,   214,    -1,   127,    -1,    38,    -1,   260,    -1,
      37,    -1,   221,    -1,   220,    -1,   146,    -1,    43,    -1,
     258,    -1,   259,    -1,   273,    -1,   262,    -1,   250,    -1,
     284,    -1,   276,    -1,   278,    -1,   277,    -1,   282,    -1,
     254,    -1,   249,    -1,    78,    -1,   216,    -1,   253,    -1,
      52,    -1,   222,    -1,   235,    -1,   301,    -1,   229,    -1,
     202,    -1,   207,    -1,   206,    -1,   205,    -1,   204,    -1,
     203,    -1,    96,    -1,   111,    -1,   112,    -1,   186,    -1,
      46,    -1,    36,    -1,    66,    -1,    71,    -1,    58,    -1,
      53,    -1,    55,    -1,    77,    -1,    42,    -1,   147,    -1,
      51,    -1,   211,    -1,   170,    -1,   171,    -1,   168,    -1,
      69,    -1,    95,    -1,   116,    -1,   128,    -1,   129,    -1,
     106,    -1,    67,    -1,   135,    -1,   188,    -1,   100,    -1,
      94,    -1,   197,    -1,   126,    -1,   167,    -1,    92,    -1,
      50,    -1,   230,    -1,   101,    -1,   198,    -1,   117,    -1,
     159,    -1,   200,    -1,   150,    -1,   136,    -1,    75,    -1,
      76,    -1,   102,    -1,   199,    -1,   151,    -1,   182,    -1,
     195,    -1,   160,    -1,   137,    -1,   131,    -1,   166,    -1,
     148,    -1,   165,    -1,    33,    -1,    40,    -1,    57,    -1,
     113,    -1,    41,    -1,    56,    -1,   215,    -1,    49,    -1,
      60,    -1,    34,    -1,    47,    -1,   272,    -1,   248,    -1,
     281,    -1,   283,    -1,   252,    -1,   266,    -1,   279,    -1,
     271,    -1,   251,    -1,   265,    -1,   280,    -1,   270,    -1,
     264,    -1,   263,    -1,   247,    -1,   246,    -1,   255,    -1,
     256,    -1,   285,    -1,   275,    -1,   274,    -1,   269,    -1,
     267,    -1,   268,    -1,   228,    -1,   234,    -1,   231,    -1,
     225,    -1,   218,    -1,   217,    -1,   219,    -1,   236,    -1,
     226,    -1,   227,    -1,   233,    -1,   223,    -1,   232,    -1,
      65,    -1,    63,    -1,    74,    -1,   169,    -1,   201,    -1,
     241,    -1,   239,    -1,   240,    -1,   237,    -1,   238,    -1,
     243,    -1,   244,    -1,   245,    -1,    64,    -1,   294,    -1,
     292,    -1,   293,    -1,   298,    -1,   299,    -1,   300,    -1,
     295,    -1,   296,    -1,   297,    -1,    79,    -1,    80,    -1,
      81,    -1,    82,    -1,    83,    -1,    84,    -1,    85,    -1,
      86,    -1,    87,    -1,    88,    -1,    89,    -1,   286,    -1,
     287,    -1,   288,    -1,   289,    -1,   290,    -1,   291,    -1,
     302,    -1,   303,    -1,   304,    -1,   305,    -1,   306,    -1,
     307,    -1,   308,    -1,    90,    -1,   105,    -1,   114,    -1,
     172,    -1,   180,    -1,   189,    -1,   138,    -1,    91,    -1,
     115,    -1,   139,    -1,   181,    -1,   625,   121,   626,    -1,
      25,    -1
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
    1303,  1308,  1312,  1316,  1320,  1322,  1328,  1330,  1334,  1335,
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
    1652,  1654,  1656,  1658,  1660,  1662,  1665,  1668,  1672,  1674,
    1679,  1684,  1688,  1693,  1695,  1699,  1701,  1703,  1705,  1707,
    1709,  1714,  1720,  1729,  1739,  1749,  1760,  1762,  1765,  1767,
    1770,  1777,  1778,  1780,  1784,  1788,  1789,  1791,  1793,  1795,
    1798,  1801,  1802,  1804,  1806,  1808,  1811,  1814,  1816,  1818,
    1820,  1822,  1824,  1826,  1828,  1830,  1832,  1834,  1836,  1840,
    1844,  1847,  1851,  1855,  1858,  1860,  1862,  1864,  1866,  1868,
    1870,  1875,  1879,  1887,  1891,  1899,  1904,  1909,  1913,  1921,
    1923,  1926,  1929,  1931,  1934,  1938,  1940,  1942,  1944,  1946,
    1948,  1952,  1954,  1956,  1958,  1962,  1964,  1966,  1968,  1970,
    1972,  1974,  1976,  1978,  1980,  1982,  1986,  1990,  1995,  2000,
    2004,  2008,  2012,  2017,  2022,  2026,  2031,  2038,  2043,  2050,
    2055,  2059,  2064,  2071,  2078,  2083,  2090,  2097,  2102,  2104,
    2107,  2109,  2111,  2113,  2117,  2121,  2123,  2125,  2130,  2136,
    2143,  2147,  2151,  2155,  2159,  2165,  2173,  2181,  2187,  2193,
    2199,  2207,  2215,  2221,  2227,  2231,  2235,  2241,  2249,  2255,
    2263,  2265,  2270,  2274,  2280,  2282,  2285,  2289,  2293,  2295,
    2299,  2302,  2303,  2305,  2307,  2310,  2312,  2316,  2318,  2322,
    2324,  2329,  2331,  2334,  2338,  2339,  2341,  2342,  2344,  2349,
    2352,  2356,  2358,  2359,  2361,  2366,  2367,  2369,  2372,  2374,
    2378,  2379,  2381,  2384,  2387,  2389,  2390,  2392,  2393,  2395,
    2397,  2399,  2401,  2403,  2405,  2407,  2411,  2415,  2417,  2419,
    2421,  2424,  2428,  2430,  2432,  2434,  2436,  2438,  2440,  2442,
    2444,  2447,  2450,  2452,  2454,  2457,  2460,  2464,  2466,  2469,
    2472,  2478,  2481,  2483,  2485,  2486,  2489,  2491,  2495,  2500,
    2501,  2504,  2505,  2508,  2513,  2518,  2522,  2525,  2529,  2531,
    2535,  2536,  2538,  2540,  2543,  2546,  2549,  2552,  2554,  2557,
    2560,  2563,  2566,  2570,  2573,  2577,  2581,  2586,  2589,  2592,
    2594,  2596,  2600,  2602,  2604,  2606,  2608,  2610,  2612,  2614,
    2616,  2618,  2620,  2622,  2624,  2626,  2628,  2630,  2632,  2634,
    2636,  2638,  2640,  2642,  2644,  2646,  2648,  2650,  2652,  2654,
    2656,  2658,  2660,  2662,  2664,  2666,  2668,  2670,  2672,  2674,
    2676,  2678,  2680,  2682,  2684,  2686,  2688,  2690,  2692,  2694,
    2696,  2698,  2700,  2702,  2704,  2706,  2708,  2710,  2712,  2714,
    2716,  2718,  2720,  2722,  2724,  2726,  2728,  2730,  2732,  2734,
    2736,  2738,  2740,  2742,  2744,  2746,  2748,  2750,  2752,  2754,
    2756,  2758,  2760,  2762,  2764,  2766,  2768,  2770,  2772,  2774,
    2776,  2778,  2780,  2782,  2784,  2786,  2788,  2790,  2792,  2794,
    2796,  2798,  2800,  2802,  2804,  2806,  2808,  2810,  2812,  2814,
    2816,  2818,  2820,  2822,  2824,  2826,  2828,  2830,  2832,  2834,
    2836,  2838,  2840,  2842,  2844,  2846,  2848,  2850,  2852,  2854,
    2856,  2858,  2860,  2862,  2864,  2866,  2868,  2870,  2872,  2874,
    2876,  2878,  2880,  2882,  2884,  2886,  2888,  2890,  2892,  2894,
    2896,  2898,  2900,  2902,  2904,  2906,  2908,  2910,  2912,  2914,
    2916,  2918,  2920,  2922,  2924,  2926,  2928,  2930,  2932,  2934,
    2936,  2938,  2940,  2942,  2944,  2946,  2948,  2950,  2952,  2954,
    2956,  2958,  2960,  2962,  2964,  2966,  2968,  2970,  2972,  2974,
    2976,  2978,  2980,  2982,  2984,  2986,  2988,  2990,  2992,  2994,
    2996,  2998,  3000,  3002,  3004,  3006,  3008,  3010,  3012,  3014,
    3016,  3018,  3020,  3022,  3024,  3026,  3028,  3030,  3032,  3034,
    3036,  3040
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   994,   994,   995,  1004,  1013,  1019,  1027,  1033,  1044,
    1049,  1057,  1064,  1071,  1080,  1087,  1095,  1103,  1111,  1122,
    1127,  1134,  1141,  1153,  1163,  1170,  1177,  1189,  1190,  1191,
    1192,  1193,  1198,  1199,  1200,  1201,  1202,  1203,  1204,  1207,
    1212,  1217,  1225,  1233,  1241,  1246,  1254,  1259,  1267,  1272,
    1280,  1287,  1294,  1301,  1311,  1313,  1316,  1326,  1331,  1339,
    1347,  1358,  1365,  1376,  1381,  1389,  1396,  1403,  1412,  1425,
    1433,  1440,  1450,  1457,  1464,  1475,  1476,  1477,  1478,  1479,
    1480,  1481,  1482,  1487,  1493,  1502,  1509,  1519,  1529,  1530,
    1531,  1532,  1533,  1534,  1535,  1536,  1537,  1538,  1543,  1551,
    1559,  1567,  1574,  1582,  1589,  1594,  1602,  1610,  1625,  1640,
    1658,  1663,  1671,  1679,  1690,  1695,  1704,  1709,  1716,  1721,
    1731,  1736,  1745,  1751,  1764,  1769,  1777,  1788,  1803,  1815,
    1830,  1835,  1840,  1845,  1853,  1860,  1871,  1876,  1886,  1893,
    1900,  1907,  1917,  1921,  1931,  1939,  1950,  1956,  1965,  1970,
    1977,  1984,  1995,  2005,  2015,  2025,  2043,  2063,  2068,  2073,
    2080,  2085,  2090,  2097,  2102,  2114,  2121,  2133,  2134,  2135,
    2136,  2137,  2138,  2139,  2141,  2142,  2143,  2144,  2145,  2150,
    2155,  2163,  2180,  2188,  2196,  2203,  2210,  2220,  2232,  2245,
    2257,  2273,  2281,  2289,  2297,  2312,  2317,  2325,  2339,  2356,
    2381,  2389,  2396,  2407,  2417,  2422,  2437,  2438,  2439,  2440,
    2441,  2442,  2447,  2448,  2451,  2452,  2453,  2454,  2455,  2460,
    2474,  2482,  2487,  2495,  2500,  2505,  2513,  2522,  2534,  2544,
    2557,  2565,  2566,  2567,  2572,  2573,  2574,  2575,  2576,  2581,
    2588,  2598,  2606,  2613,  2623,  2633,  2643,  2653,  2663,  2673,
    2683,  2693,  2704,  2713,  2723,  2733,  2749,  2758,  2767,  2775,
    2781,  2793,  2801,  2811,  2819,  2831,  2837,  2848,  2850,  2854,
    2862,  2866,  2871,  2875,  2879,  2883,  2893,  2901,  2908,  2914,
    2925,  2929,  2938,  2946,  2952,  2962,  2968,  2978,  2982,  2992,
    2998,  3004,  3010,  3019,  3028,  3037,  3050,  3054,  3062,  3068,
    3078,  3086,  3095,  3108,  3115,  3127,  3131,  3143,  3150,  3156,
    3165,  3172,  3178,  3189,  3196,  3202,  3211,  3220,  3227,  3238,
    3245,  3257,  3263,  3275,  3281,  3292,  3298,  3309,  3315,  3326,
    3335,  3339,  3348,  3352,  3360,  3364,  3374,  3381,  3390,  3400,
    3399,  3413,  3422,  3431,  3444,  3448,  3460,  3464,  3472,  3475,
    3482,  3486,  3495,  3499,  3503,  3512,  3516,  3522,  3528,  3534,
    3545,  3549,  3553,  3561,  3565,  3571,  3581,  3585,  3595,  3599,
    3609,  3613,  3623,  3627,  3637,  3641,  3649,  3653,  3657,  3661,
    3671,  3675,  3679,  3687,  3691,  3695,  3699,  3703,  3707,  3715,
    3719,  3723,  3731,  3735,  3739,  3743,  3754,  3760,  3770,  3776,
    3786,  3790,  3794,  3832,  3836,  3846,  3856,  3869,  3878,  3888,
    3892,  3901,  3905,  3914,  3920,  3928,  3934,  3946,  3952,  3962,
    3966,  3970,  3974,  3978,  3984,  3990,  3998,  4002,  4010,  4014,
    4025,  4029,  4033,  4039,  4043,  4057,  4061,  4069,  4073,  4083,
    4087,  4091,  4095,  4104,  4108,  4112,  4116,  4124,  4130,  4140,
    4148,  4152,  4156,  4160,  4164,  4168,  4172,  4176,  4180,  4190,
    4198,  4202,  4210,  4217,  4224,  4235,  4243,  4247,  4255,  4263,
    4271,  4325,  4329,  4342,  4348,  4358,  4362,  4370,  4374,  4378,
    4386,  4396,  4406,  4416,  4426,  4436,  4451,  4457,  4468,  4474,
    4485,  4496,  4498,  4502,  4507,  4517,  4520,  4527,  4533,  4539,
    4547,  4560,  4563,  4570,  4576,  4582,  4589,  4600,  4604,  4614,
    4618,  4628,  4632,  4636,  4641,  4650,  4656,  4662,  4668,  4676,
    4681,  4689,  4694,  4702,  4710,  4715,  4720,  4725,  4730,  4735,
    4744,  4752,  4756,  4773,  4777,  4785,  4793,  4801,  4805,  4813,
    4819,  4829,  4837,  4841,  4845,  4880,  4886,  4892,  4902,  4906,
    4910,  4914,  4918,  4925,  4931,  4941,  4949,  4953,  4957,  4961,
    4965,  4969,  4973,  4977,  4981,  4989,  4997,  5001,  5005,  5015,
    5023,  5031,  5035,  5039,  5047,  5051,  5057,  5063,  5067,  5077,
    5085,  5089,  5095,  5104,  5113,  5119,  5125,  5135,  5152,  5159,
    5174,  5210,  5214,  5222,  5230,  5242,  5246,  5254,  5262,  5266,
    5277,  5294,  5300,  5306,  5316,  5320,  5326,  5332,  5336,  5342,
    5346,  5352,  5358,  5365,  5375,  5380,  5388,  5394,  5404,  5426,
    5435,  5441,  5454,  5468,  5475,  5481,  5491,  5500,  5508,  5514,
    5532,  5541,  5544,  5551,  5556,  5564,  5568,  5575,  5579,  5586,
    5590,  5597,  5601,  5610,  5623,  5626,  5634,  5637,  5645,  5653,
    5661,  5665,  5673,  5676,  5684,  5696,  5699,  5707,  5719,  5725,
    5735,  5738,  5746,  5750,  5754,  5762,  5765,  5773,  5776,  5784,
    5788,  5792,  5796,  5800,  5808,  5816,  5828,  5840,  5844,  5848,
    5856,  5862,  5872,  5876,  5880,  5884,  5888,  5892,  5896,  5900,
    5908,  5912,  5916,  5920,  5928,  5934,  5944,  5954,  5958,  5966,
    5976,  5987,  5994,  5998,  6006,  6009,  6016,  6021,  6030,  6040,
    6043,  6051,  6054,  6062,  6071,  6078,  6088,  6092,  6099,  6105,
    6115,  6118,  6125,  6130,  6142,  6150,  6162,  6170,  6174,  6182,
    6186,  6190,  6198,  6206,  6210,  6214,  6218,  6226,  6234,  6246,
    6250,  6258,  6271,  6275,  6276,  6289,  6290,  6291,  6292,  6293,
    6294,  6295,  6296,  6297,  6298,  6299,  6300,  6301,  6302,  6303,
    6304,  6308,  6309,  6310,  6311,  6312,  6313,  6314,  6315,  6316,
    6317,  6318,  6319,  6320,  6321,  6322,  6323,  6324,  6325,  6326,
    6327,  6328,  6329,  6330,  6331,  6332,  6333,  6334,  6335,  6336,
    6337,  6338,  6339,  6340,  6341,  6342,  6343,  6344,  6345,  6346,
    6347,  6348,  6349,  6350,  6351,  6352,  6353,  6354,  6355,  6356,
    6357,  6358,  6359,  6360,  6361,  6362,  6363,  6364,  6365,  6366,
    6367,  6368,  6369,  6370,  6371,  6372,  6373,  6374,  6375,  6376,
    6377,  6378,  6379,  6380,  6381,  6382,  6383,  6384,  6385,  6386,
    6387,  6388,  6389,  6390,  6391,  6392,  6393,  6394,  6395,  6396,
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
    6511,  6518
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
  const int xquery_parser::yylast_ = 13309;
  const int xquery_parser::yynnts_ = 307;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 571;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 323;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 577;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 16184 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 6522 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"


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

