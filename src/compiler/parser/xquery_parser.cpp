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
#line 900 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 299 of lalr1.cc  */
#line 1016 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"

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
#line 898 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 298 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 123: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 897 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 307 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 148: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 316 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 325 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 334 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 343 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 352 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 361 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 370 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 379 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 388 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 397 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 406 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 415 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 424 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 433 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 442 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 451 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 460 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 469 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 478 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 487 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 496 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 505 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 514 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 523 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 532 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 541 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 550 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 559 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 568 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 577 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 586 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 595 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 604 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 613 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 622 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 631 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 640 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 649 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 658 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 667 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 676 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 685 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 694 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 703 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 712 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 721 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 730 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 739 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 748 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 757 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 775 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 784 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 820 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 829 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 838 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 847 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 856 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 865 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 874 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 901 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 910 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 919 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 937 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 946 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 955 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 964 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 973 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 982 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 991 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1000 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1009 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1018 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1027 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1036 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1045 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1054 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1063 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1072 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1081 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1090 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1099 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1108 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1117 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1126 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1135 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1144 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1153 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1162 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1171 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1180 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1189 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1198 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1207 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1216 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1225 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1234 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1243 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1252 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1261 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1270 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1279 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1288 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1297 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1306 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1315 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1324 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1333 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1342 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1351 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1360 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1369 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1378 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1387 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1396 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1405 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1414 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1423 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1432 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1441 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1450 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1459 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1468 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1477 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1486 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1495 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1504 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1513 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1522 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1531 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1540 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1549 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1558 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1567 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1576 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1585 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1594 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1603 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1612 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1621 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1630 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1639 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1648 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1657 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1666 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1675 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1684 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1693 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1702 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1711 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1720 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1729 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1738 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1747 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1756 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1765 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1774 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1783 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1792 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1801 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1810 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1819 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1828 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1837 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1846 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1855 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1864 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1873 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1882 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1891 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1900 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1909 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1918 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1927 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1936 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1945 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1954 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1963 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1972 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1981 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1990 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1999 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2008 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2017 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2026 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2035 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2044 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2053 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2062 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2071 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2080 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2089 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2098 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2107 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2116 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2125 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2134 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2143 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2152 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2161 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2170 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2179 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2188 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2197 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2206 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2215 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2224 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2233 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2242 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2251 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2260 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2269 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2278 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2287 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2296 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2305 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2314 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2323 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2332 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2341 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2350 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2359 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2368 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2377 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2386 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2395 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2404 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2413 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2422 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2431 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2440 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2449 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2458 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2467 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2476 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2485 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2494 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2503 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2512 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2521 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2530 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2539 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2548 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2557 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2566 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 614: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2575 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2584 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 618: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2593 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 622: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2602 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 623: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2611 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 624: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2620 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 625: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2629 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 626: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2638 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 627: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2647 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2656 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2665 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 630: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2674 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 631: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2683 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 632: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2692 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 633: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2701 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 634: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2710 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 635: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2719 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 636: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2728 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 637: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2737 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 638: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2746 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 639: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2755 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 640: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2764 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 647: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2773 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 648: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2782 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 649: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2791 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
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
#line 2888 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"

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
#line 1034 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 1043 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 1052 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 1058 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 1066 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 1072 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 1083 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 1088 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 1096 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 1103 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 1110 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 1119 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 1126 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 1134 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 1142 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 1150 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 1161 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 1166 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 1173 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 1180 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 1192 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 1202 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 1209 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 1216 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1251 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 1256 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 1264 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 1272 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 1280 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 1285 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 1293 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1298 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1306 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1311 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1319 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1326 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1333 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1340 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1355 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1365 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 1370 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 1378 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 1386 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 1397 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1404 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1415 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1420 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1428 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1435 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1442 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1451 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1464 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1472 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1479 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1489 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 1496 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1503 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 1526 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 1532 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 1541 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 1548 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1558 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1567 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1568 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1569 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1570 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1571 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1572 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1573 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1574 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1575 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1576 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1582 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1590 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1598 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1606 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1613 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1621 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1628 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1633 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1641 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1649 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1664 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1679 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1697 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1702 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1710 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1718 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 1729 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1734 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1743 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1748 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1755 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1760 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1770 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1775 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1784 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1790 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1803 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1808 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1816 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1827 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1842 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1854 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1869 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1874 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1879 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1884 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1892 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1899 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1910 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1915 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1925 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1932 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1939 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1946 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1956 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1960 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1970 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1978 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1989 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1995 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 2004 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 2009 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 2016 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 2023 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 2035 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2045 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2055 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2066 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2082 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2102 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 2106 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 2110 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 2118 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 2122 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 2126 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 2134 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 2139 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 2151 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 2158 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 2187 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 2192 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 2200 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2217 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 2225 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 2233 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 2240 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 2247 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 2257 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2269 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2282 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2294 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2310 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 2318 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 2326 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 2334 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2349 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 2354 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 2362 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2376 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2393 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2418 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2426 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 2433 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2444 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 2454 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 2459 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2504 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2518 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 2526 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 2531 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 228:

/* Line 690 of lalr1.cc  */
#line 2539 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 229:

/* Line 690 of lalr1.cc  */
#line 2544 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 2549 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 231:

/* Line 690 of lalr1.cc  */
#line 2557 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 2566 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 2578 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2588 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2601 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 2625 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 2632 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 2642 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 247:

/* Line 690 of lalr1.cc  */
#line 2650 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 2657 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 249:

/* Line 690 of lalr1.cc  */
#line 2667 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2677 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2687 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2697 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2707 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2717 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2727 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2737 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2748 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2757 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2767 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2777 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2793 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2802 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2811 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2819 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 2825 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 2837 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 2845 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 2855 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 2863 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 2875 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 2881 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2894 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2898 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2906 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2910 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2919 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2923 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2927 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2937 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2945 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2952 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2958 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2969 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2973 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 2982 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 2990 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 2996 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 3006 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 3012 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 3022 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 3026 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 3036 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 3042 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 3048 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 3054 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3063 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3072 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3081 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3094 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 3098 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 3106 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 3112 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 3122 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 3130 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3139 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3152 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 3159 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 3171 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 3175 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 3187 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 3194 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 3200 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 3209 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 3216 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 3222 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 3233 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 3240 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 3246 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 3255 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 3264 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 3271 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 3282 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 3289 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 3301 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 3307 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 3319 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 3325 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 3336 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 3342 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 3353 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 3359 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 3370 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 3379 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 3383 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 3392 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 3396 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 3404 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 3408 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3418 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 3425 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3434 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3443 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 3448 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3457 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3466 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3475 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3488 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 3492 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3504 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 3508 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 3515 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 3519 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3528 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3532 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3536 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 3544 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3548 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 3554 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 3560 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3566 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 3576 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 3580 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 3584 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 3592 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3596 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 368:

/* Line 690 of lalr1.cc  */
#line 3602 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3612 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3616 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3626 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3630 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3640 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3644 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3654 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3658 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3668 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3672 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3680 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3684 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3688 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3692 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3702 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3706 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3710 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3718 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3722 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3726 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3730 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3734 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3738 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3746 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3750 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3754 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3762 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3766 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3770 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3774 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3785 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3791 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3801 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3807 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3817 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3821 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3825 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3863 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3867 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3877 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3887 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3900 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3909 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 412:

/* Line 690 of lalr1.cc  */
#line 3919 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3923 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3932 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3936 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3945 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3951 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3959 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3965 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3977 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3983 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3993 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3997 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 4001 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 4005 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 4009 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 4015 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 4021 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 4029 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 4033 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 4041 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 4045 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 4056 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 4060 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 4064 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 4070 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 4074 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 4088 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 4092 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 4100 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 4104 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 4114 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 4118 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 4122 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 4126 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 4135 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 4139 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 4143 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 4147 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 4155 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 4161 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 4171 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 4179 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 4183 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 4187 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 4191 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 4195 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 4199 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 4203 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 4207 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 4211 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 4215 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 4220 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 4224 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 4228 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 4232 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 4240 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 4244 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 4252 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 4259 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 4266 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 4277 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 4285 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 4289 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 4297 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 4305 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 4313 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 4367 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 4371 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 4384 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 4390 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 4400 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 4404 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 4412 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 4416 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 4420 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 4428 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 488:

/* Line 690 of lalr1.cc  */
#line 4438 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 489:

/* Line 690 of lalr1.cc  */
#line 4448 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 490:

/* Line 690 of lalr1.cc  */
#line 4458 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 491:

/* Line 690 of lalr1.cc  */
#line 4468 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 492:

/* Line 690 of lalr1.cc  */
#line 4478 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 493:

/* Line 690 of lalr1.cc  */
#line 4493 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 4499 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 4510 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 4516 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 4527 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 4544 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 4549 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 4558 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 4562 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 4569 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 4575 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 4581 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 4589 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 4601 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 4605 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 4612 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 4618 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 4624 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 4631 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 4642 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 4646 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 4656 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 4660 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 4670 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 4674 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 4678 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 4683 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 4692 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 4698 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 4704 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 4710 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 4718 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 4723 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 4731 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 4736 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 4744 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 4752 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 4757 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 4762 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 4767 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 4772 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 4777 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 4786 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 4794 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 4798 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 4815 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 4819 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 4827 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 4835 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 4843 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 4847 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 4855 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 4861 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 4871 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 4879 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 4883 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 4887 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 4922 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 4928 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 4934 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 4944 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 4948 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 4952 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 4956 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 4960 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 4964 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 4968 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 4975 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 4981 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 4991 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 4999 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 5003 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 5007 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 5011 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 5015 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 5019 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 5023 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 5027 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 5031 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 5039 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 5047 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 5051 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 5055 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 5065 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 5073 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 5081 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 5085 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 5089 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 5097 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 5101 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 5107 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 5113 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 5117 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 5127 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 5135 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 5139 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 5145 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 5154 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 5163 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 5169 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 5175 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 5185 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 5202 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 5209 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 5224 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 5260 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 5264 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 5272 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 5280 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 5292 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 5296 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 5304 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 5312 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 5316 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 5327 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 5344 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 5350 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 5356 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 5366 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 5370 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 5376 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 5382 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 5386 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 5392 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 5396 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 5402 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 5408 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 5415 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 5425 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 5430 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 5438 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 5444 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 5454 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 5476 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 5485 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 5491 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 5504 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 5518 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 5525 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 5531 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 5541 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 5550 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 5558 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 5564 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 5582 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 5590 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 5594 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 5601 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 5606 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 5614 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 5618 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 5625 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 5629 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 5636 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 5640 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 5647 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 5651 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 5660 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 5672 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 5676 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 5683 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 5687 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 5695 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 5703 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 5711 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 5715 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 5722 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 5726 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 5734 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 5745 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 5749 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 5757 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 5769 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 5775 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 5784 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 5788 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 5796 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 5800 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 5804 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 5811 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 5815 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 5822 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 5826 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 5834 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 5838 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 5842 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 5846 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 5850 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 5858 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 5866 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 5878 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 5890 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 5894 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 5898 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 5906 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 5912 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 5922 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 5926 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 5930 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 5934 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 5938 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 5942 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 5946 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 5950 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 5958 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 5962 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 5966 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 5970 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 5978 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 5984 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 5994 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 6004 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 6008 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 6016 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 709:

/* Line 690 of lalr1.cc  */
#line 6026 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 710:

/* Line 690 of lalr1.cc  */
#line 6037 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 6044 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 6048 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 6055 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 6059 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 6066 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 6071 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 6080 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 6089 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 6093 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 6100 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 6104 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 6112 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 6121 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 6128 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 6138 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 6142 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 6149 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 6155 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 6164 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 6168 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 6175 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 6180 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 6192 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 6200 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 6212 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 6220 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 6224 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 6232 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 6236 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 6240 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 6248 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 6256 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 6260 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 6264 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 6268 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 6276 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 6284 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 6296 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 6300 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 6308 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 6322 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSON_ObjectConstructor( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 6329 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_PairConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 6333 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          JSON_PairList* jpl;
          if (dynamic_cast<JSON_PairConstructor*>((yysemantic_stack_[(5) - (1)].node)) != NULL)
            jpl = new JSON_PairList( LOC((yyloc)) );
          else
            jpl = dynamic_cast<JSON_PairList*>((yysemantic_stack_[(5) - (1)].node));
          jpl->push_back(new JSON_PairConstructor( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)) );
          (yyval.node) = jpl;
        }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 6346 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSON_ArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 6350 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSON_ArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 6357 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSON_ObjectConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 6362 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSON_ObjectConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 6370 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSON_ObjectConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 6375 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSON_ObjectConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 6383 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 6387 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 6394 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 6401 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in
        }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 6408 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in
        }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 6415 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in
        }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 6422 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 6426 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 6430 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 6437 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 6444 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 6451 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 6468 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 776:

/* Line 690 of lalr1.cc  */
#line 6481 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 6482 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 6483 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 6484 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 6485 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 6486 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 6487 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 6488 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 6489 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 6490 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 6491 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 6492 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 6493 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 789:

/* Line 690 of lalr1.cc  */
#line 6494 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 6495 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 792:

/* Line 690 of lalr1.cc  */
#line 6500 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 793:

/* Line 690 of lalr1.cc  */
#line 6501 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 6502 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 6503 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 796:

/* Line 690 of lalr1.cc  */
#line 6504 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 6505 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 798:

/* Line 690 of lalr1.cc  */
#line 6506 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 6507 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 6508 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 6509 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 802:

/* Line 690 of lalr1.cc  */
#line 6510 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 803:

/* Line 690 of lalr1.cc  */
#line 6511 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 6512 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 805:

/* Line 690 of lalr1.cc  */
#line 6513 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 6514 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 6515 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 6516 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 6517 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 6518 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 6519 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 6520 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 6521 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 6522 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 6523 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 6524 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 6525 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 6526 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 6527 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 6528 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 6529 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 6530 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 6531 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 6532 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 6533 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 6534 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 6535 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 6536 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 6537 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 6538 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 6539 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 6540 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 6541 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 6542 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 6543 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 6544 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 6545 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 6546 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 6547 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 6548 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 6549 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 6550 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 6551 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 6552 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 6553 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 6554 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 6555 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 6556 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 6557 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 6558 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 6559 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 6560 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 6561 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 6562 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 6563 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 6564 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 6565 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 6566 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 6567 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 6568 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 6569 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 6570 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 6571 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 6572 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 6573 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 6574 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 6575 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 6576 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 6577 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 6578 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 6579 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 6580 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 6581 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 6582 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 6583 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 6584 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 6585 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 6586 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 6587 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 6588 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 6589 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 6590 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 6591 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 6592 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 6593 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 6594 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 6595 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 6596 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 6597 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 6598 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 6599 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 6600 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 6601 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 6602 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 6603 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 6604 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 6605 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 6606 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 6607 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 6608 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 6609 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 6610 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 6611 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 6612 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 6613 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 6614 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 6615 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 6616 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 6617 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 6618 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 6619 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 6620 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 6621 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 6622 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 6623 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 6624 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 6625 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 6626 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 6627 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 6628 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 6629 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 6630 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 6631 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 6632 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 6633 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 6634 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 6635 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 6636 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 6637 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 6638 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 6639 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 6640 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 6641 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 6642 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 6643 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 6644 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 6645 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 6646 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 6647 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 6648 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 6649 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 6650 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 6651 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 6652 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 6653 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 6654 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 6655 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 6656 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 6657 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 6658 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 6659 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 6660 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 6661 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 6662 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 6663 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 6664 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 6665 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 6666 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 6667 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 6668 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 6669 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 6670 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 6671 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 6672 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 6673 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 6674 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 6675 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 6676 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 6677 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 6678 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 6679 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 6680 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 6681 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 6682 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 6683 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 6684 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 6685 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 6686 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 6687 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 6688 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 6689 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 6690 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 6691 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 6692 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 6693 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 6694 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 6695 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 6696 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 6697 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 6698 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 6699 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 6700 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 6701 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 6702 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 6703 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 6708 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 11910 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1465;
  const short int
  xquery_parser::yypact_[] =
  {
      3174, -1465, -1465, -1465,  4715,  4715,  4715, -1465, -1465,    57,
     194, -1465,    66,   215, -1465, -1465, -1465,   620, -1465, -1465,
   -1465,    37,   303,   695,   120,   322,   436,   694, -1465,    10,
   -1465, -1465, -1465, -1465, -1465, -1465,   703, -1465,   502,   532,
   -1465, -1465, -1465, -1465,   389, -1465,   723, -1465,   567,   618,
   -1465,   226, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465,
   -1465, -1465, -1465, -1465, -1465, -1465,   604,   631, -1465, -1465,
   -1465, -1465,   565, 10567, -1465, -1465, -1465,   637, -1465, -1465,
   -1465,   711, -1465,   719,   728, -1465, -1465, 14638, -1465, -1465,
   -1465, -1465, -1465, -1465, -1465, -1465,   740, -1465, -1465,   747,
     769, -1465, -1465, -1465, -1465, -1465, -1465, -1465,  3483,  6563,
    6871, 14638, -1465, -1465, -1465, -1465, -1465, -1465, -1465,   721,
   -1465, -1465,   775, 11456, -1465, 11757,   785,   790, -1465, -1465,
   -1465,   794, -1465,  9951, -1465, -1465, -1465, -1465, -1465, -1465,
     741, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465,    84,
     704, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465,   -79,
     766,   -65, -1465,  -112,   119, -1465, -1465, -1465, -1465, -1465,
   -1465,   812, -1465,   691,   692,   696, -1465, -1465,   777,   781,
   -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465,
   -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465,
   -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465,
   -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465,
   -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465,
   -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465,
   -1465, -1465, -1465,  7179,  7487, -1465,   622, -1465, -1465, -1465,
   -1465,  5023,   937, -1465,  5331, -1465, -1465,   133,    82, -1465,
   -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465,
   -1465, -1465, -1465,    88, -1465, -1465, -1465, -1465, -1465, -1465,
     336, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465,  4715,
   -1465, -1465, -1465, -1465,    25, -1465, -1465, -1465, -1465, -1465,
   -1465, -1465, -1465,   832, -1465,   750, -1465, -1465, -1465,   151,
   -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465,   780,   849,
   -1465,   855,   705,   517,   454,   288,   580, -1465,   892,   749,
     848,   850,  8719, -1465, -1465, -1465,   -14, -1465, -1465, 10259,
   -1465,   689, -1465,   796, 10567, -1465,   796, 10567, -1465, -1465,
   -1465,   643, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465,
   -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465,
   -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465,
   -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465,
   -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465,
   -1465, -1465, -1465,   806,   799, -1465, -1465, -1465, -1465, -1465,
     773, -1465,  4715,   782,   783,   382,   382,   929,   597,   603,
     504, 14924, 14638,   461,   912, 14638,   809,   847,   470, 11456,
     663,   724, 14638, 14638,   667,   583,    41, -1465, -1465, -1465,
   11456,  4715,   784,  4715,   109,  9027, 13494,   685,   697, 14638,
     854,     2,   820,  9027,   973,   135,    96, 14638,   859,   839,
     875, -1465,  9027, 11161, 14638, 14638, 14638,  4715,   798,  9027,
    9027, 14638,  4715,   830,   835, -1465, -1465, -1465,  9027, 13780,
     834, -1465,   836, -1465, -1465, -1465, -1465,   837, -1465,   843,
   -1465, -1465, -1465, -1465, -1465,   844, -1465, -1465, -1465, -1465,
   -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465,
   -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465,
   -1465, -1465, -1465, -1465, 14638, -1465, -1465, -1465, -1465, -1465,
   -1465, -1465, -1465, -1465, -1465, -1465, -1465,   860, 14638, -1465,
   -1465, -1465,   807,  3791,   882,    49,   853,   857,   862, 14638,
    4715, -1465,   852,    27, -1465,   346, -1465,    59,   971,  9027,
   -1465, -1465,    64, -1465, -1465, -1465,   993, -1465, -1465, -1465,
   -1465,  9027,   802, -1465,   986,  9027,  9027, 12055,   833,  9027,
    9027,  9027,  9027, 12055,  9027,   789,   792, 14638,   838,   840,
    9027,  9027,  3483,   778, -1465,   -42, -1465,   -43,  9027, -1465,
   -1465, -1465, -1465,    66,   694,    90,    94,  1019,  5639,  5639,
    5947,  5947,   711, -1465, -1465,   832,   711, -1465,  9027, -1465,
     906,   120,    10,   861,   865,   867,  4715,  9027, -1465, -1465,
   -1465, -1465, -1465, -1465, -1465, -1465,  9335,  9335,  9335, -1465,
    9335,  9335, -1465,  9335, -1465,  9335, -1465, -1465, -1465, -1465,
   -1465, -1465, -1465,  9335,  9335,   956,  9335,  9335,  9335,  9335,
    9335,  9335,  9335,  9335,  9335,  9335,  9335,   801,   943,   944,
     948, -1465, -1465, -1465,  7795, -1465, -1465,  9951,  9951,  9027,
     796, -1465, -1465,   796, -1465,  8103,   796,   883,  8411, -1465,
   -1465, -1465,    62, -1465,   222, -1465, -1465, -1465, -1465, -1465,
   -1465,   939,   940,   322,  1014, -1465, -1465, 14924,  1025,   527,
   14638,   888,   890,  1025,   929,   925,   921, -1465, -1465, -1465,
     472,   810,   959,   758, 14638,   923,  9027,   949, 14638, 14638,
   -1465,   934,   884,  4715, -1465,   885,   836,   532, -1465,   886,
     887,   247, -1465,   235,   237, -1465, -1465,   963, -1465,    38,
   14638,    26, 14638,   976,   242, -1465,  4715, -1465,   249, -1465,
   11456,   978,  1031, 11456,   929,   984,   530, 14638,  9027,    10,
     251,   895, -1465,   896,   898,   899,   227, -1465,    63,   904,
   -1465,   262,   290,   936, -1465,   907,  4715,  4715,   259, -1465,
     297,   300,   559,  9027,   231, -1465, -1465,  9027,  9027, -1465,
    9027,  9027,  9027, -1465,  9027, -1465,  9027, -1465, 14638,   971,
   -1465,    12,   364, -1465, -1465, -1465,   395, -1465,   205, -1465,
   -1465,   945,   946,   947,   964,   965,   941,   806, -1465,   100,
     107,   858,   998,   960,   889,   897,   893,    42, -1465,   977,
   -1465, -1465,   932,   321,  4099,   423, 10866,   778, -1465, -1465,
   -1465,   926,   133,   693,  1092,  1092, -1465, -1465,    97, -1465,
   -1465,   104, -1465,   116, -1465, -1465, -1465, -1465, -1465, -1465,
   -1465, 14638,   957,  9027,  1010, -1465, -1465, -1465,   849, -1465,
   -1465, -1465, -1465, -1465,  9335, -1465, -1465, -1465,    58,   454,
     454,   207,   288,   288,   288,   288,   580,   580, -1465, -1465,
   14066, 14066, 14638, 14638, -1465,   430, -1465, -1465,    33, -1465,
   -1465, -1465,   347, -1465, -1465,   351,   382, -1465, -1465,   537,
     576,   607, -1465,   322, -1465, -1465, -1465, -1465, -1465, -1465,
   -1465, -1465, -1465, -1465,  1025, -1465,   997, 14352,   988,  9027,
   -1465, -1465, -1465,  1036,   929,   929,  1025, -1465,   736,   929,
     590, 14638,   494,   545,  1102, -1465, -1465,   856,   548, -1465,
   -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465,
     472,   160,   913,   529,  9027, -1465, 14638,  1038,   842,   929,
   -1465, -1465, -1465, -1465,   985, 14638, -1465, 14638, -1465,  1024,
    1016, 14066,  1026,  9027,   -18,   999,    39,   338,   894, -1465,
   -1465,   614,    26,  1036, 14066,  1027,  1053,   966,   954,  1017,
     929,   992,  1021,  1057,   929,  9027,    32, -1465, -1465, -1465,
    1002, -1465, -1465, -1465, -1465,  1039,  9027,  9027,  1009, -1465,
    1058,  1059,  4715, -1465,   979,   980,  1007, 14638, -1465, 14638,
   -1465,  9027,  1020,   975,  9027, -1465,  1040,   358,   362,   373,
    1130, -1465,    45, -1465,   666, -1465, -1465,  1137, -1465,  9027,
     665,  9027,  9027,  9027,   675,  9027,  9027,  9027,  9027,  9027,
    9027,  9027,  9027, 12055,  1050,  9027,  9027, -1465,  6255,  1013,
    1018,  1022,  1023,   750,   387,   928, -1465,    -5, -1465,  9027,
     111,    80,   116,  5947,  5947,  5947,  1090, -1465,  9027,   655,
    1066, -1465, 14638,  1068, -1465, -1465,  9027,    58,   475,   414,
   -1465,   900,   140,   920,   922, -1465, -1465,   724, -1465,   914,
     531,  1030,  1032, 14352,  1033,  1034,  1035,  1037,  1041, -1465,
     460, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465,
   -1465, -1465, -1465, -1465,  1043, -1465, -1465, -1465,  9027, -1465,
   -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465,   627, -1465,
    1149,   700, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465,
   -1465,   909, -1465, -1465,  1152, -1465, -1465, -1465, -1465, -1465,
     558,  1153, -1465,   673, -1465, -1465, -1465,   834,   303,   837,
     502,   843,   844,   766, -1465,   460,  9643,   910,   901, -1465,
    1036,   160,   969,  1008,  4715,  1005,  1012,  1056,  1015,  1028,
   14638,   399, -1465, 14638, -1465,  9027,  1054,  9027,  1076,  9027,
      34,  1061,  9027,  1062, -1465,  1086,  1093,  9027, 14638,   776,
    1134, -1465, -1465, -1465, -1465, -1465, -1465, 14066, -1465,  4715,
     929,  1107, -1465, -1465, -1465,   929,  1107, -1465,  9027,  1074,
    4715, 14638, -1465, -1465,  9027,  9027,   690, -1465,    30,   701,
   -1465, 12636,   702, -1465,   709, -1465,  1046, -1465, -1465,  4715,
    1044,  1045, -1465,  9027, -1465, -1465,  9027,  1042,  1058,  1117,
   -1465,  1088, -1465,   729, -1465, -1465,  1210, -1465, -1465,  4715,
   14638, -1465,   752, -1465, -1465, -1465,  1047,  1048,   990,  1001,
   -1465, -1465, -1465,  1004,  1011, -1465, -1465, -1465,  1127, -1465,
    1055, -1465,  1029,  1078, 14638,  1060, -1465, -1465,  9027,  9027,
    9027,  4407,  6255, 10866,   928, -1465, 10866, -1465, -1465,  1092,
     415, -1465, -1465, -1465,  1066, -1465,   929, -1465,   772, -1465,
     489,  1135, -1465,  9027,  1138,  1010,   449,  1063, -1465,    58,
     996, -1465, -1465,   -28, -1465,   323,   -11,  1000,    58,   323,
    9335, -1465,   154, -1465, -1465, -1465, -1465, -1465, -1465,    58,
    1100,   972,   810,   -11, -1465, -1465,   967,  1175, -1465, -1465,
   -1465, 12350,  1070,  1071,  1073,  1075,  1077,  1079,  1080, -1465,
   -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465,
   -1465,  1225,   386,  1231,   386,  1006,  1156, -1465,  1098, 14638,
    1049, -1465, -1465,  9643, -1465,  1095, -1465, -1465, -1465, -1465,
   -1465, -1465,  9027,  1125, -1465, -1465,  9027, -1465,   428, -1465,
    9027,  1133,  9027, -1465,  9027, 14638, 14638, -1465,   606, -1465,
    9027, -1465,  1148,  1151,  1184,   929,  1107, -1465,  9027,  1099,
   -1465, -1465, -1465,  1096, -1465,    31,  9027,  4715,  1101,    50,
   -1465, 14638,  1103, 12922,   213, -1465, 13208,  1105, -1465, -1465,
    1108, -1465, -1465, -1465, -1465,  9027,   733,  1130, 14638,   851,
   -1465,  1109,  1130, 14638, -1465, -1465, -1465,  9027,  9027,  9027,
    9027,   970,  1189,  9027,  9027, -1465,  9027,   397,   419,   421,
      23, -1465, -1465, -1465, -1465, -1465,  1135, -1465, -1465, -1465,
     929, -1465, -1465, -1465, -1465, -1465,  1111,  9335, -1465, -1465,
   -1465, -1465, -1465,   101,  9335,  9335,   105, -1465,   920, -1465,
     170, -1465,   922,    58,  1143, -1465, -1465,  1064, -1465, -1465,
   -1465, -1465,  1191,  1112, -1465,   434, -1465, -1465, -1465, -1465,
   -1465, -1465, -1465, -1465,   284,   284, -1465,   386, -1465, -1465,
     447, -1465,  1271,   -11,  1206,  1119,  9643,   -44,  1051,  1139,
   -1465, -1465,  9027, -1465,  9027,  1157, -1465,  9027, -1465, -1465,
   -1465,  1256, -1465, -1465,  6255,  9027,   929, -1465, -1465, -1465,
    9027,  9027, -1465, -1465, -1465,  6255,  6255,  1216,  4715, 14638,
    1126, 14638,  9027, 14638,  1128,  6255, -1465,   296,   130,  1130,
   14638, -1465,  1120,  1130, -1465, -1465, -1465, -1465,  9027,  9027,
   -1465,  1131, -1465,  1116,  1058,  1059,  9027, -1465, -1465, -1465,
   -1465,   288,  9335,  9335,   207,   570, -1465, -1465, -1465, -1465,
   -1465, -1465,  9027, -1465, 14066, -1465, 14066,  1220, -1465, -1465,
   -1465,  1287, -1465, -1465, -1465,  1065,  1212, -1465, -1465,  1213,
   -1465,   698, 14638,  1207,  1104, 14638,  9643, -1465, -1465,  9027,
   -1465,  1208, -1465, -1465,  1107, -1465, -1465, 14066, -1465, -1465,
    1229,  9027,  1141, -1465,  1237,  6255, -1465, 14638,   341,   443,
   -1465,  1142,  1130, -1465,  1144, -1465, -1465,  1097,  6255,   734,
     467,   207,   207,  9335,   473, -1465, -1465, 14066, -1465, -1465,
    1206,  9643, -1465,  1135,  1052, 14638,  1217,  1115,  1213, -1465,
   14638,  1158, 14066,  4715, 14066,  1161, -1465, -1465,  1248,   390,
   -1465, -1465, -1465, -1465,  1166,   613, -1465, -1465, -1465,  1154,
   -1465,  9027,  1233, -1465,   207, -1465, -1465, -1465, -1465, -1465,
    9027,  1067, 14638,  1234, -1465,  4715,  1167, -1465, -1465,  1168,
    9027, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, 14638,
   -1465,  1069,  1072, 14638, -1465, -1465,  9027,  6255,  1172,  1082,
    9027,  1083,  6255,  9643, -1465,  9643, -1465,  1162,  1081, 14638,
    1140,  1241, 14638,  1084,  9643, -1465
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       159,   443,   444,   445,   162,   162,   162,   792,   996,   116,
     118,   599,   884,   893,   833,   797,   795,   777,   885,   888,
     840,   801,   778,   779,   832,   894,   781,   891,   862,   842,
     817,   837,   838,   889,   886,   836,   783,   892,   784,   785,
     933,   945,   932,   834,   853,   847,   786,   835,   788,   787,
     934,   871,   872,   839,   814,   955,   956,   957,   958,   959,
     960,   961,   962,   963,   964,   965,   979,   986,   861,   857,
     848,   828,   776,     0,   856,   864,   873,   980,   852,   469,
     829,   830,   887,   981,   987,   849,   866,     0,   475,   432,
     471,   859,   794,   850,   851,   880,   854,   870,   879,   985,
     988,   800,   841,   882,   470,   869,   875,   780,     0,     0,
       0,     0,   380,   867,   878,   883,   881,   860,   846,   935,
     844,   845,   982,     0,   379,     0,   983,   989,   876,   831,
     855,   984,   410,     0,   442,   877,   858,   865,   874,   868,
     936,   822,   827,   826,   825,   824,   823,   789,   843,     0,
     793,   890,   815,   924,   923,   925,   799,   798,   818,   930,
     782,   922,   927,   928,   919,   821,   863,   921,   931,   929,
     920,   819,   926,   940,   941,   938,   939,   937,   790,   942,
     943,   944,   910,   909,   896,   813,   806,   903,   899,   816,
     812,   911,   912,   802,   803,   796,   805,   908,   907,   904,
     900,   917,   918,   916,   906,   902,   895,   804,   915,   914,
     808,   810,   809,   901,   905,   897,   811,   898,   807,   913,
     966,   967,   968,   969,   970,   971,   947,   948,   946,   952,
     953,   954,   949,   950,   951,   820,   972,   973,   974,   975,
     976,   977,   978,     0,     0,   990,   991,   992,   994,   993,
     995,   159,     0,     2,   159,     5,     7,    19,     0,    24,
      27,    32,    33,    34,    35,    36,    37,    38,    28,    54,
      55,    29,    30,     0,    72,    75,    76,    31,    77,    78,
       0,   114,    79,    80,    81,    82,    14,   156,   157,   158,
     165,   167,   462,   168,     0,   169,   170,   171,   172,   173,
     174,   175,   178,   163,   204,   211,   206,   238,   244,     0,
     236,   237,   213,   207,   177,   208,   176,   209,   212,   335,
     337,   339,   349,   353,   355,   358,   363,   366,   369,   371,
     373,   375,     0,   377,   383,   385,     0,   401,   384,   406,
     409,   411,   414,   416,     0,   421,   418,     0,   429,   439,
     441,   415,   446,   453,   467,   454,   455,   456,   459,   460,
     457,   458,   482,   484,   485,   486,   483,   531,   532,   533,
     534,   535,   536,   438,   573,   565,   572,   571,   570,   567,
     569,   566,   568,   468,   461,   600,   601,    39,   214,   215,
     217,   216,   218,   210,   463,   464,   465,   466,   220,   219,
     221,   222,   223,   440,   775,   791,   884,   893,   891,   793,
       0,   160,   161,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   122,   124,   125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     263,   264,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   434,   437,   424,     0,     0,
     777,   801,   779,   832,   894,   781,   842,   783,   853,   786,
     788,   787,   871,   979,   986,   776,   980,   830,   981,   987,
     854,   985,   988,   935,   982,   983,   989,   984,   936,   930,
     922,   928,   919,   819,   940,   941,   938,   790,   942,   991,
     430,   440,   775,   422,     0,   185,   423,   426,   777,   778,
     779,   783,   784,   785,   786,   776,   782,   472,     0,   428,
     427,   180,     0,     0,   204,     0,   781,   788,   787,     0,
     162,   754,   942,     0,   211,     0,   473,     0,   498,     0,
     433,   773,     0,   774,   404,   405,     0,   436,   435,   425,
     408,     0,     0,   527,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   756,     0,   758,     0,     0,     3,
       1,     6,     8,     0,     0,     0,     0,     0,   159,   159,
     159,   159,     0,   115,   166,   164,     0,   183,     0,   192,
       0,     0,     0,     0,     0,     0,     0,     0,   197,   224,
     243,   239,   245,   240,   242,   241,     0,     0,     0,   394,
       0,     0,   392,     0,   344,     0,   393,   386,   391,   390,
     389,   388,   387,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   382,   381,   378,     0,   402,   407,     0,     0,     0,
     417,   450,   420,   419,   431,     0,   447,     0,     0,   538,
     540,   544,     0,   120,     0,   772,    43,    40,    41,    44,
      45,     0,     0,     0,     0,    46,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   610,   611,   612,
       0,    99,   138,     0,     0,   108,     0,     0,     0,     0,
     123,     0,     0,     0,   579,     0,     0,     0,   575,     0,
       0,     0,   589,     0,     0,   226,   227,   246,   247,     0,
       0,     0,     0,   130,     0,   134,   162,   603,     0,    56,
       0,    65,     0,     0,     0,    57,     0,     0,     0,     0,
       0,     0,   580,     0,     0,     0,     0,   308,     0,     0,
     578,     0,     0,     0,   597,     0,     0,     0,     0,   583,
       0,     0,   187,     0,     0,   181,   179,     0,     0,   751,
       0,     0,     0,   472,     0,   755,     0,   474,   499,   498,
     495,     0,     0,   529,   528,   403,     0,   526,     0,   623,
     624,   777,   779,   783,   786,   776,     0,     0,   574,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   629,     0,
     195,   196,     0,     0,     0,     0,     0,   200,   201,   757,
     759,     0,    20,     0,    21,     0,     4,    25,     0,    11,
      26,     0,    15,   884,    73,    12,    74,    16,   186,   184,
     205,     0,     0,     0,     0,   198,   225,   281,   336,   338,
     342,   348,   347,   346,     0,   343,   340,   341,     0,   357,
     356,   354,   360,   361,   362,   359,   364,   365,   368,   367,
       0,     0,     0,     0,   399,     0,   412,   413,     0,   451,
     448,   480,     0,   602,   478,     0,     0,   117,   119,     0,
       0,     0,    98,     0,    88,    90,    91,    92,    93,    95,
      96,    97,    89,    94,    84,    85,     0,     0,   104,     0,
     100,   102,   103,   110,     0,     0,    83,    42,     0,     0,
       0,     0,     0,     0,     0,   701,   706,     0,     0,   702,
     736,   689,   691,   692,   693,   695,   697,   696,   694,   698,
       0,     0,     0,     0,     0,   107,     0,   140,     0,     0,
     543,   537,   576,   577,     0,     0,   593,     0,   590,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   228,
     229,     0,   234,   136,     0,     0,   131,     0,     0,     0,
       0,     0,     0,    58,     0,     0,     0,   262,   268,   265,
       0,   582,   581,   588,   596,     0,     0,     0,     0,   542,
       0,     0,     0,   395,     0,     0,     0,     0,   586,     0,
     584,     0,   188,     0,     0,   752,     0,     0,     0,     0,
     498,   496,     0,   487,     0,   476,   477,     0,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   193,     0,   781,
     788,   787,   942,     0,     0,     0,   637,     0,   202,     0,
       0,     0,     0,   159,   159,   159,     0,   235,     0,   292,
     288,   290,     0,   282,   283,   345,     0,     0,     0,     0,
     667,   351,   640,   644,   646,   648,   650,   653,   660,   661,
     669,   894,   780,     0,   789,     0,   994,   993,   995,   370,
     549,   555,   556,   559,   604,   605,   560,   561,   766,   767,
     768,   564,   372,   374,   546,   376,   400,   452,     0,   449,
     479,   121,    52,    53,    50,    51,   127,   126,     0,    86,
       0,     0,   105,   106,   111,    70,    71,    48,    49,    69,
     707,     0,   710,   737,     0,   700,   699,   704,   703,   735,
       0,     0,   712,     0,   708,   711,   690,     0,     0,     0,
       0,     0,     0,     0,   139,   142,     0,     0,     0,   109,
     112,     0,     0,     0,   162,     0,     0,   597,     0,     0,
       0,     0,   548,     0,   249,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   230,     0,     0,     0,     0,   275,
       0,   272,   277,   233,   137,   132,   135,     0,   182,     0,
       0,    67,    61,    64,    63,     0,    59,   266,     0,     0,
     162,     0,   306,   310,     0,     0,     0,   313,     0,     0,
     319,     0,     0,   326,     0,   330,     0,   397,   396,   162,
       0,     0,   189,     0,   191,   307,     0,     0,     0,     0,
     499,     0,   488,     0,   522,   519,     0,   523,   524,     0,
       0,   518,     0,   493,   521,   520,     0,     0,     0,     0,
     616,   617,   613,     0,     0,   621,   622,   618,   760,   627,
       0,   625,     0,     0,     0,     0,   631,   194,     0,     0,
       0,     0,     0,     0,   632,   633,     0,   203,   765,    22,
       0,    13,    17,    18,   289,   301,     0,   302,     0,   293,
     294,   295,   296,     0,   285,     0,     0,     0,   651,   664,
       0,   350,   352,     0,   683,     0,     0,     0,     0,     0,
       0,   639,   641,   642,   678,   679,   680,   682,   681,     0,
       0,   655,   654,     0,   658,   662,   676,   674,   673,   666,
     670,     0,     0,     0,     0,     0,     0,     0,     0,   552,
     554,   553,   550,   547,   481,   129,   128,    87,   101,   724,
     705,     0,   729,     0,   729,   718,   713,   143,     0,     0,
       0,   113,   141,     0,    23,     0,   594,   595,   598,   591,
     592,   248,     0,     0,   261,   253,     0,   257,     0,   251,
       0,     0,     0,   270,     0,     0,     0,   232,   273,   276,
       0,   133,     0,     0,    66,     0,    60,   267,     0,     0,
     309,   311,   316,     0,   314,     0,     0,     0,     0,     0,
     320,     0,     0,     0,     0,   327,     0,     0,   331,   398,
       0,   587,   585,   190,   753,     0,     0,   498,     0,     0,
     530,     0,   498,     0,   494,    10,   762,     0,     0,     0,
       0,     0,     0,     0,     0,   630,     0,     0,     0,     0,
       0,   634,   638,   305,   303,   304,   297,   298,   299,   291,
       0,   286,   284,   668,   659,   665,     0,     0,   738,   739,
     749,   748,   747,     0,     0,     0,     0,   740,   645,   746,
       0,   643,   647,     0,     0,   652,   656,     0,   677,   672,
     675,   671,     0,     0,   562,     0,   557,   609,   551,   770,
     771,   769,   558,   725,     0,     0,   723,   730,   731,   727,
       0,   722,     0,   720,     0,     0,     0,     0,     0,     0,
     539,   250,     0,   259,     0,     0,   255,     0,   258,   271,
     279,   280,   274,   231,     0,     0,     0,    62,   269,   545,
       0,     0,   317,   321,   315,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   541,     0,     0,   498,
       0,   525,     0,   498,   614,   615,   619,   620,     0,     0,
     626,     0,   628,     0,     0,     0,     0,   635,   300,   287,
     663,   750,     0,     0,   742,     0,   688,   687,   686,   685,
     684,   649,     0,   741,     0,   606,     0,     0,   734,   733,
     732,     0,   726,   719,   717,     0,   714,   715,   709,   144,
     146,   148,     0,     0,     0,     0,     0,   254,   252,     0,
     260,     0,   199,   334,    68,   312,   318,     0,   332,   328,
       0,     0,     0,   322,     0,     0,   324,     0,   508,   502,
     497,     0,   498,   489,     0,   761,   763,     0,     0,     0,
       0,   744,   743,     0,     0,   607,   563,     0,   728,   721,
       0,     0,   150,   149,     0,     0,     0,     0,   145,   256,
       0,     0,     0,     0,     0,     0,   516,   510,     0,   509,
     511,   517,   514,   504,     0,   503,   505,   515,   491,     0,
     490,     0,     0,   636,   745,   657,   608,   716,   147,   151,
       0,     0,     0,     0,   278,     0,     0,   325,   323,     0,
       0,   501,   512,   513,   500,   506,   507,   492,   764,     0,
     152,     0,     0,     0,   333,   329,     0,     0,     0,     0,
       0,     0,     0,     0,   154,     0,   153,     0,     0,     0,
       0,     0,     0,     0,     0,   155
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1465, -1465,  -219,  1110, -1465,  1113,  1114, -1465,  1121,  -539,
   -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465,
    -982, -1465, -1465, -1465, -1465,  -238,  -585, -1465,   649,  -122,
   -1465, -1465, -1465, -1465, -1465,   203,   427, -1465, -1465,    -1,
    -194,   953, -1465,   935, -1465, -1465,  -643, -1465,   371, -1465,
     178, -1465,  -286,  -329, -1465,  -532, -1465,    24,    18,    51,
    -251,  -170, -1465,  -859, -1465, -1465,    65, -1465, -1465, -1465,
   -1465, -1465, -1465, -1465, -1465, -1465, -1465,   536,   -93,  1429,
       0, -1465, -1465, -1465, -1465,   388, -1465, -1465,  -291, -1465,
       8, -1465, -1465,   179,  -722,  -709, -1465, -1465,   624, -1465,
   -1465,   -47,   165, -1465, -1465, -1465,    52, -1465, -1465,   298,
      56, -1465, -1465,    55, -1288, -1465,   864,   149, -1465, -1465,
     147,  -999, -1465, -1465,   145, -1465, -1465, -1238, -1211, -1465,
     141, -1465, -1465,   770,   771, -1465,  -544, -1465, -1465,  -655,
     253,  -625,   250,   254, -1465, -1465, -1465, -1465, -1465,  1087,
   -1465, -1465, -1465, -1465,  -817,  -326, -1147, -1465,   -90, -1465,
   -1465, -1465, -1465, -1465, -1465, -1465,   -15,  -826, -1465, -1465,
     497,   208,  -535,  -414, -1465, -1465, -1465, -1465, -1465, -1465,
   -1465,   722, -1465, -1010, -1465,   124, -1465,   602,  -794, -1465,
   -1465, -1465, -1465, -1465,  -323,  -316, -1168, -1040, -1465, -1465,
   -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465,   511,  -745,
    -821,   225,  -847, -1465,    21,  -835, -1465, -1465, -1465, -1465,
   -1465, -1465, -1465,   981,   982,  -307,   435,   261, -1465, -1465,
   -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465,
   -1465, -1465,   110, -1465, -1465,   103, -1465,   106, -1048, -1465,
   -1465, -1465,    70,    61,  -101,   325, -1465, -1465, -1465, -1465,
   -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465,    73,
   -1465, -1465, -1465,   -94,   320,   468, -1465, -1465, -1465, -1465,
   -1465,   256, -1465, -1465, -1464, -1465, -1465, -1465,  -627, -1465,
      36, -1465,  -116, -1465, -1465, -1465, -1465, -1291, -1465,    83,
   -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465, -1465,
   -1465, -1465, -1465, -1465, -1465,  -410,  -379,   233,   952, -1465
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   252,   855,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
    1241,   764,   270,   271,   272,   273,   274,   275,   934,   935,
     936,   276,   277,   278,   940,   941,   942,   279,   435,   280,
     281,   692,   282,   437,   438,   439,   452,   754,   755,   283,
    1194,   284,  1659,  1660,   285,   286,   287,   542,   288,   289,
     290,   291,   292,   757,   293,   294,   525,   295,   296,   297,
     298,   299,   300,   628,   301,   302,   847,   848,   303,   304,
     554,   306,   629,   450,  1001,  1002,   307,   630,   308,   632,
     555,   310,   747,   748,  1229,   459,   311,   460,   461,   751,
    1230,  1231,  1232,   633,   634,  1103,  1104,  1511,   635,  1100,
    1101,  1339,  1340,  1341,  1342,   312,   776,   777,   313,  1256,
    1257,  1455,   314,  1259,  1260,   315,   316,  1262,  1263,  1264,
    1265,   317,   318,   319,   320,   884,   321,  1351,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     653,   654,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     680,   681,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   912,   361,   362,   363,  1292,   809,   810,   811,  1690,
    1734,  1735,  1728,  1729,  1736,  1730,  1293,  1294,   364,   365,
    1295,   366,   367,   368,   369,   370,   371,   372,  1143,   996,
    1129,  1392,  1130,  1545,  1131,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   783,  1206,   383,   384,   385,
     386,  1133,  1134,  1135,  1136,   387,   388,   389,   390,   391,
     392,   837,   838,   393,  1324,  1325,  1627,  1087,  1111,  1361,
    1362,  1112,  1113,  1114,  1115,  1116,  1371,  1535,  1536,  1117,
    1374,  1118,  1516,  1119,  1120,  1379,  1380,  1541,  1539,  1363,
    1364,  1365,  1366,  1639,   721,   961,   962,   963,   964,   965,
     966,  1184,  1565,  1656,  1185,  1563,  1654,   967,  1404,  1560,
    1556,  1557,  1558,   968,   969,  1367,  1375,  1526,  1368,  1522,
    1352,   394,   545,   395,   396,   397,   398,   399,   400,   401,
     402,  1137,  1138,  1139,  1140,  1242,   562,   403,   404,   405
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       305,   693,   693,   891,   305,   305,   305,   696,   309,   593,
     675,   436,   309,   309,   309,  1052,   553,   557,   631,   606,
    1086,  1016,   411,   411,   411,   864,   866,   994,   410,   413,
     414,  1258,  1246,  1028,   892,   893,   894,   895,   614,   609,
     995,  1476,   826,   570,  1291,   761,   765,  1042,   833,  1408,
     716,  1465,  1507,  1508,   611,   412,   412,   412,   520,  1347,
     921,   731,  1157,   618,   618,  1132,  1132,     9,    10,   857,
     860,  1109,   813,  1662,   990,  1218,   859,   862,   865,   867,
    1142,   998,  1537,   607,   773,  1523,   613,    11,   421,   607,
    1161,   607,     9,    10,   880,   607,   881,   882,   607,   883,
    1657,   885,  1132,   417,   418,   607,   419,   420,   305,   886,
     887,   582,   607,   421,   572,   424,   309,   417,   418,   752,
     419,   420,   422,   423,  1484,   695,   411,   457,  1215,  1456,
    1456,   616,   991,   618,   992,   992,  1195,   423,   674,   618,
     424,  1053,     9,    10,   575,   425,   576,  1321,  1074,  1456,
     595,   597,   727,  1632,   736,   798,  1132,   991,   579,   543,
     580,   614,   125,   421,   695,   618,   603,    79,   916,  1132,
    1212,   737,   422,  1248,  1282,  1626,   426,   427,   428,  1663,
    1430,    90,   604,  1235,   993,  1219,   447,  1518,   753,   443,
     424,   448,  1330,   620,  1060,   425,   615,   621,  1164,  1187,
     583,  1064,   622,  1326,  1188,   736,   104,  1054,   762,  1027,
    1106,   805,   415,  1107,   617,  1457,  1591,  1147,  1628,  1189,
     623,  1190,   737,  1688,  1519,   429,   426,   427,  1096,  1633,
    1191,  1326,   799,   577,   125,  1596,  1353,   449,   814,   429,
    1283,   999,   613,  1524,  1525,   807,  1747,   581,   917,   676,
    1353,   305,  1223,   458,   305,   763,  1281,  1192,  1234,   309,
    1459,  1664,   309,  1446,   631,  1465,  1569,   849,   850,   864,
     866,   608,  1655,  1291,  1220,  1075,  1383,   610,  1000,   852,
    1158,   458,  1291,   854,   430,  1216,  1093,  1221,  1132,   305,
    1109,  1109,   614,  1095,   760,   738,   573,   309,   430,  1396,
    1329,  1515,   471,   458,   947,   458,   521,  1249,  1354,   458,
     458,  1484,  1689,   857,   860,  1108,  1061,  1062,   624,   615,
     537,   625,  1354,  1065,  1066,   431,   728,   656,   916,   682,
    1601,  1063,   684,  1025,   729,  1057,   626,  1025,  1067,   431,
    1105,   985,   584,   987,   558,   657,  1726,   585,  1005,   416,
    1284,   432,   741,   618,  1013,   618,   563,   618,   566,   433,
     758,   627,     9,    10,   656,   618,  1195,   434,   618,   770,
     858,   861,  1636,  1712,   440,   875,   781,   782,   472,  1637,
    1401,  1009,   657,  1193,  1012,   788,   853,  1699,   620,  1638,
    1355,  1356,   621,  1357,  1058,  1726,   618,   622,  1602,  1284,
    1358,   432,  1132,  1037,  1355,  1356,  1039,  1357,   918,   433,
    1359,    11,   305,  1687,  1026,   623,  1441,   434,  1044,  1661,
     309,   986,  1360,   988,  1359,  1749,  1132,   618,  1006,   620,
     984,   586,   991,   621,  1020,  1008,  1360,  1636,   622,  1403,
    1462,   305,  1036,   305,  1637,   473,   474,   612,  1030,   309,
     615,   309,  1284,  1148,  1638,  1411,   623,  1148,   444,   732,
     711,   735,   712,  1287,   618,  1288,   812,   305,   618,  1291,
     618,  1732,   305,  1727,  1110,   309,  1031,   451,   816,   618,
     309,  1602,   614,  1038,  1222,   779,  1040,   663,  1465,  1423,
     785,    79,   733,  1289,   733,   992,   664,  1086,   843,   845,
    1502,   618,  1151,   618,    11,    90,   466,  1078,   864,   866,
     864,  1431,  1287,   624,  1288,   711,   625,   712,   733,  1661,
     714,  1554,  1762,   733,   992,   618,   950,   618,   951,   618,
     104,   806,  1109,  1149,  1165,  1166,   618,  1150,  1313,  1169,
    1646,  1109,  1289,   305,  1277,  1422,  1132,  1055,  1278,   713,
     305,   309,  1109,  1651,   624,   618,   627,   625,   309,  1279,
    1544,  1331,  1332,  1333,  1661,  1287,  1349,  1288,   411,  1203,
     659,   952,  1322,   618,  1574,   714,  1733,   521,  1056,   618,
     521,   905,   715,  1623,    79,  1555,   908,   906,   907,  1520,
     125,   453,   305,   614,  1336,  1289,  1521,   627,    90,   660,
     309,   412,   436,  1389,  1674,  1624,  1085,  1625,   305,   305,
     305,   305,   661,  1146,  1090,  1338,   309,   309,   309,   309,
    1647,   937,  1284,   104,   991,  1459,   305,  1106,  1132,   705,
    1107,  1132,  1513,  1652,   309,  1390,  1786,   715,  1787,  1094,
     615,  1732,  1600,   844,  1181,  1604,   662,  1795,  1731,  1737,
    1743,   125,  1391,   991,  1401,   704,  1745,   464,   708,  1225,
    1182,   706,   563,   938,  1226,   722,   723,  1225,   939,   701,
    1402,  1015,  1226,   563,   656,  1284,  1285,   868,  1205,   744,
    1208,   869,   749,  1608,  1152,   702,   477,   465,  1612,  1731,
     766,  1227,   657,  1110,  1110,  1737,   563,   774,   775,   778,
    1041,  1153,   992,  1183,   784,  1530,  1575,  1047,  1048,  1049,
     992,   845,   791,  1403,   658,   665,  1109,   478,   454,   725,
     479,   953,   469,  1154,   726,   475,  1091,   656,   455,   666,
    1270,  1228,  1271,   305,   954,  1287,   955,  1288,  1284,  1285,
    1155,   309,   604,  1156,   864,   657,  1765,   956,   957,   958,
    1335,   959,   476,   960,   456,  1175,   305,   792,   523,   756,
    1336,  1284,  1285,  1395,   309,  1289,  1176,  1703,  1286,  1181,
    1337,   778,   441,   470,   411,   442,  1376,  1377,   697,   756,
    1007,  1338,   803,   675,   699,  1182,   305,   305,  1287,  1255,
    1288,   698,   991,   631,   309,   309,   679,   700,   685,  1378,
    1255,  1463,  1453,  1336,  1034,  1035,  1177,   412,  1466,  1132,
     827,  1132,  1159,  1458,  1464,  1691,   827,  1178,  1289,  1694,
     839,  1467,   111,  1705,  1159,  1706,  1197,  1317,   524,  1225,
    1444,  1286,  1463,  1463,  1226,  1198,   938,   733,   733,   123,
     526,   939,  1132,   683,  1083,  1607,  1742,   445,   686,   527,
     446,  1287,  1084,  1288,  1286,   462,  1721,   538,   463,  1290,
    1284,  1285,   436,  1167,  1168,  1170,  1171,  1172,   539,  1634,
    1635,  1173,  1132,   559,  1287,   467,  1288,   149,   468,   677,
     678,  1289,   717,   718,   719,   111,  1746,  1132,   909,  1132,
     540,   909,  1631,   571,   909,  1298,   560,  1299,  1739,  1504,
    1505,  1756,   123,  1759,  1289,  1303,   567,  1304,   111,   889,
     890,   568,   593,   896,   897,   569,  1713,  1327,   574,   898,
     899,   578,  1478,  1144,  1144,   123,  1503,  1648,  1649,   587,
     588,   589,   591,   592,   598,  1110,   590,   600,   618,   619,
     149,   637,   667,   943,  1110,  1483,   636,   668,   669,   679,
     687,   670,   655,  1286,   688,  1110,   689,   973,   695,   707,
     709,   977,   978,   149,   710,   690,   691,   745,   720,   724,
     734,   750,   756,  1287,   759,  1288,   767,  1701,  1702,   746,
     768,   769,   786,   997,   780,  1003,   638,   787,  1442,   442,
     795,   446,   463,   563,   639,   640,   563,   641,   468,   479,
    1017,   793,   797,  1289,   804,   642,   808,   111,   800,   643,
     815,   644,   801,  1346,   817,   818,   645,   802,   835,   828,
     836,   846,   856,   871,   123,   522,   888,   840,   872,   841,
     900,   913,   305,   646,   873,  1587,   874,   901,   902,   522,
     309,  1050,   903,   922,  1610,   919,   920,   944,  1744,   945,
    1266,   948,   949,   971,   970,   972,   647,   648,   649,   650,
     651,   652,   149,   522,   974,   979,   976,   980,   981,   989,
    1004,   875,   982,   983,  1010,   522,  1011,   522,  1083,   521,
    1014,  1021,  1022,   733,  1023,  1024,  1084,  1029,  1032,  1068,
    1033,   436,  1069,   305,   305,   305,  1059,   441,   445,   462,
    1629,   309,   309,   309,  1097,   924,   925,   926,   927,   928,
     929,   930,   931,   932,   933,  1070,   467,   478,  1076,  1110,
    1072,  1077,  1073,  1089,  1071,  1092,  1098,  1102,  1160,   939,
     991,  1179,  1201,  1141,  1141,  1141,  1141,  1204,  1196,  1202,
    1180,  1210,  1211,  1213,   752,  1217,  1224,  1237,  1240,  1238,
    1239,  1243,  1244,  1245,  1250,  1254,  1251,  1255,  1261,  1269,
    1276,  1273,  1267,  1268,  1274,  1280,  1296,  1314,  1318,   713,
    1141,  1323,  1343,  1319,  1345,  1321,  1369,  1320,    11,  1373,
    1370,  1400,  1405,  1350,  1174,  1381,  1393,  1382,  1384,  1385,
    1386,  1416,  1387,  1399,  1413,  1409,  1388,  1414,  1417,  1418,
    1426,  1419,  1428,  1435,   305,  1410,  1593,  1432,  1434,  1200,
    1436,  1440,   309,  1445,  1420,  1448,  1463,  1480,  1207,  1477,
    1207,  1487,   411,  1491,  1141,  1497,  1498,  1499,  1415,  1469,
    1471,  1472,  1488,  1494,  1486,  1489,  1485,  1141,  1475,   305,
    1336,  1492,  1490,  1510,  1517,  1496,  1533,   309,  1527,  1514,
     305,  1538,  1534,  1540,  1553,   412,  1546,  1547,   309,  1548,
    1559,  1549,  1564,  1550,  1493,  1551,  1552,  1566,   411,   305,
     784,  1572,   784,  1584,  1449,  1562,  1585,   309,  1570,  1577,
    1586,  1590,  1589,  1619,  1618,  1644,  1595,   411,  1598,   305,
    1605,  1606,  1611,  1470,  1630,  1642,   522,   309,  1645,   522,
    1653,   412,  1181,  1669,  1568,  1658,   827,  1481,  1666,  1671,
    1677,  1681,  1698,  1685,  1707,  1693,  1708,  1697,  1710,  1711,
     412,  1083,  1083,  1722,  1715,  1720,  1723,  1716,  1709,  1084,
    1084,  1724,  1741,  1672,  1752,  1344,  1665,  1738,  1753,  1740,
     733,  1761,  1643,  1755,  1676,  1593,  1760,  1678,  1764,  1767,
    1769,  1773,  1776,  1777,  1686,  1750,  1141,  1782,  1792,  1788,
    1779,   599,   946,  1791,  1398,  1162,  1789,   601,   602,   694,
    1771,   730,   844,   703,   522,  1780,  1236,   522,   605,  1412,
    1718,   522,  1748,  1088,   522,   522,  1783,  1785,  1794,  1421,
    1233,  1582,   522,  1019,  1439,  1506,  1334,  1512,   522,  1509,
    1450,   522,   794,  1454,  1460,  1468,   878,  1479,   879,   522,
     915,  1051,  1766,  1763,  1145,   522,   522,   522,   522,   673,
    1407,  1397,  1209,   522,  1495,   739,   740,  1501,  1528,  1500,
    1532,   522,  1641,  1348,  1678,  1531,  1640,  1372,  1186,  1406,
    1561,  1650,  1529,   749,     0,     0,  1424,  1442,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   305,     0,     0,
       0,  1438,     0,     0,     0,   309,     0,     0,     0,     0,
    1141,     0,  1757,     0,     0,     0,   522,     0,     0,     0,
       0,     0,     0,     0,   778,     0,     0,     0,     0,     0,
     522,     0,     0,     0,  1141,     0,     0,     0,     0,     0,
       0,   522,     0,     0,  1774,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1482,     0,     0,  1774,     0,     0,     0,
       0,  1757,     0,  1700,     0,     0,     0,   544,     0,   522,
       0,     0,     0,     0,     0,     0,     0,   839,     0,  1704,
       0,     0,     0,     0,     0,     0,   521,     0,     0,   521,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1083,     0,     0,     0,     0,     0,
       0,     0,  1084,     0,     0,  1083,  1083,     0,   305,     0,
       0,     0,     0,  1084,  1084,  1083,   309,     0,     0,     0,
       0,     0,     0,  1084,  1141,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1567,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   923,
       0,     0,   522,     0,     0,     0,     0,     0,  1580,  1581,
       0,     0,     0,     0,     0,     0,   522,     0,     0,     0,
     522,   522,     0,     0,     0,  1083,     0,     0,     0,     0,
       0,     0,     0,  1084,  1597,     0,  1141,     0,  1083,  1141,
       0,     0,   522,     0,   522,     0,  1084,     0,     0,     0,
       0,  1609,   522,     0,     0,   522,  1613,     0,     0,   522,
       0,     0,     0,   305,     0,     0,     0,     0,     0,     0,
       0,   309,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   305,     0,     0,     0,     0,
     522,     0,     0,   309,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1083,     0,     0,
       0,     0,  1083,     0,     0,  1084,     0,     0,     0,     0,
    1084,     0,     0,     0,     0,     0,     0,     0,   522,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   522,     0,     0,     0,     0,     0,     0,
       0,     0,  1680,     0,  1682,     0,  1684,     0,     0,     0,
       0,     0,     0,  1692,     0,     0,     0,     0,     0,     0,
       0,     0,   522,   522,   522,   522,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1141,     0,  1141,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   522,
       0,     0,     0,     0,     0,  1714,     0,     0,  1717,     0,
       0,     0,     0,   522,     0,     0,     0,     0,     0,     0,
    1141,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1725,     0,     0,     0,     0,     0,     0,     0,   522,     0,
       0,     0,     0,     0,     0,     0,     0,   522,     0,   522,
    1141,     0,     0,   522,     0,     0,     0,     0,  1751,     0,
       0,     0,     0,  1754,     0,  1141,   522,  1141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   544,
       0,     0,     0,     0,     0,  1772,     0,     0,     0,   522,
       0,   522,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1778,     0,   819,   820,  1781,     0,   829,   830,
     831,   832,     0,   834,     0,     0,     0,     0,     0,   842,
       0,     0,  1790,     0,     0,  1793,     0,   851,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   870,     0,     0,
       0,     0,     0,     0,   522,   876,   877,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   522,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   911,     0,     0,   911,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   975,     0,     0,     0,     0,
       0,     0,   522,     0,     0,   522,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     522,     0,     0,     0,     0,     0,     0,     0,     0,   522,
       0,     0,     0,     0,     0,     0,     0,  1018,     0,     0,
       0,     0,     0,   522,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   522,     0,     0,     0,     0,     0,     0,
       0,     0,  1043,     0,     0,     0,  1045,  1046,     0,     0,
       0,     0,     0,     0,     0,   876,     0,     0,     0,     0,
       0,     0,   522,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   522,     0,     0,     0,
       0,     0,     0,     0,     0,   522,     0,     0,   522,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1099,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   522,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   522,     0,     0,     0,     0,     0,     0,  1163,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   522,   522,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1199,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   522,     0,   522,     0,     0,   522,     0,
       0,     0,  1214,     0,     0,     0,     0,     0,     0,     0,
     522,     0,     0,     0,     0,   522,     0,     0,     0,     0,
       0,     0,     0,     0,  1247,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1252,  1253,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1272,     0,     0,  1275,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1297,     0,
    1300,  1301,  1302,     0,  1305,  1306,  1307,  1308,  1309,  1310,
    1311,  1312,     0,     0,  1315,  1316,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1328,     0,
       0,     0,     0,     0,     0,     0,     0,  1099,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   522,     0,   522,     0,   522,     0,     0,     0,     0,
       0,     0,   522,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1394,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   522,     0,   522,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   522,     0,     0,   522,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   522,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   522,
       0,     0,     0,     0,  1425,     0,  1427,     0,  1429,     0,
       0,  1433,     0,     0,     0,     0,  1437,     0,     0,   522,
       0,     0,     0,     0,     0,     0,     0,   522,  1443,     0,
       0,     0,   522,     0,   522,     0,   522,  1447,     0,     0,
       0,     0,     0,  1451,  1452,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1473,     0,   522,  1474,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   522,     0,     0,     0,   522,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   522,     0,     0,   522,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1099,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1571,     0,     0,     0,  1573,     0,     0,     0,  1576,
       0,  1578,     0,  1579,     0,     0,     0,     0,     0,  1583,
       0,     0,     0,     0,     0,     0,     0,  1588,     0,     0,
       0,     0,     0,     0,     0,  1592,  1594,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1443,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1614,  1615,  1616,  1617,
       0,     0,  1620,  1621,     0,  1622,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1667,     0,  1668,     0,     0,  1670,     0,     0,     0,
       0,     0,     0,     0,  1673,     0,     0,     0,     0,  1675,
    1594,     0,     0,     0,     0,     0,     0,  1679,     0,     0,
       0,  1683,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1695,  1696,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1719,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1679,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1758,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1768,     0,     0,     0,     0,     0,     0,     0,     0,  1770,
       0,     0,     0,     0,  1775,     1,     2,     0,     0,  1758,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,  1775,     0,    12,    13,  1784,
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
     241,   242,   243,     0,   244,     0,   245,   246,   247,     0,
     248,   249,   250,   251,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,     0,    11,     0,     0,     0,   406,   407,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,   408,    28,    29,    30,    31,     0,    32,    33,
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
       0,     0,   126,   127,   128,     0,   541,     0,   129,     0,
     130,   131,     0,   132,   133,   134,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,   149,     0,   409,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,   244,     0,   245,   246,   247,     0,   248,
     249,   250,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,     0,
      11,     0,     0,     0,   406,   407,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
     408,    28,    29,    30,    31,     0,    32,    33,    34,    35,
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
     126,   127,   128,     0,   796,     0,   129,     0,   130,   131,
       0,   132,   133,   134,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,   149,     0,   409,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
       0,   244,     0,   245,   246,   247,     0,   248,   249,   250,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,     0,    11,     0,
       0,     0,   406,   407,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,  1079,   408,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,  1080,  1081,    50,    51,    52,    53,    54,    55,    56,
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
     128,     0,   796,     0,   129,     0,   130,   131,     0,   132,
     133,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   409,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,  1082,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,     0,   244,
       0,   245,   246,   247,     0,   248,   249,   250,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,     0,    11,     0,     0,     0,
     406,   407,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,  1079,   408,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,  1080,
    1081,    50,    51,    52,    53,    54,    55,    56,    57,    58,
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
     541,     0,   129,     0,   130,   131,     0,   132,   133,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     409,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,  1082,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     0,   244,     0,   245,
     246,   247,     0,   248,   249,   250,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,     0,    11,     0,     0,     0,   406,   407,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,   408,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,    48,    49,    50,
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
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,   132,   133,   134,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,   149,     0,   409,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,     0,   244,     0,   245,   246,   247,
       0,   248,   249,   250,     1,     2,     0,     0,     0,     0,
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
       0,     0,   147,   148,   149,     0,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,   244,     0,   245,   246,   247,     0,   248,
     249,   250,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,     0,
      11,     0,     0,     0,    12,    13,     0,    14,    15,    16,
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
     147,   148,   149,     0,   409,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
       0,   244,     0,   245,   246,   247,     0,   248,   249,   250,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,     0,    11,     0,
       0,     0,    12,   407,     0,    14,    15,    16,    17,    18,
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
     149,     0,   409,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,     0,   244,
       0,   245,   246,   247,     0,   248,   249,   250,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,     0,    11,     0,     0,     0,
     863,   407,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,   408,    28,    29,    30,
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
     409,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     0,   244,     0,   245,
     246,   247,     0,   248,   249,   250,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,     0,    11,     0,     0,     0,   406,   407,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,  1079,   408,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,  1080,  1081,    50,
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
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,   132,   133,   134,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,   149,     0,   409,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,  1082,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,     0,   244,     0,   245,   246,   247,
       0,   248,   249,   250,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     0,
       0,     0,    11,     0,     0,     0,   406,   407,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   546,   408,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,   547,   548,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   497,    82,    83,    84,    85,    86,
     549,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   550,   109,     0,   110,   111,
     112,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   124,   125,
       0,     0,   126,   127,   128,     0,     0,   551,   129,     0,
     130,   131,     0,   132,   133,   134,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,   149,     0,   409,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   514,
     515,   516,   176,   177,   517,   552,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,   244,     0,   245,   246,   247,     0,   248,
     249,   250,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     0,     0,     0,
      11,     0,     0,     0,   406,   407,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   546,
     408,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,   547,   548,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,   497,    82,    83,    84,    85,    86,   549,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,    96,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   550,   109,     0,   110,   111,   112,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,     0,   123,     0,   124,   125,     0,     0,
     126,   127,   128,     0,     0,     0,   129,   556,   130,   131,
       0,   132,   133,   134,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,   149,     0,   409,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   514,   515,   516,
     176,   177,   517,   552,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
       0,   244,     0,   245,   246,   247,     0,   248,   249,   250,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     0,     0,     0,    11,     0,
       0,     0,   406,   407,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   546,   408,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,   547,   548,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     497,    82,    83,    84,    85,    86,   549,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   550,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   409,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   514,   515,   516,   176,   177,
     517,   552,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   594,   244,
       0,   245,   246,   247,     0,   248,   249,   250,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     0,     0,     0,    11,     0,     0,     0,
     406,   407,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   546,   408,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,   547,
     548,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,   497,    82,
      83,    84,    85,    86,   549,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   550,
     109,     0,   110,   111,   112,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,     0,
     123,     0,   124,   125,     0,     0,   126,   127,   128,     0,
       0,     0,   129,     0,   130,   131,     0,   132,   133,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     409,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   514,   515,   516,   176,   177,   517,   552,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     0,   244,   596,   245,
     246,   247,     0,   248,   249,   250,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     0,     0,    11,     0,     0,     0,   406,   407,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   546,   408,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,   547,   548,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   497,    82,    83,    84,
      85,    86,   549,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   550,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,   904,     0,
     129,     0,   130,   131,     0,   132,   133,   134,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,   149,     0,   409,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   514,   515,   516,   176,   177,   517,   552,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,     0,   244,     0,   245,   246,   247,
       0,   248,   249,   250,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     0,
       0,     0,    11,     0,     0,     0,   406,   407,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   546,   408,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,   547,   548,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   497,    82,    83,    84,    85,    86,
     549,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   550,   109,     0,   110,   111,
     112,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   124,   125,
       0,     0,   126,   127,   128,     0,     0,     0,   129,   910,
     130,   131,     0,   132,   133,   134,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,   149,     0,   409,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   514,
     515,   516,   176,   177,   517,   552,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,   244,     0,   245,   246,   247,     0,   248,
     249,   250,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     0,     0,     0,
      11,     0,     0,     0,   406,   407,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   546,
     408,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,   547,   548,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,   497,    82,    83,    84,    85,    86,   549,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,    96,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   550,   109,     0,   110,   111,   112,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,     0,   123,     0,   124,   125,     0,     0,
     126,   127,   128,     0,     0,     0,   129,   914,   130,   131,
       0,   132,   133,   134,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,   149,     0,   409,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   514,   515,   516,
     176,   177,   517,   552,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
       0,   244,     0,   245,   246,   247,     0,   248,   249,   250,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     0,     0,     0,    11,     0,
       0,     0,   406,   407,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,   483,    25,   485,   408,    28,
     486,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,   488,     0,    45,    46,
      47,   490,   491,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     497,    82,    83,    84,    85,    86,   549,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   500,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   550,   109,     0,   110,   111,   671,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   672,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   409,   151,   152,   153,   154,   155,   156,   157,
     158,   509,   160,   510,   162,   511,   512,   165,   166,   167,
     168,   169,   170,   513,   172,   514,   515,   516,   176,   177,
     517,   518,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,     0,   244,
       0,   245,   519,   247,     0,   248,   249,   250,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     0,     0,     0,    11,     0,     0,     0,
     406,   407,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   546,   408,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,   547,
     548,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,   497,    82,
      83,    84,    85,    86,   549,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   550,
     109,     0,   110,   111,   112,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,     0,
     123,     0,   124,   125,     0,     0,   126,   127,   128,     0,
       0,     0,   129,     0,   130,   131,     0,   132,   133,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     409,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   514,   515,   516,   176,   177,   517,   552,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     0,   244,     0,   245,
     246,   247,     0,   248,   249,   250,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     0,     0,    11,     0,     0,     0,   406,   407,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   483,    25,   485,   408,    28,   486,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,   488,     0,    45,    46,    47,   490,   491,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   497,    82,    83,    84,
      85,    86,   549,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   500,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   550,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,   132,   133,   134,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,   149,     0,   409,   151,
     152,   153,   154,   155,   156,   157,   158,   509,   160,   510,
     162,   511,   512,   165,   166,   167,   168,   169,   170,   513,
     172,   514,   515,   516,   176,   177,   517,   518,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,     0,   244,     0,   245,   519,   247,
       0,   248,   249,   250,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     0,
       0,     0,    11,     0,     0,     0,   406,   407,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   483,
      25,   485,   408,    28,   486,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
     488,     0,    45,    46,    47,   490,   491,    50,   492,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   497,    82,    83,    84,    85,    86,
     549,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   500,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   550,   109,     0,   110,   111,
       0,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,     0,     0,
       0,     0,   126,   127,   128,     0,     0,     0,   129,     0,
     130,   131,     0,   132,   133,   134,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,   149,     0,   409,   151,   152,   153,
     154,   155,   156,   157,   158,   509,   160,   510,   162,   511,
     512,   165,   166,   167,   168,   169,   170,   513,   172,   514,
     515,   516,   176,   177,   517,   518,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,   244,     0,   245,   519,   247,     0,   248,
     249,   250,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     0,     0,     0,
      11,     0,     0,     0,   406,   407,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   483,    25,   485,
     408,    28,   486,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,   488,     0,
      45,    46,    47,   490,   491,    50,   492,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,   497,    82,    83,    84,    85,    86,   549,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   500,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   550,   109,     0,   110,   111,     0,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,     0,   123,     0,     0,     0,     0,     0,
     126,   127,   128,     0,     0,     0,   129,     0,   130,   131,
       0,     0,     0,   134,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,   149,     0,   409,   151,   152,   153,   154,   155,
     156,   157,   158,   509,   160,   510,   162,   511,   512,   165,
     166,   167,   168,   169,   170,   513,   172,   514,   515,   516,
     176,   177,   517,   518,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
       0,   244,     0,   245,   519,   247,     0,   248,   249,   250,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     0,     0,     0,    11,     0,
       0,     0,   406,   407,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,   483,    25,   485,   408,    28,
     486,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,   488,     0,    45,    46,
      47,   490,   491,    50,   492,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     497,    82,    83,    84,    85,    86,   549,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   500,     0,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,     0,   106,
     107,   550,   109,     0,   110,   111,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,     0,     0,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,     0,
       0,   134,     0,   135,     0,   136,     0,   138,     0,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   409,   151,   152,   153,   154,   155,   156,   157,
     158,   509,   160,   510,   162,   511,   512,   165,   166,   167,
     168,   169,   170,   513,   172,   514,   515,   516,   176,   177,
     517,   518,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,     0,   244,
       0,   245,   519,   247,     0,   248,   249,   250,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
     406,   407,     0,    14,    15,    16,   480,    18,    19,    20,
     481,    22,   482,   483,   484,   485,   408,    28,   486,    30,
      31,     0,    32,    33,    34,    35,   487,    37,    38,    39,
      40,    41,    42,    43,   488,     0,    45,   489,    47,   490,
     491,    50,   492,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   493,   494,    68,
       0,    69,    70,    71,   495,     0,    74,    75,    76,     0,
       0,   496,    78,     0,     0,     0,     0,    80,   497,    82,
     498,   499,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   500,    97,    98,   501,   502,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   503,   120,   121,   504,     0,
       0,     0,     0,     0,     0,     0,   505,   506,   128,     0,
       0,     0,   129,     0,   130,   507,     0,     0,     0,   134,
       0,   135,     0,   136,   137,   138,   139,   508,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,     0,     0,
     409,   151,   152,   153,   154,   155,   156,   157,   158,   509,
     160,   510,   162,   511,   512,   165,   166,   167,   168,   169,
     170,   513,   172,   514,   515,   516,   176,   177,   517,   518,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,     0,     1,     2,   245,
     519,   247,     0,   248,   249,   250,     3,     0,     0,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,   406,
     407,     0,    14,    15,    16,   528,    18,    19,    20,   481,
     529,   530,   483,   484,   485,   408,    28,   486,    30,    31,
       0,    32,    33,    34,    35,   531,    37,   532,   533,    40,
      41,    42,    43,   488,     0,    45,   534,    47,   490,   491,
      50,   492,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   493,   494,    68,     0,
      69,    70,    71,   535,     0,    74,    75,    76,     0,     0,
     496,    78,     0,     0,     0,     0,    80,   497,    82,   498,
     499,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     500,    97,    98,   501,   502,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,   107,     0,     0,
       0,     0,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   503,   120,   121,   504,     0,     0,
       0,     0,     0,     0,     0,   505,   506,   128,     0,     0,
       0,   129,     0,   130,   507,     0,     0,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   508,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,     0,     0,   409,
     151,   152,   153,   154,   155,   156,   157,   158,   509,   536,
     510,   162,   511,   512,   165,   166,   167,   168,   169,   170,
     513,   172,   514,   515,   516,   176,   177,   517,   518,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     0,     0,     0,   561,   245,   519,
     247,     0,   248,   249,   250,     7,     8,     0,     0,     0,
     771,     0,     0,     0,   406,   407,     0,    14,    15,    16,
     528,    18,    19,    20,   481,   529,   530,   483,   484,   485,
     408,    28,   486,    30,    31,     0,    32,    33,    34,    35,
     531,    37,   532,   533,    40,    41,    42,    43,   488,     0,
      45,   534,    47,   490,   491,    50,   492,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   493,   494,    68,     0,    69,    70,    71,   535,     0,
      74,    75,    76,     0,     0,   496,    78,     0,     0,     0,
       0,    80,   497,    82,   498,   499,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   500,    97,    98,   501,   502,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,   107,     0,     0,     0,     0,     0,     0,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   503,
     120,   121,   504,     0,     0,     0,     0,     0,     0,     0,
     505,   506,   128,     0,     0,     0,   129,   772,   130,   507,
       0,     0,     0,     0,     0,   135,     0,   136,   137,   138,
     139,   508,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,     0,     0,   409,   151,   152,   153,   154,   155,
     156,   157,   158,   509,   536,   510,   162,   511,   512,   165,
     166,   167,   168,   169,   170,   513,   172,   514,   515,   516,
     176,   177,   517,   518,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     0,   561,   245,   519,   247,     0,   248,   249,   250,
       7,     8,     0,     0,     0,     0,     0,     0,     0,   406,
     407,     0,    14,    15,    16,   528,    18,    19,    20,   481,
     529,   530,   483,   484,   485,   408,    28,   486,    30,    31,
       0,    32,    33,    34,    35,   531,    37,   532,   533,    40,
      41,    42,    43,   488,     0,    45,   534,    47,   490,   491,
      50,   492,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   493,   494,    68,     0,
      69,    70,    71,   535,     0,    74,    75,    76,     0,     0,
     496,    78,     0,     0,     0,     0,    80,   497,    82,   498,
     499,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     500,    97,    98,   501,   502,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,   107,     0,     0,
       0,     0,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   503,   120,   121,   504,     0,     0,
       0,     0,     0,     0,     0,   505,   506,   128,     0,     0,
       0,   129,     0,   130,   507,     0,     0,     0,     0,     0,
     135,     0,   136,   137,   138,   139,   508,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,     0,     0,   409,
     151,   152,   153,   154,   155,   156,   157,   158,   509,   536,
     510,   162,   511,   512,   165,   166,   167,   168,   169,   170,
     513,   172,   514,   515,   516,   176,   177,   517,   518,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     0,     0,     0,     0,   245,   519,
     247,     0,   248,   249,   250,   564,   565,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
     406,   407,     0,    14,    15,    16,   528,    18,    19,    20,
     481,   529,   530,   483,   484,   485,   408,    28,   486,    30,
      31,     0,    32,    33,    34,    35,   531,    37,   532,   533,
      40,    41,    42,    43,   488,     0,    45,   534,    47,   490,
     491,    50,   492,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   493,   494,    68,
       0,    69,    70,    71,   535,     0,    74,    75,    76,     0,
       0,   496,    78,     0,     0,     0,     0,    80,   497,    82,
     498,   499,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   500,    97,    98,   501,   502,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   503,   120,   121,   504,     0,
       0,     0,     0,     0,     0,     0,   505,   506,   128,     0,
       0,     0,   129,     0,   130,   507,     0,     0,     0,     0,
       0,   135,     0,   136,   137,   138,   139,   508,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,     0,     0,
     409,   151,   152,   153,   154,   155,   156,   157,   158,   509,
     536,   510,   162,   511,   512,   165,   166,   167,   168,   169,
     170,   513,   172,   514,   515,   516,   176,   177,   517,   518,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,     0,     0,     0,   245,
     519,   247,     0,   248,   249,   250,     4,     5,     6,     7,
       8,     0,     0,     0,    11,     0,     0,     0,   406,   407,
       0,    14,    15,    16,   821,    18,    19,    20,    21,   529,
     822,   483,    25,   485,   408,    28,   486,    30,    31,     0,
      32,    33,    34,    35,   823,    37,   532,   533,    40,    41,
      42,    43,   488,     0,    45,   824,    47,   490,   491,    50,
     492,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   493,   494,    68,     0,    69,
      70,    71,   825,     0,    74,    75,    76,     0,     0,   496,
      78,     0,     0,     0,    79,    80,   497,    82,   498,   499,
      85,    86,   549,    88,     0,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   500,
      97,    98,   501,   502,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   550,   109,     0,
     110,   111,     0,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   504,     0,   123,     0,
       0,     0,     0,     0,   505,   506,   128,     0,     0,     0,
     129,     0,   130,   507,     0,     0,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,   149,     0,   409,   151,
     152,   153,   154,   155,   156,   157,   158,   509,   536,   510,
     162,   511,   512,   165,   166,   167,   168,   169,   170,   513,
     172,   514,   515,   516,   176,   177,   517,   518,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,     0,   244,     0,   245,   519,   247,
       0,   248,   249,   250,     7,     8,     0,     0,     0,     0,
       0,     0,     0,   406,   407,     0,    14,    15,    16,   480,
      18,    19,    20,   481,    22,   482,   483,  1121,   485,   408,
      28,   486,    30,    31,     0,    32,    33,    34,    35,   487,
      37,    38,    39,    40,    41,    42,    43,   488,     0,    45,
     489,    47,   490,   491,    50,   492,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     493,   494,    68,     0,    69,    70,    71,   495,     0,    74,
      75,    76,     0,     0,   496,    78,     0,     0,     0,     0,
      80,   497,    82,   498,   499,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   500,    97,    98,   501,   502,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,  1122,     0,     0,     0,  1123,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   503,   120,
     121,   504,     0,     0,     0,     0,     0,     0,     0,   505,
     506,   128,     0,     0,     0,   129,  1542,   130,   507,     0,
       0,     0,  1543,     0,   135,     0,   136,   137,   138,   139,
     508,   141,   142,   143,   144,   145,   146,     0,     0,  1124,
     148,     0,     0,   409,   151,   152,   153,   154,   155,   156,
     157,   158,   509,   160,   510,   162,   511,   512,   165,   166,
     167,   168,   169,   170,   513,   172,   514,   515,   516,   176,
     177,   517,   518,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     0,     0,
       7,     8,   245,   519,   247,  1125,  1126,  1127,  1128,   406,
     407,     0,    14,    15,    16,   480,    18,    19,    20,   481,
      22,   482,   483,  1121,   485,   408,    28,   486,    30,    31,
       0,    32,    33,    34,    35,   487,    37,    38,    39,    40,
      41,    42,    43,   488,     0,    45,   489,    47,   490,   491,
      50,   492,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   493,   494,    68,     0,
      69,    70,    71,   495,     0,    74,    75,    76,     0,     0,
     496,    78,     0,     0,     0,     0,    80,   497,    82,   498,
     499,    85,    86,  1461,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     500,    97,    98,   501,   502,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,  1122,     0,     0,
       0,  1123,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   503,   120,   121,   504,     0,     0,
       0,     0,     0,     0,     0,   505,   506,   128,     0,     0,
       0,   129,     0,   130,   507,     0,     0,     0,     0,     0,
     135,     0,   136,   137,   138,   139,   508,   141,   142,   143,
     144,   145,   146,     0,     0,  1124,   148,     0,     0,   409,
     151,   152,   153,   154,   155,   156,   157,   158,   509,   160,
     510,   162,   511,   512,   165,   166,   167,   168,   169,   170,
     513,   172,   514,   515,   516,   176,   177,   517,   518,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     0,     0,     7,     8,   245,   519,
     247,  1125,  1126,  1127,  1128,   406,   407,     0,    14,    15,
      16,   480,    18,    19,    20,   481,    22,   482,   483,  1121,
     485,   408,    28,   486,    30,    31,     0,    32,    33,    34,
      35,   487,    37,    38,    39,    40,    41,    42,    43,   488,
       0,    45,   489,    47,   490,   491,    50,   492,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   493,   494,    68,     0,    69,    70,    71,   495,
       0,    74,    75,    76,     0,     0,   496,    78,     0,     0,
       0,     0,    80,   497,    82,   498,   499,    85,    86,  1599,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   500,    97,    98,   501,
     502,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,  1122,     0,     0,     0,  1123,     0,     0,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     503,   120,   121,   504,     0,     0,     0,     0,     0,     0,
       0,   505,   506,   128,     0,     0,     0,   129,     0,   130,
     507,     0,     0,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   508,   141,   142,   143,   144,   145,   146,     0,
       0,  1124,   148,     0,     0,   409,   151,   152,   153,   154,
     155,   156,   157,   158,   509,   160,   510,   162,   511,   512,
     165,   166,   167,   168,   169,   170,   513,   172,   514,   515,
     516,   176,   177,   517,   518,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       0,     0,     7,     8,   245,   519,   247,  1125,  1126,  1127,
    1128,   406,   407,     0,    14,    15,    16,   480,    18,    19,
      20,   481,    22,   482,   483,  1121,   485,   408,    28,   486,
      30,    31,     0,    32,    33,    34,    35,   487,    37,    38,
      39,    40,    41,    42,    43,   488,     0,    45,   489,    47,
     490,   491,    50,   492,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,   493,   494,
      68,     0,    69,    70,    71,   495,     0,    74,    75,    76,
       0,     0,   496,    78,     0,     0,     0,     0,    80,   497,
      82,   498,   499,    85,    86,  1603,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   500,    97,    98,   501,   502,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,  1122,
       0,     0,     0,  1123,     0,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   503,   120,   121,   504,
       0,     0,     0,     0,     0,     0,     0,   505,   506,   128,
       0,     0,     0,   129,     0,   130,   507,     0,     0,     0,
       0,     0,   135,     0,   136,   137,   138,   139,   508,   141,
     142,   143,   144,   145,   146,     0,     0,  1124,   148,     0,
       0,   409,   151,   152,   153,   154,   155,   156,   157,   158,
     509,   160,   510,   162,   511,   512,   165,   166,   167,   168,
     169,   170,   513,   172,   514,   515,   516,   176,   177,   517,
     518,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     0,     0,     7,     8,
     245,   519,   247,  1125,  1126,  1127,  1128,   406,   407,     0,
      14,    15,    16,   528,    18,    19,    20,   481,   529,   530,
     483,   484,   485,   408,    28,   486,    30,    31,     0,    32,
      33,    34,    35,   531,    37,   532,   533,    40,    41,    42,
      43,   488,     0,    45,   534,    47,   490,   491,    50,   492,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   493,   494,    68,     0,    69,    70,
      71,   535,     0,    74,    75,    76,     0,     0,   496,    78,
       0,     0,     0,     0,    80,   497,    82,   498,   499,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   500,    97,
      98,   501,   502,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,   107,     0,     0,     0,     0,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   503,   120,   121,   504,     0,     0,     0,     0,
       0,     0,     0,   505,   506,   128,     0,     0,     0,   129,
     742,   130,   507,     0,     0,     0,   743,     0,   135,     0,
     136,   137,   138,   139,   508,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,     0,     0,   409,   151,   152,
     153,   154,   155,   156,   157,   158,   509,   536,   510,   162,
     511,   512,   165,   166,   167,   168,   169,   170,   513,   172,
     514,   515,   516,   176,   177,   517,   518,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     0,     0,     7,     8,   245,   519,   247,     0,
     248,   249,   250,   406,   407,     0,    14,    15,    16,   528,
      18,    19,    20,   481,   529,   530,   483,   484,   485,   408,
      28,   486,    30,    31,     0,    32,    33,    34,    35,   531,
      37,   532,   533,    40,    41,    42,    43,   488,     0,    45,
     534,    47,   490,   491,    50,   492,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     493,   494,    68,     0,    69,    70,    71,   535,     0,    74,
      75,    76,     0,     0,   496,    78,     0,     0,     0,     0,
      80,   497,    82,   498,   499,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   500,    97,    98,   501,   502,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,   107,     0,     0,     0,     0,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   503,   120,
     121,   504,     0,     0,     0,     0,     0,     0,     0,   505,
     506,   128,     0,     0,     0,   129,   789,   130,   507,     0,
       0,     0,   790,     0,   135,     0,   136,   137,   138,   139,
     508,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,     0,     0,   409,   151,   152,   153,   154,   155,   156,
     157,   158,   509,   536,   510,   162,   511,   512,   165,   166,
     167,   168,   169,   170,   513,   172,   514,   515,   516,   176,
     177,   517,   518,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     0,     0,
       7,     8,   245,   519,   247,     0,   248,   249,   250,   406,
     407,     0,    14,    15,    16,   480,    18,    19,    20,   481,
      22,   482,   483,  1121,   485,   408,    28,   486,    30,    31,
       0,    32,    33,    34,    35,   487,    37,    38,    39,    40,
      41,    42,    43,   488,     0,    45,   489,    47,   490,   491,
      50,   492,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   493,   494,    68,     0,
      69,    70,    71,   495,     0,    74,    75,    76,     0,     0,
     496,    78,     0,     0,     0,     0,    80,   497,    82,   498,
     499,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     500,    97,    98,   501,   502,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,  1122,     0,     0,
       0,  1123,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   503,   120,   121,   504,     0,     0,
       0,     0,     0,     0,     0,   505,   506,   128,     0,     0,
       0,   129,     0,   130,   507,     0,     0,     0,     0,     0,
     135,     0,   136,   137,   138,   139,   508,   141,   142,   143,
     144,   145,   146,     0,     0,  1124,   148,     0,     0,   409,
     151,   152,   153,   154,   155,   156,   157,   158,   509,   160,
     510,   162,   511,   512,   165,   166,   167,   168,   169,   170,
     513,   172,   514,   515,   516,   176,   177,   517,   518,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     0,     0,     7,     8,   245,   519,
     247,  1125,  1126,  1127,  1128,   406,   407,     0,    14,    15,
      16,   480,    18,    19,    20,   481,    22,   482,   483,  1121,
     485,   408,    28,   486,    30,    31,     0,    32,    33,    34,
      35,   487,    37,    38,    39,    40,    41,    42,    43,   488,
       0,    45,   489,    47,   490,   491,    50,   492,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   493,   494,    68,     0,    69,    70,    71,   495,
       0,    74,    75,    76,     0,     0,   496,    78,     0,     0,
       0,     0,    80,   497,    82,   498,   499,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   500,    97,    98,   501,
     502,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,  1122,     0,     0,     0,  1123,     0,     0,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     503,   120,   121,   504,     0,     0,     0,     0,     0,     0,
       0,   505,   506,   128,     0,     0,     0,   129,     0,   130,
     507,     0,     0,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   508,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,     0,     0,   409,   151,   152,   153,   154,
     155,   156,   157,   158,   509,   160,   510,   162,   511,   512,
     165,   166,   167,   168,   169,   170,   513,   172,   514,   515,
     516,   176,   177,   517,   518,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       0,     0,     7,     8,   245,   519,   247,  1125,  1126,  1127,
    1128,   406,   407,     0,    14,    15,    16,   528,    18,    19,
      20,   481,   529,   530,   483,   484,   485,   408,    28,   486,
      30,    31,     0,    32,    33,    34,    35,   531,    37,   532,
     533,    40,    41,    42,    43,   488,     0,    45,   534,    47,
     490,   491,    50,   492,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,   493,   494,
      68,     0,    69,    70,    71,   535,     0,    74,    75,    76,
       0,     0,   496,    78,     0,     0,     0,     0,    80,   497,
      82,   498,   499,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   500,    97,    98,   501,   502,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,   107,
       0,     0,     0,     0,     0,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   503,   120,   121,   504,
       0,     0,     0,     0,     0,     0,     0,   505,   506,   128,
       0,     0,     0,   129,     0,   130,   507,     0,     0,     0,
       0,     0,   135,     0,   136,   137,   138,   139,   508,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,     0,
       0,   409,   151,   152,   153,   154,   155,   156,   157,   158,
     509,   536,   510,   162,   511,   512,   165,   166,   167,   168,
     169,   170,   513,   172,   514,   515,   516,   176,   177,   517,
     518,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     0,     0,     7,     8,
     245,   519,   247,     0,   248,   249,   250,   406,   407,     0,
      14,    15,    16,     0,    18,    19,    20,   481,     0,     0,
     483,   484,     0,   408,    28,   486,    30,    31,     0,    32,
      33,    34,    35,     0,    37,     0,     0,    40,    41,    42,
      43,   488,     0,    45,     0,    47,     0,     0,    50,   492,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   493,   494,    68,     0,    69,    70,
      71,     0,     0,    74,    75,    76,     0,     0,   496,    78,
       0,     0,     0,     0,    80,   497,    82,   498,   499,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   500,    97,
      98,   501,   502,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,     0,     0,     0,     0,     0,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   503,   120,   121,   504,     0,     0,     0,     0,
       0,     0,     0,   505,   506,   128,     0,     0,     0,   129,
       0,   130,   507,     0,     0,     0,     0,     0,   135,     0,
     136,   137,   138,   139,   508,   141,   142,   143,   144,   145,
     146,     0,     0,     0,   148,     0,     0,   409,   151,   152,
     153,   154,   155,   156,   157,   158,   509,     0,   510,   162,
     511,   512,   165,   166,   167,   168,   169,   170,   513,   172,
     514,   515,   516,   176,   177,     0,   518,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     0,     0,     0,     0,   245,   519,   247,     0,
     248,   249,   250
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   415,   416,   658,     4,     5,     6,   417,     0,   179,
     336,    12,     4,     5,     6,   809,   109,   110,   309,   257,
     846,   766,     4,     5,     6,   610,   611,   749,     4,     5,
       6,  1030,  1014,   778,   659,   660,   661,   662,   289,   258,
     749,  1279,   577,   133,  1054,   455,   456,   792,   583,  1196,
     429,  1262,  1340,  1341,   273,     4,     5,     6,    73,  1107,
     703,   440,   921,   106,   106,   900,   901,    26,    27,   608,
     609,   888,     8,   117,    36,    36,   608,   609,   610,   611,
     901,    55,  1373,     1,   463,    96,   280,    29,    47,     1,
     937,     1,    26,    27,   638,     1,   640,   641,     1,   643,
    1564,   645,   937,    37,    38,     1,    40,    41,   108,   653,
     654,   223,     1,    47,    30,    74,   108,    37,    38,   117,
      40,    41,    56,    57,  1292,    29,   108,   117,   146,    99,
      99,   106,    94,   106,    96,    96,   971,    57,   152,   106,
      74,   129,    26,    27,   223,    79,   225,   152,   106,    99,
     243,   244,   111,    52,    45,   106,   991,    94,   223,   108,
     225,   412,   176,    47,    29,   106,    33,   109,   106,  1004,
     991,    62,    56,   141,   129,   152,   110,   111,   112,   223,
     146,   123,    49,  1004,   146,   146,    66,   215,   186,   152,
      74,    71,   112,    42,    94,    79,   289,    46,   943,    39,
     312,    94,    51,   208,    44,    45,   148,   195,   112,   146,
     152,   184,   155,   155,   189,   185,   185,   184,  1506,    59,
      69,    61,    62,    93,   252,   159,   110,   111,   112,   128,
      70,   208,   183,   312,   176,   185,    96,   117,   174,   159,
     195,   215,   436,   254,   255,   186,  1710,   312,   186,   339,
      96,   251,   997,   271,   254,   159,  1050,    97,  1003,   251,
    1259,   305,   254,  1245,   555,  1476,  1413,   309,   311,   854,
     855,   189,  1563,  1283,   996,   233,  1123,   189,   252,   189,
     923,   271,  1292,   189,   218,   994,   189,   996,  1123,   289,
    1107,  1108,   543,   189,   159,   186,   212,   289,   218,  1158,
     189,  1349,    76,   271,   714,   271,    73,  1016,   168,   271,
     271,  1479,   182,   852,   853,   257,   216,   217,   167,   412,
      87,   170,   168,   216,   217,   259,   285,   157,   106,   344,
     117,   231,   347,   106,   293,   130,   185,   106,   231,   259,
     884,   106,   223,   106,   111,   175,     5,   228,   106,   155,
       9,   285,   445,   106,   764,   106,   123,   106,   125,   293,
     453,   210,    26,    27,   157,   106,  1201,   301,   106,   462,
     608,   609,   267,  1661,   159,   626,   469,   470,   152,   274,
      96,   760,   175,   223,   763,   478,   605,  1625,    42,   284,
     250,   251,    46,   253,   189,     5,   106,    51,   185,     9,
     260,   285,  1237,   106,   250,   251,   106,   253,   186,   293,
     270,    29,   412,   117,   187,    69,  1237,   301,   187,  1566,
     412,   186,   282,   186,   270,  1713,  1261,   106,   186,    42,
     183,   312,    94,    46,   183,   186,   282,   267,    51,   155,
    1261,   441,   183,   443,   274,   219,   220,   111,   186,   441,
     543,   443,     9,   106,   284,  1200,    69,   106,   155,   441,
      45,   443,    47,   122,   106,   124,   559,   467,   106,  1479,
     106,    28,   472,   132,   888,   467,   186,   155,   571,   106,
     472,   185,   733,   186,   146,   467,   186,   199,  1699,  1211,
     472,   109,   441,   152,   443,    96,   208,  1323,   591,   592,
    1326,   106,   916,   106,    29,   123,   117,   186,  1093,  1094,
    1095,  1220,   122,   167,   124,    45,   170,    47,   467,  1666,
     105,   135,   132,   472,    96,   106,    54,   106,    56,   106,
     148,   185,  1349,   186,   944,   945,   106,   186,  1073,   949,
     106,  1358,   152,   543,   186,   146,  1381,   183,   186,    79,
     550,   543,  1369,   106,   167,   106,   210,   170,   550,   186,
    1381,  1093,  1094,  1095,  1711,   122,   152,   124,   550,   979,
     116,    99,   185,   106,   146,   105,   133,   344,   183,   106,
     347,   674,   167,   186,   109,   199,   679,   677,   678,   266,
     176,   155,   592,   844,   105,   152,   273,   210,   123,   145,
     592,   550,   603,   143,  1586,   186,   183,   186,   608,   609,
     610,   611,   158,   183,   852,   126,   608,   609,   610,   611,
     186,    94,     9,   148,    94,  1624,   626,   152,  1463,   168,
     155,  1466,   183,   186,   626,   175,  1783,   167,  1785,   858,
     733,    28,  1463,   592,    96,  1466,   192,  1794,  1688,  1689,
     183,   176,   192,    94,    96,   422,   183,   155,   425,    53,
     112,   200,   429,   136,    58,   432,   433,    53,   141,   165,
     112,   141,    58,   440,   157,     9,    10,   612,   985,   446,
     987,   616,   449,  1477,   147,   181,   121,   155,  1482,  1729,
     457,    77,   175,  1107,  1108,  1735,   463,   464,   465,   466,
     141,   164,    96,   155,   471,  1360,  1428,   800,   801,   802,
      96,   804,   479,   155,   197,   135,  1533,   152,    24,   136,
     155,   249,   155,   147,   141,   121,    33,   157,    34,   149,
    1037,   117,  1039,   733,   262,   122,   264,   124,     9,    10,
     164,   733,    49,   136,  1329,   175,   133,   275,   276,   277,
      95,   279,   121,   281,    60,   261,   756,   524,   121,   152,
     105,     9,    10,   136,   756,   152,   272,   197,   102,    96,
     115,   538,   152,   155,   756,   155,   245,   246,   181,   152,
     756,   126,   549,  1109,   181,   112,   786,   787,   122,    99,
     124,   194,    94,  1084,   786,   787,   153,   194,   155,   268,
      99,    99,   112,   105,   786,   787,   261,   756,    99,  1644,
     577,  1646,   934,   112,   112,  1609,   583,   272,   152,  1613,
     587,   112,   156,  1644,   946,  1646,   297,  1078,   117,    53,
    1240,   102,    99,    99,    58,   306,   136,   786,   787,   173,
     121,   141,  1677,   346,   844,   112,   112,   152,   351,   121,
     155,   122,   844,   124,   102,   152,  1677,   117,   155,   193,
       9,    10,   863,   127,   128,   275,   276,   277,   121,  1524,
    1525,   281,  1707,   152,   122,   152,   124,   211,   155,   190,
     191,   152,   219,   220,   221,   156,  1707,  1722,   680,  1724,
     121,   683,  1517,   152,   686,   230,   121,   232,  1692,   127,
     128,  1722,   173,  1724,   152,   230,   121,   232,   156,   656,
     657,   121,  1082,   663,   664,   121,  1661,  1087,   214,   665,
     666,   155,   193,   902,   903,   173,  1336,  1554,  1555,   117,
     239,   239,   155,   152,   312,  1349,   240,     0,   106,   189,
     211,    92,    50,   710,  1358,   193,   166,   198,   100,   153,
     144,   101,   247,   102,   155,  1369,   183,   724,    29,    47,
     151,   728,   729,   211,   117,   183,   183,   282,   244,   302,
     186,   117,   152,   122,     1,   124,   117,  1632,  1633,   282,
     141,   106,   152,   750,   186,   752,   131,   152,  1239,   155,
     183,   155,   155,   760,   139,   140,   763,   142,   155,   155,
     767,   141,   120,   152,   152,   150,    35,   156,   155,   154,
      17,   156,   155,  1106,   212,    29,   161,   155,   229,   186,
     228,   243,     3,   117,   173,    73,    70,   189,   167,   189,
     229,   148,  1032,   178,   169,  1445,   169,    94,    94,    87,
    1032,   808,    94,    29,   193,   106,   106,   159,  1703,   159,
    1032,   126,   131,    94,   244,   297,   201,   202,   203,   204,
     205,   206,   211,   111,   141,   131,   117,   183,   183,   106,
      94,  1322,   186,   186,    96,   123,    45,   125,  1078,   846,
      96,   186,   186,  1032,   186,   186,  1078,   183,   152,   231,
     183,  1092,    94,  1093,  1094,  1095,   155,   152,   152,   152,
    1510,  1093,  1094,  1095,   871,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,   155,   152,   152,   141,  1533,
     223,   189,   229,   197,   235,    33,   169,   117,   131,   141,
      94,    29,    94,   900,   901,   902,   903,   152,   225,   297,
     284,   117,   126,   117,   117,   146,   252,    94,   131,   183,
     196,   159,   131,    96,   152,   146,   117,    99,    99,   152,
     120,   141,   183,   183,   189,    35,    29,   117,   155,    79,
     937,   243,   106,   155,   106,   152,   256,   155,    29,   265,
     258,    29,    29,   283,   951,   155,   143,   155,   155,   155,
     155,   186,   155,   284,   225,   285,   155,   189,   186,   143,
     146,   186,   126,   117,  1204,   304,  1457,   146,   146,   976,
     117,    77,  1204,   106,   186,   141,    99,     7,   985,   131,
     987,   231,  1204,    96,   991,  1318,  1319,  1320,  1204,   183,
     186,   186,   231,   155,   186,   231,   189,  1004,   196,  1239,
     105,   186,   231,   105,   248,   185,   146,  1239,   248,   186,
    1250,   284,   280,    78,    29,  1204,   186,   186,  1250,   186,
      29,   186,   106,   186,   235,   186,   186,   169,  1250,  1269,
    1037,   146,  1039,   125,  1250,   269,   125,  1269,   183,   146,
      96,   185,   183,    94,   314,    94,   185,  1269,   185,  1289,
     185,   183,   183,  1269,   183,   152,   344,  1289,   186,   347,
      29,  1250,    96,   146,   255,   186,  1073,  1289,   169,    53,
      94,   185,   196,   185,    94,   195,    29,   186,   106,   106,
    1269,  1321,  1322,    94,   117,   117,   185,   223,   263,  1321,
    1322,    94,   235,  1584,   117,  1102,   285,   195,   223,   195,
    1289,    93,   278,   185,  1595,  1596,   185,  1598,   182,   195,
     117,   117,   185,   185,  1605,   303,  1123,   185,   117,   197,
     291,   251,   713,   223,  1161,   938,   285,   254,   254,   416,
     303,   436,  1321,   421,   422,   303,  1005,   425,   257,  1201,
    1666,   429,  1711,   847,   432,   433,   304,   304,   304,  1210,
    1002,  1438,   440,   769,  1229,  1340,  1098,  1345,   446,  1343,
    1251,   449,   538,  1256,  1259,  1264,   636,  1283,   637,   457,
     688,   809,  1735,  1729,   903,   463,   464,   465,   466,   332,
    1195,  1160,   987,   471,  1314,   444,   444,  1324,  1358,  1323,
    1369,   479,  1533,  1108,  1685,  1362,  1530,  1117,   970,  1183,
    1404,  1557,  1359,  1210,    -1,    -1,  1213,  1698,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1457,    -1,    -1,
      -1,  1228,    -1,    -1,    -1,  1457,    -1,    -1,    -1,    -1,
    1237,    -1,  1723,    -1,    -1,    -1,   524,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1251,    -1,    -1,    -1,    -1,    -1,
     538,    -1,    -1,    -1,  1261,    -1,    -1,    -1,    -1,    -1,
      -1,   549,    -1,    -1,  1755,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1290,    -1,    -1,  1777,    -1,    -1,    -1,
      -1,  1782,    -1,  1626,    -1,    -1,    -1,   108,    -1,   587,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1314,    -1,  1642,
      -1,    -1,    -1,    -1,    -1,    -1,  1323,    -1,    -1,  1326,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1584,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1584,    -1,    -1,  1595,  1596,    -1,  1598,    -1,
      -1,    -1,    -1,  1595,  1596,  1605,  1598,    -1,    -1,    -1,
      -1,    -1,    -1,  1605,  1381,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1409,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   707,
      -1,    -1,   710,    -1,    -1,    -1,    -1,    -1,  1435,  1436,
      -1,    -1,    -1,    -1,    -1,    -1,   724,    -1,    -1,    -1,
     728,   729,    -1,    -1,    -1,  1685,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1685,  1461,    -1,  1463,    -1,  1698,  1466,
      -1,    -1,   750,    -1,   752,    -1,  1698,    -1,    -1,    -1,
      -1,  1478,   760,    -1,    -1,   763,  1483,    -1,    -1,   767,
      -1,    -1,    -1,  1723,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1723,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1755,    -1,    -1,    -1,    -1,
     808,    -1,    -1,  1755,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1777,    -1,    -1,
      -1,    -1,  1782,    -1,    -1,  1777,    -1,    -1,    -1,    -1,
    1782,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   846,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   871,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1599,    -1,  1601,    -1,  1603,    -1,    -1,    -1,
      -1,    -1,    -1,  1610,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   900,   901,   902,   903,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1644,    -1,  1646,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   937,
      -1,    -1,    -1,    -1,    -1,  1662,    -1,    -1,  1665,    -1,
      -1,    -1,    -1,   951,    -1,    -1,    -1,    -1,    -1,    -1,
    1677,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1687,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   976,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   985,    -1,   987,
    1707,    -1,    -1,   991,    -1,    -1,    -1,    -1,  1715,    -1,
      -1,    -1,    -1,  1720,    -1,  1722,  1004,  1724,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,
      -1,    -1,    -1,    -1,    -1,  1752,    -1,    -1,    -1,  1037,
      -1,  1039,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1769,    -1,   575,   576,  1773,    -1,   579,   580,
     581,   582,    -1,   584,    -1,    -1,    -1,    -1,    -1,   590,
      -1,    -1,  1789,    -1,    -1,  1792,    -1,   598,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   618,    -1,    -1,
      -1,    -1,    -1,    -1,  1102,   626,   627,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1123,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   685,    -1,    -1,   688,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   726,    -1,    -1,    -1,    -1,
      -1,    -1,  1210,    -1,    -1,  1213,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1237,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   768,    -1,    -1,
      -1,    -1,    -1,  1251,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1261,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   793,    -1,    -1,    -1,   797,   798,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   806,    -1,    -1,    -1,    -1,
      -1,    -1,  1290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1314,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1323,    -1,    -1,  1326,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   873,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1381,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1409,    -1,    -1,    -1,    -1,    -1,    -1,   939,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1435,  1436,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   974,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1461,    -1,  1463,    -1,    -1,  1466,    -1,
      -1,    -1,   993,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1478,    -1,    -1,    -1,    -1,  1483,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1015,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1026,  1027,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1041,    -1,    -1,  1044,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1059,    -1,
    1061,  1062,  1063,    -1,  1065,  1066,  1067,  1068,  1069,  1070,
    1071,  1072,    -1,    -1,  1075,  1076,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1089,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1098,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1599,    -1,  1601,    -1,  1603,    -1,    -1,    -1,    -1,
      -1,    -1,  1610,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1644,    -1,  1646,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1662,    -1,    -1,  1665,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1677,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1687,
      -1,    -1,    -1,    -1,  1215,    -1,  1217,    -1,  1219,    -1,
      -1,  1222,    -1,    -1,    -1,    -1,  1227,    -1,    -1,  1707,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1715,  1239,    -1,
      -1,    -1,  1720,    -1,  1722,    -1,  1724,  1248,    -1,    -1,
      -1,    -1,    -1,  1254,  1255,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1273,    -1,  1752,  1276,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1769,    -1,    -1,    -1,  1773,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1789,    -1,    -1,  1792,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1343,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1422,    -1,    -1,    -1,  1426,    -1,    -1,    -1,  1430,
      -1,  1432,    -1,  1434,    -1,    -1,    -1,    -1,    -1,  1440,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1448,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1456,  1457,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1475,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1487,  1488,  1489,  1490,
      -1,    -1,  1493,  1494,    -1,  1496,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1572,    -1,  1574,    -1,    -1,  1577,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1585,    -1,    -1,    -1,    -1,  1590,
    1591,    -1,    -1,    -1,    -1,    -1,    -1,  1598,    -1,    -1,
      -1,  1602,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1618,  1619,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1669,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1681,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1723,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1741,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1750,
      -1,    -1,    -1,    -1,  1755,    11,    12,    -1,    -1,  1760,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    -1,  1776,    -1,    33,    34,  1780,
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
     306,   307,   308,    -1,   310,    -1,   312,   313,   314,    -1,
     316,   317,   318,   319,    11,    12,    -1,    -1,    -1,    -1,
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
     307,   308,    -1,   310,    -1,   312,   313,   314,    -1,   316,
     317,   318,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
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
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
      -1,   310,    -1,   312,   313,   314,    -1,   316,   317,   318,
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
     301,   302,   303,   304,   305,   306,   307,   308,    -1,   310,
      -1,   312,   313,   314,    -1,   316,   317,   318,    11,    12,
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
     183,    -1,   185,    -1,   187,   188,    -1,   190,   191,   192,
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
     303,   304,   305,   306,   307,   308,    -1,   310,    -1,   312,
     313,   314,    -1,   316,   317,   318,    11,    12,    -1,    -1,
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
     175,   176,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,
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
     305,   306,   307,   308,    -1,   310,    -1,   312,   313,   314,
      -1,   316,   317,   318,    11,    12,    -1,    -1,    -1,    -1,
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
     307,   308,    -1,   310,    -1,   312,   313,   314,    -1,   316,
     317,   318,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,   310,    -1,   312,   313,   314,    -1,   316,   317,   318,
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
     301,   302,   303,   304,   305,   306,   307,   308,    -1,   310,
      -1,   312,   313,   314,    -1,   316,   317,   318,    11,    12,
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
     303,   304,   305,   306,   307,   308,    -1,   310,    -1,   312,
     313,   314,    -1,   316,   317,   318,    11,    12,    -1,    -1,
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
     175,   176,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,
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
     305,   306,   307,   308,    -1,   310,    -1,   312,   313,   314,
      -1,   316,   317,   318,    11,    12,    -1,    -1,    -1,    -1,
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
      -1,    -1,   179,   180,   181,    -1,    -1,   184,   185,    -1,
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
     307,   308,    -1,   310,    -1,   312,   313,   314,    -1,   316,
     317,   318,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
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
     179,   180,   181,    -1,    -1,    -1,   185,   186,   187,   188,
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
      -1,   310,    -1,   312,   313,   314,    -1,   316,   317,   318,
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
      -1,   312,   313,   314,    -1,   316,   317,   318,    11,    12,
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
     303,   304,   305,   306,   307,   308,    -1,   310,   311,   312,
     313,   314,    -1,   316,   317,   318,    11,    12,    -1,    -1,
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
     305,   306,   307,   308,    -1,   310,    -1,   312,   313,   314,
      -1,   316,   317,   318,    11,    12,    -1,    -1,    -1,    -1,
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
     307,   308,    -1,   310,    -1,   312,   313,   314,    -1,   316,
     317,   318,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
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
     179,   180,   181,    -1,    -1,    -1,   185,   186,   187,   188,
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
      -1,   310,    -1,   312,   313,   314,    -1,   316,   317,   318,
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
     301,   302,   303,   304,   305,   306,   307,   308,    -1,   310,
      -1,   312,   313,   314,    -1,   316,   317,   318,    11,    12,
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
     303,   304,   305,   306,   307,   308,    -1,   310,    -1,   312,
     313,   314,    -1,   316,   317,   318,    11,    12,    -1,    -1,
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
     305,   306,   307,   308,    -1,   310,    -1,   312,   313,   314,
      -1,   316,   317,   318,    11,    12,    -1,    -1,    -1,    -1,
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
      -1,   158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,
     167,   168,   169,   170,   171,    -1,   173,    -1,    -1,    -1,
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
     307,   308,    -1,   310,    -1,   312,   313,   314,    -1,   316,
     317,   318,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,   310,    -1,   312,   313,   314,    -1,   316,   317,   318,
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
      -1,    -1,    -1,   134,    -1,   136,   137,   138,    -1,    -1,
      -1,    -1,    -1,    -1,   145,   146,   147,   148,    -1,   150,
     151,   152,   153,    -1,   155,   156,    -1,   158,   159,    -1,
      -1,    -1,    -1,   164,   165,   166,   167,   168,   169,   170,
     171,    -1,   173,    -1,    -1,    -1,    -1,    -1,   179,   180,
     181,    -1,    -1,    -1,   185,    -1,   187,   188,    -1,    -1,
      -1,   192,    -1,   194,    -1,   196,    -1,   198,    -1,   200,
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
     301,   302,   303,   304,   305,   306,   307,   308,    -1,   310,
      -1,   312,   313,   314,    -1,   316,   317,   318,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,
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
      -1,    -1,   185,    -1,   187,   188,    -1,    -1,    -1,   192,
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
     303,   304,   305,   306,   307,    -1,    -1,    11,    12,   312,
     313,   314,    -1,   316,   317,   318,    20,    -1,    -1,    -1,
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
     304,   305,   306,   307,    -1,    -1,    -1,    16,   312,   313,
     314,    -1,   316,   317,   318,    24,    25,    -1,    -1,    -1,
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
     299,   300,   301,   302,   303,   304,   305,   306,   307,    -1,
      -1,    -1,    16,   312,   313,   314,    -1,   316,   317,   318,
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
     304,   305,   306,   307,    -1,    -1,    -1,    -1,   312,   313,
     314,    -1,   316,   317,   318,    18,    19,    -1,    -1,    -1,
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
     303,   304,   305,   306,   307,    -1,    -1,    -1,    -1,   312,
     313,   314,    -1,   316,   317,   318,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    -1,    99,   100,   101,    -1,    -1,   104,
     105,    -1,    -1,    -1,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    -1,    -1,    -1,    -1,   123,    -1,
     125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,
     135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
     155,   156,    -1,   158,   159,    -1,    -1,    -1,    -1,   164,
     165,   166,   167,   168,   169,   170,   171,    -1,   173,    -1,
      -1,    -1,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,
     185,    -1,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
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
     305,   306,   307,   308,    -1,   310,    -1,   312,   313,   314,
      -1,   316,   317,   318,    24,    25,    -1,    -1,    -1,    -1,
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
     300,   301,   302,   303,   304,   305,   306,   307,    -1,    -1,
      24,    25,   312,   313,   314,   315,   316,   317,   318,    33,
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
     304,   305,   306,   307,    -1,    -1,    24,    25,   312,   313,
     314,   315,   316,   317,   318,    33,    34,    -1,    36,    37,
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
      -1,    -1,    24,    25,   312,   313,   314,   315,   316,   317,
     318,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    -1,    99,   100,   101,
      -1,    -1,   104,   105,    -1,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   125,   126,   127,   128,    -1,   130,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,    -1,   149,   150,   151,
      -1,    -1,    -1,   155,    -1,    -1,   158,   159,    -1,    -1,
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
     302,   303,   304,   305,   306,   307,    -1,    -1,    24,    25,
     312,   313,   314,   315,   316,   317,   318,    33,    34,    -1,
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
     306,   307,    -1,    -1,    24,    25,   312,   313,   314,    -1,
     316,   317,   318,    33,    34,    -1,    36,    37,    38,    39,
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
     300,   301,   302,   303,   304,   305,   306,   307,    -1,    -1,
      24,    25,   312,   313,   314,    -1,   316,   317,   318,    33,
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
     304,   305,   306,   307,    -1,    -1,    24,    25,   312,   313,
     314,   315,   316,   317,   318,    33,    34,    -1,    36,    37,
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
      -1,    -1,    24,    25,   312,   313,   314,   315,   316,   317,
     318,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
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
     302,   303,   304,   305,   306,   307,    -1,    -1,    24,    25,
     312,   313,   314,    -1,   316,   317,   318,    33,    34,    -1,
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
     236,   237,   238,   239,   240,    -1,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
      -1,   257,   258,   259,    -1,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,    -1,    -1,    -1,    -1,   312,   313,   314,    -1,
     316,   317,   318
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
     305,   306,   307,   308,   310,   312,   313,   314,   316,   317,
     318,   319,   331,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     352,   353,   354,   355,   356,   357,   361,   362,   363,   367,
     369,   370,   372,   379,   381,   384,   385,   386,   388,   389,
     390,   391,   392,   394,   395,   397,   398,   399,   400,   401,
     402,   404,   405,   408,   409,   410,   411,   416,   418,   420,
     421,   426,   445,   448,   452,   455,   456,   461,   462,   463,
     464,   466,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   512,   513,   514,   528,   529,   531,   532,   533,   534,
     535,   536,   537,   545,   546,   547,   548,   549,   550,   551,
     552,   553,   554,   557,   558,   559,   560,   565,   566,   567,
     568,   569,   570,   573,   631,   633,   634,   635,   636,   637,
     638,   639,   640,   647,   648,   649,    33,    34,    49,   213,
     387,   388,   389,   387,   387,   155,   155,    37,    38,    40,
      41,    47,    56,    57,    74,    79,   110,   111,   112,   159,
     218,   259,   285,   293,   301,   368,   369,   373,   374,   375,
     159,   152,   155,   152,   155,   152,   155,    66,    71,   117,
     413,   155,   376,   155,    24,    34,    60,   117,   271,   425,
     427,   428,   152,   155,   155,   155,   117,   152,   155,   155,
     155,    76,   152,   219,   220,   121,   121,   121,   152,   155,
      39,    43,    45,    46,    47,    48,    51,    59,    67,    70,
      72,    73,    75,    90,    91,    97,   104,   111,   113,   114,
     134,   137,   138,   168,   171,   179,   180,   188,   200,   222,
     224,   226,   227,   234,   236,   237,   238,   241,   242,   313,
     496,   647,   648,   121,   117,   396,   121,   121,    39,    44,
      45,    59,    61,    62,    70,    97,   223,   647,   117,   121,
     121,   183,   387,   389,   409,   632,    48,    72,    73,   117,
     152,   184,   242,   408,   410,   420,   186,   408,   647,   152,
     121,    16,   646,   647,    18,    19,   647,   121,   121,   121,
     488,   152,    30,   212,   214,   223,   225,   312,   155,   223,
     225,   312,   223,   312,   223,   228,   312,   117,   239,   239,
     240,   155,   152,   391,   309,   408,   311,   408,   312,   333,
       0,   335,   336,    33,    49,   338,   355,     1,   189,   332,
     189,   332,   111,   370,   390,   408,   106,   189,   106,   189,
      42,    46,    51,    69,   167,   170,   185,   210,   403,   412,
     417,   418,   419,   433,   434,   438,   166,    92,   131,   139,
     140,   142,   150,   154,   156,   161,   178,   201,   202,   203,
     204,   205,   206,   480,   481,   247,   157,   175,   197,   116,
     145,   158,   192,   199,   208,   135,   149,    50,   198,   100,
     101,   157,   175,   479,   152,   485,   488,   190,   191,   153,
     500,   501,   496,   500,   496,   155,   500,   144,   155,   183,
     183,   183,   371,   503,   371,    29,   645,   181,   194,   181,
     194,   165,   181,   648,   647,   168,   200,    47,   647,   151,
     117,    45,    47,    79,   105,   167,   646,   219,   220,   221,
     244,   604,   647,   647,   302,   136,   141,   111,   285,   293,
     373,   646,   388,   389,   186,   388,    45,    62,   186,   553,
     554,   408,   186,   192,   647,   282,   282,   422,   423,   647,
     117,   429,   117,   186,   377,   378,   152,   393,   408,     1,
     159,   645,   112,   159,   351,   645,   647,   117,   141,   106,
     408,    29,   186,   646,   647,   647,   446,   447,   647,   388,
     186,   408,   408,   555,   647,   388,   152,   152,   408,   186,
     192,   647,   647,   141,   446,   183,   183,   120,   106,   183,
     155,   155,   155,   647,   152,   184,   185,   186,    35,   516,
     517,   518,   408,     8,   174,    17,   408,   212,    29,   409,
     409,    39,    45,    59,    70,    97,   502,   647,   186,   409,
     409,   409,   409,   502,   409,   229,   228,   571,   572,   647,
     189,   189,   409,   408,   389,   408,   243,   406,   407,   309,
     311,   409,   189,   332,   189,   332,     3,   339,   355,   385,
     339,   355,   385,    33,   356,   385,   356,   385,   396,   396,
     409,   117,   167,   169,   169,   390,   409,   409,   463,   464,
     466,   466,   466,   466,   465,   466,   466,   466,    70,   470,
     470,   469,   471,   471,   471,   471,   472,   472,   473,   473,
     229,    94,    94,    94,   183,   408,   488,   488,   408,   501,
     186,   409,   511,   148,   186,   511,   106,   186,   186,   106,
     106,   376,    29,   648,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,   358,   359,   360,    94,   136,   141,
     364,   365,   366,   647,   159,   159,   358,   645,   126,   131,
      54,    56,    99,   249,   262,   264,   275,   276,   277,   279,
     281,   605,   606,   607,   608,   609,   610,   617,   623,   624,
     244,    94,   297,   647,   141,   409,   117,   647,   647,   131,
     183,   183,   186,   186,   183,   106,   186,   106,   186,   106,
      36,    94,    96,   146,   424,   425,   539,   647,    55,   215,
     252,   414,   415,   647,    94,   106,   186,   387,   186,   646,
      96,    45,   646,   645,    96,   141,   539,   647,   409,   428,
     183,   186,   186,   186,   186,   106,   187,   146,   539,   183,
     186,   186,   152,   183,   388,   388,   183,   106,   186,   106,
     186,   141,   539,   409,   187,   409,   409,   408,   408,   408,
     647,   517,   518,   129,   195,   183,   183,   130,   189,   155,
      94,   216,   217,   231,    94,   216,   217,   231,   231,    94,
     155,   235,   223,   229,   106,   233,   141,   189,   186,    48,
      72,    73,   242,   410,   420,   183,   497,   577,   407,   197,
     355,    33,    33,   189,   332,   189,   112,   647,   169,   409,
     439,   440,   117,   435,   436,   466,   152,   155,   257,   484,
     503,   578,   581,   582,   583,   584,   585,   589,   591,   593,
     594,    47,   151,   155,   209,   315,   316,   317,   318,   540,
     542,   544,   545,   561,   562,   563,   564,   641,   642,   643,
     644,   647,   540,   538,   544,   538,   183,   184,   106,   186,
     186,   503,   147,   164,   147,   164,   136,   393,   376,   359,
     131,   542,   366,   409,   539,   645,   645,   127,   128,   645,
     275,   276,   277,   281,   647,   261,   272,   261,   272,    29,
     284,    96,   112,   155,   611,   614,   605,    39,    44,    59,
      61,    70,    97,   223,   380,   545,   225,   297,   306,   409,
     647,    94,   297,   645,   152,   555,   556,   647,   555,   556,
     117,   126,   540,   117,   409,   146,   425,   146,    36,   146,
     424,   425,   146,   539,   252,    53,    58,    77,   117,   424,
     430,   431,   432,   415,   539,   540,   378,    94,   183,   196,
     131,   350,   645,   159,   131,    96,   350,   409,   141,   425,
     152,   117,   409,   409,   146,    99,   449,   450,   451,   453,
     454,    99,   457,   458,   459,   460,   388,   183,   183,   152,
     555,   555,   409,   141,   189,   409,   120,   186,   186,   186,
      35,   518,   129,   195,     9,    10,   102,   122,   124,   152,
     193,   513,   515,   526,   527,   530,    29,   409,   230,   232,
     409,   409,   409,   230,   232,   409,   409,   409,   409,   409,
     409,   409,   409,   502,   117,   409,   409,   390,   155,   155,
     155,   152,   185,   243,   574,   575,   208,   391,   409,   189,
     112,   385,   385,   385,   439,    95,   105,   115,   126,   441,
     442,   443,   444,   106,   647,   106,   408,   578,   585,   152,
     283,   467,   630,    96,   168,   250,   251,   253,   260,   270,
     282,   579,   580,   599,   600,   601,   602,   625,   628,   256,
     258,   586,   604,   265,   590,   626,   245,   246,   268,   595,
     596,   155,   155,   542,   155,   155,   155,   155,   155,   143,
     175,   192,   541,   143,   409,   136,   393,   557,   365,   284,
      29,    96,   112,   155,   618,    29,   611,   541,   486,   285,
     304,   539,   380,   225,   189,   387,   186,   186,   143,   186,
     186,   423,   146,   424,   647,   409,   146,   409,   126,   409,
     146,   425,   146,   409,   146,   117,   117,   409,   647,   432,
      77,   540,   390,   409,   645,   106,   350,   409,   141,   387,
     447,   409,   409,   112,   450,   451,    99,   185,   112,   451,
     454,   117,   540,    99,   112,   458,    99,   112,   460,   183,
     387,   186,   186,   409,   409,   196,   457,   131,   193,   515,
       7,   388,   647,   193,   526,   189,   186,   231,   231,   231,
     231,    96,   186,   235,   155,   572,   185,   408,   408,   408,
     577,   575,   497,   645,   127,   128,   443,   444,   444,   440,
     105,   437,   436,   183,   186,   578,   592,   248,   215,   252,
     266,   273,   629,    96,   254,   255,   627,   248,   582,   629,
     469,   599,   583,   146,   280,   587,   588,   627,   284,   598,
      78,   597,   186,   192,   540,   543,   186,   186,   186,   186,
     186,   186,   186,    29,   135,   199,   620,   621,   622,    29,
     619,   620,   269,   615,   106,   612,   169,   647,   255,   486,
     183,   409,   146,   409,   146,   424,   409,   146,   409,   409,
     647,   647,   431,   409,   125,   125,    96,   645,   409,   183,
     185,   185,   409,   390,   409,   185,   185,   647,   185,   117,
     540,   117,   185,   117,   540,   185,   183,   112,   518,   647,
     193,   183,   518,   647,   409,   409,   409,   409,   314,    94,
     409,   409,   409,   186,   186,   186,   152,   576,   444,   645,
     183,   471,    52,   128,   469,   469,   267,   274,   284,   603,
     603,   584,   152,   278,    94,   186,   106,   186,   618,   618,
     622,   106,   186,    29,   616,   627,   613,   614,   186,   382,
     383,   486,   117,   223,   305,   285,   169,   409,   409,   146,
     409,    53,   390,   409,   350,   409,   390,    94,   390,   409,
     647,   185,   647,   409,   647,   185,   390,   117,    93,   182,
     519,   518,   647,   195,   518,   409,   409,   186,   196,   457,
     408,   469,   469,   197,   408,   540,   540,    94,    29,   263,
     106,   106,   444,   539,   647,   117,   223,   647,   382,   409,
     117,   540,    94,   185,    94,   647,     5,   132,   522,   523,
     525,   527,    28,   133,   520,   521,   524,   527,   195,   518,
     195,   235,   112,   183,   469,   183,   540,   614,   383,   444,
     303,   647,   117,   223,   647,   185,   540,   390,   409,   540,
     185,    93,   132,   525,   182,   133,   524,   195,   409,   117,
     409,   303,   647,   117,   390,   409,   185,   185,   647,   291,
     303,   647,   185,   304,   409,   304,   486,   486,   197,   285,
     647,   223,   117,   647,   304,   486
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
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   330,   331,   331,   332,   333,   333,   333,   333,   334,
     334,   335,   335,   335,   335,   335,   335,   335,   335,   336,
     336,   336,   336,   337,   338,   338,   338,   339,   339,   339,
     339,   339,   340,   340,   340,   340,   340,   340,   340,   340,
     341,   341,   342,   343,   344,   344,   345,   345,   346,   346,
     347,   347,   347,   347,   348,   348,   348,   349,   349,   349,
     349,   350,   350,   351,   351,   352,   352,   352,   352,   353,
     354,   354,   355,   355,   355,   356,   356,   356,   356,   356,
     356,   356,   356,   357,   357,   358,   358,   359,   360,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   361,   362,
     363,   364,   364,   365,   365,   365,   366,   367,   367,   367,
     368,   368,   368,   368,   369,   369,   370,   370,   370,   370,
     371,   371,   372,   372,   373,   373,   374,   374,   375,   375,
     376,   376,   376,   376,   377,   377,   378,   378,   379,   379,
     379,   379,   380,   380,   381,   381,   382,   382,   383,   383,
     383,   383,   384,   384,   384,   384,   385,   386,   386,   386,
     387,   387,   387,   388,   388,   389,   389,   390,   390,   390,
     390,   390,   390,   390,   390,   390,   390,   390,   390,   391,
     391,   392,   393,   394,   395,   395,   395,   396,   396,   396,
     396,   397,   398,   399,   400,   401,   401,   402,   403,   404,
     405,   406,   406,   407,   408,   408,   409,   409,   409,   409,
     409,   409,   410,   410,   410,   410,   410,   410,   410,   410,
     410,   410,   410,   410,   411,   412,   413,   413,   414,   414,
     414,   415,   415,   416,   416,   417,   418,   418,   418,   419,
     419,   419,   419,   419,   420,   420,   421,   422,   422,   423,
     423,   423,   423,   423,   423,   423,   423,   423,   423,   423,
     423,   424,   425,   426,   427,   427,   428,   428,   428,   428,
     429,   429,   430,   430,   430,   431,   431,   431,   432,   432,
     432,   433,   434,   435,   435,   436,   436,   437,   438,   438,
     439,   439,   440,   440,   441,   441,   441,   441,   441,   441,
     441,   442,   442,   443,   443,   444,   445,   445,   446,   446,
     447,   447,   448,   449,   449,   450,   451,   451,   452,   453,
     453,   454,   455,   455,   456,   456,   457,   457,   458,   458,
     459,   459,   460,   460,   461,   462,   462,   463,   463,   464,
     464,   464,   464,   464,   465,   464,   464,   464,   464,   466,
     466,   467,   467,   468,   468,   469,   469,   469,   470,   470,
     470,   470,   470,   471,   471,   471,   472,   472,   472,   473,
     473,   474,   474,   475,   475,   476,   476,   477,   477,   478,
     478,   478,   478,   479,   479,   479,   480,   480,   480,   480,
     480,   480,   481,   481,   481,   482,   482,   482,   482,   483,
     483,   484,   484,   485,   485,   485,   486,   486,   486,   486,
     487,   488,   488,   488,   489,   489,   490,   490,   490,   490,
     491,   491,   492,   492,   492,   492,   492,   492,   492,   493,
     493,   494,   494,   495,   495,   495,   495,   495,   496,   496,
     497,   497,   498,   498,   498,   498,   499,   499,   499,   499,
     500,   500,   501,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   503,   503,   504,
     504,   504,   505,   506,   506,   507,   508,   509,   510,   510,
     511,   511,   512,   512,   513,   513,   513,   514,   514,   514,
     514,   514,   514,   515,   515,   516,   516,   517,   518,   518,
     519,   519,   520,   520,   521,   521,   521,   521,   522,   522,
     523,   523,   523,   523,   524,   524,   525,   525,   526,   526,
     526,   526,   527,   527,   527,   527,   528,   528,   529,   529,
     530,   531,   531,   531,   531,   531,   531,   532,   533,   533,
     534,   534,   535,   536,   537,   537,   538,   538,   539,   540,
     540,   540,   541,   541,   541,   542,   542,   542,   542,   542,
     542,   542,   543,   543,   544,   545,   545,   545,   545,   545,
     545,   545,   545,   545,   546,   547,   547,   547,   548,   549,
     550,   550,   550,   551,   551,   551,   551,   551,   552,   553,
     553,   553,   553,   553,   553,   553,   554,   555,   556,   557,
     558,   558,   559,   560,   561,   561,   562,   563,   563,   564,
     565,   565,   565,   566,   566,   566,   566,   566,   566,   566,
     566,   566,   566,   567,   567,   568,   568,   569,   570,   571,
     571,   572,   573,   574,   574,   575,   576,   577,   577,   578,
     579,   579,   580,   580,   581,   581,   582,   582,   583,   583,
     584,   584,   585,   586,   586,   587,   587,   588,   589,   589,
     589,   590,   590,   591,   592,   592,   593,   594,   594,   595,
     595,   596,   596,   596,   597,   597,   598,   598,   599,   599,
     599,   599,   599,   600,   601,   602,   603,   603,   603,   604,
     604,   605,   605,   605,   605,   605,   605,   605,   605,   606,
     606,   606,   606,   607,   607,   608,   609,   609,   610,   610,
     610,   611,   611,   612,   612,   613,   613,   614,   615,   615,
     616,   616,   617,   617,   617,   618,   618,   619,   619,   620,
     620,   621,   621,   622,   622,   623,   624,   624,   625,   625,
     625,   626,   627,   627,   627,   627,   628,   628,   629,   629,
     630,   631,   632,   632,   633,   633,   634,   634,   635,   635,
     636,   636,   637,   638,   639,   640,   641,   641,   641,   642,
     643,   644,   645,   646,   646,   647,   647,   647,   647,   647,
     647,   647,   647,   647,   647,   647,   647,   647,   647,   647,
     647,   648,   648,   648,   648,   648,   648,   648,   648,   648,
     648,   648,   648,   648,   648,   648,   648,   648,   648,   648,
     648,   648,   648,   648,   648,   648,   648,   648,   648,   648,
     648,   648,   648,   648,   648,   648,   648,   648,   648,   648,
     648,   648,   648,   648,   648,   648,   648,   648,   648,   648,
     648,   648,   648,   648,   648,   648,   648,   648,   648,   648,
     648,   648,   648,   648,   648,   648,   648,   648,   648,   648,
     648,   648,   648,   648,   648,   648,   648,   648,   648,   648,
     648,   648,   648,   648,   648,   648,   648,   648,   648,   648,
     648,   648,   648,   648,   648,   648,   648,   648,   648,   648,
     648,   648,   648,   648,   648,   648,   648,   648,   648,   648,
     648,   648,   648,   648,   648,   648,   648,   648,   648,   648,
     648,   648,   648,   648,   648,   648,   648,   648,   648,   648,
     648,   648,   648,   648,   648,   648,   648,   648,   648,   648,
     648,   648,   648,   648,   648,   648,   648,   648,   648,   648,
     648,   648,   648,   648,   648,   648,   648,   648,   648,   648,
     648,   648,   648,   648,   648,   648,   648,   648,   648,   648,
     648,   648,   648,   648,   648,   648,   648,   648,   648,   648,
     648,   648,   648,   648,   648,   648,   648,   648,   648,   648,
     648,   648,   648,   648,   648,   648,   648,   648,   648,   648,
     648,   648,   648,   648,   648,   648,   649
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     3,     1,     4,     4,     3,     4,
       1,     3,     1,     1,     1,     1,     1,     4,     5,     8,
       9,     9,    10,     1,     2,     1,     2,     6,     0,     1,
       3,     3,     0,     1,     1,     1,     2,     2,     0,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     2,     3,     3,
       2,     1,     1,     1,     1,     1,     1,     4,     3,     7,
       3,     7,     4,     4,     3,     7,     1,     2,     2,     1,
       2,     3,     1,     1,     1,     1,     1,     3,     3,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     4,     4,     3,     3,
       3,     4,     4,     3,     4,     6,     4,     6,     4,     3,
       4,     6,     6,     4,     6,     6,     4,     1,     2,     1,
       1,     1,     3,     3,     1,     1,     4,     5,     6,     3,
       3,     3,     3,     5,     7,     7,     5,     5,     5,     7,
       7,     5,     5,     3,     3,     5,     7,     5,     7,     1,
       4,     3,     5,     1,     2,     3,     3,     1,     3,     2,
       0,     1,     1,     2,     1,     3,     1,     3,     1,     4,
       1,     2,     3,     0,     1,     0,     1,     4,     2,     3,
       1,     0,     1,     4,     0,     1,     2,     1,     3,     0,
       1,     2,     2,     1,     0,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     1,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     2,     2,     3,     1,     2,     2,     5,
       2,     1,     1,     0,     2,     1,     3,     4,     0,     2,
       0,     2,     4,     4,     3,     2,     3,     1,     3,     0,
       1,     1,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     3,     2,     3,     3,     4,     2,     2,     1,     1,
       3,     3,     3,     5,     2,     3,     2,     3,     2,     3,
       5,     8,     6,     8,    10,     5,     1,     1,     1,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
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
  "\"'keys'\"", "\"'{|'\"", "\"'|}'\"", "\"'{['\"", "\"']}'\"",
  "\"'json'\"", "\"'append'\"", "\"'position'\"", "\"'object'\"",
  "\"'array'\"", "\"'json-item'\"", "\"'structured-item'\"",
  "\"'BOM_UTF8'\"", "RANGE_REDUCE", "SEQUENCE_TYPE_REDUCE",
  "ADDITIVE_REDUCE", "UNION_REDUCE", "INTERSECT_EXCEPT_REDUCE",
  "QVARINDECLLIST_REDUCE", "COMMA_DOLLAR", "UNARY_PREC", "STEP_REDUCE",
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
  "FTIgnoreOption", "JSONObjectConstructor", "JSONPairList",
  "JSONArrayConstructor", "JSONSimpleObjectUnion",
  "JSONAccumulatorObjectUnion", "JSONInsertExpr", "JSONDeleteExpr",
  "JSONRenameExpr", "JSONReplaceExpr", "JSONAppendExpr", "JSONTest",
  "JSONItemTest", "JSONObjectTest", "JSONArrayTest", "URI_LITERAL",
  "NCNAME", "QNAME", "FUNCTION_NAME", "EQNAME", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const xquery_parser::rhs_number_type
  xquery_parser::yyrhs_[] =
  {
       331,     0,    -1,   333,    -1,   319,   333,    -1,     1,     3,
      -1,   335,    -1,   334,   335,    -1,   336,    -1,   334,   336,
      -1,   213,   214,    29,   189,    -1,   213,   214,    29,   130,
      29,   189,    -1,   338,   189,   385,    -1,   355,   189,   385,
      -1,   338,   189,   355,   189,   385,    -1,   385,    -1,   338,
     332,   385,    -1,   355,   332,   385,    -1,   338,   189,   355,
     332,   385,    -1,   338,   332,   355,   189,   385,    -1,   337,
      -1,   337,   338,   189,    -1,   337,   355,   189,    -1,   337,
     338,   189,   355,   189,    -1,    34,   159,   646,   131,   645,
     189,    -1,   339,    -1,   338,   189,   339,    -1,   338,   332,
     339,    -1,   340,    -1,   348,    -1,   353,    -1,   354,    -1,
     362,    -1,   341,    -1,   342,    -1,   343,    -1,   344,    -1,
     345,    -1,   346,    -1,   347,    -1,   565,    -1,    33,    38,
     181,    -1,    33,    38,   194,    -1,    33,   112,   105,   645,
      -1,    33,    37,   645,    -1,    33,    40,   181,    -1,    33,
      40,   194,    -1,    33,    57,   168,    -1,    33,    57,   200,
      -1,    33,   112,   167,   126,   127,    -1,    33,   112,   167,
     126,   128,    -1,    33,    41,   181,   106,   147,    -1,    33,
      41,   181,   106,   164,    -1,    33,    41,   165,   106,   147,
      -1,    33,    41,   165,   106,   164,    -1,   349,    -1,   352,
      -1,    49,    24,     1,    -1,    49,    60,   645,    -1,    49,
      60,   351,   645,    -1,    49,    60,   645,    96,   350,    -1,
      49,    60,   351,   645,    96,   350,    -1,   645,    -1,   350,
     106,   645,    -1,   159,   646,   131,    -1,   112,    45,   159,
      -1,    49,    34,   645,    -1,    49,    34,   159,   646,   131,
     645,    -1,    49,    34,   645,    96,   350,    -1,    49,    34,
     159,   646,   131,   645,    96,   350,    -1,    33,   159,   646,
     131,   645,    -1,    33,   112,    45,   159,   645,    -1,    33,
     112,    47,   159,   645,    -1,   356,    -1,   355,   189,   356,
      -1,   355,   332,   356,    -1,   357,    -1,   361,    -1,   363,
      -1,   367,    -1,   372,    -1,   379,    -1,   381,    -1,   384,
      -1,    33,   112,    79,   358,    -1,    33,    79,   647,   358,
      -1,   359,    -1,   358,   359,    -1,   360,   131,   557,    -1,
      80,    -1,    88,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    89,    -1,    85,    -1,    86,    -1,    87,    -1,
      33,    56,   647,    29,    -1,    33,   259,   604,    -1,    33,
     110,   151,   364,    -1,    94,   542,   365,    -1,   365,    -1,
     366,    -1,   136,    -1,   136,   366,    -1,   141,   409,    -1,
      33,   368,   141,   409,    -1,    33,   368,   136,    -1,    33,
     368,   136,   141,   409,    -1,   111,   117,   647,    -1,   111,
     117,   647,   539,    -1,   369,   111,   117,   647,    -1,   369,
     111,   117,   647,   539,    -1,   370,    -1,   369,   370,    -1,
      26,    -1,    26,   155,   371,   186,    -1,    27,    -1,    27,
     155,   371,   186,    -1,   503,    -1,   371,   106,   503,    -1,
      33,   373,    -1,    33,   369,   373,    -1,   374,    -1,   375,
      -1,    47,   648,   376,   393,    -1,    47,   648,   376,   136,
      -1,    74,    47,   648,   376,   393,    -1,    74,    47,   648,
     376,   136,    -1,   155,   186,    -1,   155,   377,   186,    -1,
     155,   186,    94,   540,    -1,   155,   377,   186,    94,   540,
      -1,   378,    -1,   377,   106,   378,    -1,   117,   647,    -1,
     117,   647,   539,    -1,    33,   285,   647,    -1,    33,   285,
     647,    94,   380,    -1,    33,   369,   285,   647,    -1,    33,
     369,   285,   647,    94,   380,    -1,   545,    -1,   545,   541,
      -1,    33,   293,   647,   297,   225,   486,   169,   382,    -1,
      33,   369,   293,   647,   297,   225,   486,   169,   382,    -1,
     383,    -1,   382,   106,   383,    -1,   486,    -1,   486,   539,
      -1,   486,   444,    -1,   486,   539,   444,    -1,    33,   301,
     302,   647,   297,   285,   647,   117,   647,   303,   409,    -1,
      33,   301,   302,   647,   297,   285,   647,   223,   117,   647,
     303,   291,   304,   486,    -1,    33,   301,   302,   647,   297,
     285,   647,   305,   223,   117,   647,   303,   409,    -1,    33,
     301,   302,   647,   306,   304,   255,   285,   647,   223,   117,
     647,   304,   486,   197,   285,   647,   223,   117,   647,   304,
     486,    -1,   386,    -1,   388,    -1,   389,    -1,    -1,   388,
      -1,   389,    -1,    -1,   408,    -1,   389,   408,    -1,   390,
      -1,   389,   390,    -1,   391,    -1,   394,    -1,   397,    -1,
     398,    -1,   399,    -1,   400,    -1,   401,    -1,   402,    -1,
     404,    -1,   456,    -1,   452,    -1,   405,    -1,   152,   389,
     183,    -1,   152,   183,    -1,   152,   387,   183,    -1,   152,
     387,   183,    -1,   395,   189,    -1,   395,   106,   396,    -1,
     111,   396,    -1,   369,   111,   396,    -1,   117,   647,    -1,
     117,   647,   539,    -1,   117,   647,   141,   409,    -1,   117,
     647,   539,   141,   409,    -1,   117,   647,   141,   409,   189,
      -1,   410,   189,    -1,   238,   240,   409,   189,    -1,   241,
     155,   408,   186,   390,    -1,   236,   239,   189,    -1,   237,
     239,   189,    -1,   420,   403,    -1,   185,   390,    -1,    48,
     155,   408,   186,   196,   390,   125,   390,    -1,   242,   391,
     406,    -1,   407,    -1,   406,   407,    -1,   243,   577,   391,
      -1,   409,    -1,   408,   106,   409,    -1,   411,    -1,   448,
      -1,   455,    -1,   461,    -1,   573,    -1,   410,    -1,   462,
      -1,   445,    -1,   566,    -1,   567,    -1,   569,    -1,   568,
      -1,   570,    -1,   637,    -1,   636,    -1,   638,    -1,   639,
      -1,   640,    -1,   420,   412,    -1,   185,   409,    -1,    66,
     282,    -1,    71,   282,    -1,   215,    -1,   252,    -1,    55,
     252,    -1,   414,   430,    77,   409,    -1,   414,    77,   409,
      -1,    46,   413,   429,   415,   415,    -1,    46,   413,   429,
     415,    -1,    42,   117,   647,    -1,   421,    -1,   426,    -1,
     416,    -1,   418,    -1,   433,    -1,   438,    -1,   434,    -1,
     417,    -1,   418,    -1,   420,   419,    -1,    46,   117,   422,
      -1,   423,    -1,   422,   106,   117,   423,    -1,   647,   146,
     409,    -1,   647,    36,   126,   146,   409,    -1,   647,   539,
     146,   409,    -1,   647,   539,    36,   126,   146,   409,    -1,
     647,   424,   146,   409,    -1,   647,    36,   126,   424,   146,
     409,    -1,   647,   539,   424,   146,   409,    -1,   647,   539,
      36,   126,   424,   146,   409,    -1,   647,   425,   146,   409,
      -1,   647,   539,   425,   146,   409,    -1,   647,   424,   425,
     146,   409,    -1,   647,   539,   424,   425,   146,   409,    -1,
      96,   117,   647,    -1,   271,   117,   647,    -1,    51,   427,
      -1,   428,    -1,   427,   106,   428,    -1,   117,   647,   141,
     409,    -1,   117,   647,   539,   141,   409,    -1,   425,   141,
     409,    -1,   117,   647,   539,   425,   141,   409,    -1,   117,
     647,   146,   409,    -1,   117,   647,   539,   146,   409,    -1,
     431,    -1,   117,   647,    -1,   117,   647,   431,    -1,   424,
      -1,   424,   432,    -1,   432,    -1,    58,   117,   647,    53,
     117,   647,    -1,    53,   117,   647,    -1,    58,   117,   647,
      -1,   210,   409,    -1,   170,   169,   435,    -1,   436,    -1,
     435,   106,   436,    -1,   117,   647,    -1,   117,   647,   437,
      -1,   105,   645,    -1,   167,   169,   439,    -1,    69,   167,
     169,   439,    -1,   440,    -1,   439,   106,   440,    -1,   409,
      -1,   409,   441,    -1,   442,    -1,   443,    -1,   444,    -1,
     442,   443,    -1,   442,   444,    -1,   443,   444,    -1,   442,
     443,   444,    -1,    95,    -1,   115,    -1,   126,   127,    -1,
     126,   128,    -1,   105,   645,    -1,    67,   117,   446,   187,
     409,    -1,   134,   117,   446,   187,   409,    -1,   447,    -1,
     446,   106,   117,   447,    -1,   647,   146,   409,    -1,   647,
     539,   146,   409,    -1,    72,   155,   408,   186,   449,   112,
     185,   409,    -1,   450,    -1,   449,   450,    -1,   451,   185,
     409,    -1,    99,   409,    -1,   451,    99,   409,    -1,    72,
     155,   408,   186,   453,   112,   185,   390,    -1,   454,    -1,
     453,   454,    -1,   451,   185,   390,    -1,    73,   155,   408,
     186,   457,   112,   185,   409,    -1,    73,   155,   408,   186,
     457,   112,   117,   647,   185,   409,    -1,    73,   155,   408,
     186,   459,   112,   185,   390,    -1,    73,   155,   408,   186,
     457,   112,   117,   647,   185,   390,    -1,   458,    -1,   457,
     458,    -1,    99,   540,   185,   409,    -1,    99,   117,   647,
      94,   540,   185,   409,    -1,   460,    -1,   459,   460,    -1,
      99,   540,   185,   390,    -1,    99,   117,   647,    94,   540,
     185,   390,    -1,    48,   155,   408,   186,   196,   409,   125,
     409,    -1,   463,    -1,   462,   166,   463,    -1,   464,    -1,
     463,    92,   464,    -1,   466,    -1,   466,   480,   466,    -1,
     466,   481,   466,    -1,   466,   131,   466,    -1,   466,   161,
     466,    -1,    -1,   466,   156,   465,   466,    -1,   466,   154,
     466,    -1,   466,   142,   466,    -1,   466,   140,   466,    -1,
     468,    -1,   468,   247,    70,   578,   467,    -1,    -1,   630,
      -1,   469,    -1,   469,   197,   469,    -1,   470,    -1,   469,
     175,   470,    -1,   469,   157,   470,    -1,   471,    -1,   470,
     192,   471,    -1,   470,   116,   471,    -1,   470,   145,   471,
      -1,   470,   158,   471,    -1,   472,    -1,   471,   199,   472,
      -1,   471,   208,   472,    -1,   473,    -1,   472,   149,   473,
      -1,   472,   135,   473,    -1,   474,    -1,   474,    50,   229,
     540,    -1,   475,    -1,   475,   198,    94,   540,    -1,   476,
      -1,   476,   100,    94,   538,    -1,   477,    -1,   477,   101,
      94,   538,    -1,   479,    -1,   478,   479,    -1,   175,    -1,
     157,    -1,   478,   175,    -1,   478,   157,    -1,   482,    -1,
     486,    -1,   483,    -1,   201,    -1,   206,    -1,   205,    -1,
     204,    -1,   203,    -1,   202,    -1,   150,    -1,   178,    -1,
     139,    -1,    75,   152,   388,   183,    -1,    75,   220,   152,
     388,   183,    -1,    75,   219,   152,   388,   183,    -1,    75,
      76,   555,   152,   388,   183,    -1,   484,   152,   183,    -1,
     484,   152,   408,   183,    -1,   485,    -1,   484,   485,    -1,
     176,   647,    17,    -1,   176,    18,    -1,   176,    19,    -1,
     487,    -1,   487,   488,    -1,   191,   488,    -1,   488,    -1,
     190,    -1,   489,    -1,   489,   190,   488,    -1,   489,   191,
     488,    -1,   490,    -1,   499,    -1,   491,    -1,   491,   500,
      -1,   494,    -1,   494,   500,    -1,   492,   496,    -1,   493,
      -1,   104,   121,    -1,   113,   121,    -1,    97,   121,    -1,
     188,   121,    -1,   114,   121,    -1,   138,   121,    -1,   137,
     121,    -1,   496,    -1,    98,   496,    -1,   495,   496,    -1,
     119,    -1,   171,   121,    -1,    90,   121,    -1,   180,   121,
      -1,   179,   121,    -1,    91,   121,    -1,   545,    -1,   497,
      -1,   647,    -1,   498,    -1,   192,    -1,    11,    -1,    12,
      -1,    20,    -1,   502,    -1,   499,   500,    -1,   499,   155,
     186,    -1,   499,   155,   511,   186,    -1,   501,    -1,   500,
     501,    -1,   153,   408,   184,    -1,   503,    -1,   505,    -1,
     506,    -1,   507,    -1,   510,    -1,   512,    -1,   508,    -1,
     509,    -1,   558,    -1,   392,    -1,   631,    -1,   633,    -1,
     634,    -1,   635,    -1,   504,    -1,   557,    -1,   109,    -1,
     148,    -1,   123,    -1,   117,   647,    -1,   155,   186,    -1,
     155,   408,   186,    -1,   118,    -1,   168,   152,   408,   183,
      -1,   200,   152,   408,   183,    -1,   648,   155,   186,    -1,
     648,   155,   511,   186,    -1,   409,    -1,   511,   106,   409,
      -1,   513,    -1,   531,    -1,   514,    -1,   528,    -1,   529,
      -1,   156,   647,   518,   129,    -1,   156,   647,   516,   518,
     129,    -1,   156,   647,   518,   195,   193,   647,   518,   195,
      -1,   156,   647,   518,   195,   515,   193,   647,   518,   195,
      -1,   156,   647,   516,   518,   195,   193,   647,   518,   195,
      -1,   156,   647,   516,   518,   195,   515,   193,   647,   518,
     195,    -1,   526,    -1,   515,   526,    -1,   517,    -1,   516,
     517,    -1,    35,   647,   518,   131,   518,   519,    -1,    -1,
      35,    -1,   182,   520,   182,    -1,    93,   522,    93,    -1,
      -1,   521,    -1,   133,    -1,   524,    -1,   521,   133,    -1,
     521,   524,    -1,    -1,   523,    -1,   132,    -1,   525,    -1,
     523,   132,    -1,   523,   525,    -1,    28,    -1,   527,    -1,
       5,    -1,   527,    -1,   513,    -1,    10,    -1,   530,    -1,
     527,    -1,     9,    -1,   122,    -1,   124,    -1,   152,   388,
     183,    -1,   211,    30,   212,    -1,   211,   212,    -1,   173,
     646,   174,    -1,   173,   646,     8,    -1,   102,     7,    -1,
     532,    -1,   533,    -1,   534,    -1,   535,    -1,   536,    -1,
     537,    -1,    43,   152,   388,   183,    -1,    21,   387,   183,
      -1,    45,   152,   408,   183,   152,   387,   183,    -1,    22,
     387,   183,    -1,    97,   152,   408,   183,   152,   387,   183,
      -1,    70,   152,   388,   183,    -1,    39,   152,   388,   183,
      -1,    23,   387,   183,    -1,    59,   152,   408,   183,   152,
     387,   183,    -1,   544,    -1,   544,   143,    -1,    94,   540,
      -1,   542,    -1,   542,   541,    -1,   209,   155,   186,    -1,
     143,    -1,   192,    -1,   175,    -1,   544,    -1,   545,    -1,
     151,   155,   186,    -1,   318,   155,   186,    -1,   561,    -1,
     564,    -1,   641,    -1,   540,    -1,   543,   106,   540,    -1,
     647,    -1,   547,    -1,   553,    -1,   551,    -1,   554,    -1,
     552,    -1,   550,    -1,   549,    -1,   548,    -1,   546,    -1,
     223,   155,   186,    -1,    44,   155,   186,    -1,    44,   155,
     553,   186,    -1,    44,   155,   554,   186,    -1,    70,   155,
     186,    -1,    39,   155,   186,    -1,    59,   155,   186,    -1,
      59,   155,   646,   186,    -1,    59,   155,    29,   186,    -1,
      97,   155,   186,    -1,    97,   155,   647,   186,    -1,    97,
     155,   647,   106,   555,   186,    -1,    97,   155,   192,   186,
      -1,    97,   155,   192,   106,   555,   186,    -1,    61,   155,
     647,   186,    -1,    45,   155,   186,    -1,    45,   155,   647,
     186,    -1,    45,   155,   647,   106,   555,   186,    -1,    45,
     155,   647,   106,   556,   186,    -1,    45,   155,   192,   186,
      -1,    45,   155,   192,   106,   555,   186,    -1,    45,   155,
     192,   106,   556,   186,    -1,    62,   155,   647,   186,    -1,
     647,    -1,   647,   143,    -1,    29,    -1,   559,    -1,   560,
      -1,   647,   144,   148,    -1,    47,   376,   393,    -1,   562,
      -1,   563,    -1,    47,   155,   192,   186,    -1,    47,   155,
     186,    94,   540,    -1,    47,   155,   543,   186,    94,   540,
      -1,   155,   542,   186,    -1,    33,   218,   219,    -1,    33,
     218,   220,    -1,    33,   218,   221,    -1,   224,   223,   409,
     231,   409,    -1,   224,   223,   409,    94,   230,   231,   409,
      -1,   224,   223,   409,    94,   232,   231,   409,    -1,   224,
     223,   409,   216,   409,    -1,   224,   223,   409,   217,   409,
      -1,   224,   225,   409,   231,   409,    -1,   224,   225,   409,
      94,   230,   231,   409,    -1,   224,   225,   409,    94,   232,
     231,   409,    -1,   224,   225,   409,   216,   409,    -1,   224,
     225,   409,   217,   409,    -1,   222,   223,   409,    -1,   222,
     225,   409,    -1,   227,   223,   409,   235,   409,    -1,   227,
     228,   229,   223,   409,   235,   409,    -1,   226,   223,   409,
      94,   409,    -1,   234,   117,   571,   233,   409,   185,   409,
      -1,   572,    -1,   571,   106,   117,   572,    -1,   647,   141,
     409,    -1,   242,   152,   408,   183,   574,    -1,   575,    -1,
     574,   575,    -1,   243,   577,   576,    -1,   152,   408,   183,
      -1,   497,    -1,   577,   208,   497,    -1,   581,   579,    -1,
      -1,   580,    -1,   599,    -1,   580,   599,    -1,   582,    -1,
     581,   260,   582,    -1,   583,    -1,   582,   256,   583,    -1,
     584,    -1,   583,   258,   146,   584,    -1,   585,    -1,   257,
     585,    -1,   589,   586,   587,    -1,    -1,   604,    -1,    -1,
     588,    -1,   280,   152,   408,   183,    -1,   593,   590,    -1,
     155,   578,   186,    -1,   591,    -1,    -1,   626,    -1,   484,
     152,   592,   183,    -1,    -1,   578,    -1,   594,   595,    -1,
     503,    -1,   152,   408,   183,    -1,    -1,   596,    -1,   246,
     597,    -1,   245,   598,    -1,   268,    -1,    -1,    78,    -1,
      -1,   284,    -1,   600,    -1,   601,    -1,   602,    -1,   628,
      -1,   625,    -1,   168,    -1,   282,   469,   603,    -1,   251,
     627,   603,    -1,   284,    -1,   274,    -1,   267,    -1,   244,
     605,    -1,   604,   244,   605,    -1,   606,    -1,   607,    -1,
     608,    -1,   623,    -1,   609,    -1,   617,    -1,   610,    -1,
     624,    -1,    99,   272,    -1,    99,   261,    -1,   264,    -1,
     279,    -1,   249,   272,    -1,   249,   261,    -1,    56,   647,
      29,    -1,   275,    -1,    54,   275,    -1,   277,   611,    -1,
     277,   155,   611,   612,   186,    -1,    54,   277,    -1,   614,
      -1,   112,    -1,    -1,   106,   613,    -1,   614,    -1,   613,
     106,   614,    -1,    96,    29,   615,   616,    -1,    -1,   269,
      29,    -1,    -1,   627,   263,    -1,   276,   284,   618,   620,
      -1,   276,   284,   112,   620,    -1,    54,   276,   284,    -1,
      96,    29,    -1,   155,   619,   186,    -1,    29,    -1,   619,
     106,    29,    -1,    -1,   621,    -1,   622,    -1,   621,   622,
      -1,   199,   618,    -1,   135,   618,    -1,   262,    29,    -1,
     281,    -1,    54,   281,    -1,    96,   215,    -1,    96,   252,
      -1,   253,   248,    -1,   265,   627,   278,    -1,   254,   469,
      -1,    96,   128,   469,    -1,    96,    52,   469,    -1,   255,
     469,   197,   469,    -1,   270,   629,    -1,   250,   629,    -1,
     273,    -1,   266,    -1,   283,   248,   471,    -1,   152,   632,
     183,    -1,   409,   120,   409,    -1,   632,   106,   409,   120,
     409,    -1,   153,   184,    -1,   153,   408,   184,    -1,   308,
     309,    -1,   308,   408,   309,    -1,   310,   311,    -1,   310,
     408,   311,    -1,   224,   312,   409,   231,   409,    -1,   224,
     312,   409,   231,   409,    96,   314,   409,    -1,   222,   312,
     502,   155,   409,   186,    -1,   226,   312,   502,   155,   409,
     186,    94,   409,    -1,   227,   312,   228,   229,   502,   155,
     409,   186,   235,   409,    -1,   313,   312,   409,   197,   409,
      -1,   642,    -1,   643,    -1,   644,    -1,   317,   155,   186,
      -1,   315,   155,   186,    -1,   316,   155,   186,    -1,    29,
      -1,    16,    -1,   647,    -1,   648,    -1,    97,    -1,    39,
      -1,    44,    -1,    45,    -1,   151,    -1,    48,    -1,   223,
      -1,    59,    -1,    61,    -1,    62,    -1,    70,    -1,    73,
      -1,    72,    -1,   209,    -1,   241,    -1,   649,    -1,    24,
      -1,   213,    -1,   126,    -1,    38,    -1,   259,    -1,    37,
      -1,   220,    -1,   219,    -1,   145,    -1,    43,    -1,   257,
      -1,   258,    -1,   272,    -1,   261,    -1,   249,    -1,   283,
      -1,   275,    -1,   277,    -1,   276,    -1,   281,    -1,   253,
      -1,   248,    -1,    78,    -1,   215,    -1,   252,    -1,    52,
      -1,   221,    -1,   234,    -1,   300,    -1,   228,    -1,   201,
      -1,   206,    -1,   205,    -1,   204,    -1,   203,    -1,   202,
      -1,    96,    -1,   110,    -1,   111,    -1,   185,    -1,    46,
      -1,    36,    -1,    66,    -1,    71,    -1,    58,    -1,    53,
      -1,    55,    -1,    77,    -1,    42,    -1,   146,    -1,    51,
      -1,   210,    -1,   169,    -1,   170,    -1,   167,    -1,    69,
      -1,    95,    -1,   115,    -1,   127,    -1,   128,    -1,   105,
      -1,    67,    -1,   134,    -1,   187,    -1,    99,    -1,    94,
      -1,   196,    -1,   125,    -1,   166,    -1,    92,    -1,    50,
      -1,   229,    -1,   100,    -1,   197,    -1,   116,    -1,   158,
      -1,   199,    -1,   149,    -1,   135,    -1,    75,    -1,    76,
      -1,   101,    -1,   198,    -1,   150,    -1,   181,    -1,   194,
      -1,   159,    -1,   136,    -1,   130,    -1,   165,    -1,   147,
      -1,   164,    -1,    33,    -1,    40,    -1,    57,    -1,   112,
      -1,    41,    -1,    56,    -1,   214,    -1,    49,    -1,    60,
      -1,    34,    -1,    47,    -1,   271,    -1,   247,    -1,   280,
      -1,   282,    -1,   251,    -1,   265,    -1,   278,    -1,   270,
      -1,   250,    -1,   264,    -1,   279,    -1,   269,    -1,   263,
      -1,   262,    -1,   246,    -1,   245,    -1,   254,    -1,   255,
      -1,   284,    -1,   274,    -1,   273,    -1,   268,    -1,   266,
      -1,   267,    -1,   227,    -1,   233,    -1,   230,    -1,   224,
      -1,   217,    -1,   216,    -1,   218,    -1,   235,    -1,   225,
      -1,   226,    -1,   232,    -1,   222,    -1,   231,    -1,    65,
      -1,    63,    -1,    74,    -1,   168,    -1,   200,    -1,   240,
      -1,   238,    -1,   239,    -1,   236,    -1,   237,    -1,   242,
      -1,   243,    -1,   244,    -1,    64,    -1,   293,    -1,   291,
      -1,   292,    -1,   297,    -1,   298,    -1,   299,    -1,   294,
      -1,   295,    -1,   296,    -1,    79,    -1,    80,    -1,    81,
      -1,    82,    -1,    83,    -1,    84,    -1,    85,    -1,    86,
      -1,    87,    -1,    88,    -1,    89,    -1,   285,    -1,   286,
      -1,   287,    -1,   288,    -1,   289,    -1,   290,    -1,   301,
      -1,   302,    -1,   303,    -1,   304,    -1,   305,    -1,   306,
      -1,   307,    -1,    90,    -1,   104,    -1,   113,    -1,   171,
      -1,   179,    -1,   188,    -1,   137,    -1,    91,    -1,   114,
      -1,   138,    -1,   180,    -1,   312,    -1,   313,    -1,   314,
      -1,   317,    -1,   316,    -1,   318,    -1,    25,    -1
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
     815,   817,   819,   821,   823,   826,   829,   832,   835,   837,
     839,   842,   847,   851,   857,   862,   866,   868,   870,   872,
     874,   876,   878,   880,   882,   884,   887,   891,   893,   898,
     902,   908,   913,   920,   925,   932,   938,   946,   951,   957,
     963,   970,   974,   978,   981,   983,   987,   992,   998,  1002,
    1009,  1014,  1020,  1022,  1025,  1029,  1031,  1034,  1036,  1043,
    1047,  1051,  1054,  1058,  1060,  1064,  1067,  1071,  1074,  1078,
    1083,  1085,  1089,  1091,  1094,  1096,  1098,  1100,  1103,  1106,
    1109,  1113,  1115,  1117,  1120,  1123,  1126,  1132,  1138,  1140,
    1145,  1149,  1154,  1163,  1165,  1168,  1172,  1175,  1179,  1188,
    1190,  1193,  1197,  1206,  1217,  1226,  1237,  1239,  1242,  1247,
    1255,  1257,  1260,  1265,  1273,  1282,  1284,  1288,  1290,  1294,
    1296,  1300,  1304,  1308,  1312,  1313,  1318,  1322,  1326,  1330,
    1332,  1338,  1339,  1341,  1343,  1347,  1349,  1353,  1357,  1359,
    1363,  1367,  1371,  1375,  1377,  1381,  1385,  1387,  1391,  1395,
    1397,  1402,  1404,  1409,  1411,  1416,  1418,  1423,  1425,  1428,
    1430,  1432,  1435,  1438,  1440,  1442,  1444,  1446,  1448,  1450,
    1452,  1454,  1456,  1458,  1460,  1462,  1467,  1473,  1479,  1486,
    1490,  1495,  1497,  1500,  1504,  1507,  1510,  1512,  1515,  1518,
    1520,  1522,  1524,  1528,  1532,  1534,  1536,  1538,  1541,  1543,
    1546,  1549,  1551,  1554,  1557,  1560,  1563,  1566,  1569,  1572,
    1574,  1577,  1580,  1582,  1585,  1588,  1591,  1594,  1597,  1599,
    1601,  1603,  1605,  1607,  1609,  1611,  1613,  1615,  1618,  1622,
    1627,  1629,  1632,  1636,  1638,  1640,  1642,  1644,  1646,  1648,
    1650,  1652,  1654,  1656,  1658,  1660,  1662,  1664,  1666,  1668,
    1670,  1672,  1674,  1677,  1680,  1684,  1686,  1691,  1696,  1700,
    1705,  1707,  1711,  1713,  1715,  1717,  1719,  1721,  1726,  1732,
    1741,  1751,  1761,  1772,  1774,  1777,  1779,  1782,  1789,  1790,
    1792,  1796,  1800,  1801,  1803,  1805,  1807,  1810,  1813,  1814,
    1816,  1818,  1820,  1823,  1826,  1828,  1830,  1832,  1834,  1836,
    1838,  1840,  1842,  1844,  1846,  1848,  1852,  1856,  1859,  1863,
    1867,  1870,  1872,  1874,  1876,  1878,  1880,  1882,  1887,  1891,
    1899,  1903,  1911,  1916,  1921,  1925,  1933,  1935,  1938,  1941,
    1943,  1946,  1950,  1952,  1954,  1956,  1958,  1960,  1964,  1968,
    1970,  1972,  1974,  1976,  1980,  1982,  1984,  1986,  1988,  1990,
    1992,  1994,  1996,  1998,  2000,  2004,  2008,  2013,  2018,  2022,
    2026,  2030,  2035,  2040,  2044,  2049,  2056,  2061,  2068,  2073,
    2077,  2082,  2089,  2096,  2101,  2108,  2115,  2120,  2122,  2125,
    2127,  2129,  2131,  2135,  2139,  2141,  2143,  2148,  2154,  2161,
    2165,  2169,  2173,  2177,  2183,  2191,  2199,  2205,  2211,  2217,
    2225,  2233,  2239,  2245,  2249,  2253,  2259,  2267,  2273,  2281,
    2283,  2288,  2292,  2298,  2300,  2303,  2307,  2311,  2313,  2317,
    2320,  2321,  2323,  2325,  2328,  2330,  2334,  2336,  2340,  2342,
    2347,  2349,  2352,  2356,  2357,  2359,  2360,  2362,  2367,  2370,
    2374,  2376,  2377,  2379,  2384,  2385,  2387,  2390,  2392,  2396,
    2397,  2399,  2402,  2405,  2407,  2408,  2410,  2411,  2413,  2415,
    2417,  2419,  2421,  2423,  2425,  2429,  2433,  2435,  2437,  2439,
    2442,  2446,  2448,  2450,  2452,  2454,  2456,  2458,  2460,  2462,
    2465,  2468,  2470,  2472,  2475,  2478,  2482,  2484,  2487,  2490,
    2496,  2499,  2501,  2503,  2504,  2507,  2509,  2513,  2518,  2519,
    2522,  2523,  2526,  2531,  2536,  2540,  2543,  2547,  2549,  2553,
    2554,  2556,  2558,  2561,  2564,  2567,  2570,  2572,  2575,  2578,
    2581,  2584,  2588,  2591,  2595,  2599,  2604,  2607,  2610,  2612,
    2614,  2618,  2622,  2626,  2632,  2635,  2639,  2642,  2646,  2649,
    2653,  2659,  2668,  2675,  2684,  2695,  2701,  2703,  2705,  2707,
    2711,  2715,  2719,  2721,  2723,  2725,  2727,  2729,  2731,  2733,
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
    3135,  3137,  3139,  3141,  3143,  3145,  3147,  3149,  3151,  3153,
    3155,  3157,  3159,  3161,  3163,  3165,  3167
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
    2477,  2478,  2483,  2484,  2487,  2488,  2489,  2490,  2491,  2494,
    2495,  2496,  2497,  2498,  2503,  2517,  2525,  2530,  2538,  2543,
    2548,  2556,  2565,  2577,  2587,  2600,  2608,  2609,  2610,  2615,
    2616,  2617,  2618,  2619,  2624,  2631,  2641,  2649,  2656,  2666,
    2676,  2686,  2696,  2706,  2716,  2726,  2736,  2747,  2756,  2766,
    2776,  2792,  2801,  2810,  2818,  2824,  2836,  2844,  2854,  2862,
    2874,  2880,  2891,  2893,  2897,  2905,  2909,  2914,  2918,  2922,
    2926,  2936,  2944,  2951,  2957,  2968,  2972,  2981,  2989,  2995,
    3005,  3011,  3021,  3025,  3035,  3041,  3047,  3053,  3062,  3071,
    3080,  3093,  3097,  3105,  3111,  3121,  3129,  3138,  3151,  3158,
    3170,  3174,  3186,  3193,  3199,  3208,  3215,  3221,  3232,  3239,
    3245,  3254,  3263,  3270,  3281,  3288,  3300,  3306,  3318,  3324,
    3335,  3341,  3352,  3358,  3369,  3378,  3382,  3391,  3395,  3403,
    3407,  3417,  3424,  3433,  3443,  3442,  3456,  3465,  3474,  3487,
    3491,  3504,  3507,  3514,  3518,  3527,  3531,  3535,  3543,  3547,
    3553,  3559,  3565,  3575,  3579,  3583,  3591,  3595,  3601,  3611,
    3615,  3625,  3629,  3639,  3643,  3653,  3657,  3667,  3671,  3679,
    3683,  3687,  3691,  3701,  3705,  3709,  3717,  3721,  3725,  3729,
    3733,  3737,  3745,  3749,  3753,  3761,  3765,  3769,  3773,  3784,
    3790,  3800,  3806,  3816,  3820,  3824,  3862,  3866,  3876,  3886,
    3899,  3908,  3918,  3922,  3931,  3935,  3944,  3950,  3958,  3964,
    3976,  3982,  3992,  3996,  4000,  4004,  4008,  4014,  4020,  4028,
    4032,  4040,  4044,  4055,  4059,  4063,  4069,  4073,  4087,  4091,
    4099,  4103,  4113,  4117,  4121,  4125,  4134,  4138,  4142,  4146,
    4154,  4160,  4170,  4178,  4182,  4186,  4190,  4194,  4198,  4202,
    4206,  4210,  4214,  4219,  4223,  4227,  4231,  4239,  4243,  4251,
    4258,  4265,  4276,  4284,  4288,  4296,  4304,  4312,  4366,  4370,
    4383,  4389,  4399,  4403,  4411,  4415,  4419,  4427,  4437,  4447,
    4457,  4467,  4477,  4492,  4498,  4509,  4515,  4526,  4537,  4539,
    4543,  4548,  4558,  4561,  4568,  4574,  4580,  4588,  4601,  4604,
    4611,  4617,  4623,  4630,  4641,  4645,  4655,  4659,  4669,  4673,
    4677,  4682,  4691,  4697,  4703,  4709,  4717,  4722,  4730,  4735,
    4743,  4751,  4756,  4761,  4766,  4771,  4776,  4785,  4793,  4797,
    4814,  4818,  4826,  4834,  4842,  4846,  4854,  4860,  4870,  4878,
    4882,  4886,  4921,  4927,  4933,  4943,  4947,  4951,  4955,  4959,
    4963,  4967,  4974,  4980,  4990,  4998,  5002,  5006,  5010,  5014,
    5018,  5022,  5026,  5030,  5038,  5046,  5050,  5054,  5064,  5072,
    5080,  5084,  5088,  5096,  5100,  5106,  5112,  5116,  5126,  5134,
    5138,  5144,  5153,  5162,  5168,  5174,  5184,  5201,  5208,  5223,
    5259,  5263,  5271,  5279,  5291,  5295,  5303,  5311,  5315,  5326,
    5343,  5349,  5355,  5365,  5369,  5375,  5381,  5385,  5391,  5395,
    5401,  5407,  5414,  5424,  5429,  5437,  5443,  5453,  5475,  5484,
    5490,  5503,  5517,  5524,  5530,  5540,  5549,  5557,  5563,  5581,
    5589,  5593,  5600,  5605,  5613,  5617,  5624,  5628,  5635,  5639,
    5646,  5650,  5659,  5672,  5675,  5683,  5686,  5694,  5702,  5710,
    5714,  5722,  5725,  5733,  5745,  5748,  5756,  5768,  5774,  5784,
    5787,  5795,  5799,  5803,  5811,  5814,  5822,  5825,  5833,  5837,
    5841,  5845,  5849,  5857,  5865,  5877,  5889,  5893,  5897,  5905,
    5911,  5921,  5925,  5929,  5933,  5937,  5941,  5945,  5949,  5957,
    5961,  5965,  5969,  5977,  5983,  5993,  6003,  6007,  6015,  6025,
    6036,  6043,  6047,  6055,  6058,  6065,  6070,  6079,  6089,  6092,
    6099,  6103,  6111,  6120,  6127,  6137,  6141,  6148,  6154,  6164,
    6167,  6174,  6179,  6191,  6199,  6211,  6219,  6223,  6231,  6235,
    6239,  6247,  6255,  6259,  6263,  6267,  6275,  6283,  6295,  6299,
    6307,  6321,  6328,  6332,  6345,  6349,  6356,  6361,  6369,  6374,
    6382,  6386,  6393,  6400,  6407,  6414,  6421,  6425,  6429,  6436,
    6443,  6450,  6462,  6466,  6467,  6480,  6481,  6482,  6483,  6484,
    6485,  6486,  6487,  6488,  6489,  6490,  6491,  6492,  6493,  6494,
    6495,  6499,  6500,  6501,  6502,  6503,  6504,  6505,  6506,  6507,
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
    6628,  6629,  6630,  6631,  6632,  6633,  6634,  6635,  6636,  6637,
    6638,  6639,  6640,  6641,  6642,  6643,  6644,  6645,  6646,  6647,
    6648,  6649,  6650,  6651,  6652,  6653,  6654,  6655,  6656,  6657,
    6658,  6659,  6660,  6661,  6662,  6663,  6664,  6665,  6666,  6667,
    6668,  6669,  6670,  6671,  6672,  6673,  6674,  6675,  6676,  6677,
    6678,  6679,  6680,  6681,  6682,  6683,  6684,  6685,  6686,  6687,
    6688,  6689,  6690,  6691,  6692,  6693,  6694,  6695,  6696,  6697,
    6698,  6699,  6700,  6701,  6702,  6703,  6708
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
     325,   326,   327,   328,   329
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 15242;
  const int xquery_parser::yynnts_ = 320;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 600;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 330;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 584;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 16975 "/home/colea/xquery_bzr/jsoniq/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 6712 "/home/colea/xquery_bzr/jsoniq/src/compiler/parser/xquery_parser.y"


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

