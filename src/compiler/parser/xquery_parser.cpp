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
#line 873 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 299 of lalr1.cc  */
#line 986 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"

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
#line 871 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 298 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 124: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 307 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 149: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 869 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 316 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 325 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 334 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 343 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 352 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 361 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 370 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 379 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 388 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 397 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 406 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 415 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 424 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 433 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 442 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 451 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 460 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 469 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 478 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 487 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 496 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 505 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 514 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 523 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 532 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 541 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 550 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 559 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 568 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 577 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 586 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 595 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 604 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 613 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 622 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 631 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 640 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 649 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 658 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 667 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 676 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 685 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 694 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 703 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 712 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 721 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 730 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 739 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 748 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 757 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 775 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 784 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 820 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 829 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 838 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 847 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 856 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 865 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 874 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 901 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 910 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 919 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 937 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 946 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 955 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 964 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 973 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 982 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 991 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1000 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1009 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1018 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1027 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1036 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1045 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1054 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1063 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1072 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1081 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1090 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1099 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1108 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1117 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1126 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1135 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1144 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1153 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1162 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1171 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1180 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1189 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1198 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1207 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1216 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1225 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1234 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1243 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1252 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1261 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1270 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1279 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1288 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1297 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1306 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1315 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1324 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1333 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1342 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1351 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1360 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1369 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1378 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1387 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1396 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1405 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1414 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1423 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1432 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1441 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1450 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1459 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1468 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1477 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1486 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1495 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1504 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1513 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1522 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1531 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1540 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1549 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1558 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1567 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1576 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1585 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1594 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1603 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1612 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1621 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1630 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1639 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1648 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1657 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1666 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1675 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1684 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1693 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1702 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1711 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1720 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1729 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1738 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1747 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1756 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1765 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1774 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1783 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1792 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1801 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1810 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1819 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1828 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1837 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1846 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1855 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1864 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1873 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1882 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1891 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1900 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1909 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1918 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1927 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1936 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1945 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1954 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1963 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1972 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1981 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1990 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1999 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2008 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2017 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2026 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2035 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2044 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2053 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2062 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2071 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2080 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2089 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2098 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2107 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2116 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2125 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2134 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2143 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2152 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2161 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2170 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2179 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2188 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2197 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2206 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2215 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2224 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2233 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2242 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2251 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2260 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2269 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2278 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2287 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2296 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2305 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2314 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2323 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2332 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2341 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2350 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2359 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2368 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2377 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2386 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2395 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2404 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2413 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2422 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2431 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2440 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2449 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2458 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2467 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2476 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2485 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2494 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2503 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2512 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2521 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2530 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2539 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2548 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2557 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2566 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2575 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2584 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2593 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2602 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 613: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2611 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 614: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2620 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 615: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2629 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2638 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2647 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 618: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2656 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 619: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2665 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2674 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2683 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 624: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2692 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 625: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2701 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 626: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2710 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
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
#line 2807 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"

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
#line 1004 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 1013 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 1022 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 1028 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 1036 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 1042 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 1053 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 1058 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 1066 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 1073 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 1080 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 1089 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 1096 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 1104 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 1112 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 1120 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 1131 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 1136 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 1143 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 1150 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 1162 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 1172 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 1179 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 1186 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 1221 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 1226 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 1234 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 1242 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 1250 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 1255 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 1263 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1268 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1276 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1281 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1289 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1296 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1303 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1310 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1325 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1335 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 1340 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 1348 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 1356 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 1367 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1374 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1385 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1390 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1398 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1405 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1412 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1421 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 1434 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1442 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1449 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1459 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 1466 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1473 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 1496 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 1502 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 1511 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 1518 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1528 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1537 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1538 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1539 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1540 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1541 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1542 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1543 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1544 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1545 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1546 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1552 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1560 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1568 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1576 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1583 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1591 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1598 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1603 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1611 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1619 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 1634 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 1649 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 1667 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1672 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1680 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1688 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 1699 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1704 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1713 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1718 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1725 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1730 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1740 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1745 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1754 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1760 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1773 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1778 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1786 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 1797 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 1812 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 1824 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 1839 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1844 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1849 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1854 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1862 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1869 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1880 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1885 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1895 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1902 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1909 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1916 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1926 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1930 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1940 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 1948 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 1959 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1965 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1974 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1979 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1986 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1993 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 2005 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 2015 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 2025 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 2036 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 2052 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 2072 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 2076 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 2080 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 2088 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 2092 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 2096 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 2104 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 2109 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 2121 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 2128 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 2157 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 2162 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 2170 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 2187 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 2195 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 2203 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 2210 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 2217 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 2227 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 2239 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 2252 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 2264 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 2280 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 2288 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 2296 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 2304 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 2319 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 2324 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 2332 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 2346 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 2363 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 2388 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2396 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 2403 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2414 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 2424 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 2429 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 2467 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 2481 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 2489 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 2494 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 2502 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 2507 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 2512 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 2520 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 2529 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 2541 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 2551 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 2564 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2588 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2595 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2605 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 2611 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected QName \"" 
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      YYERROR;
    }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 2622 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 2629 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 2637 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); // to prevent the Bison warning      
      error((yylocation_stack_[(3) - (3)]), "syntax error, unexpected QName \"" 
          + static_cast<VarInDecl*>((yysemantic_stack_[(3) - (3)].node))->get_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      YYERROR;
    }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 2648 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2658 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2668 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2678 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2688 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2698 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2708 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2718 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2729 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2738 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2748 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2758 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2774 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2783 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2792 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2800 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2806 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2818 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2826 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 2836 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 2844 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 2856 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 2862 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 2875 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 2879 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 2887 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2900 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2904 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2908 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2918 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2926 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2933 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2939 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2950 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2954 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2963 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2971 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2977 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 2987 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 2993 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 3003 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 3007 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 3017 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 3023 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 3029 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 3035 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3044 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3053 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3062 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3075 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 3079 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 3087 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 3093 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 3103 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 3111 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3120 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3133 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 3140 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 3152 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 3156 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 3168 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 3175 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 3181 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 3190 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 3197 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 3203 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 3214 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 3221 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 3227 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 3236 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 3245 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 3252 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 3263 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 3270 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 3282 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 3288 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 3300 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 3306 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 3317 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 3323 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 3334 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 3340 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 3351 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 3360 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 3364 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 3373 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 3377 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 3385 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 3389 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3399 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 3406 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3415 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3424 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 3429 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3438 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3447 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3456 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3469 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 3473 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3485 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 3489 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 3496 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 3500 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 3507 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 3511 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 3520 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3524 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3528 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3536 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 3540 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3546 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 3552 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 3558 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3568 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 3572 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 3576 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 3584 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 3588 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3594 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 368:

/* Line 690 of lalr1.cc  */
#line 3604 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3608 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3618 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3622 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3632 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3636 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3646 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3650 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3660 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3664 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3672 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3676 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3680 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3684 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3694 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3698 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3702 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3710 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3714 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3718 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3722 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3726 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3730 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3738 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3742 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3746 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3754 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3758 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3762 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3766 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3777 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3783 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3793 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3799 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3809 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3813 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3817 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3855 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3859 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3869 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3879 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3892 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3901 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 411:

/* Line 690 of lalr1.cc  */
#line 3911 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3915 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3924 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3928 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3937 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3943 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3951 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3957 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3969 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3975 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3985 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3989 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3993 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 3997 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 4001 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 4007 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 4013 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 4021 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 4025 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 4033 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 4037 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 4048 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 4052 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 4056 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 4062 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 4066 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 4080 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 4084 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 4092 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 4096 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 4106 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 4110 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 4114 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 4118 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 4127 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 4131 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 4135 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 4139 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 4147 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 4153 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 4163 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 4171 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 4175 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 4179 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 4183 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 4187 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 4191 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 4195 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 4199 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 4203 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 4213 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 4221 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 4225 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 4233 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 4240 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 4247 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 4258 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 4266 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 4270 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 4278 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 4286 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 4294 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 4348 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 4352 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 4365 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 4371 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 4381 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 4385 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 4393 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 4397 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 4401 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 4409 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 483:

/* Line 690 of lalr1.cc  */
#line 4419 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 484:

/* Line 690 of lalr1.cc  */
#line 4429 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 485:

/* Line 690 of lalr1.cc  */
#line 4446 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 486:

/* Line 690 of lalr1.cc  */
#line 4463 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 487:

/* Line 690 of lalr1.cc  */
#line 4480 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 488:

/* Line 690 of lalr1.cc  */
#line 4502 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 4508 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 4519 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 4525 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 4536 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 4553 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 4558 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 4567 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 4571 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 4578 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 4584 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 4590 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 4598 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 4610 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 4614 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 4621 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 4627 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 4633 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 4640 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 4651 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 4655 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 4665 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 4669 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 4679 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 4683 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 4687 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 4692 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 4701 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 4707 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 4713 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 4719 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 4727 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 4732 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 4740 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 4745 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 4753 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 4761 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 4766 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 4771 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 4776 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 4781 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 4786 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 4795 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 4803 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 4807 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 4824 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 4828 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 4836 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 4844 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 4852 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 4856 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 4864 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 4870 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 4880 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 4888 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 4892 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 4896 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 4931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 4937 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 4943 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 4953 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 4957 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 4961 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 4965 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 4969 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 4976 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 4982 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 4992 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 5000 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 5004 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 5008 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 5012 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 5016 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 5020 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 5024 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 5028 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 5032 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 5040 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 5048 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 5052 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 5056 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 5066 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 5074 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 5082 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 5086 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 5090 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 5098 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 5102 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 5108 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 5114 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 5118 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 5128 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 5136 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 5140 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 5146 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 5155 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 5164 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 5170 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 5176 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 5186 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 5203 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 5210 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 5225 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 5261 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 5265 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 5273 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 5281 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 5293 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 5297 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 5305 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 5313 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 5317 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 5328 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 5345 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 5351 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 5357 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 5367 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 5371 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 5377 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 5383 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 5387 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 5393 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 5397 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 5403 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 5409 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 5416 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 5426 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 5431 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 5439 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 5445 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 5455 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 5477 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 5486 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 5492 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 5505 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 5519 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 5526 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 5532 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 5542 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 5551 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 5559 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 5565 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 5583 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 5591 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 5595 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 5602 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 5607 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 5615 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 5619 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 5626 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 5630 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 5637 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 5641 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 5648 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 5652 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 5661 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 5673 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 5677 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 5684 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 5688 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 5696 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 5704 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 5712 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 5716 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 5723 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 5727 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 5735 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 5746 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 5750 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 5758 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 5770 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 5776 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 5785 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 5789 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 5797 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 5801 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 5805 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 5812 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 5816 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 5823 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 5827 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 5835 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 5839 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 5843 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 5847 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 5851 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 5859 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 5867 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 5879 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 5891 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 5895 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 5899 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 5907 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 5913 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 5923 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 5927 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 5931 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 5935 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 5939 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 5943 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 5947 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 5951 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 5959 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 5963 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 5967 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 5971 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 5979 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 5985 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 5995 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 6005 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 6009 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 6017 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 6027 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 6038 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 6045 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 6049 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 6056 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 6060 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 6067 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 6072 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 6081 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 6090 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 6094 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 6101 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 6105 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 6113 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 6122 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 6129 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 6139 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 6143 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 6150 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 6156 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 6165 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 6169 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 6176 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 6181 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 6193 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 6201 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 6213 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 6221 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 6225 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 6233 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 6237 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 6241 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 6249 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 6257 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 6261 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 6265 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 6269 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 6277 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 6285 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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
#line 6297 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 6301 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 6309 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 6327 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
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

  case 748:

/* Line 690 of lalr1.cc  */
#line 6340 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 6341 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 6342 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 6343 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 6344 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 6345 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 6346 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 6347 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 6348 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 6349 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 6350 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 6351 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 6352 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 6353 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 6354 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 6359 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 6360 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 6361 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 6362 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 6363 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 6364 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 6365 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 6366 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 6367 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 6368 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 6369 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 6370 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 6371 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 6372 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 6373 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 6374 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 6375 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 6376 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 6377 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 6378 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 6379 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 6380 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 6381 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 6382 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 6383 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 789:

/* Line 690 of lalr1.cc  */
#line 6384 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 6385 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 791:

/* Line 690 of lalr1.cc  */
#line 6386 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 792:

/* Line 690 of lalr1.cc  */
#line 6387 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 793:

/* Line 690 of lalr1.cc  */
#line 6388 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 6389 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 6390 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 796:

/* Line 690 of lalr1.cc  */
#line 6391 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 6392 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 798:

/* Line 690 of lalr1.cc  */
#line 6393 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 6394 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 6395 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 6396 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 802:

/* Line 690 of lalr1.cc  */
#line 6397 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 803:

/* Line 690 of lalr1.cc  */
#line 6398 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 6399 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 805:

/* Line 690 of lalr1.cc  */
#line 6400 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 6401 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 6402 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 6403 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 6404 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 6405 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 6406 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 6407 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 6408 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 6409 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 6410 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 6411 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 6412 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 6413 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 6414 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 6415 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 6416 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 6417 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 6418 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 6419 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 6420 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 6421 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 6422 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 6423 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 6424 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 6425 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 6426 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 6427 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 6428 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 6429 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 6430 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 6431 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 6432 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 6433 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 6434 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 6435 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 6436 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 6437 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 6438 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 6439 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 6440 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 6441 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 6442 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 6443 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 6444 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 6445 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 6446 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 6447 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 6448 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 6449 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 6450 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 6451 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 6452 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 6453 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 6454 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 6455 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 6456 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 6457 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 6458 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 6459 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 6460 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 6461 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 6462 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 6463 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 6464 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 6465 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 6466 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 6467 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 6468 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 6469 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 6470 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 6471 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 6472 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 6473 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 6474 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 6475 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 6476 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 6477 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 6478 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 6479 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 6480 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 6481 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 6482 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 6483 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 6484 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 6485 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 6486 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 6487 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 6488 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 6489 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 6490 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 6491 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 6492 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 6493 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 6494 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 6495 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 6496 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 6497 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 6498 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 6499 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 6500 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 6501 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 6502 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 6503 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 6504 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 6505 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 6506 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 6507 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 6508 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 6509 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 6510 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 6511 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 6512 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 6513 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 6514 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 6515 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 6516 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 6517 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 6518 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 6519 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 6520 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 6521 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 6522 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 6523 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 6524 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 6525 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 6526 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 6527 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 6528 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 6529 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 6530 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 6531 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 6532 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 6533 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 6534 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 6535 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 6536 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 6537 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 6538 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 6539 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 6540 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 6541 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 6542 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 6543 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 6544 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 6545 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 6546 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 6547 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 6548 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 6549 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 6550 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 6551 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 6552 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 6553 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 6554 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 6555 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 6556 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 6562 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    {
          // EQName's namespace URI value is whitespace normalized according to the rules for the xs:anyURI type
          std::string uri = "\"" + SYMTAB((yysemantic_stack_[(3) - (1)].sval)) + "\"";
          std::string eqname = SYMTAB(driver.symtab.put_uri(uri.c_str(), uri.size())) + ":" + SYMTAB((yysemantic_stack_[(3) - (3)].sval));
          (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT(eqname.c_str())), true);
        }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 6568 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 11616 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1362;
  const short int
  xquery_parser::yypact_[] =
  {
      2940, -1362, -1362, -1362,  4431,  4431,  4431, -1362, -1362,    11,
      17,    77,    80,   171, -1362, -1362, -1362,   726, -1362, -1362,
   -1362,   216,   268,   728, 13818,   283,   318,   694, -1362,   -48,
   -1362, -1362, -1362, -1362, -1362, -1362,   733, -1362,   328,   353,
   -1362, -1362, -1362, -1362,   232, -1362,   734, -1362,   364,   388,
   -1362,   222, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362,   534,   554, -1362, -1362,
   -1362, -1362,   561,  9199, -1362, -1362, -1362,   714, -1362, -1362,
   -1362,   511, -1362,   732,   748, -1362, -1362, 13224, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362,   665, -1362, -1362,   766,
     770, -1362, -1362, -1362, -1362, -1362, -1362, -1362,  3239,  6219,
   13224, -1362, -1362, -1362, -1362, -1362, -1362, -1362,   697, -1362,
   -1362,   777, 10083, -1362, 10374,   783,   790, -1362, -1362, -1362,
     793, -1362,  8603, -1362, -1362, -1362, -1362, -1362, -1362,   767,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,    26,   601,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,   -78,   778,
     474, -1362,   711,   594, -1362, -1362, -1362, -1362, -1362, -1362,
     822, -1362,   698,   701,   703, -1362, -1362,   786,   794, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362,  4729,   943, -1362,  5027, -1362, -1362,   372,    71,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362,    76, -1362, -1362, -1362, -1362, -1362,
   -1362,    85, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
    4431, -1362, -1362, -1362, -1362,    31, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362,   839, -1362,   758, -1362, -1362, -1362,
     276, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,   784,
     857, -1362,   909,   704,   851,   435,   456,   123,   643, -1362,
     904,   756,   855,   856,  7411, -1362, -1362, -1362,   448, -1362,
   -1362,  8901, -1362,   600, -1362,   803,  9199, -1362,   803,  9199,
   -1362, -1362, -1362,   686, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362,   840,   817,   807, -1362,
   -1362, -1362, -1362, -1362,   781, -1362,  4431,   785,   787,   299,
     299,   935,   538,   573,   396, 13509, 13224,   -38,   919, 13224,
     815,   854,   288, 10083,   681,   729, 13224, 13224,   674,   702,
      21, -1362, -1362, -1362, 10083,  4431,   788,  4431,    41,  7709,
   10944, 13224,   693,   695, 13224,   861,    46,   827,  7709,   980,
      53,    56, 13224,   865,   842,   878, -1362,  7709,  9790, 13224,
   13224, 13224,  4431,   799,  7709,  7709, 13224,  4431,   834,   835,
   -1362, -1362, -1362,  7709, 11229, -1362,   833, -1362,   837, -1362,
   -1362, -1362, -1362,   838, -1362,   841, -1362, -1362, -1362, -1362,
   -1362,   843, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, 13224,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362,   848, 13224, -1362, -1362, -1362,   812,  3537,   845,
     846,   847, 13224,  4431, -1362,   852,    61, -1362,   278,   956,
    7709, -1362, -1362,    89, -1362, -1362, -1362,   987, -1362, -1362,
   -1362, -1362,  7709,   795, -1362,   981,  7709,  7709,   825,  7709,
    7709,  7709,  7709,   789, 13224,   824,   826,  7709,  7709,  3239,
     771, -1362, -1362, -1362, -1362,    80,   694,    78,    79,  1015,
    5325,  5325,  5623,  5623,   511, -1362, -1362,   839,   511, -1362,
    7709, -1362,   902,   312,   -48,   853,   858,   859,  4431,  7709,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,  8007,  8007,
    8007, -1362,  8007,  8007, -1362,  8007, -1362,  8007, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362,  8007,  8007,   952,  8007,  8007,
    8007,  8007,  8007,  8007,  8007,  8007,  8007,  8007,  8007,  8007,
     797,   929,   930,   931, -1362, -1362, -1362,  6517, -1362, -1362,
    8603,  8603,  7709,   803, -1362, -1362,   803, -1362,  6815,   803,
   10083,   881,  7113, -1362, -1362, -1362, -1362,   194, -1362,   204,
   -1362, -1362, -1362, -1362, -1362,   924,   926,   283,  1006, -1362,
   -1362, 13509,   992,   574, 13224,   876,   877,   992,   935,   911,
     907, -1362, -1362, -1362,   134,   798,   950,   747, 13224,   915,
    7709,   933, 13224, 13224, -1362,   921,   874,  4431, -1362,   879,
     837,   353, -1362,   880,   882,   153, -1362,   231,   239,   958,
   -1362,    19, -1362, -1362,   958, 13224,    -2, 13224,   974,   247,
   -1362,  4431, -1362,   272, -1362, 10083,   986,  1025, 10083,   935,
     988,   548, 13224,  7709,   -48,   196,   896, -1362,   898,   900,
     903,    15, -1362,    47,   905, -1362,   279,   301,   939, -1362,
     910,  4431,  4431,   201, -1362,   329,   344,   550,  7709,    18,
   -1362, -1362,  7709,  7709,  7709, -1362,  7709, -1362,  7709, 13224,
     956, -1362,     4,   270, -1362, -1362, -1362,   331, -1362,   327,
   -1362, -1362, -1362,    -6,   141,   999,   860,   871,   -17, -1362,
     955, -1362, -1362,   908,   392,  3835,   383,  9497,   771, -1362,
     372,   672,  1066,  1066, -1362, -1362,    82, -1362, -1362,    83,
   -1362,    40, -1362, -1362, -1362, -1362, -1362, -1362, -1362, 13224,
     934,  7709,   982, -1362, -1362, -1362,   857, -1362, -1362, -1362,
   -1362, -1362,  8007, -1362, -1362, -1362,    52, -1362,   456,   456,
     -19,   123,   123,   123,   123,   643,   643, -1362, -1362, 12369,
   12369, 13224, 13224, -1362,   384, -1362, -1362,   210, -1362, -1362,
   -1362,   399, -1362, -1362, -1362,   400,   299, -1362, -1362,   575,
     587,   576, -1362,   283, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362,   992, -1362,   969, 12654,   961,  7709,
   -1362, -1362, -1362,  1011,   935,   935,   992, -1362,   780,   935,
     582, 13224,   285,   345,  1077, -1362, -1362,   823,    48, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
     134,   560,   883,   450,  7709, -1362, 13224,  1013,   821,   935,
   -1362, -1362, -1362, -1362,   957, 13224, -1362, 13224, -1362, 12939,
     991, 12369,  1003,  7709,    23,   975,    13,   408,   870, -1362,
   -1362,   608,    -2,  1011, 12369,  1007,  1030,   942,   932,   995,
     935,   968,   998,  1035,   935,  7709,   -53, -1362, -1362, -1362,
     979, -1362, -1362, -1362, -1362,  1016,  7709,  7709,   989, -1362,
    1033,  1037,  4431, -1362,   951,   959,   993, 13224, -1362, 13224,
   -1362,  7709,   997,   954,  7709,   422,   423,   430,  1105, -1362,
      90, -1362,    84, -1362, -1362,  1112, -1362,   663,  7709,  7709,
    7709,   673,  7709,  7709,  7709,  7709,  7709,  7709,  1024,  7709,
    7709, -1362,  5921,   994,   996,  1000,  1001,   758,   386,   901,
   -1362,   151, -1362,    91,   142,    40,  5623,  5623,  5623,  1069,
   -1362,  7709,   661,  1046, -1362, 13224,  1048, -1362, -1362,  7709,
      52,   514,   492, -1362,   875,   646,   912,   899, -1362, -1362,
     729, -1362,   906,   526,  1008,  1010, 12654,  1012, -1362,   -18,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,  1023,
   -1362, -1362, -1362,  7709, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362,   645, -1362,  1141,   735, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362,   886, -1362, -1362,  1144,
   -1362, -1362, -1362, -1362, -1362,   541,  1146, -1362,   612, -1362,
   -1362, -1362,   833,   268,   838,   328,   841,   843,   778, -1362,
     -18,  8305,   890,   872, -1362,  1011,   560,   953,   990,  4431,
    1002,  1004,  1034,  1005,  1018, 13224, -1362,   223, -1362, 13224,
   -1362,  7709,  1036,  7709,  1054,  7709,    42,  1039,  7709,  1040,
   -1362,  1064,  1072,  7709, 13224,   820,  1107, -1362, -1362, -1362,
   -1362, -1362, -1362, 12369, -1362,  4431,   935,  1087, -1362, -1362,
   -1362,   935,  1087, -1362,  7709,  1053,  4431, 13224, -1362, -1362,
    7709,  7709,   690, -1362,    -9,   706, -1362, 11514,   720, -1362,
     721, -1362,  1019, -1362, -1362,  4431,  1020,  1021, -1362,  7709,
   -1362, -1362,  1009,  1033,  1097, -1362,  1067, -1362,   525, -1362,
   -1362,  1202, -1362, -1362,  4431, 13224, -1362,   655, -1362, -1362,
   -1362,  1022,   984,  1014, -1362, -1362, -1362,  1017,  1026, -1362,
   -1362, -1362, -1362, -1362,   977, 13224,  1028, -1362, -1362,  7709,
    7709,  7709,  4133,  5921,  9497,   901, -1362,  9497, -1362,  1066,
     370, -1362, -1362, -1362,  1046, -1362,   935, -1362,   782, -1362,
     507,  1114, -1362,  7709,  1116,   982,   432,  1031, -1362,    52,
     962, -1362, -1362,   -88, -1362,   428,    28,   976,    52,   428,
    8007, -1362,   136, -1362, -1362, -1362, -1362, -1362, -1362,    52,
    1079,   946,   798,    28, -1362, -1362,   945,  1150, -1362, -1362,
   -1362, 10659,  1044,  1045,  1050, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362,  1195,   -26,  1204,
     -26,   965,  1131, -1362,  1070, 13224,   983, -1362, -1362,  8305,
   -1362,  1057, -1362, -1362, -1362, -1362, -1362, -1362,  7709,  1100,
   -1362, -1362,  7709, -1362,   367, -1362,  7709,  1101,  7709, -1362,
    7709, 13224, 13224, -1362,   648, -1362,  7709, -1362,  1118,  1124,
    1155,   935,  1087, -1362,  7709,  1068, -1362, -1362, -1362,  1071,
   -1362,    29,  7709,  4431,  1074,    32, -1362, 13224,  1075, 11799,
     203, -1362, 12084,  1081, -1362, -1362,  1080, -1362, -1362, -1362,
    7709,   722,  1105, 13224,   671, -1362,  1084,  1105, 13224, -1362,
   -1362,  7709,  7709,  7709,  7709,  7709, -1362,  7709,   433,   445,
     449,   183, -1362, -1362, -1362, -1362, -1362,  1114, -1362, -1362,
   -1362,   935, -1362, -1362, -1362, -1362, -1362,  1088,  8007, -1362,
   -1362, -1362, -1362, -1362,   354,  8007,  8007,   491, -1362,   912,
   -1362,   387, -1362,   899,    52,  1102, -1362, -1362,  1027, -1362,
   -1362, -1362, -1362,  1159,  1086, -1362,   453, -1362, -1362, -1362,
   -1362,   220,   220, -1362,   -26, -1362, -1362,   454, -1362,  1225,
      28,  1160,  1091,  8305,   -14,  1029,  1104, -1362, -1362,  7709,
   -1362,  7709,  1128, -1362,  7709, -1362, -1362, -1362,  1227, -1362,
   -1362,  5921,  7709,   935, -1362, -1362, -1362,  7709,  7709, -1362,
   -1362, -1362,  5921,  5921,  1187,  4431, 13224,  1096, 13224,  7709,
   13224,  1098,  5921, -1362,   457,    12,  1105, 13224, -1362,  1092,
    1105, -1362, -1362, -1362, -1362, -1362, -1362,  1090,  1033,  1037,
    7709, -1362, -1362, -1362, -1362,   123,  8007,  8007,   -19,   536,
   -1362, -1362, -1362, -1362, -1362, -1362,  7709, -1362, 12369, -1362,
   12369,  1189, -1362, -1362, -1362,  1260, -1362, -1362, -1362,  1032,
    1184, -1362, -1362,  1185, -1362,   705, 13224,  1175,  1076, 13224,
    8305, -1362, -1362,  7709, -1362,  1176, -1362, -1362,  1087, -1362,
   -1362, 12369, -1362, -1362,  1201,  7709,  1113, -1362,  1207,  5921,
   -1362, 13224,   218,   297, -1362,  1106,  1105, -1362,  1109,  5921,
     730,   467,   -19,   -19,  8007,   469, -1362, -1362, 12369, -1362,
   -1362,  1160,  8305, -1362,  1114,  1038, 13224,  1180,  1083,  1185,
   -1362, 13224,  1117, 12369,  4431, 12369,  1122, -1362, -1362,  1217,
     684, -1362, -1362, -1362, -1362,  1129,   723, -1362, -1362, -1362,
    1115, -1362,  1196, -1362,   -19, -1362, -1362, -1362, -1362, -1362,
    7709,  1041, 13224,  1198, -1362,  4431,  1127, -1362, -1362,  1132,
    7709, -1362, -1362, -1362, -1362, -1362, -1362, -1362, 13224, -1362,
    1042,  1043, 13224, -1362, -1362,  7709,  5921,  1133,  1047,  7709,
    1049,  5921,  8305, -1362,  8305, -1362,  1123,  1051, 13224,  1099,
    1206, 13224,  1052,  8305, -1362
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       159,   442,   443,   444,   162,   162,   162,   764,   963,   116,
     118,   592,   856,   865,   805,   769,   767,   749,   857,   860,
     812,   773,   750,   751,     0,   866,   753,   863,   834,   814,
     789,   809,   810,   861,   858,   808,   755,   864,   756,   757,
     905,   917,   904,   806,   825,   819,   758,   807,   760,   759,
     906,   843,   844,   811,   786,   927,   928,   929,   930,   931,
     932,   933,   934,   935,   936,   937,   951,   958,   833,   829,
     820,   800,   748,     0,   828,   836,   845,   952,   824,   464,
     801,   802,   859,   953,   959,   821,   838,     0,   470,   431,
     466,   831,   766,   822,   823,   852,   826,   842,   851,   957,
     960,   772,   813,   854,   465,   841,   847,   752,     0,     0,
       0,   379,   839,   850,   855,   853,   832,   818,   907,   816,
     817,   954,     0,   378,     0,   955,   961,   848,   803,   827,
     956,   409,     0,   441,   849,   830,   837,   846,   840,   908,
     794,   799,   798,   797,   796,   795,   761,   815,     0,   765,
     862,   787,   896,   895,   897,   771,   770,   790,   902,   754,
     894,   899,   900,   891,   793,   835,   893,   903,   901,   892,
     791,   898,   912,   913,   910,   911,   909,   762,   914,   915,
     916,   882,   881,   868,   785,   778,   875,   871,   788,   784,
     883,   884,   774,   775,   768,   777,   880,   879,   876,   872,
     889,   890,   888,   878,   874,   867,   776,   887,   886,   780,
     782,   781,   873,   877,   869,   783,   870,   779,   885,   938,
     939,   940,   941,   942,   943,   919,   920,   918,   924,   925,
     926,   921,   922,   923,   792,   944,   945,   946,   947,   948,
     949,   950,   159,     0,     2,   159,     5,     7,    19,     0,
      24,    27,    32,    33,    34,    35,    36,    37,    38,    28,
      54,    55,    29,    30,     0,    72,    75,    76,    31,    77,
      78,     0,   114,    79,    80,    81,    82,    14,   156,   157,
     158,   165,   167,   461,   168,     0,   169,   170,   171,   172,
     173,   174,   175,   178,   163,   204,   211,   206,   233,   239,
       0,   231,   232,   213,   207,   177,   208,   176,   209,   212,
     332,   334,   336,   346,   348,   352,   354,   357,   362,   365,
     368,   370,   372,   374,     0,   376,   382,   384,     0,   400,
     383,   405,   408,   410,   413,   415,     0,   420,   417,     0,
     428,   438,   440,   414,   445,   452,   462,   453,   454,   455,
     458,   459,   456,   457,   477,   479,   480,   481,   478,   526,
     527,   528,   529,   530,   531,   437,   566,   558,   565,   564,
     563,   560,   562,   559,   561,   463,   460,   593,   594,    39,
     214,   215,   217,   216,   218,   210,     0,   439,   747,   763,
     856,   865,   863,   765,     0,   160,   161,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   122,   124,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   260,   261,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     433,   436,   423,     0,     0,   744,   749,   773,   751,   804,
     866,   753,   814,   755,   825,   758,   760,   759,   843,   951,
     958,   748,   952,   802,   953,   959,   826,   957,   960,   907,
     954,   955,   961,   956,   908,   902,   894,   900,   891,   791,
     912,   913,   910,   762,   914,   429,   439,   747,   421,     0,
     185,   422,   425,   749,   750,   751,   755,   756,   757,   758,
     748,   754,   467,     0,   427,   426,   180,     0,     0,   753,
     760,   759,     0,   162,   468,   914,     0,   211,     0,   493,
       0,   432,   745,     0,   746,   403,   404,     0,   435,   434,
     424,   407,     0,     0,   522,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     3,     1,     6,     8,     0,     0,     0,     0,     0,
     159,   159,   159,   159,     0,   115,   166,   164,     0,   183,
       0,   192,     0,     0,     0,     0,     0,     0,     0,     0,
     197,   219,   238,   234,   240,   235,   237,   236,     0,     0,
       0,   393,     0,     0,   391,     0,   341,     0,   392,   385,
     390,   389,   388,   387,   386,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   381,   380,   377,     0,   401,   406,
       0,     0,     0,   416,   449,   419,   418,   430,     0,   446,
       0,     0,     0,   533,   535,   539,   592,     0,   120,     0,
      43,    40,    41,    44,    45,     0,     0,     0,     0,    46,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   603,   604,   605,     0,    99,   138,     0,     0,   108,
       0,     0,     0,     0,   123,     0,     0,     0,   572,     0,
       0,     0,   568,     0,     0,     0,   582,     0,     0,   242,
     243,     0,   221,   222,   241,     0,     0,     0,   130,     0,
     134,   162,   596,     0,    56,     0,    65,     0,     0,     0,
      57,     0,     0,     0,     0,     0,   744,   573,     0,     0,
       0,     0,   305,     0,     0,   571,     0,     0,     0,   590,
       0,     0,     0,     0,   576,     0,     0,   187,     0,     0,
     181,   179,     0,     0,     0,   467,     0,   469,     0,   494,
     493,   490,     0,     0,   524,   523,   402,     0,   521,     0,
     616,   617,   567,     0,     0,     0,     0,     0,     0,   622,
       0,   195,   196,     0,     0,     0,     0,     0,   200,   201,
      20,     0,    21,     0,     4,    25,     0,    11,    26,     0,
      15,   856,    73,    12,    74,    16,   186,   184,   205,     0,
       0,     0,     0,   198,   220,   278,   333,   335,   339,   345,
     344,   343,     0,   340,   337,   338,     0,   349,   356,   355,
     353,   359,   360,   361,   358,   363,   364,   367,   366,     0,
       0,     0,     0,   398,     0,   411,   412,     0,   450,   447,
     475,     0,   962,   595,   473,     0,     0,   117,   119,     0,
       0,     0,    98,     0,    88,    90,    91,    92,    93,    95,
      96,    97,    89,    94,    84,    85,     0,     0,   104,     0,
     100,   102,   103,   110,     0,     0,    83,    42,     0,     0,
       0,     0,     0,     0,     0,   694,   699,     0,     0,   695,
     729,   682,   684,   685,   686,   688,   690,   689,   687,   691,
       0,     0,     0,     0,     0,   107,     0,   140,     0,     0,
     538,   532,   569,   570,     0,     0,   586,     0,   583,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   223,
     224,     0,   229,   136,     0,     0,   131,     0,     0,     0,
       0,     0,     0,    58,     0,     0,     0,   259,   265,   262,
       0,   575,   574,   581,   589,     0,     0,     0,     0,   537,
       0,     0,     0,   394,     0,     0,     0,     0,   579,     0,
     577,     0,   188,     0,     0,     0,     0,     0,   493,   491,
       0,   482,     0,   471,   472,     0,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   193,     0,   753,   760,   759,   914,     0,     0,     0,
     630,     0,   202,     0,     0,     0,   159,   159,   159,     0,
     230,     0,   289,   285,   287,     0,   279,   280,   342,     0,
       0,     0,     0,   660,   350,   633,   637,   639,   641,   643,
     646,   653,   654,   662,   866,   752,     0,   761,   369,   544,
     550,   551,   553,   597,   598,   554,   557,   371,   373,   541,
     375,   399,   451,     0,   448,   474,   121,    52,    53,    50,
      51,   127,   126,     0,    86,     0,     0,   105,   106,   111,
      70,    71,    48,    49,    69,   700,     0,   703,   730,     0,
     693,   692,   697,   696,   728,     0,     0,   705,     0,   701,
     704,   683,     0,     0,     0,     0,     0,     0,     0,   139,
     142,     0,     0,     0,   109,   112,     0,     0,     0,   162,
       0,     0,   590,     0,     0,     0,   245,     0,   543,     0,
     246,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     225,     0,     0,     0,     0,   272,     0,   269,   274,   228,
     137,   132,   135,     0,   182,     0,     0,    67,    61,    64,
      63,     0,    59,   263,     0,     0,   162,     0,   303,   307,
       0,     0,     0,   310,     0,     0,   316,     0,     0,   323,
       0,   327,     0,   396,   395,   162,     0,     0,   189,     0,
     191,   304,     0,     0,     0,   494,     0,   483,     0,   517,
     514,     0,   518,   519,     0,     0,   513,     0,   488,   516,
     515,     0,     0,     0,   609,   610,   606,     0,     0,   614,
     615,   611,   620,   618,     0,     0,     0,   624,   194,     0,
       0,     0,     0,     0,     0,   625,   626,     0,   203,    22,
       0,    13,    17,    18,   286,   298,     0,   299,     0,   290,
     291,   292,   293,     0,   282,     0,     0,     0,   644,   657,
       0,   347,   351,     0,   676,     0,     0,     0,     0,     0,
       0,   632,   634,   635,   671,   672,   673,   675,   674,     0,
       0,   648,   647,     0,   651,   655,   669,   667,   666,   659,
     663,     0,     0,     0,     0,   547,   549,   548,   545,   542,
     476,   129,   128,    87,   101,   717,   698,     0,   722,     0,
     722,   711,   706,   143,     0,     0,     0,   113,   141,     0,
      23,     0,   587,   588,   591,   584,   585,   244,     0,     0,
     258,   250,     0,   254,     0,   248,     0,     0,     0,   267,
       0,     0,     0,   227,   270,   273,     0,   133,     0,     0,
      66,     0,    60,   264,     0,     0,   306,   308,   313,     0,
     311,     0,     0,     0,     0,     0,   317,     0,     0,     0,
       0,   324,     0,     0,   328,   397,     0,   580,   578,   190,
       0,     0,   493,     0,     0,   525,     0,   493,     0,   489,
      10,     0,     0,     0,     0,     0,   623,     0,     0,     0,
       0,     0,   627,   631,   302,   300,   301,   294,   295,   296,
     288,     0,   283,   281,   661,   652,   658,     0,     0,   731,
     732,   742,   741,   740,     0,     0,     0,     0,   733,   638,
     739,     0,   636,   640,     0,     0,   645,   649,     0,   670,
     665,   668,   664,     0,     0,   555,     0,   552,   602,   546,
     718,     0,     0,   716,   723,   724,   720,     0,   715,     0,
     713,     0,     0,     0,     0,     0,     0,   534,   247,     0,
     256,     0,     0,   252,     0,   255,   268,   276,   277,   271,
     226,     0,     0,     0,    62,   266,   540,     0,     0,   314,
     318,   312,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   536,     0,     0,   493,     0,   520,     0,
     493,   607,   608,   612,   613,   619,   621,     0,     0,     0,
       0,   628,   297,   284,   656,   743,     0,     0,   735,     0,
     681,   680,   679,   678,   677,   642,     0,   734,     0,   599,
       0,     0,   727,   726,   725,     0,   719,   712,   710,     0,
     707,   708,   702,   144,   146,   148,     0,     0,     0,     0,
       0,   251,   249,     0,   257,     0,   199,   331,    68,   309,
     315,     0,   329,   325,     0,     0,     0,   319,     0,     0,
     321,     0,   503,   497,   492,     0,   493,   484,     0,     0,
       0,     0,   737,   736,     0,     0,   600,   556,     0,   721,
     714,     0,     0,   150,   149,     0,     0,     0,     0,   145,
     253,     0,     0,     0,     0,     0,     0,   511,   505,     0,
     504,   506,   512,   509,   499,     0,   498,   500,   510,   486,
       0,   485,     0,   629,   738,   650,   601,   709,   147,   151,
       0,     0,     0,     0,   275,     0,     0,   322,   320,     0,
       0,   496,   507,   508,   495,   501,   502,   487,     0,   152,
       0,     0,     0,   330,   326,     0,     0,     0,     0,     0,
       0,     0,     0,   154,     0,   153,     0,     0,     0,     0,
       0,     0,     0,     0,   155
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1362, -1362,  -220,  1085, -1362,  1093,  1094, -1362,  1082,  -517,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
    -929, -1362, -1362, -1362, -1362,  -218,  -566, -1362,   633,   -92,
   -1362, -1362, -1362, -1362, -1362,   219,   424, -1362, -1362,   -11,
    -198,   936, -1362,   913, -1362, -1362,  -608, -1362,   366, -1362,
     189, -1362,  -250,  -291, -1362,  -523, -1362,    14,    94,    70,
    -246,  -175, -1362,  -829, -1362, -1362,   197, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362,   535,   -99,  1273,
       0, -1362, -1362, -1362, -1362,   382, -1362, -1362,  -289, -1362,
       8, -1362,   914,  -878,  -685,  -689, -1362, -1362,   602, -1362,
   -1362,   -25,   175, -1362, -1362, -1362,    66, -1362, -1362,   302,
      72, -1362, -1362,    81, -1241, -1362,   836,   159, -1362, -1362,
     156,  -953, -1362, -1362,   155, -1362, -1362, -1196, -1175, -1362,
     152, -1362, -1362,   757,   755, -1362,  -470,   738, -1362, -1362,
    -629,   233,  -610,   277,   280, -1362, -1362, -1362, -1362, -1362,
    1055, -1362, -1362, -1362, -1362,  -804,  -321, -1090, -1362,  -101,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362,   -27,  -766, -1362,
   -1362,   542,   215, -1362,  -373, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362,   708, -1362,  -974, -1362,   140, -1362,   591,  -765,
   -1362, -1362, -1362, -1362, -1362,  -284,  -276, -1176,  -903, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,   513,
    -732,  -675,   236,  -832, -1362,    69,  -201, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362,   949,   960,  -261,   431,   275, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362,   126, -1362, -1362,   117, -1362,   120, -1010,
   -1362, -1362, -1362,    87,    86,   -77,   325, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
      88, -1362, -1362, -1362,   -72,   321,   462, -1362, -1362, -1362,
   -1362, -1362,   266, -1362, -1362, -1361, -1362, -1362, -1362,  -549,
   -1362,    57, -1362,   -85, -1362, -1362, -1362, -1362, -1190, -1362,
      97, -1362,  -339,  -370,  1078,    62, -1362
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   243,   813,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
    1187,   739,   261,   262,   263,   264,   265,   266,   894,   895,
     896,   267,   268,   269,   900,   901,   902,   270,   419,   271,
     272,   667,   273,   421,   422,   423,   437,   729,   730,   274,
    1139,   275,  1583,  1584,   276,   277,   278,   527,   279,   280,
     281,   282,   283,   732,   284,   285,   510,   286,   287,   288,
     289,   290,   291,   600,   292,   293,   808,   809,   294,   295,
     537,   297,   601,   435,   961,   962,   298,   602,   299,   604,
     538,   301,   719,   720,  1175,   444,   302,   445,   446,   726,
    1176,  1177,  1178,   605,   606,  1056,  1057,  1442,   607,  1053,
    1054,  1279,  1280,  1281,  1282,   303,   751,   752,   304,  1202,
    1203,  1391,   305,  1205,  1206,   306,   307,  1208,  1209,  1210,
    1211,   308,   309,   310,   311,   842,   312,   313,  1291,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   625,   626,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   653,   654,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   871,   353,   354,   355,  1237,   780,   781,   782,
    1614,  1655,  1656,  1649,  1650,  1657,  1651,  1238,  1239,   356,
     357,  1240,   358,   359,   360,   361,   362,   363,   364,  1088,
     956,  1078,  1328,  1079,  1476,  1080,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   758,  1151,   375,   376,
     377,   378,  1082,  1083,  1084,  1085,   379,   380,   381,   382,
     383,   384,   798,   799,   385,  1265,  1266,  1551,  1041,  1064,
    1301,  1302,  1065,  1066,  1067,  1068,  1069,  1311,  1466,  1467,
    1070,  1314,  1071,  1447,  1072,  1073,  1319,  1320,  1472,  1470,
    1303,  1304,  1305,  1306,  1563,   695,   921,   922,   923,   924,
     925,   926,  1129,  1492,  1580,  1130,  1490,  1578,   927,  1340,
    1487,  1483,  1484,  1485,   928,   929,  1307,  1315,  1457,  1308,
    1453,  1292,   386,   543,   387,   388,   389
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int xquery_parser::yytable_ninf_ = -805;
  const short int
  xquery_parser::yytable_[] =
  {
       296,   420,   850,   570,   296,   296,   296,   648,   300,   976,
     536,   603,   300,   300,   300,  1010,   822,   824,   394,   397,
     398,   988,   851,   852,   853,   854,   668,   668,  1411,   581,
     578,   551,   955,  1401,   586,  1002,   954,  1204,  1236,  1438,
    1439,  1040,  1062,   690,   583,  1192,   505,     9,    10,  1164,
    1287,  1344,  1102,   958,   705,   950,   553,   817,   820,   823,
     825,  1419,   670,   815,   818,  1106,     9,    10,   405,   881,
     442,  1156,   579,   585,   396,   396,   396,   579,   748,   579,
     579,   666,   465,   579,   579,   465,   710,   405,  1017,  1194,
    1028,  1392,   579,  1229,  1230,   408,   406,   784,   395,   395,
     395,   736,   740,   711,  1586,  1612,     9,    10,   296,   952,
    1481,     9,    10,   951,   408,   952,   300,   401,   402,   409,
     403,   404,   985,  1468,  1454,   985,  1325,   405,  1449,  1392,
    1581,   679,  1392,   701,  1011,   507,   406,   407,   588,   629,
     838,   951,   839,   840,  1126,   841,   556,   843,   557,   507,
     586,   410,   411,  1049,   408,   844,   845,   630,  1326,   409,
    1165,  1127,    79,   680,   727,  1450,   953,   399,   590,   737,
    1161,  1109,   507,   400,  1482,  1327,    90,  1393,   528,   401,
     402,   587,   403,   404,   507,  1087,   507,  1231,   910,  1366,
     911,   410,   411,   412,   987,  1613,  1552,   584,  -744,   407,
    1012,   104,   395,   986,  1128,  1059,  1004,  1232,  1060,  1233,
    1587,  1018,  1019,   735,   959,  1518,   738,  1029,  1523,   443,
    1227,   589,   585,  1647,   443,  1169,  1020,  1229,   712,   124,
     649,  1180,  1293,   728,   912,  1021,  1401,  1234,  1419,   554,
     413,   110,   296,  1226,  1323,   296,   822,   824,   777,   603,
     300,   960,  1395,   300,  1236,  1270,  1062,  1062,   122,  1496,
     590,   580,  1382,  1236,   785,  1162,   582,  1167,   810,   812,
    1667,  1166,  1046,  1048,  1332,  1103,  1158,  1357,  1235,  1446,
     296,  1269,   586,  1455,  1456,   443,  1228,  1195,   300,  1181,
     872,   443,  1588,   815,   818,   443,   148,   587,   456,   414,
    1579,   876,   413,   590,  1262,  1294,  1229,   702,   590,   655,
    1061,   876,   657,   431,   443,   703,  1337,   590,   592,   952,
     592,  1528,   593,   636,   593,  1653,   416,   594,   666,   594,
     715,   424,   637,   685,   417,   686,  1550,   944,   945,   733,
     415,  1232,   418,  1233,  1633,   595,   947,   595,   745,   907,
     451,  1648,   833,  1620,   965,   756,   757,   811,  1022,  1023,
    1267,   414,   816,   819,   763,   969,   416,   687,   972,   427,
    1358,  1234,  1058,  1024,   417,   457,  1339,   590,   432,   590,
     980,   877,   418,   433,   913,   996,   590,  1295,  1296,  1529,
    1297,   878,  1267,  1669,   688,  1092,   296,   914,   507,   915,
     973,   507,   415,  1585,   300,   575,  1556,  1299,   590,    79,
     916,   917,   918,  1347,   919,   685,   920,   686,   946,  1300,
    1232,   576,  1233,    90,   428,   296,   948,   296,   592,   587,
     434,  1654,   593,   300,   966,   300,   997,   594,   590,   436,
    1236,   783,   458,   459,   596,  1401,   596,   597,   104,   597,
    1234,   999,   296,   787,  1013,   595,   689,   296,  1015,   968,
     300,   586,   598,   952,   778,   300,   990,   677,   507,   804,
     806,   507,  1359,  1063,   438,   507,   688,  1367,   507,   507,
     822,   824,   822,  1557,   449,  1062,   507,   599,   991,   599,
     590,   590,   507,   507,  1062,   707,   507,   707,  1040,   590,
    1585,  1433,   951,  1096,   507,  1062,  1093,  1093,  1377,   450,
     507,   507,   507,   507,  1501,  1014,   998,  1016,   507,   706,
     454,   709,   707,  1271,  1272,  1273,   507,   707,   296,   590,
     590,  1000,  1398,   296,  1229,  1230,   300,   590,   689,   590,
     590,   300,  1585,   666,   455,   629,   754,  1120,   864,   865,
     866,   760,   590,   867,   596,  1168,   590,   597,  1121,   586,
    1570,  1575,   675,   630,   420,  1110,  1111,  1039,  1091,   296,
    1114,   507,  1263,   632,   590,  1611,   590,   300,   676,  1032,
     296,   296,   296,   296,  1598,   507,  1094,  1095,   300,   300,
     300,   300,  1043,   629,   507,  1395,  1047,   599,   296,  1132,
    1148,   647,   633,   396,  1133,   710,   300,  1122,   587,  1222,
    1223,   630,  1705,  1276,  1706,   634,  1444,  1224,  1123,  1134,
    1547,  1135,   711,  1714,    79,   124,   507,   395,  1231,   509,
    1136,  1188,  1548,   631,  1278,  1188,  1549,  1337,    90,   805,
    1571,  1576,   951,  1529,   951,  1289,  1475,  1535,  1232,   635,
    1233,  1663,  1539,  1665,  1338,  1560,   460,  1137,  1081,  1081,
    1062,  1171,  1561,   104,  1229,  1230,  1172,  1059,   897,   124,
    1060,  1461,  1562,  1005,  1006,  1007,   461,   806,  1234,  1502,
    1229,  1230,   110,   462,  1150,  1173,  1153,  1063,  1063,  1647,
     975,   124,  1001,  1229,   629,  1451,  1081,  1339,   559,   122,
     560,  1171,  1452,   822,   952,  1044,  1172,   296,  1126,  1652,
    1658,   898,   630,  1101,   463,   300,   899,   464,   439,  1413,
     671,   576,   507,  1097,  1527,  1127,  1174,  1531,   440,   731,
    1140,   296,  1229,   672,  1624,  1099,  1216,   148,  1217,   300,
    1098,   648,  1293,   883,   952,   967,   507,  1652,  1142,   603,
    1081,  1653,  1100,  1658,   441,   673,  1275,  1143,  1231,  1560,
     507,   296,   296,  1081,   507,   507,  1561,  1276,   674,   300,
     300,  1615,  1316,  1317,  1231,  1618,  1562,  1277,  1232,   638,
    1233,   826,  1331,   523,  1138,   827,  1258,   507,  1278,   507,
    1201,   650,   651,   639,  1232,  1318,  1233,   507,   731,   951,
     507,   396,  1104,  1389,   507,  1037,  1201,  1232,  1234,  1233,
     420,  1276,   110,  1038,  1104,  1294,   555,  1682,   562,  1394,
    1399,  1402,  1399,   563,  1234,   395,  1558,  1559,   110,   122,
    1399,   707,   707,  1400,  1403,  1534,   508,  1234,  1555,   699,
     652,   507,   658,  1662,   700,   122,  1232,  1380,  1233,  1418,
     540,  1660,  1188,  1634,   511,   994,   995,  1685,  1115,  1116,
    1117,   570,   848,   849,  1118,  1537,  1268,   148,   868,   507,
     512,   868,   898,  1171,   868,  1081,  1234,   899,  1172,   425,
     656,   429,   426,   148,   430,   659,   447,   452,   524,   448,
     453,   507,   525,  1626,  1242,  1627,  1243,  1295,  1296,   541,
    1297,   691,   692,   693,  1247,   548,  1248,  1298,  1112,  1113,
    1435,  1436,   549,   855,   856,   550,  1063,  1299,   857,   858,
     552,   507,   507,   507,   507,  1063,  1642,  1622,  1623,  1300,
    1089,  1089,  1572,  1573,   558,   561,  1063,  1434,   565,  1378,
     564,   566,   568,   572,   567,  1140,   590,   569,   591,   609,
     628,   608,   627,  1666,   640,   641,   642,   652,   643,   507,
    1286,   660,   661,   662,   465,   663,   681,   683,  1676,   664,
    1679,   665,   684,   507,   694,   708,   722,   698,   723,   725,
     731,   734,  1081,   742,   743,   744,   755,   761,   762,   426,
     768,   779,   296,   430,   448,  1664,   770,   453,   507,   464,
     300,   772,   773,   774,   786,   776,  1081,   507,   788,   507,
     789,   507,   792,   507,   801,   807,   802,   833,   814,   797,
     829,   830,   846,   860,   861,   862,   507,   859,   831,   832,
     873,   879,  1037,   880,   420,   882,   904,   905,   908,   909,
    1038,   610,  1514,   930,   931,   932,   296,   296,   296,   611,
     612,   936,   613,   939,   300,   300,   300,   934,   940,   507,
     614,   507,   707,   941,   615,   949,   616,   942,   964,   943,
     971,   617,   884,   885,   886,   887,   888,   889,   890,   891,
     892,   893,   970,   981,   974,   982,  1212,   983,   618,   989,
     984,  1063,   992,  1025,   993,  1027,  1026,  1030,  1031,  1045,
    1055,  1105,  1553,   899,  1051,   951,  1124,  1146,  1125,  1141,
    1149,   619,   620,   621,   622,   623,   624,   507,  1157,  1147,
    1081,  1159,  1163,  1170,  1183,   727,  1184,  1186,  1189,  1185,
    1190,  1191,  1196,  1201,  1197,  1213,  1200,  1207,   507,  1219,
    1225,  1241,  1255,  1214,  1220,  1264,  1215,  1520,   687,   296,
    1259,   506,  1260,  1283,  1262,  1285,  1261,   300,  1310,  1290,
    1428,  1429,  1430,  1351,  1321,   522,  1322,  1329,  1324,  1309,
     666,  1335,  1313,  1336,  1188,  1341,  1345,  1346,  1354,  1349,
    1350,  1364,  1371,  1362,  1376,   296,  1368,  1370,   539,  1352,
    1372,  1353,  1355,   300,  1381,  1384,   296,  1399,  1081,  1412,
     544,  1081,   547,  1405,   300,  1356,  1410,  1407,  1408,  1415,
    1385,  1448,  1420,  1425,  1427,   296,  1421,   507,  1445,   396,
    1276,   507,  1441,   300,  1480,  1458,  1464,  1465,  1471,  1406,
    1469,  1477,  1478,  1486,   296,  1489,   507,  1479,  1491,  1495,
    1493,  1497,   300,   395,  1511,   507,  1422,  1499,  1504,  1423,
    1512,  1513,  1516,  1568,  1577,  1566,  1126,  1517,  1424,   507,
    1522,  1525,  1037,  1037,  1533,  1596,   396,  1532,  1538,   507,
    1038,  1038,  1554,  1569,  1590,  1593,  1600,  1520,  1582,  1602,
    1595,  1601,  1605,  1628,  1609,   396,  1610,  1619,  1617,  1629,
     395,  1631,  1632,  1636,  1641,  1643,  1630,   507,  1672,  1644,
    1637,  1645,  1659,  1675,   707,  1661,  1567,  1673,  1680,   395,
    1681,  1687,  1684,  1695,  1688,  1589,  1692,   507,  1696,  1701,
     906,  1707,  1107,  1710,  1711,  1334,   507,   571,  1416,   507,
     577,  1182,   805,   704,  1698,  1348,   669,  1708,   573,   574,
    1639,  1668,  1670,  1042,  1179,  1690,   979,  1699,   724,  1509,
    1375,  1443,  1702,  1274,  1704,  1440,  1386,  1713,  1390,   769,
    1396,  1437,  1404,  1602,   837,   836,   847,  1081,  1414,  1081,
     875,  1009,  1686,  1378,  1683,  1090,  1343,   713,  1154,   646,
    1333,  1426,  1432,   507,  1431,  1459,  1288,  1565,   714,  1564,
    1462,  1312,  1131,   296,  1342,  1463,  1460,  1488,  1677,  1574,
    1081,   300,     0,     0,     0,     0,     0,   507,     0,     0,
       0,     0,     0,     0,   506,     0,     0,   506,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1081,     0,  1693,
       0,     0,     0,   507,   507,     0,     0,     0,     0,     0,
       0,     0,  1081,     0,  1081,     0,     0,     0,     0,     0,
    1693,  1621,     0,     0,     0,  1677,     0,     0,     0,   507,
       0,   507,     0,     0,   507,     0,     0,  1625,     0,     0,
       0,     0,     0,     0,     0,   507,     0,     0,     0,     0,
     507,     0,     0,     0,   678,     0,     0,   682,     0,     0,
       0,   544,     0,     0,   696,   697,     0,     0,     0,     0,
       0,     0,   544,     0,     0,     0,     0,     0,   718,   721,
       0,  1037,   721,     0,     0,     0,     0,     0,     0,  1038,
     741,     0,  1037,  1037,     0,   296,   544,   749,   750,   753,
    1038,  1038,  1037,   300,   759,     0,     0,     0,     0,     0,
    1038,     0,   766,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   767,   507,     0,
     507,     0,   507,     0,     0,     0,     0,     0,     0,   507,
       0,   753,     0,     0,     0,     0,     0,     0,     0,  1037,
     775,     0,     0,     0,     0,     0,     0,  1038,     0,  1037,
       0,     0,     0,     0,     0,     0,     0,  1038,     0,     0,
     507,     0,   507,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   800,     0,   296,     0,     0,     0,   507,     0,
       0,   507,   300,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   507,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   507,     0,   296,     0,     0,     0,     0,
       0,     0,     0,   300,     0,     0,     0,     0,     0,     0,
     507,     0,     0,     0,     0,     0,  1037,     0,   507,     0,
       0,  1037,     0,   507,  1038,   507,     0,   507,     0,  1038,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   507,     0,     0,     0,   544,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     507,     0,     0,     0,   507,     0,     0,     0,     0,     0,
       0,     0,   903,     0,     0,     0,     0,     0,     0,     0,
     507,     0,     0,   507,     0,     0,   933,     0,     0,     0,
     937,   938,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   957,     0,   963,     0,     0,     0,     0,
       0,     0,     0,   544,     0,     0,   544,     0,     0,     0,
     977,     0,     0,     0,     0,     0,     0,     0,     0,   790,
     791,     0,   793,   794,   795,   796,     0,     0,     0,     0,
     803,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1008,     0,     0,
       0,     0,     0,   828,     0,     0,     0,     0,     0,     0,
       0,   834,   835,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   506,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1050,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   870,     0,     0,     0,   870,     0,  1086,  1086,  1086,
    1086,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   935,     0,  1086,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1145,     0,   978,     0,     0,     0,
       0,     0,     0,  1152,     0,  1152,     0,   721,     0,  1086,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1003,  1086,     0,     0,     0,     0,     0,     0,     0,
       0,   834,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   759,     0,   759,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1052,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1284,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1086,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1144,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1160,     0,     0,     0,
       0,     0,     0,   721,     0,     0,     0,  1360,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1193,     0,
       0,     0,  1374,     0,     0,     0,     0,     0,     0,  1198,
    1199,  1086,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1218,   753,     0,  1221,     0,     0,
       0,     0,     0,     0,     0,  1086,     0,     0,     0,     0,
       0,  1244,  1245,  1246,     0,  1249,  1250,  1251,  1252,  1253,
    1254,     0,  1256,  1257,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1417,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1052,     0,     0,     0,     0,     0,
       0,     0,     0,   800,     0,     0,     0,     0,     0,     0,
       0,     0,   506,     0,     0,   506,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1330,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1086,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1494,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1361,     0,  1363,     0,  1365,     0,
       0,  1369,     0,     0,     0,     0,  1373,     0,     0,  1507,
    1508,     0,     0,     0,     0,     0,     0,     0,  1379,     0,
       0,     0,     0,     0,     0,     0,     0,  1383,     0,     0,
       0,     0,     0,  1387,  1388,  1524,     0,  1086,     0,     0,
    1086,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1536,  1409,     0,     0,     0,  1540,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1052,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1604,     0,  1606,     0,  1608,     0,
       0,     0,     0,     0,     0,  1616,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1498,     0,     0,     0,  1500,     0,     0,     0,  1503,
       0,  1505,     0,  1506,     0,     0,  1086,     0,  1086,  1510,
       0,     0,     0,     0,     0,     0,     0,  1515,     0,     0,
       0,     0,     0,     0,  1635,  1519,  1521,  1638,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1086,
       0,     0,     0,  1379,     0,     0,     0,     0,     0,  1646,
       0,     0,     0,     0,  1541,  1542,  1543,  1544,  1545,     0,
    1546,     0,     0,     0,     0,     0,  1086,     0,     0,     0,
       0,     0,     0,     0,  1671,     0,     0,     0,     0,  1674,
       0,  1086,     0,  1086,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1691,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1697,     0,     0,     0,
    1700,     0,  1591,     0,  1592,     0,     0,  1594,     0,     0,
       0,     0,     0,     0,     0,  1597,  1709,     0,     0,  1712,
    1599,  1521,     0,     0,     0,     0,     0,     0,  1603,     0,
       0,     0,  1607,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1640,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1603,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1678,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1689,     0,     0,     0,     0,  1694,     0,
       0,     1,     2,  1678,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,  1694,    11,
       0,     0,  1703,    12,    13,     0,    14,    15,    16,    17,
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
     146,   147,   148,     0,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
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
      67,    68,     0,    69,    70,    71,    72,    73,     0,    74,
      75,    76,     0,     0,    77,    78,     0,     0,     0,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
       0,     0,     0,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,    96,    97,    98,    99,   100,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   108,     0,     0,   109,   110,   111,   112,   113,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,     0,   122,     0,   123,   124,     0,     0,   125,
     126,   127,     0,   526,     0,   128,     0,   129,   130,     0,
     131,   132,   133,     0,   134,     0,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,     0,     0,   146,
     147,   148,     0,   393,   150,   151,   152,   153,   154,   155,
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
     390,   391,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,   392,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,     0,    74,    75,    76,
       0,     0,    77,    78,     0,     0,     0,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,    96,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     108,     0,     0,   109,   110,   111,   112,   113,     0,     0,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
       0,   122,     0,   123,   124,     0,     0,   125,   126,   127,
       0,   771,     0,   128,     0,   129,   130,     0,   131,   132,
     133,     0,   134,     0,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,     0,     0,   146,   147,   148,
       0,   393,   150,   151,   152,   153,   154,   155,   156,   157,
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
       8,     9,    10,     0,    11,     0,     0,     0,   390,   391,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,  1033,   392,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,  1034,  1035,    50,
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
       0,   123,   124,     0,     0,   125,   126,   127,     0,   771,
       0,   128,     0,   129,   130,     0,   131,   132,   133,     0,
     134,     0,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,     0,     0,   146,   147,   148,     0,   393,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,  1036,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,     0,    11,     0,     0,     0,   390,   391,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,  1033,   392,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,  1034,  1035,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,     0,    74,    75,    76,     0,     0,    77,    78,
       0,     0,     0,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,     0,     0,     0,    90,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,    96,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   108,     0,     0,   109,
     110,   111,   112,   113,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,     0,   122,     0,   123,
     124,     0,     0,   125,   126,   127,     0,   526,     0,   128,
       0,   129,   130,     0,   131,   132,   133,     0,   134,     0,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,     0,   146,   147,   148,     0,   393,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,  1036,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,     0,
      11,     0,     0,     0,   390,   391,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
     392,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
       0,    74,    75,    76,     0,     0,    77,    78,     0,     0,
       0,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     0,     0,     0,    90,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,    96,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   108,     0,     0,   109,   110,   111,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,     0,   122,     0,   123,   124,     0,
       0,   125,   126,   127,     0,     0,     0,   128,     0,   129,
     130,     0,   131,   132,   133,     0,   134,     0,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,     0,
       0,   146,   147,   148,     0,   393,   150,   151,   152,   153,
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
       0,     0,    12,    13,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,     0,    74,
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
       0,    69,    70,    71,    72,    73,     0,    74,    75,    76,
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
       0,   393,   150,   151,   152,   153,   154,   155,   156,   157,
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
       8,     9,    10,     0,    11,     0,     0,     0,    12,   391,
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
     143,   144,   145,     0,     0,   146,   147,   148,     0,   393,
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
      10,     0,    11,     0,     0,     0,   821,   391,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,   392,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,     0,    74,    75,    76,     0,     0,    77,    78,
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
     145,     0,     0,   146,   147,   148,     0,   393,   150,   151,
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
      11,     0,     0,     0,   390,   391,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,  1033,
     392,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,  1034,  1035,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
       0,    74,    75,    76,     0,     0,    77,    78,     0,     0,
       0,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     0,     0,     0,    90,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,    96,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   108,     0,     0,   109,   110,   111,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,     0,   122,     0,   123,   124,     0,
       0,   125,   126,   127,     0,     0,     0,   128,     0,   129,
     130,     0,   131,   132,   133,     0,   134,     0,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,     0,
       0,   146,   147,   148,     0,   393,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,  1036,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     0,     0,     0,    11,     0,
       0,     0,   390,   391,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   529,   392,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,   530,   531,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,     0,    74,
      75,    76,     0,     0,    77,    78,     0,     0,     0,    79,
      80,   483,    82,    83,    84,    85,    86,   532,    88,    89,
       0,     0,     0,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,    96,    97,    98,    99,   100,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   533,     0,     0,   109,   110,   111,   112,   113,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,     0,   122,     0,   123,   124,     0,     0,   125,
     126,   127,     0,     0,     0,   128,   534,   129,   130,     0,
     131,   132,   133,     0,   134,     0,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,     0,     0,   146,
     147,   148,     0,   393,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   500,   501,   502,   175,
     176,   503,   535,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     0,     0,     0,    11,     0,     0,     0,
     390,   391,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   529,   392,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,   530,
     531,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,     0,    74,    75,    76,
       0,     0,    77,    78,     0,     0,     0,    79,    80,   483,
      82,    83,    84,    85,    86,   532,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,    96,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     533,     0,     0,   109,   110,   111,   112,   113,     0,     0,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
       0,   122,     0,   123,   124,     0,     0,   125,   126,   127,
       0,   863,     0,   128,     0,   129,   130,     0,   131,   132,
     133,     0,   134,     0,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,     0,     0,   146,   147,   148,
       0,   393,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   500,   501,   502,   175,   176,   503,
     535,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     0,     0,    11,     0,     0,     0,   390,   391,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   529,   392,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,   530,   531,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,     0,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,   483,    82,    83,
      84,    85,    86,   532,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
      96,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   533,     0,
       0,   109,   110,   111,   112,   113,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,     0,   122,
       0,   123,   124,     0,     0,   125,   126,   127,     0,     0,
       0,   128,   869,   129,   130,     0,   131,   132,   133,     0,
     134,     0,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,     0,     0,   146,   147,   148,     0,   393,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   500,   501,   502,   175,   176,   503,   535,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     0,
       0,     0,    11,     0,     0,     0,   390,   391,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   529,   392,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,   530,   531,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,     0,    74,    75,    76,     0,     0,    77,    78,
       0,     0,     0,    79,    80,   483,    82,    83,    84,    85,
      86,   532,    88,    89,     0,     0,     0,    90,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,    96,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   533,     0,     0,   109,
     110,   111,   112,   113,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,     0,   122,     0,   123,
     124,     0,     0,   125,   126,   127,     0,     0,     0,   128,
     874,   129,   130,     0,   131,   132,   133,     0,   134,     0,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,     0,   146,   147,   148,     0,   393,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     500,   501,   502,   175,   176,   503,   535,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     0,     0,     0,
      11,     0,     0,     0,   390,   391,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   469,    25,   471,
     392,    28,   472,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,   474,     0,
      45,    46,    47,   476,   477,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
       0,    74,    75,    76,     0,     0,    77,    78,     0,     0,
       0,    79,    80,   483,    82,    83,    84,    85,    86,   532,
      88,    89,     0,     0,     0,    90,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   486,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   533,     0,     0,   109,   110,   644,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,     0,   122,     0,   645,   124,     0,
       0,   125,   126,   127,     0,     0,     0,   128,     0,   129,
     130,     0,   131,   132,   133,     0,   134,     0,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,     0,
       0,   146,   147,   148,     0,   393,   150,   151,   152,   153,
     154,   155,   156,   157,   495,   159,   496,   161,   497,   498,
     164,   165,   166,   167,   168,   169,   499,   171,   500,   501,
     502,   175,   176,   503,   504,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     0,     0,     0,    11,     0,
       0,     0,   390,   391,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   529,   392,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,   530,   531,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,     0,    74,
      75,    76,     0,     0,    77,    78,     0,     0,     0,    79,
      80,   483,    82,    83,    84,    85,    86,   532,    88,    89,
       0,     0,     0,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,    96,    97,    98,    99,   100,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   533,     0,     0,   109,   110,   111,   112,   113,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,     0,   122,     0,   123,   124,     0,     0,   125,
     126,   127,     0,     0,     0,   128,     0,   129,   130,     0,
     131,   132,   133,     0,   134,     0,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,     0,     0,   146,
     147,   148,     0,   393,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   500,   501,   502,   175,
     176,   503,   535,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     0,     0,     0,    11,     0,     0,     0,
     390,   391,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,   469,    25,   471,   392,    28,   472,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,   474,     0,    45,    46,    47,   476,
     477,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,     0,    74,    75,    76,
       0,     0,    77,    78,     0,     0,     0,    79,    80,   483,
      82,    83,    84,    85,    86,   532,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   486,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     533,     0,     0,   109,   110,   111,   112,   113,     0,     0,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
       0,   122,     0,   123,   124,     0,     0,   125,   126,   127,
       0,     0,     0,   128,     0,   129,   130,     0,   131,   132,
     133,     0,   134,     0,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,     0,     0,   146,   147,   148,
       0,   393,   150,   151,   152,   153,   154,   155,   156,   157,
     495,   159,   496,   161,   497,   498,   164,   165,   166,   167,
     168,   169,   499,   171,   500,   501,   502,   175,   176,   503,
     504,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     0,     0,    11,     0,     0,     0,   390,   391,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   469,    25,   471,   392,    28,   472,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,   474,     0,    45,    46,    47,   476,   477,    50,
     478,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,     0,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,   483,    82,    83,
      84,    85,    86,   532,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     486,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   533,     0,
       0,   109,   110,     0,   112,   113,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,     0,   122,
       0,     0,     0,     0,     0,   125,   126,   127,     0,     0,
       0,   128,     0,   129,   130,     0,   131,   132,   133,     0,
     134,     0,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,     0,     0,   146,   147,   148,     0,   393,
     150,   151,   152,   153,   154,   155,   156,   157,   495,   159,
     496,   161,   497,   498,   164,   165,   166,   167,   168,   169,
     499,   171,   500,   501,   502,   175,   176,   503,   504,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     0,
       0,     0,    11,     0,     0,     0,   390,   391,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   469,
      25,   471,   392,    28,   472,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
     474,     0,    45,    46,    47,   476,   477,    50,   478,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,     0,    74,    75,    76,     0,     0,    77,    78,
       0,     0,     0,    79,    80,   483,    82,    83,    84,    85,
      86,   532,    88,    89,     0,     0,     0,    90,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   486,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   533,     0,     0,   109,
     110,     0,   112,   113,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,     0,   122,     0,     0,
       0,     0,     0,   125,   126,   127,     0,     0,     0,   128,
       0,   129,   130,     0,     0,     0,   133,     0,   134,     0,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,     0,   146,   147,   148,     0,   393,   150,   151,
     152,   153,   154,   155,   156,   157,   495,   159,   496,   161,
     497,   498,   164,   165,   166,   167,   168,   169,   499,   171,
     500,   501,   502,   175,   176,   503,   504,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     0,     0,     0,
      11,     0,     0,     0,   390,   391,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   469,    25,   471,
     392,    28,   472,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,   474,     0,
      45,    46,    47,   476,   477,    50,   478,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
       0,    74,    75,    76,     0,     0,    77,    78,     0,     0,
       0,    79,    80,   483,    82,    83,    84,    85,    86,   532,
      88,    89,     0,     0,     0,    90,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   486,     0,    98,    99,
     100,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104,     0,   106,   107,   533,     0,     0,   109,   110,     0,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,     0,   122,     0,     0,     0,     0,
       0,   125,   126,   127,     0,     0,     0,   128,     0,   129,
     130,     0,     0,     0,   133,     0,   134,     0,   135,     0,
     137,     0,   139,   140,   141,   142,   143,   144,   145,     0,
       0,   146,   147,   148,     0,   393,   150,   151,   152,   153,
     154,   155,   156,   157,   495,   159,   496,   161,   497,   498,
     164,   165,   166,   167,   168,   169,   499,   171,   500,   501,
     502,   175,   176,   503,   504,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       0,     0,     0,     7,     8,     0,     0,     0,   465,     0,
       0,     0,   390,   391,     0,    14,    15,    16,   466,    18,
      19,    20,   467,    22,   468,   469,   470,   471,   392,    28,
     472,    30,    31,     0,    32,    33,    34,    35,   473,    37,
      38,    39,    40,    41,    42,    43,   474,     0,    45,   475,
      47,   476,   477,    50,   478,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   479,
     480,    68,     0,    69,    70,    71,   481,     0,     0,    74,
      75,    76,     0,     0,   482,    78,     0,     0,     0,     0,
      80,   483,    82,   484,   485,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   486,    97,    98,   487,   488,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,   107,     0,     0,     0,     0,     0,     0,   112,   113,
       0,     0,     0,     0,   114,   115,   116,   117,   489,   119,
     120,   490,     0,     0,     0,     0,     0,     0,     0,   491,
     492,   127,     0,     0,     0,   128,     0,   129,   493,     0,
       0,     0,   133,     0,   134,     0,   135,   136,   137,   138,
     494,   140,   141,   142,   143,   144,   145,     0,     0,   146,
     147,     0,     0,   393,   150,   151,   152,   153,   154,   155,
     156,   157,   495,   159,   496,   161,   497,   498,   164,   165,
     166,   167,   168,   169,   499,   171,   500,   501,   502,   175,
     176,   503,   504,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     0,     0,
       0,     7,     8,     0,     0,     0,   465,     0,     0,     0,
     390,   391,     0,    14,    15,    16,   513,    18,    19,    20,
     467,   514,   515,   469,   470,   471,   392,    28,   472,    30,
      31,     0,    32,    33,    34,    35,   516,    37,   517,   518,
      40,    41,    42,    43,   474,     0,    45,   519,    47,   476,
     477,    50,   478,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   479,   480,    68,
       0,    69,    70,    71,   520,     0,     0,    74,    75,    76,
       0,     0,   482,    78,     0,     0,     0,     0,    80,   483,
      82,   484,   485,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   486,    97,    98,   487,   488,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,   107,
       0,     0,     0,     0,     0,     0,   112,   113,     0,     0,
       0,     0,   114,   115,   116,   117,   489,   119,   120,   490,
       0,     0,     0,     0,     0,     0,     0,   491,   492,   127,
       0,     0,     0,   128,     0,   129,   493,     0,     0,     0,
     133,     0,   134,     0,   135,   136,   137,   138,   494,   140,
     141,   142,   143,   144,   145,     0,     0,   146,   147,     0,
       0,   393,   150,   151,   152,   153,   154,   155,   156,   157,
     495,   521,   496,   161,   497,   498,   164,   165,   166,   167,
     168,   169,   499,   171,   500,   501,   502,   175,   176,   503,
     504,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   542,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     0,     0,   746,
       0,     0,     0,   390,   391,     0,    14,    15,    16,   513,
      18,    19,    20,   467,   514,   515,   469,   470,   471,   392,
      28,   472,    30,    31,     0,    32,    33,    34,    35,   516,
      37,   517,   518,    40,    41,    42,    43,   474,     0,    45,
     519,    47,   476,   477,    50,   478,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     479,   480,    68,     0,    69,    70,    71,   520,     0,     0,
      74,    75,    76,     0,     0,   482,    78,     0,     0,     0,
       0,    80,   483,    82,   484,   485,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   486,    97,    98,   487,   488,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,   107,     0,     0,     0,     0,     0,     0,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   489,
     119,   120,   490,     0,     0,     0,     0,     0,     0,     0,
     491,   492,   127,     0,     0,     0,   128,   747,   129,   493,
       0,     0,     0,     0,     0,   134,     0,   135,   136,   137,
     138,   494,   140,   141,   142,   143,   144,   145,     0,     0,
     146,   147,     0,     0,   393,   150,   151,   152,   153,   154,
     155,   156,   157,   495,   521,   496,   161,   497,   498,   164,
     165,   166,   167,   168,   169,   499,   171,   500,   501,   502,
     175,   176,   503,   504,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   542,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     0,
       0,     0,   465,     0,     0,     0,   390,   391,     0,    14,
      15,    16,   513,    18,    19,    20,   467,   514,   515,   469,
     470,   471,   392,    28,   472,    30,    31,     0,    32,    33,
      34,    35,   516,    37,   517,   518,    40,    41,    42,    43,
     474,     0,    45,   519,    47,   476,   477,    50,   478,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   479,   480,    68,     0,    69,    70,    71,
     520,     0,     0,    74,    75,    76,     0,     0,   482,    78,
       0,     0,     0,     0,    80,   483,    82,   484,   485,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   486,    97,
      98,   487,   488,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,   107,     0,     0,     0,     0,
       0,     0,   112,   113,     0,     0,     0,     0,   114,   115,
     116,   117,   489,   119,   120,   490,     0,     0,     0,     0,
       0,     0,     0,   491,   492,   127,     0,     0,     0,   128,
       0,   129,   493,     0,     0,     0,     0,     0,   134,     0,
     135,   136,   137,   138,   494,   140,   141,   142,   143,   144,
     145,     0,     0,   146,   147,     0,     0,   393,   150,   151,
     152,   153,   154,   155,   156,   157,   495,   521,   496,   161,
     497,   498,   164,   165,   166,   167,   168,   169,   499,   171,
     500,   501,   502,   175,   176,   503,   504,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   545,   546,     0,     0,     0,     0,     7,     8,
       0,     0,     0,   465,     0,     0,     0,   390,   391,     0,
      14,    15,    16,   513,    18,    19,    20,   467,   514,   515,
     469,   470,   471,   392,    28,   472,    30,    31,     0,    32,
      33,    34,    35,   516,    37,   517,   518,    40,    41,    42,
      43,   474,     0,    45,   519,    47,   476,   477,    50,   478,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   479,   480,    68,     0,    69,    70,
      71,   520,     0,     0,    74,    75,    76,     0,     0,   482,
      78,     0,     0,     0,     0,    80,   483,    82,   484,   485,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   486,
      97,    98,   487,   488,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,   105,   106,   107,     0,     0,     0,
       0,     0,     0,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   489,   119,   120,   490,     0,     0,     0,
       0,     0,     0,     0,   491,   492,   127,     0,     0,     0,
     128,     0,   129,   493,     0,     0,     0,     0,     0,   134,
       0,   135,   136,   137,   138,   494,   140,   141,   142,   143,
     144,   145,     0,     0,   146,   147,     0,     0,   393,   150,
     151,   152,   153,   154,   155,   156,   157,   495,   521,   496,
     161,   497,   498,   164,   165,   166,   167,   168,   169,   499,
     171,   500,   501,   502,   175,   176,   503,   504,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     7,     8,     0,     0,     0,   465,     0,
       0,     0,   390,   391,     0,    14,    15,    16,   466,    18,
      19,    20,   467,    22,   468,   469,  1074,   471,   392,    28,
     472,    30,    31,     0,    32,    33,    34,    35,   473,    37,
      38,    39,    40,    41,    42,    43,   474,     0,    45,   475,
      47,   476,   477,    50,   478,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   479,
     480,    68,     0,    69,    70,    71,   481,     0,     0,    74,
      75,    76,     0,     0,   482,    78,     0,     0,     0,     0,
      80,   483,    82,   484,   485,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   486,    97,    98,   487,   488,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,  1075,     0,     0,     0,  1076,     0,     0,   112,   113,
       0,     0,     0,     0,   114,   115,   116,   117,   489,   119,
     120,   490,     0,     0,     0,     0,     0,     0,     0,   491,
     492,   127,     0,     0,     0,   128,  1473,   129,   493,     0,
       0,     0,  1474,     0,   134,     0,   135,   136,   137,   138,
     494,   140,   141,   142,   143,   144,   145,     0,     0,  1077,
     147,     0,     0,   393,   150,   151,   152,   153,   154,   155,
     156,   157,   495,   159,   496,   161,   497,   498,   164,   165,
     166,   167,   168,   169,   499,   171,   500,   501,   502,   175,
     176,   503,   504,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     7,     8,
       0,     0,     0,   465,     0,     0,     0,   390,   391,     0,
      14,    15,    16,   513,    18,    19,    20,   467,   514,   515,
     469,   470,   471,   392,    28,   472,    30,    31,     0,    32,
      33,    34,    35,   516,    37,   517,   518,    40,    41,    42,
      43,   474,     0,    45,   519,    47,   476,   477,    50,   478,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   479,   480,    68,     0,    69,    70,
      71,   520,     0,     0,    74,    75,    76,     0,     0,   482,
      78,     0,     0,     0,     0,    80,   483,    82,   484,   485,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   486,
      97,    98,   487,   488,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,   105,   106,   107,     0,     0,     0,
       0,     0,     0,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   489,   119,   120,   490,     0,     0,     0,
       0,     0,     0,     0,   491,   492,   127,     0,     0,     0,
     128,   716,   129,   493,     0,     0,     0,   717,     0,   134,
       0,   135,   136,   137,   138,   494,   140,   141,   142,   143,
     144,   145,     0,     0,   146,   147,     0,     0,   393,   150,
     151,   152,   153,   154,   155,   156,   157,   495,   521,   496,
     161,   497,   498,   164,   165,   166,   167,   168,   169,   499,
     171,   500,   501,   502,   175,   176,   503,   504,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     7,     8,     0,     0,     0,   465,     0,
       0,     0,   390,   391,     0,    14,    15,    16,   513,    18,
      19,    20,   467,   514,   515,   469,   470,   471,   392,    28,
     472,    30,    31,     0,    32,    33,    34,    35,   516,    37,
     517,   518,    40,    41,    42,    43,   474,     0,    45,   519,
      47,   476,   477,    50,   478,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   479,
     480,    68,     0,    69,    70,    71,   520,     0,     0,    74,
      75,    76,     0,     0,   482,    78,     0,     0,     0,     0,
      80,   483,    82,   484,   485,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   486,    97,    98,   487,   488,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,   107,     0,     0,     0,     0,     0,     0,   112,   113,
       0,     0,     0,     0,   114,   115,   116,   117,   489,   119,
     120,   490,     0,     0,     0,     0,     0,     0,     0,   491,
     492,   127,     0,     0,     0,   128,   764,   129,   493,     0,
       0,     0,   765,     0,   134,     0,   135,   136,   137,   138,
     494,   140,   141,   142,   143,   144,   145,     0,     0,   146,
     147,     0,     0,   393,   150,   151,   152,   153,   154,   155,
     156,   157,   495,   521,   496,   161,   497,   498,   164,   165,
     166,   167,   168,   169,   499,   171,   500,   501,   502,   175,
     176,   503,   504,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     7,     8,
       0,     0,     0,   465,     0,     0,     0,   390,   391,     0,
      14,    15,    16,   466,    18,    19,    20,   467,    22,   468,
     469,  1074,   471,   392,    28,   472,    30,    31,     0,    32,
      33,    34,    35,   473,    37,    38,    39,    40,    41,    42,
      43,   474,     0,    45,   475,    47,   476,   477,    50,   478,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   479,   480,    68,     0,    69,    70,
      71,   481,     0,     0,    74,    75,    76,     0,     0,   482,
      78,     0,     0,     0,     0,    80,   483,    82,   484,   485,
      85,    86,  1397,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   486,
      97,    98,   487,   488,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,   105,   106,  1075,     0,     0,     0,
    1076,     0,     0,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   489,   119,   120,   490,     0,     0,     0,
       0,     0,     0,     0,   491,   492,   127,     0,     0,     0,
     128,     0,   129,   493,     0,     0,     0,     0,     0,   134,
       0,   135,   136,   137,   138,   494,   140,   141,   142,   143,
     144,   145,     0,     0,  1077,   147,     0,     0,   393,   150,
     151,   152,   153,   154,   155,   156,   157,   495,   159,   496,
     161,   497,   498,   164,   165,   166,   167,   168,   169,   499,
     171,   500,   501,   502,   175,   176,   503,   504,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     7,     8,     0,     0,     0,   465,     0,
       0,     0,   390,   391,     0,    14,    15,    16,   466,    18,
      19,    20,   467,    22,   468,   469,  1074,   471,   392,    28,
     472,    30,    31,     0,    32,    33,    34,    35,   473,    37,
      38,    39,    40,    41,    42,    43,   474,     0,    45,   475,
      47,   476,   477,    50,   478,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   479,
     480,    68,     0,    69,    70,    71,   481,     0,     0,    74,
      75,    76,     0,     0,   482,    78,     0,     0,     0,     0,
      80,   483,    82,   484,   485,    85,    86,  1526,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   486,    97,    98,   487,   488,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,  1075,     0,     0,     0,  1076,     0,     0,   112,   113,
       0,     0,     0,     0,   114,   115,   116,   117,   489,   119,
     120,   490,     0,     0,     0,     0,     0,     0,     0,   491,
     492,   127,     0,     0,     0,   128,     0,   129,   493,     0,
       0,     0,     0,     0,   134,     0,   135,   136,   137,   138,
     494,   140,   141,   142,   143,   144,   145,     0,     0,  1077,
     147,     0,     0,   393,   150,   151,   152,   153,   154,   155,
     156,   157,   495,   159,   496,   161,   497,   498,   164,   165,
     166,   167,   168,   169,   499,   171,   500,   501,   502,   175,
     176,   503,   504,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     7,     8,
       0,     0,     0,   465,     0,     0,     0,   390,   391,     0,
      14,    15,    16,   466,    18,    19,    20,   467,    22,   468,
     469,  1074,   471,   392,    28,   472,    30,    31,     0,    32,
      33,    34,    35,   473,    37,    38,    39,    40,    41,    42,
      43,   474,     0,    45,   475,    47,   476,   477,    50,   478,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   479,   480,    68,     0,    69,    70,
      71,   481,     0,     0,    74,    75,    76,     0,     0,   482,
      78,     0,     0,     0,     0,    80,   483,    82,   484,   485,
      85,    86,  1530,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   486,
      97,    98,   487,   488,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,   105,   106,  1075,     0,     0,     0,
    1076,     0,     0,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   489,   119,   120,   490,     0,     0,     0,
       0,     0,     0,     0,   491,   492,   127,     0,     0,     0,
     128,     0,   129,   493,     0,     0,     0,     0,     0,   134,
       0,   135,   136,   137,   138,   494,   140,   141,   142,   143,
     144,   145,     0,     0,  1077,   147,     0,     0,   393,   150,
     151,   152,   153,   154,   155,   156,   157,   495,   159,   496,
     161,   497,   498,   164,   165,   166,   167,   168,   169,   499,
     171,   500,   501,   502,   175,   176,   503,   504,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     7,     8,     0,     0,     0,   465,     0,
       0,     0,   390,   391,     0,    14,    15,    16,   466,    18,
      19,    20,   467,    22,   468,   469,  1074,   471,   392,    28,
     472,    30,    31,     0,    32,    33,    34,    35,   473,    37,
      38,    39,    40,    41,    42,    43,   474,     0,    45,   475,
      47,   476,   477,    50,   478,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   479,
     480,    68,     0,    69,    70,    71,   481,     0,     0,    74,
      75,    76,     0,     0,   482,    78,     0,     0,     0,     0,
      80,   483,    82,   484,   485,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   486,    97,    98,   487,   488,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,  1075,     0,     0,     0,  1076,     0,     0,   112,   113,
       0,     0,     0,     0,   114,   115,   116,   117,   489,   119,
     120,   490,     0,     0,     0,     0,     0,     0,     0,   491,
     492,   127,     0,     0,     0,   128,     0,   129,   493,     0,
       0,     0,     0,     0,   134,     0,   135,   136,   137,   138,
     494,   140,   141,   142,   143,   144,   145,     0,     0,  1077,
     147,     0,     0,   393,   150,   151,   152,   153,   154,   155,
     156,   157,   495,   159,   496,   161,   497,   498,   164,   165,
     166,   167,   168,   169,   499,   171,   500,   501,   502,   175,
     176,   503,   504,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     7,     8,
       0,     0,     0,   465,     0,     0,     0,   390,   391,     0,
      14,    15,    16,   466,    18,    19,    20,   467,    22,   468,
     469,  1074,   471,   392,    28,   472,    30,    31,     0,    32,
      33,    34,    35,   473,    37,    38,    39,    40,    41,    42,
      43,   474,     0,    45,   475,    47,   476,   477,    50,   478,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   479,   480,    68,     0,    69,    70,
      71,   481,     0,     0,    74,    75,    76,     0,     0,   482,
      78,     0,     0,     0,     0,    80,   483,    82,   484,   485,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   486,
      97,    98,   487,   488,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,   105,   106,  1075,     0,     0,     0,
    1076,     0,     0,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   489,   119,   120,   490,     0,     0,     0,
       0,     0,     0,     0,   491,   492,   127,     0,     0,     0,
     128,     0,   129,   493,     0,     0,     0,     0,     0,   134,
       0,   135,   136,   137,   138,   494,   140,   141,   142,   143,
     144,   145,     0,     0,   146,   147,     0,     0,   393,   150,
     151,   152,   153,   154,   155,   156,   157,   495,   159,   496,
     161,   497,   498,   164,   165,   166,   167,   168,   169,   499,
     171,   500,   501,   502,   175,   176,   503,   504,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     7,     8,     0,     0,     0,   465,     0,
       0,     0,   390,   391,     0,    14,    15,    16,   513,    18,
      19,    20,   467,   514,   515,   469,   470,   471,   392,    28,
     472,    30,    31,     0,    32,    33,    34,    35,   516,    37,
     517,   518,    40,    41,    42,    43,   474,     0,    45,   519,
      47,   476,   477,    50,   478,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   479,
     480,    68,     0,    69,    70,    71,   520,     0,     0,    74,
      75,    76,     0,     0,   482,    78,     0,     0,     0,     0,
      80,   483,    82,   484,   485,    85,    86,  1155,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   486,    97,    98,   487,   488,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,   107,     0,     0,     0,     0,     0,     0,   112,   113,
       0,     0,     0,     0,   114,   115,   116,   117,   489,   119,
     120,   490,     0,     0,     0,     0,     0,     0,     0,   491,
     492,   127,     0,     0,     0,   128,     0,   129,   493,     0,
       0,     0,     0,     0,   134,     0,   135,   136,   137,   138,
     494,   140,   141,   142,   143,   144,   145,     0,     0,   146,
     147,     0,     0,   393,   150,   151,   152,   153,   154,   155,
     156,   157,   495,   521,   496,   161,   497,   498,   164,   165,
     166,   167,   168,   169,   499,   171,   500,   501,   502,   175,
     176,   503,   504,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     7,     8,
       0,     0,     0,   465,     0,     0,     0,   390,   391,     0,
      14,    15,    16,   513,    18,    19,    20,   467,   514,   515,
     469,   470,   471,   392,    28,   472,    30,    31,     0,    32,
      33,    34,    35,   516,    37,   517,   518,    40,    41,    42,
      43,   474,     0,    45,   519,    47,   476,   477,    50,   478,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   479,   480,    68,     0,    69,    70,
      71,   520,     0,     0,    74,    75,    76,     0,     0,   482,
      78,     0,     0,     0,     0,    80,   483,    82,   484,   485,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   486,
      97,    98,   487,   488,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,   105,   106,   107,     0,     0,     0,
       0,     0,     0,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   489,   119,   120,   490,     0,     0,     0,
       0,     0,     0,     0,   491,   492,   127,     0,     0,     0,
     128,     0,   129,   493,     0,     0,     0,     0,     0,   134,
       0,   135,   136,   137,   138,   494,   140,   141,   142,   143,
     144,   145,     0,     0,   146,   147,     0,     0,   393,   150,
     151,   152,   153,   154,   155,   156,   157,   495,   521,   496,
     161,   497,   498,   164,   165,   166,   167,   168,   169,   499,
     171,   500,   501,   502,   175,   176,   503,   504,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     7,     8,     0,     0,     0,   465,     0,
       0,     0,   390,   391,     0,    14,    15,    16,     0,    18,
      19,    20,   467,     0,     0,   469,   470,     0,   392,    28,
     472,    30,    31,     0,    32,    33,    34,    35,     0,    37,
       0,     0,    40,    41,    42,    43,   474,     0,    45,     0,
      47,     0,     0,    50,   478,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   479,
     480,    68,     0,    69,    70,    71,     0,     0,     0,    74,
      75,    76,     0,     0,   482,    78,     0,     0,     0,     0,
      80,   483,    82,   484,   485,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   486,    97,    98,   487,   488,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,     0,     0,     0,     0,     0,     0,     0,   112,   113,
       0,     0,     0,     0,   114,   115,   116,   117,   489,   119,
     120,   490,     0,     0,     0,     0,     0,     0,     0,   491,
     492,   127,     0,     0,     0,   128,     0,   129,   493,     0,
       0,     0,     0,     0,   134,     0,   135,   136,   137,   138,
     494,   140,   141,   142,   143,   144,   145,     0,     0,     0,
     147,     0,     0,   393,   150,   151,   152,   153,   154,   155,
     156,   157,   495,     0,   496,   161,   497,   498,   164,   165,
     166,   167,   168,   169,   499,   171,   500,   501,   502,   175,
     176,     0,   504,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,  -804,   431,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -804,     0,     0,     0,  -804,     0,     0,     0,  -804,  -804,
       0,     0,     0,  -804,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   432,     0,     0,  -804,     0,   433,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -804,     0,  -804,  -804,     0,     0,     0,  -804,  -804,  -804,
    -804,     0,     0,     0,  -804,  -804,     0,     0,     0,     0,
       0,  -804,     0,     0,  -804,  -804,   434,     0,     0,     0,
       0,     0,     0,     0,  -804,  -804,     0,     0,     0,     0,
    -804,     0,     0,     0,  -804,     0,     0,     0,  -804,  -804,
       0,  -804,     0,  -804,  -804,     0,     0,     0,  -804,  -804,
       0,     0,  -804,  -804,  -804,  -804,  -804,  -804,     0,     0,
    -804,     0,     0,     0,     0,  -804,  -804,     0,     0,  -804,
       0,     0,     0,     0,  -804,     0,     0,  -804,     0,     0,
       0,     0,  -804,  -804,  -804,  -804,  -804,     0,  -804,  -804,
    -804,  -804,     0,     0,     0,     0,  -804,  -804,  -804,     0,
    -804,  -804,  -804,  -804,  -804,  -804,     0,  -804,     0,  -804,
       0,     0,     0,     0,  -804,  -804,  -804,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -804,     0,  -804,     0,  -804,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -804,     0,     0,     0,
       0,  -804
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,    12,   631,   178,     4,     5,     6,   328,     0,   741,
     109,   300,     4,     5,     6,   780,   582,   583,     4,     5,
       6,   753,   632,   633,   634,   635,   399,   400,  1224,   249,
     248,   132,   721,  1208,   280,   767,   721,   990,  1012,  1280,
    1281,   807,   846,   413,   264,   974,    73,    26,    27,    36,
    1060,  1141,   881,    55,   424,    36,    30,   580,   581,   582,
     583,  1237,   401,   580,   581,   897,    26,    27,    47,   677,
     118,   949,     1,   271,     4,     5,     6,     1,   448,     1,
       1,    29,    29,     1,     1,    29,    45,    47,    94,   142,
     107,   100,     1,     9,    10,    74,    56,     8,     4,     5,
       6,   440,   441,    62,   118,    93,    26,    27,   108,    96,
     136,    26,    27,    94,    74,    96,   108,    37,    38,    79,
      40,    41,   107,  1313,    96,   107,   144,    47,   216,   100,
    1491,   169,   100,   112,   130,    73,    56,    57,   107,   158,
     610,    94,   612,   613,    96,   615,   224,   617,   226,    87,
     396,   111,   112,   113,    74,   625,   626,   176,   176,    79,
     147,   113,   110,   201,   118,   253,   147,   156,   107,   113,
     147,   903,   110,   156,   200,   193,   124,   186,   108,    37,
      38,   280,    40,    41,   122,   860,   124,   103,    54,   147,
      56,   111,   112,   113,   147,   183,  1437,   112,   121,    57,
     196,   149,   108,   188,   156,   153,   188,   123,   156,   125,
     224,   217,   218,   160,   216,   186,   160,   234,   186,   272,
     130,   190,   420,     5,   272,   957,   232,     9,   187,   177,
     331,   963,    96,   187,   100,    94,  1411,   153,  1414,   213,
     160,   157,   242,  1008,  1076,   245,   812,   813,   187,   538,
     242,   253,  1205,   245,  1228,   113,  1060,  1061,   174,  1349,
     107,   190,  1191,  1237,   175,   954,   190,   956,   190,   190,
    1631,   956,   190,   190,  1103,   883,   951,  1155,   194,  1289,
     280,   190,   528,   255,   256,   272,   196,   976,   280,   964,
     660,   272,   306,   810,   811,   272,   212,   396,    76,   219,
    1490,   107,   160,   107,   153,   169,     9,   286,   107,   336,
     258,   107,   339,     1,   272,   294,    96,   107,    42,    96,
      42,   118,    46,   200,    46,    28,   286,    51,    29,    51,
     429,   160,   209,    45,   294,    47,   153,   184,   107,   438,
     260,   123,   302,   125,  1585,    69,   107,    69,   447,   688,
     118,   133,   598,  1549,   107,   454,   455,   577,   217,   218,
     209,   219,   580,   581,   463,   735,   286,    79,   738,   153,
     147,   153,   842,   232,   294,   153,   156,   107,    66,   107,
     184,   187,   302,    71,   250,   184,   107,   251,   252,   186,
     254,   187,   209,  1634,   106,   185,   396,   263,   336,   265,
     739,   339,   260,  1493,   396,    33,    52,   271,   107,   110,
     276,   277,   278,  1145,   280,    45,   282,    47,   187,   283,
     123,    49,   125,   124,   156,   425,   187,   427,    42,   528,
     118,   134,    46,   425,   187,   427,   107,    51,   107,   156,
    1414,   540,   220,   221,   168,  1620,   168,   171,   149,   171,
     153,   107,   452,   552,   184,    69,   168,   457,   131,   187,
     452,   707,   186,    96,   186,   457,   187,   405,   406,   568,
     569,   409,  1157,   846,   156,   413,   106,  1166,   416,   417,
    1046,  1047,  1048,   129,   156,  1289,   424,   211,   187,   211,
     107,   107,   430,   431,  1298,   425,   434,   427,  1264,   107,
    1590,  1267,    94,   876,   442,  1309,   107,   107,  1183,   156,
     448,   449,   450,   451,   147,   184,   187,   190,   456,   425,
     156,   427,   452,  1046,  1047,  1048,   464,   457,   528,   107,
     107,   187,  1207,   533,     9,    10,   528,   107,   168,   107,
     107,   533,  1632,    29,   156,   158,   452,   262,   647,   650,
     651,   457,   107,   652,   168,   147,   107,   171,   273,   805,
     107,   107,   166,   176,   575,   904,   905,   184,   184,   569,
     909,   509,   186,   117,   107,   118,   107,   569,   182,   187,
     580,   581,   582,   583,  1513,   523,   187,   187,   580,   581,
     582,   583,   810,   158,   532,  1548,   816,   211,   598,    39,
     939,   153,   146,   533,    44,    45,   598,   262,   707,   187,
     187,   176,  1702,   106,  1704,   159,   184,   187,   273,    59,
     187,    61,    62,  1713,   110,   177,   564,   533,   103,   118,
      70,   970,   187,   198,   127,   974,   187,    96,   124,   569,
     187,   187,    94,   186,    94,   153,  1321,  1412,   123,   193,
     125,   184,  1417,   184,   113,   268,   122,    97,   859,   860,
    1464,    53,   275,   149,     9,    10,    58,   153,    94,   177,
     156,  1300,   285,   772,   773,   774,   122,   776,   153,  1364,
       9,    10,   157,   122,   945,    77,   947,  1060,  1061,     5,
     142,   177,   142,     9,   158,   267,   897,   156,   224,   174,
     226,    53,   274,  1269,    96,    33,    58,   707,    96,  1612,
    1613,   137,   176,   137,   153,   707,   142,   156,    24,   194,
     182,    49,   660,   148,  1399,   113,   118,  1402,    34,   153,
     931,   731,     9,   195,   198,   148,   997,   212,   999,   731,
     165,  1062,    96,   681,    96,   731,   684,  1650,   298,  1038,
     951,    28,   165,  1656,    60,   182,    95,   307,   103,   268,
     698,   761,   762,   964,   702,   703,   275,   106,   195,   761,
     762,  1536,   246,   247,   103,  1540,   285,   116,   123,   136,
     125,   584,   137,   118,   224,   588,  1032,   725,   127,   727,
     100,   191,   192,   150,   123,   269,   125,   735,   153,    94,
     738,   731,   894,   113,   742,   805,   100,   123,   153,   125,
     821,   106,   157,   805,   906,   169,   215,   133,   224,   113,
     100,   100,   100,   229,   153,   731,  1455,  1456,   157,   174,
     100,   761,   762,   113,   113,   113,   122,   153,  1448,   137,
     154,   779,   156,   113,   142,   174,   123,  1186,   125,   194,
     153,  1616,  1191,  1585,   122,   761,   762,   134,   276,   277,
     278,  1036,   629,   630,   282,   194,  1041,   212,   653,   807,
     122,   656,   137,    53,   659,  1076,   153,   142,    58,   153,
     338,   153,   156,   212,   156,   343,   153,   153,   122,   156,
     156,   829,   122,  1568,   231,  1570,   233,   251,   252,   122,
     254,   220,   221,   222,   231,   122,   233,   261,   128,   129,
     128,   129,   122,   636,   637,   122,  1289,   271,   638,   639,
     153,   859,   860,   861,   862,  1298,  1601,  1556,  1557,   283,
     861,   862,  1481,  1482,   156,   224,  1309,  1276,   240,  1185,
     118,   240,   156,     0,   241,  1146,   107,   153,   190,    92,
      99,   167,   248,  1628,    50,   199,   101,   154,   102,   897,
    1059,   121,   145,   156,    29,   184,    47,   152,  1643,   184,
    1645,   184,   118,   911,   245,   187,   283,   303,   283,   118,
     153,     1,  1183,   118,   142,   107,   187,   153,   153,   156,
     142,    35,   992,   156,   156,  1624,   184,   156,   936,   156,
     992,   156,   156,   156,    17,   153,  1207,   945,   213,   947,
      29,   949,   187,   951,   190,   244,   190,  1263,     3,   230,
     118,   168,    70,    94,    94,    94,   964,   230,   170,   170,
     149,   107,  1032,   107,  1045,    29,   160,   160,   127,   132,
    1032,   132,  1381,   245,    94,   298,  1046,  1047,  1048,   140,
     141,   118,   143,   132,  1046,  1047,  1048,   142,   184,   997,
     151,   999,   992,   184,   155,   107,   157,   187,    94,   187,
      45,   162,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    96,   187,    96,   187,   992,   187,   179,   184,
     187,  1464,   153,    94,   184,   224,   236,   142,   190,    33,
     118,   132,  1441,   142,   170,    94,    29,    94,   285,   226,
     153,   202,   203,   204,   205,   206,   207,  1055,   127,   298,
    1321,   118,   147,   253,    94,   118,   184,   132,   160,   197,
     132,    96,   153,   100,   118,   184,   147,   100,  1076,   142,
      35,    29,   118,   184,   190,   244,   153,  1393,    79,  1149,
     156,    73,   156,   107,   153,   107,   156,  1149,   259,   284,
    1259,  1260,  1261,  1149,   156,    87,   156,   144,   156,   257,
      29,   285,   266,    29,  1513,    29,   286,   305,   144,   226,
     190,   127,   118,   147,    77,  1185,   147,   147,   110,   187,
     118,   187,   187,  1185,   107,   142,  1196,   100,  1399,   132,
     122,  1402,   124,   184,  1196,   187,   197,   187,   187,     7,
    1196,   249,   190,   236,   186,  1215,   232,  1155,   187,  1149,
     106,  1159,   106,  1215,    29,   249,   147,   281,    78,  1215,
     285,   187,   187,    29,  1234,   270,  1174,   187,   107,   256,
     170,   184,  1234,  1149,   126,  1183,   232,   147,   147,   232,
     126,    96,   184,    94,    29,   153,    96,   186,   232,  1197,
     186,   186,  1262,  1263,   184,  1511,  1196,   186,   184,  1207,
    1262,  1263,   184,   187,   170,   147,  1522,  1523,   187,  1525,
      53,    94,   186,    94,   186,  1215,  1532,   197,   196,    29,
    1196,   107,   107,   118,   118,    94,   264,  1235,   118,   186,
     224,    94,   196,   186,  1234,   196,   279,   224,   186,  1215,
      93,   196,   183,   186,   118,   286,   118,  1255,   186,   186,
     687,   198,   898,   224,   118,  1106,  1264,   242,  1234,  1267,
     248,   965,  1262,   420,   292,  1146,   400,   286,   245,   245,
    1590,  1632,   304,   808,   962,   304,   744,   304,   434,  1374,
    1175,  1285,   305,  1051,   305,  1283,  1197,   305,  1202,   523,
    1205,  1280,  1210,  1609,   609,   608,   628,  1568,  1228,  1570,
     662,   780,  1656,  1619,  1650,   862,  1140,   428,   947,   324,
    1105,  1255,  1265,  1321,  1264,  1298,  1061,  1464,   428,  1461,
    1302,  1070,   930,  1393,  1128,  1309,  1299,  1340,  1644,  1484,
    1601,  1393,    -1,    -1,    -1,    -1,    -1,  1345,    -1,    -1,
      -1,    -1,    -1,    -1,   336,    -1,    -1,   339,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1628,    -1,  1675,
      -1,    -1,    -1,  1371,  1372,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1643,    -1,  1645,    -1,    -1,    -1,    -1,    -1,
    1696,  1550,    -1,    -1,    -1,  1701,    -1,    -1,    -1,  1397,
      -1,  1399,    -1,    -1,  1402,    -1,    -1,  1566,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1413,    -1,    -1,    -1,    -1,
    1418,    -1,    -1,    -1,   406,    -1,    -1,   409,    -1,    -1,
      -1,   413,    -1,    -1,   416,   417,    -1,    -1,    -1,    -1,
      -1,    -1,   424,    -1,    -1,    -1,    -1,    -1,   430,   431,
      -1,  1511,   434,    -1,    -1,    -1,    -1,    -1,    -1,  1511,
     442,    -1,  1522,  1523,    -1,  1525,   448,   449,   450,   451,
    1522,  1523,  1532,  1525,   456,    -1,    -1,    -1,    -1,    -1,
    1532,    -1,   464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   509,  1526,    -1,
    1528,    -1,  1530,    -1,    -1,    -1,    -1,    -1,    -1,  1537,
      -1,   523,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1609,
     532,    -1,    -1,    -1,    -1,    -1,    -1,  1609,    -1,  1619,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1619,    -1,    -1,
    1568,    -1,  1570,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   564,    -1,  1644,    -1,    -1,    -1,  1586,    -1,
      -1,  1589,  1644,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1601,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1611,    -1,  1675,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1675,    -1,    -1,    -1,    -1,    -1,    -1,
    1628,    -1,    -1,    -1,    -1,    -1,  1696,    -1,  1636,    -1,
      -1,  1701,    -1,  1641,  1696,  1643,    -1,  1645,    -1,  1701,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1672,    -1,    -1,    -1,   660,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1688,    -1,    -1,    -1,  1692,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   684,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1708,    -1,    -1,  1711,    -1,    -1,   698,    -1,    -1,    -1,
     702,   703,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   725,    -1,   727,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   735,    -1,    -1,   738,    -1,    -1,    -1,
     742,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   556,
     557,    -1,   559,   560,   561,   562,    -1,    -1,    -1,    -1,
     567,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   779,    -1,    -1,
      -1,    -1,    -1,   590,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   598,   599,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   807,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   829,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   658,    -1,    -1,    -1,   662,    -1,   859,   860,   861,
     862,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   700,    -1,   897,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   911,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   936,    -1,   743,    -1,    -1,    -1,
      -1,    -1,    -1,   945,    -1,   947,    -1,   949,    -1,   951,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   768,   964,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   778,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   997,    -1,   999,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   831,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1055,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1076,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   899,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   934,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   953,    -1,    -1,    -1,
      -1,    -1,    -1,  1155,    -1,    -1,    -1,  1159,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   975,    -1,
      -1,    -1,  1174,    -1,    -1,    -1,    -1,    -1,    -1,   986,
     987,  1183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1001,  1197,    -1,  1004,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1207,    -1,    -1,    -1,    -1,
      -1,  1018,  1019,  1020,    -1,  1022,  1023,  1024,  1025,  1026,
    1027,    -1,  1029,  1030,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1235,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1051,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1255,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1264,    -1,    -1,  1267,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1093,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1321,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1345,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1161,    -1,  1163,    -1,  1165,    -1,
      -1,  1168,    -1,    -1,    -1,    -1,  1173,    -1,    -1,  1371,
    1372,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1185,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1194,    -1,    -1,
      -1,    -1,    -1,  1200,  1201,  1397,    -1,  1399,    -1,    -1,
    1402,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1413,  1219,    -1,    -1,    -1,  1418,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1283,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1526,    -1,  1528,    -1,  1530,    -1,
      -1,    -1,    -1,    -1,    -1,  1537,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1358,    -1,    -1,    -1,  1362,    -1,    -1,    -1,  1366,
      -1,  1368,    -1,  1370,    -1,    -1,  1568,    -1,  1570,  1376,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1384,    -1,    -1,
      -1,    -1,    -1,    -1,  1586,  1392,  1393,  1589,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1601,
      -1,    -1,    -1,  1410,    -1,    -1,    -1,    -1,    -1,  1611,
      -1,    -1,    -1,    -1,  1421,  1422,  1423,  1424,  1425,    -1,
    1427,    -1,    -1,    -1,    -1,    -1,  1628,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1636,    -1,    -1,    -1,    -1,  1641,
      -1,  1643,    -1,  1645,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1672,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1688,    -1,    -1,    -1,
    1692,    -1,  1499,    -1,  1501,    -1,    -1,  1504,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1512,  1708,    -1,    -1,  1711,
    1517,  1518,    -1,    -1,    -1,    -1,    -1,    -1,  1525,    -1,
      -1,    -1,  1529,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1593,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1605,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1644,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1670,    -1,    -1,    -1,    -1,  1675,    -1,
      -1,    11,    12,  1680,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,  1695,    29,
      -1,    -1,  1699,    33,    34,    -1,    36,    37,    38,    39,
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
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    98,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,    -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,   156,   157,   158,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,
     181,   182,    -1,   184,    -1,   186,    -1,   188,   189,    -1,
     191,   192,   193,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,   210,
     211,   212,    -1,   214,   215,   216,   217,   218,   219,   220,
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
      -1,    94,    95,    96,    97,    98,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
      -1,   124,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,    -1,   156,   157,   158,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,   184,    -1,   186,    -1,   188,   189,    -1,   191,   192,
     193,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,    -1,   210,   211,   212,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
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
      95,    96,    97,    98,    -1,   100,   101,   102,    -1,    -1,
     105,   106,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,    -1,    -1,   124,
      -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,
     135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,
      -1,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,   156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,   184,
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
     305,   306,   307,   308,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    98,    -1,   100,   101,   102,    -1,    -1,   105,   106,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,   126,
     127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,    -1,   156,
     157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,   174,    -1,   176,
     177,    -1,    -1,   180,   181,   182,    -1,   184,    -1,   186,
      -1,   188,   189,    -1,   191,   192,   193,    -1,   195,    -1,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,    -1,    -1,   210,   211,   212,    -1,   214,   215,   216,
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
      -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,    -1,    -1,   124,    -1,   126,   127,   128,
     129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,
     139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,   156,   157,   158,
     159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    -1,   176,   177,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
     189,    -1,   191,   192,   193,    -1,   195,    -1,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,    -1,
      -1,   210,   211,   212,    -1,   214,   215,   216,   217,   218,
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
      91,    92,    -1,    94,    95,    96,    97,    98,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,    -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,   156,   157,   158,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
     191,   192,   193,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,   210,
     211,   212,    -1,   214,   215,   216,   217,   218,   219,   220,
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
      -1,    94,    95,    96,    97,    98,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
      -1,   124,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,    -1,   156,   157,   158,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,
     193,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,    -1,   210,   211,   212,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
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
     305,   306,   307,   308,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    98,    -1,   100,   101,   102,    -1,    -1,   105,   106,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,   126,
     127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,    -1,   156,
     157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,   174,    -1,   176,
     177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
      -1,   188,   189,    -1,   191,   192,   193,    -1,   195,    -1,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,    -1,    -1,   210,   211,   212,    -1,   214,   215,   216,
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
      -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,    -1,    -1,   124,    -1,   126,   127,   128,
     129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,
     139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,   156,   157,   158,
     159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    -1,   176,   177,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
     189,    -1,   191,   192,   193,    -1,   195,    -1,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,    -1,
      -1,   210,   211,   212,    -1,   214,   215,   216,   217,   218,
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
      91,    92,    -1,    94,    95,    96,    97,    98,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,    -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,   156,   157,   158,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,   187,   188,   189,    -1,
     191,   192,   193,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,   210,
     211,   212,    -1,   214,   215,   216,   217,   218,   219,   220,
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
      -1,    94,    95,    96,    97,    98,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
      -1,   124,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,    -1,   156,   157,   158,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,   184,    -1,   186,    -1,   188,   189,    -1,   191,   192,
     193,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,    -1,   210,   211,   212,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
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
      95,    96,    97,    98,    -1,   100,   101,   102,    -1,    -1,
     105,   106,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,    -1,    -1,   124,
      -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,
     135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,
      -1,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,   156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,   187,   188,   189,    -1,   191,   192,   193,    -1,
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
     305,   306,   307,   308,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    98,    -1,   100,   101,   102,    -1,    -1,   105,   106,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,   126,
     127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,    -1,   156,
     157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,   174,    -1,   176,
     177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
     187,   188,   189,    -1,   191,   192,   193,    -1,   195,    -1,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,    -1,    -1,   210,   211,   212,    -1,   214,   215,   216,
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
      -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,    -1,    -1,   124,    -1,   126,   127,   128,
     129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,
     139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,   156,   157,   158,
     159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    -1,   176,   177,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
     189,    -1,   191,   192,   193,    -1,   195,    -1,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,    -1,
      -1,   210,   211,   212,    -1,   214,   215,   216,   217,   218,
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
      91,    92,    -1,    94,    95,    96,    97,    98,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,    -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,   156,   157,   158,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
     191,   192,   193,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,   210,
     211,   212,    -1,   214,   215,   216,   217,   218,   219,   220,
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
      -1,    94,    95,    96,    97,    98,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
      -1,   124,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,    -1,   156,   157,   158,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,
     193,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,    -1,   210,   211,   212,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
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
      95,    96,    97,    98,    -1,   100,   101,   102,    -1,    -1,
     105,   106,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,    -1,    -1,   124,
      -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,
     135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,
      -1,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,   156,   157,    -1,   159,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,
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
     305,   306,   307,   308,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    98,    -1,   100,   101,   102,    -1,    -1,   105,   106,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,   126,
     127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,    -1,   156,
     157,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,   174,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
      -1,   188,   189,    -1,    -1,    -1,   193,    -1,   195,    -1,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,    -1,    -1,   210,   211,   212,    -1,   214,   215,   216,
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
      -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,    -1,    -1,   124,    -1,   126,   127,   128,
     129,    -1,   131,    -1,    -1,    -1,   135,    -1,   137,   138,
     139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
     149,    -1,   151,   152,   153,    -1,    -1,   156,   157,    -1,
     159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
     189,    -1,    -1,    -1,   193,    -1,   195,    -1,   197,    -1,
     199,    -1,   201,   202,   203,   204,   205,   206,   207,    -1,
      -1,   210,   211,   212,    -1,   214,   215,   216,   217,   218,
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
      -1,    -1,   193,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,   210,
     211,    -1,    -1,   214,   215,   216,   217,   218,   219,   220,
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
      -1,    94,    95,    96,    97,    -1,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,   152,
      -1,    -1,    -1,    -1,    -1,    -1,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,
     193,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
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
     180,   181,   182,    -1,    -1,    -1,   186,   187,   188,   189,
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
     300,   301,   302,   303,   304,   305,   306,   307,   308,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    -1,    -1,   100,   101,   102,    -1,    -1,   105,   106,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,    -1,   150,   151,   152,    -1,    -1,    -1,    -1,
      -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
      -1,   188,   189,    -1,    -1,    -1,    -1,    -1,   195,    -1,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,    -1,    -1,   210,   211,    -1,    -1,   214,   215,   216,
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
      96,    97,    -1,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,    -1,   150,   151,   152,    -1,    -1,    -1,
      -1,    -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,   195,
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
     306,   307,   308,    24,    25,    -1,    -1,    -1,    29,    -1,
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
      -1,    -1,   193,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,   210,
     211,    -1,    -1,   214,   215,   216,   217,   218,   219,   220,
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
      96,    97,    -1,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,    -1,   150,   151,   152,    -1,    -1,    -1,
      -1,    -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,   187,   188,   189,    -1,    -1,    -1,   193,    -1,   195,
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
     306,   307,   308,    24,    25,    -1,    -1,    -1,    29,    -1,
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
     181,   182,    -1,    -1,    -1,   186,   187,   188,   189,    -1,
      -1,    -1,   193,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,   210,
     211,    -1,    -1,   214,   215,   216,   217,   218,   219,   220,
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
      96,    97,    -1,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,    -1,   150,   151,   152,    -1,    -1,    -1,
     156,    -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,   195,
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
     306,   307,   308,    24,    25,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
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
      -1,    -1,    -1,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,   210,
     211,    -1,    -1,   214,   215,   216,   217,   218,   219,   220,
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
      96,    97,    -1,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,    -1,   150,   151,   152,    -1,    -1,    -1,
     156,    -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,   195,
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
     306,   307,   308,    24,    25,    -1,    -1,    -1,    29,    -1,
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
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
      -1,    -1,    -1,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,   210,
     211,    -1,    -1,   214,   215,   216,   217,   218,   219,   220,
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
      96,    97,    -1,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,    -1,   150,   151,   152,    -1,    -1,    -1,
     156,    -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,   195,
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
     306,   307,   308,    24,    25,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
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
     151,   152,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
      -1,    -1,    -1,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,   210,
     211,    -1,    -1,   214,   215,   216,   217,   218,   219,   220,
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
      96,    97,    -1,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,    -1,   150,   151,   152,    -1,    -1,    -1,
      -1,    -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,   195,
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
     306,   307,   308,    24,    25,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    -1,    40,
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
      -1,    -1,    -1,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,    -1,
     211,    -1,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,    -1,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,    -1,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,     0,     1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    46,    -1,    -1,    -1,    50,    51,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    69,    -1,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    94,    95,    -1,    -1,    -1,    99,   100,   101,
     102,    -1,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,
      -1,   113,    -1,    -1,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,
     132,    -1,    -1,    -1,   136,    -1,    -1,    -1,   140,   141,
      -1,   143,    -1,   145,   146,    -1,    -1,    -1,   150,   151,
      -1,    -1,   154,   155,   156,   157,   158,   159,    -1,    -1,
     162,    -1,    -1,    -1,    -1,   167,   168,    -1,    -1,   171,
      -1,    -1,    -1,    -1,   176,    -1,    -1,   179,    -1,    -1,
      -1,    -1,   184,   185,   186,   187,   188,    -1,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,   199,   200,    -1,
     202,   203,   204,   205,   206,   207,    -1,   209,    -1,   211,
      -1,    -1,    -1,    -1,   216,   217,   218,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     232,    -1,   234,    -1,   236,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,
      -1,   253
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
     307,   308,   309,   321,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   342,   343,   344,   345,   346,   347,   351,   352,   353,
     357,   359,   360,   362,   369,   371,   374,   375,   376,   378,
     379,   380,   381,   382,   384,   385,   387,   388,   389,   390,
     391,   392,   394,   395,   398,   399,   400,   401,   406,   408,
     410,   411,   416,   435,   438,   442,   445,   446,   451,   452,
     453,   454,   456,   457,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   503,   504,   505,   519,   520,   522,   523,
     524,   525,   526,   527,   528,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   548,   549,   550,   551,   556,
     557,   558,   559,   560,   561,   564,   622,   624,   625,   626,
      33,    34,    49,   214,   377,   378,   379,   377,   377,   156,
     156,    37,    38,    40,    41,    47,    56,    57,    74,    79,
     111,   112,   113,   160,   219,   260,   286,   294,   302,   358,
     359,   363,   364,   365,   160,   153,   156,   153,   156,   153,
     156,     1,    66,    71,   118,   403,   156,   366,   156,    24,
      34,    60,   118,   272,   415,   417,   418,   153,   156,   156,
     156,   118,   153,   156,   156,   156,    76,   153,   220,   221,
     122,   122,   122,   153,   156,    29,    39,    43,    45,    46,
      47,    48,    51,    59,    67,    70,    72,    73,    75,    90,
      91,    97,   105,   112,   114,   115,   135,   138,   139,   169,
     172,   180,   181,   189,   201,   223,   225,   227,   228,   235,
     237,   238,   239,   242,   243,   487,   624,   625,   122,   118,
     386,   122,   122,    39,    44,    45,    59,    61,    62,    70,
      97,   224,   624,   118,   122,   122,   184,   377,   379,    48,
      72,    73,   118,   153,   187,   243,   398,   400,   410,   624,
     153,   122,    16,   623,   624,    18,    19,   624,   122,   122,
     122,   479,   153,    30,   213,   215,   224,   226,   156,   224,
     226,   224,   224,   229,   118,   240,   240,   241,   156,   153,
     381,   323,     0,   325,   326,    33,    49,   328,   345,     1,
     190,   322,   190,   322,   112,   360,   380,   398,   107,   190,
     107,   190,    42,    46,    51,    69,   168,   171,   186,   211,
     393,   402,   407,   408,   409,   423,   424,   428,   167,    92,
     132,   140,   141,   143,   151,   155,   157,   162,   179,   202,
     203,   204,   205,   206,   207,   471,   472,   248,    99,   158,
     176,   198,   117,   146,   159,   193,   200,   209,   136,   150,
      50,   199,   101,   102,   158,   176,   470,   153,   476,   479,
     191,   192,   154,   491,   492,   487,   491,   487,   156,   491,
     121,   145,   156,   184,   184,   184,    29,   361,   494,   361,
     622,   182,   195,   182,   195,   166,   182,   625,   624,   169,
     201,    47,   624,   152,   118,    45,    47,    79,   106,   168,
     623,   220,   221,   222,   245,   595,   624,   624,   303,   137,
     142,   112,   286,   294,   363,   623,   378,   379,   187,   378,
      45,    62,   187,   544,   545,   398,   187,   193,   624,   412,
     413,   624,   283,   283,   412,   118,   419,   118,   187,   367,
     368,   153,   383,   398,     1,   160,   622,   113,   160,   341,
     622,   624,   118,   142,   107,   398,    29,   187,   623,   624,
     624,   436,   437,   624,   378,   187,   398,   398,   546,   624,
     378,   153,   153,   398,   187,   193,   624,   624,   142,   436,
     184,   184,   156,   156,   156,   624,   153,   187,   186,    35,
     507,   508,   509,   398,     8,   175,    17,   398,   213,    29,
     399,   399,   187,   399,   399,   399,   399,   230,   562,   563,
     624,   190,   190,   399,   398,   379,   398,   244,   396,   397,
     190,   322,   190,   322,     3,   329,   345,   375,   329,   345,
     375,    33,   346,   375,   346,   375,   386,   386,   399,   118,
     168,   170,   170,   380,   399,   399,   453,   454,   456,   456,
     456,   456,   455,   456,   456,   456,    70,   457,   461,   461,
     460,   462,   462,   462,   462,   463,   463,   464,   464,   230,
      94,    94,    94,   184,   398,   479,   479,   398,   492,   187,
     399,   502,   623,   149,   187,   502,   107,   187,   187,   107,
     107,   366,    29,   625,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,   348,   349,   350,    94,   137,   142,
     354,   355,   356,   624,   160,   160,   348,   622,   127,   132,
      54,    56,   100,   250,   263,   265,   276,   277,   278,   280,
     282,   596,   597,   598,   599,   600,   601,   608,   614,   615,
     245,    94,   298,   624,   142,   399,   118,   624,   624,   132,
     184,   184,   187,   187,   184,   107,   187,   107,   187,   107,
      36,    94,    96,   147,   414,   415,   530,   624,    55,   216,
     253,   404,   405,   624,    94,   107,   187,   377,   187,   623,
      96,    45,   623,   622,    96,   142,   530,   624,   399,   418,
     184,   187,   187,   187,   187,   107,   188,   147,   530,   184,
     187,   187,   153,   184,   378,   378,   184,   107,   187,   107,
     187,   142,   530,   399,   188,   398,   398,   398,   624,   508,
     509,   130,   196,   184,   184,   131,   190,    94,   217,   218,
     232,    94,   217,   218,   232,    94,   236,   224,   107,   234,
     142,   190,   187,    48,    72,    73,   243,   400,   410,   184,
     488,   568,   397,   345,    33,    33,   190,   322,   190,   113,
     624,   170,   399,   429,   430,   118,   425,   426,   456,   153,
     156,   258,   475,   494,   569,   572,   573,   574,   575,   576,
     580,   582,   584,   585,    47,   152,   156,   210,   531,   533,
     535,   536,   552,   553,   554,   555,   624,   531,   529,   535,
     529,   184,   185,   107,   187,   187,   494,   148,   165,   148,
     165,   137,   383,   366,   349,   132,   533,   356,   399,   530,
     622,   622,   128,   129,   622,   276,   277,   278,   282,   624,
     262,   273,   262,   273,    29,   285,    96,   113,   156,   602,
     605,   596,    39,    44,    59,    61,    70,    97,   224,   370,
     536,   226,   298,   307,   399,   624,    94,   298,   622,   153,
     546,   547,   624,   546,   547,   118,   413,   127,   531,   118,
     399,   147,   415,   147,    36,   147,   414,   415,   147,   530,
     253,    53,    58,    77,   118,   414,   420,   421,   422,   405,
     530,   531,   368,    94,   184,   197,   132,   340,   622,   160,
     132,    96,   340,   399,   142,   415,   153,   118,   399,   399,
     147,   100,   439,   440,   441,   443,   444,   100,   447,   448,
     449,   450,   378,   184,   184,   153,   546,   546,   399,   142,
     190,   399,   187,   187,   187,    35,   509,   130,   196,     9,
      10,   103,   123,   125,   153,   194,   504,   506,   517,   518,
     521,    29,   231,   233,   399,   399,   399,   231,   233,   399,
     399,   399,   399,   399,   399,   118,   399,   399,   380,   156,
     156,   156,   153,   186,   244,   565,   566,   209,   381,   190,
     113,   375,   375,   375,   429,    95,   106,   116,   127,   431,
     432,   433,   434,   107,   624,   107,   398,   569,   576,   153,
     284,   458,   621,    96,   169,   251,   252,   254,   261,   271,
     283,   570,   571,   590,   591,   592,   593,   616,   619,   257,
     259,   577,   595,   266,   581,   617,   246,   247,   269,   586,
     587,   156,   156,   533,   156,   144,   176,   193,   532,   144,
     399,   137,   383,   548,   355,   285,    29,    96,   113,   156,
     609,    29,   602,   532,   477,   286,   305,   530,   370,   226,
     190,   377,   187,   187,   144,   187,   187,   413,   147,   414,
     624,   399,   147,   399,   127,   399,   147,   415,   147,   399,
     147,   118,   118,   399,   624,   422,    77,   531,   380,   399,
     622,   107,   340,   399,   142,   377,   437,   399,   399,   113,
     440,   441,   100,   186,   113,   441,   444,   118,   531,   100,
     113,   448,   100,   113,   450,   184,   377,   187,   187,   399,
     197,   447,   132,   194,   506,     7,   378,   624,   194,   517,
     190,   232,   232,   232,   232,   236,   563,   186,   398,   398,
     398,   568,   566,   488,   622,   128,   129,   433,   434,   434,
     430,   106,   427,   426,   184,   187,   569,   583,   249,   216,
     253,   267,   274,   620,    96,   255,   256,   618,   249,   573,
     620,   460,   590,   574,   147,   281,   578,   579,   618,   285,
     589,    78,   588,   187,   193,   531,   534,   187,   187,   187,
      29,   136,   200,   611,   612,   613,    29,   610,   611,   270,
     606,   107,   603,   170,   624,   256,   477,   184,   399,   147,
     399,   147,   414,   399,   147,   399,   399,   624,   624,   421,
     399,   126,   126,    96,   622,   399,   184,   186,   186,   399,
     380,   399,   186,   186,   624,   186,   118,   531,   118,   186,
     118,   531,   186,   184,   113,   509,   624,   194,   184,   509,
     624,   399,   399,   399,   399,   399,   399,   187,   187,   187,
     153,   567,   434,   622,   184,   462,    52,   129,   460,   460,
     268,   275,   285,   594,   594,   575,   153,   279,    94,   187,
     107,   187,   609,   609,   613,   107,   187,    29,   607,   618,
     604,   605,   187,   372,   373,   477,   118,   224,   306,   286,
     170,   399,   399,   147,   399,    53,   380,   399,   340,   399,
     380,    94,   380,   399,   624,   186,   624,   399,   624,   186,
     380,   118,    93,   183,   510,   509,   624,   196,   509,   197,
     447,   398,   460,   460,   198,   398,   531,   531,    94,    29,
     264,   107,   107,   434,   530,   624,   118,   224,   624,   372,
     399,   118,   531,    94,   186,    94,   624,     5,   133,   513,
     514,   516,   518,    28,   134,   511,   512,   515,   518,   196,
     509,   196,   113,   184,   460,   184,   531,   605,   373,   434,
     304,   624,   118,   224,   624,   186,   531,   380,   399,   531,
     186,    93,   133,   516,   183,   134,   515,   196,   118,   399,
     304,   624,   118,   380,   399,   186,   186,   624,   292,   304,
     624,   186,   305,   399,   305,   477,   477,   198,   286,   624,
     224,   118,   624,   305,   477
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
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   320,   321,   321,   322,   323,   323,   323,   323,   324,
     324,   325,   325,   325,   325,   325,   325,   325,   325,   326,
     326,   326,   326,   327,   328,   328,   328,   329,   329,   329,
     329,   329,   330,   330,   330,   330,   330,   330,   330,   330,
     331,   331,   332,   333,   334,   334,   335,   335,   336,   336,
     337,   337,   337,   337,   338,   338,   338,   339,   339,   339,
     339,   340,   340,   341,   341,   342,   342,   342,   342,   343,
     344,   344,   345,   345,   345,   346,   346,   346,   346,   346,
     346,   346,   346,   347,   347,   348,   348,   349,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   351,   352,
     353,   354,   354,   355,   355,   355,   356,   357,   357,   357,
     358,   358,   358,   358,   359,   359,   360,   360,   360,   360,
     361,   361,   362,   362,   363,   363,   364,   364,   365,   365,
     366,   366,   366,   366,   367,   367,   368,   368,   369,   369,
     369,   369,   370,   370,   371,   371,   372,   372,   373,   373,
     373,   373,   374,   374,   374,   374,   375,   376,   376,   376,
     377,   377,   377,   378,   378,   379,   379,   380,   380,   380,
     380,   380,   380,   380,   380,   380,   380,   380,   380,   381,
     381,   382,   383,   384,   385,   385,   385,   386,   386,   386,
     386,   387,   388,   389,   390,   391,   391,   392,   393,   394,
     395,   396,   396,   397,   398,   398,   399,   399,   399,   399,
     399,   399,   400,   400,   400,   400,   400,   400,   400,   401,
     402,   403,   403,   404,   404,   404,   405,   405,   406,   406,
     407,   408,   408,   408,   409,   409,   409,   409,   409,   410,
     410,   411,   411,   412,   412,   412,   413,   413,   413,   413,
     413,   413,   413,   413,   413,   413,   413,   413,   414,   415,
     416,   417,   417,   418,   418,   418,   418,   419,   419,   420,
     420,   420,   421,   421,   421,   422,   422,   422,   423,   424,
     425,   425,   426,   426,   427,   428,   428,   429,   429,   430,
     430,   431,   431,   431,   431,   431,   431,   431,   432,   432,
     433,   433,   434,   435,   435,   436,   436,   437,   437,   438,
     439,   439,   440,   441,   441,   442,   443,   443,   444,   445,
     445,   446,   446,   447,   447,   448,   448,   449,   449,   450,
     450,   451,   452,   452,   453,   453,   454,   454,   454,   454,
     454,   455,   454,   454,   454,   454,   456,   456,   457,   457,
     458,   458,   459,   459,   460,   460,   460,   461,   461,   461,
     461,   461,   462,   462,   462,   463,   463,   463,   464,   464,
     465,   465,   466,   466,   467,   467,   468,   468,   469,   469,
     469,   469,   470,   470,   470,   471,   471,   471,   471,   471,
     471,   472,   472,   472,   473,   473,   473,   473,   474,   474,
     475,   475,   476,   476,   476,   477,   477,   477,   477,   478,
     479,   479,   479,   480,   480,   481,   481,   481,   481,   482,
     482,   483,   483,   483,   483,   483,   483,   483,   484,   484,
     485,   485,   486,   486,   486,   486,   486,   487,   487,   488,
     488,   489,   489,   489,   489,   490,   490,   490,   490,   491,
     491,   492,   493,   493,   493,   493,   493,   493,   493,   493,
     493,   493,   494,   494,   495,   495,   495,   496,   497,   497,
     498,   499,   500,   501,   501,   502,   502,   503,   503,   504,
     504,   504,   505,   505,   505,   505,   505,   505,   506,   506,
     507,   507,   508,   509,   509,   510,   510,   511,   511,   512,
     512,   512,   512,   513,   513,   514,   514,   514,   514,   515,
     515,   516,   516,   517,   517,   517,   517,   518,   518,   518,
     518,   519,   519,   520,   520,   521,   522,   522,   522,   522,
     522,   522,   523,   524,   524,   525,   525,   526,   527,   528,
     528,   529,   529,   530,   531,   531,   531,   532,   532,   532,
     533,   533,   533,   533,   533,   534,   534,   535,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   537,   538,   538,
     538,   539,   540,   541,   541,   541,   542,   542,   542,   542,
     542,   543,   544,   544,   544,   544,   544,   544,   544,   545,
     546,   547,   548,   549,   549,   550,   551,   552,   552,   553,
     554,   554,   555,   556,   556,   556,   557,   557,   557,   557,
     557,   557,   557,   557,   557,   557,   558,   558,   559,   559,
     560,   561,   562,   562,   563,   564,   565,   565,   566,   567,
     568,   568,   569,   570,   570,   571,   571,   572,   572,   573,
     573,   574,   574,   575,   575,   576,   577,   577,   578,   578,
     579,   580,   580,   580,   581,   581,   582,   583,   583,   584,
     585,   585,   586,   586,   587,   587,   587,   588,   588,   589,
     589,   590,   590,   590,   590,   590,   591,   592,   593,   594,
     594,   594,   595,   595,   596,   596,   596,   596,   596,   596,
     596,   596,   597,   597,   597,   597,   598,   598,   599,   600,
     600,   601,   601,   601,   602,   602,   603,   603,   604,   604,
     605,   606,   606,   607,   607,   608,   608,   608,   609,   609,
     610,   610,   611,   611,   612,   612,   613,   613,   614,   615,
     615,   616,   616,   616,   617,   618,   618,   618,   618,   619,
     619,   620,   620,   621,   622,   623,   623,   624,   624,   624,
     624,   624,   624,   624,   624,   624,   624,   624,   624,   624,
     624,   624,   624,   625,   625,   625,   625,   625,   625,   625,
     625,   625,   625,   625,   625,   625,   625,   625,   625,   625,
     625,   625,   625,   625,   625,   625,   625,   625,   625,   625,
     625,   625,   625,   625,   625,   625,   625,   625,   625,   625,
     625,   625,   625,   625,   625,   625,   625,   625,   625,   625,
     625,   625,   625,   625,   625,   625,   625,   625,   625,   625,
     625,   625,   625,   625,   625,   625,   625,   625,   625,   625,
     625,   625,   625,   625,   625,   625,   625,   625,   625,   625,
     625,   625,   625,   625,   625,   625,   625,   625,   625,   625,
     625,   625,   625,   625,   625,   625,   625,   625,   625,   625,
     625,   625,   625,   625,   625,   625,   625,   625,   625,   625,
     625,   625,   625,   625,   625,   625,   625,   625,   625,   625,
     625,   625,   625,   625,   625,   625,   625,   625,   625,   625,
     625,   625,   625,   625,   625,   625,   625,   625,   625,   625,
     625,   625,   625,   625,   625,   625,   625,   625,   625,   625,
     625,   625,   625,   625,   625,   625,   625,   625,   625,   625,
     625,   625,   625,   625,   625,   625,   625,   625,   625,   625,
     625,   625,   625,   625,   625,   625,   625,   625,   625,   625,
     625,   625,   625,   625,   625,   625,   625,   625,   625,   625,
     625,   625,   625,   625,   625,   625,   625,   625,   625,   625,
     625,   625,   626,   626
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
       2,     3,     3,     1,     4,     3,     3,     5,     4,     6,
       4,     6,     5,     7,     4,     5,     5,     6,     3,     3,
       2,     1,     3,     4,     5,     3,     6,     4,     5,     1,
       2,     3,     1,     2,     1,     6,     3,     3,     2,     3,
       1,     3,     2,     3,     2,     3,     4,     1,     3,     1,
       2,     1,     1,     1,     2,     2,     2,     3,     1,     1,
       2,     2,     2,     5,     5,     1,     4,     3,     4,     8,
       1,     2,     3,     2,     3,     8,     1,     2,     3,     8,
      10,     8,    10,     1,     2,     4,     7,     1,     2,     4,
       7,     8,     1,     3,     1,     3,     1,     3,     3,     3,
       3,     0,     4,     3,     3,     3,     1,     5,     1,     3,
       0,     1,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     4,
       1,     4,     1,     4,     1,     4,     1,     2,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     5,     5,     6,     3,     4,
       1,     2,     3,     2,     2,     1,     2,     2,     1,     1,
       1,     3,     3,     1,     1,     1,     2,     1,     2,     2,
       1,     2,     2,     2,     2,     2,     2,     2,     1,     2,
       2,     1,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     4,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       1,     4,     4,     3,     4,     1,     3,     1,     1,     1,
       1,     1,     4,     5,     8,     9,     9,    10,     1,     2,
       1,     2,     6,     0,     1,     3,     3,     0,     1,     1,
       1,     2,     2,     0,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     2,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     4,     3,     7,     3,     7,     4,     4,     3,
       7,     1,     2,     2,     1,     2,     3,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
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
  "\"'keys'\"", "\"'BOM_UTF8'\"", "RANGE_REDUCE", "SEQUENCE_TYPE_REDUCE",
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
       321,     0,    -1,   323,    -1,   309,   323,    -1,     1,     3,
      -1,   325,    -1,   324,   325,    -1,   326,    -1,   324,   326,
      -1,   214,   215,    29,   190,    -1,   214,   215,    29,   131,
      29,   190,    -1,   328,   190,   375,    -1,   345,   190,   375,
      -1,   328,   190,   345,   190,   375,    -1,   375,    -1,   328,
     322,   375,    -1,   345,   322,   375,    -1,   328,   190,   345,
     322,   375,    -1,   328,   322,   345,   190,   375,    -1,   327,
      -1,   327,   328,   190,    -1,   327,   345,   190,    -1,   327,
     328,   190,   345,   190,    -1,    34,   160,   623,   132,   622,
     190,    -1,   329,    -1,   328,   190,   329,    -1,   328,   322,
     329,    -1,   330,    -1,   338,    -1,   343,    -1,   344,    -1,
     352,    -1,   331,    -1,   332,    -1,   333,    -1,   334,    -1,
     335,    -1,   336,    -1,   337,    -1,   556,    -1,    33,    38,
     182,    -1,    33,    38,   195,    -1,    33,   113,   106,   622,
      -1,    33,    37,   622,    -1,    33,    40,   182,    -1,    33,
      40,   195,    -1,    33,    57,   169,    -1,    33,    57,   201,
      -1,    33,   113,   168,   127,   128,    -1,    33,   113,   168,
     127,   129,    -1,    33,    41,   182,   107,   148,    -1,    33,
      41,   182,   107,   165,    -1,    33,    41,   166,   107,   148,
      -1,    33,    41,   166,   107,   165,    -1,   339,    -1,   342,
      -1,    49,    24,     1,    -1,    49,    60,   622,    -1,    49,
      60,   341,   622,    -1,    49,    60,   622,    96,   340,    -1,
      49,    60,   341,   622,    96,   340,    -1,   622,    -1,   340,
     107,   622,    -1,   160,   623,   132,    -1,   113,    45,   160,
      -1,    49,    34,   622,    -1,    49,    34,   160,   623,   132,
     622,    -1,    49,    34,   622,    96,   340,    -1,    49,    34,
     160,   623,   132,   622,    96,   340,    -1,    33,   160,   623,
     132,   622,    -1,    33,   113,    45,   160,   622,    -1,    33,
     113,    47,   160,   622,    -1,   346,    -1,   345,   190,   346,
      -1,   345,   322,   346,    -1,   347,    -1,   351,    -1,   353,
      -1,   357,    -1,   362,    -1,   369,    -1,   371,    -1,   374,
      -1,    33,   113,    79,   348,    -1,    33,    79,   624,   348,
      -1,   349,    -1,   348,   349,    -1,   350,   132,   548,    -1,
      80,    -1,    88,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    89,    -1,    85,    -1,    86,    -1,    87,    -1,
      33,    56,   624,    29,    -1,    33,   260,   595,    -1,    33,
     111,   152,   354,    -1,    94,   533,   355,    -1,   355,    -1,
     356,    -1,   137,    -1,   137,   356,    -1,   142,   399,    -1,
      33,   358,   142,   399,    -1,    33,   358,   137,    -1,    33,
     358,   137,   142,   399,    -1,   112,   118,   624,    -1,   112,
     118,   624,   530,    -1,   359,   112,   118,   624,    -1,   359,
     112,   118,   624,   530,    -1,   360,    -1,   359,   360,    -1,
      26,    -1,    26,   156,   361,   187,    -1,    27,    -1,    27,
     156,   361,   187,    -1,   494,    -1,   361,   107,   494,    -1,
      33,   363,    -1,    33,   359,   363,    -1,   364,    -1,   365,
      -1,    47,   625,   366,   383,    -1,    47,   625,   366,   137,
      -1,    74,    47,   625,   366,   383,    -1,    74,    47,   625,
     366,   137,    -1,   156,   187,    -1,   156,   367,   187,    -1,
     156,   187,    94,   531,    -1,   156,   367,   187,    94,   531,
      -1,   368,    -1,   367,   107,   368,    -1,   118,   624,    -1,
     118,   624,   530,    -1,    33,   286,   624,    -1,    33,   286,
     624,    94,   370,    -1,    33,   359,   286,   624,    -1,    33,
     359,   286,   624,    94,   370,    -1,   536,    -1,   536,   532,
      -1,    33,   294,   624,   298,   226,   477,   170,   372,    -1,
      33,   359,   294,   624,   298,   226,   477,   170,   372,    -1,
     373,    -1,   372,   107,   373,    -1,   477,    -1,   477,   530,
      -1,   477,   434,    -1,   477,   530,   434,    -1,    33,   302,
     303,   624,   298,   286,   624,   118,   624,   304,   399,    -1,
      33,   302,   303,   624,   298,   286,   624,   224,   118,   624,
     304,   292,   305,   477,    -1,    33,   302,   303,   624,   298,
     286,   624,   306,   224,   118,   624,   304,   399,    -1,    33,
     302,   303,   624,   307,   305,   256,   286,   624,   224,   118,
     624,   305,   477,   198,   286,   624,   224,   118,   624,   305,
     477,    -1,   376,    -1,   378,    -1,   379,    -1,    -1,   378,
      -1,   379,    -1,    -1,   398,    -1,   379,   398,    -1,   380,
      -1,   379,   380,    -1,   381,    -1,   384,    -1,   387,    -1,
     388,    -1,   389,    -1,   390,    -1,   391,    -1,   392,    -1,
     394,    -1,   446,    -1,   442,    -1,   395,    -1,   153,   379,
     184,    -1,   153,   184,    -1,   153,   377,   184,    -1,   153,
     377,   184,    -1,   385,   190,    -1,   385,   107,   386,    -1,
     112,   386,    -1,   359,   112,   386,    -1,   118,   624,    -1,
     118,   624,   530,    -1,   118,   624,   142,   399,    -1,   118,
     624,   530,   142,   399,    -1,   118,   624,   142,   399,   190,
      -1,   400,   190,    -1,   239,   241,   399,   190,    -1,   242,
     156,   398,   187,   380,    -1,   237,   240,   190,    -1,   238,
     240,   190,    -1,   410,   393,    -1,   186,   380,    -1,    48,
     156,   398,   187,   197,   380,   126,   380,    -1,   243,   381,
     396,    -1,   397,    -1,   396,   397,    -1,   244,   568,   381,
      -1,   399,    -1,   398,   107,   399,    -1,   401,    -1,   438,
      -1,   445,    -1,   451,    -1,   564,    -1,   400,    -1,   452,
      -1,   435,    -1,   557,    -1,   558,    -1,   560,    -1,   559,
      -1,   561,    -1,   410,   402,    -1,   186,   399,    -1,    66,
     283,    -1,    71,   283,    -1,   216,    -1,   253,    -1,    55,
     253,    -1,   404,   420,    77,   399,    -1,   404,    77,   399,
      -1,    46,   403,   419,   405,   405,    -1,    46,   403,   419,
     405,    -1,    42,   118,   624,    -1,   411,    -1,   416,    -1,
     406,    -1,   408,    -1,   423,    -1,   428,    -1,   424,    -1,
     407,    -1,   408,    -1,   410,   409,    -1,    46,   118,   412,
      -1,    46,     1,   412,    -1,   413,    -1,   412,   107,   118,
     413,    -1,   412,   107,   413,    -1,   624,   147,   399,    -1,
     624,    36,   127,   147,   399,    -1,   624,   530,   147,   399,
      -1,   624,   530,    36,   127,   147,   399,    -1,   624,   414,
     147,   399,    -1,   624,    36,   127,   414,   147,   399,    -1,
     624,   530,   414,   147,   399,    -1,   624,   530,    36,   127,
     414,   147,   399,    -1,   624,   415,   147,   399,    -1,   624,
     530,   415,   147,   399,    -1,   624,   414,   415,   147,   399,
      -1,   624,   530,   414,   415,   147,   399,    -1,    96,   118,
     624,    -1,   272,   118,   624,    -1,    51,   417,    -1,   418,
      -1,   417,   107,   418,    -1,   118,   624,   142,   399,    -1,
     118,   624,   530,   142,   399,    -1,   415,   142,   399,    -1,
     118,   624,   530,   415,   142,   399,    -1,   118,   624,   147,
     399,    -1,   118,   624,   530,   147,   399,    -1,   421,    -1,
     118,   624,    -1,   118,   624,   421,    -1,   414,    -1,   414,
     422,    -1,   422,    -1,    58,   118,   624,    53,   118,   624,
      -1,    53,   118,   624,    -1,    58,   118,   624,    -1,   211,
     399,    -1,   171,   170,   425,    -1,   426,    -1,   425,   107,
     426,    -1,   118,   624,    -1,   118,   624,   427,    -1,   106,
     622,    -1,   168,   170,   429,    -1,    69,   168,   170,   429,
      -1,   430,    -1,   429,   107,   430,    -1,   399,    -1,   399,
     431,    -1,   432,    -1,   433,    -1,   434,    -1,   432,   433,
      -1,   432,   434,    -1,   433,   434,    -1,   432,   433,   434,
      -1,    95,    -1,   116,    -1,   127,   128,    -1,   127,   129,
      -1,   106,   622,    -1,    67,   118,   436,   188,   399,    -1,
     135,   118,   436,   188,   399,    -1,   437,    -1,   436,   107,
     118,   437,    -1,   624,   147,   399,    -1,   624,   530,   147,
     399,    -1,    72,   156,   398,   187,   439,   113,   186,   399,
      -1,   440,    -1,   439,   440,    -1,   441,   186,   399,    -1,
     100,   399,    -1,   441,   100,   399,    -1,    72,   156,   398,
     187,   443,   113,   186,   380,    -1,   444,    -1,   443,   444,
      -1,   441,   186,   380,    -1,    73,   156,   398,   187,   447,
     113,   186,   399,    -1,    73,   156,   398,   187,   447,   113,
     118,   624,   186,   399,    -1,    73,   156,   398,   187,   449,
     113,   186,   380,    -1,    73,   156,   398,   187,   447,   113,
     118,   624,   186,   380,    -1,   448,    -1,   447,   448,    -1,
     100,   531,   186,   399,    -1,   100,   118,   624,    94,   531,
     186,   399,    -1,   450,    -1,   449,   450,    -1,   100,   531,
     186,   380,    -1,   100,   118,   624,    94,   531,   186,   380,
      -1,    48,   156,   398,   187,   197,   399,   126,   399,    -1,
     453,    -1,   452,   167,   453,    -1,   454,    -1,   453,    92,
     454,    -1,   456,    -1,   456,   471,   456,    -1,   456,   472,
     456,    -1,   456,   132,   456,    -1,   456,   162,   456,    -1,
      -1,   456,   157,   455,   456,    -1,   456,   155,   456,    -1,
     456,   143,   456,    -1,   456,   141,   456,    -1,   457,    -1,
     457,   248,    70,   569,   458,    -1,   459,    -1,   459,    99,
     457,    -1,    -1,   621,    -1,   460,    -1,   460,   198,   460,
      -1,   461,    -1,   460,   176,   461,    -1,   460,   158,   461,
      -1,   462,    -1,   461,   193,   462,    -1,   461,   117,   462,
      -1,   461,   146,   462,    -1,   461,   159,   462,    -1,   463,
      -1,   462,   200,   463,    -1,   462,   209,   463,    -1,   464,
      -1,   463,   150,   464,    -1,   463,   136,   464,    -1,   465,
      -1,   465,    50,   230,   531,    -1,   466,    -1,   466,   199,
      94,   531,    -1,   467,    -1,   467,   101,    94,   529,    -1,
     468,    -1,   468,   102,    94,   529,    -1,   470,    -1,   469,
     470,    -1,   176,    -1,   158,    -1,   469,   176,    -1,   469,
     158,    -1,   473,    -1,   477,    -1,   474,    -1,   202,    -1,
     207,    -1,   206,    -1,   205,    -1,   204,    -1,   203,    -1,
     151,    -1,   179,    -1,   140,    -1,    75,   153,   378,   184,
      -1,    75,   221,   153,   378,   184,    -1,    75,   220,   153,
     378,   184,    -1,    75,    76,   546,   153,   378,   184,    -1,
     475,   153,   184,    -1,   475,   153,   398,   184,    -1,   476,
      -1,   475,   476,    -1,   177,   624,    17,    -1,   177,    18,
      -1,   177,    19,    -1,   478,    -1,   478,   479,    -1,   192,
     479,    -1,   479,    -1,   191,    -1,   480,    -1,   480,   191,
     479,    -1,   480,   192,   479,    -1,   481,    -1,   490,    -1,
     482,    -1,   482,   491,    -1,   485,    -1,   485,   491,    -1,
     483,   487,    -1,   484,    -1,   105,   122,    -1,   114,   122,
      -1,    97,   122,    -1,   189,   122,    -1,   115,   122,    -1,
     139,   122,    -1,   138,   122,    -1,   487,    -1,    98,   487,
      -1,   486,   487,    -1,   120,    -1,   172,   122,    -1,    90,
     122,    -1,   181,   122,    -1,   180,   122,    -1,    91,   122,
      -1,   536,    -1,   488,    -1,   624,    -1,   489,    -1,   193,
      -1,    11,    -1,    12,    -1,    20,    -1,   493,    -1,   490,
     491,    -1,   490,   156,   187,    -1,   490,   156,   502,   187,
      -1,   492,    -1,   491,   492,    -1,   154,   398,   185,    -1,
     494,    -1,   496,    -1,   497,    -1,   498,    -1,   501,    -1,
     503,    -1,   499,    -1,   500,    -1,   549,    -1,   382,    -1,
     495,    -1,   548,    -1,   110,    -1,   149,    -1,   124,    -1,
     118,   624,    -1,   156,   187,    -1,   156,   398,   187,    -1,
     119,    -1,   169,   153,   398,   184,    -1,   201,   153,   398,
     184,    -1,   625,   156,   187,    -1,   625,   156,   502,   187,
      -1,   399,    -1,   502,   107,   399,    -1,   504,    -1,   522,
      -1,   505,    -1,   519,    -1,   520,    -1,   157,   624,   509,
     130,    -1,   157,   624,   507,   509,   130,    -1,   157,   624,
     509,   196,   194,   624,   509,   196,    -1,   157,   624,   509,
     196,   506,   194,   624,   509,   196,    -1,   157,   624,   507,
     509,   196,   194,   624,   509,   196,    -1,   157,   624,   507,
     509,   196,   506,   194,   624,   509,   196,    -1,   517,    -1,
     506,   517,    -1,   508,    -1,   507,   508,    -1,    35,   624,
     509,   132,   509,   510,    -1,    -1,    35,    -1,   183,   511,
     183,    -1,    93,   513,    93,    -1,    -1,   512,    -1,   134,
      -1,   515,    -1,   512,   134,    -1,   512,   515,    -1,    -1,
     514,    -1,   133,    -1,   516,    -1,   514,   133,    -1,   514,
     516,    -1,    28,    -1,   518,    -1,     5,    -1,   518,    -1,
     504,    -1,    10,    -1,   521,    -1,   518,    -1,     9,    -1,
     123,    -1,   125,    -1,   153,   378,   184,    -1,   212,    30,
     213,    -1,   212,   213,    -1,   174,   623,   175,    -1,   174,
     623,     8,    -1,   103,     7,    -1,   523,    -1,   524,    -1,
     525,    -1,   526,    -1,   527,    -1,   528,    -1,    43,   153,
     378,   184,    -1,    21,   377,   184,    -1,    45,   153,   398,
     184,   153,   377,   184,    -1,    22,   377,   184,    -1,    97,
     153,   398,   184,   153,   377,   184,    -1,    70,   153,   378,
     184,    -1,    39,   153,   378,   184,    -1,    23,   377,   184,
      -1,    59,   153,   398,   184,   153,   377,   184,    -1,   535,
      -1,   535,   144,    -1,    94,   531,    -1,   533,    -1,   533,
     532,    -1,   210,   156,   187,    -1,   144,    -1,   193,    -1,
     176,    -1,   535,    -1,   536,    -1,   152,   156,   187,    -1,
     552,    -1,   555,    -1,   531,    -1,   534,   107,   531,    -1,
     624,    -1,   538,    -1,   544,    -1,   542,    -1,   545,    -1,
     543,    -1,   541,    -1,   540,    -1,   539,    -1,   537,    -1,
     224,   156,   187,    -1,    44,   156,   187,    -1,    44,   156,
     544,   187,    -1,    44,   156,   545,   187,    -1,    70,   156,
     187,    -1,    39,   156,   187,    -1,    59,   156,   187,    -1,
      59,   156,   623,   187,    -1,    59,   156,    29,   187,    -1,
      97,   156,   187,    -1,    97,   156,   624,   187,    -1,    97,
     156,   624,   107,   546,   187,    -1,    97,   156,   193,   187,
      -1,    97,   156,   193,   107,   546,   187,    -1,    61,   156,
     624,   187,    -1,    45,   156,   187,    -1,    45,   156,   624,
     187,    -1,    45,   156,   624,   107,   546,   187,    -1,    45,
     156,   624,   107,   547,   187,    -1,    45,   156,   193,   187,
      -1,    45,   156,   193,   107,   546,   187,    -1,    45,   156,
     193,   107,   547,   187,    -1,    62,   156,   624,   187,    -1,
     624,    -1,   624,   144,    -1,    29,    -1,   550,    -1,   551,
      -1,   624,   145,   149,    -1,    47,   366,   383,    -1,   553,
      -1,   554,    -1,    47,   156,   193,   187,    -1,    47,   156,
     187,    94,   531,    -1,    47,   156,   534,   187,    94,   531,
      -1,   156,   533,   187,    -1,    33,   219,   220,    -1,    33,
     219,   221,    -1,    33,   219,   222,    -1,   225,   224,   399,
     232,   399,    -1,   225,   224,   399,    94,   231,   232,   399,
      -1,   225,   224,   399,    94,   233,   232,   399,    -1,   225,
     224,   399,   217,   399,    -1,   225,   224,   399,   218,   399,
      -1,   225,   226,   399,   232,   399,    -1,   225,   226,   399,
      94,   231,   232,   399,    -1,   225,   226,   399,    94,   233,
     232,   399,    -1,   225,   226,   399,   217,   399,    -1,   225,
     226,   399,   218,   399,    -1,   223,   224,   399,    -1,   223,
     226,   399,    -1,   228,   224,   399,   236,   399,    -1,   228,
     229,   230,   224,   399,   236,   399,    -1,   227,   224,   399,
      94,   399,    -1,   235,   118,   562,   234,   399,   186,   399,
      -1,   563,    -1,   562,   107,   118,   563,    -1,   624,   142,
     399,    -1,   243,   153,   398,   184,   565,    -1,   566,    -1,
     565,   566,    -1,   244,   568,   567,    -1,   153,   398,   184,
      -1,   488,    -1,   568,   209,   488,    -1,   572,   570,    -1,
      -1,   571,    -1,   590,    -1,   571,   590,    -1,   573,    -1,
     572,   261,   573,    -1,   574,    -1,   573,   257,   574,    -1,
     575,    -1,   574,   259,   147,   575,    -1,   576,    -1,   258,
     576,    -1,   580,   577,   578,    -1,    -1,   595,    -1,    -1,
     579,    -1,   281,   153,   398,   184,    -1,   584,   581,    -1,
     156,   569,   187,    -1,   582,    -1,    -1,   617,    -1,   475,
     153,   583,   184,    -1,    -1,   569,    -1,   585,   586,    -1,
     494,    -1,   153,   398,   184,    -1,    -1,   587,    -1,   247,
     588,    -1,   246,   589,    -1,   269,    -1,    -1,    78,    -1,
      -1,   285,    -1,   591,    -1,   592,    -1,   593,    -1,   619,
      -1,   616,    -1,   169,    -1,   283,   460,   594,    -1,   252,
     618,   594,    -1,   285,    -1,   275,    -1,   268,    -1,   245,
     596,    -1,   595,   245,   596,    -1,   597,    -1,   598,    -1,
     599,    -1,   614,    -1,   600,    -1,   608,    -1,   601,    -1,
     615,    -1,   100,   273,    -1,   100,   262,    -1,   265,    -1,
     280,    -1,   250,   273,    -1,   250,   262,    -1,    56,   624,
      29,    -1,   276,    -1,    54,   276,    -1,   278,   602,    -1,
     278,   156,   602,   603,   187,    -1,    54,   278,    -1,   605,
      -1,   113,    -1,    -1,   107,   604,    -1,   605,    -1,   604,
     107,   605,    -1,    96,    29,   606,   607,    -1,    -1,   270,
      29,    -1,    -1,   618,   264,    -1,   277,   285,   609,   611,
      -1,   277,   285,   113,   611,    -1,    54,   277,   285,    -1,
      96,    29,    -1,   156,   610,   187,    -1,    29,    -1,   610,
     107,    29,    -1,    -1,   612,    -1,   613,    -1,   612,   613,
      -1,   200,   609,    -1,   136,   609,    -1,   263,    29,    -1,
     282,    -1,    54,   282,    -1,    96,   216,    -1,    96,   253,
      -1,   254,   249,    -1,   266,   618,   279,    -1,   255,   460,
      -1,    96,   129,   460,    -1,    96,    52,   460,    -1,   256,
     460,   198,   460,    -1,   271,   620,    -1,   251,   620,    -1,
     274,    -1,   267,    -1,   284,   249,   462,    -1,    29,    -1,
      16,    -1,   624,    -1,   625,    -1,    97,    -1,    39,    -1,
      44,    -1,    45,    -1,   152,    -1,    48,    -1,   224,    -1,
      59,    -1,    61,    -1,    62,    -1,    70,    -1,    73,    -1,
      72,    -1,   210,    -1,   242,    -1,   626,    -1,    24,    -1,
     214,    -1,   127,    -1,    38,    -1,   260,    -1,    37,    -1,
     221,    -1,   220,    -1,   146,    -1,    43,    -1,   258,    -1,
     259,    -1,   273,    -1,   262,    -1,   250,    -1,   284,    -1,
     276,    -1,   278,    -1,   277,    -1,   282,    -1,   254,    -1,
     249,    -1,    78,    -1,   216,    -1,   253,    -1,    52,    -1,
     222,    -1,   235,    -1,   301,    -1,   229,    -1,   202,    -1,
     207,    -1,   206,    -1,   205,    -1,   204,    -1,   203,    -1,
      96,    -1,   111,    -1,   112,    -1,   186,    -1,    46,    -1,
      36,    -1,    66,    -1,    71,    -1,    58,    -1,    53,    -1,
      55,    -1,    77,    -1,    42,    -1,   147,    -1,    51,    -1,
     211,    -1,   170,    -1,   171,    -1,   168,    -1,    69,    -1,
      95,    -1,   116,    -1,   128,    -1,   129,    -1,   106,    -1,
      67,    -1,   135,    -1,   188,    -1,   100,    -1,    94,    -1,
     197,    -1,   126,    -1,   167,    -1,    92,    -1,    50,    -1,
     230,    -1,   101,    -1,   198,    -1,   117,    -1,   159,    -1,
     200,    -1,   150,    -1,   136,    -1,    75,    -1,    76,    -1,
     102,    -1,   199,    -1,   151,    -1,   182,    -1,   195,    -1,
     160,    -1,   137,    -1,   131,    -1,   166,    -1,   148,    -1,
     165,    -1,    33,    -1,    40,    -1,    57,    -1,   113,    -1,
      41,    -1,    56,    -1,   215,    -1,    49,    -1,    60,    -1,
      34,    -1,    47,    -1,   272,    -1,   248,    -1,   281,    -1,
     283,    -1,   252,    -1,   266,    -1,   279,    -1,   271,    -1,
     251,    -1,   265,    -1,   280,    -1,   270,    -1,   264,    -1,
     263,    -1,   247,    -1,   246,    -1,   255,    -1,   256,    -1,
     285,    -1,   275,    -1,   274,    -1,   269,    -1,   267,    -1,
     268,    -1,   228,    -1,   234,    -1,   231,    -1,   225,    -1,
     218,    -1,   217,    -1,   219,    -1,   236,    -1,   226,    -1,
     227,    -1,   233,    -1,   223,    -1,   232,    -1,    65,    -1,
      63,    -1,    74,    -1,   169,    -1,   201,    -1,   241,    -1,
     239,    -1,   240,    -1,   237,    -1,   238,    -1,   243,    -1,
     244,    -1,   245,    -1,    64,    -1,   294,    -1,   292,    -1,
     293,    -1,   298,    -1,   299,    -1,   300,    -1,   295,    -1,
     296,    -1,   297,    -1,    79,    -1,    80,    -1,    81,    -1,
      82,    -1,    83,    -1,    84,    -1,    85,    -1,    86,    -1,
      87,    -1,    88,    -1,    89,    -1,   286,    -1,   287,    -1,
     288,    -1,   289,    -1,   290,    -1,   291,    -1,   302,    -1,
     303,    -1,   304,    -1,   305,    -1,   306,    -1,   307,    -1,
     308,    -1,    90,    -1,   105,    -1,   114,    -1,   172,    -1,
     180,    -1,   189,    -1,   138,    -1,    91,    -1,   115,    -1,
     139,    -1,   181,    -1,   622,   121,   623,    -1,    25,    -1
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
     874,   877,   881,   885,   887,   892,   896,   900,   906,   911,
     918,   923,   930,   936,   944,   949,   955,   961,   968,   972,
     976,   979,   981,   985,   990,   996,  1000,  1007,  1012,  1018,
    1020,  1023,  1027,  1029,  1032,  1034,  1041,  1045,  1049,  1052,
    1056,  1058,  1062,  1065,  1069,  1072,  1076,  1081,  1083,  1087,
    1089,  1092,  1094,  1096,  1098,  1101,  1104,  1107,  1111,  1113,
    1115,  1118,  1121,  1124,  1130,  1136,  1138,  1143,  1147,  1152,
    1161,  1163,  1166,  1170,  1173,  1177,  1186,  1188,  1191,  1195,
    1204,  1215,  1224,  1235,  1237,  1240,  1245,  1253,  1255,  1258,
    1263,  1271,  1280,  1282,  1286,  1288,  1292,  1294,  1298,  1302,
    1306,  1310,  1311,  1316,  1320,  1324,  1328,  1330,  1336,  1338,
    1342,  1343,  1345,  1347,  1351,  1353,  1357,  1361,  1363,  1367,
    1371,  1375,  1379,  1381,  1385,  1389,  1391,  1395,  1399,  1401,
    1406,  1408,  1413,  1415,  1420,  1422,  1427,  1429,  1432,  1434,
    1436,  1439,  1442,  1444,  1446,  1448,  1450,  1452,  1454,  1456,
    1458,  1460,  1462,  1464,  1466,  1471,  1477,  1483,  1490,  1494,
    1499,  1501,  1504,  1508,  1511,  1514,  1516,  1519,  1522,  1524,
    1526,  1528,  1532,  1536,  1538,  1540,  1542,  1545,  1547,  1550,
    1553,  1555,  1558,  1561,  1564,  1567,  1570,  1573,  1576,  1578,
    1581,  1584,  1586,  1589,  1592,  1595,  1598,  1601,  1603,  1605,
    1607,  1609,  1611,  1613,  1615,  1617,  1619,  1622,  1626,  1631,
    1633,  1636,  1640,  1642,  1644,  1646,  1648,  1650,  1652,  1654,
    1656,  1658,  1660,  1662,  1664,  1666,  1668,  1670,  1673,  1676,
    1680,  1682,  1687,  1692,  1696,  1701,  1703,  1707,  1709,  1711,
    1713,  1715,  1717,  1722,  1728,  1737,  1747,  1757,  1768,  1770,
    1773,  1775,  1778,  1785,  1786,  1788,  1792,  1796,  1797,  1799,
    1801,  1803,  1806,  1809,  1810,  1812,  1814,  1816,  1819,  1822,
    1824,  1826,  1828,  1830,  1832,  1834,  1836,  1838,  1840,  1842,
    1844,  1848,  1852,  1855,  1859,  1863,  1866,  1868,  1870,  1872,
    1874,  1876,  1878,  1883,  1887,  1895,  1899,  1907,  1912,  1917,
    1921,  1929,  1931,  1934,  1937,  1939,  1942,  1946,  1948,  1950,
    1952,  1954,  1956,  1960,  1962,  1964,  1966,  1970,  1972,  1974,
    1976,  1978,  1980,  1982,  1984,  1986,  1988,  1990,  1994,  1998,
    2003,  2008,  2012,  2016,  2020,  2025,  2030,  2034,  2039,  2046,
    2051,  2058,  2063,  2067,  2072,  2079,  2086,  2091,  2098,  2105,
    2110,  2112,  2115,  2117,  2119,  2121,  2125,  2129,  2131,  2133,
    2138,  2144,  2151,  2155,  2159,  2163,  2167,  2173,  2181,  2189,
    2195,  2201,  2207,  2215,  2223,  2229,  2235,  2239,  2243,  2249,
    2257,  2263,  2271,  2273,  2278,  2282,  2288,  2290,  2293,  2297,
    2301,  2303,  2307,  2310,  2311,  2313,  2315,  2318,  2320,  2324,
    2326,  2330,  2332,  2337,  2339,  2342,  2346,  2347,  2349,  2350,
    2352,  2357,  2360,  2364,  2366,  2367,  2369,  2374,  2375,  2377,
    2380,  2382,  2386,  2387,  2389,  2392,  2395,  2397,  2398,  2400,
    2401,  2403,  2405,  2407,  2409,  2411,  2413,  2415,  2419,  2423,
    2425,  2427,  2429,  2432,  2436,  2438,  2440,  2442,  2444,  2446,
    2448,  2450,  2452,  2455,  2458,  2460,  2462,  2465,  2468,  2472,
    2474,  2477,  2480,  2486,  2489,  2491,  2493,  2494,  2497,  2499,
    2503,  2508,  2509,  2512,  2513,  2516,  2521,  2526,  2530,  2533,
    2537,  2539,  2543,  2544,  2546,  2548,  2551,  2554,  2557,  2560,
    2562,  2565,  2568,  2571,  2574,  2578,  2581,  2585,  2589,  2594,
    2597,  2600,  2602,  2604,  2608,  2610,  2612,  2614,  2616,  2618,
    2620,  2622,  2624,  2626,  2628,  2630,  2632,  2634,  2636,  2638,
    2640,  2642,  2644,  2646,  2648,  2650,  2652,  2654,  2656,  2658,
    2660,  2662,  2664,  2666,  2668,  2670,  2672,  2674,  2676,  2678,
    2680,  2682,  2684,  2686,  2688,  2690,  2692,  2694,  2696,  2698,
    2700,  2702,  2704,  2706,  2708,  2710,  2712,  2714,  2716,  2718,
    2720,  2722,  2724,  2726,  2728,  2730,  2732,  2734,  2736,  2738,
    2740,  2742,  2744,  2746,  2748,  2750,  2752,  2754,  2756,  2758,
    2760,  2762,  2764,  2766,  2768,  2770,  2772,  2774,  2776,  2778,
    2780,  2782,  2784,  2786,  2788,  2790,  2792,  2794,  2796,  2798,
    2800,  2802,  2804,  2806,  2808,  2810,  2812,  2814,  2816,  2818,
    2820,  2822,  2824,  2826,  2828,  2830,  2832,  2834,  2836,  2838,
    2840,  2842,  2844,  2846,  2848,  2850,  2852,  2854,  2856,  2858,
    2860,  2862,  2864,  2866,  2868,  2870,  2872,  2874,  2876,  2878,
    2880,  2882,  2884,  2886,  2888,  2890,  2892,  2894,  2896,  2898,
    2900,  2902,  2904,  2906,  2908,  2910,  2912,  2914,  2916,  2918,
    2920,  2922,  2924,  2926,  2928,  2930,  2932,  2934,  2936,  2938,
    2940,  2942,  2944,  2946,  2948,  2950,  2952,  2954,  2956,  2958,
    2960,  2962,  2964,  2966,  2968,  2970,  2972,  2974,  2976,  2978,
    2980,  2982,  2984,  2986,  2988,  2990,  2992,  2994,  2996,  2998,
    3000,  3002,  3004,  3006,  3008,  3010,  3012,  3014,  3016,  3018,
    3020,  3022,  3024,  3026,  3028,  3030,  3032,  3034,  3036,  3038,
    3040,  3042,  3044,  3048
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1002,  1002,  1003,  1012,  1021,  1027,  1035,  1041,  1052,
    1057,  1065,  1072,  1079,  1088,  1095,  1103,  1111,  1119,  1130,
    1135,  1142,  1149,  1161,  1171,  1178,  1185,  1197,  1198,  1199,
    1200,  1201,  1206,  1207,  1208,  1209,  1210,  1211,  1212,  1215,
    1220,  1225,  1233,  1241,  1249,  1254,  1262,  1267,  1275,  1280,
    1288,  1295,  1302,  1309,  1319,  1321,  1324,  1334,  1339,  1347,
    1355,  1366,  1373,  1384,  1389,  1397,  1404,  1411,  1420,  1433,
    1441,  1448,  1458,  1465,  1472,  1483,  1484,  1485,  1486,  1487,
    1488,  1489,  1490,  1495,  1501,  1510,  1517,  1527,  1537,  1538,
    1539,  1540,  1541,  1542,  1543,  1544,  1545,  1546,  1551,  1559,
    1567,  1575,  1582,  1590,  1597,  1602,  1610,  1618,  1633,  1648,
    1666,  1671,  1679,  1687,  1698,  1703,  1712,  1717,  1724,  1729,
    1739,  1744,  1753,  1759,  1772,  1777,  1785,  1796,  1811,  1823,
    1838,  1843,  1848,  1853,  1861,  1868,  1879,  1884,  1894,  1901,
    1908,  1915,  1925,  1929,  1939,  1947,  1958,  1964,  1973,  1978,
    1985,  1992,  2003,  2013,  2023,  2033,  2051,  2071,  2075,  2080,
    2087,  2091,  2096,  2103,  2108,  2120,  2127,  2139,  2140,  2141,
    2142,  2143,  2144,  2145,  2147,  2148,  2149,  2150,  2151,  2156,
    2161,  2169,  2186,  2194,  2202,  2209,  2216,  2226,  2238,  2251,
    2263,  2279,  2287,  2295,  2303,  2318,  2323,  2331,  2345,  2362,
    2387,  2395,  2402,  2413,  2423,  2428,  2443,  2444,  2445,  2446,
    2447,  2448,  2453,  2454,  2457,  2458,  2459,  2460,  2461,  2466,
    2480,  2488,  2493,  2501,  2506,  2511,  2519,  2528,  2540,  2550,
    2563,  2571,  2572,  2573,  2578,  2579,  2580,  2581,  2582,  2587,
    2594,  2604,  2610,  2621,  2628,  2636,  2647,  2657,  2667,  2677,
    2687,  2697,  2707,  2717,  2728,  2737,  2747,  2757,  2773,  2782,
    2791,  2799,  2805,  2817,  2825,  2835,  2843,  2855,  2861,  2872,
    2874,  2878,  2886,  2890,  2895,  2899,  2903,  2907,  2917,  2925,
    2932,  2938,  2949,  2953,  2962,  2970,  2976,  2986,  2992,  3002,
    3006,  3016,  3022,  3028,  3034,  3043,  3052,  3061,  3074,  3078,
    3086,  3092,  3102,  3110,  3119,  3132,  3139,  3151,  3155,  3167,
    3174,  3180,  3189,  3196,  3202,  3213,  3220,  3226,  3235,  3244,
    3251,  3262,  3269,  3281,  3287,  3299,  3305,  3316,  3322,  3333,
    3339,  3350,  3359,  3363,  3372,  3376,  3384,  3388,  3398,  3405,
    3414,  3424,  3423,  3437,  3446,  3455,  3468,  3472,  3484,  3488,
    3496,  3499,  3506,  3510,  3519,  3523,  3527,  3535,  3539,  3545,
    3551,  3557,  3567,  3571,  3575,  3583,  3587,  3593,  3603,  3607,
    3617,  3621,  3631,  3635,  3645,  3649,  3659,  3663,  3671,  3675,
    3679,  3683,  3693,  3697,  3701,  3709,  3713,  3717,  3721,  3725,
    3729,  3737,  3741,  3745,  3753,  3757,  3761,  3765,  3776,  3782,
    3792,  3798,  3808,  3812,  3816,  3854,  3858,  3868,  3878,  3891,
    3900,  3910,  3914,  3923,  3927,  3936,  3942,  3950,  3956,  3968,
    3974,  3984,  3988,  3992,  3996,  4000,  4006,  4012,  4020,  4024,
    4032,  4036,  4047,  4051,  4055,  4061,  4065,  4079,  4083,  4091,
    4095,  4105,  4109,  4113,  4117,  4126,  4130,  4134,  4138,  4146,
    4152,  4162,  4170,  4174,  4178,  4182,  4186,  4190,  4194,  4198,
    4202,  4212,  4220,  4224,  4232,  4239,  4246,  4257,  4265,  4269,
    4277,  4285,  4293,  4347,  4351,  4364,  4370,  4380,  4384,  4392,
    4396,  4400,  4408,  4418,  4428,  4445,  4462,  4479,  4501,  4507,
    4518,  4524,  4535,  4546,  4548,  4552,  4557,  4567,  4570,  4577,
    4583,  4589,  4597,  4610,  4613,  4620,  4626,  4632,  4639,  4650,
    4654,  4664,  4668,  4678,  4682,  4686,  4691,  4700,  4706,  4712,
    4718,  4726,  4731,  4739,  4744,  4752,  4760,  4765,  4770,  4775,
    4780,  4785,  4794,  4802,  4806,  4823,  4827,  4835,  4843,  4851,
    4855,  4863,  4869,  4879,  4887,  4891,  4895,  4930,  4936,  4942,
    4952,  4956,  4960,  4964,  4968,  4975,  4981,  4991,  4999,  5003,
    5007,  5011,  5015,  5019,  5023,  5027,  5031,  5039,  5047,  5051,
    5055,  5065,  5073,  5081,  5085,  5089,  5097,  5101,  5107,  5113,
    5117,  5127,  5135,  5139,  5145,  5154,  5163,  5169,  5175,  5185,
    5202,  5209,  5224,  5260,  5264,  5272,  5280,  5292,  5296,  5304,
    5312,  5316,  5327,  5344,  5350,  5356,  5366,  5370,  5376,  5382,
    5386,  5392,  5396,  5402,  5408,  5415,  5425,  5430,  5438,  5444,
    5454,  5476,  5485,  5491,  5504,  5518,  5525,  5531,  5541,  5550,
    5558,  5564,  5582,  5590,  5594,  5601,  5606,  5614,  5618,  5625,
    5629,  5636,  5640,  5647,  5651,  5660,  5673,  5676,  5684,  5687,
    5695,  5703,  5711,  5715,  5723,  5726,  5734,  5746,  5749,  5757,
    5769,  5775,  5785,  5788,  5796,  5800,  5804,  5812,  5815,  5823,
    5826,  5834,  5838,  5842,  5846,  5850,  5858,  5866,  5878,  5890,
    5894,  5898,  5906,  5912,  5922,  5926,  5930,  5934,  5938,  5942,
    5946,  5950,  5958,  5962,  5966,  5970,  5978,  5984,  5994,  6004,
    6008,  6016,  6026,  6037,  6044,  6048,  6056,  6059,  6066,  6071,
    6080,  6090,  6093,  6100,  6104,  6112,  6121,  6128,  6138,  6142,
    6149,  6155,  6165,  6168,  6175,  6180,  6192,  6200,  6212,  6220,
    6224,  6232,  6236,  6240,  6248,  6256,  6260,  6264,  6268,  6276,
    6284,  6296,  6300,  6308,  6321,  6325,  6326,  6339,  6340,  6341,
    6342,  6343,  6344,  6345,  6346,  6347,  6348,  6349,  6350,  6351,
    6352,  6353,  6354,  6358,  6359,  6360,  6361,  6362,  6363,  6364,
    6365,  6366,  6367,  6368,  6369,  6370,  6371,  6372,  6373,  6374,
    6375,  6376,  6377,  6378,  6379,  6380,  6381,  6382,  6383,  6384,
    6385,  6386,  6387,  6388,  6389,  6390,  6391,  6392,  6393,  6394,
    6395,  6396,  6397,  6398,  6399,  6400,  6401,  6402,  6403,  6404,
    6405,  6406,  6407,  6408,  6409,  6410,  6411,  6412,  6413,  6414,
    6415,  6416,  6417,  6418,  6419,  6420,  6421,  6422,  6423,  6424,
    6425,  6426,  6427,  6428,  6429,  6430,  6431,  6432,  6433,  6434,
    6435,  6436,  6437,  6438,  6439,  6440,  6441,  6442,  6443,  6444,
    6445,  6446,  6447,  6448,  6449,  6450,  6451,  6452,  6453,  6454,
    6455,  6456,  6457,  6458,  6459,  6460,  6461,  6462,  6463,  6464,
    6465,  6466,  6467,  6468,  6469,  6470,  6471,  6472,  6473,  6474,
    6475,  6476,  6477,  6478,  6479,  6480,  6481,  6482,  6483,  6484,
    6485,  6486,  6487,  6488,  6489,  6490,  6491,  6492,  6493,  6494,
    6495,  6496,  6497,  6498,  6499,  6500,  6501,  6502,  6503,  6504,
    6505,  6506,  6507,  6508,  6509,  6510,  6511,  6512,  6513,  6514,
    6515,  6516,  6517,  6518,  6519,  6520,  6521,  6522,  6523,  6524,
    6525,  6526,  6527,  6528,  6529,  6530,  6531,  6532,  6533,  6534,
    6535,  6536,  6537,  6538,  6539,  6540,  6541,  6542,  6543,  6544,
    6545,  6546,  6547,  6548,  6549,  6550,  6551,  6552,  6553,  6554,
    6555,  6556,  6561,  6568
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
     315,   316,   317,   318,   319
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 14071;
  const int xquery_parser::yynnts_ = 307;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 572;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 320;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 574;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 16389 "/home/colea/xquery_bzr/error-messages/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 6572 "/home/colea/xquery_bzr/error-messages/src/compiler/parser/xquery_parser.y"


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

