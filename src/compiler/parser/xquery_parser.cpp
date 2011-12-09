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
#line 87 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"


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
#line 77 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 892 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 299 of lalr1.cc  */
#line 998 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 299 of lalr1.cc  */
#line 107 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"

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
#line 193 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"

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
#line 890 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 298 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 123: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 307 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 148: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 316 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 325 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 334 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 343 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 352 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 361 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 370 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 379 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 388 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 397 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 406 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 415 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 424 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 433 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 442 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 451 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 460 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 469 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 478 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 487 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 496 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 505 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 514 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 523 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 532 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 541 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 550 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 559 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 568 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 577 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 586 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 595 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 604 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 613 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 622 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 631 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 640 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 649 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 658 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 667 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 676 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 685 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 694 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 703 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 712 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 721 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 730 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 739 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 748 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 757 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 775 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 784 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 820 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 829 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 838 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 847 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 856 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 865 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 874 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 901 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 910 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 919 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 937 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 946 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 955 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 964 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 973 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 982 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 991 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1000 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1009 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1018 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1027 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1036 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1045 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1054 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1063 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1072 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1081 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1090 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1099 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1108 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1117 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1126 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1135 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1144 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1153 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1162 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1171 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1180 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1189 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1198 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1207 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1216 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1225 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1234 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1243 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1252 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1261 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1270 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1279 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1288 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1297 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1306 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1315 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1324 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1333 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1342 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1351 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1360 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1369 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1378 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1387 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1396 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1405 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1414 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1423 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "JSONPairConstructor" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1432 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1441 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1450 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1459 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1468 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1477 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1486 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1495 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1504 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1513 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1522 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1531 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1540 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1549 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1558 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1567 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1576 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1585 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1594 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1603 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1612 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1621 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1630 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1639 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1648 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1657 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1666 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1675 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1684 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1693 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1702 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1711 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1720 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1729 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1738 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1747 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1756 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1765 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1774 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1783 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1792 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1801 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1810 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1819 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1828 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1837 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1846 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1855 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1864 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1873 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1882 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1891 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1900 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1909 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1918 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1927 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1936 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1945 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1954 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1963 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1972 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1981 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1990 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1999 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2008 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2017 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2026 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2035 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2044 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2053 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2062 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2071 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2080 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2089 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2098 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2107 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2116 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2125 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2134 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2143 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2152 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2161 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2170 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2179 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2188 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2197 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2206 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2215 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2224 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2233 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2242 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2251 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2260 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2269 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2278 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2287 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2296 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2305 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2314 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2323 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2332 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2341 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2350 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2359 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2368 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2377 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2386 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2395 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2404 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2413 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2422 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2431 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2440 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2449 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2458 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2467 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2476 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2485 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2494 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2503 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2512 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2521 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2530 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2539 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2548 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2557 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2566 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2575 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 614: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2584 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2593 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 618: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2602 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 622: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2611 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 623: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2620 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 624: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2629 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 625: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2638 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 626: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2647 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 627: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2656 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2665 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2674 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 630: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2683 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 631: /* "JSONConstructor" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2692 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 632: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2701 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 633: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2710 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 643: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2719 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 644: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2728 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 645: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2737 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
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
#line 140 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 565 of lalr1.cc  */
#line 2834 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"

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
#line 1016 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 1025 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 1034 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 1040 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 1048 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 1054 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 1065 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 1070 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 1078 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 1085 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 1092 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 1101 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 1108 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 1116 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 1124 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 1132 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 1143 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 1148 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 1155 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 1162 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 1174 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 1184 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 1191 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 1198 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1233 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 1238 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 1246 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 1254 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 1262 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 1267 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 1275 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1280 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1288 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1293 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1301 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1308 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1315 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1322 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1337 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1347 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 1352 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 1360 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 1368 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 1379 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1386 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1397 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1402 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1410 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1417 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1424 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1433 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1446 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1454 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1461 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1471 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 1478 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1485 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 1508 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 1514 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 1523 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 1530 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1540 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1549 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1550 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1551 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1552 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1553 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1554 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1555 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1556 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1557 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1558 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1564 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1572 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1580 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1588 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1595 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1603 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1610 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1615 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1623 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1631 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1646 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1661 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1679 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1684 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1692 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1700 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 1711 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1716 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1725 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1730 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1737 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1742 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1752 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1757 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1766 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1772 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1785 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1790 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1798 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1809 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1824 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1836 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1851 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1856 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1861 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1866 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1874 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1881 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1892 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1897 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1914 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1928 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1938 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1942 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1952 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1960 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1971 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1977 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1986 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1991 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1998 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 2005 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 2017 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2027 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2037 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2048 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2064 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2084 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 2089 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 2093 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 2101 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 2106 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 2110 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 2118 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 2123 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 2135 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 2142 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 2171 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 2176 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 2184 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2201 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 2209 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 2217 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 2224 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 2231 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 2241 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2253 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2266 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2278 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2294 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 2302 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 2310 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 2318 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2333 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 2338 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 2346 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2360 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2377 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2402 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2410 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 2417 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2428 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 2438 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 2443 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2481 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2495 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 2503 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 2508 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 2516 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 2521 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 2526 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 2534 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2543 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2555 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2565 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2578 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2602 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2609 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2619 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 2627 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 2634 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 2644 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2654 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2664 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2674 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2684 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2694 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2704 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2714 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2725 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2734 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2744 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2754 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2770 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2779 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2788 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2796 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2802 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2814 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2822 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2832 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2840 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2852 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 2858 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 2871 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 2875 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 2883 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 2887 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2896 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2900 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2904 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2914 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2922 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2929 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2935 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2946 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2950 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2959 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2967 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2973 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2983 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2989 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 2999 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 3003 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 3013 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 3019 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 3025 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 3031 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3040 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3049 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3058 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3071 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 3075 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 3083 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 3089 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 3099 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 3107 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3116 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3129 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 3136 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 3148 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 3152 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 3164 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 3171 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 3177 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 3186 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 3193 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 3199 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 3210 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 3217 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 3223 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 3232 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 3241 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 3248 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3259 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 3266 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3278 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 3284 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 3296 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 3302 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 3313 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 3319 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 3330 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 3336 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 3347 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 3356 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 3360 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 3369 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 3373 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 3381 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 3385 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3395 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 3402 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3411 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3420 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 3425 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3434 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3443 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3452 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3465 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 3469 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3481 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 3485 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 3493 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 3497 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RangeExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 3505 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 3509 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new JSON_PairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 3518 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 3522 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 3526 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3535 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3539 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3545 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 3551 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3557 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 3568 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 3572 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3576 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 3584 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 3588 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 3594 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 3604 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3608 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 368:

/* Line 690 of lalr1.cc  */
#line 3618 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3622 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3632 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3636 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3646 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3650 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3660 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3664 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3672 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3676 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3680 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3684 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3694 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3698 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3702 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3710 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3714 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3718 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3722 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3726 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3730 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3738 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3742 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3746 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3754 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3758 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3762 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3766 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3777 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3783 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3793 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3799 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3809 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3813 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3817 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3855 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3859 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3869 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3879 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3892 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3901 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3911 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3924 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3928 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3937 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3943 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3951 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3957 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3969 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3975 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3985 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3989 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3993 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3997 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 4001 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 4007 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 4013 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 4021 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 4025 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 4033 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 4037 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 4048 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 4052 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 4056 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 4062 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 4066 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 4080 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 4084 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 4092 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 4096 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 4106 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 4110 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 4114 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 4118 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 4127 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 4131 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 4135 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 4139 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 4147 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 4153 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 4163 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 4171 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 4175 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 4179 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 4183 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 4187 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 4191 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 4195 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 4199 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 4203 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 4213 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 4217 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 4225 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 4229 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 4237 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 4244 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 4251 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 4262 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 4270 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 4274 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 4282 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 4290 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 4298 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 4352 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 4356 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 4369 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 4375 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 4385 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 4389 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 4397 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 4401 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 4405 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 4413 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 4423 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 4433 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 4443 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 4453 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 4463 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 4478 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 4484 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 4495 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 4501 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 4512 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 4529 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 4534 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 4543 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 4547 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 4554 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 4560 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 4566 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 4574 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 4586 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 4590 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 4597 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 4603 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 4609 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 4616 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 4627 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 4631 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 4641 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 4645 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 4655 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 4659 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 4663 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 4668 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 4677 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 4683 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 4689 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 4695 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 4703 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 4708 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 4716 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 4721 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 4729 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 4737 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 4742 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 4747 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 4752 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 4757 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 4762 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 4771 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 4779 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 4783 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 4800 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 4804 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 4812 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 4820 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 4828 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 4832 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 4840 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 4846 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 4856 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 4864 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 4868 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 4872 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 4907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 4913 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 4919 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 4929 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 4933 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 4937 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 4941 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 4945 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 4949 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new JSON_Test( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].json_test_value) );
        }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 4956 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 4962 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 4972 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 4980 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 4984 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 4988 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 4992 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 4996 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 5000 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 5004 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 5008 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 5012 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 5020 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 5028 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 5032 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 5036 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 5046 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 5054 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 5062 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 5066 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 5070 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 5078 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 5082 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 5088 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 5094 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 5098 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 5108 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 5116 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 5120 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 5126 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 5135 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 5144 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 5150 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 5156 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 5166 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 5183 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 5190 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 5205 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 5241 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 5245 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 5253 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 5261 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 5273 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 5277 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 5285 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 5293 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 5297 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 5308 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 5325 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 5331 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 5337 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 5347 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 5351 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 5357 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 5363 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 5367 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 5373 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 5377 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 5383 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 5389 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 5396 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 5406 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 5411 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 5419 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 5425 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 5435 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 5457 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 5466 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 5472 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 5485 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 5499 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 5506 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 5512 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 5522 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 5531 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 5539 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 5545 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 5563 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 5571 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 5575 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 5582 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 5587 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 5595 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 5599 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 5606 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 5610 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 5617 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 5621 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 5628 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 5632 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 5641 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 5653 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 5657 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 5664 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 5668 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 5676 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 5684 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 5692 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 5696 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 5703 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 5707 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 5715 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 5726 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 5730 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 5738 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 5750 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 5756 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 5765 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 5769 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 5777 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 5781 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 5785 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 5792 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 5796 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 5803 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 5807 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 5815 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 5819 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 5823 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 5827 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 5831 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 5839 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 5847 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 5859 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 5871 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 5875 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 5879 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 5887 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 5893 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 5903 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 5907 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 5911 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 5915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 5919 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 5923 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 5927 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 5931 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 5939 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 5943 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 5947 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 5951 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 5959 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 5965 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 5975 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 5985 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 5989 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 5997 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 6007 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 6018 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 6025 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 6029 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 6036 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 6040 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 6047 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 6052 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 6061 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 6070 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 6074 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 6081 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 6085 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 6093 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 6102 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 6109 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 6119 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 6123 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 6130 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 6136 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 6145 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 6149 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 6156 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 6161 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 6173 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 6181 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 6193 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 6201 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 6205 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 6213 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 6217 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 6221 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 6229 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 6237 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 6241 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 6245 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 6249 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 6257 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 6265 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 6277 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 6281 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 6289 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 6298 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 6302 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 6309 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new JSON_ArrayConstructor( LOC( (yyloc) ), NULL );
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 6313 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSON_ArrayConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 6320 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new JSON_ObjectConstructor( LOC( (yyloc) ), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 6327 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.json_test_value) = (yysemantic_stack_[(1) - (1)].json_test_value);
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 6331 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.json_test_value) = (yysemantic_stack_[(1) - (1)].json_test_value);
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 6335 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.json_test_value) = (yysemantic_stack_[(1) - (1)].json_test_value);
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 6339 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.json_test_value) = (yysemantic_stack_[(1) - (1)].json_test_value);
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 6343 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.json_test_value) = (yysemantic_stack_[(1) - (1)].json_test_value);
        }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 6347 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.json_test_value) = (yysemantic_stack_[(1) - (1)].json_test_value);
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 6354 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.json_test_value) = json_test::json_item;
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 6361 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.json_test_value) = json_test::object;
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 6368 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.json_test_value) = json_test::array;
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 6375 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.json_test_value) = json_test::pair;
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 6382 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.json_test_value) = json_test::object_pair;
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 6389 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.json_test_value) = json_test::array_pair;
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 6407 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 765:

/* Line 690 of lalr1.cc  */
#line 6420 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 6421 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 6422 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 6423 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 6424 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 6425 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 6426 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 6427 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 6428 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 6429 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 6430 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 6431 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 6432 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 6433 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 6434 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 6439 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 6440 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 6441 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 6442 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 6443 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 6444 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 6445 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 6446 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 789:

/* Line 690 of lalr1.cc  */
#line 6447 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 6448 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 791:

/* Line 690 of lalr1.cc  */
#line 6449 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 792:

/* Line 690 of lalr1.cc  */
#line 6450 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 793:

/* Line 690 of lalr1.cc  */
#line 6451 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 6452 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 6453 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 796:

/* Line 690 of lalr1.cc  */
#line 6454 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 6455 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 798:

/* Line 690 of lalr1.cc  */
#line 6456 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 6457 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 6458 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 6459 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 802:

/* Line 690 of lalr1.cc  */
#line 6460 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 803:

/* Line 690 of lalr1.cc  */
#line 6461 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 6462 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 805:

/* Line 690 of lalr1.cc  */
#line 6463 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 6464 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 6465 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 6466 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 6467 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 6468 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 6469 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 6470 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 6471 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 6472 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 6473 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 6474 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 6475 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 6476 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 6477 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 6478 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 6479 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 6480 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 6481 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 6482 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 6483 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 6484 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 6485 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 6486 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 6487 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 6488 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 6489 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 6490 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 6491 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 6492 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 6493 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 6494 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 6495 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 6496 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 6497 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 6498 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 6499 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 6500 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 6501 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 6502 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 6503 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 6504 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 6505 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 6506 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 6507 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 6508 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 6509 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 6510 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 6511 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 6512 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 6513 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 6514 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 6515 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 6516 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 6517 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 6518 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 6519 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 6520 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 6521 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 6522 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 6523 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 6524 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 6525 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 6526 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 6527 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 6528 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 6529 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 6530 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 6531 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 6532 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 6533 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 6534 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 6535 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 6536 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 6537 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 6538 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 6539 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 6540 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 6541 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 6542 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 6543 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 6544 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 6545 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 6546 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 6547 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 6548 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 6549 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 6550 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 6551 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 6552 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 6553 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 6554 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 6555 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 6556 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 6557 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 6558 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 6559 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 6560 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 6561 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 6562 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 6563 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 6564 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 6565 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 6566 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 6567 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 6568 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 6569 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 6570 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 6571 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 6572 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 6573 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 6574 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 6575 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 6576 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 6577 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 6578 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 6579 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 6580 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 6581 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 6582 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 6583 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 6584 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 6585 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 6586 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 6587 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 6588 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 6589 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 6590 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 6591 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 6592 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 6593 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 6594 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 6595 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 6596 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 6597 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 6598 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 6599 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 6600 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 6601 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 6602 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 6603 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 6604 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 6605 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 6606 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 6607 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 6608 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 6609 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 6610 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 6611 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 6612 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 6613 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 6614 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 6615 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 6616 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 6617 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 6618 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 6619 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 6620 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 6621 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 6622 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 6623 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 6624 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 6625 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 6626 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 6627 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 6628 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 6629 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 6630 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 6631 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 6632 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 6633 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 6634 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 6635 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 6636 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 6641 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 11750 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1425;
  const short int
  xquery_parser::yypact_[] =
  {
      3004, -1425, -1425, -1425,  4489,  4489,  4489, -1425, -1425,   122,
     171, -1425,   105,   182, -1425, -1425, -1425,   661, -1425, -1425,
   -1425,   262,   265,   694,    78,   295,   330,   649, -1425,   -35,
   -1425, -1425, -1425, -1425, -1425, -1425,   769, -1425,   392,   463,
   -1425, -1425, -1425, -1425,    42, -1425,   774, -1425,   503,   611,
   -1425,    30, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425,   489,   698, -1425, -1425,
   -1425, -1425,   232,  9241, -1425, -1425, -1425,   721, -1425, -1425,
   -1425,   609, -1425,   727,   755, -1425, -1425, 13004, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425,   798, -1425, -1425,   765,
     804, -1425, -1425, -1425, -1425, -1425, -1425, -1425,  3301,  6271,
    6568, 13004, -1425, -1425, -1425, -1425, -1425, -1425, -1425,   767,
   -1425, -1425,   814, 10122, -1425, 12152,   819,   832, -1425, -1425,
   -1425,   835, -1425,  8944, -1425, -1425, -1425, -1425, -1425, -1425,
     808, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,    36,
     752, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,   688,
     806,   705, -1425,   751,   643, -1425, -1425, -1425, -1425, -1425,
   -1425,   858, -1425,   737,   738,   740, -1425, -1425,   823,   829,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425,  4786,   982, -1425,  5083, -1425, -1425,   612,
      91, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425,    93, -1425, -1425, -1425, -1425,
   -1425, -1425,   103, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425,  4489, -1425, -1425, -1425, -1425,    -8, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425,   877, -1425,   795, -1425, -1425,
   -1425,   662, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
     820,   893, -1425,   766,   741,   790,   324,   486,   519,   455,
   -1425,   939,   792,   891,   892,  7756, -1425, -1425, -1425,   271,
   -1425, -1425,  8944, -1425,   -51, -1425,   839,  9241, -1425,   839,
    9241, -1425, -1425, -1425,   778, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425,   850,   840, -1425, -1425, -1425, -1425, -1425,   817, -1425,
    4489,   822,   824,   282,   282,   969,   -31,   607,   610, 13288,
   13004,   453,   954, 13004,   851,   889,   313, 10122,   680,   759,
   13004, 13004,   706,   747,    37, -1425, -1425, -1425, 10122,  4489,
     826,  4489,    59,  8053, 12436,   734,   735, 13004,   897,    17,
     866,  8053,  1009,    72,    54, 13004,   902,   879,   915, -1425,
    8053,  9830, 13004, 13004, 13004,  4489,   836,  8053,  8053, 13004,
    4489,   871,   872, -1425, -1425, -1425,  8053, 12720,   873, -1425,
     876, -1425, -1425, -1425, -1425,   878, -1425,   880, -1425, -1425,
   -1425, -1425, -1425,   882, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, 13004, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425,   885, 13004, -1425, -1425, -1425,   844,
    3598,    29,   884,   887,   888, 13004,  4489, -1425,   894,     6,
   -1425,   707, -1425,    41,   997,  8053, -1425, -1425,    68, -1425,
   -1425, -1425,  1017, -1425, -1425, -1425, -1425,  8053,   833, -1425,
    1012,  8053,  8053,   862,  8053,  8053,  8053,  8053,   825, 13004,
     867,   868,  8053,  8053,  3301,   812, -1425, -1425, -1425, -1425,
     105,   649,    95,    96,  1058,  5380,  5380,  5677,  5677,   609,
   -1425, -1425,   877,   609, -1425,  8053, -1425,   945,    78,   -35,
     896,   895,   898,  4489,  8053, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425,  8350,  8350,  8350, -1425,  8350,  8350, -1425,
    8350, -1425,  8350, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
    8350,  8350,   998,  8350,  8350,  8350,  8350,  8350,  8350,  8350,
    8350,  8350,  8350,  8350,  8350,   841,   975,   977,   978, -1425,
   -1425, -1425,  6865, -1425, -1425,  8944,  8944,  8053,   839, -1425,
   -1425,   839, -1425,  7162,   839,   925,  7459, -1425, -1425, -1425,
      67, -1425,    81, -1425, -1425, -1425, -1425, -1425, -1425,   968,
     970,   295,  1048, -1425, -1425, 13288,   775,   604, 13004,   919,
     920,   775,   969,   955,   949, -1425, -1425, -1425,    71,   838,
     989,   788, 13004,   946,  8053,   971, 13004, 13004, -1425,   958,
     903,  4489, -1425,   907,   876,   463, -1425,   905,   906,   188,
   -1425,   153,   200, -1425, -1425,   987, -1425,    21, 13004,    13,
   13004,  1000,   208, -1425,  4489, -1425,   211, -1425, 10122,   999,
    1051, 10122,   969,  1001,   561, 13004,  8053,   -35,   197,   912,
   -1425,   914,   916,   917,    14, -1425,   467,   921, -1425,   213,
     215,   953, -1425,   923,  4489,  4489,   219, -1425,   230,   236,
     581,  8053,    31, -1425, -1425, -1425,  8053,  8053,  8053, -1425,
    8053, -1425,  8053, -1425, 13004,   997, -1425,     4,   245, -1425,
   -1425, -1425,   287, -1425,   237, -1425, -1425, -1425,   285,   375,
    1013,   874,   890,   -13, -1425,   973, -1425, -1425,   922,   250,
    3895,   351,  9538,   812, -1425,   612,   757,  1077,  1077, -1425,
   -1425,   102, -1425, -1425,   104, -1425,    44, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, 13004,   943,  8053,  1002, -1425, -1425,
   -1425,   893, -1425, -1425, -1425, -1425, -1425,  8350, -1425, -1425,
   -1425,   124, -1425,   302,   486,   486,   519,   519,   519,   519,
     455,   455, -1425, -1425, 11566, 11566, 13004, 13004, -1425,   373,
   -1425, -1425,    22, -1425, -1425, -1425,   259, -1425, -1425,   290,
     282, -1425, -1425,   574,   631,   657, -1425,   295, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,   775, -1425,
     984, 11856,   976,  8053, -1425, -1425, -1425,  1022,   969,   969,
     775, -1425,   810,   969,   614, 13004,   309,   415,  1089, -1425,
   -1425,   837,   568, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425,    71,   671,   899,   573,  8053, -1425,
   13004,  1026,   828,   969, -1425, -1425, -1425, -1425,   974, 13004,
   -1425, 13004, -1425,  1005,  1003, 11566,  1006,  8053,   -60,   981,
      26,   483,   881, -1425, -1425,   583,    13,  1022, 11566,  1011,
    1036,   948,   936,  1004,   969,   979,  1008,  1038,   969,  8053,
     -34, -1425, -1425, -1425,   985, -1425, -1425, -1425, -1425,  1019,
    8053,  8053,   994, -1425,  1042,  1043,  4489, -1425,   960,   961,
     993, 13004, -1425, 13004, -1425,  8053,  1007,   957,  8053,   297,
     298,   301,  1112, -1425,     7, -1425,   216, -1425, -1425,  1120,
   -1425,   704,  8053,  8053,  8053,   709,  8053,  8053,  8053,  8053,
    8053,  8053,  1033,  8053,  8053, -1425,  5974,   996,  1010,  1014,
    1015,   795,   708,   909, -1425,   420, -1425,   112,   526,    44,
    5677,  5677,  5677,  1074, -1425,  8053,   656,  1049, -1425, 13004,
    1050, -1425, -1425,  8053,   124,   179,   576, -1425,   875,   421,
     904,   901, -1425, -1425,   759, -1425,   908,   502,  1020,  1021,
   11856,  1024,  1025,  1027,  1028,  1029,  1030,  1031, -1425,   571,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425,  1018, -1425, -1425, -1425,
    8053, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
     660, -1425,  1125,   773, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425,   910, -1425, -1425,  1133, -1425, -1425, -1425,
   -1425, -1425,   605,  1134, -1425,   703, -1425, -1425, -1425,   873,
     265,   878,   392,   880,   882,   806, -1425,   571,  8647,   883,
     860, -1425,  1022,   671,   947,   988,  4489,   995,  1016,  1044,
    1032,  1035, 13004,    61, -1425, 13004, -1425,  8053,  1052,  8053,
    1062,  8053,   -47,  1054,  8053,  1057, -1425,  1053,  1072,  8053,
   13004,   815,  1113, -1425, -1425, -1425, -1425, -1425, -1425, 11566,
   -1425,  4489,   969,  1090, -1425, -1425, -1425,   969,  1090, -1425,
    8053,  1056,  4489, 13004, -1425, -1425,  8053,  8053,   600, -1425,
       3,   690, -1425, 10696,   723, -1425,   725, -1425,  1023, -1425,
   -1425,  4489,  1039,  1041, -1425,  8053, -1425, -1425,  1034,  1042,
    1096, -1425,  1073, -1425,   261, -1425, -1425,  1198, -1425, -1425,
    4489, 13004, -1425,   513, -1425, -1425, -1425,  1040,   980,   983,
   -1425, -1425, -1425,   991,  1037, -1425, -1425, -1425, -1425, -1425,
     972, 13004,  1047, -1425, -1425,  8053,  8053,  8053,  4192,  5974,
    9538,   909, -1425,  9538, -1425,  1077,   129, -1425, -1425, -1425,
    1049, -1425,   969, -1425,   818, -1425,   630,  1103, -1425,  8053,
    1105,  1002,   425,  1055, -1425,   124,   965, -1425, -1425,   -77,
   -1425,   572,   -15,   967,   124,   572,  8350, -1425,    62, -1425,
   -1425, -1425, -1425, -1425, -1425,   124,  1070,   944,   838,   -15,
   -1425, -1425,   935,  1150, -1425, -1425, -1425, 10406,  1060,  1061,
    1063,  1065,  1066,  1067,  1068,  1069,  1071, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,  1204,
     -16,  1205,   -16,   990,  1131, -1425,  1079, 13004,  1046, -1425,
   -1425,  8647, -1425,  1059, -1425, -1425, -1425, -1425, -1425, -1425,
    8053,  1092, -1425, -1425,  8053, -1425,   432, -1425,  8053,  1094,
    8053, -1425,  8053, 13004, 13004, -1425,   357, -1425,  8053, -1425,
    1118,  1135,  1160,   969,  1090, -1425,  8053,  1078, -1425, -1425,
   -1425,  1080, -1425,    15,  8053,  4489,  1081,    25, -1425, 13004,
    1082, 10986,   325, -1425, 11276,  1084, -1425, -1425,  1088, -1425,
   -1425, -1425,  8053,   728,  1112, 13004,   532, -1425,  1091,  1112,
   13004, -1425, -1425,  8053,  8053,  8053,  8053,  8053, -1425,  8053,
     305,   306,   359,   449, -1425, -1425, -1425, -1425, -1425,  1103,
   -1425, -1425, -1425,   969, -1425, -1425, -1425, -1425, -1425,  1093,
    8350, -1425, -1425, -1425, -1425, -1425,   116,  8350,  8350,   495,
   -1425,   904, -1425,   423, -1425,   901,   124,  1110, -1425, -1425,
    1064, -1425, -1425, -1425, -1425,  1169,  1086, -1425,   368, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,   464,
     464, -1425,   -16, -1425, -1425,   398, -1425,  1246,   -15,  1181,
    1098,  8647,   -37,  1045,  1111, -1425, -1425,  8053, -1425,  8053,
    1136, -1425,  8053, -1425, -1425, -1425,  1232, -1425, -1425,  5974,
    8053,   969, -1425, -1425, -1425,  8053,  8053, -1425, -1425, -1425,
    5974,  5974,  1195,  4489, 13004,  1106, 13004,  8053, 13004,  1107,
    5974, -1425,   441,    16,  1112, 13004, -1425,  1095,  1112, -1425,
   -1425, -1425, -1425, -1425, -1425,  1097,  1042,  1043,  8053, -1425,
   -1425, -1425, -1425,   519,  8350,  8350,   302,   450, -1425, -1425,
   -1425, -1425, -1425, -1425,  8053, -1425, 11566, -1425, 11566,  1200,
   -1425, -1425, -1425,  1266, -1425, -1425, -1425,  1083,  1192, -1425,
   -1425,  1196, -1425,   736, 13004,  1187,  1085, 13004,  8647, -1425,
   -1425,  8053, -1425,  1188, -1425, -1425,  1090, -1425, -1425, 11566,
   -1425, -1425,  1215,  8053,  1127, -1425,  1216,  5974, -1425, 13004,
     319,   334, -1425,  1121,  1112, -1425,  1122,  5974,   732,    29,
     302,   302,  8350,   447, -1425, -1425, 11566, -1425, -1425,  1181,
    8647, -1425,  1103,  1087, 13004,  1201,  1099,  1196, -1425, 13004,
    1128, 11566,  4489, 11566,  1130, -1425, -1425,  1231,   500, -1425,
   -1425, -1425, -1425,  1143,   518, -1425, -1425, -1425,  1132, -1425,
    1209,   302, -1425, -1425, -1425, -1425, -1425,  8053,  1100, 13004,
    1211, -1425,  4489,  1144, -1425, -1425,  1147,  8053, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, 13004, -1425,  1075,  1101, 13004,
   -1425, -1425,  8053,  5974,  1148,  1102,  8053,  1104,  5974,  8647,
   -1425,  8647, -1425,  1137,  1076, 13004,  1129,  1218, 13004,  1108,
    8647, -1425
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       159,   440,   441,   442,   162,   162,   162,   781,   979,   116,
     118,   592,   873,   882,   822,   786,   784,   766,   874,   877,
     829,   790,   767,   768,   821,   883,   770,   880,   851,   831,
     806,   826,   827,   878,   875,   825,   772,   881,   773,   774,
     922,   934,   921,   823,   842,   836,   775,   824,   777,   776,
     923,   860,   861,   828,   803,   944,   945,   946,   947,   948,
     949,   950,   951,   952,   953,   954,   968,   975,   850,   846,
     837,   817,   765,     0,   845,   853,   862,   969,   841,   463,
     818,   819,   876,   970,   976,   838,   855,     0,   469,   429,
     465,   848,   783,   839,   840,   869,   843,   859,   868,   974,
     977,   789,   830,   871,   464,   858,   864,   769,     0,     0,
       0,     0,   377,   856,   867,   872,   870,   849,   835,   924,
     833,   834,   971,     0,   376,     0,   972,   978,   865,   820,
     844,   973,   407,     0,   439,   866,   847,   854,   863,   857,
     925,   811,   816,   815,   814,   813,   812,   778,   832,     0,
     782,   879,   804,   913,   912,   914,   788,   787,   807,   919,
     771,   911,   916,   917,   908,   810,   852,   910,   920,   918,
     909,   808,   915,   929,   930,   927,   928,   926,   779,   931,
     932,   933,   899,   898,   885,   802,   795,   892,   888,   805,
     801,   900,   901,   791,   792,   785,   794,   897,   896,   893,
     889,   906,   907,   905,   895,   891,   884,   793,   904,   903,
     797,   799,   798,   890,   894,   886,   800,   887,   796,   902,
     955,   956,   957,   958,   959,   960,   936,   937,   935,   941,
     942,   943,   938,   939,   940,   809,   961,   962,   963,   964,
     965,   966,   967,   159,     0,     2,   159,     5,     7,    19,
       0,    24,    27,    32,    33,    34,    35,    36,    37,    38,
      28,    54,    55,    29,    30,     0,    72,    75,    76,    31,
      77,    78,     0,   114,    79,    80,    81,    82,    14,   156,
     157,   158,   165,   167,   459,   168,     0,   169,   170,   171,
     172,   173,   174,   175,   178,   163,   204,   211,   206,   233,
     239,     0,   231,   232,   213,   207,   177,   208,   176,   209,
     212,   330,   332,   334,   344,   348,   350,   352,   355,   360,
     363,   366,   368,   370,   372,     0,   374,   380,   382,     0,
     398,   381,   403,   406,   408,   411,   413,     0,   418,   415,
       0,   426,   436,   438,   412,   443,   450,   461,   451,   452,
     453,   456,   457,   454,   455,   476,   478,   479,   480,   477,
     525,   526,   527,   528,   529,   530,   435,   566,   558,   565,
     564,   563,   560,   562,   559,   561,   462,   458,   593,   594,
      39,   214,   215,   217,   216,   218,   210,   748,   460,   744,
     745,   437,   764,   780,   873,   882,   880,   782,     0,   160,
     161,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   122,   124,   125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   258,   259,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   431,   434,   421,     0,     0,   766,   790,
     768,   821,   883,   770,   831,   772,   842,   775,   777,   776,
     860,   968,   975,   765,   969,   819,   970,   976,   843,   974,
     977,   924,   971,   972,   978,   973,   925,   919,   911,   917,
     908,   808,   929,   930,   927,   779,   931,   427,   437,   764,
     419,     0,   185,   420,   423,   766,   767,   768,   772,   773,
     774,   775,   765,   771,   466,     0,   425,   424,   180,     0,
       0,     0,   770,   777,   776,     0,   162,   746,   931,     0,
     211,     0,   467,     0,   492,     0,   430,   762,     0,   763,
     401,   402,     0,   433,   432,   422,   405,     0,     0,   521,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     1,     6,     8,
       0,     0,     0,     0,     0,   159,   159,   159,   159,     0,
     115,   166,   164,     0,   183,     0,   192,     0,     0,     0,
       0,     0,     0,     0,     0,   197,   219,   238,   234,   240,
     235,   237,   236,     0,     0,     0,   391,     0,     0,   389,
       0,   339,     0,   390,   383,   388,   387,   386,   385,   384,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   379,
     378,   375,     0,   399,   404,     0,     0,     0,   414,   447,
     417,   416,   428,     0,   444,     0,     0,   532,   534,   538,
       0,   120,     0,   761,    43,    40,    41,    44,    45,     0,
       0,     0,     0,    46,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   603,   604,   605,     0,    99,
     138,     0,     0,   108,     0,     0,     0,     0,   123,     0,
       0,     0,   572,     0,     0,     0,   568,     0,     0,     0,
     582,     0,     0,   221,   222,   241,   242,     0,     0,     0,
       0,   130,     0,   134,   162,   596,     0,    56,     0,    65,
       0,     0,     0,    57,     0,     0,     0,     0,     0,     0,
     573,     0,     0,     0,     0,   303,     0,     0,   571,     0,
       0,     0,   590,     0,     0,     0,     0,   576,     0,     0,
     187,     0,     0,   181,   179,   629,     0,     0,     0,   466,
       0,   747,     0,   468,   493,   492,   489,     0,     0,   523,
     522,   400,     0,   520,     0,   616,   617,   567,     0,     0,
       0,     0,     0,     0,   622,     0,   195,   196,     0,     0,
       0,     0,     0,   200,   201,    20,     0,    21,     0,     4,
      25,     0,    11,    26,     0,    15,   873,    73,    12,    74,
      16,   186,   184,   205,     0,     0,     0,     0,   198,   220,
     276,   331,   333,   337,   343,   342,   341,     0,   338,   335,
     336,     0,   349,   351,   354,   353,   357,   358,   359,   356,
     361,   362,   365,   364,     0,     0,     0,     0,   396,     0,
     409,   410,     0,   448,   445,   474,     0,   595,   472,     0,
       0,   117,   119,     0,     0,     0,    98,     0,    88,    90,
      91,    92,    93,    95,    96,    97,    89,    94,    84,    85,
       0,     0,   104,     0,   100,   102,   103,   110,     0,     0,
      83,    42,     0,     0,     0,     0,     0,     0,     0,   694,
     699,     0,     0,   695,   729,   682,   684,   685,   686,   688,
     690,   689,   687,   691,     0,     0,     0,     0,     0,   107,
       0,   140,     0,     0,   537,   531,   569,   570,     0,     0,
     586,     0,   583,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   223,   224,     0,   229,   136,     0,     0,
     131,     0,     0,     0,     0,     0,     0,    58,     0,     0,
       0,   257,   263,   260,     0,   575,   574,   581,   589,     0,
       0,     0,     0,   536,     0,     0,     0,   392,     0,     0,
       0,     0,   579,     0,   577,     0,   188,     0,     0,     0,
       0,     0,   492,   490,     0,   481,     0,   470,   471,     0,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   193,     0,   770,   777,   776,
     931,     0,     0,     0,   630,     0,   202,     0,     0,     0,
     159,   159,   159,     0,   230,     0,   287,   283,   285,     0,
     277,   278,   340,     0,     0,     0,     0,   660,   346,   633,
     637,   639,   641,   643,   646,   653,   654,   662,   883,   769,
       0,   778,     0,     0,     0,     0,     0,     0,   367,   543,
     549,   550,   552,   597,   598,   553,   554,   749,   750,   751,
     752,   753,   754,   557,   369,   371,   540,   373,   397,   449,
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
       0,     0,     0,     0,     0,     0,     0,   546,   548,   547,
     544,   541,   475,   129,   128,    87,   101,   717,   698,     0,
     722,     0,   722,   711,   706,   143,     0,     0,     0,   113,
     141,     0,    23,     0,   587,   588,   591,   584,   585,   243,
       0,     0,   256,   248,     0,   252,     0,   246,     0,     0,
       0,   265,     0,     0,     0,   227,   268,   271,     0,   133,
       0,     0,    66,     0,    60,   262,     0,     0,   304,   306,
     311,     0,   309,     0,     0,     0,     0,     0,   315,     0,
       0,     0,     0,   322,     0,     0,   326,   395,     0,   580,
     578,   190,     0,     0,   492,     0,     0,   524,     0,   492,
       0,   488,    10,     0,     0,     0,     0,     0,   623,     0,
       0,     0,     0,     0,   627,   631,   300,   298,   299,   292,
     293,   294,   286,     0,   281,   279,   661,   652,   658,     0,
       0,   731,   732,   742,   741,   740,     0,     0,     0,     0,
     733,   638,   739,     0,   636,   640,     0,     0,   645,   649,
       0,   670,   665,   668,   664,     0,     0,   555,     0,   551,
     602,   545,   757,   760,   755,   756,   759,   758,   718,     0,
       0,   716,   723,   724,   720,     0,   715,     0,   713,     0,
       0,     0,     0,     0,     0,   533,   245,     0,   254,     0,
       0,   250,     0,   253,   266,   274,   275,   269,   226,     0,
       0,     0,    62,   264,   539,     0,     0,   312,   316,   310,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   535,     0,     0,   492,     0,   519,     0,   492,   607,
     608,   612,   613,   619,   621,     0,     0,     0,     0,   628,
     295,   282,   656,   743,     0,     0,   735,     0,   681,   680,
     679,   678,   677,   642,     0,   734,     0,   599,     0,     0,
     727,   726,   725,     0,   719,   712,   710,     0,   707,   708,
     702,   144,   146,   148,     0,     0,     0,     0,     0,   249,
     247,     0,   255,     0,   199,   329,    68,   307,   313,     0,
     327,   323,     0,     0,     0,   317,     0,     0,   319,     0,
     502,   496,   491,     0,   492,   483,     0,     0,     0,     0,
     737,   736,     0,     0,   600,   556,     0,   721,   714,     0,
       0,   150,   149,     0,     0,     0,     0,   145,   251,     0,
       0,     0,     0,     0,     0,   510,   504,     0,   503,   505,
     511,   508,   498,     0,   497,   499,   509,   485,     0,   484,
       0,   738,   650,   601,   709,   147,   151,     0,     0,     0,
       0,   273,     0,     0,   320,   318,     0,     0,   495,   506,
     507,   494,   500,   501,   486,     0,   152,     0,     0,     0,
     328,   324,     0,     0,     0,     0,     0,     0,     0,     0,
     154,     0,   153,     0,     0,     0,     0,     0,     0,     0,
       0,   155
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1425, -1425,  -221,  1114, -1425,  1109,  1116, -1425,  1115,  -507,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
    -944, -1425, -1425, -1425, -1425,  -216,  -556, -1425,   645,   -90,
   -1425, -1425, -1425, -1425, -1425,   218,   442, -1425, -1425,    -9,
    -205,   950, -1425,   924, -1425, -1425,  -609, -1425,   374, -1425,
     187, -1425,  -267,  -304, -1425,  -538, -1425,     5,    33,    69,
    -171,  -160, -1425,  -833, -1425, -1425,  -424, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425,   545,   -84,  1310,
       0, -1425, -1425, -1425, -1425,   393, -1425, -1425,  -285, -1425,
       8, -1425, -1425,   191,  -691,  -685, -1425, -1425,   613, -1425,
   -1425,   -29,   174, -1425, -1425, -1425,    70, -1425, -1425,   315,
      73, -1425, -1425,    77, -1237, -1425,   849,   162, -1425, -1425,
     158,  -964, -1425, -1425,   156, -1425, -1425, -1200, -1173, -1425,
     157, -1425, -1425,   771,   772, -1425,  -426, -1425, -1425,   754,
    -627,   307,  -617,   308,   304, -1425, -1425, -1425, -1425, -1425,
    1117, -1425, -1425, -1425, -1425,  -766,  -311, -1081, -1425,   -80,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425,   -30,  -777, -1425,
   -1425,   563,   123, -1425,  -402, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425,   719, -1425,  -970, -1425,   144, -1425,   606,  -757,
   -1425, -1425, -1425, -1425, -1425,  -292,  -284, -1195,  -904, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,   528,
    -729,  -804,   239,  -814, -1425,    85,  -775, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425,   966,   986,  -335,   448,   278, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425,   130, -1425, -1425,   121,   -48,   113, -1019,
   -1425, -1425, -1425,    99,    82,   -76,   344, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
     101, -1425, -1425, -1425,   -69,   342,   488, -1425, -1425, -1425,
   -1425, -1425,   272, -1425, -1425, -1424, -1425, -1425, -1425,  -555,
   -1425,    58, -1425,   -88, -1425, -1425, -1425, -1425, -1260, -1425,
     110, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425,  -388,  -363,   886,    98, -1425
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   244,   818,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
    1203,   742,   262,   263,   264,   265,   266,   267,   898,   899,
     900,   268,   269,   270,   904,   905,   906,   271,   423,   272,
     273,   670,   274,   425,   426,   427,   440,   732,   733,   275,
    1156,   276,  1611,  1612,   277,   278,   279,   529,   280,   281,
     282,   283,   284,   735,   285,   286,   512,   287,   288,   289,
     290,   291,   292,   605,   293,   294,   813,   814,   295,   296,
     540,   298,   606,   438,   965,   966,   299,   607,   300,   609,
     541,   302,   725,   726,  1191,   447,   303,   448,   449,   729,
    1192,  1193,  1194,   610,   611,  1060,  1061,  1464,   612,  1057,
    1058,  1295,  1296,  1297,  1298,   304,   754,   755,   305,  1218,
    1219,  1413,   306,  1221,  1222,   307,   308,  1224,  1225,  1226,
    1227,   309,   310,   311,   312,   847,   313,  1307,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   630,   631,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   658,   659,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   876,   354,   355,   356,  1253,   785,   786,   787,
    1642,  1683,  1684,  1677,  1678,  1685,  1679,  1254,  1255,   357,
     358,  1256,   359,   360,   361,   362,   363,   364,   365,  1105,
     960,  1088,  1350,  1089,  1498,  1090,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   761,  1168,   376,   377,
     378,   379,  1092,  1093,  1094,  1095,   380,   381,   382,   383,
     384,   385,   803,   804,   386,  1281,  1282,   387,  1045,  1068,
    1317,  1318,  1069,  1070,  1071,  1072,  1073,  1327,  1488,  1489,
    1074,  1330,  1075,  1469,  1076,  1077,  1335,  1336,  1494,  1492,
    1319,  1320,  1321,  1322,  1591,   699,   925,   926,   927,   928,
     929,   930,  1146,  1520,  1608,  1147,  1518,  1606,   931,  1362,
    1515,  1511,  1512,  1513,   932,   933,  1323,  1331,  1479,  1324,
    1475,  1308,   388,   389,   390,  1096,  1097,  1098,  1099,  1100,
    1101,  1102,  1204,   548,   391,   392,   393
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       297,   671,   671,   424,   297,   297,   297,   853,   301,   398,
     401,   402,   301,   301,   301,   980,   608,   674,   653,   575,
     856,   857,   858,   859,   531,   539,   543,   992,  1014,   586,
    1220,   827,   829,   583,  1208,  1044,   958,   399,   399,   399,
    1433,  1006,   959,   507,   588,  1303,  1252,   822,   825,   828,
     830,  1423,  1119,   556,   694,   739,   743,   954,  1441,  1460,
    1461,  1104,  1180,     9,    10,   709,   558,   590,   962,  1490,
       9,    10,   885,   400,   400,   400,   789,  1366,   820,   823,
    1614,  1476,   445,   673,   409,  1066,  1177,  1123,   751,  1091,
    1091,   409,   584,  1032,   584,  1609,   584,   584,   593,  1388,
     410,   673,  1414,   584,   714,   584,   459,  1210,   297,  1640,
     591,   412,   595,   584,  1414,   955,   301,   956,   412,  1509,
     989,   715,   956,   413,  1414,   914,  1091,   915,   595,     9,
      10,     9,    10,  1015,   730,   595,  1243,   989,  1471,   655,
     656,   399,   405,   406,   435,   407,   408,   595,   705,   436,
     675,  1174,   409,    11,   414,   415,  1053,   956,  1309,   454,
    1157,   410,   411,   676,  1197,   831,   740,   957,  1584,   832,
     916,   509,  1181,   880,   689,  1472,   690,   530,  1126,   412,
    1091,   594,   460,  1510,   413,   509,  1615,   880,  1415,   843,
     781,   844,   845,  1091,   846,   437,   848,   592,  1641,  1016,
    1546,   990,  1244,   731,   849,   850,  1109,  1380,    11,   509,
    1551,   446,   775,   741,   589,   414,   415,   416,  1008,   590,
    1033,   509,  1580,   509,   446,  1245,  1246,   783,   963,   591,
    1310,   738,  1185,    79,   692,  1694,   446,   446,  1196,  1477,
    1478,  1441,   790,   297,  1585,   716,   297,    90,   559,   461,
     462,   301,   654,   881,   301,  1242,   608,  1417,  1607,   949,
    1423,   827,   829,  1404,   417,   964,  1339,   882,  1616,  1182,
    1245,  1246,   104,  1178,  1252,  1183,  1063,   403,  1120,  1064,
     585,   297,   587,  1252,   815,   817,  1468,  1354,    79,   301,
    1524,  1050,   446,  1052,   595,  1211,   693,   446,  1066,  1066,
     125,  1285,    90,   595,   911,  1091,   951,   660,   820,   823,
     662,    11,  1311,  1312,   969,  1313,   592,   595,  1247,   595,
     917,   595,   706,   418,  1675,   595,   404,   104,  1245,   420,
     707,  1063,  1315,   918,  1064,   919,  1001,   421,  1248,   950,
    1249,   428,  1003,  1245,  1316,   422,   920,   921,   922,   719,
     923,   595,   924,   465,   977,   125,   595,   736,   689,   591,
     690,   816,  1681,  1247,   419,  1110,   748,  1019,  1250,   821,
     824,   948,   111,   759,   760,   973,  1661,  1648,   976,  1021,
     984,  1065,   766,  1248,   466,  1249,   952,   467,  1157,   123,
     420,    79,   691,   595,   970,  1399,  1110,   972,   421,   994,
     297,   995,  1000,   595,   595,    90,   422,   595,   301,  1251,
    1187,   595,   595,  1250,   431,  1188,  1002,   111,   692,  1420,
     432,  1062,  1004,   652,  1091,  1696,  1020,   149,  1017,   297,
     104,   297,   838,  1369,   123,   509,  1036,   301,   509,   301,
    1613,  1248,  1556,  1249,   634,  1111,   592,   125,  1091,  1067,
     439,  1676,   531,   956,  1435,   297,  1248,   595,  1249,   635,
     297,   788,   710,   301,   713,   595,  1252,  1682,   301,  1025,
    1018,  1250,   149,   792,  1598,  1423,  1112,   636,  1113,   595,
     693,   635,  1381,  1238,  1239,   441,  1250,  1240,   757,   809,
     811,  1575,  1576,   763,   827,   829,   827,  1389,   711,   636,
     711,  1022,  1023,  1044,  1603,  1675,  1455,   681,   509,  1245,
    1557,   509,  1287,  1288,  1289,   509,  1024,  1309,   509,   509,
    1127,  1128,  1245,  1246,   711,  1131,   509,  1245,   956,   711,
     297,   595,   509,  1497,  1043,   509,   297,  1613,   301,  1066,
     591,  1245,  1246,   509,   301,  1577,  1681,   452,  1066,   509,
     509,   509,   509,   595,  1599,  1165,  1108,   509,  1639,  1066,
    1359,   955,  1091,   405,   406,   509,   407,   408,   869,   399,
    1137,   424,  1278,   872,   297,   870,   871,   955,  1529,  1613,
     635,  1138,   301,   411,  1604,   297,   297,   297,   297,  1310,
     643,  1026,  1027,   301,   301,   301,   301,  1626,   636,  1047,
    1051,  1578,   637,   297,   644,   400,  1028,   635,  1466,   509,
     463,   301,  1417,   991,  1167,  1247,  1170,  1555,   453,  1361,
    1559,   683,  1248,   509,  1249,   636,  1557,   592,  1283,  1184,
    1692,   638,  1709,   509,  1247,  1248,  1187,  1249,  1286,   591,
    1248,  1188,  1249,   810,   639,   580,  1091,  1652,  1732,  1091,
    1733,  1712,  1250,   684,  1248,   955,  1249,  1283,   457,  1741,
    1189,   581,  1067,  1067,  1143,  1250,  1232,   509,  1233,   111,
    1250,  1311,  1312,   442,  1313,   955,  1139,  1563,   640,   956,
    1144,  1314,  1567,   443,  1250,   417,   123,  1140,   111,  1483,
    1588,  1315,  1009,  1010,  1011,  1530,   811,  1589,   901,  1217,
    1190,  1359,   979,  1316,   597,   123,  1440,  1590,   598,   444,
    1149,   297,  1411,   599,  1347,  1150,   714,  1360,   641,   301,
    1066,  1114,  1005,  1145,   149,  1565,   511,   642,  1305,   827,
    1151,   600,  1152,   715,   297,  1292,  1680,  1686,  1115,   971,
     902,  1153,   301,   149,   418,   903,  1348,  1332,  1333,   597,
     597,  1291,   125,   598,   598,   653,  1294,   608,   599,   599,
    1361,  1292,  1588,  1349,   297,   297,   458,   399,  1154,  1589,
    1334,  1293,   301,   301,  1680,   679,   600,   600,  1116,  1590,
    1686,   873,  1294,   887,   873,   419,   509,   873,   677,  1217,
    1048,   680,  1654,  1118,  1655,  1117,  1353,   998,   999,  1143,
     509,   678,  1416,   400,   509,   509,   581,  1643,  1121,   734,
    1041,  1646,   734,   429,  1402,  1144,   430,   424,  1042,   464,
    1121,  1091,  1421,  1091,  1424,  1670,   509,  1421,   509,   601,
     955,  1421,   602,   711,   711,  1422,   509,  1425,  1473,   509,
    1562,  1292,   510,   509,  1690,  1474,   433,   603,   513,   434,
    1586,  1587,  1693,  1583,  1091,   888,   889,   890,   891,   892,
     893,   894,   895,   896,   897,  1274,   567,  1703,  1187,  1706,
    1159,   568,   604,  1188,   601,   601,   514,   602,   602,  1160,
     575,  1091,   509,   703,  1662,  1284,   526,  1688,   704,  1132,
    1133,  1134,   782,  1279,  1155,  1135,  1091,   615,  1091,   695,
     696,   697,   661,  1067,  1456,   616,   617,   664,   618,   902,
     509,   561,  1067,   562,   903,   525,   619,   604,   604,   545,
     620,   450,   621,  1067,   451,   527,   455,   622,   564,   456,
     565,   657,   509,   663,  1258,   546,  1259,  1129,  1130,  1263,
     553,  1264,   854,   855,   623,  1457,  1458,   862,   863,   860,
     861,  1106,  1106,   554,  1600,  1601,   555,  1650,  1651,   508,
     557,   563,   509,   509,   509,   509,   560,   624,   625,   626,
     627,   628,   629,   524,   566,   569,   570,   571,   573,  1302,
     572,   574,   577,   595,   596,   614,   613,   633,   632,   645,
     646,   647,   657,   648,   665,   666,   297,   544,   673,   509,
     667,   685,   687,   698,   301,   668,   688,   669,   702,   549,
     737,   552,   712,   509,   728,  1542,   723,   724,   734,   745,
     746,   747,   758,   764,   765,  1691,   771,   773,   430,  1228,
    1400,   434,   784,   451,   791,   456,  1041,   467,   509,   776,
     424,   794,   777,   778,  1042,   793,   780,   509,   797,   509,
     297,   297,   297,   509,   802,   812,   806,   807,   301,   301,
     301,   819,   834,   835,   836,   711,   509,   837,   851,   865,
     864,   866,   867,   877,   883,  1581,   884,   886,   908,   909,
     913,   912,   934,   935,  1067,   936,   944,   938,   940,   943,
     945,   946,   947,   953,   968,   974,   975,   978,   985,   509,
     986,   509,   987,   988,   993,   996,   997,  1029,   838,  1030,
    1049,  1035,  1055,  1031,  1034,  1122,   955,   903,  1141,  1059,
    1163,  1142,  1172,  1175,  1158,  1164,  1166,  1179,   730,  1173,
    1199,  1200,  1201,  1186,  1207,  1202,  1213,  1212,  1205,  1206,
    1216,  1217,  1223,  1229,  1230,  1231,  1236,  1241,  1235,  1257,
    1271,  1275,  1280,   691,    11,  1299,  1301,   509,  1306,  1326,
    1325,  1351,  1358,  1363,  1368,  1276,   297,  1278,  1367,  1277,
    1393,  1373,  1371,  1329,   301,  1337,  1338,  1372,   509,  1340,
    1341,  1374,  1342,  1343,  1344,  1345,  1346,  1376,  1386,  1394,
    1398,  1450,  1451,  1452,  1357,  1421,  1403,  1406,  1384,   399,
    1390,   297,  1375,  1392,  1434,  1437,  1427,  1447,  1292,   301,
    1463,  1443,   297,  1470,  1444,  1480,  1486,  1407,  1377,  1491,
     301,  1378,  1445,   508,  1487,  1429,   508,  1430,  1493,  1442,
    1432,   297,  1449,  1508,  1514,   400,  1428,  1519,  1527,   301,
    1532,  1467,  1525,  1539,  1548,   399,  1499,  1500,  1521,  1501,
     297,  1502,  1503,  1504,  1505,  1506,  1541,  1507,   301,  1517,
    1540,  1544,  1594,  1596,   399,  1545,  1550,  1553,  1446,  1560,
     509,  1561,  1597,   509,  1566,  1605,  1582,  1143,  1041,  1041,
    1618,   400,  1621,  1438,  1610,  1623,  1042,  1042,   509,  1629,
    1645,  1633,  1637,  1647,  1656,  1657,   682,   509,  1659,   686,
     400,  1523,  1660,   549,  1664,  1669,   700,   701,  1665,  1671,
    1673,   509,  1672,  1702,   549,  1707,  1687,  1689,  1699,   711,
     722,   509,  1700,   727,  1708,  1711,  1715,  1714,  1719,  1722,
    1617,   744,  1723,  1728,  1734,  1738,   910,   549,   752,   753,
     756,  1356,  1595,  1198,  1124,   762,  1658,   810,   708,   509,
    1370,  1667,  1737,   769,   672,   578,  1695,   576,  1046,  1195,
     983,  1735,   579,  1379,   582,  1397,  1725,  1537,  1624,   509,
    1290,  1465,  1462,  1459,   772,  1408,  1412,  1418,   509,  1628,
    1548,   509,  1630,  1426,   841,   879,   842,   852,  1436,  1638,
    1697,  1013,  1713,  1453,  1710,  1107,  1365,   770,   717,  1171,
    1355,  1448,  1454,  1717,  1726,  1579,  1729,  1485,  1731,  1304,
    1593,   756,  1740,  1481,  1592,   297,  1328,  1364,   718,  1484,
    1516,   779,  1148,   301,  1602,  1482,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   509,     0,     0,     0,     0,
       0,     0,   651,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   805,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   509,  1630,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1400,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   509,   509,     0,  1649,     0,     0,     0,     0,     0,
       0,  1704,     0,     0,     0,     0,     0,     0,     0,     0,
    1653,     0,     0,     0,     0,     0,     0,   509,     0,   509,
       0,     0,   509,     0,     0,     0,     0,     0,     0,     0,
       0,  1720,     0,   509,     0,     0,     0,     0,   509,  1041,
       0,     0,     0,     0,     0,     0,     0,  1042,     0,     0,
    1041,  1041,  1720,   297,     0,     0,     0,  1704,  1042,  1042,
    1041,   301,     0,     0,     0,     0,     0,     0,  1042,     0,
       0,     0,     0,     0,   907,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   937,     0,
       0,     0,   941,   942,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   961,     0,   967,     0,     0,     0,
       0,     0,     0,     0,   549,     0,     0,   549,     0,     0,
       0,   981,     0,     0,     0,     0,     0,  1041,     0,     0,
       0,     0,     0,     0,     0,  1042,     0,  1041,     0,     0,
       0,     0,   509,     0,   509,  1042,   509,     0,     0,     0,
       0,     0,     0,   509,     0,     0,     0,     0,     0,     0,
    1012,     0,   297,     0,     0,     0,     0,     0,     0,     0,
     301,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   509,     0,   509,     0,   508,     0,
       0,     0,   297,     0,     0,     0,     0,     0,     0,     0,
     301,     0,   509,     0,     0,   509,     0,     0,     0,     0,
    1054,     0,     0,  1041,     0,     0,     0,   509,  1041,     0,
       0,  1042,     0,     0,     0,     0,  1042,   509,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1103,  1103,  1103,  1103,   509,     0,     0,     0,     0,     0,
       0,     0,   509,     0,     0,     0,     0,   509,     0,   509,
       0,   509,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   509,     0,     0,
       0,  1136,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   509,     0,     0,     0,   509,     0,     0,
       0,     0,     0,     0,     0,     0,  1162,     0,     0,     0,
       0,     0,     0,   509,     0,  1169,   509,  1169,     0,     0,
       0,  1103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   795,   796,     0,   798,   799,   800,   801,     0,     0,
       0,     0,   808,     0,     0,     0,     0,   762,     0,   762,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   833,     0,     0,     0,     0,
       0,     0,     0,   839,   840,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1300,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1103,     0,     0,     0,
       0,     0,     0,   875,     0,     0,   875,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   939,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   982,     0,   727,     0,
       0,  1382,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1396,     0,     0,     0,
       0,  1007,     0,     0,     0,  1103,     0,     0,     0,     0,
       0,     0,   839,     0,     0,     0,     0,     0,     0,   756,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1439,     0,     0,
       0,     0,     0,     0,     0,     0,  1056,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   805,     0,     0,
       0,     0,     0,     0,     0,     0,   508,     0,     0,   508,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1161,     0,
       0,     0,     0,  1522,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1176,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1535,
    1536,     0,     0,     0,     0,     0,     0,     0,     0,  1209,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1214,  1215,     0,     0,     0,  1552,     0,  1103,     0,     0,
    1103,     0,     0,     0,     0,  1234,     0,     0,  1237,     0,
       0,  1564,     0,     0,     0,     0,  1568,     0,     0,     0,
       0,     0,  1260,  1261,  1262,     0,  1265,  1266,  1267,  1268,
    1269,  1270,     0,  1272,  1273,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1056,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1352,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1632,     0,  1634,     0,  1636,     0,     0,     0,     0,     0,
       0,  1644,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1103,     0,  1103,     0,     0,  1383,     0,  1385,
       0,  1387,     0,     0,  1391,     0,     0,     0,     0,  1395,
    1663,     0,     0,  1666,     0,     0,     0,     0,     0,     0,
       0,  1401,     0,     0,     0,  1103,     0,     0,     0,     0,
    1405,     0,     0,     0,     0,  1674,  1409,  1410,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1103,     0,     0,  1431,     0,     0,     0,     0,
    1698,     0,     0,     0,     0,  1701,     0,  1103,     0,  1103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1718,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1724,     0,     0,     0,  1727,     0,     0,     0,  1056,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1736,     0,     0,  1739,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1526,     0,     0,     0,  1528,     0,     0,     0,  1531,     0,
    1533,     0,  1534,     0,     0,     0,     0,     0,  1538,     0,
       0,     0,     0,     0,     0,     0,  1543,     0,     0,     0,
       0,     0,     0,     0,  1547,  1549,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1401,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1569,  1570,  1571,  1572,  1573,     0,  1574,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1619,     0,  1620,
       0,     0,  1622,     0,     0,     0,     0,     0,     0,     0,
    1625,     0,     0,     0,     0,  1627,  1549,     0,     0,     0,
       0,     0,     0,  1631,     0,     0,     0,  1635,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1668,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1631,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1705,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1716,     0,     0,
       0,     0,  1721,     0,     0,     1,     2,  1705,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,  1721,    11,     0,     0,  1730,    12,    13,     0,
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
     241,   242,     1,     2,     0,     0,     0,     0,   243,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,     0,
      11,     0,     0,     0,   394,   395,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
     396,    28,    29,    30,    31,     0,    32,    33,    34,    35,
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
     126,   127,   128,     0,   528,     0,   129,     0,   130,   131,
       0,   132,   133,   134,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,   149,     0,   397,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,   394,   395,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,   396,    28,    29,
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
       0,   774,     0,   129,     0,   130,   131,     0,   132,   133,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   397,   151,   152,   153,   154,   155,   156,   157,   158,
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
       8,     9,    10,     0,    11,     0,     0,     0,   394,   395,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,  1037,   396,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,  1038,  1039,    50,
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
     124,   125,     0,     0,   126,   127,   128,     0,   774,     0,
     129,     0,   130,   131,     0,   132,   133,   134,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,   149,     0,   397,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,  1040,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,     0,     0,     0,   394,   395,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    1037,   396,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,  1038,  1039,    50,    51,    52,    53,
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
       0,   126,   127,   128,     0,   528,     0,   129,     0,   130,
     131,     0,   132,   133,   134,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,   149,     0,   397,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,  1040,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,     0,    11,     0,
       0,     0,   394,   395,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,   396,    28,
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
     149,     0,   397,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     1,     2,     0,
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
     239,   240,   241,   242,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,     0,    11,     0,     0,     0,    12,    13,     0,    14,
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
     103,   104,   105,   106,   107,   108,   109,     0,   110,   111,
     112,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   124,   125,
       0,     0,   126,   127,   128,     0,     0,     0,   129,     0,
     130,   131,     0,   132,   133,   134,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,   149,     0,   397,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
       0,     0,     0,    12,   395,     0,    14,    15,    16,    17,
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
     148,   149,     0,   397,   151,   152,   153,   154,   155,   156,
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
     826,   395,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,   396,    28,    29,    30,
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
     397,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,   394,   395,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,  1037,   396,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,  1038,  1039,    50,    51,
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
     146,     0,     0,   147,   148,   149,     0,   397,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,  1040,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     0,     0,     0,
      11,     0,     0,     0,   394,   395,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   532,
     396,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,   533,   534,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,   485,    82,    83,    84,    85,    86,   535,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,    96,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   536,   109,     0,   110,   111,   112,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,     0,   123,     0,   124,   125,     0,     0,
     126,   127,   128,     0,     0,   537,   129,     0,   130,   131,
       0,   132,   133,   134,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,   149,     0,   397,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   502,   503,   504,
     176,   177,   505,   538,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   394,   395,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   532,   396,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     533,   534,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,    74,    75,    76,
       0,     0,    77,    78,     0,     0,     0,    79,    80,   485,
      82,    83,    84,    85,    86,   535,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,    96,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     536,   109,     0,   110,   111,   112,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,     0,   124,   125,     0,     0,   126,   127,   128,
       0,     0,     0,   129,   542,   130,   131,     0,   132,   133,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   397,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   502,   503,   504,   176,   177,   505,
     538,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     0,     0,    11,     0,     0,     0,   394,   395,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   532,   396,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,   533,   534,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   485,    82,    83,    84,
      85,    86,   535,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   536,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,   868,     0,
     129,     0,   130,   131,     0,   132,   133,   134,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,   149,     0,   397,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   502,   503,   504,   176,   177,   505,   538,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   394,   395,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     532,   396,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,   533,   534,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,    74,    75,    76,     0,     0,    77,    78,     0,     0,
       0,    79,    80,   485,    82,    83,    84,    85,    86,   535,
      88,    89,     0,     0,     0,    90,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,    96,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   536,   109,     0,   110,   111,   112,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,     0,   123,     0,   124,   125,     0,
       0,   126,   127,   128,     0,     0,     0,   129,   874,   130,
     131,     0,   132,   133,   134,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,   149,     0,   397,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   502,   503,
     504,   176,   177,   505,   538,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     0,     0,     0,    11,     0,
       0,     0,   394,   395,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   532,   396,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,   533,   534,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     485,    82,    83,    84,    85,    86,   535,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   536,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,   878,   130,   131,     0,   132,
     133,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   397,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   502,   503,   504,   176,   177,
     505,   538,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     0,     0,     0,    11,     0,     0,     0,   394,
     395,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   471,    25,   473,   396,    28,   474,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,   476,     0,    45,    46,    47,   478,   479,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,   485,    82,    83,
      84,    85,    86,   535,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     488,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   536,   109,
       0,   110,   111,   649,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,     0,   123,
       0,   650,   125,     0,     0,   126,   127,   128,     0,     0,
       0,   129,     0,   130,   131,     0,   132,   133,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   397,
     151,   152,   153,   154,   155,   156,   157,   158,   497,   160,
     498,   162,   499,   500,   165,   166,   167,   168,   169,   170,
     501,   172,   502,   503,   504,   176,   177,   505,   506,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     0,
       0,     0,    11,     0,     0,     0,   394,   395,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   532,   396,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,   533,   534,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   485,    82,    83,    84,    85,    86,
     535,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   536,   109,     0,   110,   111,
     112,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   124,   125,
       0,     0,   126,   127,   128,     0,     0,     0,   129,     0,
     130,   131,     0,   132,   133,   134,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,   149,     0,   397,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   502,
     503,   504,   176,   177,   505,   538,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     0,     0,     0,    11,
       0,     0,     0,   394,   395,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   471,    25,   473,   396,
      28,   474,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,   476,     0,    45,
      46,    47,   478,   479,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,    74,
      75,    76,     0,     0,    77,    78,     0,     0,     0,    79,
      80,   485,    82,    83,    84,    85,    86,   535,    88,    89,
       0,     0,     0,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   488,    97,    98,    99,   100,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   536,   109,     0,   110,   111,   112,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,     0,   123,     0,   124,   125,     0,     0,   126,
     127,   128,     0,     0,     0,   129,     0,   130,   131,     0,
     132,   133,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   397,   151,   152,   153,   154,   155,   156,
     157,   158,   497,   160,   498,   162,   499,   500,   165,   166,
     167,   168,   169,   170,   501,   172,   502,   503,   504,   176,
     177,   505,   506,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     0,     0,     0,    11,     0,     0,     0,
     394,   395,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,   471,    25,   473,   396,    28,   474,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,   476,     0,    45,    46,    47,   478,
     479,    50,   480,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,   485,    82,
      83,    84,    85,    86,   535,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   488,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   536,
     109,     0,   110,   111,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,     0,
     123,     0,     0,     0,     0,     0,   126,   127,   128,     0,
       0,     0,   129,     0,   130,   131,     0,   132,   133,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     397,   151,   152,   153,   154,   155,   156,   157,   158,   497,
     160,   498,   162,   499,   500,   165,   166,   167,   168,   169,
     170,   501,   172,   502,   503,   504,   176,   177,   505,   506,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   394,   395,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     471,    25,   473,   396,    28,   474,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,   476,     0,    45,    46,    47,   478,   479,    50,   480,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,    74,    75,    76,     0,     0,    77,    78,
       0,     0,     0,    79,    80,   485,    82,    83,    84,    85,
      86,   535,    88,    89,     0,     0,     0,    90,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   488,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   536,   109,     0,   110,
     111,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,     0,   123,     0,     0,
       0,     0,     0,   126,   127,   128,     0,     0,     0,   129,
       0,   130,   131,     0,     0,     0,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   397,   151,   152,
     153,   154,   155,   156,   157,   158,   497,   160,   498,   162,
     499,   500,   165,   166,   167,   168,   169,   170,   501,   172,
     502,   503,   504,   176,   177,   505,   506,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     0,     0,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,   394,   395,     0,    14,    15,    16,
     468,    18,    19,    20,   469,    22,   470,   471,   472,   473,
     396,    28,   474,    30,    31,     0,    32,    33,    34,    35,
     475,    37,    38,    39,    40,    41,    42,    43,   476,     0,
      45,   477,    47,   478,   479,    50,   480,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   481,   482,    68,     0,    69,    70,    71,   483,     0,
      74,    75,    76,     0,     0,   484,    78,     0,     0,     0,
       0,    80,   485,    82,   486,   487,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   488,    97,    98,   489,   490,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,   107,     0,     0,     0,     0,     0,     0,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   491,
     120,   121,   492,     0,     0,     0,     0,     0,     0,     0,
     493,   494,   128,     0,     0,     0,   129,     0,   130,   495,
       0,     0,     0,   134,     0,   135,     0,   136,   137,   138,
     139,   496,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,     0,     0,   397,   151,   152,   153,   154,   155,
     156,   157,   158,   497,   160,   498,   162,   499,   500,   165,
     166,   167,   168,   169,   170,   501,   172,   502,   503,   504,
     176,   177,   505,   506,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,   394,   395,     0,    14,    15,    16,   515,    18,    19,
      20,   469,   516,   517,   471,   472,   473,   396,    28,   474,
      30,    31,     0,    32,    33,    34,    35,   518,    37,   519,
     520,    40,    41,    42,    43,   476,     0,    45,   521,    47,
     478,   479,    50,   480,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,   481,   482,
      68,     0,    69,    70,    71,   522,     0,    74,    75,    76,
       0,     0,   484,    78,     0,     0,     0,     0,    80,   485,
      82,   486,   487,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   488,    97,    98,   489,   490,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,   107,
       0,     0,     0,     0,     0,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   491,   120,   121,   492,
       0,     0,     0,     0,     0,     0,     0,   493,   494,   128,
       0,     0,     0,   129,     0,   130,   495,     0,     0,     0,
     134,     0,   135,     0,   136,   137,   138,   139,   496,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,     0,
       0,   397,   151,   152,   153,   154,   155,   156,   157,   158,
     497,   523,   498,   162,   499,   500,   165,   166,   167,   168,
     169,   170,   501,   172,   502,   503,   504,   176,   177,   505,
     506,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   547,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     0,     0,   749,
       0,     0,     0,   394,   395,     0,    14,    15,    16,   515,
      18,    19,    20,   469,   516,   517,   471,   472,   473,   396,
      28,   474,    30,    31,     0,    32,    33,    34,    35,   518,
      37,   519,   520,    40,    41,    42,    43,   476,     0,    45,
     521,    47,   478,   479,    50,   480,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     481,   482,    68,     0,    69,    70,    71,   522,     0,    74,
      75,    76,     0,     0,   484,    78,     0,     0,     0,     0,
      80,   485,    82,   486,   487,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   488,    97,    98,   489,   490,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,   107,     0,     0,     0,     0,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   491,   120,
     121,   492,     0,     0,     0,     0,     0,     0,     0,   493,
     494,   128,     0,     0,     0,   129,   750,   130,   495,     0,
       0,     0,     0,     0,   135,     0,   136,   137,   138,   139,
     496,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,     0,     0,   397,   151,   152,   153,   154,   155,   156,
     157,   158,   497,   523,   498,   162,   499,   500,   165,   166,
     167,   168,   169,   170,   501,   172,   502,   503,   504,   176,
     177,   505,   506,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   547,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,   394,   395,     0,    14,    15,
      16,   515,    18,    19,    20,   469,   516,   517,   471,   472,
     473,   396,    28,   474,    30,    31,     0,    32,    33,    34,
      35,   518,    37,   519,   520,    40,    41,    42,    43,   476,
       0,    45,   521,    47,   478,   479,    50,   480,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   481,   482,    68,     0,    69,    70,    71,   522,
       0,    74,    75,    76,     0,     0,   484,    78,     0,     0,
       0,     0,    80,   485,    82,   486,   487,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   488,    97,    98,   489,
     490,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,   107,     0,     0,     0,     0,     0,     0,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     491,   120,   121,   492,     0,     0,     0,     0,     0,     0,
       0,   493,   494,   128,     0,     0,     0,   129,     0,   130,
     495,     0,     0,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   496,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,     0,     0,   397,   151,   152,   153,   154,
     155,   156,   157,   158,   497,   523,   498,   162,   499,   500,
     165,   166,   167,   168,   169,   170,   501,   172,   502,   503,
     504,   176,   177,   505,   506,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       7,     8,     0,     0,     0,     0,     0,     0,     0,   394,
     395,     0,    14,    15,    16,   468,    18,    19,    20,   469,
      22,   470,   471,  1078,   473,   396,    28,   474,    30,    31,
       0,    32,    33,    34,    35,   475,    37,    38,    39,    40,
      41,    42,    43,   476,     0,    45,   477,    47,   478,   479,
      50,   480,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   481,   482,    68,     0,
      69,    70,    71,   483,     0,    74,    75,    76,     0,     0,
     484,    78,     0,     0,     0,     0,    80,   485,    82,   486,
     487,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     488,    97,    98,   489,   490,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,  1079,     0,     0,
       0,  1080,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   491,   120,   121,   492,     0,     0,
       0,     0,     0,     0,     0,   493,   494,   128,     0,     0,
       0,   129,  1495,   130,   495,     0,     0,     0,  1496,     0,
     135,     0,   136,   137,   138,   139,   496,   141,   142,   143,
     144,   145,   146,     0,     0,  1081,   148,     0,     0,   397,
     151,   152,   153,   154,   155,   156,   157,   158,   497,   160,
     498,   162,   499,   500,   165,   166,   167,   168,   169,   170,
     501,   172,   502,   503,   504,   176,   177,   505,   506,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,  1082,  1083,  1084,  1085,  1086,  1087,
       7,     8,     0,     0,     0,     0,     0,     0,     0,   394,
     395,     0,    14,    15,    16,   468,    18,    19,    20,   469,
      22,   470,   471,  1078,   473,   396,    28,   474,    30,    31,
       0,    32,    33,    34,    35,   475,    37,    38,    39,    40,
      41,    42,    43,   476,     0,    45,   477,    47,   478,   479,
      50,   480,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   481,   482,    68,     0,
      69,    70,    71,   483,     0,    74,    75,    76,     0,     0,
     484,    78,     0,     0,     0,     0,    80,   485,    82,   486,
     487,    85,    86,  1419,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     488,    97,    98,   489,   490,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,  1079,     0,     0,
       0,  1080,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   491,   120,   121,   492,     0,     0,
       0,     0,     0,     0,     0,   493,   494,   128,     0,     0,
       0,   129,     0,   130,   495,     0,     0,     0,     0,     0,
     135,     0,   136,   137,   138,   139,   496,   141,   142,   143,
     144,   145,   146,     0,     0,  1081,   148,     0,     0,   397,
     151,   152,   153,   154,   155,   156,   157,   158,   497,   160,
     498,   162,   499,   500,   165,   166,   167,   168,   169,   170,
     501,   172,   502,   503,   504,   176,   177,   505,   506,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,  1082,  1083,  1084,  1085,  1086,  1087,
       7,     8,     0,     0,     0,     0,     0,     0,     0,   394,
     395,     0,    14,    15,    16,   468,    18,    19,    20,   469,
      22,   470,   471,  1078,   473,   396,    28,   474,    30,    31,
       0,    32,    33,    34,    35,   475,    37,    38,    39,    40,
      41,    42,    43,   476,     0,    45,   477,    47,   478,   479,
      50,   480,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   481,   482,    68,     0,
      69,    70,    71,   483,     0,    74,    75,    76,     0,     0,
     484,    78,     0,     0,     0,     0,    80,   485,    82,   486,
     487,    85,    86,  1554,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     488,    97,    98,   489,   490,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,  1079,     0,     0,
       0,  1080,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   491,   120,   121,   492,     0,     0,
       0,     0,     0,     0,     0,   493,   494,   128,     0,     0,
       0,   129,     0,   130,   495,     0,     0,     0,     0,     0,
     135,     0,   136,   137,   138,   139,   496,   141,   142,   143,
     144,   145,   146,     0,     0,  1081,   148,     0,     0,   397,
     151,   152,   153,   154,   155,   156,   157,   158,   497,   160,
     498,   162,   499,   500,   165,   166,   167,   168,   169,   170,
     501,   172,   502,   503,   504,   176,   177,   505,   506,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,  1082,  1083,  1084,  1085,  1086,  1087,
       7,     8,     0,     0,     0,     0,     0,     0,     0,   394,
     395,     0,    14,    15,    16,   468,    18,    19,    20,   469,
      22,   470,   471,  1078,   473,   396,    28,   474,    30,    31,
       0,    32,    33,    34,    35,   475,    37,    38,    39,    40,
      41,    42,    43,   476,     0,    45,   477,    47,   478,   479,
      50,   480,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   481,   482,    68,     0,
      69,    70,    71,   483,     0,    74,    75,    76,     0,     0,
     484,    78,     0,     0,     0,     0,    80,   485,    82,   486,
     487,    85,    86,  1558,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     488,    97,    98,   489,   490,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,  1079,     0,     0,
       0,  1080,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   491,   120,   121,   492,     0,     0,
       0,     0,     0,     0,     0,   493,   494,   128,     0,     0,
       0,   129,     0,   130,   495,     0,     0,     0,     0,     0,
     135,     0,   136,   137,   138,   139,   496,   141,   142,   143,
     144,   145,   146,     0,     0,  1081,   148,     0,     0,   397,
     151,   152,   153,   154,   155,   156,   157,   158,   497,   160,
     498,   162,   499,   500,   165,   166,   167,   168,   169,   170,
     501,   172,   502,   503,   504,   176,   177,   505,   506,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,  1082,  1083,  1084,  1085,  1086,  1087,
       7,     8,     0,     0,     0,     0,     0,     0,     0,   394,
     395,     0,    14,    15,    16,   468,    18,    19,    20,   469,
      22,   470,   471,  1078,   473,   396,    28,   474,    30,    31,
       0,    32,    33,    34,    35,   475,    37,    38,    39,    40,
      41,    42,    43,   476,     0,    45,   477,    47,   478,   479,
      50,   480,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   481,   482,    68,     0,
      69,    70,    71,   483,     0,    74,    75,    76,     0,     0,
     484,    78,     0,     0,     0,     0,    80,   485,    82,   486,
     487,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     488,    97,    98,   489,   490,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,  1079,     0,     0,
       0,  1080,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   491,   120,   121,   492,     0,     0,
       0,     0,     0,     0,     0,   493,   494,   128,     0,     0,
       0,   129,     0,   130,   495,     0,     0,     0,     0,     0,
     135,     0,   136,   137,   138,   139,   496,   141,   142,   143,
     144,   145,   146,     0,     0,  1081,   148,     0,     0,   397,
     151,   152,   153,   154,   155,   156,   157,   158,   497,   160,
     498,   162,   499,   500,   165,   166,   167,   168,   169,   170,
     501,   172,   502,   503,   504,   176,   177,   505,   506,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,  1082,  1083,  1084,  1085,  1086,  1087,
       7,     8,     0,     0,     0,     0,     0,     0,     0,   394,
     395,     0,    14,    15,    16,   468,    18,    19,    20,   469,
      22,   470,   471,  1078,   473,   396,    28,   474,    30,    31,
       0,    32,    33,    34,    35,   475,    37,    38,    39,    40,
      41,    42,    43,   476,     0,    45,   477,    47,   478,   479,
      50,   480,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   481,   482,    68,     0,
      69,    70,    71,   483,     0,    74,    75,    76,     0,     0,
     484,    78,     0,     0,     0,     0,    80,   485,    82,   486,
     487,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     488,    97,    98,   489,   490,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,  1079,     0,     0,
       0,  1080,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   491,   120,   121,   492,     0,     0,
       0,     0,     0,     0,     0,   493,   494,   128,     0,     0,
       0,   129,     0,   130,   495,     0,     0,     0,     0,     0,
     135,     0,   136,   137,   138,   139,   496,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,     0,     0,   397,
     151,   152,   153,   154,   155,   156,   157,   158,   497,   160,
     498,   162,   499,   500,   165,   166,   167,   168,   169,   170,
     501,   172,   502,   503,   504,   176,   177,   505,   506,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,  1082,  1083,  1084,  1085,  1086,  1087,
     550,   551,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,   394,   395,     0,    14,    15,
      16,   515,    18,    19,    20,   469,   516,   517,   471,   472,
     473,   396,    28,   474,    30,    31,     0,    32,    33,    34,
      35,   518,    37,   519,   520,    40,    41,    42,    43,   476,
       0,    45,   521,    47,   478,   479,    50,   480,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   481,   482,    68,     0,    69,    70,    71,   522,
       0,    74,    75,    76,     0,     0,   484,    78,     0,     0,
       0,     0,    80,   485,    82,   486,   487,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   488,    97,    98,   489,
     490,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,   107,     0,     0,     0,     0,     0,     0,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     491,   120,   121,   492,     0,     0,     0,     0,     0,     0,
       0,   493,   494,   128,     0,     0,     0,   129,     0,   130,
     495,     0,     0,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   496,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,     0,     0,   397,   151,   152,   153,   154,
     155,   156,   157,   158,   497,   523,   498,   162,   499,   500,
     165,   166,   167,   168,   169,   170,   501,   172,   502,   503,
     504,   176,   177,   505,   506,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       7,     8,     0,     0,     0,     0,     0,     0,     0,   394,
     395,     0,    14,    15,    16,   515,    18,    19,    20,   469,
     516,   517,   471,   472,   473,   396,    28,   474,    30,    31,
       0,    32,    33,    34,    35,   518,    37,   519,   520,    40,
      41,    42,    43,   476,     0,    45,   521,    47,   478,   479,
      50,   480,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   481,   482,    68,     0,
      69,    70,    71,   522,     0,    74,    75,    76,     0,     0,
     484,    78,     0,     0,     0,     0,    80,   485,    82,   486,
     487,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     488,    97,    98,   489,   490,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,   107,     0,     0,
       0,     0,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   491,   120,   121,   492,     0,     0,
       0,     0,     0,     0,     0,   493,   494,   128,     0,     0,
       0,   129,   720,   130,   495,     0,     0,     0,   721,     0,
     135,     0,   136,   137,   138,   139,   496,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,     0,     0,   397,
     151,   152,   153,   154,   155,   156,   157,   158,   497,   523,
     498,   162,   499,   500,   165,   166,   167,   168,   169,   170,
     501,   172,   502,   503,   504,   176,   177,   505,   506,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     7,     8,     0,     0,     0,     0,
       0,     0,     0,   394,   395,     0,    14,    15,    16,   515,
      18,    19,    20,   469,   516,   517,   471,   472,   473,   396,
      28,   474,    30,    31,     0,    32,    33,    34,    35,   518,
      37,   519,   520,    40,    41,    42,    43,   476,     0,    45,
     521,    47,   478,   479,    50,   480,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     481,   482,    68,     0,    69,    70,    71,   522,     0,    74,
      75,    76,     0,     0,   484,    78,     0,     0,     0,     0,
      80,   485,    82,   486,   487,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   488,    97,    98,   489,   490,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,   107,     0,     0,     0,     0,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   491,   120,
     121,   492,     0,     0,     0,     0,     0,     0,     0,   493,
     494,   128,     0,     0,     0,   129,   767,   130,   495,     0,
       0,     0,   768,     0,   135,     0,   136,   137,   138,   139,
     496,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,     0,     0,   397,   151,   152,   153,   154,   155,   156,
     157,   158,   497,   523,   498,   162,   499,   500,   165,   166,
     167,   168,   169,   170,   501,   172,   502,   503,   504,   176,
     177,   505,   506,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     7,     8,
       0,     0,     0,     0,     0,     0,     0,   394,   395,     0,
      14,    15,    16,   515,    18,    19,    20,   469,   516,   517,
     471,   472,   473,   396,    28,   474,    30,    31,     0,    32,
      33,    34,    35,   518,    37,   519,   520,    40,    41,    42,
      43,   476,     0,    45,   521,    47,   478,   479,    50,   480,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   481,   482,    68,     0,    69,    70,
      71,   522,     0,    74,    75,    76,     0,     0,   484,    78,
       0,     0,     0,     0,    80,   485,    82,   486,   487,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   488,    97,
      98,   489,   490,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,   107,     0,     0,     0,     0,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   491,   120,   121,   492,     0,     0,     0,     0,
       0,     0,     0,   493,   494,   128,     0,     0,     0,   129,
       0,   130,   495,     0,     0,     0,     0,     0,   135,     0,
     136,   137,   138,   139,   496,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,     0,     0,   397,   151,   152,
     153,   154,   155,   156,   157,   158,   497,   523,   498,   162,
     499,   500,   165,   166,   167,   168,   169,   170,   501,   172,
     502,   503,   504,   176,   177,   505,   506,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     7,     8,     0,     0,     0,     0,     0,     0,
       0,   394,   395,     0,    14,    15,    16,     0,    18,    19,
      20,   469,     0,     0,   471,   472,     0,   396,    28,   474,
      30,    31,     0,    32,    33,    34,    35,     0,    37,     0,
       0,    40,    41,    42,    43,   476,     0,    45,     0,    47,
       0,     0,    50,   480,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,   481,   482,
      68,     0,    69,    70,    71,     0,     0,    74,    75,    76,
       0,     0,   484,    78,     0,     0,     0,     0,    80,   485,
      82,   486,   487,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   488,    97,    98,   489,   490,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,     0,
       0,     0,     0,     0,     0,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   491,   120,   121,   492,
       0,     0,     0,     0,     0,     0,     0,   493,   494,   128,
       0,     0,     0,   129,     0,   130,   495,     0,     0,     0,
       0,     0,   135,     0,   136,   137,   138,   139,   496,   141,
     142,   143,   144,   145,   146,     0,     0,     0,   148,     0,
       0,   397,   151,   152,   153,   154,   155,   156,   157,   158,
     497,     0,   498,   162,   499,   500,   165,   166,   167,   168,
     169,   170,   501,   172,   502,   503,   504,   176,   177,     0,
     506,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   403,   404,    12,     4,     5,     6,   634,     0,     4,
       5,     6,     4,     5,     6,   744,   301,   405,   329,   179,
     637,   638,   639,   640,   108,   109,   110,   756,   785,   250,
     994,   587,   588,   249,   978,   812,   727,     4,     5,     6,
    1240,   770,   727,    73,   265,  1064,  1016,   585,   586,   587,
     588,  1224,   885,   133,   417,   443,   444,    36,  1253,  1296,
    1297,   865,    36,    26,    27,   428,    30,   272,    55,  1329,
      26,    27,   681,     4,     5,     6,     8,  1158,   585,   586,
     117,    96,   117,    29,    47,   851,   146,   901,   451,   864,
     865,    47,     1,   106,     1,  1519,     1,     1,   106,   146,
      56,    29,    99,     1,    45,     1,    76,   141,   108,    93,
     281,    74,   106,     1,    99,    94,   108,    96,    74,   135,
     106,    62,    96,    79,    99,    54,   901,    56,   106,    26,
      27,    26,    27,   129,   117,   106,   129,   106,   215,   190,
     191,   108,    37,    38,    66,    40,    41,   106,   111,    71,
     181,   955,    47,    29,   110,   111,   112,    96,    96,   117,
     935,    56,    57,   194,   968,   589,   112,   146,    52,   593,
      99,    73,   146,   106,    45,   252,    47,   108,   907,    74,
     955,   189,   152,   199,    79,    87,   223,   106,   185,   615,
     184,   617,   618,   968,   620,   117,   622,   281,   182,   195,
     185,   187,   195,   186,   630,   631,   184,   146,    29,   111,
     185,   271,   183,   159,   111,   110,   111,   112,   187,   424,
     233,   123,  1459,   125,   271,     9,    10,   186,   215,   400,
     168,   159,   961,   109,   105,  1659,   271,   271,   967,   254,
     255,  1436,   174,   243,   128,   186,   246,   123,   212,   219,
     220,   243,   332,   186,   246,  1012,   541,  1221,  1518,   106,
    1433,   817,   818,  1207,   159,   252,  1080,   186,   305,   960,
       9,    10,   148,   958,  1244,   960,   152,   155,   887,   155,
     189,   281,   189,  1253,   189,   189,  1305,  1120,   109,   281,
    1371,   189,   271,   189,   106,   980,   167,   271,  1064,  1065,
     176,   189,   123,   106,   692,  1080,   106,   337,   815,   816,
     340,    29,   250,   251,   106,   253,   400,   106,   102,   106,
     249,   106,   285,   218,     5,   106,   155,   148,     9,   285,
     293,   152,   270,   262,   155,   264,   106,   293,   122,   186,
     124,   159,   106,     9,   282,   301,   275,   276,   277,   433,
     279,   106,   281,   121,   742,   176,   106,   441,    45,   530,
      47,   582,    28,   102,   259,   106,   450,   130,   152,   585,
     586,   183,   156,   457,   458,   738,  1613,  1577,   741,    94,
     183,   257,   466,   122,   152,   124,   186,   155,  1163,   173,
     285,   109,    79,   106,   186,  1199,   106,   186,   293,   186,
     400,   186,   183,   106,   106,   123,   301,   106,   400,   193,
      53,   106,   106,   152,   152,    58,   186,   156,   105,  1223,
     155,   847,   186,   152,  1199,  1662,   189,   211,   183,   429,
     148,   431,   603,  1162,   173,   337,   186,   429,   340,   431,
    1521,   122,   117,   124,   120,   186,   530,   176,  1223,   851,
     155,   132,   536,    96,   193,   455,   122,   106,   124,   157,
     460,   545,   429,   455,   431,   106,  1436,   133,   460,    94,
     183,   152,   211,   557,   106,  1648,   186,   175,   880,   106,
     167,   157,  1173,   186,   186,   155,   152,   186,   455,   573,
     574,   186,   186,   460,  1050,  1051,  1052,  1182,   429,   175,
     431,   216,   217,  1280,   106,     5,  1283,   409,   410,     9,
     185,   413,  1050,  1051,  1052,   417,   231,    96,   420,   421,
     908,   909,     9,    10,   455,   913,   428,     9,    96,   460,
     530,   106,   434,  1337,   183,   437,   536,  1618,   530,  1305,
     711,     9,    10,   445,   536,   186,    28,   155,  1314,   451,
     452,   453,   454,   106,   186,   943,   183,   459,   117,  1325,
      96,    94,  1337,    37,    38,   467,    40,    41,   652,   536,
     261,   580,   152,   657,   574,   655,   656,    94,   146,  1660,
     157,   272,   574,    57,   186,   585,   586,   587,   588,   168,
     135,   216,   217,   585,   586,   587,   588,  1541,   175,   815,
     821,   152,   116,   603,   149,   536,   231,   157,   183,   511,
     121,   603,  1576,   146,   949,   102,   951,  1421,   155,   155,
    1424,   168,   122,   525,   124,   175,   185,   711,   208,   146,
     183,   145,   132,   535,   102,   122,    53,   124,   112,   810,
     122,    58,   124,   574,   158,    33,  1421,   197,  1729,  1424,
    1731,   133,   152,   200,   122,    94,   124,   208,   155,  1740,
      77,    49,  1064,  1065,    96,   152,  1001,   569,  1003,   156,
     152,   250,   251,    24,   253,    94,   261,  1434,   192,    96,
     112,   260,  1439,    34,   152,   159,   173,   272,   156,  1316,
     267,   270,   776,   777,   778,  1386,   780,   274,    94,    99,
     117,    96,   141,   282,    42,   173,   193,   284,    46,    60,
      39,   711,   112,    51,   143,    44,    45,   112,   199,   711,
    1486,   147,   141,   155,   211,   193,   117,   208,   152,  1285,
      59,    69,    61,    62,   734,   105,  1640,  1641,   164,   734,
     136,    70,   734,   211,   218,   141,   175,   245,   246,    42,
      42,    95,   176,    46,    46,  1066,   126,  1042,    51,    51,
     155,   105,   267,   192,   764,   765,   155,   734,    97,   274,
     268,   115,   764,   765,  1678,   165,    69,    69,   147,   284,
    1684,   658,   126,   685,   661,   259,   688,   664,   181,    99,
      33,   181,  1596,   136,  1598,   164,   136,   764,   765,    96,
     702,   194,   112,   734,   706,   707,    49,  1564,   898,   152,
     810,  1568,   152,   152,  1202,   112,   155,   826,   810,   121,
     910,  1596,    99,  1598,    99,  1629,   728,    99,   730,   167,
      94,    99,   170,   764,   765,   112,   738,   112,   266,   741,
     112,   105,   121,   745,   112,   273,   152,   185,   121,   155,
    1477,  1478,  1656,  1470,  1629,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,  1036,   223,  1671,    53,  1673,
     297,   228,   210,    58,   167,   167,   121,   170,   170,   306,
    1040,  1656,   784,   136,  1613,  1045,   121,  1644,   141,   275,
     276,   277,   185,   185,   223,   281,  1671,   131,  1673,   219,
     220,   221,   339,  1305,  1292,   139,   140,   344,   142,   136,
     812,   223,  1314,   225,   141,   117,   150,   210,   210,   152,
     154,   152,   156,  1325,   155,   121,   152,   161,   223,   155,
     225,   153,   834,   155,   230,   121,   232,   127,   128,   230,
     121,   232,   635,   636,   178,   127,   128,   643,   644,   641,
     642,   866,   867,   121,  1509,  1510,   121,  1584,  1585,    73,
     152,   155,   864,   865,   866,   867,   214,   201,   202,   203,
     204,   205,   206,    87,   223,   117,   239,   239,   155,  1063,
     240,   152,     0,   106,   189,    92,   166,   197,   247,    50,
     198,   100,   153,   101,   144,   155,   996,   111,    29,   901,
     183,    47,   151,   244,   996,   183,   117,   183,   302,   123,
       1,   125,   186,   915,   117,  1403,   282,   282,   152,   117,
     141,   106,   186,   152,   152,  1652,   141,   183,   155,   996,
    1201,   155,    35,   155,    17,   155,  1036,   155,   940,   155,
    1049,    29,   155,   155,  1036,   212,   152,   949,   186,   951,
    1050,  1051,  1052,   955,   229,   243,   189,   189,  1050,  1051,
    1052,     3,   117,   167,   169,   996,   968,   169,    70,    94,
     229,    94,    94,   148,   106,  1463,   106,    29,   159,   159,
     131,   126,   244,    94,  1486,   297,   183,   141,   117,   131,
     183,   186,   186,   106,    94,    96,    45,    96,   186,  1001,
     186,  1003,   186,   186,   183,   152,   183,    94,  1279,   235,
      33,   189,   169,   223,   141,   131,    94,   141,    29,   117,
      94,   284,   117,   117,   225,   297,   152,   146,   117,   126,
      94,   183,   196,   252,    96,   131,   117,   152,   159,   131,
     146,    99,    99,   183,   183,   152,   189,    35,   141,    29,
     117,   155,   243,    79,    29,   106,   106,  1059,   283,   258,
     256,   143,    29,    29,   304,   155,  1166,   152,   285,   155,
     117,  1166,   225,   265,  1166,   155,   155,   189,  1080,   155,
     155,   186,   155,   155,   155,   155,   155,   143,   126,   117,
      77,  1275,  1276,  1277,   284,    99,   106,   141,   146,  1166,
     146,  1201,   186,   146,   131,     7,   183,   235,   105,  1201,
     105,   231,  1212,   248,   231,   248,   146,  1212,   186,   284,
    1212,   186,   231,   337,   280,   186,   340,   186,    78,   189,
     196,  1231,   185,    29,    29,  1166,  1231,   106,   146,  1231,
     146,   186,   183,   125,  1415,  1212,   186,   186,   169,   186,
    1250,   186,   186,   186,   186,   186,    96,   186,  1250,   269,
     125,   183,   152,    94,  1231,   185,   185,   185,   231,   185,
    1172,   183,   186,  1175,   183,    29,   183,    96,  1278,  1279,
     169,  1212,   146,  1250,   186,    53,  1278,  1279,  1190,    94,
     195,   185,   185,   196,    94,    29,   410,  1199,   106,   413,
    1231,   255,   106,   417,   117,   117,   420,   421,   223,    94,
      94,  1213,   185,   185,   428,   185,   195,   195,   117,  1250,
     434,  1223,   223,   437,    93,   182,   117,   195,   117,   185,
     285,   445,   185,   185,   197,   117,   691,   451,   452,   453,
     454,  1123,   278,   969,   902,   459,   263,  1278,   424,  1251,
    1163,  1618,   223,   467,   404,   246,  1660,   243,   813,   966,
     747,   285,   246,  1172,   249,  1191,   291,  1396,  1539,  1271,
    1055,  1301,  1299,  1296,   525,  1213,  1218,  1221,  1280,  1550,
    1551,  1283,  1553,  1226,   613,   666,   614,   633,  1244,  1560,
     303,   785,  1684,  1280,  1678,   867,  1157,   511,   432,   951,
    1122,  1271,  1281,   303,   303,  1453,   304,  1325,   304,  1065,
    1486,   525,   304,  1314,  1483,  1415,  1074,  1145,   432,  1318,
    1362,   535,   934,  1415,  1512,  1315,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1337,    -1,    -1,    -1,    -1,
      -1,    -1,   325,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   569,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1367,  1637,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1647,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1393,  1394,    -1,  1578,    -1,    -1,    -1,    -1,    -1,
      -1,  1672,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1594,    -1,    -1,    -1,    -1,    -1,    -1,  1419,    -1,  1421,
      -1,    -1,  1424,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1702,    -1,  1435,    -1,    -1,    -1,    -1,  1440,  1539,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1539,    -1,    -1,
    1550,  1551,  1723,  1553,    -1,    -1,    -1,  1728,  1550,  1551,
    1560,  1553,    -1,    -1,    -1,    -1,    -1,    -1,  1560,    -1,
      -1,    -1,    -1,    -1,   688,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   702,    -1,
      -1,    -1,   706,   707,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   728,    -1,   730,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   738,    -1,    -1,   741,    -1,    -1,
      -1,   745,    -1,    -1,    -1,    -1,    -1,  1637,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1637,    -1,  1647,    -1,    -1,
      -1,    -1,  1554,    -1,  1556,  1647,  1558,    -1,    -1,    -1,
      -1,    -1,    -1,  1565,    -1,    -1,    -1,    -1,    -1,    -1,
     784,    -1,  1672,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1672,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1596,    -1,  1598,    -1,   812,    -1,
      -1,    -1,  1702,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1702,    -1,  1614,    -1,    -1,  1617,    -1,    -1,    -1,    -1,
     834,    -1,    -1,  1723,    -1,    -1,    -1,  1629,  1728,    -1,
      -1,  1723,    -1,    -1,    -1,    -1,  1728,  1639,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     864,   865,   866,   867,  1656,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1664,    -1,    -1,    -1,    -1,  1669,    -1,  1671,
      -1,  1673,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   901,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1699,    -1,    -1,
      -1,   915,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1715,    -1,    -1,    -1,  1719,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   940,    -1,    -1,    -1,
      -1,    -1,    -1,  1735,    -1,   949,  1738,   951,    -1,    -1,
      -1,   955,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   968,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   561,   562,    -1,   564,   565,   566,   567,    -1,    -1,
      -1,    -1,   572,    -1,    -1,    -1,    -1,  1001,    -1,  1003,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   595,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   603,   604,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1059,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1080,    -1,    -1,    -1,
      -1,    -1,    -1,   663,    -1,    -1,   666,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   704,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   746,    -1,  1172,    -1,
      -1,  1175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1190,    -1,    -1,    -1,
      -1,   771,    -1,    -1,    -1,  1199,    -1,    -1,    -1,    -1,
      -1,    -1,   782,    -1,    -1,    -1,    -1,    -1,    -1,  1213,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1223,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1251,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   836,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1271,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1280,    -1,    -1,  1283,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   903,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1337,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   938,    -1,
      -1,    -1,    -1,  1367,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   957,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1393,
    1394,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   979,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     990,   991,    -1,    -1,    -1,  1419,    -1,  1421,    -1,    -1,
    1424,    -1,    -1,    -1,    -1,  1005,    -1,    -1,  1008,    -1,
      -1,  1435,    -1,    -1,    -1,    -1,  1440,    -1,    -1,    -1,
      -1,    -1,  1022,  1023,  1024,    -1,  1026,  1027,  1028,  1029,
    1030,  1031,    -1,  1033,  1034,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1055,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1554,    -1,  1556,    -1,  1558,    -1,    -1,    -1,    -1,    -1,
      -1,  1565,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1596,    -1,  1598,    -1,    -1,  1177,    -1,  1179,
      -1,  1181,    -1,    -1,  1184,    -1,    -1,    -1,    -1,  1189,
    1614,    -1,    -1,  1617,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1201,    -1,    -1,    -1,  1629,    -1,    -1,    -1,    -1,
    1210,    -1,    -1,    -1,    -1,  1639,  1216,  1217,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1656,    -1,    -1,  1235,    -1,    -1,    -1,    -1,
    1664,    -1,    -1,    -1,    -1,  1669,    -1,  1671,    -1,  1673,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1699,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1715,    -1,    -1,    -1,  1719,    -1,    -1,    -1,  1299,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1735,    -1,    -1,  1738,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1380,    -1,    -1,    -1,  1384,    -1,    -1,    -1,  1388,    -1,
    1390,    -1,  1392,    -1,    -1,    -1,    -1,    -1,  1398,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1406,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1414,  1415,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1432,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1443,  1444,  1445,  1446,  1447,    -1,  1449,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1527,    -1,  1529,
      -1,    -1,  1532,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1540,    -1,    -1,    -1,    -1,  1545,  1546,    -1,    -1,    -1,
      -1,    -1,    -1,  1553,    -1,    -1,    -1,  1557,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1621,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1633,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1672,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1697,    -1,    -1,
      -1,    -1,  1702,    -1,    -1,    11,    12,  1707,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,  1722,    29,    -1,    -1,  1726,    33,    34,    -1,
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
     306,   307,    11,    12,    -1,    -1,    -1,    -1,   314,    -1,
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
     179,   180,   181,    -1,   183,    -1,   185,    -1,   187,   188,
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
     302,   303,   304,   305,   306,   307,    11,    12,    -1,    -1,
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
     148,   149,   150,   151,   152,   153,    -1,   155,   156,   157,
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
     147,   148,   149,   150,   151,   152,   153,    -1,   155,   156,
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
     149,   150,   151,   152,   153,    -1,   155,   156,   157,   158,
     159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,    -1,   173,    -1,   175,   176,    -1,    -1,
     179,   180,   181,    -1,    -1,   184,   185,    -1,   187,   188,
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
      -1,    -1,    -1,   185,   186,   187,   188,    -1,   190,   191,
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
     147,   148,   149,   150,   151,   152,   153,    -1,   155,   156,
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
     153,    -1,   155,   156,    -1,   158,   159,    -1,    -1,    -1,
      -1,   164,   165,   166,   167,   168,   169,   170,   171,    -1,
     173,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,    -1,
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
     146,   147,   148,   149,   150,   151,   152,   153,    -1,   155,
     156,    -1,   158,   159,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,   173,    -1,    -1,
      -1,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,
      -1,   187,   188,    -1,    -1,    -1,   192,    -1,   194,    -1,
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
      -1,    20,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,
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
     299,   300,   301,   302,   303,   304,   305,   306,   307,    11,
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
     302,   303,   304,   305,   306,   307,    16,    -1,    -1,    -1,
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
     250,   251,   252,   253,   254,   255,    -1,   257,   258,   259,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,    16,    -1,
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
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    -1,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,    -1,   149,   150,   151,    -1,    -1,
      -1,   155,    -1,    -1,   158,   159,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   179,   180,   181,    -1,    -1,
      -1,   185,    -1,   187,   188,    -1,    -1,    -1,    -1,    -1,
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
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    -1,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,    -1,   149,   150,   151,    -1,    -1,
      -1,   155,    -1,    -1,   158,   159,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   179,   180,   181,    -1,    -1,
      -1,   185,    -1,   187,   188,    -1,    -1,    -1,    -1,    -1,
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
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    -1,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,    -1,   149,   150,   151,    -1,    -1,
      -1,   155,    -1,    -1,   158,   159,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   179,   180,   181,    -1,    -1,
      -1,   185,    -1,   187,   188,    -1,    -1,    -1,    -1,    -1,
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
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
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
      -1,   185,    -1,   187,   188,    -1,    -1,    -1,    -1,    -1,
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
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
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
      -1,   185,    -1,   187,   188,    -1,    -1,    -1,    -1,    -1,
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
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
      18,    19,    -1,    -1,    -1,    -1,    24,    25,    -1,    -1,
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
     304,   305,   306,   307,    24,    25,    -1,    -1,    -1,    -1,
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
      -1,    -1,   192,    -1,   194,    -1,   196,   197,   198,   199,
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
     300,   301,   302,   303,   304,   305,   306,   307,    24,    25,
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
      -1,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
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
     306,   307,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    -1,    40,    41,
      42,    43,    -1,    -1,    46,    47,    -1,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    -1,    60,    -1,
      -1,    63,    64,    65,    66,    67,    -1,    69,    -1,    71,
      -1,    -1,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    -1,    -1,    99,   100,   101,
      -1,    -1,   104,   105,    -1,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   125,   126,   127,   128,    -1,   130,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,    -1,   149,   150,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
      -1,    -1,    -1,   185,    -1,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,    -1,   210,    -1,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,    -1,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,   257,   258,   259,    -1,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307
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
     305,   306,   307,   314,   330,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   351,   352,   353,   354,   355,   356,   360,   361,
     362,   366,   368,   369,   371,   378,   380,   383,   384,   385,
     387,   388,   389,   390,   391,   393,   394,   396,   397,   398,
     399,   400,   401,   403,   404,   407,   408,   409,   410,   415,
     417,   419,   420,   425,   444,   447,   451,   454,   455,   460,
     461,   462,   463,   465,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   512,   513,   514,   528,   529,   531,
     532,   533,   534,   535,   536,   537,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   557,   558,   559,   560,
     565,   566,   567,   568,   569,   570,   573,   576,   631,   632,
     633,   643,   644,   645,    33,    34,    49,   213,   386,   387,
     388,   386,   386,   155,   155,    37,    38,    40,    41,    47,
      56,    57,    74,    79,   110,   111,   112,   159,   218,   259,
     285,   293,   301,   367,   368,   372,   373,   374,   159,   152,
     155,   152,   155,   152,   155,    66,    71,   117,   412,   155,
     375,   155,    24,    34,    60,   117,   271,   424,   426,   427,
     152,   155,   155,   155,   117,   152,   155,   155,   155,    76,
     152,   219,   220,   121,   121,   121,   152,   155,    39,    43,
      45,    46,    47,    48,    51,    59,    67,    70,    72,    73,
      75,    90,    91,    97,   104,   111,   113,   114,   134,   137,
     138,   168,   171,   179,   180,   188,   200,   222,   224,   226,
     227,   234,   236,   237,   238,   241,   242,   496,   643,   644,
     121,   117,   395,   121,   121,    39,    44,    45,    59,    61,
      62,    70,    97,   223,   643,   117,   121,   121,   183,   386,
     388,   407,    48,    72,    73,   117,   152,   184,   242,   407,
     409,   419,   186,   407,   643,   152,   121,    16,   642,   643,
      18,    19,   643,   121,   121,   121,   488,   152,    30,   212,
     214,   223,   225,   155,   223,   225,   223,   223,   228,   117,
     239,   239,   240,   155,   152,   390,   332,     0,   334,   335,
      33,    49,   337,   354,     1,   189,   331,   189,   331,   111,
     369,   389,   407,   106,   189,   106,   189,    42,    46,    51,
      69,   167,   170,   185,   210,   402,   411,   416,   417,   418,
     432,   433,   437,   166,    92,   131,   139,   140,   142,   150,
     154,   156,   161,   178,   201,   202,   203,   204,   205,   206,
     480,   481,   247,   197,   120,   157,   175,   116,   145,   158,
     192,   199,   208,   135,   149,    50,   198,   100,   101,   157,
     175,   479,   152,   485,   488,   190,   191,   153,   500,   501,
     496,   500,   496,   155,   500,   144,   155,   183,   183,   183,
     370,   503,   370,    29,   641,   181,   194,   181,   194,   165,
     181,   644,   643,   168,   200,    47,   643,   151,   117,    45,
      47,    79,   105,   167,   642,   219,   220,   221,   244,   604,
     643,   643,   302,   136,   141,   111,   285,   293,   372,   642,
     387,   388,   186,   387,    45,    62,   186,   553,   554,   407,
     186,   192,   643,   282,   282,   421,   422,   643,   117,   428,
     117,   186,   376,   377,   152,   392,   407,     1,   159,   641,
     112,   159,   350,   641,   643,   117,   141,   106,   407,    29,
     186,   642,   643,   643,   445,   446,   643,   387,   186,   407,
     407,   555,   643,   387,   152,   152,   407,   186,   192,   643,
     643,   141,   445,   183,   183,   183,   155,   155,   155,   643,
     152,   184,   185,   186,    35,   516,   517,   518,   407,     8,
     174,    17,   407,   212,    29,   408,   408,   186,   408,   408,
     408,   408,   229,   571,   572,   643,   189,   189,   408,   407,
     388,   407,   243,   405,   406,   189,   331,   189,   331,     3,
     338,   354,   384,   338,   354,   384,    33,   355,   384,   355,
     384,   395,   395,   408,   117,   167,   169,   169,   389,   408,
     408,   462,   463,   465,   465,   465,   465,   464,   465,   465,
     465,    70,   468,   469,   470,   470,   471,   471,   471,   471,
     472,   472,   473,   473,   229,    94,    94,    94,   183,   407,
     488,   488,   407,   501,   186,   408,   511,   148,   186,   511,
     106,   186,   186,   106,   106,   375,    29,   644,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,   357,   358,
     359,    94,   136,   141,   363,   364,   365,   643,   159,   159,
     357,   641,   126,   131,    54,    56,    99,   249,   262,   264,
     275,   276,   277,   279,   281,   605,   606,   607,   608,   609,
     610,   617,   623,   624,   244,    94,   297,   643,   141,   408,
     117,   643,   643,   131,   183,   183,   186,   186,   183,   106,
     186,   106,   186,   106,    36,    94,    96,   146,   423,   424,
     539,   643,    55,   215,   252,   413,   414,   643,    94,   106,
     186,   386,   186,   642,    96,    45,   642,   641,    96,   141,
     539,   643,   408,   427,   183,   186,   186,   186,   186,   106,
     187,   146,   539,   183,   186,   186,   152,   183,   387,   387,
     183,   106,   186,   106,   186,   141,   539,   408,   187,   407,
     407,   407,   643,   517,   518,   129,   195,   183,   183,   130,
     189,    94,   216,   217,   231,    94,   216,   217,   231,    94,
     235,   223,   106,   233,   141,   189,   186,    48,    72,    73,
     242,   409,   419,   183,   497,   577,   406,   354,    33,    33,
     189,   331,   189,   112,   643,   169,   408,   438,   439,   117,
     434,   435,   465,   152,   155,   257,   484,   503,   578,   581,
     582,   583,   584,   585,   589,   591,   593,   594,    47,   151,
     155,   209,   308,   309,   310,   311,   312,   313,   540,   542,
     544,   545,   561,   562,   563,   564,   634,   635,   636,   637,
     638,   639,   640,   643,   540,   538,   544,   538,   183,   184,
     106,   186,   186,   503,   147,   164,   147,   164,   136,   392,
     375,   358,   131,   542,   365,   408,   539,   641,   641,   127,
     128,   641,   275,   276,   277,   281,   643,   261,   272,   261,
     272,    29,   284,    96,   112,   155,   611,   614,   605,    39,
      44,    59,    61,    70,    97,   223,   379,   545,   225,   297,
     306,   408,   643,    94,   297,   641,   152,   555,   556,   643,
     555,   556,   117,   126,   540,   117,   408,   146,   424,   146,
      36,   146,   423,   424,   146,   539,   252,    53,    58,    77,
     117,   423,   429,   430,   431,   414,   539,   540,   377,    94,
     183,   196,   131,   349,   641,   159,   131,    96,   349,   408,
     141,   424,   152,   117,   408,   408,   146,    99,   448,   449,
     450,   452,   453,    99,   456,   457,   458,   459,   387,   183,
     183,   152,   555,   555,   408,   141,   189,   408,   186,   186,
     186,    35,   518,   129,   195,     9,    10,   102,   122,   124,
     152,   193,   513,   515,   526,   527,   530,    29,   230,   232,
     408,   408,   408,   230,   232,   408,   408,   408,   408,   408,
     408,   117,   408,   408,   389,   155,   155,   155,   152,   185,
     243,   574,   575,   208,   390,   189,   112,   384,   384,   384,
     438,    95,   105,   115,   126,   440,   441,   442,   443,   106,
     643,   106,   407,   578,   585,   152,   283,   466,   630,    96,
     168,   250,   251,   253,   260,   270,   282,   579,   580,   599,
     600,   601,   602,   625,   628,   256,   258,   586,   604,   265,
     590,   626,   245,   246,   268,   595,   596,   155,   155,   542,
     155,   155,   155,   155,   155,   155,   155,   143,   175,   192,
     541,   143,   408,   136,   392,   557,   364,   284,    29,    96,
     112,   155,   618,    29,   611,   541,   486,   285,   304,   539,
     379,   225,   189,   386,   186,   186,   143,   186,   186,   422,
     146,   423,   643,   408,   146,   408,   126,   408,   146,   424,
     146,   408,   146,   117,   117,   408,   643,   431,    77,   540,
     389,   408,   641,   106,   349,   408,   141,   386,   446,   408,
     408,   112,   449,   450,    99,   185,   112,   450,   453,   117,
     540,    99,   112,   457,    99,   112,   459,   183,   386,   186,
     186,   408,   196,   456,   131,   193,   515,     7,   387,   643,
     193,   526,   189,   231,   231,   231,   231,   235,   572,   185,
     407,   407,   407,   577,   575,   497,   641,   127,   128,   442,
     443,   443,   439,   105,   436,   435,   183,   186,   578,   592,
     248,   215,   252,   266,   273,   629,    96,   254,   255,   627,
     248,   582,   629,   469,   599,   583,   146,   280,   587,   588,
     627,   284,   598,    78,   597,   186,   192,   540,   543,   186,
     186,   186,   186,   186,   186,   186,   186,   186,    29,   135,
     199,   620,   621,   622,    29,   619,   620,   269,   615,   106,
     612,   169,   643,   255,   486,   183,   408,   146,   408,   146,
     423,   408,   146,   408,   408,   643,   643,   430,   408,   125,
     125,    96,   641,   408,   183,   185,   185,   408,   389,   408,
     185,   185,   643,   185,   117,   540,   117,   185,   117,   540,
     185,   183,   112,   518,   643,   193,   183,   518,   643,   408,
     408,   408,   408,   408,   408,   186,   186,   186,   152,   576,
     443,   641,   183,   471,    52,   128,   469,   469,   267,   274,
     284,   603,   603,   584,   152,   278,    94,   186,   106,   186,
     618,   618,   622,   106,   186,    29,   616,   627,   613,   614,
     186,   381,   382,   486,   117,   223,   305,   285,   169,   408,
     408,   146,   408,    53,   389,   408,   349,   408,   389,    94,
     389,   408,   643,   185,   643,   408,   643,   185,   389,   117,
      93,   182,   519,   518,   643,   195,   518,   196,   456,   407,
     469,   469,   197,   407,   540,   540,    94,    29,   263,   106,
     106,   443,   539,   643,   117,   223,   643,   381,   408,   117,
     540,    94,   185,    94,   643,     5,   132,   522,   523,   525,
     527,    28,   133,   520,   521,   524,   527,   195,   518,   195,
     112,   469,   183,   540,   614,   382,   443,   303,   643,   117,
     223,   643,   185,   540,   389,   408,   540,   185,    93,   132,
     525,   182,   133,   524,   195,   117,   408,   303,   643,   117,
     389,   408,   185,   185,   643,   291,   303,   643,   185,   304,
     408,   304,   486,   486,   197,   285,   643,   223,   117,   643,
     304,   486
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
     575,   576,   577,   578,   579,   580,   581,   582,   583
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   329,   330,   330,   331,   332,   332,   332,   332,   333,
     333,   334,   334,   334,   334,   334,   334,   334,   334,   335,
     335,   335,   335,   336,   337,   337,   337,   338,   338,   338,
     338,   338,   339,   339,   339,   339,   339,   339,   339,   339,
     340,   340,   341,   342,   343,   343,   344,   344,   345,   345,
     346,   346,   346,   346,   347,   347,   347,   348,   348,   348,
     348,   349,   349,   350,   350,   351,   351,   351,   351,   352,
     353,   353,   354,   354,   354,   355,   355,   355,   355,   355,
     355,   355,   355,   356,   356,   357,   357,   358,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   360,   361,
     362,   363,   363,   364,   364,   364,   365,   366,   366,   366,
     367,   367,   367,   367,   368,   368,   369,   369,   369,   369,
     370,   370,   371,   371,   372,   372,   373,   373,   374,   374,
     375,   375,   375,   375,   376,   376,   377,   377,   378,   378,
     378,   378,   379,   379,   380,   380,   381,   381,   382,   382,
     382,   382,   383,   383,   383,   383,   384,   385,   385,   385,
     386,   386,   386,   387,   387,   388,   388,   389,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   390,
     390,   391,   392,   393,   394,   394,   394,   395,   395,   395,
     395,   396,   397,   398,   399,   400,   400,   401,   402,   403,
     404,   405,   405,   406,   407,   407,   408,   408,   408,   408,
     408,   408,   409,   409,   409,   409,   409,   409,   409,   410,
     411,   412,   412,   413,   413,   413,   414,   414,   415,   415,
     416,   417,   417,   417,   418,   418,   418,   418,   418,   419,
     419,   420,   421,   421,   422,   422,   422,   422,   422,   422,
     422,   422,   422,   422,   422,   422,   423,   424,   425,   426,
     426,   427,   427,   427,   427,   428,   428,   429,   429,   429,
     430,   430,   430,   431,   431,   431,   432,   433,   434,   434,
     435,   435,   436,   437,   437,   438,   438,   439,   439,   440,
     440,   440,   440,   440,   440,   440,   441,   441,   442,   442,
     443,   444,   444,   445,   445,   446,   446,   447,   448,   448,
     449,   450,   450,   451,   452,   452,   453,   454,   454,   455,
     455,   456,   456,   457,   457,   458,   458,   459,   459,   460,
     461,   461,   462,   462,   463,   463,   463,   463,   463,   464,
     463,   463,   463,   463,   465,   465,   466,   466,   467,   467,
     468,   468,   469,   469,   469,   470,   470,   470,   470,   470,
     471,   471,   471,   472,   472,   472,   473,   473,   474,   474,
     475,   475,   476,   476,   477,   477,   478,   478,   478,   478,
     479,   479,   479,   480,   480,   480,   480,   480,   480,   481,
     481,   481,   482,   482,   482,   482,   483,   483,   484,   484,
     485,   485,   485,   486,   486,   486,   486,   487,   488,   488,
     488,   489,   489,   490,   490,   490,   490,   491,   491,   492,
     492,   492,   492,   492,   492,   492,   493,   493,   494,   494,
     495,   495,   495,   495,   495,   496,   496,   497,   497,   498,
     498,   498,   498,   499,   499,   499,   499,   500,   500,   501,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   503,   503,   504,   504,   504,   505,   506,   506,   507,
     508,   509,   510,   510,   511,   511,   512,   512,   513,   513,
     513,   514,   514,   514,   514,   514,   514,   515,   515,   516,
     516,   517,   518,   518,   519,   519,   520,   520,   521,   521,
     521,   521,   522,   522,   523,   523,   523,   523,   524,   524,
     525,   525,   526,   526,   526,   526,   527,   527,   527,   527,
     528,   528,   529,   529,   530,   531,   531,   531,   531,   531,
     531,   532,   533,   533,   534,   534,   535,   536,   537,   537,
     538,   538,   539,   540,   540,   540,   541,   541,   541,   542,
     542,   542,   542,   542,   542,   543,   543,   544,   545,   545,
     545,   545,   545,   545,   545,   545,   545,   546,   547,   547,
     547,   548,   549,   550,   550,   550,   551,   551,   551,   551,
     551,   552,   553,   553,   553,   553,   553,   553,   553,   554,
     555,   556,   557,   558,   558,   559,   560,   561,   561,   562,
     563,   563,   564,   565,   565,   565,   566,   566,   566,   566,
     566,   566,   566,   566,   566,   566,   567,   567,   568,   568,
     569,   570,   571,   571,   572,   573,   574,   574,   575,   576,
     577,   577,   578,   579,   579,   580,   580,   581,   581,   582,
     582,   583,   583,   584,   584,   585,   586,   586,   587,   587,
     588,   589,   589,   589,   590,   590,   591,   592,   592,   593,
     594,   594,   595,   595,   596,   596,   596,   597,   597,   598,
     598,   599,   599,   599,   599,   599,   600,   601,   602,   603,
     603,   603,   604,   604,   605,   605,   605,   605,   605,   605,
     605,   605,   606,   606,   606,   606,   607,   607,   608,   609,
     609,   610,   610,   610,   611,   611,   612,   612,   613,   613,
     614,   615,   615,   616,   616,   617,   617,   617,   618,   618,
     619,   619,   620,   620,   621,   621,   622,   622,   623,   624,
     624,   625,   625,   625,   626,   627,   627,   627,   627,   628,
     628,   629,   629,   630,   631,   631,   632,   632,   633,   634,
     634,   634,   634,   634,   634,   635,   636,   637,   638,   639,
     640,   641,   642,   642,   643,   643,   643,   643,   643,   643,
     643,   643,   643,   643,   643,   643,   643,   643,   643,   643,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   645
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
       2,     1,     1,     3,     1,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
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
  "\"'keys'\"", "\"'array'\"", "\"'array-pair'\"", "\"'json-item'\"",
  "\"'object'\"", "\"'object-pair'\"", "\"'pair'\"", "\"'BOM_UTF8'\"",
  "RANGE_REDUCE", "JSON_REDUCE", "ADDITIVE_REDUCE",
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
  "JSONObjectConstructor", "JSONTest", "JSONItemTest", "JSONObjectTest",
  "JSONArrayTest", "JSONPairTest", "JSONObjectPairTest",
  "JSONArrayPairTest", "URI_LITERAL", "NCNAME", "QNAME", "FUNCTION_NAME",
  "EQNAME", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const xquery_parser::rhs_number_type
  xquery_parser::yyrhs_[] =
  {
       330,     0,    -1,   332,    -1,   314,   332,    -1,     1,     3,
      -1,   334,    -1,   333,   334,    -1,   335,    -1,   333,   335,
      -1,   213,   214,    29,   189,    -1,   213,   214,    29,   130,
      29,   189,    -1,   337,   189,   384,    -1,   354,   189,   384,
      -1,   337,   189,   354,   189,   384,    -1,   384,    -1,   337,
     331,   384,    -1,   354,   331,   384,    -1,   337,   189,   354,
     331,   384,    -1,   337,   331,   354,   189,   384,    -1,   336,
      -1,   336,   337,   189,    -1,   336,   354,   189,    -1,   336,
     337,   189,   354,   189,    -1,    34,   159,   642,   131,   641,
     189,    -1,   338,    -1,   337,   189,   338,    -1,   337,   331,
     338,    -1,   339,    -1,   347,    -1,   352,    -1,   353,    -1,
     361,    -1,   340,    -1,   341,    -1,   342,    -1,   343,    -1,
     344,    -1,   345,    -1,   346,    -1,   565,    -1,    33,    38,
     181,    -1,    33,    38,   194,    -1,    33,   112,   105,   641,
      -1,    33,    37,   641,    -1,    33,    40,   181,    -1,    33,
      40,   194,    -1,    33,    57,   168,    -1,    33,    57,   200,
      -1,    33,   112,   167,   126,   127,    -1,    33,   112,   167,
     126,   128,    -1,    33,    41,   181,   106,   147,    -1,    33,
      41,   181,   106,   164,    -1,    33,    41,   165,   106,   147,
      -1,    33,    41,   165,   106,   164,    -1,   348,    -1,   351,
      -1,    49,    24,     1,    -1,    49,    60,   641,    -1,    49,
      60,   350,   641,    -1,    49,    60,   641,    96,   349,    -1,
      49,    60,   350,   641,    96,   349,    -1,   641,    -1,   349,
     106,   641,    -1,   159,   642,   131,    -1,   112,    45,   159,
      -1,    49,    34,   641,    -1,    49,    34,   159,   642,   131,
     641,    -1,    49,    34,   641,    96,   349,    -1,    49,    34,
     159,   642,   131,   641,    96,   349,    -1,    33,   159,   642,
     131,   641,    -1,    33,   112,    45,   159,   641,    -1,    33,
     112,    47,   159,   641,    -1,   355,    -1,   354,   189,   355,
      -1,   354,   331,   355,    -1,   356,    -1,   360,    -1,   362,
      -1,   366,    -1,   371,    -1,   378,    -1,   380,    -1,   383,
      -1,    33,   112,    79,   357,    -1,    33,    79,   643,   357,
      -1,   358,    -1,   357,   358,    -1,   359,   131,   557,    -1,
      80,    -1,    88,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    89,    -1,    85,    -1,    86,    -1,    87,    -1,
      33,    56,   643,    29,    -1,    33,   259,   604,    -1,    33,
     110,   151,   363,    -1,    94,   542,   364,    -1,   364,    -1,
     365,    -1,   136,    -1,   136,   365,    -1,   141,   408,    -1,
      33,   367,   141,   408,    -1,    33,   367,   136,    -1,    33,
     367,   136,   141,   408,    -1,   111,   117,   643,    -1,   111,
     117,   643,   539,    -1,   368,   111,   117,   643,    -1,   368,
     111,   117,   643,   539,    -1,   369,    -1,   368,   369,    -1,
      26,    -1,    26,   155,   370,   186,    -1,    27,    -1,    27,
     155,   370,   186,    -1,   503,    -1,   370,   106,   503,    -1,
      33,   372,    -1,    33,   368,   372,    -1,   373,    -1,   374,
      -1,    47,   644,   375,   392,    -1,    47,   644,   375,   136,
      -1,    74,    47,   644,   375,   392,    -1,    74,    47,   644,
     375,   136,    -1,   155,   186,    -1,   155,   376,   186,    -1,
     155,   186,    94,   540,    -1,   155,   376,   186,    94,   540,
      -1,   377,    -1,   376,   106,   377,    -1,   117,   643,    -1,
     117,   643,   539,    -1,    33,   285,   643,    -1,    33,   285,
     643,    94,   379,    -1,    33,   368,   285,   643,    -1,    33,
     368,   285,   643,    94,   379,    -1,   545,    -1,   545,   541,
      -1,    33,   293,   643,   297,   225,   486,   169,   381,    -1,
      33,   368,   293,   643,   297,   225,   486,   169,   381,    -1,
     382,    -1,   381,   106,   382,    -1,   486,    -1,   486,   539,
      -1,   486,   443,    -1,   486,   539,   443,    -1,    33,   301,
     302,   643,   297,   285,   643,   117,   643,   303,   408,    -1,
      33,   301,   302,   643,   297,   285,   643,   223,   117,   643,
     303,   291,   304,   486,    -1,    33,   301,   302,   643,   297,
     285,   643,   305,   223,   117,   643,   303,   408,    -1,    33,
     301,   302,   643,   306,   304,   255,   285,   643,   223,   117,
     643,   304,   486,   197,   285,   643,   223,   117,   643,   304,
     486,    -1,   385,    -1,   387,    -1,   388,    -1,    -1,   387,
      -1,   388,    -1,    -1,   407,    -1,   388,   407,    -1,   389,
      -1,   388,   389,    -1,   390,    -1,   393,    -1,   396,    -1,
     397,    -1,   398,    -1,   399,    -1,   400,    -1,   401,    -1,
     403,    -1,   455,    -1,   451,    -1,   404,    -1,   152,   388,
     183,    -1,   152,   183,    -1,   152,   386,   183,    -1,   152,
     386,   183,    -1,   394,   189,    -1,   394,   106,   395,    -1,
     111,   395,    -1,   368,   111,   395,    -1,   117,   643,    -1,
     117,   643,   539,    -1,   117,   643,   141,   408,    -1,   117,
     643,   539,   141,   408,    -1,   117,   643,   141,   408,   189,
      -1,   409,   189,    -1,   238,   240,   408,   189,    -1,   241,
     155,   407,   186,   389,    -1,   236,   239,   189,    -1,   237,
     239,   189,    -1,   419,   402,    -1,   185,   389,    -1,    48,
     155,   407,   186,   196,   389,   125,   389,    -1,   242,   390,
     405,    -1,   406,    -1,   405,   406,    -1,   243,   577,   390,
      -1,   408,    -1,   407,   106,   408,    -1,   410,    -1,   447,
      -1,   454,    -1,   460,    -1,   573,    -1,   409,    -1,   461,
      -1,   444,    -1,   566,    -1,   567,    -1,   569,    -1,   568,
      -1,   570,    -1,   419,   411,    -1,   185,   408,    -1,    66,
     282,    -1,    71,   282,    -1,   215,    -1,   252,    -1,    55,
     252,    -1,   413,   429,    77,   408,    -1,   413,    77,   408,
      -1,    46,   412,   428,   414,   414,    -1,    46,   412,   428,
     414,    -1,    42,   117,   643,    -1,   420,    -1,   425,    -1,
     415,    -1,   417,    -1,   432,    -1,   437,    -1,   433,    -1,
     416,    -1,   417,    -1,   419,   418,    -1,    46,   117,   421,
      -1,   422,    -1,   421,   106,   117,   422,    -1,   643,   146,
     408,    -1,   643,    36,   126,   146,   408,    -1,   643,   539,
     146,   408,    -1,   643,   539,    36,   126,   146,   408,    -1,
     643,   423,   146,   408,    -1,   643,    36,   126,   423,   146,
     408,    -1,   643,   539,   423,   146,   408,    -1,   643,   539,
      36,   126,   423,   146,   408,    -1,   643,   424,   146,   408,
      -1,   643,   539,   424,   146,   408,    -1,   643,   423,   424,
     146,   408,    -1,   643,   539,   423,   424,   146,   408,    -1,
      96,   117,   643,    -1,   271,   117,   643,    -1,    51,   426,
      -1,   427,    -1,   426,   106,   427,    -1,   117,   643,   141,
     408,    -1,   117,   643,   539,   141,   408,    -1,   424,   141,
     408,    -1,   117,   643,   539,   424,   141,   408,    -1,   117,
     643,   146,   408,    -1,   117,   643,   539,   146,   408,    -1,
     430,    -1,   117,   643,    -1,   117,   643,   430,    -1,   423,
      -1,   423,   431,    -1,   431,    -1,    58,   117,   643,    53,
     117,   643,    -1,    53,   117,   643,    -1,    58,   117,   643,
      -1,   210,   408,    -1,   170,   169,   434,    -1,   435,    -1,
     434,   106,   435,    -1,   117,   643,    -1,   117,   643,   436,
      -1,   105,   641,    -1,   167,   169,   438,    -1,    69,   167,
     169,   438,    -1,   439,    -1,   438,   106,   439,    -1,   408,
      -1,   408,   440,    -1,   441,    -1,   442,    -1,   443,    -1,
     441,   442,    -1,   441,   443,    -1,   442,   443,    -1,   441,
     442,   443,    -1,    95,    -1,   115,    -1,   126,   127,    -1,
     126,   128,    -1,   105,   641,    -1,    67,   117,   445,   187,
     408,    -1,   134,   117,   445,   187,   408,    -1,   446,    -1,
     445,   106,   117,   446,    -1,   643,   146,   408,    -1,   643,
     539,   146,   408,    -1,    72,   155,   407,   186,   448,   112,
     185,   408,    -1,   449,    -1,   448,   449,    -1,   450,   185,
     408,    -1,    99,   408,    -1,   450,    99,   408,    -1,    72,
     155,   407,   186,   452,   112,   185,   389,    -1,   453,    -1,
     452,   453,    -1,   450,   185,   389,    -1,    73,   155,   407,
     186,   456,   112,   185,   408,    -1,    73,   155,   407,   186,
     456,   112,   117,   643,   185,   408,    -1,    73,   155,   407,
     186,   458,   112,   185,   389,    -1,    73,   155,   407,   186,
     456,   112,   117,   643,   185,   389,    -1,   457,    -1,   456,
     457,    -1,    99,   540,   185,   408,    -1,    99,   117,   643,
      94,   540,   185,   408,    -1,   459,    -1,   458,   459,    -1,
      99,   540,   185,   389,    -1,    99,   117,   643,    94,   540,
     185,   389,    -1,    48,   155,   407,   186,   196,   408,   125,
     408,    -1,   462,    -1,   461,   166,   462,    -1,   463,    -1,
     462,    92,   463,    -1,   465,    -1,   465,   480,   465,    -1,
     465,   481,   465,    -1,   465,   131,   465,    -1,   465,   161,
     465,    -1,    -1,   465,   156,   464,   465,    -1,   465,   154,
     465,    -1,   465,   142,   465,    -1,   465,   140,   465,    -1,
     467,    -1,   467,   247,    70,   578,   466,    -1,    -1,   630,
      -1,   468,    -1,   468,   197,   468,    -1,   469,    -1,   469,
     120,   469,    -1,   470,    -1,   469,   175,   470,    -1,   469,
     157,   470,    -1,   471,    -1,   470,   192,   471,    -1,   470,
     116,   471,    -1,   470,   145,   471,    -1,   470,   158,   471,
      -1,   472,    -1,   471,   199,   472,    -1,   471,   208,   472,
      -1,   473,    -1,   472,   149,   473,    -1,   472,   135,   473,
      -1,   474,    -1,   474,    50,   229,   540,    -1,   475,    -1,
     475,   198,    94,   540,    -1,   476,    -1,   476,   100,    94,
     538,    -1,   477,    -1,   477,   101,    94,   538,    -1,   479,
      -1,   478,   479,    -1,   175,    -1,   157,    -1,   478,   175,
      -1,   478,   157,    -1,   482,    -1,   486,    -1,   483,    -1,
     201,    -1,   206,    -1,   205,    -1,   204,    -1,   203,    -1,
     202,    -1,   150,    -1,   178,    -1,   139,    -1,    75,   152,
     387,   183,    -1,    75,   220,   152,   387,   183,    -1,    75,
     219,   152,   387,   183,    -1,    75,    76,   555,   152,   387,
     183,    -1,   484,   152,   183,    -1,   484,   152,   407,   183,
      -1,   485,    -1,   484,   485,    -1,   176,   643,    17,    -1,
     176,    18,    -1,   176,    19,    -1,   487,    -1,   487,   488,
      -1,   191,   488,    -1,   488,    -1,   190,    -1,   489,    -1,
     489,   190,   488,    -1,   489,   191,   488,    -1,   490,    -1,
     499,    -1,   491,    -1,   491,   500,    -1,   494,    -1,   494,
     500,    -1,   492,   496,    -1,   493,    -1,   104,   121,    -1,
     113,   121,    -1,    97,   121,    -1,   188,   121,    -1,   114,
     121,    -1,   138,   121,    -1,   137,   121,    -1,   496,    -1,
      98,   496,    -1,   495,   496,    -1,   119,    -1,   171,   121,
      -1,    90,   121,    -1,   180,   121,    -1,   179,   121,    -1,
      91,   121,    -1,   545,    -1,   497,    -1,   643,    -1,   498,
      -1,   192,    -1,    11,    -1,    12,    -1,    20,    -1,   502,
      -1,   499,   500,    -1,   499,   155,   186,    -1,   499,   155,
     511,   186,    -1,   501,    -1,   500,   501,    -1,   153,   407,
     184,    -1,   503,    -1,   505,    -1,   506,    -1,   507,    -1,
     510,    -1,   512,    -1,   508,    -1,   509,    -1,   558,    -1,
     391,    -1,   631,    -1,   504,    -1,   557,    -1,   109,    -1,
     148,    -1,   123,    -1,   117,   643,    -1,   155,   186,    -1,
     155,   407,   186,    -1,   118,    -1,   168,   152,   407,   183,
      -1,   200,   152,   407,   183,    -1,   644,   155,   186,    -1,
     644,   155,   511,   186,    -1,   408,    -1,   511,   106,   408,
      -1,   513,    -1,   531,    -1,   514,    -1,   528,    -1,   529,
      -1,   156,   643,   518,   129,    -1,   156,   643,   516,   518,
     129,    -1,   156,   643,   518,   195,   193,   643,   518,   195,
      -1,   156,   643,   518,   195,   515,   193,   643,   518,   195,
      -1,   156,   643,   516,   518,   195,   193,   643,   518,   195,
      -1,   156,   643,   516,   518,   195,   515,   193,   643,   518,
     195,    -1,   526,    -1,   515,   526,    -1,   517,    -1,   516,
     517,    -1,    35,   643,   518,   131,   518,   519,    -1,    -1,
      35,    -1,   182,   520,   182,    -1,    93,   522,    93,    -1,
      -1,   521,    -1,   133,    -1,   524,    -1,   521,   133,    -1,
     521,   524,    -1,    -1,   523,    -1,   132,    -1,   525,    -1,
     523,   132,    -1,   523,   525,    -1,    28,    -1,   527,    -1,
       5,    -1,   527,    -1,   513,    -1,    10,    -1,   530,    -1,
     527,    -1,     9,    -1,   122,    -1,   124,    -1,   152,   387,
     183,    -1,   211,    30,   212,    -1,   211,   212,    -1,   173,
     642,   174,    -1,   173,   642,     8,    -1,   102,     7,    -1,
     532,    -1,   533,    -1,   534,    -1,   535,    -1,   536,    -1,
     537,    -1,    43,   152,   387,   183,    -1,    21,   386,   183,
      -1,    45,   152,   407,   183,   152,   386,   183,    -1,    22,
     386,   183,    -1,    97,   152,   407,   183,   152,   386,   183,
      -1,    70,   152,   387,   183,    -1,    39,   152,   387,   183,
      -1,    23,   386,   183,    -1,    59,   152,   407,   183,   152,
     386,   183,    -1,   544,    -1,   544,   143,    -1,    94,   540,
      -1,   542,    -1,   542,   541,    -1,   209,   155,   186,    -1,
     143,    -1,   192,    -1,   175,    -1,   544,    -1,   545,    -1,
     151,   155,   186,    -1,   561,    -1,   564,    -1,   634,    -1,
     540,    -1,   543,   106,   540,    -1,   643,    -1,   547,    -1,
     553,    -1,   551,    -1,   554,    -1,   552,    -1,   550,    -1,
     549,    -1,   548,    -1,   546,    -1,   223,   155,   186,    -1,
      44,   155,   186,    -1,    44,   155,   553,   186,    -1,    44,
     155,   554,   186,    -1,    70,   155,   186,    -1,    39,   155,
     186,    -1,    59,   155,   186,    -1,    59,   155,   642,   186,
      -1,    59,   155,    29,   186,    -1,    97,   155,   186,    -1,
      97,   155,   643,   186,    -1,    97,   155,   643,   106,   555,
     186,    -1,    97,   155,   192,   186,    -1,    97,   155,   192,
     106,   555,   186,    -1,    61,   155,   643,   186,    -1,    45,
     155,   186,    -1,    45,   155,   643,   186,    -1,    45,   155,
     643,   106,   555,   186,    -1,    45,   155,   643,   106,   556,
     186,    -1,    45,   155,   192,   186,    -1,    45,   155,   192,
     106,   555,   186,    -1,    45,   155,   192,   106,   556,   186,
      -1,    62,   155,   643,   186,    -1,   643,    -1,   643,   143,
      -1,    29,    -1,   559,    -1,   560,    -1,   643,   144,   148,
      -1,    47,   375,   392,    -1,   562,    -1,   563,    -1,    47,
     155,   192,   186,    -1,    47,   155,   186,    94,   540,    -1,
      47,   155,   543,   186,    94,   540,    -1,   155,   542,   186,
      -1,    33,   218,   219,    -1,    33,   218,   220,    -1,    33,
     218,   221,    -1,   224,   223,   408,   231,   408,    -1,   224,
     223,   408,    94,   230,   231,   408,    -1,   224,   223,   408,
      94,   232,   231,   408,    -1,   224,   223,   408,   216,   408,
      -1,   224,   223,   408,   217,   408,    -1,   224,   225,   408,
     231,   408,    -1,   224,   225,   408,    94,   230,   231,   408,
      -1,   224,   225,   408,    94,   232,   231,   408,    -1,   224,
     225,   408,   216,   408,    -1,   224,   225,   408,   217,   408,
      -1,   222,   223,   408,    -1,   222,   225,   408,    -1,   227,
     223,   408,   235,   408,    -1,   227,   228,   229,   223,   408,
     235,   408,    -1,   226,   223,   408,    94,   408,    -1,   234,
     117,   571,   233,   408,   185,   408,    -1,   572,    -1,   571,
     106,   117,   572,    -1,   643,   141,   408,    -1,   242,   152,
     407,   183,   574,    -1,   575,    -1,   574,   575,    -1,   243,
     577,   576,    -1,   152,   407,   183,    -1,   497,    -1,   577,
     208,   497,    -1,   581,   579,    -1,    -1,   580,    -1,   599,
      -1,   580,   599,    -1,   582,    -1,   581,   260,   582,    -1,
     583,    -1,   582,   256,   583,    -1,   584,    -1,   583,   258,
     146,   584,    -1,   585,    -1,   257,   585,    -1,   589,   586,
     587,    -1,    -1,   604,    -1,    -1,   588,    -1,   280,   152,
     407,   183,    -1,   593,   590,    -1,   155,   578,   186,    -1,
     591,    -1,    -1,   626,    -1,   484,   152,   592,   183,    -1,
      -1,   578,    -1,   594,   595,    -1,   503,    -1,   152,   407,
     183,    -1,    -1,   596,    -1,   246,   597,    -1,   245,   598,
      -1,   268,    -1,    -1,    78,    -1,    -1,   284,    -1,   600,
      -1,   601,    -1,   602,    -1,   628,    -1,   625,    -1,   168,
      -1,   282,   469,   603,    -1,   251,   627,   603,    -1,   284,
      -1,   274,    -1,   267,    -1,   244,   605,    -1,   604,   244,
     605,    -1,   606,    -1,   607,    -1,   608,    -1,   623,    -1,
     609,    -1,   617,    -1,   610,    -1,   624,    -1,    99,   272,
      -1,    99,   261,    -1,   264,    -1,   279,    -1,   249,   272,
      -1,   249,   261,    -1,    56,   643,    29,    -1,   275,    -1,
      54,   275,    -1,   277,   611,    -1,   277,   155,   611,   612,
     186,    -1,    54,   277,    -1,   614,    -1,   112,    -1,    -1,
     106,   613,    -1,   614,    -1,   613,   106,   614,    -1,    96,
      29,   615,   616,    -1,    -1,   269,    29,    -1,    -1,   627,
     263,    -1,   276,   284,   618,   620,    -1,   276,   284,   112,
     620,    -1,    54,   276,   284,    -1,    96,    29,    -1,   155,
     619,   186,    -1,    29,    -1,   619,   106,    29,    -1,    -1,
     621,    -1,   622,    -1,   621,   622,    -1,   199,   618,    -1,
     135,   618,    -1,   262,    29,    -1,   281,    -1,    54,   281,
      -1,    96,   215,    -1,    96,   252,    -1,   253,   248,    -1,
     265,   627,   278,    -1,   254,   469,    -1,    96,   128,   469,
      -1,    96,    52,   469,    -1,   255,   469,   197,   469,    -1,
     270,   629,    -1,   250,   629,    -1,   273,    -1,   266,    -1,
     283,   248,   471,    -1,   632,    -1,   633,    -1,   153,   184,
      -1,   153,   407,   184,    -1,   576,    -1,   635,    -1,   636,
      -1,   637,    -1,   638,    -1,   639,    -1,   640,    -1,   310,
     155,   186,    -1,   311,   155,   186,    -1,   308,   155,   186,
      -1,   313,   155,   186,    -1,   312,   155,   186,    -1,   309,
     155,   186,    -1,    29,    -1,    16,    -1,   643,    -1,   644,
      -1,    97,    -1,    39,    -1,    44,    -1,    45,    -1,   151,
      -1,    48,    -1,   223,    -1,    59,    -1,    61,    -1,    62,
      -1,    70,    -1,    73,    -1,    72,    -1,   209,    -1,   241,
      -1,   645,    -1,    24,    -1,   213,    -1,   126,    -1,    38,
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
      -1,    91,    -1,   114,    -1,   138,    -1,   180,    -1,    25,
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
    2593,  2596,  2598,  2600,  2604,  2606,  2608,  2611,  2615,  2617,
    2619,  2621,  2623,  2625,  2627,  2629,  2633,  2637,  2641,  2645,
    2649,  2653,  2655,  2657,  2659,  2661,  2663,  2665,  2667,  2669,
    2671,  2673,  2675,  2677,  2679,  2681,  2683,  2685,  2687,  2689,
    2691,  2693,  2695,  2697,  2699,  2701,  2703,  2705,  2707,  2709,
    2711,  2713,  2715,  2717,  2719,  2721,  2723,  2725,  2727,  2729,
    2731,  2733,  2735,  2737,  2739,  2741,  2743,  2745,  2747,  2749,
    2751,  2753,  2755,  2757,  2759,  2761,  2763,  2765,  2767,  2769,
    2771,  2773,  2775,  2777,  2779,  2781,  2783,  2785,  2787,  2789,
    2791,  2793,  2795,  2797,  2799,  2801,  2803,  2805,  2807,  2809,
    2811,  2813,  2815,  2817,  2819,  2821,  2823,  2825,  2827,  2829,
    2831,  2833,  2835,  2837,  2839,  2841,  2843,  2845,  2847,  2849,
    2851,  2853,  2855,  2857,  2859,  2861,  2863,  2865,  2867,  2869,
    2871,  2873,  2875,  2877,  2879,  2881,  2883,  2885,  2887,  2889,
    2891,  2893,  2895,  2897,  2899,  2901,  2903,  2905,  2907,  2909,
    2911,  2913,  2915,  2917,  2919,  2921,  2923,  2925,  2927,  2929,
    2931,  2933,  2935,  2937,  2939,  2941,  2943,  2945,  2947,  2949,
    2951,  2953,  2955,  2957,  2959,  2961,  2963,  2965,  2967,  2969,
    2971,  2973,  2975,  2977,  2979,  2981,  2983,  2985,  2987,  2989,
    2991,  2993,  2995,  2997,  2999,  3001,  3003,  3005,  3007,  3009,
    3011,  3013,  3015,  3017,  3019,  3021,  3023,  3025,  3027,  3029,
    3031,  3033,  3035,  3037,  3039,  3041,  3043,  3045,  3047,  3049,
    3051,  3053,  3055,  3057,  3059,  3061,  3063,  3065,  3067,  3069,
    3071,  3073,  3075,  3077,  3079,  3081,  3083,  3085,  3087,  3089
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1014,  1014,  1015,  1024,  1033,  1039,  1047,  1053,  1064,
    1069,  1077,  1084,  1091,  1100,  1107,  1115,  1123,  1131,  1142,
    1147,  1154,  1161,  1173,  1183,  1190,  1197,  1209,  1210,  1211,
    1212,  1213,  1218,  1219,  1220,  1221,  1222,  1223,  1224,  1227,
    1232,  1237,  1245,  1253,  1261,  1266,  1274,  1279,  1287,  1292,
    1300,  1307,  1314,  1321,  1331,  1333,  1336,  1346,  1351,  1359,
    1367,  1378,  1385,  1396,  1401,  1409,  1416,  1423,  1432,  1445,
    1453,  1460,  1470,  1477,  1484,  1495,  1496,  1497,  1498,  1499,
    1500,  1501,  1502,  1507,  1513,  1522,  1529,  1539,  1549,  1550,
    1551,  1552,  1553,  1554,  1555,  1556,  1557,  1558,  1563,  1571,
    1579,  1587,  1594,  1602,  1609,  1614,  1622,  1630,  1645,  1660,
    1678,  1683,  1691,  1699,  1710,  1715,  1724,  1729,  1736,  1741,
    1751,  1756,  1765,  1771,  1784,  1789,  1797,  1808,  1823,  1835,
    1850,  1855,  1860,  1865,  1873,  1880,  1891,  1896,  1906,  1913,
    1920,  1927,  1937,  1941,  1951,  1959,  1970,  1976,  1985,  1990,
    1997,  2004,  2015,  2025,  2035,  2045,  2063,  2083,  2088,  2093,
    2100,  2105,  2110,  2117,  2122,  2134,  2141,  2153,  2154,  2155,
    2156,  2157,  2158,  2159,  2161,  2162,  2163,  2164,  2165,  2170,
    2175,  2183,  2200,  2208,  2216,  2223,  2230,  2240,  2252,  2265,
    2277,  2293,  2301,  2309,  2317,  2332,  2337,  2345,  2359,  2376,
    2401,  2409,  2416,  2427,  2437,  2442,  2457,  2458,  2459,  2460,
    2461,  2462,  2467,  2468,  2471,  2472,  2473,  2474,  2475,  2480,
    2494,  2502,  2507,  2515,  2520,  2525,  2533,  2542,  2554,  2564,
    2577,  2585,  2586,  2587,  2592,  2593,  2594,  2595,  2596,  2601,
    2608,  2618,  2626,  2633,  2643,  2653,  2663,  2673,  2683,  2693,
    2703,  2713,  2724,  2733,  2743,  2753,  2769,  2778,  2787,  2795,
    2801,  2813,  2821,  2831,  2839,  2851,  2857,  2868,  2870,  2874,
    2882,  2886,  2891,  2895,  2899,  2903,  2913,  2921,  2928,  2934,
    2945,  2949,  2958,  2966,  2972,  2982,  2988,  2998,  3002,  3012,
    3018,  3024,  3030,  3039,  3048,  3057,  3070,  3074,  3082,  3088,
    3098,  3106,  3115,  3128,  3135,  3147,  3151,  3163,  3170,  3176,
    3185,  3192,  3198,  3209,  3216,  3222,  3231,  3240,  3247,  3258,
    3265,  3277,  3283,  3295,  3301,  3312,  3318,  3329,  3335,  3346,
    3355,  3359,  3368,  3372,  3380,  3384,  3394,  3401,  3410,  3420,
    3419,  3433,  3442,  3451,  3464,  3468,  3481,  3484,  3492,  3496,
    3504,  3508,  3517,  3521,  3525,  3534,  3538,  3544,  3550,  3556,
    3567,  3571,  3575,  3583,  3587,  3593,  3603,  3607,  3617,  3621,
    3631,  3635,  3645,  3649,  3659,  3663,  3671,  3675,  3679,  3683,
    3693,  3697,  3701,  3709,  3713,  3717,  3721,  3725,  3729,  3737,
    3741,  3745,  3753,  3757,  3761,  3765,  3776,  3782,  3792,  3798,
    3808,  3812,  3816,  3854,  3858,  3868,  3878,  3891,  3900,  3910,
    3914,  3923,  3927,  3936,  3942,  3950,  3956,  3968,  3974,  3984,
    3988,  3992,  3996,  4000,  4006,  4012,  4020,  4024,  4032,  4036,
    4047,  4051,  4055,  4061,  4065,  4079,  4083,  4091,  4095,  4105,
    4109,  4113,  4117,  4126,  4130,  4134,  4138,  4146,  4152,  4162,
    4170,  4174,  4178,  4182,  4186,  4190,  4194,  4198,  4202,  4212,
    4216,  4224,  4228,  4236,  4243,  4250,  4261,  4269,  4273,  4281,
    4289,  4297,  4351,  4355,  4368,  4374,  4384,  4388,  4396,  4400,
    4404,  4412,  4422,  4432,  4442,  4452,  4462,  4477,  4483,  4494,
    4500,  4511,  4522,  4524,  4528,  4533,  4543,  4546,  4553,  4559,
    4565,  4573,  4586,  4589,  4596,  4602,  4608,  4615,  4626,  4630,
    4640,  4644,  4654,  4658,  4662,  4667,  4676,  4682,  4688,  4694,
    4702,  4707,  4715,  4720,  4728,  4736,  4741,  4746,  4751,  4756,
    4761,  4770,  4778,  4782,  4799,  4803,  4811,  4819,  4827,  4831,
    4839,  4845,  4855,  4863,  4867,  4871,  4906,  4912,  4918,  4928,
    4932,  4936,  4940,  4944,  4948,  4955,  4961,  4971,  4979,  4983,
    4987,  4991,  4995,  4999,  5003,  5007,  5011,  5019,  5027,  5031,
    5035,  5045,  5053,  5061,  5065,  5069,  5077,  5081,  5087,  5093,
    5097,  5107,  5115,  5119,  5125,  5134,  5143,  5149,  5155,  5165,
    5182,  5189,  5204,  5240,  5244,  5252,  5260,  5272,  5276,  5284,
    5292,  5296,  5307,  5324,  5330,  5336,  5346,  5350,  5356,  5362,
    5366,  5372,  5376,  5382,  5388,  5395,  5405,  5410,  5418,  5424,
    5434,  5456,  5465,  5471,  5484,  5498,  5505,  5511,  5521,  5530,
    5538,  5544,  5562,  5571,  5574,  5581,  5586,  5594,  5598,  5605,
    5609,  5616,  5620,  5627,  5631,  5640,  5653,  5656,  5664,  5667,
    5675,  5683,  5691,  5695,  5703,  5706,  5714,  5726,  5729,  5737,
    5749,  5755,  5765,  5768,  5776,  5780,  5784,  5792,  5795,  5803,
    5806,  5814,  5818,  5822,  5826,  5830,  5838,  5846,  5858,  5870,
    5874,  5878,  5886,  5892,  5902,  5906,  5910,  5914,  5918,  5922,
    5926,  5930,  5938,  5942,  5946,  5950,  5958,  5964,  5974,  5984,
    5988,  5996,  6006,  6017,  6024,  6028,  6036,  6039,  6046,  6051,
    6060,  6070,  6073,  6081,  6084,  6092,  6101,  6108,  6118,  6122,
    6129,  6135,  6145,  6148,  6155,  6160,  6172,  6180,  6192,  6200,
    6204,  6212,  6216,  6220,  6228,  6236,  6240,  6244,  6248,  6256,
    6264,  6276,  6280,  6288,  6297,  6301,  6308,  6312,  6319,  6326,
    6330,  6334,  6338,  6342,  6346,  6353,  6360,  6367,  6374,  6381,
    6388,  6401,  6405,  6406,  6419,  6420,  6421,  6422,  6423,  6424,
    6425,  6426,  6427,  6428,  6429,  6430,  6431,  6432,  6433,  6434,
    6438,  6439,  6440,  6441,  6442,  6443,  6444,  6445,  6446,  6447,
    6448,  6449,  6450,  6451,  6452,  6453,  6454,  6455,  6456,  6457,
    6458,  6459,  6460,  6461,  6462,  6463,  6464,  6465,  6466,  6467,
    6468,  6469,  6470,  6471,  6472,  6473,  6474,  6475,  6476,  6477,
    6478,  6479,  6480,  6481,  6482,  6483,  6484,  6485,  6486,  6487,
    6488,  6489,  6490,  6491,  6492,  6493,  6494,  6495,  6496,  6497,
    6498,  6499,  6500,  6501,  6502,  6503,  6504,  6505,  6506,  6507,
    6508,  6509,  6510,  6511,  6512,  6513,  6514,  6515,  6516,  6517,
    6518,  6519,  6520,  6521,  6522,  6523,  6524,  6525,  6526,  6527,
    6528,  6529,  6530,  6531,  6532,  6533,  6534,  6535,  6536,  6537,
    6538,  6539,  6540,  6541,  6542,  6543,  6544,  6545,  6546,  6547,
    6548,  6549,  6550,  6551,  6552,  6553,  6554,  6555,  6556,  6557,
    6558,  6559,  6560,  6561,  6562,  6563,  6564,  6565,  6566,  6567,
    6568,  6569,  6570,  6571,  6572,  6573,  6574,  6575,  6576,  6577,
    6578,  6579,  6580,  6581,  6582,  6583,  6584,  6585,  6586,  6587,
    6588,  6589,  6590,  6591,  6592,  6593,  6594,  6595,  6596,  6597,
    6598,  6599,  6600,  6601,  6602,  6603,  6604,  6605,  6606,  6607,
    6608,  6609,  6610,  6611,  6612,  6613,  6614,  6615,  6616,  6617,
    6618,  6619,  6620,  6621,  6622,  6623,  6624,  6625,  6626,  6627,
    6628,  6629,  6630,  6631,  6632,  6633,  6634,  6635,  6636,  6641
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
     325,   326,   327,   328
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 13595;
  const int xquery_parser::yynnts_ = 317;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 577;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 329;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 583;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 16454 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 6645 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"


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

