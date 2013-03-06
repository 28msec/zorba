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
#line 87 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"


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
#line 77 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 913 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 299 of lalr1.cc  */
#line 1038 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 299 of lalr1.cc  */
#line 107 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"

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
#line 193 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"

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
        case 111: /* "\"'DECIMAL'\"" */

/* Line 480 of lalr1.cc  */
#line 911 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 298 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 125: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 307 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 150: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 909 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 316 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 325 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 334 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 343 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 352 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 361 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 370 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 379 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 388 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 397 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 406 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 415 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 424 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 433 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 442 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 451 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 460 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 469 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 478 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 487 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 496 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 505 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 514 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 523 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 532 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 541 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 550 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 559 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 568 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 577 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 586 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 595 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 604 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 613 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 622 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 631 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 640 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 649 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 658 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 667 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 676 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 685 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 694 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 703 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 712 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 721 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 730 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 739 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 748 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 757 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 775 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 784 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 793 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 802 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 811 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 820 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 829 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 838 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 856 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 865 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 874 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 883 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 892 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 901 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 919 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 937 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 946 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 955 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 964 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 973 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 982 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 991 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1000 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1009 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1018 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1027 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1036 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1045 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1054 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1063 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1072 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1081 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1090 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1099 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1108 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1117 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1126 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1135 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1144 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1153 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1162 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1171 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1180 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1189 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1198 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1207 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1216 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1225 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1234 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1243 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1252 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1261 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1270 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1279 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1288 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1297 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1306 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1315 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1324 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1333 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1342 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1351 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1360 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "SequenceTypeList" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1369 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1378 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1387 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1396 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1405 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1414 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1423 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1432 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1441 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1450 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1459 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1468 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1477 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1486 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1495 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1504 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1513 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1522 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1531 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1540 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1549 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "SimpleMapExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1558 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1567 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1576 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1585 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1594 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1603 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1612 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1621 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1630 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1639 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1648 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1657 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1666 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1675 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1684 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1693 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1702 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1711 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1720 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1729 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1738 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1747 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1756 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1765 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1774 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1783 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1792 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1801 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1810 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1819 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1828 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1837 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1846 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1855 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1864 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1873 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1882 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1891 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1900 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1909 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1918 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1927 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1936 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1945 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1954 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1963 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1972 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1981 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1990 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1999 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2008 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2017 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2026 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2035 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2044 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2053 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2062 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "CompNamespaceConstructor" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2071 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2080 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2089 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2098 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2107 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2116 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "GeneralizedAtomicType" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2125 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "SimpleType" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2134 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2143 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2152 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2161 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2170 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2179 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2188 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2197 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2206 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2215 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2224 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2233 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2242 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2251 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2260 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2269 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2278 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2287 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2296 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2305 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2314 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2323 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2332 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2341 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2350 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2359 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2368 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2377 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2386 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2395 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2404 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2413 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2422 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2431 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2440 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2449 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2458 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2467 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2476 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2485 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2494 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2503 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2512 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2521 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2530 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2539 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 613: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2548 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 614: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2557 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 615: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2566 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2575 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2584 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 618: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2593 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 619: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2602 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2611 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 624: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2620 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 627: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2629 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2638 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 632: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2647 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 633: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2656 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 634: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2665 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 635: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2674 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 636: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2683 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 637: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2692 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 638: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2701 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 639: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2710 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 640: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2719 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 641: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2728 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 642: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2737 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 643: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2746 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 644: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2755 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 645: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2764 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 646: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2773 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 647: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2782 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 648: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2791 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 649: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2800 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 650: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2809 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 657: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2818 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 658: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2827 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 659: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2836 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
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
#line 140 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 565 of lalr1.cc  */
#line 2933 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"

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
#line 1056 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 1060 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 1064 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 1072 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 1078 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 1082 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 1091 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 1097 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 1105 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 1111 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 1122 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 1127 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 1135 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 1142 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 1149 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 1158 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 1165 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 1173 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 1181 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 1189 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 1200 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 1205 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 1212 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 1219 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 1231 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 1241 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 1248 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 1255 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      // error
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 1290 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 1295 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 1303 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1311 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1319 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1324 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1332 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1337 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1345 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1350 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 1358 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 1363 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1368 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1373 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 1386 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 1396 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1401 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1409 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1417 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1428 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1435 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1446 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1451 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 1459 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1466 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1473 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1482 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 1495 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1503 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 1510 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 1520 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 1527 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 1534 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1557 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1563 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1572 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1579 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1589 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1598 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1599 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1600 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1601 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1602 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1603 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1604 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1605 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1606 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1607 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1613 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1621 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1629 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1637 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1644 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1652 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1659 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1664 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1672 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1680 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1694 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1708 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1725 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1730 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1738 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1746 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1757 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1762 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1771 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1776 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1783 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1788 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1798 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1803 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1812 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1818 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1831 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1836 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1844 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1855 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1870 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1882 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1897 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1902 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1907 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1912 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1920 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1927 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1938 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1943 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1953 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1962 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1971 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1980 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1992 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1996 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 2002 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 2006 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 2016 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2026 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2039 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 2045 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 2054 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 2059 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 2066 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 2073 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 2085 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 2095 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 2105 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 2116 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2132 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2152 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 2156 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 2160 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 2168 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 2172 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 2176 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 2184 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 2189 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 2201 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 2208 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 2218 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2250 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 2255 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 2263 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2280 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 2288 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 2296 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 2303 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 2310 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 2321 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2330 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2339 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2348 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2361 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 2369 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 2377 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2385 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2400 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2405 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 2413 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2427 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2444 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2469 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 2477 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 2484 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2495 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2505 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2510 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2523 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2570 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2584 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 2592 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 2597 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2605 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2610 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2615 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2623 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2632 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2644 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2654 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2667 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 2691 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 2698 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2708 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2714 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected qualified name \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (3)].node);
      YYERROR;
    }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2723 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL; // to prevent the Bison warning
      error((yylocation_stack_[(2) - (2)]), ""); // the error message is already set in the driver's parseError member
      YYERROR;
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2733 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2740 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2748 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (3)]), "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yysemantic_stack_[(3) - (3)].node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (1)].node);
      YYERROR;
    }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2760 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2770 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2780 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2790 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2800 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2810 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2820 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2830 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2841 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2850 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2860 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2870 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2886 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2895 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2904 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2912 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2918 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2930 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2938 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2948 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2956 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2968 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2974 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2987 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2991 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2999 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 3003 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 3012 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 3016 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 3020 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 3030 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 3038 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 3045 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 3051 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 3061 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 3065 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 3069 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 3077 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 3085 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 3093 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         NULL,
                         NULL,
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 3105 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 3113 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 3119 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 3129 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 3135 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 3145 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 3149 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 3159 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 3165 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 3171 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 3177 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3186 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3195 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3204 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3217 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 3221 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 3229 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 3235 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 3245 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 3253 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3262 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3275 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 3282 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 3294 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 3298 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 3310 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 3317 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 3323 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 3332 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 3339 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 3345 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 3356 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 3363 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 3369 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 3378 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 3387 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 3394 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 3405 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 3412 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 3424 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 3430 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 3442 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 3448 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 3459 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 3465 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 3476 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 3482 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 3493 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 3499 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 3510 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 3519 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 3523 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 3532 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3536 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3544 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3548 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3558 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3565 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3574 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3583 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3588 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3597 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3606 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3615 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3628 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3632 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3644 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3648 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3655 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3659 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3666 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3670 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3679 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3683 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3687 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3695 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3699 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3705 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3711 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3717 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3727 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3731 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3735 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3743 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3747 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3753 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3763 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3767 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3777 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3781 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3791 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3795 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3805 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3809 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3819 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3823 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3832 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3836 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3844 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3848 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3852 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3856 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3866 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3870 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3874 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3881 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3886 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3894 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3898 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3902 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3906 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3910 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3914 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3922 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3926 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3930 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3938 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3942 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3946 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3950 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3961 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3967 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 3977 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 3983 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 3993 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 3997 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 4001 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 4039 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 4043 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 4053 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 4063 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 4076 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 4085 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 4095 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 4099 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 4108 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 4112 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 4121 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 4127 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 4135 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 4141 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 4153 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 4159 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 4169 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 4173 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 4177 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 4181 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 4185 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 4191 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 4197 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 4205 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 4209 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 4217 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 4221 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 4232 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 4236 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 4240 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 4246 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 4250 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 4264 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 4268 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 4276 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 4280 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 4290 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 4294 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 4298 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 4302 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 4311 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 4315 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 4319 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 4323 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 4331 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 4337 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 4347 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 4355 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 4359 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 4363 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 4367 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 4371 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 4375 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 4379 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 4383 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 4387 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 4391 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 4396 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 4400 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 4404 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 4408 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 4416 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 4420 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 4428 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 4435 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 4442 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 4453 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 4461 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 4465 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 4473 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 4481 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 4489 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 4543 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 4547 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 4560 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 4566 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 4576 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 4580 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 4588 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 4592 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 4596 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 4604 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                  NULL,
                                  NULL,
                                  NULL);
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 4612 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      if (static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr))->get_qname())
      {
        error((yylocation_stack_[(8) - (5)]), "syntax error, end tag </" +
                  static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr))->get_qname().str() +
                  "> does not match start tag <" +
                  static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr))->get_qname().str() + ">");
        YYERROR;
      }

      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr)),
                                  static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr)),
                                  NULL,
                                  NULL);
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 4629 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                  NULL,
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                                  NULL);
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 4637 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      if (static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname())
      {
        error((yylocation_stack_[(9) - (5)]), "syntax error, end tag </" +
                  static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname().str() +
                  "> does not match start tag <" +
                  static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname().str() + ">");
        YYERROR;
      }

      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
                                  static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
                                  NULL);
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 4656 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      if (static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname())
      {
        error((yylocation_stack_[(9) - (5)]), "syntax error, end tag </" +
                  static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname().str() +
                  "> does not match start tag <" +
                  static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname().str() + ">");
        YYERROR;
      }

      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
                                  static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
                                  NULL,
                                  dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 4675 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      if (static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname())
      {
        error((yylocation_stack_[(10) - (5)]), "syntax error, end tag </" +
                  static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname().str() +
                  "> does not match start tag <" +
                  static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr))->get_qname().str() + ">");
        YYERROR;
      }

      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr)),
                                  static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)),
                                  dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 4697 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 4703 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 4714 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 4720 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 4731 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 4746 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 4751 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 4760 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 4764 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 4771 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 4777 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 4783 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 4790 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 4801 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 4805 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 4812 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 4818 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 4824 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 4831 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 4842 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 4846 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 4854 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 4858 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 4866 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 4870 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 4874 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 4879 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 4888 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 4892 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 4896 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 4900 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 4908 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 4913 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 4921 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 4926 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 4934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 4942 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 4947 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 4952 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 4957 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 4962 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 4967 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 4978 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 4986 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 4990 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 5007 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 5011 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 5019 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 5027 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 5035 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 5039 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 5047 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 5051 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 5059 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 5067 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 5071 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 5075 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 5110 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 5116 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 5122 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 5132 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 5136 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 5140 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 5144 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 5148 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 5152 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 5156 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 5163 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 5169 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 5179 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 5187 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 5195 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 5199 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 5203 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 5207 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 5211 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 5215 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 5219 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 5223 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 5227 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 5235 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 5243 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 5247 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 5251 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 5261 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 5269 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 5277 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 5281 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 5285 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 5293 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 5297 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 5303 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 5309 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 5313 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 5323 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 5331 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 5335 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 5341 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 5350 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 5359 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 5365 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 5371 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 5381 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 5398 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 5405 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 5420 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 5456 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 5460 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 5468 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 5476 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 5488 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 5492 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 5500 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 5508 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 5512 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 5523 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 5540 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 5546 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 5552 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 5562 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 5566 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 5572 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 5578 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 5582 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 5588 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 5592 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 5598 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 5604 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 5611 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 5621 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 5626 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 5634 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 5640 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 5650 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 5672 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 5681 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 5687 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 5700 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 5714 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 5721 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 5727 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 5737 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 5746 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 5754 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 5760 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 5778 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 5786 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 5790 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 5797 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 5802 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 5810 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 5814 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 5821 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 5825 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 5832 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 5836 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 5843 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 5847 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 5856 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 5868 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 5872 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 5879 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 5883 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 5891 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 5899 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 5907 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 5911 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 5918 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 5922 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 5930 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 5941 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 5945 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 5953 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 5965 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 5971 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 5980 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 5984 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 5992 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 5996 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 6000 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 6007 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 6011 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 6018 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 6022 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 6030 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 6034 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 6038 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 6042 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 6046 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 6054 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 6062 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 6074 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 6086 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 6090 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 6094 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 6102 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 6108 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 6118 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 6122 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 6126 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 6130 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 6134 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 6138 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 6142 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 6146 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 6154 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 6158 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 6162 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 6166 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 6174 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 6180 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 6190 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 6200 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 6204 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 6212 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

  case 734:

/* Line 690 of lalr1.cc  */
#line 6222 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

  case 735:

/* Line 690 of lalr1.cc  */
#line 6233 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 6240 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 6244 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 6251 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 6255 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 6262 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 6267 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 6276 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 6285 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 6289 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 6296 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 6300 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 6308 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 6317 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 6324 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 6334 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 6338 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 6345 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 6351 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 6360 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 6364 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 6371 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 6376 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 6388 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 6396 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 6408 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 6416 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 6420 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 6428 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 6432 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 6436 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 6444 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 6452 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 6456 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 6460 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 6464 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 6472 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 6480 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 6492 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 6496 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 6504 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 6518 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 6522 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 6529 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 6534 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 6542 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 6547 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 6556 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 6564 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 6570 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 6580 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 6586 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

  case 787:

/* Line 690 of lalr1.cc  */
#line 6596 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 6603 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 789:

/* Line 690 of lalr1.cc  */
#line 6610 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

  case 790:

/* Line 690 of lalr1.cc  */
#line 6635 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

  case 791:

/* Line 690 of lalr1.cc  */
#line 6663 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

  case 792:

/* Line 690 of lalr1.cc  */
#line 6691 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 793:

/* Line 690 of lalr1.cc  */
#line 6695 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 6699 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 6706 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 796:

/* Line 690 of lalr1.cc  */
#line 6713 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 6720 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 6737 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
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

  case 802:

/* Line 690 of lalr1.cc  */
#line 6750 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 803:

/* Line 690 of lalr1.cc  */
#line 6751 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 6752 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 805:

/* Line 690 of lalr1.cc  */
#line 6753 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 6754 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 6755 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 6756 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 6757 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 6758 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 6759 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 6760 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 6761 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 6762 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 6763 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 6764 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 6769 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 6770 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 6771 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 6772 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 6773 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 6774 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 6775 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 6776 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 6777 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 6778 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 6779 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 6780 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 6781 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 6782 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 6783 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 6784 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 6785 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 6786 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 6787 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 6788 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 6789 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 6790 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 6791 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 6792 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 6793 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 6794 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 6795 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 6796 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 6797 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 6798 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 6799 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 6800 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 6801 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 6802 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 6803 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 6804 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 6805 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 6806 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 6807 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 6808 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 6809 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 6810 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 6811 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 6812 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 6813 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 6814 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 6815 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 6816 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 6817 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 6818 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 6819 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 6820 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 6821 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 6822 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 6823 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 6824 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 6825 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 6826 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 6827 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 6828 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 6829 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 6830 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 6831 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 6832 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 6833 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 6834 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 6835 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 6836 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 6837 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 6838 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 6839 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 6840 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 6841 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 6842 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 6843 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 6844 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 6845 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 6846 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 6847 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 6848 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 6849 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 6850 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 6851 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 6852 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 6853 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 6854 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 6855 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 6856 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 6857 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 6858 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 6859 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 6860 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 6861 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 6862 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 6863 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 6864 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 6865 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 6866 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 6867 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 6868 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 6869 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 6870 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 6871 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 6872 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 6873 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 6874 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 6875 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 6876 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 6877 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 6878 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 6879 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 6880 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 6881 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 6882 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 6883 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 6884 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 6885 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 6886 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 6887 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 6888 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 6889 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 6890 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 6891 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 6892 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 6893 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 6894 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 6895 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 6896 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 6897 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 6898 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 6899 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 6900 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 6901 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 6902 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 6903 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 6904 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 6905 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 6906 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 6907 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 6908 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 6909 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 6910 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 6911 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 6912 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 6913 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 6914 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 6915 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 6916 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 6917 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 6918 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 6919 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 6920 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 6921 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 6922 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 6923 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 6924 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 6925 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 6926 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 6927 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 6928 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 6929 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 6930 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 6931 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 6932 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 6933 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 6934 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 6935 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 6936 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 6937 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 6938 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 6939 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 6940 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 6941 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 6942 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 6943 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 6944 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 6945 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 6946 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 6947 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 997:

/* Line 690 of lalr1.cc  */
#line 6948 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 998:

/* Line 690 of lalr1.cc  */
#line 6949 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 999:

/* Line 690 of lalr1.cc  */
#line 6950 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 1000:

/* Line 690 of lalr1.cc  */
#line 6951 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 1001:

/* Line 690 of lalr1.cc  */
#line 6952 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 1002:

/* Line 690 of lalr1.cc  */
#line 6953 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 1003:

/* Line 690 of lalr1.cc  */
#line 6954 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 1004:

/* Line 690 of lalr1.cc  */
#line 6955 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 1005:

/* Line 690 of lalr1.cc  */
#line 6956 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 1006:

/* Line 690 of lalr1.cc  */
#line 6957 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 1007:

/* Line 690 of lalr1.cc  */
#line 6958 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 1008:

/* Line 690 of lalr1.cc  */
#line 6959 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 1009:

/* Line 690 of lalr1.cc  */
#line 6960 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1010:

/* Line 690 of lalr1.cc  */
#line 6961 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1011:

/* Line 690 of lalr1.cc  */
#line 6962 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1012:

/* Line 690 of lalr1.cc  */
#line 6963 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1013:

/* Line 690 of lalr1.cc  */
#line 6964 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1014:

/* Line 690 of lalr1.cc  */
#line 6965 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1015:

/* Line 690 of lalr1.cc  */
#line 6966 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1016:

/* Line 690 of lalr1.cc  */
#line 6967 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 1017:

/* Line 690 of lalr1.cc  */
#line 6968 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 1018:

/* Line 690 of lalr1.cc  */
#line 6969 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1019:

/* Line 690 of lalr1.cc  */
#line 6970 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 1020:

/* Line 690 of lalr1.cc  */
#line 6971 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 1021:

/* Line 690 of lalr1.cc  */
#line 6972 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 1022:

/* Line 690 of lalr1.cc  */
#line 6973 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 1023:

/* Line 690 of lalr1.cc  */
#line 6978 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 12296 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1555;
  const short int
  xquery_parser::yypact_[] =
  {
      4794, -1555, -1555, -1555,  6353,  6353,  6353,  6353, -1555, -1555,
      53,   223, -1555,   138,   496, -1555, -1555, -1555,   832, -1555,
   -1555, -1555,   285,   364,   833,  4513,   631,   635,   162, -1555,
      92, -1555, -1555, -1555, -1555, -1555, -1555,   843, -1555,   772,
     842, -1555, -1555, -1555, -1555,   597, -1555,   844, -1555,   855,
     864, -1555,   324, -1555, -1555, -1555, -1555, -1555, -1555, -1555,
   -1555, -1555, -1555, -1555, -1555, -1555, -1555,   706,   765, -1555,
   -1555, -1555, -1555,    55, 12262, -1555, -1555, -1555,   905, -1555,
   -1555, -1555,   916, -1555,   932,   936, -1555, -1555, 16652, -1555,
   -1555, -1555, -1555, -1555, -1555, -1555, -1555,   941, -1555, -1555,
     938,   940, -1555, -1555, -1555, -1555, -1555, -1555, -1555,  5420,
    8219,  8530, 16652, -1555, -1555,   910, -1555, -1555, -1555, -1555,
     912, -1555, -1555,   945, 13158, -1555, 13462,   946,   947, -1555,
   -1555, -1555,   948, -1555, 11640, -1555, -1555, -1555, -1555, -1555,
   -1555,   919, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555,
     150,   857, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555,
     147,   918,   212, -1555,   -96,   281, -1555, -1555, -1555, -1555,
   -1555, -1555,   957, -1555,   835,   836,   839, -1555, -1555,   922,
     926, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555,
   -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555,
   -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555,
   -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555,
   -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555,
   -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555,
   -1555, -1555, -1555, -1555,  8841,  9152, -1555,   769, -1555, -1555,
   -1555, -1555, -1555,  5107,  6664,  1085, -1555,  6975, -1555, -1555,
     901,   103, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555,
   -1555, -1555, -1555, -1555, -1555, -1555,   110, -1555, -1555, -1555,
   -1555, -1555, -1555,   436, -1555, -1555, -1555, -1555, -1555, -1555,
   -1555, -1555,  6353, -1555, -1555, -1555, -1555,   290, -1555, -1555,
   -1555, -1555, -1555, -1555, -1555, -1555,   161, -1555,   896, -1555,
   -1555, -1555,   586, -1555, -1555, -1555, -1555, -1555, -1555, -1555,
   -1555,   920,   996, -1555,   798,   841,   992,   582,   700,   780,
     484, -1555,  1042,   893,   993,   994, 10396, -1555,   907, -1555,
   -1555,    16, -1555, -1555, 11951, -1555,   840, -1555,   944, 12262,
   -1555,   944, 12262, -1555, -1555, -1555,    28, -1555, -1555, -1555,
   -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555,
   -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555,
   -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555,
   -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555,
   -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555,   956,
     949, -1555, -1555, -1555, -1555, -1555,   923, -1555,  6353,   924,
     925,   928,  6353,   114,   114,  1074,   672,   775,   786, 16940,
   16652,   623,  1059, 16652,   958,   995,   754, 13158,   815,   883,
   16652, 16652,   824,   870,    75, -1555, -1555, -1555, 13158,  6353,
     954,  6353,   349, 10707, 14348, 16652, -1555,   847,   848, 16652,
    1015,    50,   981, 10707,  1135,    70,   101, 16652,  1018,  1000,
    1036, -1555, 10707, 12861, 16652, 16652, 16652,  6353,   959, 10707,
   10707, 16652,  6353,   991,   997, -1555, -1555, -1555, 10707, 14636,
     989, -1555,   999, -1555, -1555, -1555, -1555,  1001, -1555,  1002,
   -1555, -1555, -1555, -1555, -1555,  1003, -1555, -1555, -1555, -1555,
   -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555,
   -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555,
   -1555, -1555, -1555, -1555, -1555, 16652, -1555, -1555, -1555, -1555,
   -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555,  1005, 16652,
   -1555, -1555, -1555,   964,  5731,  1028,   367,  1004,  1007,  1008,
   16652,  6353, -1555,   998,   171, -1555,   696, -1555,   197,  1117,
   10707, 10707, -1555, -1555,   132, -1555, -1555, -1555,  1137, -1555,
   -1555, -1555, -1555, 10707,   951, -1555,  1132, 10707, 10707, 13763,
     980, 10707, 10707, 10707, 10707, 13763, 10707,   937,   939, 16652,
     984,   985, 10707, 10707,  5420,   931, -1555,    56, -1555,    65,
   10707,  6664, -1555, -1555, -1555, -1555, -1555,   138,   162,   112,
     123,  1176,  7286,  3247,  7597,  3569,   916, -1555, -1555,   189,
     916, -1555, 10707,  4191, -1555,  1061,   753,    92,  1012,  1011,
    1013,  6353, 10707, -1555, -1555, -1555, -1555, -1555, -1555, -1555,
   -1555, 11018, 11018, 11018, -1555, 11018, 11018, -1555, 11018, -1555,
   11018, -1555, -1555, -1555, -1555, -1555, -1555, -1555, 11018, 11018,
    1112, 11018, 11018, 11018, 11018, 11018, 11018, 11018, 11018, 11018,
   11018, 11018, 11018,   953,  1091,  1092,  1093, -1555, -1555, -1555,
   11329,  9463, -1555, -1555, 11640, 11640, 10707,   944, -1555, -1555,
     944, -1555,  9774,   944,  1039, 10085, -1555, -1555, -1555, -1555,
     279, -1555,   406, -1555, -1555, -1555, -1555, -1555, -1555,  1082,
    1083,   631,  1162, -1555, -1555, 16940,  1037,   716, 16652,  1032,
    1033,  1037,  1074,  1067,  1063, -1555, -1555, -1555,   307,   950,
    1103,   899, 16652,  1057, 10707,  1084, 16652, 16652, -1555,  1069,
    1019, -1555,  1020,   999,   842, -1555,  1022,  1023,   137, -1555,
     452,   504,  1098, -1555,    44, -1555, -1555,  1098, 16652,    40,
   16652,  1113,   507, -1555,  6353, -1555,   227, -1555, 13158,  1110,
    1166, 13158,  1074,  1116,   400, 16652, 10707,    92,   155,  1026,
   -1555,  1027,  1029,  1030,    41, -1555,   360,  1031, -1555,   243,
     245,  1065, -1555,  1035,  6353,  6353,   396, -1555,   523,   573,
     647, 10707,   303, -1555, -1555, 10707, 10707, -1555, 10707, 10707,
   10707, -1555, 10707, -1555, 10707, -1555, 16652,  1117, -1555,   370,
     403,   418, -1555, -1555, -1555,   423, -1555,   278, -1555, -1555,
    1068,  1070,  1071,  1072,  1073,    28,   956, -1555,   314,   533,
      -8,   113,  1126,   652,   990,  1009,  1006,    11, -1555,  1086,
   -1555, -1555,  1040,   247,  5731,   424, 12564,   931, -1555, -1555,
   -1555,  1016, -1555,   901,   829,  1196,   837, -1555, -1555,   126,
   -1555, -1555, -1555,   134, -1555,    88, -1555, -1555, -1555, -1555,
   -1555,  3880, -1555, -1555, -1555, 16652,  1062, 10707,  1115, -1555,
   -1555, -1555,   996, -1555, -1555, -1555, -1555, -1555, 11018, -1555,
   -1555, -1555,   118, -1555,   700,   700,   766,   780,   780,   780,
     780,   484,   484, -1555, -1555, 15788, 15788, 16652, 16652, -1555,
   -1555,   445, -1555, -1555,   202, -1555, -1555, -1555,   574, -1555,
   -1555,   576,   114, -1555, -1555,    33,    42,   819, -1555,   631,
   -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555,
    1037, -1555,  1106, 16076,  1097, 10707, -1555, -1555, -1555,  1141,
    1074,  1074,  1037, -1555,   911,  1074,   731, 16652,   168,   238,
    1212, -1555, -1555,   960,   689, -1555, -1555, -1555, -1555, -1555,
   -1555, -1555, -1555, -1555, -1555, -1555,   307,    30,  1017,   685,
   10707, -1555, 16652,  1148,   952,  1074, -1555, -1555, -1555, -1555,
    1095, 16652, -1555, 16652, -1555, 16364,  1118, 15788,  1134, 10707,
      87,  1108,    57,   701,  1010, -1555, -1555,   827,    40,  1141,
   15788,  1139,  1156,  1075,  1055,  1129,  1074,  1105,  1131,  1170,
    1074, 10707,   -37, -1555, -1555, -1555,  1119, -1555, -1555, -1555,
   -1555,  1150, 10707, 10707,  1123, -1555,  1171,  1173,  6353, -1555,
    1090,  1096,  1124, 16652, -1555, 16652, -1555, 10707,  1140,  1089,
   10707, -1555,  1155,   248,   305,   308,  1246, -1555,   511, -1555,
     116,  1133, -1555, -1555,  1255, -1555,   172, 10707, 10707, 10707,
     730, 10707, 10707, 10707, 10707, 10707, 10707, 10707, 10707, 10707,
   13763,  1167, 10707, 10707, -1555,  7908,   133,  1043, -1555,     6,
   -1555, 10707,   136,   415,    88,  7597,  3569,  7597,  1210, -1555,
   -1555, 10707,   794,  1184, -1555, 16652,  1185, -1555, -1555, 10707,
     118,   742,   465, -1555,  1014,   174,  1038,  1034, -1555, -1555,
     883, -1555,  1044,   699,  1142,  1144, 16076,  1147,  1149,  1151,
    1153,  1157, -1555,   721, -1555, -1555, -1555, -1555, -1555, -1555,
   -1555, -1555, -1555, -1555, -1555, -1555, -1555,  1160, -1555, -1555,
   -1555, -1555, 10707, -1555, -1555, -1555, -1555, -1555, -1555, -1555,
   -1555, -1555,   822, -1555,  1264,   887, -1555, -1555, -1555, -1555,
   -1555, -1555, -1555, -1555, -1555,  1041, -1555, -1555,  1266, -1555,
   -1555, -1555, -1555, -1555,   736,  1283, -1555,   852, -1555, -1555,
   -1555,   989,   364,  1001,   772,  1002,  1003,   918,  1149,  1151,
    1153, -1555,   721,   721, 11329,  1045,  1025, -1555,  1141,    30,
    1087,  1125,  6353,  1136,  1152,  1174,  1159,  1161, 16652, -1555,
     374, -1555, 16652, -1555, 10707,  1172, 10707,  1194, 10707,   178,
    1181, 10707,  1182, -1555,  1216,  1218, 10707, 16652,   975,  1260,
   -1555, -1555, -1555, -1555, -1555, -1555, 15788, -1555,  6353,  1074,
    1231, -1555, -1555, -1555,  1074,  1231, -1555, 10707,  1201,  6353,
   16652, -1555, -1555, 10707, 10707,   643, -1555,    45,   807, -1555,
   14924,   863, -1555,   866, -1555,  1165, -1555, -1555,  6353,  1163,
    1164, -1555, 10707, -1555, -1555, 10707,  1168,  1171,  1253, -1555,
    1222, -1555,   535, -1555, -1555,  1351, -1555, -1555,  6353, 16652,
   -1555,   554, -1555, -1555, -1555,  6353,  1169,  1127,  1128, -1555,
   -1555, -1555,  1130,  1138, -1555, -1555, -1555,  1262, -1555, -1555,
   -1555, -1555,  1143,   414, 16652,  1178, -1555,  1211,  1213,  1217,
    1215, -1555,   896,   728, 12564,  1043, -1555,  6042, 12564, -1555,
   -1555,  1196,   494, -1555, -1555, -1555,  1184, -1555,  1074, -1555,
     915, -1555,    86,  1268, -1555, 10707,   322,  1115,   475,  1188,
   -1555,   118,  1122, -1555, -1555,   622, -1555,   386,   241,  1145,
     118,   386, 11018, -1555,   412, -1555, -1555, -1555, -1555, -1555,
   -1555,   118,  1229,  1099,   950,   241, -1555, -1555,  1100,  1299,
   -1555, -1555, -1555, 14060,  1191,  1195,  1197,  1198,  1200,  1202,
    1203, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555,
   -1555, -1555, -1555,  1354,   277,  1359,   277,  1121,  1286, -1555,
   -1555,  1224, 16652,  1154, -1555, -1555, 11329, -1555,  1214, -1555,
   -1555, -1555, -1555, -1555, -1555, 10707,  1249, -1555, -1555, 10707,
   -1555,   521, -1555, 10707,  1250, 10707, -1555, 10707, 16652, 16652,
   -1555,   830, -1555, 10707, -1555,  1273,  1274,  1305,  1074,  1231,
   -1555, 10707,  1220, -1555, -1555, -1555,  1219, -1555,   369, 10707,
    6353,  1221,   379, -1555, 16652,   439, -1555, 15212,   488, -1555,
   15500,  1223, -1555, -1555,  1228, -1555, -1555, -1555, -1555, 10707,
     867,  1246, 16652,   661, -1555,  1232,  1246, 16652, -1555,  1233,
   -1555, 10707, 10707, 10707, 10707,  1102, 10707, 10707, -1555, 10707,
   10707, 10707, 10707,  7908,    13, -1555, -1555, -1555, -1555, -1555,
    1268, -1555, -1555, -1555,  1074, 10707, -1555,  1277, -1555, -1555,
   -1555, -1555,  1236, 11018, -1555, -1555, -1555, -1555, -1555,   104,
   11018, 11018,   675, -1555,  1038, -1555,   514, -1555,  1034,   118,
    1269, -1555, -1555,  1146, -1555, -1555, -1555, -1555,  1314,  1237,
   -1555,   588, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555,
     547,   547, -1555,   277, -1555, -1555,   606, -1555,  1386,   241,
    1327,  1238, 11329,   -22,  1177,  1259, -1555, -1555, 10707, -1555,
   10707,  1284, -1555, 10707, -1555, -1555, -1555,  1377, -1555, -1555,
    7908, 10707,  1074, -1555, -1555, -1555, 10707, 10707, -1555, -1555,
   -1555,  7908,  7908,  1339,  6353, 15788, 16652,   559, 16652, 10707,
   16652,   707,  7908, -1555,   553,    49,  1246, 16652, -1555,  1239,
    1246, -1555, -1555, -1555, -1555, -1555, 10707, -1555, -1555, -1555,
     315,   340,   353, 10707, -1555, -1555, -1555,  1328, 10707, -1555,
     780, 11018, 11018,   766,   726, -1555, -1555, -1555, -1555, -1555,
   -1555, 10707, -1555, 15788, -1555, 15788,  1343, -1555, -1555, -1555,
    1409, -1555, -1555, -1555,  1186,  1332, -1555, -1555,  1334, -1555,
     656, 16652,  1324,  1225, 16652, 11329, -1555, -1555, 10707, -1555,
    1335, -1555, -1555,  1231, -1555, -1555, 15788, -1555, -1555, -1555,
    1358, 10707,  1270, -1555,  1361,  7908, -1555, 16652,   697,   564,
   -1555,  1261,  1246, -1555,  1263, -1555,  1265,  1171,  1173,   482,
   -1555,  1328,   766,   766, 11018,   489, -1555, -1555, 15788, -1555,
   -1555,  1327, 11329, -1555,  1268,  1175, 16652,  1341,  1240,  1334,
   -1555, 16652,   717, 15788,  6353, 15788,  1271, -1555, -1555,  1368,
     698, -1555, -1555, -1555, -1555,  1285,   591, -1555, -1555, -1555,
    1272, -1555,  7908,   882, -1555, -1555,   766, -1555, -1555, -1555,
   -1555, -1555, 10707,  1179, 16652,  1348, -1555,  6353,   723, -1555,
   -1555,   725, 10707, -1555, -1555, -1555, -1555, -1555, -1555, -1555,
    1349, -1555,  1180,  1183, 16652, -1555, -1555, 10707,  7908, 16652,
    1187, 10707,  1189,  1289, 11329, -1555, 11329,  7908, -1555,  1278,
    1192, 16652,  1245,  1353, 16652,  1190, 11329, -1555
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       165,   466,   467,   468,   168,   168,   168,     0,   818,  1023,
     120,   122,   624,   910,   919,   859,   823,   821,   803,   911,
     914,   866,   827,   804,   805,     0,   920,   807,   917,   888,
     868,   843,   863,   864,   915,   912,   862,   809,   918,   810,
     811,   959,   971,   958,   860,   879,   873,   812,   861,   814,
     813,   960,   897,   898,   865,   840,   981,   982,   983,   984,
     985,   986,   987,   988,   989,   990,   991,  1005,  1012,   887,
     883,   874,   854,   802,     0,   882,   890,   899,  1006,   878,
     492,   855,   856,   913,  1007,  1013,   875,   892,     0,   498,
     455,   494,   885,   820,   876,   877,   906,   880,   896,   905,
    1011,  1014,   826,   867,   908,   493,   895,   901,   806,     0,
       0,     0,     0,   401,   893,   904,   909,   907,   886,   872,
     961,   870,   871,  1008,     0,   400,     0,  1009,  1015,   902,
     857,   881,  1010,   433,     0,   465,   903,   884,   891,   900,
     894,   962,   848,   853,   852,   851,   850,   849,   815,   869,
       0,   819,   916,   841,   950,   949,   951,   825,   824,   844,
     956,   808,   948,   953,   954,   945,   847,   889,   947,   957,
     955,   946,   845,   952,   966,   967,   964,   965,   963,   816,
     968,   969,   970,   936,   935,   922,   839,   832,   929,   925,
     842,   838,   937,   938,   828,   829,   822,   831,   934,   933,
     930,   926,   943,   944,   942,   932,   928,   921,   830,   941,
     940,   834,   836,   835,   927,   931,   923,   837,   924,   833,
     939,   992,   993,   994,   995,   996,   997,   973,   974,   972,
     978,   979,   980,   975,   976,   977,   846,   998,   999,  1000,
    1001,  1002,  1003,  1004,     0,     0,  1016,  1017,  1018,  1021,
    1020,  1019,  1022,   165,   165,     0,     2,   165,     9,    11,
      23,     0,    28,    31,    36,    37,    38,    39,    40,    41,
      42,    32,    58,    59,    33,    34,     0,    76,    79,    80,
      35,    81,    82,     0,   118,    83,    84,    85,    86,    18,
     162,   163,   164,   171,   174,   485,   175,     0,   176,   177,
     178,   179,   180,   181,   182,   185,     0,   211,   219,   214,
     246,   252,     0,   244,   245,   221,   215,   184,   216,   183,
     217,   220,   352,   354,   356,   366,   368,   372,   374,   377,
     382,   385,   388,   390,   392,   394,     0,   398,   405,   404,
     406,     0,   424,   407,   429,   432,   434,   437,   439,     0,
     444,   441,     0,   452,   462,   464,   438,   469,   476,   490,
     477,   478,   479,   482,   483,   480,   481,   505,   507,   508,
     509,   506,   554,   555,   556,   557,   558,   559,   560,   461,
     598,   590,   597,   596,   595,   592,   594,   591,   593,   491,
     484,   625,   626,    43,   222,   223,   225,   224,   226,   218,
     487,   488,   489,   486,   228,   231,   227,   229,   230,   463,
     801,   817,   910,   919,   917,   819,     0,   166,   167,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   126,   128,   129,     0,     0,
       0,     0,     0,     0,     0,     0,   256,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     274,   275,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   457,   460,   447,     0,     0,
     803,   827,   805,   858,   920,   807,   868,   809,   879,   812,
     814,   813,   897,  1005,  1012,   802,  1006,   856,  1007,  1013,
     880,  1011,  1014,   904,   961,  1008,  1009,  1015,  1010,   962,
     956,   948,   954,   945,   845,   966,   967,   964,   816,   968,
    1017,   453,   463,   801,   445,     0,   192,   446,   449,   803,
     804,   805,   809,   810,   811,   812,   802,   808,   495,     0,
     451,   450,   187,     0,     0,   211,     0,   807,   814,   813,
       0,   168,   776,   968,     0,   219,     0,   496,     0,   521,
       0,     0,   456,   799,     0,   800,   427,   428,     0,   459,
     458,   448,   431,     0,     0,   550,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   778,     0,   780,     0,
       0,   165,     3,     4,     1,    10,    12,     0,     0,     0,
       0,     6,   165,     0,   165,     0,     0,   119,   172,     0,
       0,   190,     0,     0,   199,     0,     0,     0,     0,     0,
       0,     0,     0,   204,   232,   251,   247,   253,   248,   250,
     249,     0,     0,     0,   417,     0,     0,   415,     0,   361,
       0,   416,   409,   414,   413,   412,   411,   410,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   403,   402,   399,
       0,     0,   425,   430,     0,     0,     0,   440,   473,   443,
     442,   454,     0,   470,     0,     0,   562,   564,   568,   570,
       0,   124,     0,   798,    47,    44,    45,    48,    49,     0,
       0,     0,     0,    50,    51,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   635,   636,   637,     0,   103,
     142,     0,     0,   112,     0,     0,     0,     0,   127,     0,
       0,   604,     0,     0,     0,   600,     0,     0,     0,   614,
       0,     0,   255,   257,     0,   234,   235,   254,     0,     0,
       0,   134,     0,   138,   168,   628,     0,    60,     0,    69,
       0,     0,     0,    61,     0,     0,     0,     0,     0,     0,
     605,     0,     0,     0,     0,   323,     0,     0,   603,     0,
       0,     0,   622,     0,     0,     0,     0,   608,     0,     0,
     194,     0,     0,   188,   186,     0,     0,   782,     0,     0,
       0,   495,     0,   777,     0,   497,   522,   521,   518,     0,
       0,     0,   552,   551,   426,     0,   549,     0,   648,   649,
     803,   805,   809,   812,   802,   789,     0,   599,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   654,     0,
     202,   203,     0,     0,     0,     0,     0,   207,   208,   779,
     781,     0,     5,    24,     0,    25,     0,     7,    29,     0,
      15,     8,    30,     0,    19,   910,    77,    16,    78,    20,
     193,     0,   191,   212,   213,     0,     0,     0,     0,   205,
     233,   292,   353,   355,   359,   365,   364,   363,     0,   360,
     357,   358,     0,   369,   376,   375,   373,   379,   380,   381,
     378,   383,   384,   387,   386,     0,     0,     0,     0,   408,
     422,     0,   435,   436,     0,   474,   471,   503,     0,   627,
     501,     0,     0,   121,   123,     0,     0,     0,   102,     0,
      92,    94,    95,    96,    97,    99,   100,   101,    93,    98,
      88,    89,     0,     0,   108,     0,   104,   106,   107,   114,
       0,     0,    87,    46,     0,     0,     0,     0,     0,     0,
       0,   726,   731,     0,     0,   727,   761,   714,   716,   717,
     718,   720,   722,   721,   719,   723,     0,     0,     0,     0,
       0,   111,     0,   144,     0,     0,   567,   561,   601,   602,
       0,     0,   618,     0,   615,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   236,   237,     0,   242,   140,
       0,     0,   135,     0,     0,     0,     0,     0,     0,    62,
       0,     0,     0,   273,   279,   276,     0,   607,   606,   613,
     621,     0,     0,     0,     0,   566,     0,     0,     0,   418,
       0,     0,     0,     0,   611,     0,   609,     0,   195,     0,
       0,   783,     0,     0,     0,     0,   521,   519,     0,   510,
       0,     0,   499,   500,     0,    13,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   200,     0,     0,     0,   662,     0,
     209,     0,     0,     0,     0,   165,     0,   165,     0,   173,
     243,     0,   307,   303,   305,     0,   293,   294,   362,     0,
       0,     0,     0,   692,   370,   665,   669,   671,   673,   675,
     678,   685,   686,   694,   920,   806,     0,   815,  1021,  1020,
    1019,  1022,   389,   573,   579,   580,   583,   629,   630,   584,
     585,   792,   793,   794,   588,   391,   393,   396,   589,   395,
     423,   475,     0,   472,   502,   125,    56,    57,    54,    55,
     131,   130,     0,    90,     0,     0,   109,   110,   115,    74,
      75,    52,    53,    73,   732,     0,   735,   762,     0,   725,
     724,   729,   728,   760,     0,     0,   737,     0,   733,   736,
     715,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   143,   146,   148,     0,     0,     0,   113,   116,     0,
       0,     0,   168,     0,     0,   622,     0,     0,     0,   259,
       0,   572,     0,   260,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   238,     0,     0,     0,     0,   286,     0,
     283,   288,   241,   141,   136,   139,     0,   189,     0,     0,
      71,    65,    68,    67,     0,    63,   277,     0,     0,   168,
       0,   321,   325,     0,     0,     0,   328,     0,     0,   334,
       0,     0,   341,     0,   345,     0,   420,   419,   168,     0,
       0,   196,     0,   198,   322,     0,     0,     0,     0,   522,
       0,   512,     0,   545,   542,     0,   546,   547,     0,     0,
     541,     0,   516,   544,   543,     0,     0,     0,     0,   641,
     642,   638,     0,     0,   646,   647,   643,   785,   786,   652,
     790,   650,     0,     0,     0,     0,   656,   807,   814,   813,
     968,   201,     0,     0,     0,   657,   658,     0,     0,   210,
     788,    26,     0,    17,    21,    22,   304,   316,     0,   317,
       0,   308,   309,   310,   311,     0,   296,     0,     0,     0,
     676,   689,     0,   367,   371,     0,   708,     0,     0,     0,
       0,     0,     0,   664,   666,   667,   703,   704,   705,   707,
     706,     0,     0,   680,   679,     0,   683,   687,   701,   699,
     698,   691,   695,     0,     0,     0,     0,     0,     0,     0,
       0,   576,   578,   577,   574,   397,   504,   133,   132,    91,
     105,   749,   730,     0,   754,     0,   754,   743,   738,   147,
     149,     0,     0,     0,   117,   145,     0,    27,     0,   619,
     620,   623,   616,   617,   258,     0,     0,   272,   264,     0,
     268,     0,   262,     0,     0,     0,   281,     0,     0,     0,
     240,   284,   287,     0,   137,     0,     0,    70,     0,    64,
     278,     0,     0,   324,   326,   331,     0,   329,     0,     0,
       0,     0,     0,   335,     0,     0,   349,     0,     0,   342,
       0,     0,   346,   421,     0,   612,   610,   197,   784,     0,
       0,   521,     0,     0,   553,     0,   521,     0,   517,     0,
      14,     0,     0,     0,     0,     0,     0,     0,   655,     0,
       0,     0,     0,     0,     0,   659,   663,   320,   318,   319,
     312,   313,   314,   306,     0,     0,   301,     0,   295,   693,
     684,   690,     0,     0,   763,   764,   774,   773,   772,     0,
       0,     0,     0,   765,   670,   771,     0,   668,   672,     0,
       0,   677,   681,     0,   702,   697,   700,   696,     0,     0,
     586,     0,   581,   634,   575,   796,   797,   795,   582,   750,
       0,     0,   748,   755,   756,   752,     0,   747,     0,   745,
       0,     0,     0,     0,     0,     0,   563,   261,     0,   270,
       0,     0,   266,     0,   269,   282,   290,   291,   285,   239,
       0,     0,     0,    66,   280,   569,     0,     0,   332,   336,
     330,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   565,     0,     0,   521,     0,   548,     0,
     521,   571,   639,   640,   644,   645,     0,   651,   791,   653,
       0,     0,     0,     0,   660,   315,   302,   297,     0,   688,
     775,     0,     0,   767,     0,   713,   712,   711,   710,   709,
     674,     0,   766,     0,   631,     0,     0,   759,   758,   757,
       0,   751,   744,   742,     0,   739,   740,   734,   150,   152,
     154,     0,     0,     0,     0,     0,   265,   263,     0,   271,
       0,   206,   351,    72,   327,   333,     0,   347,   343,   350,
       0,     0,     0,   337,     0,     0,   339,     0,   531,   525,
     520,     0,   521,   511,     0,   787,     0,     0,     0,     0,
     300,   298,   769,   768,     0,     0,   632,   587,     0,   753,
     746,     0,     0,   156,   155,     0,     0,     0,     0,   151,
     267,     0,     0,     0,     0,     0,     0,   539,   533,     0,
     532,   534,   540,   537,   527,     0,   526,   528,   538,   513,
       0,   514,     0,     0,   661,   299,   770,   682,   633,   741,
     153,   157,     0,     0,     0,     0,   289,     0,     0,   340,
     338,     0,     0,   524,   535,   536,   523,   529,   530,   515,
       0,   158,     0,     0,     0,   348,   344,     0,     0,     0,
       0,     0,     0,     0,     0,   160,     0,     0,   159,     0,
       0,     0,     0,     0,     0,     0,     0,   161
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1555, -1555,  -230,  -190, -1555,  1226,  1230, -1555,  1235,  -545,
   -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555,
    -985, -1555, -1555, -1555, -1555,  -241,  -592, -1555,   746,    -1,
   -1555, -1555, -1555, -1555, -1555,   288,   515, -1555, -1555,   -11,
    -131,  1058, -1555,  1047, -1555, -1555,  -638, -1555,   455, -1555,
     263, -1555,  -207,  -253, -1555,  -537, -1555,     5,    38,     9,
    -289,  -172, -1555,  -858, -1555, -1555,   218, -1555, -1555, -1555,
   -1555, -1555, -1555, -1555, -1555, -1555, -1555,   633,   -86,  1459,
       0, -1555, -1555, -1555, -1555,   473, -1555, -1555,  -311, -1555,
      23, -1555,  1046,  -931,  -724,  -699, -1555, -1555,   715, -1555,
   -1555,    35,   249, -1555, -1555, -1555,   127, -1514, -1555,   389,
     139, -1555, -1555,   143, -1304, -1555,   962,   236, -1555, -1555,
     232, -1007, -1555, -1555,   230, -1555, -1555, -1250, -1232, -1555,
     226, -1426, -1555, -1555,   869,   872, -1555,  -548,   850, -1555,
   -1555,  -654,   377,  -640,   372,   365, -1555, -1555, -1555,   594,
   -1555, -1555,  1199, -1555, -1555, -1555, -1555, -1555,  -871,  -315,
    -669, -1555,   -78, -1555, -1555, -1555, -1555, -1555, -1555, -1555,
      -7,  -819, -1555,  -535,   671,   323, -1555,  -406, -1555, -1555,
   -1555, -1555, -1555, -1555, -1555,   820, -1555, -1019, -1555,   215,
   -1555,   703,  -788, -1555, -1555, -1555, -1555, -1555,  -248,  -239,
   -1226, -1554, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555,
   -1555, -1555, -1555,  -762,  -875,  -169,  -864, -1555, -1555, -1555,
    -846, -1555, -1555, -1555, -1555, -1555, -1555, -1555,  1080,  1088,
    -133,   524,   355, -1555, -1555, -1555, -1555, -1555, -1555, -1555,
   -1555, -1555, -1555, -1555, -1555, -1555, -1555,   198, -1555, -1555,
     186, -1555,   190, -1048, -1555, -1555, -1555,   153,   144,   -23,
     416, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555, -1555,
   -1555, -1555, -1555, -1555,   154, -1555, -1555, -1555,   -17,   410,
     555, -1555, -1555, -1555, -1555, -1555,   345, -1555, -1555, -1478,
   -1555, -1555, -1555,  -534, -1555,   117, -1555,   -39, -1555, -1555,
   -1555, -1555, -1314, -1555,   164, -1555, -1555, -1555, -1555, -1555,
     965, -1555, -1555, -1555, -1555, -1555,  -925, -1555, -1555, -1555,
    -413,  -375,   246,   974, -1555
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   255,   633,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
    1270,   782,   273,   274,   275,   276,   277,   278,   960,   961,
     962,   279,   280,   281,   966,   967,   968,   282,   443,   283,
     284,   710,   285,   445,   446,   447,   462,   772,   773,   286,
    1221,   287,  1698,  1699,   288,   289,   290,   553,   291,   292,
     293,   294,   295,   775,   296,   297,   536,   298,   299,   300,
     301,   302,   303,   643,   304,   305,   867,   868,   306,   307,
     565,   309,   644,   460,  1027,  1028,   310,   645,   311,   647,
     566,   313,   762,   763,  1258,   469,   314,   470,   471,   769,
    1259,  1260,  1261,   648,   649,  1126,  1127,  1546,   650,  1123,
    1124,  1371,  1372,  1373,  1374,   315,   794,   795,   316,  1285,
    1286,  1488,   317,  1288,  1289,   318,   319,  1291,  1292,  1293,
    1294,  1495,   320,   321,   322,   323,   908,   324,   325,  1383,
     326,   327,   328,   329,   330,   331,   332,   333,   334,  1166,
     335,   336,   337,   338,   668,   669,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   703,   698,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   938,   366,   367,   368,  1321,
     827,   828,   829,  1730,  1775,  1776,  1769,  1770,  1777,  1771,
    1322,  1323,   369,   370,  1324,   371,   372,   373,   374,   375,
     376,   377,   378,  1022,  1496,  1424,  1153,  1581,  1154,  1167,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     801,  1234,   389,   390,   391,   392,  1156,  1157,  1158,  1159,
     393,   394,   395,   396,   397,   398,   857,   858,   399,  1355,
    1356,  1664,  1109,  1134,  1393,  1394,  1135,  1136,  1137,  1138,
    1139,  1403,  1571,  1572,  1140,  1406,  1141,  1552,  1142,  1143,
    1411,  1412,  1577,  1575,  1395,  1396,  1397,  1398,  1678,   739,
     987,   988,   989,   990,   991,   992,  1208,  1601,  1695,  1209,
    1599,  1693,   993,  1436,  1596,  1592,  1593,  1594,   994,   995,
    1399,  1407,  1562,  1400,  1558,  1384,   400,   401,   402,   403,
     556,   404,   405,   406,   407,   408,  1160,  1161,  1162,  1163,
    1271,   574,   409,   410,   411
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int xquery_parser::yytable_ninf_ = -859;
  const short int
  xquery_parser::yytable_[] =
  {
       308,   646,   444,   628,   308,   308,   308,   308,   605,   416,
     419,   420,   714,   418,   418,   418,   422,   711,   711,   620,
     916,   929,  1042,   312,   564,   568,   692,   312,   312,   312,
     312,   623,   886,   888,  1054,   917,   918,   919,   920,  1078,
    1020,  1132,   417,   417,   417,   421,   625,  1108,  1068,  1287,
    1152,  1165,   779,   783,   845,  1275,   582,   621,  1510,  1499,
     853,  1320,   734,   612,   613,  1021,   621,   531,  1541,  1542,
    1211,  1637,  1223,   749,  1641,  1212,   753,   878,   882,  1155,
    1155,  1016,  1379,   947,  1239,   880,   884,   887,   889,  1181,
    1213,  1573,  1214,   754,  1247,  1518,  1024,  1701,   791,  1185,
     713,  1215,    10,    11,   621,   904,  1277,   905,   906,   308,
     907,   621,   909,   621,   815,    10,    11,  1155,   554,  1101,
     910,   911,  1696,   429,   621,  1313,  1314,   621,  1216,   628,
     594,   713,   312,   628,   621,   621,   429,   621,   621,  1017,
     832,  1018,  1241,  1728,    12,   430,  1489,   417,    12,  1051,
     432,  1222,   627,  1740,  1018,  1264,   621,  1671,   607,   609,
    1357,  -169,   621,   432,   632,    10,    11,  1663,   433,   770,
     691,  1155,   621,   632,  1772,  1778,   425,   426,   487,   427,
     428,   584,  1176,   696,  1155,   702,   429,   464,   745,  -170,
     621,  1178,  1019,  1368,   126,   430,   431,   465,   621,  1177,
     434,   435,  1118,   621,  1702,  1248,   629,  1188,  1179,   488,
     423,   467,   489,   432,  1370,   780,  1772,  1358,   433,   595,
    1315,   816,  1778,   466,  1358,    80,  1094,  1785,   621,    80,
    1052,   778,  1490,  1729,  1672,  1244,  1665,   468,   771,    91,
    1316,   632,  1317,    91,   621,   632,   621,  1102,   621,   621,
     434,   435,   436,   308,   308,   646,  1217,   308,  1025,  1132,
    1132,  1252,   781,   632,   105,   628,   693,  1263,   105,   632,
    1318,  1385,  1129,  1789,   112,  1130,   312,   312,  1499,   632,
     312,  1492,  1415,   886,   888,  1694,  1703,  1518,  1310,  1479,
    1762,   124,   308,  1320,   622,  1026,   126,   632,  1249,   437,
    1155,   624,  1320,   873,  1223,   632,   621,  1454,   833,   621,
     632,  1182,  1319,   627,   875,   312,   621,  1115,   468,   973,
     532,  1245,  1010,  1250,  1428,  1117,  1463,  1361,   878,   882,
     150,   468,   629,  1551,   548,   632,   629,  1798,  1559,  1801,
    1046,   621,   699,  1278,  1386,   701,  -169,  1095,  1218,  1219,
    1220,   632,   899,   632,   621,   632,   632,   823,   569,   438,
    1128,   468,   976,   746,   977,   585,   468,   758,   869,  1039,
     575,   747,   578,   587,  -170,   588,   440,   776,  1131,   870,
     424,   879,   883,  1222,   441,   825,   788,   942,  1171,   874,
     876,  1474,   442,   799,   800,   753,  1753,   621,   630,   891,
     439,   481,   806,  1035,   621,  1327,  1038,  1328,   978,  1086,
    1084,  1051,   754,   632,  1590,  1034,   632,  1017,   308,   621,
    1155,   872,   308,   632,   621,   621,   440,  1387,  1388,  1544,
    1389,  1056,  1199,  1057,   441,  1105,  1306,  1390,   591,   451,
     592,   312,   442,  1200,  1155,   312,   621,  1391,   632,   308,
    1791,   308,   468,   425,   426,  1017,   427,   428,   422,  1392,
     422,   632,   589,    10,    11,  1545,  1444,   943,   629,  1085,
    1489,  1018,   312,   431,   312,   816,   621,   308,   482,  1591,
    1489,   631,   308,   621,   830,   831,   422,   750,  1783,   752,
     621,   422,  1070,  1307,  1320,  1017,  1308,   835,  1560,  1561,
     312,  1079,  1201,  1736,   632,   312,  1133,   596,  1053,  1385,
    1132,   632,   597,  1202,   942,   797,  1456,   863,   865,  1132,
     803,   452,  1455,   886,   888,   886,   632,   593,  1737,  1362,
    1132,   632,   632,  1087,  1088,  1108,  1175,   755,  1580,  1536,
     729,  1738,   730,  1041,  1313,  1314,   483,   484,  1089,   626,
    1464,  1499,   817,   632,   308,  1441,  1627,  1189,  1190,   979,
    1011,   308,  1193,  1313,  1314,  1343,  1632,  1155,  1080,   696,
     418,   702,   980,  1313,   981,   628,   437,   312,  1363,  1364,
    1365,  1062,  1386,   632,   312,   982,   983,   984,  1081,   985,
     632,   986,  1231,  1773,   944,   532,   598,   632,   532,   417,
    1313,   732,  1119,  1082,   308,   931,   444,  1638,  1083,  1107,
     934,   308,  1013,   864,  1547,  1031,   932,   933,  1018,  1381,
    1773,   681,   308,   308,   308,   308,  1634,   312,  1090,   635,
    1170,  1063,  1112,   636,   312,   682,   438,  1713,   637,  1315,
    1012,   308,  1311,   126,  1433,   312,   312,   312,   312,  1116,
    1635,  1155,  1527,   876,  1155,  1556,   638,   448,  1315,  1316,
    1549,  1317,  1557,   733,   312,  1387,  1388,  1784,  1389,  1610,
    1313,  1314,  1727,   672,  1787,  1639,   722,   439,  1316,   726,
    1317,  1065,  1172,   575,  1172,  1391,   740,   741,  1316,  1318,
    1317,   673,  1014,   112,   575,  1032,  1685,  1392,  1132,  1774,
     761,   764,  1767,  1767,  1435,   764,  1313,  1313,  1318,  1312,
     124,  1064,   112,   784,  1690,  1316,   476,  1317,  1318,   575,
     792,   793,   796,  1645,  1133,  1133,  1807,   802,  1649,   124,
    1492,  1512,  1073,  1074,  1075,   809,   865,  1611,  1566,   635,
    1639,   672,  1017,   636,  1284,  1318,  1721,  1097,   637,   150,
    1517,  1017,  1091,  1092,   455,   639,   456,  1486,   640,   673,
    1719,  1066,  1173,  1368,  1174,  1315,   638,  1093,   150,   886,
    1635,   635,    12,   641,   308,   636,  1686,  1605,  1106,  1033,
     637,   810,   674,   418,  1675,  1316,  1205,  1317,   461,  1155,
    1067,  1676,   463,   723,  1691,   796,  1017,   312,   638,   642,
     729,  1677,   730,  1206,   308,   308,   821,   696,  1746,   702,
    1747,   963,   417,   422,   422,  1318,  1351,   692,   675,   112,
     457,  1316,  1316,  1317,  1317,   458,   724,   312,   312,   485,
     881,  1768,  1804,  1433,   731,   846,   124,  1155,   881,  1155,
    1554,   846,  1060,  1061,   890,   859,  1207,   676,   892,  1251,
    1434,  1318,  1318,    80,   964,   715,  1477,  1647,  1731,   965,
     677,   732,  1734,  1113,   308,   639,  1421,    91,   640,   716,
    1155,  1114,   459,  1788,   444,   150,   891,  1555,  1233,   618,
    1236,  1254,   876,   824,  1254,   672,  1255,   312,   486,  1255,
    1367,   308,   105,  1435,  1725,   678,  1129,   639,  1422,  1130,
     640,  1368,  1155,   673,  1797,  1256,  1673,  1674,  1284,   642,
    1817,  1369,  1818,  1670,   312,  1533,  1423,  1155,  1635,  1155,
     126,  1491,  1370,   733,  1018,   672,  1744,  1018,  1635,   474,
    1299,   653,  1300,  1700,  1635,   617,  1635,  1359,  1754,   654,
     655,   642,   656,   673,  1780,  1675,  1257,  1408,  1409,  1205,
     657,   618,  1676,   719,   658,  1537,   659,  1180,   717,  1183,
    1427,   660,  1677,  1332,  1497,  1333,  1206,  1500,  1497,   720,
    1410,  1183,   718,   774,   969,  1133,   774,  1498,   661,  1475,
    1501,  1644,   679,  1497,  1133,  1225,   449,   453,   999,   450,
     454,   680,  1003,  1004,  1226,  1133,  1810,   472,   477,   475,
     473,   478,   662,   663,   664,   665,   666,   667,   743,  1194,
    1195,  1196,   479,   744,  1023,  1197,  1029,  1742,  1743,   697,
     935,   480,   700,   935,   575,   964,   935,   575,   534,  1254,
     965,  1043,   694,   695,  1255,   535,  1700,   735,   736,   737,
    1191,  1192,   646,  1378,  1538,  1539,   923,   924,   533,   914,
     915,   921,   922,  1439,  1440,   537,  1687,  1688,   308,   538,
     549,   550,   533,   551,   570,  1623,   571,   422,   572,   579,
     580,   581,  1076,   583,   586,   590,   599,   600,   601,   603,
     604,   312,   602,  1700,   610,   614,   533,   634,   651,   652,
    1786,   670,   671,   683,   684,   685,  1295,   686,   533,   696,
     533,   690,   704,   444,   713,  1352,   705,   725,   706,   707,
     708,   727,   532,   709,   728,   308,   308,   308,   950,   951,
     952,   953,   954,   955,   956,   957,   958,   959,  1353,   742,
     738,  1666,   765,   766,   768,   774,   777,   785,   312,   312,
     312,  1120,   751,   786,   787,   804,   450,   798,   811,   813,
     815,   805,   822,   826,   834,  1828,   454,  1829,   473,   478,
     489,   818,   837,  1133,   819,   820,   836,  1837,   847,   855,
     856,  1164,  1164,  1168,  1168,   860,   861,   866,   605,   877,
     895,   896,   897,   912,   898,   925,   926,   927,   928,   939,
     945,   946,   948,   970,   971,   974,   975,   996,   997,   998,
    1000,  1629,  1005,  1002,  1006,  1007,  1015,  1036,  1030,  1164,
    1008,  1009,  1037,  1040,  1047,  1048,  1055,  1049,  1050,  1058,
    1059,  1096,   449,  1198,   453,   472,   477,   488,  1098,  1103,
    1114,  1104,   308,  1121,  1125,  1099,  1017,  1448,  1100,  1184,
     965,   418,  1203,  1229,   899,  1224,  1240,  1204,  1228,  1232,
    1111,  1266,  1230,  1242,  1268,   312,  1246,  1235,   770,  1235,
    1267,   764,  1269,  1164,  1273,  1253,  1272,  1274,   308,  1280,
     417,  1283,  1284,  1279,  1290,  1296,  1164,  1305,  1298,   308,
    1303,  1297,  1309,  1302,  1482,  1326,  1344,  1325,   418,  1354,
     731,   312,  1375,  1377,    12,  1402,  1432,  1401,   308,  1413,
    1382,  1414,   312,  1504,  1416,  1425,  1417,   418,  1418,   802,
    1419,   802,  1405,  1437,  1420,  1446,  1447,   417,   308,  1451,
    1459,   312,  1461,   533,  1449,   308,   533,   422,  1431,  1465,
    1467,  1711,  1443,  1442,   422,  1468,   417,  1469,  1473,  1478,
    1450,   312,  1715,  1629,  1481,  1717,   846,  1452,   312,  1453,
    1503,  1505,  1506,  1726,  1497,  1511,  1515,  1352,  1514,  1525,
    1520,  1521,  1522,  1519,  1523,  1529,   864,  1509,  1530,  1357,
    1531,  1376,  1524,  1553,  1532,  1368,  1550,  1569,  1576,  1582,
    1353,  1526,  1570,  1583,  1589,  1584,  1585,  1574,  1586,  1595,
    1587,  1588,  1164,  1598,  1600,  1602,  1563,  1608,  1613,  1606,
    1620,  1621,  1622,   721,   533,  1625,  1626,   533,  1631,  1683,
    1642,   533,  1604,  1643,   533,   533,  1692,  1648,  1651,  1656,
    1668,  1669,   533,  1681,  1205,  1684,  1697,  1682,   533,   533,
    1705,  1710,  1708,   533,  1716,  1544,  1717,  1733,  1748,  1749,
    1751,   533,  1752,  1756,  1660,  1661,  1662,   533,   533,   533,
     533,  1757,  1750,  1763,  1761,   533,  1765,  1764,  1802,  1779,
    1794,  1781,  1803,   533,  1782,  1704,  1795,  1814,  1819,  1806,
    1809,  1833,  1834,  1430,  1820,  1799,  1827,   972,  1830,  1186,
    1831,  1792,   712,   615,   764,  1812,  1265,   616,  1457,  1821,
     308,   748,  1445,  1475,  1824,   619,  1826,  1836,  1759,  1790,
    1110,  1262,  1045,  1471,  1548,   767,  1618,  1472,  1815,   533,
    1366,   812,  1164,   312,  1543,  1540,  1483,  1487,  1493,  1502,
     902,   913,  1169,   533,   903,   941,   796,  1513,  1808,  1815,
    1077,  1805,   756,  1352,   533,   689,  1164,  1237,  1799,  1429,
     757,  1535,  1528,  1564,  1534,  1568,  1680,  1380,  1567,  1679,
    1404,  1210,  1438,  1597,  1689,  1565,  1353,     0,   851,     0,
       0,     0,     0,     0,     0,  1516,     0,     0,   555,     0,
       0,     0,     0,   533,     0,     0,     0,  1739,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     859,     0,     0,     0,     0,  1745,     0,     0,     0,     0,
     532,     0,     0,     0,   532,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1352,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1352,  1352,     0,   308,     0,     0,     0,     0,     0,
       0,     0,  1352,  1353,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1353,  1353,     0,   312,     0,  1164,
       0,     0,     0,     0,     0,  1353,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1603,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   949,
       0,     0,   533,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1616,  1617,   533,     0,     0,     0,
     533,   533,     0,     0,     0,  1352,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1633,     0,   533,  1164,   533,     0,  1164,     0,  1353,     0,
       0,     0,   533,     0,     0,   533,     0,     0,  1646,   533,
       0,     0,     0,  1650,   308,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1352,     0,     0,     0,     0,   312,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   308,     0,     0,
     533,     0,     0,     0,     0,  1353,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1352,     0,
     312,     0,     0,     0,     0,     0,     0,  1352,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     533,  1353,     0,     0,     0,     0,     0,     0,     0,     0,
    1353,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   533,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1164,  1720,     0,  1722,     0,  1724,     0,     0,     0,
       0,     0,     0,  1732,     0,     0,     0,     0,     0,   533,
     533,   533,   533,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1164,
       0,  1164,     0,     0,     0,     0,     0,   533,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1755,     0,     0,
    1758,   533,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1164,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1766,     0,     0,   533,     0,     0,     0,
       0,     0,     0,     0,     0,   533,     0,   533,     0,   533,
       0,   533,     0,     0,  1164,     0,     0,     0,     0,     0,
       0,     0,  1793,     0,   533,     0,     0,  1796,     0,  1164,
       0,  1164,     0,     0,     0,     0,     0,     0,     0,     0,
     555,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   533,     0,   533,
    1813,     0,     0,     0,     0,     0,   838,   839,     0,     0,
     848,   849,   850,   852,     0,   854,     0,     0,     0,     0,
    1822,   862,     0,     0,     0,  1823,     0,     0,     0,   871,
       0,     0,     0,     0,     0,     0,     0,  1832,     0,     0,
    1835,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   893,   894,     0,     0,     0,     0,     0,     0,   533,
     900,   901,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     533,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   937,     0,     0,   937,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1001,     0,     0,     0,     0,     0,     0,
       0,     0,   533,     0,     0,     0,   533,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   533,     0,     0,     0,     0,     0,     0,     0,     0,
     533,     0,     0,     0,     0,  1044,     0,     0,     0,     0,
       0,     0,     0,     0,   533,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   533,     0,     0,     0,     0,     0,
    1069,     0,     0,     0,  1071,  1072,     0,     0,     0,     0,
       0,     0,     0,   900,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   533,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   533,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   533,     0,
       0,     0,   533,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     894,     0,     0,     0,     0,     0,  1122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   533,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   533,     0,     0,     0,
       0,     0,     0,     0,  1187,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   533,   533,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1227,
       0,     0,     0,     0,     0,     0,     0,     0,   533,     0,
       0,   533,     0,     0,   533,     0,     0,     0,  1243,     0,
       0,     0,     0,     0,     0,     0,   533,     0,     0,     0,
       0,   533,     0,     0,     0,     0,     0,     0,     0,     0,
    1276,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1281,  1282,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1301,     0,     0,  1304,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1329,  1330,  1331,     0,
    1334,  1335,  1336,  1337,  1338,  1339,  1340,  1341,  1342,     0,
       0,  1345,  1346,     0,     0,     0,     0,     0,     0,     0,
    1360,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   533,
     533,     0,   533,     0,   533,     0,     0,     0,     0,     0,
       0,   533,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1426,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   533,     0,   533,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   533,     0,     0,   533,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     533,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   533,     0,  1458,     0,  1460,     0,  1462,     0,     0,
    1466,     0,     0,     0,     0,  1470,     0,     0,     0,     0,
       0,     0,   533,     0,     0,     0,     0,  1476,     0,     0,
     533,     0,     0,     0,     0,   533,  1480,   533,     0,   533,
       0,     0,  1484,  1485,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1507,     0,     0,  1508,     0,     0,     0,   533,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   533,     0,
       0,     0,     0,   533,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   533,     0,     0,   533,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1607,     0,     0,     0,  1609,     0,
       0,     0,  1612,     0,  1614,     0,  1615,     0,     0,     0,
       0,     0,  1619,     0,     0,     0,     0,     0,     0,     0,
    1624,     0,     0,     0,     0,     0,     0,     0,  1628,  1630,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1476,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1652,  1653,  1654,  1655,     0,  1657,  1658,     0,  1659,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1667,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1706,     0,  1707,
       0,     0,  1709,     0,     0,     0,     0,     0,     0,     0,
    1712,     0,     0,     0,     0,  1714,  1630,     0,     0,     0,
       0,     0,     0,  1718,     0,     0,     0,     0,  1723,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1735,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1741,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1760,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1718,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1800,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -165,   881,     0,
       0,  1811,     0,     0,     0,     0,  1816,     0,     1,     2,
       0,  1800,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,    11,  1816,    12,     0,     0,
    1825,    13,   413,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,     0,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,     0,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,    70,    71,    72,    73,    74,     0,    75,    76,
      77,     0,     0,    78,    79,     0,     0,     0,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,     0,
       0,     0,    91,     0,    92,    93,    94,    95,     0,    96,
       0,     0,     0,    97,    98,    99,   100,   101,     0,     0,
       0,     0,     0,     0,   102,   103,   104,   105,   106,   107,
     108,   109,   110,     0,   111,   112,   113,   114,   115,     0,
       0,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,     0,   124,     0,   125,   126,     0,     0,   127,   128,
     129,     0,     0,     0,   130,     0,   131,   132,     0,   133,
     134,     0,   135,     0,   136,     0,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,     0,     0,   148,
     149,   150,     0,   415,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,     0,   194,   195,   196,
       0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,     0,
     245,     0,   246,   247,   248,   249,   250,   251,   252,  -165,
     881,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,    11,     0,    12,
       0,     0,     0,   885,   413,     0,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   414,
      29,    30,    31,    32,     0,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,     0,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,     0,    70,    71,    72,    73,    74,     0,
      75,    76,    77,     0,     0,    78,    79,     0,     0,     0,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,     0,     0,     0,    91,     0,    92,    93,    94,    95,
       0,    96,     0,     0,     0,    97,    98,    99,   100,   101,
       0,     0,     0,     0,     0,     0,   102,   103,   104,   105,
     106,   107,   108,   109,   110,     0,   111,   112,   113,   114,
     115,     0,     0,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   123,     0,   124,     0,   125,   126,     0,     0,
     127,   128,   129,     0,     0,     0,   130,     0,   131,   132,
       0,   133,   134,     0,   135,     0,   136,     0,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,     0,
       0,   148,   149,   150,     0,   415,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,     0,   194,
     195,   196,     0,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   881,   245,     0,   246,   247,   248,   249,   250,   251,
     252,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,    11,     0,
      12,     0,     0,     0,   412,   413,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
     414,    29,    30,    31,    32,     0,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,     0,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,    70,    71,    72,    73,    74,
       0,    75,    76,    77,     0,     0,    78,    79,     0,     0,
       0,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,     0,     0,     0,    91,     0,    92,    93,    94,
      95,     0,    96,     0,     0,     0,    97,    98,    99,   100,
     101,     0,     0,     0,     0,     0,     0,   102,   103,   104,
     105,   106,   107,   108,   109,   110,     0,   111,   112,   113,
     114,   115,     0,     0,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,     0,   124,     0,   125,   126,     0,
       0,   127,   128,   129,     0,     0,     0,   130,     0,   131,
     132,     0,   133,   134,     0,   135,     0,   136,     0,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
       0,     0,   148,   149,   150,     0,   415,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,     0,
     194,   195,   196,     0,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   881,   245,     0,   246,   247,   248,   249,   250,
     251,   252,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,     0,     0,
       0,    12,     0,     0,     0,   412,   413,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
     557,   414,    29,    30,    31,    32,     0,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
       0,    46,    47,    48,   558,   559,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,    70,    71,    72,    73,
      74,     0,    75,    76,    77,     0,     0,    78,    79,     0,
       0,     0,    80,    81,   507,    83,    84,    85,    86,    87,
     560,    89,    90,     0,     0,     0,    91,     0,    92,    93,
      94,    95,     0,    96,     0,     0,     0,    97,    98,    99,
     100,   101,     0,     0,     0,     0,     0,     0,   102,   103,
     104,   105,   106,   107,   108,   561,   110,     0,   111,   112,
     113,   114,   115,     0,     0,     0,     0,   116,   117,   118,
     119,   120,   121,   122,   123,     0,   124,     0,   125,   126,
       0,     0,   127,   128,   129,     0,     0,     0,   130,     0,
     131,   132,     0,   133,   134,     0,   135,     0,   136,     0,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,     0,     0,   148,   149,   150,     0,   415,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     525,   526,   527,   177,   178,   528,   563,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
       0,   194,   195,   196,     0,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,     0,   245,     0,   246,   247,   248,   249,
     250,   251,   252,  -858,   455,     0,   456,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -858,     0,     0,     0,
    -858,     0,     0,     0,  -858,  -858,     0,     0,     0,  -858,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     457,     0,     0,  -858,     0,   458,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -858,     0,  -858,  -858,
    -858,     0,     0,  -858,  -858,  -858,  -858,     0,     0,     0,
    -858,  -858,     0,     0,     0,     0,     0,  -858,     0,     0,
    -858,  -858,   459,     0,     0,  -858,     0,     0,     0,     0,
    -858,  -858,     0,     0,     0,     0,  -858,     0,     0,     0,
    -858,     0,     0,     0,  -858,  -858,     0,  -858,     0,  -858,
    -858,     0,     0,     0,  -858,  -858,     0,     0,  -858,  -858,
    -858,  -858,  -858,  -858,     0,     0,  -858,     0,     0,     0,
       0,  -858,  -858,     0,     0,  -858,     0,     0,     0,     0,
    -858,     0,     0,  -858,     0,     0,     0,     0,  -858,  -858,
    -858,  -858,  -858,     0,  -858,  -858,  -858,  -858,  -858,     0,
       0,     0,     0,  -858,  -858,  -858,     0,  -858,  -858,  -858,
    -858,  -858,  -858,     0,  -858,     0,  -858,     0,     0,     0,
       0,  -858,  -858,  -858,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -858,     0,  -858,
       0,  -858,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -858,     0,     0,     0,     0,  -858,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,     0,    12,  -858,     0,  -858,    13,    14,
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,     0,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,     0,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,     0,    70,
      71,    72,    73,    74,     0,    75,    76,    77,     0,     0,
      78,    79,     0,     0,     0,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,     0,     0,     0,    91,
       0,    92,    93,    94,    95,     0,    96,     0,     0,     0,
      97,    98,    99,   100,   101,     0,     0,     0,     0,     0,
       0,   102,   103,   104,   105,   106,   107,   108,   109,   110,
       0,   111,   112,   113,   114,   115,     0,     0,     0,     0,
     116,   117,   118,   119,   120,   121,   122,   123,     0,   124,
       0,   125,   126,     0,     0,   127,   128,   129,     0,     0,
       0,   130,     0,   131,   132,     0,   133,   134,     0,   135,
       0,   136,     0,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,     0,     0,   148,   149,   150,     0,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,     0,   194,   195,   196,     0,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,     0,   245,     0,   246,
     247,   248,   249,   250,   251,   252,   253,   254,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,    11,     0,    12,     0,     0,
       0,    13,    14,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,     0,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,     0,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,    70,    71,    72,    73,    74,     0,    75,    76,
      77,     0,     0,    78,    79,     0,     0,     0,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,     0,
       0,     0,    91,     0,    92,    93,    94,    95,     0,    96,
       0,     0,     0,    97,    98,    99,   100,   101,     0,     0,
       0,     0,     0,     0,   102,   103,   104,   105,   106,   107,
     108,   109,   110,     0,   111,   112,   113,   114,   115,     0,
       0,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,     0,   124,     0,   125,   126,     0,     0,   127,   128,
     129,     0,     0,     0,   130,     0,   131,   132,     0,   133,
     134,     0,   135,     0,   136,     0,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,     0,     0,   148,
     149,   150,     0,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,     0,   194,   195,   196,
       0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,     0,
     245,     0,   246,   247,   248,   249,   250,   251,   252,     0,
     611,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,    11,     0,
      12,     0,     0,     0,   412,   413,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
     414,    29,    30,    31,    32,     0,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,     0,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,    70,    71,    72,    73,    74,
       0,    75,    76,    77,     0,     0,    78,    79,     0,     0,
       0,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,     0,     0,     0,    91,     0,    92,    93,    94,
      95,     0,    96,     0,     0,     0,    97,    98,    99,   100,
     101,     0,     0,     0,     0,     0,     0,   102,   103,   104,
     105,   106,   107,   108,   109,   110,     0,   111,   112,   113,
     114,   115,     0,     0,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,     0,   124,     0,   125,   126,     0,
       0,   127,   128,   129,     0,   552,     0,   130,     0,   131,
     132,     0,   133,   134,     0,   135,     0,   136,     0,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
       0,     0,   148,   149,   150,     0,   415,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,     0,
     194,   195,   196,     0,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,     0,   245,     0,   246,   247,   248,   249,   250,
     251,   252,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
       0,    12,     0,     0,     0,   412,   413,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,   414,    29,    30,    31,    32,     0,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
       0,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,    70,    71,    72,    73,
      74,     0,    75,    76,    77,     0,     0,    78,    79,     0,
       0,     0,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     0,     0,     0,    91,     0,    92,    93,
      94,    95,     0,    96,     0,     0,     0,    97,    98,    99,
     100,   101,     0,     0,     0,     0,     0,     0,   102,   103,
     104,   105,   106,   107,   108,   109,   110,     0,   111,   112,
     113,   114,   115,     0,     0,     0,     0,   116,   117,   118,
     119,   120,   121,   122,   123,     0,   124,     0,   125,   126,
       0,     0,   127,   128,   129,     0,   814,     0,   130,     0,
     131,   132,     0,   133,   134,     0,   135,     0,   136,     0,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,     0,     0,   148,   149,   150,     0,   415,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
       0,   194,   195,   196,     0,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,     0,   245,     0,   246,   247,   248,   249,
     250,   251,   252,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
      11,     0,    12,     0,     0,     0,   412,   413,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,  1347,   414,    29,    30,    31,    32,     0,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,     0,    46,    47,    48,  1348,  1349,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,    70,    71,    72,
      73,    74,     0,    75,    76,    77,     0,     0,    78,    79,
       0,     0,     0,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,     0,     0,     0,    91,     0,    92,
      93,    94,    95,     0,    96,     0,     0,     0,    97,    98,
      99,   100,   101,     0,     0,     0,     0,     0,     0,   102,
     103,   104,   105,   106,   107,   108,   109,   110,     0,   111,
     112,   113,   114,   115,     0,     0,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   123,     0,   124,     0,   125,
     126,     0,     0,   127,   128,   129,     0,   552,     0,   130,
       0,   131,   132,     0,   133,   134,     0,   135,     0,   136,
       0,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,     0,     0,   148,   149,   150,     0,   415,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,  1350,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,     0,   194,   195,   196,     0,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,     0,   245,     0,   246,   247,   248,
     249,   250,   251,   252,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,     0,    12,     0,     0,     0,   412,   413,     0,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,   414,    29,    30,    31,    32,     0,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,     0,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     0,    70,    71,
      72,    73,    74,     0,    75,    76,    77,     0,     0,    78,
      79,     0,     0,     0,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,     0,     0,     0,    91,     0,
      92,    93,    94,    95,     0,    96,     0,     0,     0,    97,
      98,    99,   100,   101,     0,     0,     0,     0,     0,     0,
     102,   103,   104,   105,   106,   107,   108,   109,   110,     0,
     111,   112,   113,   114,   115,     0,     0,     0,     0,   116,
     117,   118,   119,   120,   121,   122,   123,     0,   124,     0,
     125,   126,     0,     0,   127,   128,   129,     0,     0,     0,
     130,     0,   131,   132,     0,   133,   134,     0,   135,     0,
     136,     0,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,     0,     0,   148,   149,   150,     0,   415,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,     0,   194,   195,   196,     0,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,     0,   245,     0,   246,   247,
     248,   249,   250,   251,   252,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,     0,    12,     0,     0,     0,    13,    14,
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,     0,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,     0,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,     0,    70,
      71,    72,    73,    74,     0,    75,    76,    77,     0,     0,
      78,    79,     0,     0,     0,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,     0,     0,     0,    91,
       0,    92,    93,    94,    95,     0,    96,     0,     0,     0,
      97,    98,    99,   100,   101,     0,     0,     0,     0,     0,
       0,   102,   103,   104,   105,   106,   107,   108,   109,   110,
       0,   111,   112,   113,   114,   115,     0,     0,     0,     0,
     116,   117,   118,   119,   120,   121,   122,   123,     0,   124,
       0,   125,   126,     0,     0,   127,   128,   129,     0,     0,
       0,   130,     0,   131,   132,     0,   133,   134,     0,   135,
       0,   136,     0,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,     0,     0,   148,   149,   150,     0,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,     0,   194,   195,   196,     0,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,     0,   245,     0,   246,
     247,   248,   249,   250,   251,   252,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,     0,    12,     0,     0,     0,    13,
      14,     0,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
       0,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,     0,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,     0,
      70,    71,    72,    73,    74,     0,    75,    76,    77,     0,
       0,    78,    79,     0,     0,     0,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     0,     0,     0,
      91,     0,    92,    93,    94,    95,     0,    96,     0,     0,
       0,    97,    98,    99,   100,   101,     0,     0,     0,     0,
       0,     0,   102,   103,   104,   105,   106,   107,   108,   109,
     110,     0,   111,   112,   113,   114,   115,     0,     0,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   123,     0,
     124,     0,   125,   126,     0,     0,   127,   128,   129,     0,
       0,     0,   130,     0,   131,   132,     0,   133,   134,     0,
     135,     0,   136,     0,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,     0,     0,   148,   149,   150,
       0,   415,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,     0,   194,   195,   196,     0,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,     0,   245,     0,
     246,   247,   248,   249,   250,   251,   252,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,    11,     0,    12,     0,     0,     0,
      13,   413,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,     0,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,     0,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,    70,    71,    72,    73,    74,     0,    75,    76,    77,
       0,     0,    78,    79,     0,     0,     0,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,     0,     0,
       0,    91,     0,    92,    93,    94,    95,     0,    96,     0,
       0,     0,    97,    98,    99,   100,   101,     0,     0,     0,
       0,     0,     0,   102,   103,   104,   105,   106,   107,   108,
     109,   110,     0,   111,   112,   113,   114,   115,     0,     0,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   123,
       0,   124,     0,   125,   126,     0,     0,   127,   128,   129,
       0,     0,     0,   130,     0,   131,   132,     0,   133,   134,
       0,   135,     0,   136,     0,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,     0,     0,   148,   149,
     150,     0,   415,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,     0,   194,   195,   196,     0,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,     0,   245,
       0,   246,   247,   248,   249,   250,   251,   252,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,    11,     0,    12,     0,     0,
       0,   885,   413,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,   414,    29,    30,
      31,    32,     0,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,     0,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,    70,    71,    72,    73,    74,     0,    75,    76,
      77,     0,     0,    78,    79,     0,     0,     0,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,     0,
       0,     0,    91,     0,    92,    93,    94,    95,     0,    96,
       0,     0,     0,    97,    98,    99,   100,   101,     0,     0,
       0,     0,     0,     0,   102,   103,   104,   105,   106,   107,
     108,   109,   110,     0,   111,   112,   113,   114,   115,     0,
       0,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,     0,   124,     0,   125,   126,     0,     0,   127,   128,
     129,     0,     0,     0,   130,     0,   131,   132,     0,   133,
     134,     0,   135,     0,   136,     0,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,     0,     0,   148,
     149,   150,     0,   415,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,     0,   194,   195,   196,
       0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,     0,
     245,     0,   246,   247,   248,   249,   250,   251,   252,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,    11,     0,    12,     0,
       0,     0,   412,   413,     0,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,  1347,   414,    29,
      30,    31,    32,     0,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,     0,    46,    47,
      48,  1348,  1349,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,    70,    71,    72,    73,    74,     0,    75,
      76,    77,     0,     0,    78,    79,     0,     0,     0,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
       0,     0,     0,    91,     0,    92,    93,    94,    95,     0,
      96,     0,     0,     0,    97,    98,    99,   100,   101,     0,
       0,     0,     0,     0,     0,   102,   103,   104,   105,   106,
     107,   108,   109,   110,     0,   111,   112,   113,   114,   115,
       0,     0,     0,     0,   116,   117,   118,   119,   120,   121,
     122,   123,     0,   124,     0,   125,   126,     0,     0,   127,
     128,   129,     0,     0,     0,   130,     0,   131,   132,     0,
     133,   134,     0,   135,     0,   136,     0,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,     0,     0,
     148,   149,   150,     0,   415,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,  1350,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,     0,   194,   195,
     196,     0,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
       0,   245,     0,   246,   247,   248,   249,   250,   251,   252,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,     0,     0,     0,    12,
       0,     0,     0,   412,   413,     0,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,   557,   414,
      29,    30,    31,    32,     0,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,     0,    46,
      47,    48,   558,   559,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,     0,    70,    71,    72,    73,    74,     0,
      75,    76,    77,     0,     0,    78,    79,     0,     0,     0,
      80,    81,   507,    83,    84,    85,    86,    87,   560,    89,
      90,     0,     0,     0,    91,     0,    92,    93,    94,    95,
       0,    96,     0,     0,     0,    97,    98,    99,   100,   101,
       0,     0,     0,     0,     0,     0,   102,   103,   104,   105,
     106,   107,   108,   561,   110,     0,   111,   112,   113,   114,
     115,     0,     0,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   123,     0,   124,     0,   125,   126,     0,     0,
     127,   128,   129,     0,     0,   562,   130,     0,   131,   132,
       0,   133,   134,     0,   135,     0,   136,     0,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,     0,
       0,   148,   149,   150,     0,   415,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   525,   526,
     527,   177,   178,   528,   563,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,     0,   194,
     195,   196,     0,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,     0,   245,     0,   246,   247,   248,   249,   250,   251,
     252,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,     0,     0,     0,
      12,     0,     0,     0,   412,   413,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,   557,
     414,    29,    30,    31,    32,     0,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,     0,
      46,    47,    48,   558,   559,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,    70,    71,    72,    73,    74,
       0,    75,    76,    77,     0,     0,    78,    79,     0,     0,
       0,    80,    81,   507,    83,    84,    85,    86,    87,   560,
      89,    90,     0,     0,     0,    91,     0,    92,    93,    94,
      95,     0,    96,     0,     0,     0,    97,    98,    99,   100,
     101,     0,     0,     0,     0,     0,     0,   102,   103,   104,
     105,   106,   107,   108,   561,   110,     0,   111,   112,   113,
     114,   115,     0,     0,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,     0,   124,     0,   125,   126,     0,
       0,   127,   128,   129,     0,     0,     0,   130,   567,   131,
     132,     0,   133,   134,     0,   135,     0,   136,     0,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
       0,     0,   148,   149,   150,     0,   415,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   525,
     526,   527,   177,   178,   528,   563,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,     0,
     194,   195,   196,     0,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,     0,   245,     0,   246,   247,   248,   249,   250,
     251,   252,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,     0,     0,
       0,    12,     0,     0,     0,   412,   413,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
     557,   414,    29,    30,    31,    32,     0,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
       0,    46,    47,    48,   558,   559,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,    70,    71,    72,    73,
      74,     0,    75,    76,    77,     0,     0,    78,    79,     0,
       0,     0,    80,    81,   507,    83,    84,    85,    86,    87,
     560,    89,    90,     0,     0,     0,    91,     0,    92,    93,
      94,    95,     0,    96,     0,     0,     0,    97,    98,    99,
     100,   101,     0,     0,     0,     0,     0,     0,   102,   103,
     104,   105,   106,   107,   108,   561,   110,     0,   111,   112,
     113,   114,   115,     0,     0,     0,     0,   116,   117,   118,
     119,   120,   121,   122,   123,     0,   124,     0,   125,   126,
       0,     0,   127,   128,   129,     0,     0,     0,   130,     0,
     131,   132,     0,   133,   134,     0,   135,     0,   136,     0,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,     0,     0,   148,   149,   150,     0,   415,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     525,   526,   527,   177,   178,   528,   563,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
       0,   194,   195,   196,     0,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   606,   245,     0,   246,   247,   248,   249,
     250,   251,   252,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,     0,
       0,     0,    12,     0,     0,     0,   412,   413,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   557,   414,    29,    30,    31,    32,     0,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,     0,    46,    47,    48,   558,   559,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,    70,    71,    72,
      73,    74,     0,    75,    76,    77,     0,     0,    78,    79,
       0,     0,     0,    80,    81,   507,    83,    84,    85,    86,
      87,   560,    89,    90,     0,     0,     0,    91,     0,    92,
      93,    94,    95,     0,    96,     0,     0,     0,    97,    98,
      99,   100,   101,     0,     0,     0,     0,     0,     0,   102,
     103,   104,   105,   106,   107,   108,   561,   110,     0,   111,
     112,   113,   114,   115,     0,     0,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   123,     0,   124,     0,   125,
     126,     0,     0,   127,   128,   129,     0,     0,     0,   130,
       0,   131,   132,     0,   133,   134,     0,   135,     0,   136,
       0,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,     0,     0,   148,   149,   150,     0,   415,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   525,   526,   527,   177,   178,   528,   563,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,     0,   194,   195,   196,     0,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,     0,   245,   608,   246,   247,   248,
     249,   250,   251,   252,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
       0,     0,     0,    12,     0,     0,     0,   412,   413,     0,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,   557,   414,    29,    30,    31,    32,     0,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,     0,    46,    47,    48,   558,   559,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     0,    70,    71,
      72,    73,    74,     0,    75,    76,    77,     0,     0,    78,
      79,     0,     0,     0,    80,    81,   507,    83,    84,    85,
      86,    87,   560,    89,    90,     0,     0,     0,    91,     0,
      92,    93,    94,    95,     0,    96,     0,     0,     0,    97,
      98,    99,   100,   101,     0,     0,     0,     0,     0,     0,
     102,   103,   104,   105,   106,   107,   108,   561,   110,     0,
     111,   112,   113,   114,   115,     0,     0,     0,     0,   116,
     117,   118,   119,   120,   121,   122,   123,     0,   124,     0,
     125,   126,     0,     0,   127,   128,   129,     0,   930,     0,
     130,     0,   131,   132,     0,   133,   134,     0,   135,     0,
     136,     0,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,     0,     0,   148,   149,   150,     0,   415,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   525,   526,   527,   177,   178,   528,   563,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,     0,   194,   195,   196,     0,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,     0,   245,     0,   246,   247,
     248,   249,   250,   251,   252,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,     0,     0,     0,    12,     0,     0,     0,   412,   413,
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,   557,   414,    29,    30,    31,    32,     0,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,     0,    46,    47,    48,   558,   559,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,     0,    70,
      71,    72,    73,    74,     0,    75,    76,    77,     0,     0,
      78,    79,     0,     0,     0,    80,    81,   507,    83,    84,
      85,    86,    87,   560,    89,    90,     0,     0,     0,    91,
       0,    92,    93,    94,    95,     0,    96,     0,     0,     0,
      97,    98,    99,   100,   101,     0,     0,     0,     0,     0,
       0,   102,   103,   104,   105,   106,   107,   108,   561,   110,
       0,   111,   112,   113,   114,   115,     0,     0,     0,     0,
     116,   117,   118,   119,   120,   121,   122,   123,     0,   124,
       0,   125,   126,     0,     0,   127,   128,   129,     0,     0,
       0,   130,   936,   131,   132,     0,   133,   134,     0,   135,
       0,   136,     0,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,     0,     0,   148,   149,   150,     0,
     415,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   525,   526,   527,   177,   178,   528,   563,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,     0,   194,   195,   196,     0,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,     0,   245,     0,   246,
     247,   248,   249,   250,   251,   252,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,     0,     0,     0,    12,     0,     0,     0,   412,
     413,     0,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,   557,   414,    29,    30,    31,    32,
       0,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,     0,    46,    47,    48,   558,   559,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,     0,
      70,    71,    72,    73,    74,     0,    75,    76,    77,     0,
       0,    78,    79,     0,     0,     0,    80,    81,   507,    83,
      84,    85,    86,    87,   560,    89,    90,     0,     0,     0,
      91,     0,    92,    93,    94,    95,     0,    96,     0,     0,
       0,    97,    98,    99,   100,   101,     0,     0,     0,     0,
       0,     0,   102,   103,   104,   105,   106,   107,   108,   561,
     110,     0,   111,   112,   113,   114,   115,     0,     0,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   123,     0,
     124,     0,   125,   126,     0,     0,   127,   128,   129,     0,
       0,     0,   130,   940,   131,   132,     0,   133,   134,     0,
     135,     0,   136,     0,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,     0,     0,   148,   149,   150,
       0,   415,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   525,   526,   527,   177,   178,   528,
     563,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,     0,   194,   195,   196,     0,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,     0,   245,     0,
     246,   247,   248,   249,   250,   251,   252,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,     0,     0,     0,    12,     0,     0,     0,
     412,   413,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,   493,    26,   495,   414,    29,   496,    31,
      32,     0,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,   498,     0,    46,    47,    48,   500,
     501,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,    70,    71,    72,    73,    74,     0,    75,    76,    77,
       0,     0,    78,    79,     0,     0,     0,    80,    81,   507,
      83,    84,    85,    86,    87,   560,    89,    90,     0,     0,
       0,    91,     0,    92,    93,    94,    95,     0,    96,     0,
       0,     0,   510,    98,    99,   100,   101,     0,     0,     0,
       0,     0,     0,   102,   103,   104,   105,   106,   107,   108,
     561,   110,     0,   111,   112,   687,   114,   115,     0,     0,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   123,
       0,   124,     0,   688,   126,     0,     0,   127,   128,   129,
       0,     0,     0,   130,     0,   131,   132,     0,   133,   134,
       0,   135,     0,   136,     0,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,     0,     0,   148,   149,
     150,     0,   415,   152,   153,   154,   155,   156,   157,   158,
     159,   520,   161,   521,   163,   522,   523,   166,   167,   168,
     169,   170,   171,   524,   173,   525,   526,   527,   177,   178,
     528,   529,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,     0,   194,   195,   196,     0,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,     0,   245,
       0,   246,   530,   248,   249,   250,   251,   252,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,     0,     0,     0,    12,     0,     0,
       0,   412,   413,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,   557,   414,    29,    30,
      31,    32,     0,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,     0,    46,    47,    48,
     558,   559,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,    70,    71,    72,    73,    74,     0,    75,    76,
      77,     0,     0,    78,    79,     0,     0,     0,    80,    81,
     507,    83,    84,    85,    86,    87,   560,    89,    90,     0,
       0,     0,    91,     0,    92,    93,    94,    95,     0,    96,
       0,     0,     0,    97,    98,    99,   100,   101,     0,     0,
       0,     0,     0,     0,   102,   103,   104,   105,   106,   107,
     108,   561,   110,     0,   111,   112,   113,   114,   115,     0,
       0,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,     0,   124,     0,   125,   126,     0,     0,   127,   128,
     129,     0,     0,     0,   130,     0,   131,   132,     0,   133,
     134,     0,   135,     0,   136,     0,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,     0,     0,   148,
     149,   150,     0,   415,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   525,   526,   527,   177,
     178,   528,   563,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,     0,   194,   195,   196,
       0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,     0,
     245,     0,   246,   247,   248,   249,   250,   251,   252,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,     0,     0,     0,    12,     0,
       0,     0,   412,   413,     0,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,   493,    26,   495,   414,    29,
     496,    31,    32,     0,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,   498,     0,    46,    47,
      48,   500,   501,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,    70,    71,    72,    73,    74,     0,    75,
      76,    77,     0,     0,    78,    79,     0,     0,     0,    80,
      81,   507,    83,    84,    85,    86,    87,   560,    89,    90,
       0,     0,     0,    91,     0,    92,    93,    94,    95,     0,
      96,     0,     0,     0,   510,    98,    99,   100,   101,     0,
       0,     0,     0,     0,     0,   102,   103,   104,   105,   106,
     107,   108,   561,   110,     0,   111,   112,   113,   114,   115,
       0,     0,     0,     0,   116,   117,   118,   119,   120,   121,
     122,   123,     0,   124,     0,   125,   126,     0,     0,   127,
     128,   129,     0,     0,     0,   130,     0,   131,   132,     0,
     133,   134,     0,   135,     0,   136,     0,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,     0,     0,
     148,   149,   150,     0,   415,   152,   153,   154,   155,   156,
     157,   158,   159,   520,   161,   521,   163,   522,   523,   166,
     167,   168,   169,   170,   171,   524,   173,   525,   526,   527,
     177,   178,   528,   529,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,     0,   194,   195,
     196,     0,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
       0,   245,     0,   246,   530,   248,   249,   250,   251,   252,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,     0,     0,     0,    12,
       0,     0,     0,   412,   413,     0,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,   493,    26,   495,   414,
      29,   496,    31,    32,     0,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,   498,     0,    46,
      47,    48,   500,   501,    51,   502,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,     0,    70,    71,    72,    73,    74,     0,
      75,    76,    77,     0,     0,    78,    79,     0,     0,     0,
      80,    81,   507,    83,    84,    85,    86,    87,   560,    89,
      90,     0,     0,     0,    91,     0,    92,    93,    94,    95,
       0,    96,     0,     0,     0,   510,    98,    99,   100,   101,
       0,     0,     0,     0,     0,     0,   102,   103,   104,   105,
     106,   107,   108,   561,   110,     0,   111,   112,     0,   114,
     115,     0,     0,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   123,     0,   124,     0,     0,     0,     0,     0,
     127,   128,   129,     0,     0,     0,   130,     0,   131,   132,
       0,   133,   134,     0,   135,     0,   136,     0,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,     0,
       0,   148,   149,   150,     0,   415,   152,   153,   154,   155,
     156,   157,   158,   159,   520,   161,   521,   163,   522,   523,
     166,   167,   168,   169,   170,   171,   524,   173,   525,   526,
     527,   177,   178,   528,   529,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,     0,   194,
     195,   196,     0,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,     0,   245,     0,   246,   530,   248,   249,   250,   251,
     252,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,     0,     0,     0,
      12,     0,     0,     0,   412,   413,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,   493,    26,   495,
     414,    29,   496,    31,    32,     0,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,   498,     0,
      46,    47,    48,   500,   501,    51,   502,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,    70,    71,    72,    73,    74,
       0,    75,    76,    77,     0,     0,    78,    79,     0,     0,
       0,    80,    81,   507,    83,    84,    85,    86,    87,   560,
      89,    90,     0,     0,     0,    91,     0,    92,    93,    94,
      95,     0,    96,     0,     0,     0,   510,    98,    99,   100,
     101,     0,     0,     0,     0,     0,     0,   102,   103,   104,
     105,   106,   107,   108,   561,   110,     0,   111,   112,     0,
     114,   115,     0,     0,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,     0,   124,     0,     0,     0,     0,
       0,   127,   128,   129,     0,     0,     0,   130,     0,   131,
     132,     0,     0,     0,     0,   135,     0,   136,     0,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
       0,     0,   148,   149,   150,     0,   415,   152,   153,   154,
     155,   156,   157,   158,   159,   520,   161,   521,   163,   522,
     523,   166,   167,   168,   169,   170,   171,   524,   173,   525,
     526,   527,   177,   178,   528,   529,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,     0,
     194,   195,   196,     0,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,     0,   245,     0,   246,   530,   248,   249,   250,
     251,   252,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,     0,     0,
       0,    12,     0,     0,     0,   412,   413,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,   493,    26,
     495,   414,    29,   496,    31,    32,     0,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,   498,
       0,    46,    47,    48,   500,   501,    51,   502,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,    70,    71,    72,    73,
      74,     0,    75,    76,    77,     0,     0,    78,    79,     0,
       0,     0,    80,    81,   507,    83,    84,    85,    86,    87,
     560,    89,    90,     0,     0,     0,    91,     0,    92,    93,
      94,    95,     0,    96,     0,     0,     0,   510,     0,    99,
     100,   101,     0,     0,     0,     0,     0,     0,   102,   103,
     104,   105,     0,   107,   108,   561,   110,     0,   111,   112,
       0,   114,   115,     0,     0,     0,     0,   116,   117,   118,
     119,   120,   121,   122,   123,     0,   124,     0,     0,     0,
       0,     0,   127,   128,   129,     0,     0,     0,   130,     0,
     131,   132,     0,     0,     0,     0,   135,     0,   136,     0,
     137,     0,   139,     0,   141,   142,   143,   144,   145,   146,
     147,     0,     0,   148,   149,   150,     0,   415,   152,   153,
     154,   155,   156,   157,   158,   159,   520,   161,   521,   163,
     522,   523,   166,   167,   168,   169,   170,   171,   524,   173,
     525,   526,   527,   177,   178,   528,   529,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
       0,   194,   195,   196,     0,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,     0,   245,     0,   246,   530,   248,   249,
     250,   251,   252,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     0,     0,     0,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,   412,   413,     0,    15,
      16,    17,   490,    19,    20,    21,   491,    23,   492,   493,
     494,   495,   414,    29,   496,    31,    32,     0,    33,    34,
      35,    36,   497,    38,    39,    40,    41,    42,    43,    44,
     498,     0,    46,   499,    48,   500,   501,    51,   502,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,   503,   504,    69,     0,    70,    71,    72,
     505,     0,     0,    75,    76,    77,     0,     0,   506,    79,
       0,     0,     0,     0,    81,   507,    83,   508,   509,    86,
      87,     0,     0,     0,     0,     0,     0,     0,     0,    92,
      93,    94,    95,     0,    96,     0,     0,     0,   510,    98,
      99,   511,   512,     0,     0,     0,     0,     0,     0,   102,
     103,   104,     0,   106,   107,   108,     0,     0,     0,     0,
       0,     0,   114,   513,     0,     0,     0,     0,   116,   117,
     118,   119,   514,   121,   122,   515,     0,     0,     0,     0,
       0,     0,     0,   516,   517,   129,     0,     0,     0,   130,
       0,   131,   518,     0,     0,     0,     0,   135,     0,   136,
       0,   137,   138,   139,   140,   519,   142,   143,   144,   145,
     146,   147,     0,     0,   148,   149,     0,     0,   415,   152,
     153,   154,   155,   156,   157,   158,   159,   520,   161,   521,
     163,   522,   523,   166,   167,   168,   169,   170,   171,   524,
     173,   525,   526,   527,   177,   178,   528,   529,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,     0,   194,   195,   196,     0,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,     0,     1,     2,   246,   530,   248,
     249,   250,   251,   252,     3,     0,     0,     0,     0,     8,
       9,     0,     0,     0,     0,     0,     0,     0,   412,   413,
       0,    15,    16,    17,   539,    19,    20,    21,   491,   540,
     541,   493,   494,   495,   414,    29,   496,    31,    32,     0,
      33,    34,    35,    36,   542,    38,   543,   544,    41,    42,
      43,    44,   498,     0,    46,   545,    48,   500,   501,    51,
     502,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,   503,   504,    69,     0,    70,
      71,    72,   546,     0,     0,    75,    76,    77,     0,     0,
     506,    79,     0,     0,     0,     0,    81,   507,    83,   508,
     509,    86,    87,     0,     0,     0,     0,     0,     0,     0,
       0,    92,    93,    94,    95,     0,    96,     0,     0,     0,
     510,    98,    99,   511,   512,     0,     0,     0,     0,     0,
       0,   102,   103,   104,     0,   106,   107,   108,     0,     0,
       0,     0,     0,     0,   114,   513,     0,     0,     0,     0,
     116,   117,   118,   119,   514,   121,   122,   515,     0,     0,
       0,     0,     0,     0,     0,   516,   517,   129,     0,     0,
       0,   130,     0,   131,   518,     0,     0,     0,     0,   135,
       0,   136,     0,   137,   138,   139,   140,   519,   142,   143,
     144,   145,   146,   147,     0,     0,   148,   149,     0,     0,
     415,   152,   153,   154,   155,   156,   157,   158,   159,   520,
     547,   521,   163,   522,   523,   166,   167,   168,   169,   170,
     171,   524,   173,   525,   526,   527,   177,   178,   528,   529,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,     0,   194,   195,   196,     0,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,     0,   573,     0,   246,
     530,   248,   249,   250,   251,   252,     8,     9,     0,     0,
       0,   789,     0,     0,     0,   412,   413,     0,    15,    16,
      17,   539,    19,    20,    21,   491,   540,   541,   493,   494,
     495,   414,    29,   496,    31,    32,     0,    33,    34,    35,
      36,   542,    38,   543,   544,    41,    42,    43,    44,   498,
       0,    46,   545,    48,   500,   501,    51,   502,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,   503,   504,    69,     0,    70,    71,    72,   546,
       0,     0,    75,    76,    77,     0,     0,   506,    79,     0,
       0,     0,     0,    81,   507,    83,   508,   509,    86,    87,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    93,
      94,    95,     0,    96,     0,     0,     0,   510,    98,    99,
     511,   512,     0,     0,     0,     0,     0,     0,   102,   103,
     104,     0,   106,   107,   108,     0,     0,     0,     0,     0,
       0,   114,   513,     0,     0,     0,     0,   116,   117,   118,
     119,   514,   121,   122,   515,     0,     0,     0,     0,     0,
       0,     0,   516,   517,   129,     0,     0,     0,   130,   790,
     131,   518,     0,     0,     0,     0,     0,     0,   136,     0,
     137,   138,   139,   140,   519,   142,   143,   144,   145,   146,
     147,     0,     0,   148,   149,     0,     0,   415,   152,   153,
     154,   155,   156,   157,   158,   159,   520,   547,   521,   163,
     522,   523,   166,   167,   168,   169,   170,   171,   524,   173,
     525,   526,   527,   177,   178,   528,   529,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
       0,   194,   195,   196,     0,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,     0,   573,     0,   246,   530,   248,   249,
     250,   251,   252,     8,     9,     0,     0,     0,     0,     0,
       0,     0,   412,   413,     0,    15,    16,    17,   539,    19,
      20,    21,   491,   540,   541,   493,   494,   495,   414,    29,
     496,    31,    32,     0,    33,    34,    35,    36,   542,    38,
     543,   544,    41,    42,    43,    44,   498,     0,    46,   545,
      48,   500,   501,    51,   502,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,   503,
     504,    69,     0,    70,    71,    72,   546,     0,     0,    75,
      76,    77,     0,     0,   506,    79,     0,     0,     0,     0,
      81,   507,    83,   508,   509,    86,    87,     0,     0,     0,
       0,     0,     0,     0,     0,    92,    93,    94,    95,     0,
      96,     0,     0,     0,   510,    98,    99,   511,   512,     0,
       0,     0,     0,     0,     0,   102,   103,   104,     0,   106,
     107,   108,     0,     0,     0,     0,     0,     0,   114,   513,
       0,     0,     0,     0,   116,   117,   118,   119,   514,   121,
     122,   515,     0,     0,     0,     0,     0,     0,     0,   516,
     517,   129,     0,     0,     0,   130,     0,   131,   518,     0,
       0,     0,     0,     0,     0,   136,     0,   137,   138,   139,
     140,   519,   142,   143,   144,   145,   146,   147,     0,     0,
     148,   149,     0,     0,   415,   152,   153,   154,   155,   156,
     157,   158,   159,   520,   547,   521,   163,   522,   523,   166,
     167,   168,   169,   170,   171,   524,   173,   525,   526,   527,
     177,   178,   528,   529,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,     0,   194,   195,
     196,     0,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
       0,     0,     0,   246,   530,   248,   249,   250,   251,   252,
     576,   577,     0,     0,     0,     0,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,   412,   413,     0,    15,
      16,    17,   539,    19,    20,    21,   491,   540,   541,   493,
     494,   495,   414,    29,   496,    31,    32,     0,    33,    34,
      35,    36,   542,    38,   543,   544,    41,    42,    43,    44,
     498,     0,    46,   545,    48,   500,   501,    51,   502,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,   503,   504,    69,     0,    70,    71,    72,
     546,     0,     0,    75,    76,    77,     0,     0,   506,    79,
       0,     0,     0,     0,    81,   507,    83,   508,   509,    86,
      87,     0,     0,     0,     0,     0,     0,     0,     0,    92,
      93,    94,    95,     0,    96,     0,     0,     0,   510,    98,
      99,   511,   512,     0,     0,     0,     0,     0,     0,   102,
     103,   104,     0,   106,   107,   108,     0,     0,     0,     0,
       0,     0,   114,   513,     0,     0,     0,     0,   116,   117,
     118,   119,   514,   121,   122,   515,     0,     0,     0,     0,
       0,     0,     0,   516,   517,   129,     0,     0,     0,   130,
       0,   131,   518,     0,     0,     0,     0,     0,     0,   136,
       0,   137,   138,   139,   140,   519,   142,   143,   144,   145,
     146,   147,     0,     0,   148,   149,     0,     0,   415,   152,
     153,   154,   155,   156,   157,   158,   159,   520,   547,   521,
     163,   522,   523,   166,   167,   168,   169,   170,   171,   524,
     173,   525,   526,   527,   177,   178,   528,   529,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,     0,   194,   195,   196,     0,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,     0,     0,     0,   246,   530,   248,
     249,   250,   251,   252,     4,     5,     6,     7,     8,     9,
       0,     0,     0,    12,     0,     0,     0,   412,   413,     0,
      15,    16,    17,   840,    19,    20,    21,    22,   540,   841,
     493,    26,   495,   414,    29,   496,    31,    32,     0,    33,
      34,    35,    36,   842,    38,   543,   544,    41,    42,    43,
      44,   498,     0,    46,   843,    48,   500,   501,    51,   502,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,   503,   504,    69,     0,    70,    71,
      72,   844,     0,     0,    75,    76,    77,     0,     0,   506,
      79,     0,     0,     0,    80,    81,   507,    83,   508,   509,
      86,    87,   560,    89,     0,     0,     0,     0,    91,     0,
      92,    93,    94,    95,     0,    96,     0,     0,     0,   510,
      98,    99,   511,   512,     0,     0,     0,     0,     0,     0,
     102,   103,   104,   105,   106,   107,   108,   561,   110,     0,
     111,   112,     0,   114,   115,     0,     0,     0,     0,   116,
     117,   118,   119,   120,   121,   122,   515,     0,   124,     0,
       0,     0,     0,     0,   516,   517,   129,     0,     0,     0,
     130,     0,   131,   518,     0,     0,     0,     0,     0,     0,
     136,     0,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,     0,     0,   148,   149,   150,     0,   415,
     152,   153,   154,   155,   156,   157,   158,   159,   520,   547,
     521,   163,   522,   523,   166,   167,   168,   169,   170,   171,
     524,   173,   525,   526,   527,   177,   178,   528,   529,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,     0,   194,   195,   196,     0,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,     0,   245,     0,   246,   530,
     248,   249,   250,   251,   252,     8,     9,     0,     0,     0,
       0,     0,     0,     0,   412,   413,     0,    15,    16,    17,
     490,    19,    20,    21,   491,    23,   492,   493,  1144,   495,
     414,    29,   496,    31,    32,     0,    33,    34,    35,    36,
     497,    38,    39,    40,    41,    42,    43,    44,   498,     0,
      46,   499,    48,   500,   501,    51,   502,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,   503,   504,    69,     0,    70,    71,    72,   505,     0,
       0,    75,    76,    77,     0,     0,   506,    79,     0,     0,
       0,     0,    81,   507,    83,   508,   509,    86,    87,     0,
       0,     0,     0,     0,     0,     0,     0,    92,    93,    94,
      95,     0,    96,     0,     0,     0,   510,    98,    99,   511,
     512,     0,     0,     0,     0,     0,     0,   102,   103,   104,
       0,   106,   107,  1145,     0,     0,     0,  1146,     0,     0,
     114,   513,     0,     0,     0,     0,   116,   117,   118,   119,
     514,   121,   122,   515,     0,     0,     0,     0,     0,     0,
       0,   516,   517,   129,     0,     0,     0,   130,  1578,   131,
     518,     0,     0,     0,     0,  1579,     0,   136,     0,   137,
     138,   139,   140,   519,   142,   143,   144,   145,   146,   147,
       0,     0,  1147,   149,     0,     0,   415,   152,   153,   154,
     155,   156,   157,   158,   159,   520,   161,   521,   163,   522,
     523,   166,   167,   168,   169,   170,   171,   524,   173,   525,
     526,   527,   177,   178,   528,   529,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,     0,
     194,   195,   196,     0,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,     0,     0,     8,     9,   246,   530,   248,  1148,  1149,
    1150,  1151,   412,   413,     0,    15,    16,    17,   539,    19,
      20,    21,   491,   540,   541,   493,   494,   495,   414,    29,
     496,    31,    32,     0,    33,    34,    35,    36,   542,    38,
     543,   544,    41,    42,    43,    44,   498,     0,    46,   545,
      48,   500,   501,    51,   502,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,   503,
     504,    69,     0,    70,    71,    72,   546,     0,     0,    75,
      76,    77,     0,     0,   506,    79,     0,     0,     0,     0,
      81,   507,    83,   508,   509,    86,    87,     0,     0,     0,
       0,     0,     0,     0,     0,    92,    93,    94,    95,     0,
      96,     0,     0,     0,   510,    98,    99,   511,   512,     0,
       0,     0,     0,     0,     0,   102,   103,   104,     0,   106,
     107,   108,     0,     0,     0,     0,     0,     0,   114,   513,
       0,     0,     0,     0,   116,   117,   118,   119,   514,   121,
     122,   515,     0,     0,     0,     0,     0,     0,     0,   516,
     517,   129,     0,     0,     0,   130,   759,   131,   518,     0,
       0,     0,     0,   760,     0,   136,     0,   137,   138,   139,
     140,   519,   142,   143,   144,   145,   146,   147,     0,     0,
     148,   149,     0,     0,   415,   152,   153,   154,   155,   156,
     157,   158,   159,   520,   547,   521,   163,   522,   523,   166,
     167,   168,   169,   170,   171,   524,   173,   525,   526,   527,
     177,   178,   528,   529,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,     0,   194,   195,
     196,     0,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
       0,     8,     9,   246,   530,   248,   249,   250,   251,   252,
     412,   413,     0,    15,    16,    17,   539,    19,    20,    21,
     491,   540,   541,   493,   494,   495,   414,    29,   496,    31,
      32,     0,    33,    34,    35,    36,   542,    38,   543,   544,
      41,    42,    43,    44,   498,     0,    46,   545,    48,   500,
     501,    51,   502,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,   503,   504,    69,
       0,    70,    71,    72,   546,     0,     0,    75,    76,    77,
       0,     0,   506,    79,     0,     0,     0,     0,    81,   507,
      83,   508,   509,    86,    87,     0,     0,     0,     0,     0,
       0,     0,     0,    92,    93,    94,    95,     0,    96,     0,
       0,     0,   510,    98,    99,   511,   512,     0,     0,     0,
       0,     0,     0,   102,   103,   104,     0,   106,   107,   108,
       0,     0,     0,     0,     0,     0,   114,   513,     0,     0,
       0,     0,   116,   117,   118,   119,   514,   121,   122,   515,
       0,     0,     0,     0,     0,     0,     0,   516,   517,   129,
       0,     0,     0,   130,   807,   131,   518,     0,     0,     0,
       0,   808,     0,   136,     0,   137,   138,   139,   140,   519,
     142,   143,   144,   145,   146,   147,     0,     0,   148,   149,
       0,     0,   415,   152,   153,   154,   155,   156,   157,   158,
     159,   520,   547,   521,   163,   522,   523,   166,   167,   168,
     169,   170,   171,   524,   173,   525,   526,   527,   177,   178,
     528,   529,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,     0,   194,   195,   196,     0,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,     0,     0,     8,
       9,   246,   530,   248,   249,   250,   251,   252,   412,   413,
       0,    15,    16,    17,   490,    19,    20,    21,   491,    23,
     492,   493,  1144,   495,   414,    29,   496,    31,    32,     0,
      33,    34,    35,    36,   497,    38,    39,    40,    41,    42,
      43,    44,   498,     0,    46,   499,    48,   500,   501,    51,
     502,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,   503,   504,    69,     0,    70,
      71,    72,   505,     0,     0,    75,    76,    77,     0,     0,
     506,    79,     0,     0,     0,     0,    81,   507,    83,   508,
     509,    86,    87,  1494,     0,     0,     0,     0,     0,     0,
       0,    92,    93,    94,    95,     0,    96,     0,     0,     0,
     510,    98,    99,   511,   512,     0,     0,     0,     0,     0,
       0,   102,   103,   104,     0,   106,   107,  1145,     0,     0,
       0,  1146,     0,     0,   114,   513,     0,     0,     0,     0,
     116,   117,   118,   119,   514,   121,   122,   515,     0,     0,
       0,     0,     0,     0,     0,   516,   517,   129,     0,     0,
       0,   130,     0,   131,   518,     0,     0,     0,     0,     0,
       0,   136,     0,   137,   138,   139,   140,   519,   142,   143,
     144,   145,   146,   147,     0,     0,  1147,   149,     0,     0,
     415,   152,   153,   154,   155,   156,   157,   158,   159,   520,
     161,   521,   163,   522,   523,   166,   167,   168,   169,   170,
     171,   524,   173,   525,   526,   527,   177,   178,   528,   529,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,     0,   194,   195,   196,     0,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,     0,     8,     9,   246,
     530,   248,  1148,  1149,  1150,  1151,   412,   413,     0,    15,
      16,    17,   490,    19,    20,    21,   491,    23,   492,   493,
    1144,   495,   414,    29,   496,    31,    32,     0,    33,    34,
      35,    36,   497,    38,    39,    40,    41,    42,    43,    44,
     498,     0,    46,   499,    48,   500,   501,    51,   502,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,   503,   504,    69,     0,    70,    71,    72,
     505,     0,     0,    75,    76,    77,     0,     0,   506,    79,
       0,     0,     0,     0,    81,   507,    83,   508,   509,    86,
      87,  1636,     0,     0,     0,     0,     0,     0,     0,    92,
      93,    94,    95,     0,    96,     0,     0,     0,   510,    98,
      99,   511,   512,     0,     0,     0,     0,     0,     0,   102,
     103,   104,     0,   106,   107,  1145,     0,     0,     0,  1146,
       0,     0,   114,   513,     0,     0,     0,     0,   116,   117,
     118,   119,   514,   121,   122,   515,     0,     0,     0,     0,
       0,     0,     0,   516,   517,   129,     0,     0,     0,   130,
       0,   131,   518,     0,     0,     0,     0,     0,     0,   136,
       0,   137,   138,   139,   140,   519,   142,   143,   144,   145,
     146,   147,     0,     0,  1147,   149,     0,     0,   415,   152,
     153,   154,   155,   156,   157,   158,   159,   520,   161,   521,
     163,   522,   523,   166,   167,   168,   169,   170,   171,   524,
     173,   525,   526,   527,   177,   178,   528,   529,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,     0,   194,   195,   196,     0,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,     0,     8,     9,   246,   530,   248,
    1148,  1149,  1150,  1151,   412,   413,     0,    15,    16,    17,
     490,    19,    20,    21,   491,    23,   492,   493,  1144,   495,
     414,    29,   496,    31,    32,     0,    33,    34,    35,    36,
     497,    38,    39,    40,    41,    42,    43,    44,   498,     0,
      46,   499,    48,   500,   501,    51,   502,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,   503,   504,    69,     0,    70,    71,    72,   505,     0,
       0,    75,    76,    77,     0,     0,   506,    79,     0,     0,
       0,     0,    81,   507,    83,   508,   509,    86,    87,  1640,
       0,     0,     0,     0,     0,     0,     0,    92,    93,    94,
      95,     0,    96,     0,     0,     0,   510,    98,    99,   511,
     512,     0,     0,     0,     0,     0,     0,   102,   103,   104,
       0,   106,   107,  1145,     0,     0,     0,  1146,     0,     0,
     114,   513,     0,     0,     0,     0,   116,   117,   118,   119,
     514,   121,   122,   515,     0,     0,     0,     0,     0,     0,
       0,   516,   517,   129,     0,     0,     0,   130,     0,   131,
     518,     0,     0,     0,     0,     0,     0,   136,     0,   137,
     138,   139,   140,   519,   142,   143,   144,   145,   146,   147,
       0,     0,  1147,   149,     0,     0,   415,   152,   153,   154,
     155,   156,   157,   158,   159,   520,   161,   521,   163,   522,
     523,   166,   167,   168,   169,   170,   171,   524,   173,   525,
     526,   527,   177,   178,   528,   529,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,     0,
     194,   195,   196,     0,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,     0,     0,     8,     9,   246,   530,   248,  1148,  1149,
    1150,  1151,   412,   413,     0,    15,    16,    17,   490,    19,
      20,    21,   491,    23,   492,   493,  1144,   495,   414,    29,
     496,    31,    32,     0,    33,    34,    35,    36,   497,    38,
      39,    40,    41,    42,    43,    44,   498,     0,    46,   499,
      48,   500,   501,    51,   502,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,   503,
     504,    69,     0,    70,    71,    72,   505,     0,     0,    75,
      76,    77,     0,     0,   506,    79,     0,     0,     0,     0,
      81,   507,    83,   508,   509,    86,    87,     0,     0,     0,
       0,     0,     0,     0,     0,    92,    93,    94,    95,     0,
      96,     0,     0,     0,   510,    98,    99,   511,   512,     0,
       0,     0,     0,     0,     0,   102,   103,   104,     0,   106,
     107,  1145,     0,     0,     0,  1146,     0,     0,   114,   513,
       0,     0,     0,     0,   116,   117,   118,   119,   514,   121,
     122,   515,     0,     0,     0,     0,     0,     0,     0,   516,
     517,   129,     0,     0,     0,   130,     0,   131,   518,     0,
       0,     0,     0,     0,     0,   136,     0,   137,   138,   139,
     140,   519,   142,   143,   144,   145,   146,   147,     0,     0,
    1147,   149,     0,     0,   415,   152,   153,   154,   155,   156,
     157,   158,   159,   520,   161,   521,   163,   522,   523,   166,
     167,   168,   169,   170,   171,   524,   173,   525,   526,   527,
     177,   178,   528,   529,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,     0,   194,   195,
     196,     0,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
       0,     8,     9,   246,   530,   248,  1148,  1149,  1150,  1151,
     412,   413,     0,    15,    16,    17,   490,    19,    20,    21,
     491,    23,   492,   493,  1144,   495,   414,    29,   496,    31,
      32,     0,    33,    34,    35,    36,   497,    38,    39,    40,
      41,    42,    43,    44,   498,     0,    46,   499,    48,   500,
     501,    51,   502,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,   503,   504,    69,
       0,    70,    71,    72,   505,     0,     0,    75,    76,    77,
       0,     0,   506,    79,     0,     0,     0,     0,    81,   507,
      83,   508,   509,    86,    87,     0,     0,     0,     0,     0,
       0,     0,     0,    92,    93,    94,    95,     0,    96,     0,
       0,     0,   510,    98,    99,   511,   512,     0,     0,     0,
       0,     0,     0,   102,   103,   104,     0,   106,   107,  1145,
       0,     0,     0,  1146,     0,     0,   114,   513,     0,     0,
       0,     0,   116,   117,   118,   119,   514,   121,   122,   515,
       0,     0,     0,     0,     0,     0,     0,   516,   517,   129,
       0,     0,     0,   130,     0,   131,   518,     0,     0,     0,
       0,     0,     0,   136,     0,   137,   138,   139,   140,   519,
     142,   143,   144,   145,   146,   147,     0,     0,   148,   149,
       0,     0,   415,   152,   153,   154,   155,   156,   157,   158,
     159,   520,   161,   521,   163,   522,   523,   166,   167,   168,
     169,   170,   171,   524,   173,   525,   526,   527,   177,   178,
     528,   529,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,     0,   194,   195,   196,     0,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,     0,     0,     8,
       9,   246,   530,   248,  1148,  1149,  1150,  1151,   412,   413,
       0,    15,    16,    17,   539,    19,    20,    21,   491,   540,
     541,   493,   494,   495,   414,    29,   496,    31,    32,     0,
      33,    34,    35,    36,   542,    38,   543,   544,    41,    42,
      43,    44,   498,     0,    46,   545,    48,   500,   501,    51,
     502,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,   503,   504,    69,     0,    70,
      71,    72,   546,     0,     0,    75,    76,    77,     0,     0,
     506,    79,     0,     0,     0,     0,    81,   507,    83,   508,
     509,    86,    87,  1238,     0,     0,     0,     0,     0,     0,
       0,    92,    93,    94,    95,     0,    96,     0,     0,     0,
     510,    98,    99,   511,   512,     0,     0,     0,     0,     0,
       0,   102,   103,   104,     0,   106,   107,   108,     0,     0,
       0,     0,     0,     0,   114,   513,     0,     0,     0,     0,
     116,   117,   118,   119,   514,   121,   122,   515,     0,     0,
       0,     0,     0,     0,     0,   516,   517,   129,     0,     0,
       0,   130,     0,   131,   518,     0,     0,     0,     0,     0,
       0,   136,     0,   137,   138,   139,   140,   519,   142,   143,
     144,   145,   146,   147,     0,     0,   148,   149,     0,     0,
     415,   152,   153,   154,   155,   156,   157,   158,   159,   520,
     547,   521,   163,   522,   523,   166,   167,   168,   169,   170,
     171,   524,   173,   525,   526,   527,   177,   178,   528,   529,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,     0,   194,   195,   196,     0,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,     0,     8,     9,   246,
     530,   248,   249,   250,   251,   252,   412,   413,     0,    15,
      16,    17,   539,    19,    20,    21,   491,   540,   541,   493,
     494,   495,   414,    29,   496,    31,    32,     0,    33,    34,
      35,    36,   542,    38,   543,   544,    41,    42,    43,    44,
     498,     0,    46,   545,    48,   500,   501,    51,   502,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,   503,   504,    69,     0,    70,    71,    72,
     546,     0,     0,    75,    76,    77,     0,     0,   506,    79,
       0,     0,     0,     0,    81,   507,    83,   508,   509,    86,
      87,     0,     0,     0,     0,     0,     0,     0,     0,    92,
      93,    94,    95,     0,    96,     0,     0,     0,   510,    98,
      99,   511,   512,     0,     0,     0,     0,     0,     0,   102,
     103,   104,     0,   106,   107,   108,     0,     0,     0,     0,
       0,     0,   114,   513,     0,     0,     0,     0,   116,   117,
     118,   119,   514,   121,   122,   515,     0,     0,     0,     0,
       0,     0,     0,   516,   517,   129,     0,     0,     0,   130,
       0,   131,   518,     0,     0,     0,     0,     0,     0,   136,
       0,   137,   138,   139,   140,   519,   142,   143,   144,   145,
     146,   147,     0,     0,   148,   149,     0,     0,   415,   152,
     153,   154,   155,   156,   157,   158,   159,   520,   547,   521,
     163,   522,   523,   166,   167,   168,   169,   170,   171,   524,
     173,   525,   526,   527,   177,   178,   528,   529,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,     0,   194,   195,   196,     0,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,     0,     8,     9,   246,   530,   248,
     249,   250,   251,   252,   412,   413,     0,    15,    16,    17,
       0,    19,    20,    21,   491,     0,     0,   493,   494,     0,
     414,    29,   496,    31,    32,     0,    33,    34,    35,    36,
       0,    38,     0,     0,    41,    42,    43,    44,   498,     0,
      46,     0,    48,     0,     0,    51,   502,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,   503,   504,    69,     0,    70,    71,    72,     0,     0,
       0,    75,    76,    77,     0,     0,   506,    79,     0,     0,
       0,     0,    81,   507,    83,   508,   509,    86,    87,     0,
       0,     0,     0,     0,     0,     0,     0,    92,    93,    94,
      95,     0,    96,     0,     0,     0,   510,    98,    99,   511,
     512,     0,     0,     0,     0,     0,     0,   102,   103,   104,
       0,   106,   107,     0,     0,     0,     0,     0,     0,     0,
     114,   513,     0,     0,     0,     0,   116,   117,   118,   119,
     514,   121,   122,   515,     0,     0,     0,     0,     0,     0,
       0,   516,   517,   129,     0,     0,     0,   130,     0,   131,
     518,     0,     0,     0,     0,     0,     0,   136,     0,   137,
     138,   139,   140,   519,   142,   143,   144,   145,   146,   147,
       0,     0,     0,   149,     0,     0,   415,   152,   153,   154,
     155,   156,   157,   158,   159,   520,     0,   521,   163,   522,
     523,   166,   167,   168,   169,   170,   171,   524,   173,   525,
     526,   527,   177,   178,     0,   529,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,     0,
     194,   195,   196,     0,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,     0,     0,     0,     0,   246,   530,   248,   249,   250,
     251,   252
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   312,    13,   292,     4,     5,     6,     7,   180,     4,
       5,     6,   425,     4,     5,     6,     7,   423,   424,   260,
     674,   690,   784,     0,   110,   111,   341,     4,     5,     6,
       7,   261,   624,   625,   796,   675,   676,   677,   678,   827,
     764,   912,     4,     5,     6,     7,   276,   866,   810,  1056,
     925,   926,   465,   466,   589,  1040,   134,     1,  1308,  1291,
     595,  1080,   437,   253,   254,   764,     1,    74,  1372,  1373,
      40,  1497,   997,   448,  1500,    45,    46,   622,   623,   925,
     926,    37,  1130,   721,  1015,   622,   623,   624,   625,   947,
      60,  1405,    62,    63,    37,  1321,    56,   119,   473,   963,
      30,    71,    27,    28,     1,   653,   143,   655,   656,   109,
     658,     1,   660,     1,   122,    27,    28,   963,   109,   108,
     668,   669,  1600,    48,     1,     9,    10,     1,    98,   418,
     226,    30,   109,   422,     1,     1,    48,     1,     1,    95,
       8,    97,  1017,    94,    30,    57,   101,   109,    30,   108,
      75,   997,   283,  1667,    97,  1030,     1,    53,   244,   245,
     154,     0,     1,    75,   108,    27,    28,   154,    80,   119,
     154,  1017,     1,   108,  1728,  1729,    38,    39,   123,    41,
      42,    31,   149,   155,  1030,   157,    48,    25,   113,     0,
       1,   149,   148,   107,   178,    57,    58,    35,     1,   166,
     112,   113,   114,     1,   226,   148,   292,   969,   166,   154,
     157,   119,   157,    75,   128,   114,  1770,   211,    80,   315,
     104,   108,  1776,    61,   211,   111,   234,  1741,     1,   111,
     189,   161,   187,   184,   130,   148,  1540,   274,   188,   125,
     124,   108,   126,   125,     1,   108,     1,   236,     1,     1,
     112,   113,   114,   253,   254,   566,   226,   257,   218,  1130,
    1131,  1023,   161,   108,   150,   554,   344,  1029,   150,   108,
     154,    97,   154,  1751,   158,   157,   253,   254,  1510,   108,
     257,  1288,  1146,   875,   876,  1599,   308,  1513,  1076,  1274,
    1716,   175,   292,  1312,   191,   255,   178,   108,  1022,   161,
    1146,   191,  1321,   191,  1229,   108,     1,  1238,   176,     1,
     108,   949,   196,   444,   191,   292,     1,   191,   274,   732,
      74,  1020,   185,  1022,  1182,   191,   148,   191,   873,   874,
     214,   274,   418,  1381,    88,   108,   422,  1763,    97,  1765,
     185,     1,   349,  1042,   170,   352,   185,   234,   318,   319,
     320,   108,   641,   108,     1,   108,   108,   186,   112,   221,
     908,   274,    55,   288,    57,   215,   274,   453,   312,   782,
     124,   296,   126,   226,   185,   228,   288,   463,   260,   314,
     157,   622,   623,  1229,   296,   188,   472,   108,   186,   619,
     620,  1266,   304,   479,   480,    46,  1700,     1,   108,   629,
     262,    77,   488,   778,     1,   233,   781,   235,   101,    95,
     132,   108,    63,   108,   137,   188,   108,    95,   418,     1,
    1266,   611,   422,   108,     1,     1,   288,   253,   254,   107,
     256,   188,   264,   188,   296,   188,   188,   263,   226,   154,
     228,   418,   304,   275,  1290,   422,     1,   273,   108,   449,
    1754,   451,   274,    38,    39,    95,    41,    42,   449,   285,
     451,   108,   315,    27,    28,   143,  1228,   188,   554,   191,
     101,    97,   449,    58,   451,   108,     1,   477,   154,   202,
     101,   191,   482,     1,   570,   571,   477,   449,  1738,   451,
       1,   482,   189,   188,  1513,    95,   188,   583,   257,   258,
     477,   131,   264,   188,   108,   482,   912,   226,   148,    97,
    1381,   108,   231,   275,   108,   477,  1240,   603,   604,  1390,
     482,   157,   148,  1115,  1116,  1117,   108,   315,   188,   114,
    1401,   108,   108,   219,   220,  1354,   942,   188,  1413,  1358,
      46,   188,    48,   143,     9,    10,   222,   223,   234,   113,
    1249,  1783,   185,   108,   554,  1224,   187,   970,   971,   252,
     108,   561,   975,     9,    10,  1100,   187,  1413,   198,   155,
     561,   157,   265,     9,   267,   864,   161,   554,  1115,  1116,
    1117,   185,   170,   108,   561,   278,   279,   280,   185,   282,
     108,   284,  1005,    29,   188,   349,   315,   108,   352,   561,
       9,   107,   891,   185,   604,   691,   617,   119,   185,   185,
     696,   611,   108,   604,  1376,   108,   694,   695,    97,   154,
      29,   137,   622,   623,   624,   625,   187,   604,    95,    43,
     185,   108,   873,    47,   611,   151,   221,  1622,    52,   104,
     188,   641,   131,   178,    97,   622,   623,   624,   625,   879,
     211,  1497,   238,   883,  1500,   269,    70,   161,   104,   124,
     185,   126,   276,   169,   641,   253,   254,   185,   256,   148,
       9,    10,   119,   159,   185,   187,   430,   262,   124,   433,
     126,   108,   108,   437,   108,   273,   440,   441,   124,   154,
     126,   177,   188,   158,   448,   188,   108,   285,  1569,   135,
     454,   455,     5,     5,   157,   459,     9,     9,   154,   198,
     175,   188,   158,   467,   108,   124,   119,   126,   154,   473,
     474,   475,   476,  1511,  1130,  1131,   135,   481,  1516,   175,
    1737,   196,   818,   819,   820,   489,   822,  1461,  1392,    43,
     187,   159,    95,    47,   101,   154,   187,    95,    52,   214,
     196,    95,   219,   220,     1,   169,     3,   114,   172,   177,
    1635,   188,   188,   107,   188,   104,    70,   234,   214,  1361,
     211,    43,    30,   187,   774,    47,   188,  1446,   864,   774,
      52,   535,   200,   774,   270,   124,    97,   126,   157,  1635,
     143,   277,   157,   170,   188,   549,    95,   774,    70,   213,
      46,   287,    48,   114,   804,   805,   560,   155,  1683,   157,
    1685,    95,   774,   804,   805,   154,  1105,  1132,   118,   158,
      67,   124,   124,   126,   126,    72,   203,   804,   805,   123,
       1,   134,   134,    97,    80,   589,   175,  1683,     1,  1685,
     218,   595,   804,   805,   626,   599,   157,   147,   630,   148,
     114,   154,   154,   111,   138,   183,  1269,   196,  1646,   143,
     160,   107,  1650,    34,   864,   169,   145,   125,   172,   197,
    1716,    34,   119,  1748,   885,   214,  1106,   255,  1011,    50,
    1013,    54,  1112,   187,    54,   159,    59,   864,   123,    59,
      96,   891,   150,   157,   187,   195,   154,   169,   177,   157,
     172,   107,  1748,   177,   187,    78,  1560,  1561,   101,   213,
     187,   117,   187,  1553,   891,   187,   195,  1763,   211,  1765,
     178,   114,   128,   169,    97,   159,   200,    97,   211,   157,
    1063,   133,  1065,  1602,   211,    34,   211,  1109,  1700,   141,
     142,   213,   144,   177,  1732,   270,   119,   248,   249,    97,
     152,    50,   277,   167,   156,  1368,   158,   138,   183,   960,
     138,   163,   287,   233,   101,   235,   114,   101,   101,   183,
     271,   972,   197,   154,   728,  1381,   154,   114,   180,  1268,
     114,   114,   202,   101,  1390,   300,   154,   154,   742,   157,
     157,   211,   746,   747,   309,  1401,   114,   154,   154,   157,
     157,   157,   204,   205,   206,   207,   208,   209,   138,   278,
     279,   280,   157,   143,   768,   284,   770,  1671,  1672,   348,
     697,   157,   351,   700,   778,   138,   703,   781,   123,    54,
     143,   785,   192,   193,    59,   119,  1705,   222,   223,   224,
     129,   130,  1353,  1129,   129,   130,   681,   682,    74,   672,
     673,   679,   680,  1222,  1223,   123,  1590,  1591,  1058,   123,
     119,   123,    88,   123,   154,  1478,   154,  1058,   123,   123,
     123,   123,   826,   154,   217,   157,   119,   242,   242,   157,
     154,  1058,   243,  1752,   315,     0,   112,   191,   168,    93,
    1744,   250,   100,    51,   201,   102,  1058,   103,   124,   155,
     126,   194,   146,  1114,    30,  1105,   157,    48,   185,   185,
     185,   153,   866,   185,   119,  1115,  1116,  1117,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,  1105,   305,
     247,  1544,   285,   285,   119,   154,     1,   119,  1115,  1116,
    1117,   895,   188,   143,   108,   154,   157,   188,   143,   185,
     122,   154,   154,    36,    17,  1824,   157,  1826,   157,   157,
     157,   157,    30,  1569,   157,   157,   215,  1836,   188,   232,
     231,   925,   926,   927,   928,   191,   191,   246,  1350,     3,
     119,   169,   171,    71,   171,   232,    95,    95,    95,   150,
     108,   108,    30,   161,   161,   128,   133,   247,    95,   300,
     143,  1490,   133,   119,   185,   185,   108,    97,    95,   963,
     188,   188,    46,    97,   188,   188,   185,   188,   188,   154,
     185,    95,   154,   977,   154,   154,   154,   154,   238,   143,
      34,   191,  1232,   171,   119,   226,    95,  1232,   232,   133,
     143,  1232,    30,    95,  1533,   228,   128,   287,  1002,   154,
     234,    95,   300,   119,   199,  1232,   148,  1011,   119,  1013,
     185,  1015,   133,  1017,   133,   255,   161,    97,  1268,   119,
    1232,   148,   101,   154,   101,   185,  1030,   122,   154,  1279,
     191,   185,    36,   143,  1279,    30,   119,   154,  1279,   246,
      80,  1268,   108,   108,    30,   261,    30,   259,  1298,   157,
     286,   157,  1279,  1298,   157,   145,   157,  1298,   157,  1063,
     157,  1065,   268,    30,   157,   228,   191,  1279,  1318,   145,
     148,  1298,   128,   349,   188,  1325,   352,  1318,   287,   148,
     148,  1620,   307,   288,  1325,   119,  1298,   119,    78,   108,
     188,  1318,  1631,  1632,   143,  1634,  1100,   188,  1325,   188,
     185,   188,   188,  1642,   101,   133,  1318,  1357,     7,    97,
     191,   234,   234,  1325,   234,   187,  1357,   199,   157,   154,
     157,  1125,   234,   251,   157,   107,   188,   148,    79,   188,
    1357,   238,   283,   188,    30,   188,   188,   287,   188,    30,
     188,   188,  1146,   272,   108,   171,   251,   148,   148,   185,
     127,   127,    97,   429,   430,   185,   187,   433,   187,    95,
     187,   437,   258,   185,   440,   441,    30,   185,   185,   317,
     143,   185,   448,   154,    97,   188,   188,   281,   454,   455,
     171,    54,   148,   459,    95,   107,  1725,   198,    95,    30,
     108,   467,   108,   119,  1530,  1531,  1532,   473,   474,   475,
     476,   226,   266,    95,   119,   481,    95,   187,   187,   198,
     119,   198,    94,   489,   199,   288,   226,   119,   119,   184,
     198,   226,   119,  1185,   294,  1764,   187,   731,   200,   964,
     288,   306,   424,   257,  1238,   306,  1031,   257,  1242,   306,
    1490,   444,  1229,  1782,   307,   260,   307,   307,  1705,  1752,
     867,  1028,   787,  1257,  1377,   459,  1471,  1258,  1797,   535,
    1121,   549,  1266,  1490,  1375,  1372,  1280,  1285,  1288,  1293,
     651,   671,   928,   549,   652,   705,  1280,  1312,  1776,  1818,
     827,  1770,   452,  1533,   560,   336,  1290,  1013,  1827,  1184,
     452,  1355,  1344,  1390,  1354,  1401,  1569,  1131,  1394,  1566,
    1140,   996,  1207,  1436,  1593,  1391,  1533,    -1,   593,    -1,
      -1,    -1,    -1,    -1,    -1,  1319,    -1,    -1,   109,    -1,
      -1,    -1,    -1,   599,    -1,    -1,    -1,  1663,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1344,    -1,    -1,    -1,    -1,  1681,    -1,    -1,    -1,    -1,
    1354,    -1,    -1,    -1,  1358,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1620,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1631,  1632,    -1,  1634,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1642,  1620,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1631,  1632,    -1,  1634,    -1,  1413,
      -1,    -1,    -1,    -1,    -1,  1642,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1442,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   725,
      -1,    -1,   728,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1468,  1469,   742,    -1,    -1,    -1,
     746,   747,    -1,    -1,    -1,  1725,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1494,    -1,   768,  1497,   770,    -1,  1500,    -1,  1725,    -1,
      -1,    -1,   778,    -1,    -1,   781,    -1,    -1,  1512,   785,
      -1,    -1,    -1,  1517,  1764,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1782,    -1,    -1,    -1,    -1,  1764,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1797,    -1,    -1,
     826,    -1,    -1,    -1,    -1,  1782,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1818,    -1,
    1797,    -1,    -1,    -1,    -1,    -1,    -1,  1827,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     866,  1818,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1827,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   895,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1635,  1636,    -1,  1638,    -1,  1640,    -1,    -1,    -1,
      -1,    -1,    -1,  1647,    -1,    -1,    -1,    -1,    -1,   925,
     926,   927,   928,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1683,
      -1,  1685,    -1,    -1,    -1,    -1,    -1,   963,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1701,    -1,    -1,
    1704,   977,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1716,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1727,    -1,    -1,  1002,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1011,    -1,  1013,    -1,  1015,
      -1,  1017,    -1,    -1,  1748,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1756,    -1,  1030,    -1,    -1,  1761,    -1,  1763,
      -1,  1765,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     561,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1063,    -1,  1065,
    1794,    -1,    -1,    -1,    -1,    -1,   587,   588,    -1,    -1,
     591,   592,   593,   594,    -1,   596,    -1,    -1,    -1,    -1,
    1814,   602,    -1,    -1,    -1,  1819,    -1,    -1,    -1,   610,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1831,    -1,    -1,
    1834,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   632,   633,    -1,    -1,    -1,    -1,    -1,    -1,  1125,
     641,   642,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   702,    -1,    -1,   705,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   744,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1238,    -1,    -1,    -1,  1242,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1266,    -1,    -1,    -1,    -1,   786,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1280,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1290,    -1,    -1,    -1,    -1,    -1,
     811,    -1,    -1,    -1,   815,   816,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   824,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1319,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1344,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1354,    -1,
      -1,    -1,  1358,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     891,    -1,    -1,    -1,    -1,    -1,   897,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1413,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1442,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   965,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1468,  1469,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1000,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1494,    -1,
      -1,  1497,    -1,    -1,  1500,    -1,    -1,    -1,  1019,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1512,    -1,    -1,    -1,
      -1,  1517,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1041,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1052,  1053,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1067,    -1,    -1,  1070,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1087,  1088,  1089,    -1,
    1091,  1092,  1093,  1094,  1095,  1096,  1097,  1098,  1099,    -1,
      -1,  1102,  1103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1635,
    1636,    -1,  1638,    -1,  1640,    -1,    -1,    -1,    -1,    -1,
      -1,  1647,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1683,    -1,  1685,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1701,    -1,    -1,  1704,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1716,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1727,    -1,  1244,    -1,  1246,    -1,  1248,    -1,    -1,
    1251,    -1,    -1,    -1,    -1,  1256,    -1,    -1,    -1,    -1,
      -1,    -1,  1748,    -1,    -1,    -1,    -1,  1268,    -1,    -1,
    1756,    -1,    -1,    -1,    -1,  1761,  1277,  1763,    -1,  1765,
      -1,    -1,  1283,  1284,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1302,    -1,    -1,  1305,    -1,    -1,    -1,  1794,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1814,    -1,
      -1,    -1,    -1,  1819,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1831,    -1,    -1,  1834,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1375,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1455,    -1,    -1,    -1,  1459,    -1,
      -1,    -1,  1463,    -1,  1465,    -1,  1467,    -1,    -1,    -1,
      -1,    -1,  1473,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1481,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1489,  1490,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1509,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1521,  1522,  1523,  1524,    -1,  1526,  1527,    -1,  1529,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1545,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1608,    -1,  1610,
      -1,    -1,  1613,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1621,    -1,    -1,    -1,    -1,  1626,  1627,    -1,    -1,    -1,
      -1,    -1,    -1,  1634,    -1,    -1,    -1,    -1,  1639,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1656,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1668,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1708,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1721,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1764,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,
      -1,  1792,    -1,    -1,    -1,    -1,  1797,    -1,    11,    12,
      -1,  1802,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,  1817,    30,    -1,    -1,
    1821,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,   192,
     193,    -1,   195,    -1,   197,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,    -1,    -1,   212,
     213,   214,    -1,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,    -1,   260,   261,   262,
      -1,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,    -1,
     313,    -1,   315,   316,   317,   318,   319,   320,   321,     0,
       1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    98,    99,    -1,
     101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,
      -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,   140,
      -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,   157,   158,   159,   160,
     161,    -1,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,
     181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,
      -1,   192,   193,    -1,   195,    -1,   197,    -1,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,    -1,
      -1,   212,   213,   214,    -1,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,    -1,   260,
     261,   262,    -1,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,     1,   313,    -1,   315,   316,   317,   318,   319,   320,
     321,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    99,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,   177,   178,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,    -1,   192,   193,    -1,   195,    -1,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,   212,   213,   214,    -1,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
     260,   261,   262,    -1,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,     1,   313,    -1,   315,   316,   317,   318,   319,
     320,   321,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    98,
      99,    -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,
     129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,
     139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,   157,   158,
     159,   160,   161,    -1,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,   177,   178,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,   190,    -1,   192,   193,    -1,   195,    -1,   197,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,   212,   213,   214,    -1,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
      -1,   260,   261,   262,    -1,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,    -1,   313,    -1,   315,   316,   317,   318,
     319,   320,   321,     0,     1,    -1,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      47,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,    95,    96,
      97,    -1,    -1,   100,   101,   102,   103,    -1,    -1,    -1,
     107,   108,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,
     117,   118,   119,    -1,    -1,   122,    -1,    -1,    -1,    -1,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
     137,    -1,    -1,    -1,   141,   142,    -1,   144,    -1,   146,
     147,    -1,    -1,    -1,   151,   152,    -1,    -1,   155,   156,
     157,   158,   159,   160,    -1,    -1,   163,    -1,    -1,    -1,
      -1,   168,   169,    -1,    -1,   172,    -1,    -1,    -1,    -1,
     177,    -1,    -1,   180,    -1,    -1,    -1,    -1,   185,   186,
     187,   188,   189,    -1,   191,   192,   193,   194,   195,    -1,
      -1,    -1,    -1,   200,   201,   202,    -1,   204,   205,   206,
     207,   208,   209,    -1,   211,    -1,   213,    -1,    -1,    -1,
      -1,   218,   219,   220,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   234,    -1,   236,
      -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,   255,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,   312,    -1,   314,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    99,    -1,   101,   102,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,    -1,    -1,    -1,   125,
      -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,
     136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,
      -1,   147,   148,   149,   150,   151,   152,   153,   154,   155,
      -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,   175,
      -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,    -1,   192,   193,    -1,   195,
      -1,   197,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,   212,   213,   214,    -1,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    -1,   260,   261,   262,    -1,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,    -1,   313,    -1,   315,
     316,   317,   318,   319,   320,   321,   322,   323,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,   192,
     193,    -1,   195,    -1,   197,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,    -1,    -1,   212,
     213,   214,    -1,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,    -1,   260,   261,   262,
      -1,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,    -1,
     313,    -1,   315,   316,   317,   318,   319,   320,   321,    -1,
     323,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    99,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,   177,   178,    -1,
      -1,   181,   182,   183,    -1,   185,    -1,   187,    -1,   189,
     190,    -1,   192,   193,    -1,   195,    -1,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,   212,   213,   214,    -1,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
     260,   261,   262,    -1,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,    -1,   313,    -1,   315,   316,   317,   318,   319,
     320,   321,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    98,
      99,    -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,
     129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,
     139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,   157,   158,
     159,   160,   161,    -1,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,   177,   178,
      -1,    -1,   181,   182,   183,    -1,   185,    -1,   187,    -1,
     189,   190,    -1,   192,   193,    -1,   195,    -1,   197,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,   212,   213,   214,    -1,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
      -1,   260,   261,   262,    -1,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,    -1,   313,    -1,   315,   316,   317,   318,
     319,   320,   321,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    99,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    -1,    -1,    -1,   125,    -1,   127,
     128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,
     138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,   150,   151,   152,   153,   154,   155,    -1,   157,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,   175,    -1,   177,
     178,    -1,    -1,   181,   182,   183,    -1,   185,    -1,   187,
      -1,   189,   190,    -1,   192,   193,    -1,   195,    -1,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,    -1,   212,   213,   214,    -1,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    -1,   260,   261,   262,    -1,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,    -1,   313,    -1,   315,   316,   317,
     318,   319,   320,   321,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    96,
      97,    98,    99,    -1,   101,   102,   103,    -1,    -1,   106,
     107,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,   125,    -1,
     127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
     157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,   175,    -1,
     177,   178,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,
     187,    -1,   189,   190,    -1,   192,   193,    -1,   195,    -1,
     197,    -1,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,    -1,    -1,   212,   213,   214,    -1,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,   260,   261,   262,    -1,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,    -1,   313,    -1,   315,   316,
     317,   318,   319,   320,   321,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    99,    -1,   101,   102,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,    -1,    -1,    -1,   125,
      -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,
     136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,
      -1,   147,   148,   149,   150,   151,   152,   153,   154,   155,
      -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,   175,
      -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,    -1,   192,   193,    -1,   195,
      -1,   197,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,   212,   213,   214,    -1,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    -1,   260,   261,   262,    -1,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,    -1,   313,    -1,   315,
     316,   317,   318,   319,   320,   321,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      95,    96,    97,    98,    99,    -1,   101,   102,   103,    -1,
      -1,   106,   107,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
     175,    -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,
      -1,    -1,   187,    -1,   189,   190,    -1,   192,   193,    -1,
     195,    -1,   197,    -1,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,    -1,    -1,   212,   213,   214,
      -1,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,    -1,   260,   261,   262,    -1,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,    -1,   313,    -1,
     315,   316,   317,   318,   319,   320,   321,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    98,    99,    -1,   101,   102,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    -1,    -1,
      -1,   125,    -1,   127,   128,   129,   130,    -1,   132,    -1,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    -1,   157,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,    -1,   189,   190,    -1,   192,   193,
      -1,   195,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
     214,    -1,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,   260,   261,   262,    -1,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,    -1,   313,
      -1,   315,   316,   317,   318,   319,   320,   321,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,   192,
     193,    -1,   195,    -1,   197,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,    -1,    -1,   212,
     213,   214,    -1,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,    -1,   260,   261,   262,
      -1,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,    -1,
     313,    -1,   315,   316,   317,   318,   319,   320,   321,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    -1,
      -1,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    99,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
      -1,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,
     192,   193,    -1,   195,    -1,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
     212,   213,   214,    -1,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,   260,   261,
     262,    -1,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
      -1,   313,    -1,   315,   316,   317,   318,   319,   320,   321,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    98,    99,    -1,
     101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,
      -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,   140,
      -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,   157,   158,   159,   160,
     161,    -1,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,
     181,   182,   183,    -1,    -1,   186,   187,    -1,   189,   190,
      -1,   192,   193,    -1,   195,    -1,   197,    -1,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,    -1,
      -1,   212,   213,   214,    -1,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,    -1,   260,
     261,   262,    -1,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,    -1,   313,    -1,   315,   316,   317,   318,   319,   320,
     321,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    99,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,   177,   178,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,   188,   189,
     190,    -1,   192,   193,    -1,   195,    -1,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,   212,   213,   214,    -1,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
     260,   261,   262,    -1,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,    -1,   313,    -1,   315,   316,   317,   318,   319,
     320,   321,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    98,
      99,    -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,
     129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,
     139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,   157,   158,
     159,   160,   161,    -1,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,   177,   178,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,   190,    -1,   192,   193,    -1,   195,    -1,   197,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,   212,   213,   214,    -1,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
      -1,   260,   261,   262,    -1,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,    -1,   315,   316,   317,   318,
     319,   320,   321,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    99,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    -1,    -1,    -1,   125,    -1,   127,
     128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,
     138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,   150,   151,   152,   153,   154,   155,    -1,   157,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,   175,    -1,   177,
     178,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
      -1,   189,   190,    -1,   192,   193,    -1,   195,    -1,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,    -1,   212,   213,   214,    -1,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    -1,   260,   261,   262,    -1,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,    -1,   313,   314,   315,   316,   317,
     318,   319,   320,   321,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    96,
      97,    98,    99,    -1,   101,   102,   103,    -1,    -1,   106,
     107,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,   125,    -1,
     127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
     157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,   175,    -1,
     177,   178,    -1,    -1,   181,   182,   183,    -1,   185,    -1,
     187,    -1,   189,   190,    -1,   192,   193,    -1,   195,    -1,
     197,    -1,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,    -1,    -1,   212,   213,   214,    -1,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,   260,   261,   262,    -1,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,    -1,   313,    -1,   315,   316,
     317,   318,   319,   320,   321,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    99,    -1,   101,   102,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,    -1,    -1,    -1,   125,
      -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,
     136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,
      -1,   147,   148,   149,   150,   151,   152,   153,   154,   155,
      -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,   175,
      -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,   188,   189,   190,    -1,   192,   193,    -1,   195,
      -1,   197,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,   212,   213,   214,    -1,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    -1,   260,   261,   262,    -1,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,    -1,   313,    -1,   315,
     316,   317,   318,   319,   320,   321,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      95,    96,    97,    98,    99,    -1,   101,   102,   103,    -1,
      -1,   106,   107,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
     175,    -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,
      -1,    -1,   187,   188,   189,   190,    -1,   192,   193,    -1,
     195,    -1,   197,    -1,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,    -1,    -1,   212,   213,   214,
      -1,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,    -1,   260,   261,   262,    -1,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,    -1,   313,    -1,
     315,   316,   317,   318,   319,   320,   321,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    98,    99,    -1,   101,   102,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    -1,    -1,
      -1,   125,    -1,   127,   128,   129,   130,    -1,   132,    -1,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    -1,   157,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,    -1,   189,   190,    -1,   192,   193,
      -1,   195,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
     214,    -1,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,   260,   261,   262,    -1,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,    -1,   313,
      -1,   315,   316,   317,   318,   319,   320,   321,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,   192,
     193,    -1,   195,    -1,   197,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,    -1,    -1,   212,
     213,   214,    -1,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,    -1,   260,   261,   262,
      -1,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,    -1,
     313,    -1,   315,   316,   317,   318,   319,   320,   321,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    99,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
      -1,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,
     192,   193,    -1,   195,    -1,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
     212,   213,   214,    -1,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,   260,   261,
     262,    -1,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
      -1,   313,    -1,   315,   316,   317,   318,   319,   320,   321,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    98,    99,    -1,
     101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,
      -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,   140,
      -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,   157,   158,    -1,   160,
     161,    -1,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,   175,    -1,    -1,    -1,    -1,    -1,
     181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,
      -1,   192,   193,    -1,   195,    -1,   197,    -1,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,    -1,
      -1,   212,   213,   214,    -1,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,    -1,   260,
     261,   262,    -1,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,    -1,   313,    -1,   315,   316,   317,   318,   319,   320,
     321,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    99,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,   157,   158,    -1,
     160,   161,    -1,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,    -1,    -1,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,   212,   213,   214,    -1,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
     260,   261,   262,    -1,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,    -1,   313,    -1,   315,   316,   317,   318,   319,
     320,   321,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    98,
      99,    -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,
     129,   130,    -1,   132,    -1,    -1,    -1,   136,    -1,   138,
     139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,
     149,   150,    -1,   152,   153,   154,   155,    -1,   157,   158,
      -1,   160,   161,    -1,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,    -1,    -1,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,   197,    -1,
     199,    -1,   201,    -1,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,   212,   213,   214,    -1,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
      -1,   260,   261,   262,    -1,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,    -1,   313,    -1,   315,   316,   317,   318,
     319,   320,   321,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,
     138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,    -1,   151,   152,   153,    -1,    -1,    -1,    -1,
      -1,    -1,   160,   161,    -1,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
      -1,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,    -1,   212,   213,    -1,    -1,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    -1,   260,   261,   262,    -1,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,    -1,    -1,    11,    12,   315,   316,   317,
     318,   319,   320,   321,    20,    -1,    -1,    -1,    -1,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    -1,    -1,   101,   102,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,
     136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,
      -1,   147,   148,   149,    -1,   151,   152,   153,    -1,    -1,
      -1,    -1,    -1,    -1,   160,   161,    -1,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,   197,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,   212,   213,    -1,    -1,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    -1,   260,   261,   262,    -1,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,    -1,    16,    -1,   315,
     316,   317,   318,   319,   320,   321,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    98,
      -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,
     129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,
     139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,
     149,    -1,   151,   152,   153,    -1,    -1,    -1,    -1,    -1,
      -1,   160,   161,    -1,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,   212,   213,    -1,    -1,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
      -1,   260,   261,   262,    -1,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,    -1,    -1,    16,    -1,   315,   316,   317,   318,
     319,   320,   321,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,    -1,   151,
     152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,
      -1,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,
      -1,    -1,    -1,    -1,    -1,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
     212,   213,    -1,    -1,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,   260,   261,
     262,    -1,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
      -1,    -1,    -1,   315,   316,   317,   318,   319,   320,   321,
      18,    19,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,
     138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,    -1,   151,   152,   153,    -1,    -1,    -1,    -1,
      -1,    -1,   160,   161,    -1,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
      -1,   189,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,    -1,   212,   213,    -1,    -1,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    -1,   260,   261,   262,    -1,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,    -1,    -1,    -1,    -1,   315,   316,   317,
     318,   319,   320,   321,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    96,
      97,    98,    -1,    -1,   101,   102,   103,    -1,    -1,   106,
     107,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    -1,    -1,    -1,    -1,   125,    -1,
     127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
     157,   158,    -1,   160,   161,    -1,    -1,    -1,    -1,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,   175,    -1,
      -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,
     187,    -1,   189,   190,    -1,    -1,    -1,    -1,    -1,    -1,
     197,    -1,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,    -1,    -1,   212,   213,   214,    -1,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,   260,   261,   262,    -1,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,    -1,   313,    -1,   315,   316,
     317,   318,   319,   320,   321,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    -1,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
      -1,   151,   152,   153,    -1,    -1,    -1,   157,    -1,    -1,
     160,   161,    -1,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,   212,   213,    -1,    -1,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
     260,   261,   262,    -1,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,    -1,    -1,    25,    26,   315,   316,   317,   318,   319,
     320,   321,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,    -1,   151,
     152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,
      -1,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
     212,   213,    -1,    -1,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,   260,   261,
     262,    -1,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
      -1,    25,    26,   315,   316,   317,   318,   319,   320,   321,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    98,    -1,    -1,   101,   102,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,   128,   129,   130,    -1,   132,    -1,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,    -1,   151,   152,   153,
      -1,    -1,    -1,    -1,    -1,    -1,   160,   161,    -1,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
      -1,    -1,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,   260,   261,   262,    -1,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,    -1,    -1,    25,
      26,   315,   316,   317,   318,   319,   320,   321,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    -1,    -1,   101,   102,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,
     136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,
      -1,   147,   148,   149,    -1,   151,   152,   153,    -1,    -1,
      -1,   157,    -1,    -1,   160,   161,    -1,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,    -1,    -1,    -1,    -1,    -1,
      -1,   197,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,   212,   213,    -1,    -1,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    -1,   260,   261,   262,    -1,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,    -1,    25,    26,   315,
     316,   317,   318,   319,   320,   321,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,
     138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,    -1,   151,   152,   153,    -1,    -1,    -1,   157,
      -1,    -1,   160,   161,    -1,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
      -1,   189,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,    -1,   212,   213,    -1,    -1,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    -1,   260,   261,   262,    -1,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,    -1,    -1,    25,    26,   315,   316,   317,
     318,   319,   320,   321,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    -1,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
      -1,   151,   152,   153,    -1,    -1,    -1,   157,    -1,    -1,
     160,   161,    -1,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,   212,   213,    -1,    -1,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
     260,   261,   262,    -1,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,    -1,    -1,    25,    26,   315,   316,   317,   318,   319,
     320,   321,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,    -1,   151,
     152,   153,    -1,    -1,    -1,   157,    -1,    -1,   160,   161,
      -1,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,
      -1,    -1,    -1,    -1,    -1,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
     212,   213,    -1,    -1,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,   260,   261,
     262,    -1,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
      -1,    25,    26,   315,   316,   317,   318,   319,   320,   321,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    98,    -1,    -1,   101,   102,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,   128,   129,   130,    -1,   132,    -1,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,    -1,   151,   152,   153,
      -1,    -1,    -1,   157,    -1,    -1,   160,   161,    -1,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,    -1,   189,   190,    -1,    -1,    -1,
      -1,    -1,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
      -1,    -1,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,   260,   261,   262,    -1,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,    -1,    -1,    25,
      26,   315,   316,   317,   318,   319,   320,   321,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    -1,    -1,   101,   102,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,
     136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,
      -1,   147,   148,   149,    -1,   151,   152,   153,    -1,    -1,
      -1,    -1,    -1,    -1,   160,   161,    -1,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,    -1,    -1,    -1,    -1,    -1,
      -1,   197,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,   212,   213,    -1,    -1,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    -1,   260,   261,   262,    -1,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,    -1,    25,    26,   315,
     316,   317,   318,   319,   320,   321,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,
     138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,    -1,   151,   152,   153,    -1,    -1,    -1,    -1,
      -1,    -1,   160,   161,    -1,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
      -1,   189,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,    -1,   212,   213,    -1,    -1,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    -1,   260,   261,   262,    -1,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,    -1,    -1,    25,    26,   315,   316,   317,
     318,   319,   320,   321,    34,    35,    -1,    37,    38,    39,
      -1,    41,    42,    43,    44,    -1,    -1,    47,    48,    -1,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      -1,    61,    -1,    -1,    64,    65,    66,    67,    68,    -1,
      70,    -1,    72,    -1,    -1,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    -1,    -1,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
      -1,   151,   152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     160,   161,    -1,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,    -1,   213,    -1,    -1,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
     260,   261,   262,    -1,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,    -1,    -1,    -1,    -1,   315,   316,   317,   318,   319,
     320,   321
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    11,    12,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    30,    34,    35,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      95,    96,    97,    98,    99,   101,   102,   103,   106,   107,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   125,   127,   128,   129,   130,   132,   136,   137,   138,
     139,   140,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   157,   158,   159,   160,   161,   166,   167,   168,   169,
     170,   171,   172,   173,   175,   177,   178,   181,   182,   183,
     187,   189,   190,   192,   193,   195,   197,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   212,   213,
     214,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   260,   261,   262,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   313,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   336,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   357,   358,   359,   360,   361,   362,   366,
     367,   368,   372,   374,   375,   377,   384,   386,   389,   390,
     391,   393,   394,   395,   396,   397,   399,   400,   402,   403,
     404,   405,   406,   407,   409,   410,   413,   414,   415,   416,
     421,   423,   425,   426,   431,   450,   453,   457,   460,   461,
     467,   468,   469,   470,   472,   473,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   485,   486,   487,   488,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   521,   522,   523,   537,
     538,   540,   541,   542,   543,   544,   545,   546,   547,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   567,
     568,   569,   570,   575,   576,   577,   578,   579,   580,   583,
     641,   642,   643,   644,   646,   647,   648,   649,   650,   657,
     658,   659,    34,    35,    50,   216,   392,   393,   394,   392,
     392,   393,   394,   157,   157,    38,    39,    41,    42,    48,
      57,    58,    75,    80,   112,   113,   114,   161,   221,   262,
     288,   296,   304,   373,   374,   378,   379,   380,   161,   154,
     157,   154,   157,   154,   157,     1,     3,    67,    72,   119,
     418,   157,   381,   157,    25,    35,    61,   119,   274,   430,
     432,   433,   154,   157,   157,   157,   119,   154,   157,   157,
     157,    77,   154,   222,   223,   123,   123,   123,   154,   157,
      40,    44,    46,    47,    48,    49,    52,    60,    68,    71,
      73,    74,    76,    91,    92,    98,   106,   113,   115,   116,
     136,   139,   140,   161,   170,   173,   181,   182,   190,   203,
     225,   227,   229,   230,   237,   239,   240,   241,   244,   245,
     316,   505,   657,   658,   123,   119,   401,   123,   123,    40,
      45,    46,    60,    62,    63,    71,    98,   226,   657,   119,
     123,   123,   185,   392,   394,   414,   645,    49,    73,    74,
     119,   154,   186,   245,   413,   415,   425,   188,   413,   657,
     154,   154,   123,    16,   656,   657,    18,    19,   657,   123,
     123,   123,   497,   154,    31,   215,   217,   226,   228,   315,
     157,   226,   228,   315,   226,   315,   226,   231,   315,   119,
     242,   242,   243,   157,   154,   396,   312,   413,   314,   413,
     315,   323,   338,   338,     0,   340,   341,    34,    50,   343,
     360,     1,   191,   337,   191,   337,   113,   375,   395,   413,
     108,   191,   108,   337,   191,    43,    47,    52,    70,   169,
     172,   187,   213,   408,   417,   422,   423,   424,   438,   439,
     443,   168,    93,   133,   141,   142,   144,   152,   156,   158,
     163,   180,   204,   205,   206,   207,   208,   209,   489,   490,
     250,   100,   159,   177,   200,   118,   147,   160,   195,   202,
     211,   137,   151,    51,   201,   102,   103,   159,   177,   487,
     194,   154,   494,   497,   192,   193,   155,   509,   510,   505,
     509,   505,   157,   509,   146,   157,   185,   185,   185,   185,
     376,   512,   376,    30,   655,   183,   197,   183,   197,   167,
     183,   658,   657,   170,   203,    48,   657,   153,   119,    46,
      48,    80,   107,   169,   656,   222,   223,   224,   247,   614,
     657,   657,   305,   138,   143,   113,   288,   296,   378,   656,
     393,   188,   393,    46,    63,   188,   563,   564,   413,   188,
     195,   657,   427,   428,   657,   285,   285,   427,   119,   434,
     119,   188,   382,   383,   154,   398,   413,     1,   161,   655,
     114,   161,   356,   655,   657,   119,   143,   108,   413,    30,
     188,   656,   657,   657,   451,   452,   657,   393,   188,   413,
     413,   565,   657,   393,   154,   154,   413,   188,   195,   657,
     657,   143,   451,   185,   185,   122,   108,   185,   157,   157,
     157,   657,   154,   186,   187,   188,    36,   525,   526,   527,
     413,   413,     8,   176,    17,   413,   215,    30,   414,   414,
      40,    46,    60,    71,    98,   508,   657,   188,   414,   414,
     414,   645,   414,   508,   414,   232,   231,   581,   582,   657,
     191,   191,   414,   413,   394,   413,   246,   411,   412,   312,
     314,   414,   338,   191,   337,   191,   337,     3,   344,   360,
     390,     1,   344,   360,   390,    34,   361,   390,   361,   390,
     401,   337,   401,   414,   414,   119,   169,   171,   171,   395,
     414,   414,   469,   470,   472,   472,   472,   472,   471,   472,
     472,   472,    71,   473,   477,   477,   476,   478,   478,   478,
     478,   479,   479,   480,   480,   232,    95,    95,    95,   495,
     185,   413,   497,   497,   413,   510,   188,   414,   520,   150,
     188,   520,   108,   188,   188,   108,   108,   381,    30,   658,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
     363,   364,   365,    95,   138,   143,   369,   370,   371,   657,
     161,   161,   363,   655,   128,   133,    55,    57,   101,   252,
     265,   267,   278,   279,   280,   282,   284,   615,   616,   617,
     618,   619,   620,   627,   633,   634,   247,    95,   300,   657,
     143,   414,   119,   657,   657,   133,   185,   185,   188,   188,
     185,   108,   188,   108,   188,   108,    37,    95,    97,   148,
     429,   430,   548,   657,    56,   218,   255,   419,   420,   657,
      95,   108,   188,   392,   188,   656,    97,    46,   656,   655,
      97,   143,   548,   657,   414,   433,   185,   188,   188,   188,
     188,   108,   189,   148,   548,   185,   188,   188,   154,   185,
     393,   393,   185,   108,   188,   108,   188,   143,   548,   414,
     189,   414,   414,   413,   413,   413,   657,   526,   527,   131,
     198,   185,   185,   185,   132,   191,    95,   219,   220,   234,
      95,   219,   220,   234,   234,   234,    95,    95,   238,   226,
     232,   108,   236,   143,   191,   188,   413,   185,   506,   587,
     412,   234,   360,    34,    34,   191,   337,   191,   114,   395,
     657,   171,   414,   444,   445,   119,   440,   441,   472,   154,
     157,   260,   493,   512,   588,   591,   592,   593,   594,   595,
     599,   601,   603,   604,    48,   153,   157,   212,   318,   319,
     320,   321,   549,   551,   553,   555,   571,   572,   573,   574,
     651,   652,   653,   654,   657,   549,   484,   554,   657,   484,
     185,   186,   108,   188,   188,   512,   149,   166,   149,   166,
     138,   398,   381,   364,   133,   551,   371,   414,   548,   655,
     655,   129,   130,   655,   278,   279,   280,   284,   657,   264,
     275,   264,   275,    30,   287,    97,   114,   157,   621,   624,
     615,    40,    45,    60,    62,    71,    98,   226,   318,   319,
     320,   385,   555,   651,   228,   300,   309,   414,   657,    95,
     300,   655,   154,   565,   566,   657,   565,   566,   119,   428,
     128,   549,   119,   414,   148,   430,   148,    37,   148,   429,
     430,   148,   548,   255,    54,    59,    78,   119,   429,   435,
     436,   437,   420,   548,   549,   383,    95,   185,   199,   133,
     355,   655,   161,   133,    97,   355,   414,   143,   430,   154,
     119,   414,   414,   148,   101,   454,   455,   456,   458,   459,
     101,   462,   463,   464,   465,   393,   185,   185,   154,   565,
     565,   414,   143,   191,   414,   122,   188,   188,   188,    36,
     527,   131,   198,     9,    10,   104,   124,   126,   154,   196,
     522,   524,   535,   536,   539,   154,    30,   233,   235,   414,
     414,   414,   233,   235,   414,   414,   414,   414,   414,   414,
     414,   414,   414,   508,   119,   414,   414,    49,    73,    74,
     245,   395,   415,   425,   246,   584,   585,   154,   211,   396,
     414,   191,   114,   390,   390,   390,   444,    96,   107,   117,
     128,   446,   447,   448,   449,   108,   657,   108,   413,   588,
     595,   154,   286,   474,   640,    97,   170,   253,   254,   256,
     263,   273,   285,   589,   590,   609,   610,   611,   612,   635,
     638,   259,   261,   596,   614,   268,   600,   636,   248,   249,
     271,   605,   606,   157,   157,   551,   157,   157,   157,   157,
     157,   145,   177,   195,   550,   145,   414,   138,   398,   567,
     370,   287,    30,    97,   114,   157,   628,    30,   621,   550,
     550,   495,   288,   307,   548,   385,   228,   191,   392,   188,
     188,   145,   188,   188,   428,   148,   429,   657,   414,   148,
     414,   128,   414,   148,   430,   148,   414,   148,   119,   119,
     414,   657,   437,    78,   549,   395,   414,   655,   108,   355,
     414,   143,   392,   452,   414,   414,   114,   455,   456,   101,
     187,   114,   456,   459,   119,   466,   549,   101,   114,   463,
     101,   114,   465,   185,   392,   188,   188,   414,   414,   199,
     462,   133,   196,   524,     7,   393,   657,   196,   535,   393,
     191,   234,   234,   234,   234,    97,   238,   238,   582,   187,
     157,   157,   157,   187,   587,   585,   506,   655,   129,   130,
     448,   449,   449,   445,   107,   143,   442,   548,   441,   185,
     188,   588,   602,   251,   218,   255,   269,   276,   639,    97,
     257,   258,   637,   251,   592,   639,   476,   609,   593,   148,
     283,   597,   598,   637,   287,   608,    79,   607,   188,   195,
     549,   552,   188,   188,   188,   188,   188,   188,   188,    30,
     137,   202,   630,   631,   632,    30,   629,   630,   272,   625,
     108,   622,   171,   657,   258,   495,   185,   414,   148,   414,
     148,   429,   414,   148,   414,   414,   657,   657,   436,   414,
     127,   127,    97,   655,   414,   185,   187,   187,   414,   395,
     414,   187,   187,   657,   187,   211,   119,   466,   119,   187,
     119,   466,   187,   185,   114,   527,   657,   196,   185,   527,
     657,   185,   414,   414,   414,   414,   317,   414,   414,   414,
     413,   413,   413,   154,   586,   449,   655,   414,   143,   185,
     478,    53,   130,   476,   476,   270,   277,   287,   613,   613,
     594,   154,   281,    95,   188,   108,   188,   628,   628,   632,
     108,   188,    30,   626,   637,   623,   624,   188,   387,   388,
     495,   119,   226,   308,   288,   171,   414,   414,   148,   414,
      54,   395,   414,   355,   414,   395,    95,   395,   414,   549,
     657,   187,   657,   414,   657,   187,   395,   119,    94,   184,
     528,   527,   657,   198,   527,   414,   188,   188,   188,   413,
     442,   414,   476,   476,   200,   413,   549,   549,    95,    30,
     266,   108,   108,   449,   548,   657,   119,   226,   657,   387,
     414,   119,   466,    95,   187,    95,   657,     5,   134,   531,
     532,   534,   536,    29,   135,   529,   530,   533,   536,   198,
     527,   198,   199,   462,   185,   442,   476,   185,   549,   624,
     388,   449,   306,   657,   119,   226,   657,   187,   466,   395,
     414,   466,   187,    94,   134,   534,   184,   135,   533,   198,
     114,   414,   306,   657,   119,   395,   414,   187,   187,   119,
     294,   306,   657,   657,   307,   414,   307,   187,   495,   495,
     200,   288,   657,   226,   119,   657,   307,   495
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
     585,   586,   587,   588,   589
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   335,   336,   336,   336,   336,   337,   337,   337,   338,
     338,   338,   338,   339,   339,   340,   340,   340,   340,   340,
     340,   340,   340,   341,   341,   341,   341,   342,   343,   343,
     343,   344,   344,   344,   344,   344,   345,   345,   345,   345,
     345,   345,   345,   345,   346,   346,   347,   348,   349,   349,
     350,   350,   351,   351,   352,   352,   352,   352,   353,   353,
     353,   354,   354,   354,   354,   355,   355,   356,   356,   357,
     357,   357,   357,   358,   359,   359,   360,   360,   360,   361,
     361,   361,   361,   361,   361,   361,   361,   362,   362,   363,
     363,   364,   365,   365,   365,   365,   365,   365,   365,   365,
     365,   365,   366,   367,   368,   369,   369,   370,   370,   370,
     371,   372,   372,   372,   373,   373,   373,   373,   374,   374,
     375,   375,   375,   375,   376,   376,   377,   377,   378,   378,
     379,   379,   380,   380,   381,   381,   381,   381,   382,   382,
     383,   383,   384,   384,   384,   384,   385,   385,   385,   385,
     386,   386,   387,   387,   388,   388,   388,   388,   389,   389,
     389,   389,   390,   391,   391,   391,   392,   392,   392,   393,
     393,   394,   394,   394,   395,   395,   395,   395,   395,   395,
     395,   395,   395,   395,   395,   395,   396,   396,   397,   398,
     399,   400,   400,   400,   401,   401,   401,   401,   402,   403,
     404,   405,   406,   406,   407,   408,   409,   410,   411,   411,
     412,   413,   413,   413,   414,   414,   414,   414,   414,   414,
     415,   415,   415,   415,   415,   415,   415,   415,   415,   415,
     415,   415,   416,   417,   418,   418,   419,   419,   419,   420,
     420,   421,   421,   422,   423,   423,   423,   424,   424,   424,
     424,   424,   425,   425,   426,   426,   426,   427,   427,   427,
     428,   428,   428,   428,   428,   428,   428,   428,   428,   428,
     428,   428,   429,   430,   431,   432,   432,   433,   433,   433,
     433,   434,   434,   435,   435,   435,   436,   436,   436,   437,
     437,   437,   438,   439,   440,   440,   441,   441,   441,   441,
     441,   441,   442,   443,   443,   444,   444,   445,   445,   446,
     446,   446,   446,   446,   446,   446,   447,   447,   448,   448,
     449,   450,   450,   451,   451,   452,   452,   453,   454,   454,
     455,   456,   456,   457,   458,   458,   459,   460,   460,   461,
     461,   462,   462,   463,   463,   464,   464,   465,   465,   466,
     466,   467,   468,   468,   469,   469,   470,   470,   470,   470,
     470,   471,   470,   470,   470,   470,   472,   472,   473,   473,
     474,   474,   475,   475,   476,   476,   476,   477,   477,   477,
     477,   477,   478,   478,   478,   479,   479,   479,   480,   480,
     481,   481,   482,   482,   483,   483,   484,   484,   485,   485,
     486,   486,   486,   486,   487,   487,   487,   488,   488,   489,
     489,   489,   489,   489,   489,   490,   490,   490,   491,   491,
     491,   491,   492,   492,   493,   493,   494,   494,   494,   495,
     495,   495,   495,   496,   497,   497,   497,   498,   498,   499,
     499,   499,   499,   500,   500,   501,   501,   501,   501,   501,
     501,   501,   502,   502,   503,   503,   504,   504,   504,   504,
     504,   505,   505,   506,   506,   507,   507,   507,   507,   508,
     508,   508,   508,   509,   509,   510,   511,   511,   511,   511,
     511,   511,   511,   511,   511,   511,   511,   511,   511,   511,
     512,   512,   513,   513,   513,   514,   515,   515,   516,   517,
     518,   519,   519,   520,   520,   521,   521,   522,   522,   522,
     523,   523,   523,   523,   523,   523,   524,   524,   525,   525,
     526,   527,   527,   528,   528,   529,   529,   530,   530,   530,
     530,   531,   531,   532,   532,   532,   532,   533,   533,   534,
     534,   535,   535,   535,   535,   536,   536,   536,   536,   537,
     537,   538,   538,   539,   540,   540,   540,   540,   540,   540,
     540,   541,   542,   542,   543,   543,   544,   545,   546,   546,
     547,   547,   548,   549,   549,   549,   550,   550,   550,   551,
     551,   551,   551,   551,   551,   551,   552,   552,   553,   554,
     555,   555,   555,   555,   555,   555,   555,   555,   555,   556,
     557,   557,   557,   558,   559,   560,   560,   560,   561,   561,
     561,   561,   561,   562,   563,   563,   563,   563,   563,   563,
     563,   564,   565,   566,   567,   568,   568,   569,   570,   571,
     571,   572,   573,   573,   574,   575,   575,   575,   576,   576,
     576,   576,   576,   576,   576,   576,   576,   576,   577,   577,
     578,   578,   579,   580,   581,   581,   582,   583,   584,   584,
     585,   586,   587,   587,   588,   589,   589,   590,   590,   591,
     591,   592,   592,   593,   593,   594,   594,   595,   596,   596,
     597,   597,   598,   599,   599,   599,   600,   600,   601,   602,
     602,   603,   604,   604,   605,   605,   606,   606,   606,   607,
     607,   608,   608,   609,   609,   609,   609,   609,   610,   611,
     612,   613,   613,   613,   614,   614,   615,   615,   615,   615,
     615,   615,   615,   615,   616,   616,   616,   616,   617,   617,
     618,   619,   619,   620,   620,   620,   621,   621,   622,   622,
     623,   623,   624,   625,   625,   626,   626,   627,   627,   627,
     628,   628,   629,   629,   630,   630,   631,   631,   632,   632,
     633,   634,   634,   635,   635,   635,   636,   637,   637,   637,
     637,   638,   638,   639,   639,   640,   641,   641,   642,   642,
     643,   643,   644,   645,   645,   646,   646,   646,   647,   648,
     649,   650,   651,   651,   651,   652,   653,   654,   655,   656,
     656,   657,   657,   657,   657,   657,   657,   657,   657,   657,
     657,   657,   657,   657,   657,   657,   657,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   659
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
       4,     8,     5,     9,     9,    10,     1,     2,     1,     2,
       6,     0,     1,     3,     3,     0,     1,     1,     1,     2,
       2,     0,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       2,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     4,     3,     7,     3,     7,     4,     4,     3,     7,
       3,     7,     2,     1,     2,     3,     1,     1,     1,     1,
       1,     3,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     4,     4,     3,     3,     3,     4,     4,     3,     4,
       6,     4,     6,     4,     3,     4,     6,     6,     4,     6,
       6,     4,     1,     2,     1,     1,     1,     3,     3,     1,
       1,     4,     5,     6,     3,     3,     3,     3,     5,     7,
       7,     5,     5,     5,     7,     7,     5,     5,     3,     3,
       5,     7,     5,     7,     1,     4,     3,     5,     1,     2,
       3,     3,     1,     3,     2,     0,     1,     1,     2,     1,
       3,     1,     3,     1,     4,     1,     2,     3,     0,     1,
       0,     1,     4,     2,     3,     1,     0,     1,     4,     0,
       1,     2,     1,     3,     0,     1,     2,     2,     1,     0,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     1,     1,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     2,     2,
       3,     1,     2,     2,     5,     2,     1,     1,     0,     2,
       1,     3,     4,     0,     2,     0,     2,     4,     4,     3,
       2,     3,     1,     3,     0,     1,     1,     2,     2,     2,
       2,     1,     2,     2,     2,     2,     3,     2,     3,     3,
       4,     2,     2,     1,     1,     3,     2,     3,     2,     3,
       2,     3,     3,     3,     5,     5,     5,     8,     5,     3,
       5,     7,     1,     1,     1,     3,     3,     3,     1,     1,
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
       1,     1,     1,     1
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
  "\"'processing-instruction NCName {'\"", "\"'namespace NCName {'\"",
  "\"'QName'\"", "\"'EQName'\"", "\"'%QName'\"", "\"'%EQName'\"",
  "\"'quote attribute content'\"", "\"'STRING'\"", "\"'XML comment'\"",
  "\"'URI'\"", "\"'NCName'\"", "\"'declare'\"", "\"'module'\"",
  "\"'<blank>'\"", "\"'allowing'\"", "\"'base-uri'\"",
  "\"'boundary-space'\"", "\"'comment'\"", "\"'construction'\"",
  "\"'copy-namespaces'\"", "\"'count'\"", "\"'document'\"",
  "\"'document-node'\"", "\"'element'\"", "\"'for'\"", "\"'function'\"",
  "\"'if'\"", "\"'import'\"", "\"'instance'\"", "\"'let'\"", "\"'most'\"",
  "\"'next'\"", "\"'no'\"", "\"'only'\"", "\"'option'\"", "\"'ordering'\"",
  "\"'previous'\"", "\"'processing-instruction'\"", "\"'schema'\"",
  "\"'schema-attribute'\"", "\"'schema-element'\"", "\"'sequential'\"",
  "\"'set'\"", "\"'simple'\"", "\"'sliding'\"", "\"'some'\"",
  "\"'space'\"", "\"'stable'\"", "\"'text'\"", "\"'tumbling'\"",
  "\"'switch'\"", "\"'typeswitch'\"", "\"'updating'\"", "\"'validate'\"",
  "\"'type'\"", "\"'when'\"", "\"'word'\"", "\"'decimal-format'\"",
  "\"'decimal-separator'\"", "\"'grouping-separator'\"", "\"'infinity'\"",
  "\"'minus-sign'\"", "\"'NaN'\"", "\"'percent'\"", "\"'per-mille'\"",
  "\"'zero-digit'\"", "\"'digit'\"", "\"'pattern-separator'\"",
  "\"'ancestor'\"", "\"'ancestor-or-self'\"", "\"'and'\"", "\"'''\"",
  "\"'as'\"", "\"'ascending'\"", "\"'at'\"", "\"'attribute'\"", "\"'@'\"",
  "\"'||'\"", "\"'case'\"", "\"'castable'\"", "\"'cast'\"",
  "\"'CDATA[['\"", "\"']]'\"", "\"'child'\"", "\"'collation'\"", "\"','\"",
  "\"'(:'\"", "\"':)'\"", "\"'DECIMAL'\"", "\"'context'\"",
  "\"'variable'\"", "\"'default'\"", "\"'descendant'\"",
  "\"'descendant-or-self'\"", "\"'descending'\"", "\"'div'\"", "\"'$'\"",
  "\"'.'\"", "\"'..'\"", "\"':'\"", "\"'::'\"", "\"'{{'\"", "\"'DOUBLE'\"",
  "\"'<double {>'\"", "\"'else'\"", "\"'empty'\"", "\"'greatest'\"",
  "\"'least'\"", "\"'/>'\"", "\"'encoding'\"", "\"'='\"", "\"''''\"",
  "\"'\\\"\\\"'\"", "\"'every'\"", "\"'except'\"", "\"'external'\"",
  "\"'following'\"", "\"'following-sibling'\"", "\"'follows'\"",
  "\"'>='\"", "\"':='\"", "\"'>'\"", "\"'?'\"", "\"'#'\"", "\"'idiv'\"",
  "\"'in'\"", "\"'inherit'\"", "\"'INTEGER'\"", "\"'intersect'\"",
  "\"'is'\"", "\"'item'\"", "\"'{'\"", "\"'['\"", "\"'<='\"", "\"'('\"",
  "\"'<'\"", "\"'-'\"", "\"'mod'\"", "\"'namespace'\"", "\"'nan'\"",
  "\"'!='\"", "\"'nodecomp'\"", "\"'?""?'\"", "\"'<no inherit>'\"",
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
  "CompCommentConstructor", "CompPIConstructor",
  "CompNamespaceConstructor", "TypeDeclaration", "SequenceType",
  "OccurrenceIndicator", "ItemType", "TypeList", "GeneralizedAtomicType",
  "SimpleType", "KindTest", "AnyKindTest", "DocumentTest", "TextTest",
  "CommentTest", "PITest", "AttributeTest", "SchemaAttributeTest",
  "ElementTest", "SchemaElementTest", "TypeName", "TypeName_WITH_HOOK",
  "StringLiteral", "FunctionItemExpr", "LiteralFunctionItem",
  "InlineFunction", "FunctionTest", "AnyFunctionTest", "TypedFunctionTest",
  "ParenthesizedItemType", "RevalidationDecl", "InsertExpr", "DeleteExpr",
  "ReplaceExpr", "RenameExpr", "TransformExpr", "VarNameList",
  "VarNameDecl", "TryExpr", "CatchListExpr", "CatchExpr", "BracedExpr",
  "NameTestList", "FTSelection", "opt_FTPosFilter_list",
  "FTPosFilter_list", "FTOr", "FTAnd", "FTMildNot", "FTUnaryNot",
  "FTPrimaryWithOptions", "opt_FTMatchOptions", "opt_FTWeight", "FTWeight",
  "FTPrimary", "opt_FTTimes", "FTExtensionSelection", "opt_FTSelection",
  "FTWords", "FTWordsValue", "opt_FTAnyallOption", "FTAnyallOption",
  "opt_word", "opt_words", "FTPosFilter", "FTOrder", "FTWindow",
  "FTDistance", "FTUnit", "FTMatchOptions", "FTMatchOption",
  "FTCaseOption", "FTDiacriticsOption", "FTExtensionOption",
  "FTStemOption", "FTThesaurusOption", "FTThesaurusID_or_default",
  "opt_FTThesaurus_list", "FTThesaurus_list", "FTThesaurusID",
  "opt_relationship", "opt_levels", "FTStopWordOption", "FTStopWords",
  "STRING_LITERAL_list", "opt_FTStopWordsInclExcl_list",
  "FTStopWordsInclExcl_list", "FTStopWordsInclExcl", "FTLanguageOption",
  "FTWildCardOption", "FTContent", "FTTimes", "FTRange", "FTScope",
  "FTBigUnit", "FTIgnoreOption", "JSONArrayConstructor",
  "JSONSimpleObjectUnion", "JSONAccumulatorObjectUnion",
  "JSONObjectConstructor", "JSONPairList", "JSONInsertExpr",
  "JSONAppendExpr", "JSONDeleteExpr", "JSONRenameExpr", "JSONReplaceExpr",
  "JSONTest", "JSONItemTest", "JSONObjectTest", "JSONArrayTest",
  "URI_LITERAL", "NCNAME", "QNAME", "FUNCTION_NAME", "EQNAME", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const xquery_parser::rhs_number_type
  xquery_parser::yyrhs_[] =
  {
       336,     0,    -1,   338,    -1,   322,   338,    -1,   323,   338,
      -1,   322,   323,   338,    -1,     1,    -1,     1,     3,    -1,
     337,     1,    -1,   340,    -1,   339,   340,    -1,   341,    -1,
     339,   341,    -1,   216,   217,    30,   191,    -1,   216,   217,
      30,   132,    30,   191,    -1,   343,   191,   390,    -1,   360,
     191,   390,    -1,   343,   191,   360,   191,   390,    -1,   390,
      -1,   343,   337,   390,    -1,   360,   337,   390,    -1,   343,
     191,   360,   337,   390,    -1,   343,   337,   360,   191,   390,
      -1,   342,    -1,   342,   343,   191,    -1,   342,   360,   191,
      -1,   342,   343,   191,   360,   191,    -1,    35,   161,   656,
     133,   655,   191,    -1,   344,    -1,   343,   191,   344,    -1,
     343,   337,   344,    -1,   345,    -1,   353,    -1,   358,    -1,
     359,    -1,   367,    -1,   346,    -1,   347,    -1,   348,    -1,
     349,    -1,   350,    -1,   351,    -1,   352,    -1,   575,    -1,
      34,    39,   183,    -1,    34,    39,   197,    -1,    34,   114,
     107,   655,    -1,    34,    38,   655,    -1,    34,    41,   183,
      -1,    34,    41,   197,    -1,    34,    58,   170,    -1,    34,
      58,   203,    -1,    34,   114,   169,   128,   129,    -1,    34,
     114,   169,   128,   130,    -1,    34,    42,   183,   108,   149,
      -1,    34,    42,   183,   108,   166,    -1,    34,    42,   167,
     108,   149,    -1,    34,    42,   167,   108,   166,    -1,   354,
      -1,   357,    -1,    50,    25,     1,    -1,    50,    61,   655,
      -1,    50,    61,   356,   655,    -1,    50,    61,   655,    97,
     355,    -1,    50,    61,   356,   655,    97,   355,    -1,   655,
      -1,   355,   108,   655,    -1,   161,   656,   133,    -1,   114,
      46,   161,    -1,    50,    35,   655,    -1,    50,    35,   161,
     656,   133,   655,    -1,    50,    35,   655,    97,   355,    -1,
      50,    35,   161,   656,   133,   655,    97,   355,    -1,    34,
     161,   656,   133,   655,    -1,    34,   114,    46,   161,   655,
      -1,    34,   114,    48,   161,   655,    -1,   361,    -1,   360,
     191,   361,    -1,   360,   337,   361,    -1,   362,    -1,   366,
      -1,   368,    -1,   372,    -1,   377,    -1,   384,    -1,   386,
      -1,   389,    -1,    34,   114,    80,   363,    -1,    34,    80,
     657,   363,    -1,   364,    -1,   363,   364,    -1,   365,   133,
     567,    -1,    81,    -1,    89,    -1,    82,    -1,    83,    -1,
      84,    -1,    85,    -1,    90,    -1,    86,    -1,    87,    -1,
      88,    -1,    34,    57,   657,    30,    -1,    34,   262,   614,
      -1,    34,   112,   153,   369,    -1,    95,   551,   370,    -1,
     370,    -1,   371,    -1,   138,    -1,   138,   371,    -1,   143,
     414,    -1,    34,   373,   143,   414,    -1,    34,   373,   138,
      -1,    34,   373,   138,   143,   414,    -1,   113,   119,   657,
      -1,   113,   119,   657,   548,    -1,   374,   113,   119,   657,
      -1,   374,   113,   119,   657,   548,    -1,   375,    -1,   374,
     375,    -1,    27,    -1,    27,   157,   376,   188,    -1,    28,
      -1,    28,   157,   376,   188,    -1,   512,    -1,   376,   108,
     512,    -1,    34,   378,    -1,    34,   374,   378,    -1,   379,
      -1,   380,    -1,    48,   658,   381,   398,    -1,    48,   658,
     381,   138,    -1,    75,    48,   658,   381,   398,    -1,    75,
      48,   658,   381,   138,    -1,   157,   188,    -1,   157,   382,
     188,    -1,   157,   188,    95,   549,    -1,   157,   382,   188,
      95,   549,    -1,   383,    -1,   382,   108,   383,    -1,   119,
     657,    -1,   119,   657,   548,    -1,    34,   288,   657,    -1,
      34,   288,   657,    95,   385,    -1,    34,   374,   288,   657,
      -1,    34,   374,   288,   657,    95,   385,    -1,   555,    -1,
     555,   550,    -1,   651,    -1,   651,   550,    -1,    34,   296,
     657,   300,   228,   495,   171,   387,    -1,    34,   374,   296,
     657,   300,   228,   495,   171,   387,    -1,   388,    -1,   387,
     108,   388,    -1,   495,    -1,   495,   548,    -1,   495,   449,
      -1,   495,   548,   449,    -1,    34,   304,   305,   657,   300,
     288,   657,   119,   657,   306,   414,    -1,    34,   304,   305,
     657,   300,   288,   657,   226,   119,   657,   306,   294,   307,
     495,    -1,    34,   304,   305,   657,   300,   288,   657,   308,
     226,   119,   657,   306,   414,    -1,    34,   304,   305,   657,
     309,   307,   258,   288,   657,   226,   119,   657,   307,   495,
     200,   288,   657,   226,   119,   657,   307,   495,    -1,   391,
      -1,   393,    -1,   394,    -1,    -1,   393,    -1,   394,    -1,
      -1,   413,    -1,   394,   413,    -1,   395,    -1,   394,   395,
      -1,   394,   413,   337,   395,    -1,   396,    -1,   399,    -1,
     402,    -1,   403,    -1,   404,    -1,   405,    -1,   406,    -1,
     407,    -1,   409,    -1,   461,    -1,   457,    -1,   410,    -1,
     154,   394,   185,    -1,   154,   185,    -1,   154,   392,   185,
      -1,   154,   392,   185,    -1,   400,   191,    -1,   400,   108,
     401,    -1,   113,   401,    -1,   374,   113,   401,    -1,   119,
     657,    -1,   119,   657,   548,    -1,   119,   657,   143,   414,
      -1,   119,   657,   548,   143,   414,    -1,   119,   657,   143,
     414,   191,    -1,   415,   191,    -1,   241,   243,   414,   191,
      -1,   244,   157,   413,   188,   395,    -1,   239,   242,   191,
      -1,   240,   242,   191,    -1,   425,   408,    -1,   187,   395,
      -1,    49,   157,   413,   188,   199,   395,   127,   395,    -1,
     245,   396,   411,    -1,   412,    -1,   411,   412,    -1,   246,
     587,   396,    -1,   414,    -1,   413,   108,   414,    -1,   413,
     337,   414,    -1,   416,    -1,   453,    -1,   460,    -1,   467,
      -1,   583,    -1,   415,    -1,   468,    -1,   450,    -1,   576,
      -1,   577,    -1,   579,    -1,   578,    -1,   580,    -1,   648,
      -1,   646,    -1,   649,    -1,   650,    -1,   647,    -1,   425,
     417,    -1,   187,   414,    -1,    67,   285,    -1,    72,   285,
      -1,   218,    -1,   255,    -1,    56,   255,    -1,   419,   435,
      78,   414,    -1,   419,    78,   414,    -1,    47,   418,   434,
     420,   420,    -1,    47,   418,   434,   420,    -1,    43,   119,
     657,    -1,   426,    -1,   431,    -1,   421,    -1,   423,    -1,
     438,    -1,   443,    -1,   439,    -1,   422,    -1,   423,    -1,
     425,   424,    -1,    47,   119,   427,    -1,    47,     1,   427,
      -1,    47,     3,    -1,   428,    -1,   427,   108,   119,   428,
      -1,   427,   108,   428,    -1,   657,   148,   414,    -1,   657,
      37,   128,   148,   414,    -1,   657,   548,   148,   414,    -1,
     657,   548,    37,   128,   148,   414,    -1,   657,   429,   148,
     414,    -1,   657,    37,   128,   429,   148,   414,    -1,   657,
     548,   429,   148,   414,    -1,   657,   548,    37,   128,   429,
     148,   414,    -1,   657,   430,   148,   414,    -1,   657,   548,
     430,   148,   414,    -1,   657,   429,   430,   148,   414,    -1,
     657,   548,   429,   430,   148,   414,    -1,    97,   119,   657,
      -1,   274,   119,   657,    -1,    52,   432,    -1,   433,    -1,
     432,   108,   433,    -1,   119,   657,   143,   414,    -1,   119,
     657,   548,   143,   414,    -1,   430,   143,   414,    -1,   119,
     657,   548,   430,   143,   414,    -1,   119,   657,   148,   414,
      -1,   119,   657,   548,   148,   414,    -1,   436,    -1,   119,
     657,    -1,   119,   657,   436,    -1,   429,    -1,   429,   437,
      -1,   437,    -1,    59,   119,   657,    54,   119,   657,    -1,
      54,   119,   657,    -1,    59,   119,   657,    -1,   213,   414,
      -1,   172,   171,   440,    -1,   441,    -1,   440,   108,   441,
      -1,   119,   657,    -1,   119,   657,   143,   414,    -1,   119,
     657,   548,   143,   414,    -1,   119,   657,   548,   143,   414,
     442,    -1,   119,   657,   143,   414,   442,    -1,   119,   657,
     442,    -1,   107,   655,    -1,   169,   171,   444,    -1,    70,
     169,   171,   444,    -1,   445,    -1,   444,   108,   445,    -1,
     414,    -1,   414,   446,    -1,   447,    -1,   448,    -1,   449,
      -1,   447,   448,    -1,   447,   449,    -1,   448,   449,    -1,
     447,   448,   449,    -1,    96,    -1,   117,    -1,   128,   129,
      -1,   128,   130,    -1,   107,   655,    -1,    68,   119,   451,
     189,   414,    -1,   136,   119,   451,   189,   414,    -1,   452,
      -1,   451,   108,   119,   452,    -1,   657,   148,   414,    -1,
     657,   548,   148,   414,    -1,    73,   157,   413,   188,   454,
     114,   187,   414,    -1,   455,    -1,   454,   455,    -1,   456,
     187,   414,    -1,   101,   414,    -1,   456,   101,   414,    -1,
      73,   157,   413,   188,   458,   114,   187,   395,    -1,   459,
      -1,   458,   459,    -1,   456,   187,   395,    -1,    74,   157,
     413,   188,   462,   114,   187,   414,    -1,    74,   157,   413,
     188,   462,   114,   119,   657,   187,   414,    -1,    74,   157,
     413,   188,   464,   114,   187,   395,    -1,    74,   157,   413,
     188,   462,   114,   119,   657,   187,   395,    -1,   463,    -1,
     462,   463,    -1,   101,   466,   187,   414,    -1,   101,   119,
     657,    95,   466,   187,   414,    -1,   465,    -1,   464,   465,
      -1,   101,   466,   187,   395,    -1,   101,   119,   657,    95,
     466,   187,   395,    -1,   549,    -1,   466,   211,   549,    -1,
      49,   157,   413,   188,   199,   414,   127,   414,    -1,   469,
      -1,   468,   168,   469,    -1,   470,    -1,   469,    93,   470,
      -1,   472,    -1,   472,   489,   472,    -1,   472,   490,   472,
      -1,   472,   133,   472,    -1,   472,   163,   472,    -1,    -1,
     472,   158,   471,   472,    -1,   472,   156,   472,    -1,   472,
     144,   472,    -1,   472,   142,   472,    -1,   473,    -1,   473,
     250,    71,   588,   474,    -1,   475,    -1,   475,   100,   473,
      -1,    -1,   640,    -1,   476,    -1,   476,   200,   476,    -1,
     477,    -1,   476,   177,   477,    -1,   476,   159,   477,    -1,
     478,    -1,   477,   195,   478,    -1,   477,   118,   478,    -1,
     477,   147,   478,    -1,   477,   160,   478,    -1,   479,    -1,
     478,   202,   479,    -1,   478,   211,   479,    -1,   480,    -1,
     479,   151,   480,    -1,   479,   137,   480,    -1,   481,    -1,
     481,    51,   232,   549,    -1,   482,    -1,   482,   201,    95,
     549,    -1,   483,    -1,   483,   102,    95,   484,    -1,   485,
      -1,   485,   103,    95,   484,    -1,   554,    -1,   554,   145,
      -1,   487,    -1,   486,   487,    -1,   177,    -1,   159,    -1,
     486,   177,    -1,   486,   159,    -1,   491,    -1,   488,    -1,
     492,    -1,   495,    -1,   488,   194,   495,    -1,   204,    -1,
     209,    -1,   208,    -1,   207,    -1,   206,    -1,   205,    -1,
     152,    -1,   180,    -1,   141,    -1,    76,   154,   393,   185,
      -1,    76,   223,   154,   393,   185,    -1,    76,   222,   154,
     393,   185,    -1,    76,    77,   565,   154,   393,   185,    -1,
     493,   154,   185,    -1,   493,   154,   413,   185,    -1,   494,
      -1,   493,   494,    -1,   178,   657,    17,    -1,   178,    18,
      -1,   178,    19,    -1,   496,    -1,   496,   497,    -1,   193,
     497,    -1,   497,    -1,   192,    -1,   498,    -1,   498,   192,
     497,    -1,   498,   193,   497,    -1,   499,    -1,   508,    -1,
     500,    -1,   500,   509,    -1,   503,    -1,   503,   509,    -1,
     501,   505,    -1,   502,    -1,   106,   123,    -1,   115,   123,
      -1,    98,   123,    -1,   190,   123,    -1,   116,   123,    -1,
     140,   123,    -1,   139,   123,    -1,   505,    -1,    99,   505,
      -1,   504,   505,    -1,   121,    -1,   173,   123,    -1,    91,
     123,    -1,   182,   123,    -1,   181,   123,    -1,    92,   123,
      -1,   555,    -1,   506,    -1,   657,    -1,   507,    -1,   195,
      -1,    11,    -1,    12,    -1,    20,    -1,   511,    -1,   508,
     509,    -1,   508,   157,   188,    -1,   508,   157,   520,   188,
      -1,   510,    -1,   509,   510,    -1,   155,   413,   186,    -1,
     512,    -1,   514,    -1,   515,    -1,   516,    -1,   519,    -1,
     521,    -1,   517,    -1,   518,    -1,   568,    -1,   397,    -1,
     644,    -1,   641,    -1,   642,    -1,   643,    -1,   513,    -1,
     567,    -1,   111,    -1,   150,    -1,   125,    -1,   119,   657,
      -1,   157,   188,    -1,   157,   413,   188,    -1,   120,    -1,
     170,   154,   413,   185,    -1,   203,   154,   413,   185,    -1,
     658,   157,   188,    -1,   658,   157,   520,   188,    -1,   414,
      -1,   520,   108,   414,    -1,   522,    -1,   540,    -1,   523,
      -1,   537,    -1,   538,    -1,   158,   657,   527,   131,    -1,
     158,   657,   527,   198,   196,   657,   527,   198,    -1,   158,
     657,   525,   527,   131,    -1,   158,   657,   525,   527,   198,
     196,   657,   527,   198,    -1,   158,   657,   527,   198,   524,
     196,   657,   527,   198,    -1,   158,   657,   525,   527,   198,
     524,   196,   657,   527,   198,    -1,   535,    -1,   524,   535,
      -1,   526,    -1,   525,   526,    -1,    36,   657,   527,   133,
     527,   528,    -1,    -1,    36,    -1,   184,   529,   184,    -1,
      94,   531,    94,    -1,    -1,   530,    -1,   135,    -1,   533,
      -1,   530,   135,    -1,   530,   533,    -1,    -1,   532,    -1,
     134,    -1,   534,    -1,   532,   134,    -1,   532,   534,    -1,
      29,    -1,   536,    -1,     5,    -1,   536,    -1,   522,    -1,
      10,    -1,   539,    -1,   536,    -1,     9,    -1,   124,    -1,
     126,    -1,   154,   393,   185,    -1,   214,    31,   215,    -1,
     214,   215,    -1,   175,   656,   176,    -1,   175,   656,     8,
      -1,   104,     7,    -1,   541,    -1,   542,    -1,   543,    -1,
     544,    -1,   545,    -1,   546,    -1,   547,    -1,    44,   154,
     393,   185,    -1,    21,   392,   185,    -1,    46,   154,   413,
     185,   154,   392,   185,    -1,    22,   392,   185,    -1,    98,
     154,   413,   185,   154,   392,   185,    -1,    71,   154,   393,
     185,    -1,    40,   154,   393,   185,    -1,    23,   392,   185,
      -1,    60,   154,   413,   185,   154,   392,   185,    -1,    24,
     393,   185,    -1,   161,   154,   413,   185,   154,   393,   185,
      -1,    95,   549,    -1,   551,    -1,   551,   550,    -1,   212,
     157,   188,    -1,   145,    -1,   195,    -1,   177,    -1,   553,
      -1,   555,    -1,   153,   157,   188,    -1,   321,   157,   188,
      -1,   571,    -1,   574,    -1,   651,    -1,   549,    -1,   552,
     108,   549,    -1,   657,    -1,   657,    -1,   557,    -1,   563,
      -1,   561,    -1,   564,    -1,   562,    -1,   560,    -1,   559,
      -1,   558,    -1,   556,    -1,   226,   157,   188,    -1,    45,
     157,   188,    -1,    45,   157,   563,   188,    -1,    45,   157,
     564,   188,    -1,    71,   157,   188,    -1,    40,   157,   188,
      -1,    60,   157,   188,    -1,    60,   157,   656,   188,    -1,
      60,   157,    30,   188,    -1,    98,   157,   188,    -1,    98,
     157,   657,   188,    -1,    98,   157,   657,   108,   565,   188,
      -1,    98,   157,   195,   188,    -1,    98,   157,   195,   108,
     565,   188,    -1,    62,   157,   657,   188,    -1,    46,   157,
     188,    -1,    46,   157,   657,   188,    -1,    46,   157,   657,
     108,   565,   188,    -1,    46,   157,   657,   108,   566,   188,
      -1,    46,   157,   195,   188,    -1,    46,   157,   195,   108,
     565,   188,    -1,    46,   157,   195,   108,   566,   188,    -1,
      63,   157,   657,   188,    -1,   657,    -1,   657,   145,    -1,
      30,    -1,   569,    -1,   570,    -1,   657,   146,   150,    -1,
      48,   381,   398,    -1,   572,    -1,   573,    -1,    48,   157,
     195,   188,    -1,    48,   157,   188,    95,   549,    -1,    48,
     157,   552,   188,    95,   549,    -1,   157,   551,   188,    -1,
      34,   221,   222,    -1,    34,   221,   223,    -1,    34,   221,
     224,    -1,   227,   226,   414,   234,   414,    -1,   227,   226,
     414,    95,   233,   234,   414,    -1,   227,   226,   414,    95,
     235,   234,   414,    -1,   227,   226,   414,   219,   414,    -1,
     227,   226,   414,   220,   414,    -1,   227,   228,   414,   234,
     414,    -1,   227,   228,   414,    95,   233,   234,   414,    -1,
     227,   228,   414,    95,   235,   234,   414,    -1,   227,   228,
     414,   219,   414,    -1,   227,   228,   414,   220,   414,    -1,
     225,   226,   414,    -1,   225,   228,   414,    -1,   230,   226,
     414,   238,   414,    -1,   230,   231,   232,   226,   414,   238,
     414,    -1,   229,   226,   414,    95,   414,    -1,   237,   119,
     581,   236,   414,   187,   414,    -1,   582,    -1,   581,   108,
     119,   582,    -1,   657,   143,   414,    -1,   245,   154,   413,
     185,   584,    -1,   585,    -1,   584,   585,    -1,   246,   587,
     586,    -1,   154,   413,   185,    -1,   506,    -1,   587,   211,
     506,    -1,   591,   589,    -1,    -1,   590,    -1,   609,    -1,
     590,   609,    -1,   592,    -1,   591,   263,   592,    -1,   593,
      -1,   592,   259,   593,    -1,   594,    -1,   593,   261,   148,
     594,    -1,   595,    -1,   260,   595,    -1,   599,   596,   597,
      -1,    -1,   614,    -1,    -1,   598,    -1,   283,   154,   413,
     185,    -1,   603,   600,    -1,   157,   588,   188,    -1,   601,
      -1,    -1,   636,    -1,   493,   154,   602,   185,    -1,    -1,
     588,    -1,   604,   605,    -1,   512,    -1,   154,   413,   185,
      -1,    -1,   606,    -1,   249,   607,    -1,   248,   608,    -1,
     271,    -1,    -1,    79,    -1,    -1,   287,    -1,   610,    -1,
     611,    -1,   612,    -1,   638,    -1,   635,    -1,   170,    -1,
     285,   476,   613,    -1,   254,   637,   613,    -1,   287,    -1,
     277,    -1,   270,    -1,   247,   615,    -1,   614,   247,   615,
      -1,   616,    -1,   617,    -1,   618,    -1,   633,    -1,   619,
      -1,   627,    -1,   620,    -1,   634,    -1,   101,   275,    -1,
     101,   264,    -1,   267,    -1,   282,    -1,   252,   275,    -1,
     252,   264,    -1,    57,   657,    30,    -1,   278,    -1,    55,
     278,    -1,   280,   621,    -1,   280,   157,   621,   622,   188,
      -1,    55,   280,    -1,   624,    -1,   114,    -1,    -1,   108,
     623,    -1,   624,    -1,   623,   108,   624,    -1,    97,    30,
     625,   626,    -1,    -1,   272,    30,    -1,    -1,   637,   266,
      -1,   279,   287,   628,   630,    -1,   279,   287,   114,   630,
      -1,    55,   279,   287,    -1,    97,    30,    -1,   157,   629,
     188,    -1,    30,    -1,   629,   108,    30,    -1,    -1,   631,
      -1,   632,    -1,   631,   632,    -1,   202,   628,    -1,   137,
     628,    -1,   265,    30,    -1,   284,    -1,    55,   284,    -1,
      97,   218,    -1,    97,   255,    -1,   256,   251,    -1,   268,
     637,   281,    -1,   257,   476,    -1,    97,   130,   476,    -1,
      97,    53,   476,    -1,   258,   476,   200,   476,    -1,   273,
     639,    -1,   253,   639,    -1,   276,    -1,   269,    -1,   286,
     251,   478,    -1,   155,   186,    -1,   155,   413,   186,    -1,
     311,   312,    -1,   311,   413,   312,    -1,   313,   314,    -1,
     313,   413,   314,    -1,   154,   645,   185,    -1,   414,   122,
     414,    -1,   645,   108,   414,   122,   414,    -1,   227,   315,
     414,   234,   414,    -1,   227,   315,   645,   234,   414,    -1,
     227,   315,   414,   234,   414,    97,   317,   414,    -1,   316,
     315,   414,   234,   414,    -1,   225,   315,   508,    -1,   229,
     315,   508,    95,   414,    -1,   230,   315,   231,   232,   508,
     238,   414,    -1,   652,    -1,   653,    -1,   654,    -1,   320,
     157,   188,    -1,   318,   157,   188,    -1,   319,   157,   188,
      -1,    30,    -1,    16,    -1,   657,    -1,   658,    -1,    98,
      -1,    40,    -1,    45,    -1,    46,    -1,   153,    -1,    49,
      -1,   226,    -1,    60,    -1,    62,    -1,    63,    -1,    71,
      -1,    74,    -1,    73,    -1,   212,    -1,   244,    -1,   659,
      -1,    25,    -1,   216,    -1,   128,    -1,    39,    -1,   262,
      -1,    38,    -1,   223,    -1,   222,    -1,   147,    -1,    44,
      -1,   260,    -1,   261,    -1,   275,    -1,   264,    -1,   252,
      -1,   286,    -1,   278,    -1,   280,    -1,   279,    -1,   284,
      -1,   256,    -1,   251,    -1,    79,    -1,   218,    -1,   255,
      -1,    53,    -1,   224,    -1,   237,    -1,   303,    -1,   231,
      -1,   204,    -1,   209,    -1,   208,    -1,   207,    -1,   206,
      -1,   205,    -1,    97,    -1,   112,    -1,   113,    -1,   187,
      -1,    47,    -1,    37,    -1,    67,    -1,    72,    -1,    59,
      -1,    54,    -1,    56,    -1,    78,    -1,    43,    -1,   148,
      -1,    52,    -1,   213,    -1,   171,    -1,   172,    -1,   169,
      -1,    70,    -1,    96,    -1,   117,    -1,   129,    -1,   130,
      -1,   107,    -1,    68,    -1,   136,    -1,   189,    -1,   101,
      -1,    95,    -1,   199,    -1,   127,    -1,   168,    -1,    93,
      -1,    51,    -1,   232,    -1,   102,    -1,   200,    -1,   118,
      -1,   160,    -1,   202,    -1,   151,    -1,   137,    -1,    76,
      -1,    77,    -1,   103,    -1,   201,    -1,   152,    -1,   183,
      -1,   197,    -1,   161,    -1,   138,    -1,   132,    -1,   167,
      -1,   149,    -1,   166,    -1,    34,    -1,    41,    -1,    58,
      -1,   114,    -1,    42,    -1,    57,    -1,   217,    -1,    50,
      -1,    61,    -1,    35,    -1,    48,    -1,   274,    -1,   250,
      -1,   283,    -1,   285,    -1,   254,    -1,   268,    -1,   281,
      -1,   273,    -1,   253,    -1,   267,    -1,   282,    -1,   272,
      -1,   266,    -1,   265,    -1,   249,    -1,   248,    -1,   257,
      -1,   258,    -1,   287,    -1,   277,    -1,   276,    -1,   271,
      -1,   269,    -1,   270,    -1,   230,    -1,   236,    -1,   233,
      -1,   227,    -1,   220,    -1,   219,    -1,   221,    -1,   238,
      -1,   228,    -1,   229,    -1,   235,    -1,   225,    -1,   234,
      -1,    66,    -1,    64,    -1,    75,    -1,   170,    -1,   203,
      -1,   243,    -1,   241,    -1,   242,    -1,   239,    -1,   240,
      -1,   245,    -1,   246,    -1,   247,    -1,    65,    -1,   296,
      -1,   294,    -1,   295,    -1,   300,    -1,   301,    -1,   302,
      -1,   297,    -1,   298,    -1,   299,    -1,    80,    -1,    81,
      -1,    82,    -1,    83,    -1,    84,    -1,    85,    -1,    86,
      -1,    87,    -1,    88,    -1,    89,    -1,    90,    -1,   288,
      -1,   289,    -1,   290,    -1,   291,    -1,   292,    -1,   293,
      -1,   304,    -1,   305,    -1,   306,    -1,   307,    -1,   308,
      -1,   309,    -1,   310,    -1,    91,    -1,   106,    -1,   115,
      -1,   173,    -1,   181,    -1,   190,    -1,   139,    -1,    92,
      -1,   116,    -1,   140,    -1,   182,    -1,   315,    -1,   316,
      -1,   317,    -1,   320,    -1,   319,    -1,   318,    -1,   321,
      -1,    26,    -1
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
    1805,  1810,  1819,  1825,  1835,  1845,  1856,  1858,  1861,  1863,
    1866,  1873,  1874,  1876,  1880,  1884,  1885,  1887,  1889,  1891,
    1894,  1897,  1898,  1900,  1902,  1904,  1907,  1910,  1912,  1914,
    1916,  1918,  1920,  1922,  1924,  1926,  1928,  1930,  1932,  1936,
    1940,  1943,  1947,  1951,  1954,  1956,  1958,  1960,  1962,  1964,
    1966,  1968,  1973,  1977,  1985,  1989,  1997,  2002,  2007,  2011,
    2019,  2023,  2031,  2034,  2036,  2039,  2043,  2045,  2047,  2049,
    2051,  2053,  2057,  2061,  2063,  2065,  2067,  2069,  2073,  2075,
    2077,  2079,  2081,  2083,  2085,  2087,  2089,  2091,  2093,  2095,
    2099,  2103,  2108,  2113,  2117,  2121,  2125,  2130,  2135,  2139,
    2144,  2151,  2156,  2163,  2168,  2172,  2177,  2184,  2191,  2196,
    2203,  2210,  2215,  2217,  2220,  2222,  2224,  2226,  2230,  2234,
    2236,  2238,  2243,  2249,  2256,  2260,  2264,  2268,  2272,  2278,
    2286,  2294,  2300,  2306,  2312,  2320,  2328,  2334,  2340,  2344,
    2348,  2354,  2362,  2368,  2376,  2378,  2383,  2387,  2393,  2395,
    2398,  2402,  2406,  2408,  2412,  2415,  2416,  2418,  2420,  2423,
    2425,  2429,  2431,  2435,  2437,  2442,  2444,  2447,  2451,  2452,
    2454,  2455,  2457,  2462,  2465,  2469,  2471,  2472,  2474,  2479,
    2480,  2482,  2485,  2487,  2491,  2492,  2494,  2497,  2500,  2502,
    2503,  2505,  2506,  2508,  2510,  2512,  2514,  2516,  2518,  2520,
    2524,  2528,  2530,  2532,  2534,  2537,  2541,  2543,  2545,  2547,
    2549,  2551,  2553,  2555,  2557,  2560,  2563,  2565,  2567,  2570,
    2573,  2577,  2579,  2582,  2585,  2591,  2594,  2596,  2598,  2599,
    2602,  2604,  2608,  2613,  2614,  2617,  2618,  2621,  2626,  2631,
    2635,  2638,  2642,  2644,  2648,  2649,  2651,  2653,  2656,  2659,
    2662,  2665,  2667,  2670,  2673,  2676,  2679,  2683,  2686,  2690,
    2694,  2699,  2702,  2705,  2707,  2709,  2713,  2716,  2720,  2723,
    2727,  2730,  2734,  2738,  2742,  2748,  2754,  2760,  2769,  2775,
    2779,  2785,  2793,  2795,  2797,  2799,  2803,  2807,  2811,  2813,
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
    3135,  3137,  3139,  3141,  3143,  3145,  3147,  3149,  3151,  3153,
    3155,  3157,  3159,  3161,  3163,  3165,  3167,  3169,  3171,  3173,
    3175,  3177,  3179,  3181,  3183,  3185,  3187,  3189,  3191,  3193,
    3195,  3197,  3199,  3201,  3203,  3205,  3207,  3209,  3211,  3213,
    3215,  3217,  3219,  3221,  3223,  3225,  3227,  3229,  3231,  3233,
    3235,  3237,  3239,  3241,  3243,  3245,  3247,  3249,  3251,  3253,
    3255,  3257,  3259,  3261
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1054,  1054,  1055,  1059,  1063,  1071,  1077,  1081,  1090,
    1096,  1104,  1110,  1121,  1126,  1134,  1141,  1148,  1157,  1164,
    1172,  1180,  1188,  1199,  1204,  1211,  1218,  1230,  1240,  1247,
    1254,  1266,  1267,  1268,  1269,  1270,  1275,  1276,  1277,  1278,
    1279,  1280,  1281,  1284,  1289,  1294,  1302,  1310,  1318,  1323,
    1331,  1336,  1344,  1349,  1357,  1362,  1367,  1372,  1380,  1382,
    1385,  1395,  1400,  1408,  1416,  1427,  1434,  1445,  1450,  1458,
    1465,  1472,  1481,  1494,  1502,  1509,  1519,  1526,  1533,  1544,
    1545,  1546,  1547,  1548,  1549,  1550,  1551,  1556,  1562,  1571,
    1578,  1588,  1598,  1599,  1600,  1601,  1602,  1603,  1604,  1605,
    1606,  1607,  1612,  1620,  1628,  1636,  1643,  1651,  1658,  1663,
    1671,  1679,  1693,  1707,  1724,  1729,  1737,  1745,  1756,  1761,
    1770,  1775,  1782,  1787,  1797,  1802,  1811,  1817,  1830,  1835,
    1843,  1854,  1869,  1881,  1896,  1901,  1906,  1911,  1919,  1926,
    1937,  1942,  1952,  1961,  1970,  1979,  1991,  1995,  2001,  2005,
    2015,  2025,  2038,  2044,  2053,  2058,  2065,  2072,  2083,  2093,
    2103,  2113,  2131,  2151,  2155,  2160,  2167,  2171,  2176,  2183,
    2188,  2200,  2207,  2217,  2232,  2233,  2234,  2235,  2236,  2237,
    2238,  2240,  2241,  2242,  2243,  2244,  2249,  2254,  2262,  2279,
    2287,  2295,  2302,  2309,  2320,  2329,  2338,  2347,  2360,  2368,
    2376,  2384,  2399,  2404,  2412,  2426,  2443,  2468,  2476,  2483,
    2494,  2504,  2509,  2522,  2539,  2540,  2541,  2542,  2543,  2544,
    2549,  2550,  2553,  2554,  2555,  2556,  2557,  2560,  2561,  2562,
    2563,  2564,  2569,  2583,  2591,  2596,  2604,  2609,  2614,  2622,
    2631,  2643,  2653,  2666,  2674,  2675,  2676,  2681,  2682,  2683,
    2684,  2685,  2690,  2697,  2707,  2713,  2722,  2732,  2739,  2747,
    2759,  2769,  2779,  2789,  2799,  2809,  2819,  2829,  2840,  2849,
    2859,  2869,  2885,  2894,  2903,  2911,  2917,  2929,  2937,  2947,
    2955,  2967,  2973,  2984,  2986,  2990,  2998,  3002,  3007,  3011,
    3015,  3019,  3029,  3037,  3044,  3050,  3060,  3064,  3068,  3076,
    3084,  3092,  3104,  3112,  3118,  3128,  3134,  3144,  3148,  3158,
    3164,  3170,  3176,  3185,  3194,  3203,  3216,  3220,  3228,  3234,
    3244,  3252,  3261,  3274,  3281,  3293,  3297,  3309,  3316,  3322,
    3331,  3338,  3344,  3355,  3362,  3368,  3377,  3386,  3393,  3404,
    3411,  3423,  3429,  3441,  3447,  3458,  3464,  3475,  3481,  3492,
    3498,  3509,  3518,  3522,  3531,  3535,  3543,  3547,  3557,  3564,
    3573,  3583,  3582,  3596,  3605,  3614,  3627,  3631,  3643,  3647,
    3655,  3658,  3665,  3669,  3678,  3682,  3686,  3694,  3698,  3704,
    3710,  3716,  3726,  3730,  3734,  3742,  3746,  3752,  3762,  3766,
    3776,  3780,  3790,  3794,  3804,  3808,  3818,  3822,  3831,  3835,
    3843,  3847,  3851,  3855,  3865,  3869,  3873,  3880,  3885,  3893,
    3897,  3901,  3905,  3909,  3913,  3921,  3925,  3929,  3937,  3941,
    3945,  3949,  3960,  3966,  3976,  3982,  3992,  3996,  4000,  4038,
    4042,  4052,  4062,  4075,  4084,  4094,  4098,  4107,  4111,  4120,
    4126,  4134,  4140,  4152,  4158,  4168,  4172,  4176,  4180,  4184,
    4190,  4196,  4204,  4208,  4216,  4220,  4231,  4235,  4239,  4245,
    4249,  4263,  4267,  4275,  4279,  4289,  4293,  4297,  4301,  4310,
    4314,  4318,  4322,  4330,  4336,  4346,  4354,  4358,  4362,  4366,
    4370,  4374,  4378,  4382,  4386,  4390,  4395,  4399,  4403,  4407,
    4415,  4419,  4427,  4434,  4441,  4452,  4460,  4464,  4472,  4480,
    4488,  4542,  4546,  4559,  4565,  4575,  4579,  4587,  4591,  4595,
    4603,  4611,  4628,  4636,  4653,  4672,  4696,  4702,  4713,  4719,
    4730,  4739,  4741,  4745,  4750,  4760,  4763,  4770,  4776,  4782,
    4789,  4801,  4804,  4811,  4817,  4823,  4830,  4841,  4845,  4853,
    4857,  4865,  4869,  4873,  4878,  4887,  4891,  4895,  4899,  4907,
    4912,  4920,  4925,  4933,  4941,  4946,  4951,  4956,  4961,  4966,
    4971,  4977,  4985,  4989,  5006,  5010,  5018,  5026,  5034,  5038,
    5046,  5050,  5058,  5066,  5070,  5074,  5109,  5115,  5121,  5131,
    5135,  5139,  5143,  5147,  5151,  5155,  5162,  5168,  5178,  5186,
    5194,  5198,  5202,  5206,  5210,  5214,  5218,  5222,  5226,  5234,
    5242,  5246,  5250,  5260,  5268,  5276,  5280,  5284,  5292,  5296,
    5302,  5308,  5312,  5322,  5330,  5334,  5340,  5349,  5358,  5364,
    5370,  5380,  5397,  5404,  5419,  5455,  5459,  5467,  5475,  5487,
    5491,  5499,  5507,  5511,  5522,  5539,  5545,  5551,  5561,  5565,
    5571,  5577,  5581,  5587,  5591,  5597,  5603,  5610,  5620,  5625,
    5633,  5639,  5649,  5671,  5680,  5686,  5699,  5713,  5720,  5726,
    5736,  5745,  5753,  5759,  5777,  5785,  5789,  5796,  5801,  5809,
    5813,  5820,  5824,  5831,  5835,  5842,  5846,  5855,  5868,  5871,
    5879,  5882,  5890,  5898,  5906,  5910,  5918,  5921,  5929,  5941,
    5944,  5952,  5964,  5970,  5980,  5983,  5991,  5995,  5999,  6007,
    6010,  6018,  6021,  6029,  6033,  6037,  6041,  6045,  6053,  6061,
    6073,  6085,  6089,  6093,  6101,  6107,  6117,  6121,  6125,  6129,
    6133,  6137,  6141,  6145,  6153,  6157,  6161,  6165,  6173,  6179,
    6189,  6199,  6203,  6211,  6221,  6232,  6239,  6243,  6251,  6254,
    6261,  6266,  6275,  6285,  6288,  6295,  6299,  6307,  6316,  6323,
    6333,  6337,  6344,  6350,  6360,  6363,  6370,  6375,  6387,  6395,
    6407,  6415,  6419,  6427,  6431,  6435,  6443,  6451,  6455,  6459,
    6463,  6471,  6479,  6491,  6495,  6503,  6517,  6521,  6528,  6533,
    6541,  6546,  6555,  6563,  6569,  6579,  6585,  6595,  6602,  6609,
    6634,  6662,  6690,  6694,  6698,  6705,  6712,  6719,  6731,  6735,
    6736,  6749,  6750,  6751,  6752,  6753,  6754,  6755,  6756,  6757,
    6758,  6759,  6760,  6761,  6762,  6763,  6764,  6768,  6769,  6770,
    6771,  6772,  6773,  6774,  6775,  6776,  6777,  6778,  6779,  6780,
    6781,  6782,  6783,  6784,  6785,  6786,  6787,  6788,  6789,  6790,
    6791,  6792,  6793,  6794,  6795,  6796,  6797,  6798,  6799,  6800,
    6801,  6802,  6803,  6804,  6805,  6806,  6807,  6808,  6809,  6810,
    6811,  6812,  6813,  6814,  6815,  6816,  6817,  6818,  6819,  6820,
    6821,  6822,  6823,  6824,  6825,  6826,  6827,  6828,  6829,  6830,
    6831,  6832,  6833,  6834,  6835,  6836,  6837,  6838,  6839,  6840,
    6841,  6842,  6843,  6844,  6845,  6846,  6847,  6848,  6849,  6850,
    6851,  6852,  6853,  6854,  6855,  6856,  6857,  6858,  6859,  6860,
    6861,  6862,  6863,  6864,  6865,  6866,  6867,  6868,  6869,  6870,
    6871,  6872,  6873,  6874,  6875,  6876,  6877,  6878,  6879,  6880,
    6881,  6882,  6883,  6884,  6885,  6886,  6887,  6888,  6889,  6890,
    6891,  6892,  6893,  6894,  6895,  6896,  6897,  6898,  6899,  6900,
    6901,  6902,  6903,  6904,  6905,  6906,  6907,  6908,  6909,  6910,
    6911,  6912,  6913,  6914,  6915,  6916,  6917,  6918,  6919,  6920,
    6921,  6922,  6923,  6924,  6925,  6926,  6927,  6928,  6929,  6930,
    6931,  6932,  6933,  6934,  6935,  6936,  6937,  6938,  6939,  6940,
    6941,  6942,  6943,  6944,  6945,  6946,  6947,  6948,  6949,  6950,
    6951,  6952,  6953,  6954,  6955,  6956,  6957,  6958,  6959,  6960,
    6961,  6962,  6963,  6964,  6965,  6966,  6967,  6968,  6969,  6970,
    6971,  6972,  6973,  6978
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
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 17261;
  const int xquery_parser::yynnts_ = 325;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 614;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 335;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 589;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 17805 "/home/markos/zorba/repo/ns-nodes/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 6982 "/home/markos/zorba/repo/ns-nodes/src/compiler/parser/xquery_parser.y"


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

